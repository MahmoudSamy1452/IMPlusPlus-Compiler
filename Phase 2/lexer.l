%{
  #include "y.tab.h"
  #include "enums.h"
  #include "structs.h"
  void yyerror(char*);
  int count = 1;
%}

%%

([1-9][0-9]*|0)         {
                          yylval.val = {atoi(yytext), TYPE::INT};
                          return INTEGER;
                        }

([1-9][0-9]*|0)\.[0-9]+ {
                          yylval.val = {atof(yytext), TYPE::FLOAT};
                          return FLOATING;
                        }
                        
\'[^\']?\'               {
                          yylval.val = {yytext, TYPE::CHAR};
                          return CHAR;
                        }                       

\"[^\"]*\"              {
                          yylval.val = {yytext, TYPE::CHAR_ARRAY};
                          return STRING;
                        }

("True"|"False")        {
                          yylval.val = {(yytext == "True" ? 1 : 0), TYPE::BOOL};
                          return BOOLEAN;
                        }

[-+/*(){}.=;&|~><?:,]   {
                          yylval.val = yytext;
                          return *yytext;
                        }

"while"         return WHILE;
"repeat"        return REPEAT;
"until"         return UNTIL;
"for"           return FOR;
"switch"        return SWITCH;
"case"          return CASE;
"if"            return IF;
"then"          return THEN;
"else"          return ELSE;
"function"      return FUNCTION;
"ret"           return RETURN;
"int"           return INT;
"float"         return FLOAT;
"bool"          return BOOL;
"char"          return CHARACTER;
"string"        return STRING;
"const"         return CONST;
"void"          return VOID;
">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;

[a-zA-Z_][a-zA-Z0-9_]*  {
                          yylval.string = yytext;
                          return VARIABLE;
                        }

[ \t\n]+        ;       /* ignore whitespace */
\/\/.*          ;       /* ignore comments */

.              ; yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
