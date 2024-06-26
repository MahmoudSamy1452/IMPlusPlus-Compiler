%{
    #include <stdio.h>
    void yyerror(char *);
    int yylex(void);
    extern FILE *yyin;

//     entry* sym[26]; /* index, const, val */
%}

%union {
    float value;                /* float value */
    char* string;               /* string value */
    char sIndex;                /* symbol table index */
};

%token <value> INTEGER FLOATING BOOLEAN
%token <string> CHAR CHARARRAY
%token <string> VARIABLE
%token WHILE REPEAT UNTIL FOR SWITCH CASE IF THEN ELSE FUNCTION RETURN INT FLOAT CHARACTER STRING BOOL VOID CONST GE LE EQ NE
%type <value> expression caseExpression

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
        datatype VARIABLE
        | datatype VARIABLE '=' assignmentValue        /*{ sym[$2] = $4; sym[$2].const = 0;}*/ /* check for redeclaration */
        | CONST datatype VARIABLE '=' assignmentValue  /*{ sym[$3].value = $5; sym[$3].const = 1; }*/
        ;

assignment:
        VARIABLE '=' assignmentValue                   /*{ sym[$1] = $3; }*/ /* check for const assignment */
        ;

assignmentValue:
        expression
        | CHAR
        | CHARARRAY
        | VARIABLE '(' parameters ')'
        ;

initialization:
        declaration
        | assignment
        ;

statement:
        initialization { printf("initialization\n");}
        | WHILE '(' expression ')' scope { printf("while\n");}
        | REPEAT scope UNTIL '(' expression ')' { printf("repeat\n");}
        | FOR '(' initialization ';' expression ';' assignment ')' scope    { printf("for\n");}
        | SWITCH '(' expression ')' '{' case '}' /* check switch(exp) can be literal */ { printf("switch\n");}
        | scope
        | IF '(' expression ')' THEN scope { printf("if\n");}
        | IF '(' expression ')' THEN scope ELSE scope { printf("if else\n");}
        | FUNCTION datatype VARIABLE '(' arguments ')' scope { printf("function\n");}
        | FUNCTION VOID VARIABLE '(' arguments ')' scope { printf("function\n");}
        | VARIABLE '(' parameters ')' { printf("function call\n"); }
        | RETURN assignmentValue
        | RETURN
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
        CASE caseCondition ':' scope { printf("case\n");}
        | CASE caseCondition ':' scope case { printf("case case\n");}
        ;

caseCondition:
        | CHAR
        | caseExpression
        ;

caseExpression:
        INTEGER
        | BOOLEAN                       { printf("boolean\n");}
        | caseExpression '<' caseExpression     { /*$$ = $1 < $3;*/ printf("less than\n");}
        | caseExpression '>' caseExpression     { /*$$ = $1 > $3;*/ }
        | caseExpression LE caseExpression      { /*$$ = $1 <= $3;*/ }
        | caseExpression GE caseExpression      { /*$$ = $1 >= $3;*/}
        | caseExpression EQ caseExpression      { /*$$ = $1 == $3;*/ }
        | caseExpression NE caseExpression      { /*$$ = $1 != $3;*/}
        | caseExpression '|' caseExpression     { /*$$ = $1 || $3;*/ }
        | caseExpression '&' caseExpression     { /*$$ = $1 && $3;*/ }
        | caseExpression '+' caseExpression     { /*$$ = $1 + $3;*/ printf("add\n");}
        | caseExpression '-' caseExpression     { /*$$ = $1 - $3; printf("sub\n");*/}
        | caseExpression '*' caseExpression     { /*$$ = $1 * $3; printf("mul\n");*/}
        | caseExpression '/' caseExpression     { /*$$ = $1 / $3; printf("div\n");*/}
        | '~' caseExpression                { /*$$ = !$2; */}
        | '-' caseExpression                { /*$$ = -$2; */}
        | '(' caseExpression ')'            { /*$$ = $2; */}
        ;

expression:
        FLOATING
        | INTEGER
        | BOOLEAN                       { printf("boolean\n");}
        | VARIABLE                      { /*$$ = 0*/ ; printf("variable\n");}
        | expression '<' expression     { /*$$ = $1 < $3;*/ printf("less than\n");}
        | expression '>' expression     { /*$$ = $1 > $3;*/ }
        | expression LE expression      { /*$$ = $1 <= $3;*/ }
        | expression GE expression      { /*$$ = $1 >= $3;*/}
        | expression EQ expression      { /*$$ = $1 == $3;*/ }
        | expression NE expression      { /*$$ = $1 != $3;*/}
        | expression '|' expression     { /*$$ = $1 || $3;*/ }
        | expression '&' expression     { /*$$ = $1 && $3;*/ }
        | expression '+' expression     { /*$$ = $1 + $3;*/ printf("add\n");}
        | expression '-' expression     { /*$$ = $1 - $3; printf("sub\n");*/}
        | expression '*' expression     { /*$$ = $1 * $3; printf("mul\n");*/}
        | expression '/' expression     { /*$$ = $1 / $3; printf("div\n");*/}
        | '~' expression                { /*$$ = !$2; */}
        | '-' expression                { /*$$ = -$2; */}
        | '(' expression ')'            { /*$$ = $2; */}
        ;
datatype:
        INT
        | FLOAT
        | BOOL
        | CHARACTER
        | STRING
        ;

scope:
        '{' program '}' { printf("scope\n");}
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

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
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
