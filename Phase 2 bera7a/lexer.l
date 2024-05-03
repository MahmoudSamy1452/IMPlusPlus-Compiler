
%{
  #include "y.tab.h"
  #include "structs.h"
  #include "enums.h"
  void yyerror(const char*);
  int count = 1;
%}
%%

([1-9][0-9]*|0)         {
                          int* p = new int(atoi(yytext));
                          yylval.val = new Value{p, Type::TYPE_INT};
                          return INTEGER;
                        }

([1-9][0-9]*|0)\.[0-9]+ {
                          double* p = new double(atof(yytext));
                          yylval.val = new Value{p, Type::TYPE_FLOAT};
                          return FLOATING;
                        }
                        
\'[^\']?\'              {
                          char* p = new char(atof(yytext));
                          yylval.val = new Value{p, Type::TYPE_CHAR};
                          return CHAR;
                        }                       

\"[^\"]*\"              {
                          yylval.val = new Value{(void*)yytext, Type::TYPE_CHAR_ARRAY};
                          return CHARARRAY;
                        }

("True"|"False")        {

                          int* p = new int(atoi(yytext));
                          yylval.val = new Value{p, Type::TYPE_BOOL};
                          return BOOLEAN;
                        }

[-+/*(){}.=;&|~><?:,]   {
                          yylval.string = strdup(yytext);
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
                          yylval.string = strdup(yytext);
                          printf("Variable %s\n", yylval.string);
                          return VARIABLE;
                        }

[ \t\n]+        ;       /* ignore whitespace */
\/\/.*          ;       /* ignore comments */

.              ; yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
