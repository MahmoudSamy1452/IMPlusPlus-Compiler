%code requires{
    #include "SymbolTable.h"
    #include "structs.h"
    #include <stack>
    #include <utility>
    #include <queue>
    #include <string>
    #include <fstream>
    #include <iomanip>
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
    std::stack<int> labelsStack;
    int forCount = 0, labels = 0;
    std::stack<string> forStack;
    std::stack<int> switchStack;

    string* currentFunction = nullptr;

    extern int yylineno;

    ofstream quadFile("Quadruples.txt");
    ofstream errorMessages("errorMessages.txt");
    ofstream symbolTable("symbolTable.txt");

    
    
%}

%union {
    float value;                /* float value */
    char* string;               /* string value */
    Type type;
    Value* val;
    queue<Type>* types;
};

%token <val> CHAR CHARARRAY INTEGER FLOATING BOOLEAN
%token <string> VARIABLE
%token WHILE REPEAT UNTIL FOR SWITCH CASE IF THEN ELSE FUNCTION RETURN INT FLOAT CHARACTER STRING BOOL VOID CONST GE LE EQ NE
%type <type> datatype
%type <val> assignmentValue expression caseExpression
%type <types> parametersList parameters

%nonassoc '='
%left '|'
%left '&'
%left '<' '>' GE LE EQ NE
%left '+' '-'
%left '*' '/'
%right '~'

%%

program: 
        { symbolTable << "{" << endl;} lines   {
                symTable->checkUnusedVariables(); 
                symTable->printTable(); symbolTable << "}" << endl;}
        ;

lines:  
        statement ';' lines
        | /* NULL */
        | ';' lines
        ;

declaration:
        datatype VARIABLE                               {       
                                                                symTable->insert($2, $1);
                                                        }
        | datatype VARIABLE '=' assignmentValue         { 

                                                                symTable->insert($2, $1, $4->value);
                                                                symTable->setValue($2, $4);
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)$2);
                                                                else
                                                                        quadFile << "POP " << $2 << endl;
                                                        }
        | CONST datatype VARIABLE '=' assignmentValue   {       symTable->insert($3, $2, $5->value, true);
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)$3);
                                                                else
                                                                        quadFile << "POP " << $3 << endl;
                                                        }
        ;


assignment:
        VARIABLE '=' assignmentValue                   { symTable->setValue($1, $3);
                                                          if(forCount > 0){
                                                                forStack.push("POP " + (string)$1);
                                                          }
                                                          else
                                                              quadFile << "POP " << $1 << endl;
                                                        }
        ;

assignmentValue:
        CHAR { quadFile << "PUSH " << *(char*)$1->value << endl; $$ = $1; }
        | CHARARRAY { quadFile << "PUSH " << (string)reinterpret_cast<char*>($1->value) << endl; $$ = $1; }
        | expression
        | VARIABLE '(' parameters ')' {
                                        if(symTable->lookup($1) == nullptr) {
                                            throwError("function " + string($1) + " not declared\n");
                                        }
                                        else if(symTable->lookup($1)->type != Type::TYPE_FUNC) {
                                            throwError(string($1) + " is not a function\n");
                                        }
                                        else if(symTable->lookup($1)->args->size() != $3->size()) {
                                            throwError("function " + string($1) + " argument size mismatch\n");
                                        }
                                        quadFile << "CALL " << $1 << endl; 
                                        $$ = new Value{nullptr, *symTable->lookup($1)->returnType};
                                }
        ;

initialization:
        declaration
        | assignment
        ;

