build:
	flex .\lexer.l
	bison -d --yacc .\parser.y
	gcc -o mahmoud.exe lex.yy.c y.tab.c