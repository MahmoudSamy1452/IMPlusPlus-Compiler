%code requires{
    #include "SymbolTable.h"
    #include "structs.h"
    #include <stack>
    #include <utility>
    #include <queue>
    #include <string>
}

%{
    #include <stdio.h>
    #include "structs.h"
    #include "SymbolTable.h"
    #include "codeGenerator.h"
    void yyerror(const char *);
    void throwError(string);
    int yylex(void);
    extern FILE *yyin;

    SymbolTable* symTable = new SymbolTable();
    std::stack<std::pair<bool, Type>> funcStack;
    std::stack<int> labelsStack;
    int forCount = 0, labels = 0;
    std::stack<string> forStack;
%}

%union {
    float value;                /* float value */
    char* string;               /* string value */
    Type type;
    Value* val;
};

%token <val> CHAR CHARARRAY INTEGER FLOATING BOOLEAN
%token <string> VARIABLE
%token WHILE REPEAT UNTIL FOR SWITCH CASE IF THEN ELSE FUNCTION RETURN INT FLOAT CHARACTER STRING BOOL VOID CONST GE LE EQ NE
%type <type> datatype
%type <val> assignmentValue expression caseExpression

%nonassoc '='
%left '|'
%left '&'
%left '<' '>' GE LE EQ NE
%left '+' '-'
%left '*' '/'
%right '~'

%%

program:
        statement ';' program
        | /* NULL */
        | ';' program
        ;

declaration:
        datatype VARIABLE                               {       
                                                                symTable->insert($2, $1);
                                                        }
        | datatype VARIABLE '=' assignmentValue         { 
                                                                symTable->insert($2, $1, $4->value);
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)$2);
                                                                else
                                                                        cout << "POP " << $2 << endl;
                                                        }
        | CONST datatype VARIABLE '=' assignmentValue   {       symTable->insert($3, $2, $5->value, true);
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)$3);
                                                                else
                                                                        cout << "POP " << $3 << endl;
                                                        }
        ;


assignment:
        VARIABLE '=' assignmentValue                   { symTable->setValue($1, $3);
                                                          if(forCount > 0){
                                                                forStack.push("POP " + (string)$1);
                                                          }
                                                          else
                                                              cout << "POP " << $1 << endl;
                                                        }
        ;

assignmentValue:
        expression                                
        | CHAR
        | CHARARRAY
        | VARIABLE '(' parameters ')' {cout << "CALL " << $1 << endl;} /*TODO: call function to get return type from symbol table and push it to stack in val struct*/
        ;

initialization:
        declaration
        | assignment
        ;

