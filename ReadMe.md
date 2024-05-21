# Instructions
1. open `src` folder where you can find lexer.l & parser.y. You can already find compiler.exe. In case you want to generate a new compiler.exe, run the following commands:
- flex lexer.l
- bison --yacc -d ./parser.y
- g++ .\lex.yy.c .\y.tab.c .\SymbolTable.cpp -o compiler -std=c++11

2. Run compiler on any txt file of your choice by running the following command: 
- ./compiler.exe ./testcase.txt

# GUI
To Run GUI, please make sure that you have node installed and followed the previous compilation steps:
1. Navigate to `Backend` folder and run the following commands:
- cp ../src/compiler.exe . (if you want to try out a new compiler.exe)
- npm i
- node index.js

2. Navigate to `Frontend` folder and run the following commands:
- npm i
- npm run dev


![Project Thumbnail](https://github.com/MahmoudSamy1452/IMPlusPlus-Compiler/assets/86854027/8e85f26a-c221-4274-9ee8-97b5e04b6d57)