statement:
        initialization 
        | whileLoop '(' expression endBracketJump scope                       { 
                                                                                quadFile << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
        | repeatLoop scope UNTIL '(' expression ')'                           { 
                                                                                quadFile << "JZ Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
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
                                                                                    quadFile << tempStack.top() << endl;
                                                                                    tempStack.pop();
                                                                                }
                                                                                quadFile << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                               }
        | SWITCH '(' caseExpression endCaseExpression '{' case '}'              { quadFile << "OutLabel" << switchStack.top() << ":" << endl;                                                                       switchStack.pop(); labelsStack.pop(); }
        | scope
        | ifCondition '(' expression endBracketJump THEN scope { quadFile << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
        | ifCondition '(' expression endBracketJump THEN scope elseLabel scope { quadFile << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
        | funcDeclaration scope 
        | VARIABLE '(' parameters ')' {
                                        if(symTable->lookup($1) == nullptr) {
                                            throwError("function " + string($1) + " not declared\n");
                                        }
                                        else if(symTable->lookup($1)->type != Type::TYPE_FUNC) {
                                            throwError(string($1) + " is not a function\n");
                                        }
                                        else if(symTable->lookup($1)->args->size() != $3->size()) {
                                            throwError("function " + string($1) + " argument size mismatch\n");
                                        }
                                        auto params = $3;
                                        auto args = *symTable->lookup($1)->args;
                                        for(auto arg: args) {
                                            if(arg.first != params->front()) {
                                                throwError("argument type mismatch\n");
                                            }
                                            params->pop();
                                        }
                                        quadFile << "CALL " << $1 << endl; 
                                }
        | RETURN assignmentValue {
                                    quadFile << "POP " << "$retvalue" << endl;
                                    quadFile << "RET " << "$retvalue" << endl;
                                    if(symTable->getFunctionName() == nullptr) {
                                        throwError("return statement outside function\n");
                                    }
                                    else if(*symTable->getReturnType(*symTable->getFunctionName()) != $2->type) {throwError("return type mismatch\n");}
                                    symTable->setIsReturned();
                                 }
        | RETURN                {
                                    quadFile << "RET" << endl;
                                    if(symTable->getFunctionName() == nullptr) {
                                        throwError("return statement outside function\n");
                                    }
                                    else if(*symTable->getReturnType(*symTable->getFunctionName()) != Type::TYPE_VOID) {throwError("return type mismatch\n");}
                                    symTable->setIsReturned();
                                 }
        ;

whileLoop:
        WHILE                   { 
                                        quadFile << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
        ;

repeatLoop:
        REPEAT                  { 
                                        quadFile << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
        ;

forLoop:
        FOR '(' initialization ';'      { 
                                                quadFile << endl << "Label" << labels << ": " << endl;
                                                labelsStack.push(labels++);
                                        }
        ;

ifCondition: 
        IF                              { 
                                                labelsStack.push(labels++); 
                                        }
        ;

endBracketJump:
        ')' { quadFile << "JZ OutLabel" << labelsStack.top() << endl; }
        ;

endCaseExpression:
        ')' { quadFile << "POP $t" << labels << endl; labelsStack.push(labels++); switchStack.push(labels++); }
        ;

semicolonJump:
        ';' { quadFile << "JZ OutLabel" << labelsStack.top() << endl; forCount++; forStack.push("@"); }
        ;

endForDeclaration:
        ')' { forCount--; }
        ;

elseLabel:
        ELSE { quadFile << "JMP OutLabel" << labels << '\n' << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); labelsStack.push(labels++); }
        ;

funcDeclaration:
        funcHeader '(' arguments ')'
        ;

funcHeader:
        FUNCTION datatype VARIABLE  { quadFile << $3 << ':' << endl; symTable->insert($3, Type::TYPE_FUNC, nullptr, false, new vector<pair<Type, string>>(), new Type($2)); currentFunction = new string($3);}
        | FUNCTION VOID VARIABLE   { quadFile << $3 << ':' << endl; symTable->insert($3, Type::TYPE_FUNC, nullptr, false, new vector<pair<Type, string>>(), new Type(Type::TYPE_VOID)); currentFunction = new string($3);}
        ;

argumentsList:
        datatype VARIABLE                       { quadFile << "POP " << $2 << endl; symTable->addArgs(*currentFunction, $2, $1); }
        | datatype VARIABLE ',' argumentsList   { quadFile << "POP " << $2 << endl; symTable->addArgs(*currentFunction, $2, $1);}
        ;

arguments:
        argumentsList
        | /* NULL */
        ;

parametersList:
        assignmentValue ',' parametersList {$3->push($1->type); $$ = $3;}
        | assignmentValue                  {$$ = new queue<Type>(); $$->push($1->type);}
        ;

parameters:
        parametersList {$$ = $1;}
        | /* NULL */ {$$ = new queue<Type>();}
        ;

case:
        CASE caseExpression caseColon caseScope                
        | CASE caseExpression caseColon caseScope case
        ;

/* caseCondition:
        | CHAR
        | caseExpression
        ; */

caseExpression:
        INTEGER                         {  
                                                $$ = $1;
                                                quadFile << "PUSH " << *(int*)$1->value << endl;
                                        }
        | BOOLEAN                       { 
                                                $$ = $1;
                                                quadFile << "PUSH " << *(bool*)$1->value << endl ;
                                        }
        | CHAR                          { 
                                                $$ = $1;
                                                quadFile << "PUSH " << *(char*)$1->value << endl;
                                        }
        | VARIABLE                      { 
                                                Type t = symTable->getType($1);
                                                $$ = new Value{symTable->getValue($1), symTable->getType($1)};
                                                quadFile << "PUSH " << $1 << endl;
                                        }
        | caseExpression '<' caseExpression     { implementOperation(OP::LeT, forCount,&forStack, $1->type, $3->type);  $$ = $1;}
        | caseExpression '>' caseExpression     { implementOperation(OP::GrT, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression LE caseExpression      { implementOperation(OP::LeE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression GE caseExpression      { implementOperation(OP::GrE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression EQ caseExpression      { implementOperation(OP::EQQ, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression NE caseExpression      { implementOperation(OP::NoE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression '|' caseExpression     { implementOperation(OP::OR, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression '&' caseExpression     { implementOperation(OP::AND, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression '+' caseExpression     { implementOperation(OP::PLUS, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression '-' caseExpression     { implementOperation(OP::MINUS, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression '*' caseExpression     { implementOperation(OP::MULTIPLY, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | caseExpression '/' caseExpression     { implementOperation(OP::DIVIDE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | '~' caseExpression                { implementOperation(OP::NOT, forCount,&forStack, $2->type, $2->type); $$ = $2;}
        | '-' caseExpression                { implementOperation(OP::NEG, forCount,&forStack, $2->type, $2->type); $$ = $2;}
        | '(' caseExpression ')'            { $$ = $2;}    
        ;

caseColon:
        ':'                     {   
                                        quadFile << "PUSH $t" << labelsStack.top() << endl << "EQ" << endl << "JZ label" << labels << endl; 
                                        labelsStack.push(labels++); 
                                }
        ;

caseScope:
        scope                   { 
                                        quadFile << "JMP OutLabel" << switchStack.top() << endl << "label " << labelsStack.top() << ":" << endl;
                                        labelsStack.pop();
                                }
        ;

expression:
        FLOATING                        { $$ = $1;
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(float*)$1->value));
                                            else
                                                quadFile << "PUSH " << *(float*)$1->value << endl;
                                        }
        | INTEGER                       { $$ = $1;
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(int*)$1->value));
                                            else
                                                quadFile << "PUSH " << *(int*)$1->value << endl;
                                        }
        | BOOLEAN                       { $$ = $1;
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(bool*)$1->value));
                                            else
                                                quadFile << "PUSH " << *(int*)$1->value << endl ;
                                        }
        | VARIABLE                      { 
                                                if(forCount > 0)
                                                        forStack.push("PUSH " + (string)$1);
                                                else
                                                        quadFile << "PUSH " << $1 << endl;
                                                Type t = symTable->getType($1);
                                                $$ = new Value{symTable->getValue($1), symTable->getType($1)};
                                        }
        | expression '<' expression     { implementOperation(OP::LeT, forCount, &forStack, $1->type, $3->type);  $$ = $1; /* TODO: check on type and propagate*/}
        | expression '>' expression     { implementOperation(OP::GrT, forCount, &forStack, $1->type, $3->type); $$ = $1;}
        | expression LE expression      { implementOperation(OP::LeE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression GE expression      { implementOperation(OP::GrE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression EQ expression      { implementOperation(OP::EQQ, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression NE expression      { implementOperation(OP::NoE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression '|' expression     { implementOperation(OP::OR, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression '&' expression     { implementOperation(OP::AND, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression '+' expression     { implementOperation(OP::PLUS, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression '-' expression     { implementOperation(OP::MINUS, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression '*' expression     { implementOperation(OP::MULTIPLY, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | expression '/' expression     { implementOperation(OP::DIVIDE, forCount,&forStack, $1->type, $3->type); $$ = $1;}
        | '~' expression                { implementOperation(OP::NOT, forCount,&forStack, $2->type, $2->type); $$ = $2;}
        | '-' expression                { implementOperation(OP::NEG, forCount,&forStack, $2->type, $2->type); $$ = $2;}
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
        scopeInit lines '}' { 
                                if(symTable->getFunctionName() != nullptr && symTable->getIsReturned() == false) {
                                        throwError("Function " + *symTable->getFunctionName() + " is missing a return statement\n");
                                }
                                symTable->checkUnusedVariables();
                                symTable->printTable();
                                symTable = symTable->getParentTable();
                                symbolTable << "}" << endl;
                                }
        ;

scopeInit:
        '{'     {       
                        symbolTable << "{" << endl;
                        symTable = new SymbolTable(symTable);
                        if(currentFunction != nullptr) {
                                symTable->setFunctionName(currentFunction);
                                auto args = symTable->lookup(*currentFunction)->args;
                                for(auto arg : *args) {
                                       symTable->insert(arg.second, arg.first);
                                       symTable->setValue(arg.second, new Value{(void*)1, arg.first});
                                }
                                currentFunction = nullptr;
                        }
                }
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
}

void throwError(string s) {
        errorMessages << "Error at line " << yylineno << ": " << s << endl;
        const char *x = s.c_str();
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