statement:
        initialization 
        | whileLoop '(' expression endBracketJump scope                       { 
                                                                                cout << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
        | repeatLoop scope UNTIL '(' expression ')'                           { 
                                                                                cout << "JZ Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
        | forLoop expression semicolonJump assignment endForDeclaration scope {
                                                                                stack<string> tempStack;
                                                                                while (forStack.top() != "@"){
                                                                                    tempStack.push(forStack.top());
                                                                                    forStack.pop();
                                                                                }
                                                                                forStack.pop();
                                                                                while (!tempStack.empty()){
                                                                                    cout << tempStack.top() << endl;
                                                                                    tempStack.pop();
                                                                                }
                                                                                cout << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                               }
        | SWITCH '(' expression ')' '{' case '}' /* check switch(exp) can be literal */ 
        | scope
        | ifCondition '(' expression endBracketJump THEN scope { cout << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
        | ifCondition '(' expression endBracketJump THEN scope elseLabel scope { cout << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
        | funcDeclaration scope  {
                                    if(!funcStack.top().first) { throwError("function declaration without return\n"); }
                                    funcStack.pop();

                                 }
        | VARIABLE '(' parameters ')' { cout << "CALL " << $1 << endl; }
        | RETURN assignmentValue {
                                    if(funcStack.empty()) { throwError("return statement outside function\n"); }
                                    else if(funcStack.top().second != $2->type) {throwError("return type mismatch\n");}
                                    funcStack.pop();
                                    funcStack.push(std::make_pair(true, $2->type));
                                 }
        | RETURN                {
                                    if(funcStack.empty()) { throwError("return statement outside function\n"); }
                                    else if(funcStack.top().second != Type::TYPE_VOID) { throwError("return type mismatch\n");}
                                 }
        ;

whileLoop:
        WHILE                   { 
                                        cout << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
        ;

repeatLoop:
        REPEAT                  { 
                                        cout << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
        ;

forLoop:
        FOR '(' initialization ';'      { 
                                                cout << endl << "Label" << labels << ": " << endl;
                                                labelsStack.push(labels++);
                                        }
        ;

ifCondition: 
        IF                              { 
                                                labelsStack.push(labels++); 
                                        }
        ;

endBracketJump:
        ')' { cout << "JZ OutLabel" << labelsStack.top() << endl; }
        ;

semicolonJump:
        ';' { cout << "JZ OutLabel" << labelsStack.top() << endl; forCount++; forStack.push("@"); }
        ;

endForDeclaration:
        ')' { forCount--; }
        ;

elseLabel:
        ELSE { cout << "JMP OutLabel" << labels << '\n' << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); labelsStack.push(labels++); }
        ;

funcDeclaration:
        FUNCTION datatype VARIABLE '(' arguments ')' { funcStack.push(std::make_pair(false, $2)); printf("function declaration\n");}
        | FUNCTION VOID VARIABLE '(' arguments ')'  { funcStack.push(std::make_pair(true, Type::TYPE_VOID)); printf("function declaration\n");}
        ;

argumentsList:
        datatype VARIABLE
        | datatype VARIABLE ',' argumentsList
        ;

arguments:
        argumentsList
        | /* NULL */
        ;

parametersList:
        assignmentValue ',' parametersList
        | assignmentValue
        ;

parameters:
        parametersList
        | /* NULL */
        ;

case:
        CASE caseCondition ':' scope 
        | CASE caseCondition ':' scope case 
        ;

caseCondition:
        | CHAR
        | caseExpression
        ;

caseExpression:
        INTEGER
        | BOOLEAN                       
        | caseExpression '<' caseExpression     
        | caseExpression '>' caseExpression     
        | caseExpression LE caseExpression      
        | caseExpression GE caseExpression      
        | caseExpression EQ caseExpression      
        | caseExpression NE caseExpression      
        | caseExpression '|' caseExpression     
        | caseExpression '&' caseExpression     
        | caseExpression '+' caseExpression     
        | caseExpression '-' caseExpression     
        | caseExpression '*' caseExpression     
        | caseExpression '/' caseExpression     
        | '~' caseExpression {$$ = $2;}               
        | '-' caseExpression {$$ = $2;} 
        | '(' caseExpression ')' {$$ = $2;}       
        ;

expression:
        FLOATING
        | INTEGER                       { $$ = $1;
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(int*)$1->value));
                                            else
                                                cout << "PUSH " << *(int*)$1->value << endl;
                                        }
        | BOOLEAN                       { $$ = $1;
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(bool*)$1->value));
                                            else
                                                cout << "PUSH " << *(int*)$1->value << endl ;
                                        }
        | VARIABLE                      { $$ = new Value{symTable->getValue($1), symTable->getType($1)};
                                            if(forCount > 0)
                                                forStack.push("PUSH " + (string)$1);
                                            else
                                                cout << "PUSH " << $1 << endl;
                                        }
        | expression '<' expression     { implementOperation(OP::LeT, forCount,&forStack);  $$ = $1; /* TODO: check on type and propagate*/}
        | expression '>' expression     { implementOperation(OP::GrT, forCount,&forStack); $$ = $1;}
        | expression LE expression      { implementOperation(OP::LeE, forCount,&forStack); $$ = $1;}
        | expression GE expression      { implementOperation(OP::GrE, forCount,&forStack); $$ = $1;}
        | expression EQ expression      { implementOperation(OP::EQQ, forCount,&forStack); $$ = $1;}
        | expression NE expression      { implementOperation(OP::NoE, forCount,&forStack); $$ = $1;}
        | expression '|' expression     { implementOperation(OP::OR, forCount,&forStack); $$ = $1;}
        | expression '&' expression     { implementOperation(OP::AND, forCount,&forStack); $$ = $1;}
        | expression '+' expression     { implementOperation(OP::PLUS, forCount,&forStack); $$ = $1;}
        | expression '-' expression     { implementOperation(OP::MINUS, forCount,&forStack); $$ = $1;}
        | expression '*' expression     { implementOperation(OP::MULTIPLY, forCount,&forStack); $$ = $1;}
        | expression '/' expression     { implementOperation(OP::DIVIDE, forCount,&forStack); $$ = $1;}
        | '~' expression                { implementOperation(OP::NOT, forCount,&forStack); $$ = $2;}
        | '-' expression                { implementOperation(OP::NEG, forCount,&forStack); $$ = $2;}
        | '(' expression ')'            { $$ = $2;}
        ;
datatype:
        INT                             { $$ = Type::TYPE_INT; }
        | FLOAT                         { $$ = Type::TYPE_FLOAT; }
        | BOOL                          { $$ = Type::TYPE_BOOL; }
        | CHARACTER                     { $$ = Type::TYPE_CHAR; }
        | STRING                        { $$ = Type::TYPE_CHAR_ARRAY; }  
        ;

scope:
        scopeInit program '}' {symTable = symTable->getParentTable();}
        ;

scopeInit:
        '{'       {symTable = new SymbolTable(symTable);}
        ;

/* funcScopeValue:
        '{' program returnValue program '}'
        ;

funcScopeVoid:
        '{' program returnVoid program '}'
        | scope
        ; */

/* returnValue:
    RETURN assignmentValue ';' /* check return type  { printf("return\n");}
    ; */

/* returnVoid:
    RETURN ';'
    ; */

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

void throwError(string s) {
    const char *x = s.c_str();
    yyerror(x);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  // Open the input file
  FILE *inputFile = fopen(argv[1], "r");
  if (inputFile == NULL) {
    perror("fopen");
    return 1;
  }

  // Set yyin to the input file stream
  yyin = inputFile;

  // Parse the input file
  yyparse();

  // Close the input file
  fclose(inputFile);
  return 0;
}
