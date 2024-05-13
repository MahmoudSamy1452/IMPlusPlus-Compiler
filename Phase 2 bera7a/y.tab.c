
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 11 ".\\parser.y"

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



/* Line 189 of yacc.c  */
#line 98 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 1 ".\\parser.y"

    #include "SymbolTable.h"
    #include "structs.h"
    #include <stack>
    #include <utility>
    #include <queue>
    #include <string>
    #include <fstream>



/* Line 209 of yacc.c  */
#line 134 "y.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     CHARARRAY = 259,
     INTEGER = 260,
     FLOATING = 261,
     BOOLEAN = 262,
     VARIABLE = 263,
     WHILE = 264,
     REPEAT = 265,
     UNTIL = 266,
     FOR = 267,
     SWITCH = 268,
     CASE = 269,
     IF = 270,
     THEN = 271,
     ELSE = 272,
     FUNCTION = 273,
     RETURN = 274,
     INT = 275,
     FLOAT = 276,
     CHARACTER = 277,
     STRING = 278,
     BOOL = 279,
     VOID = 280,
     CONST = 281,
     GE = 282,
     LE = 283,
     EQ = 284,
     NE = 285
   };
#endif
/* Tokens.  */
#define CHAR 258
#define CHARARRAY 259
#define INTEGER 260
#define FLOATING 261
#define BOOLEAN 262
#define VARIABLE 263
#define WHILE 264
#define REPEAT 265
#define UNTIL 266
#define FOR 267
#define SWITCH 268
#define CASE 269
#define IF 270
#define THEN 271
#define ELSE 272
#define FUNCTION 273
#define RETURN 274
#define INT 275
#define FLOAT 276
#define CHARACTER 277
#define STRING 278
#define BOOL 279
#define VOID 280
#define CONST 281
#define GE 282
#define LE 283
#define EQ 284
#define NE 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 35 ".\\parser.y"

    float value;                /* float value */
    char* string;               /* string value */
    Type type;
    Value* val;
    queue<Type>* types;



