%code requires{
    #include "SymbolTable.h"
    #include "structs.h"
    #include <stack>
    #include <utility>
}

%{
    #include <stdio.h>
    #include "structs.h"
    #include "SymbolTable.h"
    void yyerror(const char *);
    void throwError(string);
    int yylex(void);
    extern FILE *yyin;

    SymbolTable* symTable = new SymbolTable();
    std::stack <std::pair<bool, Type>> funcStack;
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
        datatype VARIABLE                               { symTable->insert($2, $1); printf("declaration\n");}
        | datatype VARIABLE '=' assignmentValue         { symTable->insert($2, $1, $4->value); printf("declaration = value\n");}
        | CONST datatype VARIABLE '=' assignmentValue   { symTable->insert($3, $2, $5->value, true); printf("const declaration");}
        ;


assignment:
        VARIABLE '=' assignmentValue                   { symTable->setValue($1, $3); }
        ;

assignmentValue:
        expression                                
        | CHAR
        | CHARARRAY
        | VARIABLE '(' parameters ')' {} /*TODO: call function to get return type from symbol table and push it to stack in val struct*/
        ;

initialization:
        declaration
        | assignment
        ;

statement:
        initialization 
        | WHILE '(' expression ')' scope 
        | REPEAT scope UNTIL '(' expression ')' 
        | FOR '(' initialization ';' expression ';' assignment ')' scope    
        | SWITCH '(' expression ')' '{' case '}' /* check switch(exp) can be literal */ 
        | scope
        | IF '(' expression ')' THEN scope 
        | IF '(' expression ')' THEN scope ELSE scope 
        | funcDeclaration scope  {
                                    if(!funcStack.top().first) { throwError("function declaration without return\n"); }
                                    funcStack.pop();

                                 }
        | VARIABLE '(' parameters ')' { /*printf("function call\n"); */}
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
        | INTEGER
        | BOOLEAN                       
        | VARIABLE                     { $$ = new Value{symTable->getValue($1), symTable->getType($1)}; }
        | expression '<' expression     
        | expression '>' expression     
        | expression LE expression     
        | expression GE expression      
        | expression EQ expression      
        | expression NE expression      
        | expression '|' expression     
        | expression '&' expression    
        | expression '+' expression    { int* sum = new int(*((int*)($1->value)) + *((int*)($3->value)));
                $$ = new Value{(void*)sum, Type::TYPE_INT};}
        | expression '-' expression    { int* minus = new int(*((int*)($1->value)) - *((int*)($3->value)));
                $$ = new Value{(void*)minus, Type::TYPE_INT};}
        | expression '*' expression     
        | expression '/' expression     
        | '~' expression             {$$ = $2;}         
        | '-' expression             {$$ = $2;}   
        | '(' expression ')'         {$$ = $2;}   
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
        '{'       {symTable = new SymbolTable(symTable); printf("scope\n");}
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
