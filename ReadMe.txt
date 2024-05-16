1. open `src` folder where you can find lexer.l & parser.y. You can already find compiler.exe. In case you want to generate a new compiler.exe, run the following commands:
a. flex lexer.l
b. bison --yacc -d ./parser.y
c. g++ .\lex.yy.c .\y.tab.c .\SymbolTable.cpp -o compiler -std=c++11

2. Run compiler on any txt file of your choice by running the following command: 
a. ./compiler.exe ./testcase.txt



To Run GUI, please make sure that you have node installed and followed the previous compilation steps:
1. Navigate to `Backend` folder and run the following commands:
a. cp ../src/compiler.exe .
a. npm i
b. node index.js

2. Navigate to `Frontend` folder and run the following commands:
a. npm i
b. npm run dev