/* Line 214 of yacc.c  */
#line 221 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 233 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,     2,
      42,    43,    38,    36,    46,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    41,
      34,    31,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,    32,    45,    40,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    11,    14,    19,    25,    29,
      31,    33,    35,    40,    42,    44,    46,    52,    59,    66,
      74,    76,    83,    92,    95,   100,   103,   105,   107,   109,
     114,   116,   118,   120,   122,   124,   126,   131,   135,   139,
     142,   147,   149,   150,   154,   156,   158,   159,   164,   170,
     172,   174,   176,   178,   182,   186,   190,   194,   198,   202,
     206,   210,   214,   218,   222,   226,   229,   232,   236,   238,
     240,   242,   244,   246,   248,   252,   256,   260,   264,   268,
     272,   276,   280,   284,   288,   292,   296,   299,   302,   306,
     308,   310,   312,   314,   316,   320
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    54,    41,    49,    -1,    -1,    41,    49,
      -1,    75,     8,    -1,    75,     8,    31,    52,    -1,    26,
      75,     8,    31,    52,    -1,     8,    31,    52,    -1,     3,
      -1,     4,    -1,    74,    -1,     8,    42,    69,    43,    -1,
      50,    -1,    51,    -1,    53,    -1,    55,    42,    74,    59,
      76,    -1,    56,    76,    11,    42,    74,    43,    -1,    57,
      74,    61,    51,    62,    76,    -1,    13,    42,    71,    60,
      44,    70,    45,    -1,    76,    -1,    58,    42,    74,    59,
      16,    76,    -1,    58,    42,    74,    59,    16,    76,    63,
      76,    -1,    64,    76,    -1,     8,    42,    69,    43,    -1,
      19,    52,    -1,    19,    -1,     9,    -1,    10,    -1,    12,
      42,    53,    41,    -1,    15,    -1,    43,    -1,    43,    -1,
      41,    -1,    43,    -1,    17,    -1,    65,    42,    67,    43,
      -1,    18,    75,     8,    -1,    18,    25,     8,    -1,    75,
       8,    -1,    75,     8,    46,    66,    -1,    66,    -1,    -1,
      52,    46,    68,    -1,    52,    -1,    68,    -1,    -1,    14,
      71,    72,    73,    -1,    14,    71,    72,    73,    70,    -1,
       5,    -1,     7,    -1,     3,    -1,     8,    -1,    71,    34,
      71,    -1,    71,    35,    71,    -1,    71,    28,    71,    -1,
      71,    27,    71,    -1,    71,    29,    71,    -1,    71,    30,
      71,    -1,    71,    32,    71,    -1,    71,    33,    71,    -1,
      71,    36,    71,    -1,    71,    37,    71,    -1,    71,    38,
      71,    -1,    71,    39,    71,    -1,    40,    71,    -1,    37,
      71,    -1,    42,    71,    43,    -1,    47,    -1,    76,    -1,
       6,    -1,     5,    -1,     7,    -1,     8,    -1,    74,    34,
      74,    -1,    74,    35,    74,    -1,    74,    28,    74,    -1,
      74,    27,    74,    -1,    74,    29,    74,    -1,    74,    30,
      74,    -1,    74,    32,    74,    -1,    74,    33,    74,    -1,
      74,    36,    74,    -1,    74,    37,    74,    -1,    74,    38,
      74,    -1,    74,    39,    74,    -1,    40,    74,    -1,    37,
      74,    -1,    42,    74,    43,    -1,    20,    -1,    21,    -1,
      24,    -1,    22,    -1,    23,    -1,    77,    49,    45,    -1,
      44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    62,    63,    67,    70,    79,    89,    99,
     100,   101,   102,   118,   119,   123,   124,   128,   132,   146,
     147,   148,   149,   150,   151,   171,   181,   192,   199,   206,
     213,   219,   223,   228,   232,   236,   240,   244,   245,   249,
     250,   254,   255,   259,   260,   264,   265,   269,   274,   287,
     291,   295,   299,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   322,   330,
     338,   344,   350,   356,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   381,
     382,   383,   384,   385,   389,   398
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "CHARARRAY", "INTEGER",
  "FLOATING", "BOOLEAN", "VARIABLE", "WHILE", "REPEAT", "UNTIL", "FOR",
  "SWITCH", "CASE", "IF", "THEN", "ELSE", "FUNCTION", "RETURN", "INT",
  "FLOAT", "CHARACTER", "STRING", "BOOL", "VOID", "CONST", "GE", "LE",
  "EQ", "NE", "'='", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'~'", "';'", "'('", "')'", "'{'", "'}'", "','", "':'", "$accept",
  "program", "declaration", "assignment", "assignmentValue",
  "initialization", "statement", "whileLoop", "repeatLoop", "forLoop",
  "ifCondition", "endBracketJump", "endCaseExpression", "semicolonJump",
  "endForDeclaration", "elseLabel", "funcDeclaration", "funcHeader",
  "argumentsList", "arguments", "parametersList", "parameters", "case",
  "caseExpression", "caseColon", "caseScope", "expression", "datatype",
  "scope", "scopeInit", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    61,   124,    38,    60,    62,    43,    45,    42,    47,
     126,    59,    40,    41,   123,   125,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    50,    51,    52,
      52,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    76,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     4,     5,     3,     1,
       1,     1,     4,     1,     1,     1,     5,     6,     6,     7,
       1,     6,     8,     2,     4,     2,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     2,
       4,     1,     0,     3,     1,     1,     0,     4,     5,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    27,    28,     0,     0,    30,     0,    26,    89,
      90,    92,    93,    91,     0,     3,    95,     0,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       3,     0,    46,     0,     0,     0,     0,     9,    10,    71,
      70,    72,    73,     0,     0,     0,    25,    11,     0,     4,
       1,     3,     0,     0,    73,     0,     0,    23,    42,     5,
       0,     8,    44,    45,     0,     0,     0,    51,    49,    50,
      52,     0,     0,     0,     0,    38,    37,    46,    87,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,    33,     0,     0,
      41,     0,     0,     0,    94,     0,    24,    29,    66,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,    88,    77,    76,    78,
      79,    80,    81,    74,    75,    82,    83,    84,    85,     0,
      31,     0,     0,     0,     0,    36,    39,     6,    43,    67,
      56,    55,    57,    58,    59,    60,    53,    54,    61,    62,
      63,    64,     0,    12,     7,    16,     0,    34,     0,     0,
       0,     0,     0,    17,    18,    21,    40,     0,    19,    35,
       0,    68,     0,    22,    47,    69,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    62,    20,    21,    22,    23,    24,
      25,   141,   124,    98,   168,   180,    26,    27,   100,   101,
      63,    64,   172,    74,   182,   184,    47,    28,    29,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -40
