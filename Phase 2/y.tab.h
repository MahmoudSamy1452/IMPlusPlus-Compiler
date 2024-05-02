
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 1 "parser.y"

    #include "SymbolTable.h"
    #include "structs.h"



/* Line 1676 of yacc.c  */
#line 47 "y.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOATING = 259,
     BOOLEAN = 260,
     VARIABLE = 261,
     CHAR = 262,
     CHARARRAY = 263,
     WHILE = 264,
     REPEAT = 265,
     UNTIL = 266,
     FOR = 267,
     SWITCH = 268,
     CASE = 269,
     IF = 270,
     THEN = 271,
     ELSE = 272,
     RETURN = 273,
     CONST = 274,
     GE = 275,
     LE = 276,
     EQ = 277,
     NE = 278,
     VOID = 279,
     FUNCTION = 280,
     INT = 281,
     FLOAT = 282,
     BOOL = 283,
     CHARACTER = 284,
     STRING = 285
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOATING 259
#define BOOLEAN 260
#define VARIABLE 261
#define CHAR 262
#define CHARARRAY 263
#define WHILE 264
#define REPEAT 265
#define UNTIL 266
#define FOR 267
#define SWITCH 268
#define CASE 269
#define IF 270
#define THEN 271
#define ELSE 272
#define RETURN 273
#define CONST 274
#define GE 275
#define LE 276
#define EQ 277
#define NE 278
#define VOID 279
#define FUNCTION 280
#define INT 281
#define FLOAT 282
#define BOOL 283
#define CHARACTER 284
#define STRING 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "parser.y"

    float value;                /* float value */
    char* string;               /* string value */
    Type type;                  /* data type */
    Value* val;                 /* value */



/* Line 1676 of yacc.c  */
#line 133 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


