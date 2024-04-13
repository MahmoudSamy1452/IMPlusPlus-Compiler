%{
    #include <stdio.h>
    void yyerror(char *);
    int yylex(void);

//     entry* sym[26]; /* index, const, val */
%}

%union {
    float value;                /* float value */
    char* string;               /* string value */
    char sIndex;                /* symbol table index */
};

%token <value> INTEGER FLOATING BOOLEAN
%token <string> CHAR CHARARRAY
%token <sIndex> VARIABLE
%token WHILE REPEAT UNTIL FOR SWITCH CASE IF THEN ELSE FUNCTION RETURN INT FLOAT CHARACTER STRING BOOL VOID CONST GE LE EQ NE
%type <value> expression

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
        ;

assignment:
        VARIABLE '=' expression                   /*{ sym[$1] = $3; }*/ /* check for const assignment */
        | datatype VARIABLE '=' expression        /*{ sym[$2] = $4; sym[$2].const = 0;}*/ /* check for redeclaration */
        | CONST datatype VARIABLE '=' expression  /*{ sym[$3].value = $5; sym[$3].const = 1; }*/
        ;

statement:
        assignment { printf("assignment\n");}
        | WHILE '(' expression ')' scope { printf("while\n");}
        | REPEAT scope UNTIL '(' expression ')' { printf("repeat\n");}
        | FOR '(' assignment ';' expression ';' expression ')' scope    { printf("for\n");}
        | SWITCH '(' expression ')' '{' case '}' /* check switch(exp) can be literal */ { printf("switch\n");}
        | scope { printf("scope\n");}
        | IF '(' expression ')' THEN scope { printf("if\n");}
        | IF '(' expression ')' THEN scope ELSE scope { printf("if else\n");}
        | FUNCTION datatype VARIABLE '(' ')' scope { printf("function\n");}
        | FUNCTION datatype VARIABLE '(' arguments ')' scope { printf("function\n");}
        | RETURN expression /* check return type */ { printf("return\n");}
        ;

arguments:
        datatype VARIABLE
        | datatype VARIABLE ',' arguments

case:
        CASE expression ':' scope
        | CASE expression ':' scope case
        ;

expression:
        INTEGER
        | FLOATING
        | BOOLEAN
        /* | CHAR  
        | CHARARRAY */
        | VARIABLE                      { $$ = 0; } // { $$ = sym[$1]; }
        | expression '<' expression     { $$ = $1 < $3; }
        | expression '>' expression     { $$ = $1 > $3; }
        | expression LE expression      { $$ = $1 <= $3; }
        | expression GE expression      { $$ = $1 >= $3;}
        | expression EQ expression      { $$ = $1 == $3; }
        | expression NE expression      { $$ = $1 != $3; }
        | expression '|' expression     { $$ = $1 || $3; }
        | expression '&' expression     { $$ = $1 && $3; }
        | expression '+' expression     { $$ = $1 + $3; printf("add\n");}
        | expression '-' expression     { $$ = $1 - $3; printf("sub\n");}
        | expression '*' expression     { $$ = $1 * $3; printf("mul\n");}
        | expression '/' expression     { $$ = $1 / $3; printf("div\n");}
        | '~' expression                { $$ = !$2; }
        | '-' expression                { $$ = -$2; }
        | '(' expression ')'            { $$ = $2; }
        ;

datatype:
        INT
        | FLOAT
        | BOOL
        | CHARACTER
        | STRING
        ;

scope:
        '{' program '}'
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
}