static const yytype_int16 yypact[] =
{
      86,   -26,   -40,   -40,   -36,   -24,   -40,    16,     5,   -40,
     -40,   -40,   -40,   -40,   102,    86,   -40,    21,   -40,   -40,
     -40,   -13,     1,   -14,    50,     2,   -14,     4,    40,   -40,
      86,     5,     5,    94,    12,    45,    51,   -40,   -40,   -40,
     -40,   -40,    44,    50,    50,    50,   -40,   253,    80,   -40,
     -40,    86,    50,    78,   -40,   238,    50,   -40,   102,    60,
      48,   -40,    54,   -40,    68,    72,    87,   -40,   -40,   -40,
     -40,    12,    12,    12,   153,   -40,   -40,     5,   -12,   -40,
     170,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    82,   -40,   187,    89,   -40,   121,   187,
     -40,    95,   131,     5,   -40,     5,   -40,   -40,    46,   -40,
     204,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,   -40,    96,   112,   -40,    98,    98,    98,
      98,   115,   279,    98,    98,   -12,   -12,   -40,   -40,     5,
     -40,   -14,    50,   113,   125,   -40,   111,   -40,   -40,   -40,
     296,   296,   296,   296,   266,   292,   296,   296,    46,    46,
     -40,   -40,   145,   -40,   -40,   -40,   221,   -40,   -14,   -14,
     102,    12,   116,   -40,   -40,   151,   -40,   137,   -40,   -40,
     -14,   -40,   -14,   -40,   145,   -40,   -40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,    -1,   -40,    64,    -6,   144,   -40,   -40,   -40,   -40,
     -40,    79,   -40,   -40,   -40,   -40,   -40,   -40,     9,   -40,
      88,   117,    11,   -39,   -40,   -40,   -21,    -7,   -22,   -40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      36,    53,    46,    55,    57,    31,    33,    48,    37,    38,
      39,    40,    41,    42,    49,    67,    32,    68,    34,    69,
      70,    50,    78,    79,    80,    61,    91,    92,    51,    60,
      16,    95,   108,   109,   110,    99,     9,    10,    11,    12,
      13,    35,    43,    52,    56,    44,    58,    45,    59,    71,
      94,   102,    72,    75,    73,    39,    40,    41,    54,    76,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   121,   122,    77,    43,    93,    96,
      44,   103,    45,   104,     1,     2,     3,   147,     4,     5,
     105,     6,    65,    31,     7,     8,     9,    10,    11,    12,
      13,   106,    14,   139,     9,    10,    11,    12,    13,   165,
      14,   166,     9,    10,    11,    12,    13,    15,   107,    65,
      16,   142,   177,   164,    89,    90,    91,    92,   145,   146,
     162,   169,    81,    82,    83,    84,   174,   175,    86,    87,
      88,    89,    90,    91,    92,   163,   167,   170,   183,   171,
     185,   178,   143,   102,   111,   112,   113,   114,   179,   115,
     116,   117,   118,   119,   120,   121,   122,    66,   144,   176,
     111,   112,   113,   114,   181,   115,   116,   117,   118,   119,
     120,   121,   122,   148,   125,   186,   123,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,   126,    81,    82,    83,    84,     0,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
     140,   111,   112,   113,   114,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   149,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,   173,    81,    82,    83,    84,     0,
      85,    86,    87,    88,    89,    90,    91,    92,     0,    97,
      81,    82,    83,    84,     0,    85,    86,    87,    88,    89,
      90,    91,    92,   111,   112,   113,   114,     0,     0,   116,
     117,   118,   119,   120,   121,   122,    81,    82,    83,    84,
       0,     0,     0,    87,    88,    89,    90,    91,    92,   111,
     112,   113,   114,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   119,   120,   121,   122
};

