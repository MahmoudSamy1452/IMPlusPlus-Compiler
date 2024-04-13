
%{
  #include "y.tab.h"
  int count = 1;
%}
%%

([1-9][0-9]*|0)         {
                          yylval.value = atoi(yytext);
                          return INTEGER;
                        }

([1-9][0-9]*|0)\.[0-9]+ {
                          yylval.value = atof(yytext);
                          return FLOATING;
                        }
                        
(\"|\')[^$1]$1           {
                          yylval.string = yytext;
                          return CHAR;
                        }                        

(\"|\')[^$1]*$1         {
                          yylval.string = yytext;
                          return CHARARRAY;
                        }

("True"|"False")        {
                          yylval.value = (yytext == "True" ? 1 : 0);
                          return BOOLEAN;
                        }

[-+/*(){}.=;&|~><(==)(!=)(<=)(>=)?:,] {
                                        yylval.string = yytext;
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
'>='            return GE;
'<='            return LE;
'=='            return EQ;
'!='            return NE;

[a-z_]+[a-zA-Z0-9_]*    { 
                          yylval.sIndex = count++;
                          yylval.string = yytext;
                          return VARIABLE;
                        }

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