static const yytype_int16 yycheck[] =
{
       7,    23,     8,    24,    26,    31,    42,    14,     3,     4,
       5,     6,     7,     8,    15,     3,    42,     5,    42,     7,
       8,     0,    43,    44,    45,    31,    38,    39,    41,    30,
      44,    52,    71,    72,    73,    56,    20,    21,    22,    23,
      24,    25,    37,    42,    42,    40,    42,    42,     8,    37,
      51,    58,    40,     8,    42,     5,     6,     7,     8,     8,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    38,    39,    42,    37,     8,    11,
      40,    31,    42,    45,     8,     9,    10,   103,    12,    13,
      46,    15,     8,    31,    18,    19,    20,    21,    22,    23,
      24,    43,    26,    31,    20,    21,    22,    23,    24,   141,
      26,   142,    20,    21,    22,    23,    24,    41,    41,     8,
      44,    42,   171,   139,    36,    37,    38,    39,    43,     8,
      44,    16,    27,    28,    29,    30,   168,   169,    33,    34,
      35,    36,    37,    38,    39,    43,    43,    46,   180,    14,
     182,    45,    98,   170,    27,    28,    29,    30,    17,    32,
      33,    34,    35,    36,    37,    38,    39,    33,    99,   170,
      27,    28,    29,    30,    47,    32,    33,    34,    35,    36,
      37,    38,    39,   105,    77,   184,    43,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    27,    28,    29,    30,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    27,    28,    29,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    27,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    12,    13,    15,    18,    19,    20,
      21,    22,    23,    24,    26,    41,    44,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    64,    65,    75,    76,
      77,    31,    42,    42,    42,    25,    75,     3,     4,     5,
       6,     7,     8,    37,    40,    42,    52,    74,    75,    49,
       0,    41,    42,    76,     8,    74,    42,    76,    42,     8,
      49,    52,    52,    68,    69,     8,    53,     3,     5,     7,
       8,    37,    40,    42,    71,     8,     8,    42,    74,    74,
      74,    27,    28,    29,    30,    32,    33,    34,    35,    36,
      37,    38,    39,     8,    49,    74,    11,    41,    61,    74,
      66,    67,    75,    31,    45,    46,    43,    41,    71,    71,
      71,    27,    28,    29,    30,    32,    33,    34,    35,    36,
      37,    38,    39,    43,    60,    69,    43,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    31,
      43,    59,    42,    51,    59,    43,     8,    52,    68,    43,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    44,    43,    52,    76,    74,    43,    62,    16,
      46,    14,    70,    43,    76,    76,    66,    71,    45,    17,
      63,    47,    72,    76,    73,    76,    70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 61 ".\\parser.y"
    {symTable->checkUnusedVariables();}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 62 ".\\parser.y"
    {symTable->checkUnusedVariables();}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 63 ".\\parser.y"
    {symTable->checkUnusedVariables();}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 67 ".\\parser.y"
    {       
                                                                symTable->insert((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].type));
                                                        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 70 ".\\parser.y"
    { 

                                                                symTable->insert((yyvsp[(2) - (4)].string), (yyvsp[(1) - (4)].type), (yyvsp[(4) - (4)].val)->value);
                                                                symTable->setValue((yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].val));
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)(yyvsp[(2) - (4)].string));
                                                                else
                                                                        quadFile << "POP " << (yyvsp[(2) - (4)].string) << endl;
                                                        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 79 ".\\parser.y"
    {       symTable->insert((yyvsp[(3) - (5)].string), (yyvsp[(2) - (5)].type), (yyvsp[(5) - (5)].val)->value, true);
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)(yyvsp[(3) - (5)].string));
                                                                else
                                                                        cout << "POP " << (yyvsp[(3) - (5)].string) << endl;
                                                        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 89 ".\\parser.y"
    { symTable->setValue((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].val));
                                                          if(forCount > 0){
                                                                forStack.push("POP " + (string)(yyvsp[(1) - (3)].string));
                                                          }
                                                          else
                                                              cout << "POP " << (yyvsp[(1) - (3)].string) << endl;
                                                        }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 99 ".\\parser.y"
    { cout << "PUSH " << *(char*)(yyvsp[(1) - (1)].val)->value << endl; (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 100 ".\\parser.y"
    { cout << "PUSH " << (string)reinterpret_cast<char*>((yyvsp[(1) - (1)].val)->value) << endl; (yyval.val) = (yyvsp[(1) - (1)].val); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 102 ".\\parser.y"
    {
                                        if(symTable->lookup((yyvsp[(1) - (4)].string)) == nullptr) {
                                            throwError("function " + string((yyvsp[(1) - (4)].string)) + " not declared\n");
                                        }
                                        else if(symTable->lookup((yyvsp[(1) - (4)].string))->type != Type::TYPE_FUNC) {
                                            throwError(string((yyvsp[(1) - (4)].string)) + " is not a function\n");
                                        }
                                        else if(symTable->lookup((yyvsp[(1) - (4)].string))->args->size() != (yyvsp[(3) - (4)].types)->size()) {
                                            throwError("function " + string((yyvsp[(1) - (4)].string)) + " argument size mismatch\n");
                                        }
                                        cout << "CALL " << (yyvsp[(1) - (4)].string) << endl; 
                                        (yyval.val) = new Value{nullptr, *symTable->lookup((yyvsp[(1) - (4)].string))->returnType};
                                }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 124 ".\\parser.y"
    { 
                                                                                cout << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 128 ".\\parser.y"
    { 
                                                                                cout << "JZ Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 132 ".\\parser.y"
    {
                                                                                stack<string> tempStack;
                                                                                while (forStack.top() != "@"){
                                                                                    tempStack.push(forStack.top());
                                                                                    forStack.pop();
                                                                                }
                                                                                forStack.pop();
                                                                                while (!tempStack.empty()){
                                                                                    cout << tempStack.top() << endl;
                                                                                    tempStack.pop();
                                                                                }
                                                                                cout << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                               }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 146 ".\\parser.y"
    { cout << "OutLabel" << switchStack.top() << ":" << endl;                                                                       switchStack.pop(); labelsStack.pop(); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 148 ".\\parser.y"
    { cout << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 149 ".\\parser.y"
    { cout << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 151 ".\\parser.y"
    {
                                        if(symTable->lookup((yyvsp[(1) - (4)].string)) == nullptr) {
                                            throwError("function " + string((yyvsp[(1) - (4)].string)) + " not declared\n");
                                        }
                                        else if(symTable->lookup((yyvsp[(1) - (4)].string))->type != Type::TYPE_FUNC) {
                                            throwError(string((yyvsp[(1) - (4)].string)) + " is not a function\n");
                                        }
                                        else if(symTable->lookup((yyvsp[(1) - (4)].string))->args->size() != (yyvsp[(3) - (4)].types)->size()) {
                                            throwError("function " + string((yyvsp[(1) - (4)].string)) + " argument size mismatch\n");
                                        }
                                        auto params = (yyvsp[(3) - (4)].types);
                                        auto args = *symTable->lookup((yyvsp[(1) - (4)].string))->args;
                                        for(auto arg: args) {
                                            if(arg.first != params->front()) {
                                                throwError("argument type mismatch\n");
                                            }
                                            params->pop();
                                        }
                                        cout << "CALL " << (yyvsp[(1) - (4)].string) << endl; 
                                }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 171 ".\\parser.y"
    {
                                    cout << "POP " << "$retvalue" << endl;
                                    cout << "RET " << "$retvalue" << endl;
                                //     cout << "function name: " <<symTable->getFunctionName() << endl;
                                    if(symTable->getFunctionName() == nullptr) {
                                        throwError("return statement outside function\n");
                                    }
                                    else if(*symTable->getReturnType(*symTable->getFunctionName()) != (yyvsp[(2) - (2)].val)->type) {throwError("return type mismatch\n");}
                                    symTable->setIsReturned();
                                 }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 181 ".\\parser.y"
    {
                                    cout << "RET" << endl;
                                    if(symTable->getFunctionName() == nullptr) {
                                        throwError("return statement outside function\n");
                                    }
                                    else if(*symTable->getReturnType(*symTable->getFunctionName()) != Type::TYPE_VOID) {throwError("return type mismatch\n");}
                                    symTable->setIsReturned();
                                 }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 192 ".\\parser.y"
    { 
                                        cout << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 199 ".\\parser.y"
    { 
                                        cout << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 ".\\parser.y"
    { 
                                                cout << endl << "Label" << labels << ": " << endl;
                                                labelsStack.push(labels++);
                                        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 213 ".\\parser.y"
    { 
                                                labelsStack.push(labels++); 
                                        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 219 ".\\parser.y"
    { cout << "JZ OutLabel" << labelsStack.top() << endl; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 223 ".\\parser.y"
    { cout << "POP $t" << labels << endl; labelsStack.push(labels++); switchStack.push(labels++);
                cout << "Stack top in endCaseExpression: " << labelsStack.top() << endl; }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 228 ".\\parser.y"
    { cout << "JZ OutLabel" << labelsStack.top() << endl; forCount++; forStack.push("@"); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 232 ".\\parser.y"
    { forCount--; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 236 ".\\parser.y"
    { cout << "JMP OutLabel" << labels << '\n' << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); labelsStack.push(labels++); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 244 ".\\parser.y"
    { cout << (yyvsp[(3) - (3)].string) << ':' << endl; symTable->insert((yyvsp[(3) - (3)].string), Type::TYPE_FUNC, nullptr, false, new vector<pair<Type, string>>(), new Type((yyvsp[(2) - (3)].type))); currentFunction = new string((yyvsp[(3) - (3)].string));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 245 ".\\parser.y"
    { cout << (yyvsp[(3) - (3)].string) << ':' << endl; symTable->insert((yyvsp[(3) - (3)].string), Type::TYPE_FUNC, nullptr, false, new vector<pair<Type, string>>(), new Type(Type::TYPE_VOID)); currentFunction = new string((yyvsp[(3) - (3)].string));}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 249 ".\\parser.y"
    { cout << "POP " << (yyvsp[(2) - (2)].string) << endl; symTable->addArgs(*currentFunction, (yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].type)); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 250 ".\\parser.y"
    { cout << "POP " << (yyvsp[(2) - (4)].string) << endl; symTable->addArgs(*currentFunction, (yyvsp[(2) - (4)].string), (yyvsp[(1) - (4)].type));}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 259 ".\\parser.y"
    {(yyvsp[(3) - (3)].types)->push((yyvsp[(1) - (3)].val)->type); (yyval.types) = (yyvsp[(3) - (3)].types);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 260 ".\\parser.y"
    {(yyval.types) = new queue<Type>(); (yyval.types)->push((yyvsp[(1) - (1)].val)->type);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 264 ".\\parser.y"
    {(yyval.types) = (yyvsp[(1) - (1)].types);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 265 ".\\parser.y"
    {(yyval.types) = new queue<Type>();}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 269 ".\\parser.y"
    { 
                                                                        // cout << "JMP OutLabel" << switchStack.top() << endl << "label" << labelsStack.top() << ":" << endl;
                                                                        // labelsStack.pop();
                                                                        cout << "Stack top in case: " << labelsStack.top() << endl;
                                                                }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 274 ".\\parser.y"
    { 
                                                                        // cout << "JMP OutLabel" << switchStack.top() << endl << "label" << labelsStack.top() << ":" << endl;
                                                                        // labelsStack.pop();
                                                                        cout << "Stack top in case case: " << labelsStack.top() << endl;
                                                                }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 287 ".\\parser.y"
    {  
                                                (yyval.val) = (yyvsp[(1) - (1)].val);
                                                cout << "PUSH " << *(int*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 291 ".\\parser.y"
    { 
                                                (yyval.val) = (yyvsp[(1) - (1)].val);
                                                cout << "PUSH " << *(bool*)(yyvsp[(1) - (1)].val)->value << endl ;
                                        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 295 ".\\parser.y"
    { 
                                                (yyval.val) = (yyvsp[(1) - (1)].val);
                                                cout << "PUSH " << *(char*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 299 ".\\parser.y"
    { 
                                                Type t = symTable->getType((yyvsp[(1) - (1)].string));
                                                (yyval.val) = new Value{symTable->getValue((yyvsp[(1) - (1)].string)), symTable->getType((yyvsp[(1) - (1)].string))};
                                                cout << "PUSH " << (yyvsp[(1) - (1)].string) << endl;
                                        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 304 ".\\parser.y"
    { implementOperation(OP::LeT, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type);  (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 305 ".\\parser.y"
    { implementOperation(OP::GrT, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 306 ".\\parser.y"
    { implementOperation(OP::LeE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 307 ".\\parser.y"
    { implementOperation(OP::GrE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 308 ".\\parser.y"
    { implementOperation(OP::EQQ, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 309 ".\\parser.y"
    { implementOperation(OP::NoE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 310 ".\\parser.y"
    { implementOperation(OP::OR, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 311 ".\\parser.y"
    { implementOperation(OP::AND, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 312 ".\\parser.y"
    { implementOperation(OP::PLUS, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 313 ".\\parser.y"
    { implementOperation(OP::MINUS, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 314 ".\\parser.y"
    { implementOperation(OP::MULTIPLY, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 315 ".\\parser.y"
    { implementOperation(OP::DIVIDE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 316 ".\\parser.y"
    { implementOperation(OP::NOT, forCount,&forStack, (yyvsp[(2) - (2)].val)->type, (yyvsp[(2) - (2)].val)->type); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 317 ".\\parser.y"
    { implementOperation(OP::NEG, forCount,&forStack, (yyvsp[(2) - (2)].val)->type, (yyvsp[(2) - (2)].val)->type); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 318 ".\\parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 322 ".\\parser.y"
    {   
                                        cout << "PUSH $t" << labelsStack.top() << endl << "EQ" << endl << "JZ label" << labels << endl; 
                                        labelsStack.push(labels++); 
                                        cout << "Stack top in caseColon: " << labelsStack.top() << endl;
                                }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 330 ".\\parser.y"
    { 
                                        cout << "JMP OutLabel" << switchStack.top() << endl << "label " << labelsStack.top() << ":" << endl;
                                        labelsStack.pop();
                                        cout << "Stack top in caseScope: " << labelsStack.top() << endl;
                                }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 338 ".\\parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(float*)(yyvsp[(1) - (1)].val)->value));
                                            else
                                                cout << "PUSH " << *(float*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 344 ".\\parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(int*)(yyvsp[(1) - (1)].val)->value));
                                            else
                                                cout << "PUSH " << *(int*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 350 ".\\parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(bool*)(yyvsp[(1) - (1)].val)->value));
                                            else
                                                cout << "PUSH " << *(int*)(yyvsp[(1) - (1)].val)->value << endl ;
                                        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 356 ".\\parser.y"
    { 
                                                if(forCount > 0)
                                                        forStack.push("PUSH " + (string)(yyvsp[(1) - (1)].string));
                                                else
                                                        cout << "PUSH " << (yyvsp[(1) - (1)].string) << endl;
                                                Type t = symTable->getType((yyvsp[(1) - (1)].string));
                                                (yyval.val) = new Value{symTable->getValue((yyvsp[(1) - (1)].string)), symTable->getType((yyvsp[(1) - (1)].string))};
                                        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 364 ".\\parser.y"
    { implementOperation(OP::LeT, forCount, &forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type);  (yyval.val) = (yyvsp[(1) - (3)].val); /* TODO: check on type and propagate*/}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 365 ".\\parser.y"
    { implementOperation(OP::GrT, forCount, &forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 366 ".\\parser.y"
    { implementOperation(OP::LeE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 367 ".\\parser.y"
    { implementOperation(OP::GrE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 368 ".\\parser.y"
    { implementOperation(OP::EQQ, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 369 ".\\parser.y"
    { implementOperation(OP::NoE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 370 ".\\parser.y"
    { implementOperation(OP::OR, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 371 ".\\parser.y"
    { implementOperation(OP::AND, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 372 ".\\parser.y"
    { implementOperation(OP::PLUS, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 373 ".\\parser.y"
    { implementOperation(OP::MINUS, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 374 ".\\parser.y"
    { implementOperation(OP::MULTIPLY, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 375 ".\\parser.y"
    { implementOperation(OP::DIVIDE, forCount,&forStack, (yyvsp[(1) - (3)].val)->type, (yyvsp[(3) - (3)].val)->type); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 376 ".\\parser.y"
    { implementOperation(OP::NOT, forCount,&forStack, (yyvsp[(2) - (2)].val)->type, (yyvsp[(2) - (2)].val)->type); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 377 ".\\parser.y"
    { implementOperation(OP::NEG, forCount,&forStack, (yyvsp[(2) - (2)].val)->type, (yyvsp[(2) - (2)].val)->type); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 378 ".\\parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val);}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 381 ".\\parser.y"
    { (yyval.type) = Type::TYPE_INT; }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 382 ".\\parser.y"
    { (yyval.type) = Type::TYPE_FLOAT; }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 383 ".\\parser.y"
    { (yyval.type) = Type::TYPE_BOOL; }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 384 ".\\parser.y"
    { (yyval.type) = Type::TYPE_CHAR; }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 385 ".\\parser.y"
    { (yyval.type) = Type::TYPE_CHAR_ARRAY; }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 389 ".\\parser.y"
    { 
                                if(symTable->getFunctionName() != nullptr && symTable->getIsReturned() == false) {
                                        throwError("Function " + *symTable->getFunctionName() + " is missing a return statement\n");
                                }
                                symTable->checkUnusedVariables();
                                symTable = symTable->getParentTable();}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 398 ".\\parser.y"
    {       
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
    break;



/* Line 1455 of yacc.c  */
#line 2381 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 429 ".\\parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

void throwError(string s) {
        cout << "Error at line " << yylineno << ": " << s << endl;
        const char *x = s.c_str();
        yyerror(x);
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

