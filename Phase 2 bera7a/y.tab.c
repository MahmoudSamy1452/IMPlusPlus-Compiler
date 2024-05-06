
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
#line 10 "parser.y"

    #include <stdio.h>
    #include "structs.h"
    #include "SymbolTable.h"
    #include "codeGenerator.h"
    void yyerror(const char *);
    void throwError(string);
    int yylex(void);
    extern FILE *yyin;

    SymbolTable* symTable = new SymbolTable();
    std::stack<std::pair<bool, Type>> funcStack;
    std::stack<int> labelsStack;
    int forCount = 0, labels = 0;
    std::stack<string> forStack;
    std::stack<int> switchStack;


/* Line 189 of yacc.c  */
#line 92 "y.tab.c"

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
#line 1 "parser.y"

    #include "SymbolTable.h"
    #include "structs.h"
    #include <stack>
    #include <utility>
    #include <queue>
    #include <string>



/* Line 209 of yacc.c  */
#line 127 "y.tab.c"

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
#line 28 "parser.y"

    float value;                /* float value */
    char* string;               /* string value */
    Type type;
    Value* val;



/* Line 214 of yacc.c  */
#line 213 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "y.tab.c"

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  189

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
     114,   116,   118,   120,   122,   124,   126,   133,   140,   143,
     148,   150,   151,   155,   157,   159,   160,   165,   171,   173,
     175,   177,   179,   183,   187,   191,   195,   199,   203,   207,
     211,   215,   219,   223,   227,   230,   233,   237,   239,   241,
     243,   245,   247,   249,   253,   257,   261,   265,   269,   273,
     277,   281,   285,   289,   293,   297,   300,   303,   307,   309,
     311,   313,   315,   317,   321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    54,    41,    49,    -1,    -1,    41,    49,
      -1,    74,     8,    -1,    74,     8,    31,    52,    -1,    26,
      74,     8,    31,    52,    -1,     8,    31,    52,    -1,    73,
      -1,     3,    -1,     4,    -1,     8,    42,    68,    43,    -1,
      50,    -1,    51,    -1,    53,    -1,    55,    42,    73,    59,
      75,    -1,    56,    75,    11,    42,    73,    43,    -1,    57,
      73,    61,    51,    62,    75,    -1,    13,    42,    70,    60,
      44,    69,    45,    -1,    75,    -1,    58,    42,    73,    59,
      16,    75,    -1,    58,    42,    73,    59,    16,    75,    63,
      75,    -1,    64,    75,    -1,     8,    42,    68,    43,    -1,
      19,    52,    -1,    19,    -1,     9,    -1,    10,    -1,    12,
      42,    53,    41,    -1,    15,    -1,    43,    -1,    43,    -1,
      41,    -1,    43,    -1,    17,    -1,    18,    74,     8,    42,
      66,    43,    -1,    18,    25,     8,    42,    66,    43,    -1,
      74,     8,    -1,    74,     8,    46,    65,    -1,    65,    -1,
      -1,    52,    46,    67,    -1,    52,    -1,    67,    -1,    -1,
      14,    70,    71,    72,    -1,    14,    70,    71,    72,    69,
      -1,     5,    -1,     7,    -1,     3,    -1,     8,    -1,    70,
      34,    70,    -1,    70,    35,    70,    -1,    70,    28,    70,
      -1,    70,    27,    70,    -1,    70,    29,    70,    -1,    70,
      30,    70,    -1,    70,    32,    70,    -1,    70,    33,    70,
      -1,    70,    36,    70,    -1,    70,    37,    70,    -1,    70,
      38,    70,    -1,    70,    39,    70,    -1,    40,    70,    -1,
      37,    70,    -1,    42,    70,    43,    -1,    47,    -1,    75,
      -1,     6,    -1,     5,    -1,     7,    -1,     8,    -1,    73,
      34,    73,    -1,    73,    35,    73,    -1,    73,    28,    73,
      -1,    73,    27,    73,    -1,    73,    29,    73,    -1,    73,
      30,    73,    -1,    73,    32,    73,    -1,    73,    33,    73,
      -1,    73,    36,    73,    -1,    73,    37,    73,    -1,    73,
      38,    73,    -1,    73,    39,    73,    -1,    40,    73,    -1,
      37,    73,    -1,    42,    73,    43,    -1,    20,    -1,    21,
      -1,    24,    -1,    22,    -1,    23,    -1,    76,    49,    45,
      -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    53,    54,    58,    61,    69,    79,    89,
      90,    91,    92,    96,    97,   101,   102,   106,   110,   124,
     125,   126,   127,   128,   133,   134,   140,   147,   154,   161,
     168,   174,   178,   183,   187,   191,   195,   196,   200,   201,
     205,   206,   210,   211,   215,   216,   220,   225,   238,   242,
     246,   250,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   276,   284,   292,
     293,   299,   305,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   328,   329,
     330,   331,   332,   336,   340
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
  "endForDeclaration", "elseLabel", "funcDeclaration", "argumentsList",
  "arguments", "parametersList", "parameters", "case", "caseExpression",
  "caseColon", "caseScope", "expression", "datatype", "scope", "scopeInit", 0
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
      58,    59,    60,    61,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     4,     5,     3,     1,
       1,     1,     4,     1,     1,     1,     5,     6,     6,     7,
       1,     6,     8,     2,     4,     2,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     6,     6,     2,     4,
       1,     0,     3,     1,     1,     0,     4,     5,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    27,    28,     0,     0,    30,     0,    26,    88,
      89,    91,    92,    90,     0,     3,    94,     0,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,    20,     3,
       0,    45,     0,     0,     0,     0,    10,    11,    70,    69,
      71,    72,     0,     0,     0,    25,     9,     0,     4,     1,
       3,     0,     0,    72,     0,     0,    23,     5,     0,     8,
      43,    44,     0,     0,     0,    50,    48,    49,    51,     0,
       0,     0,     0,     0,     0,    45,    86,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    33,     0,     0,     0,    93,
       0,    24,    29,    65,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
      41,    41,     0,    87,    76,    75,    77,    78,    79,    80,
      73,    74,    81,    82,    83,    84,     0,    31,     0,     0,
       0,     0,     6,    42,    66,    55,    54,    56,    57,    58,
      59,    52,    53,    60,    61,    62,    63,     0,    40,     0,
       0,     0,    12,     7,    16,     0,    34,     0,     0,     0,
       0,    37,    38,    36,    17,    18,    21,     0,    19,     0,
      35,     0,    67,     0,    39,    22,    46,    68,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    60,    20,    21,    22,    23,    24,
      25,   138,   119,    96,   167,   181,    26,   158,   159,    61,
      62,   170,    72,   183,   186,    46,    27,    28,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int16 yypact[] =
{
      78,   -26,   -62,   -62,   -36,   -10,   -62,   103,    33,   -62,
     -62,   -62,   -62,   -62,   300,    78,   -62,    35,   -62,   -62,
     -62,    -8,     0,    27,    75,     2,    27,    71,   -62,    78,
      33,    33,     5,    69,    76,    77,   -62,   -62,   -62,   -62,
     -62,    47,    75,    75,    75,   -62,   241,    86,   -62,   -62,
      78,    75,    84,   -62,   226,    75,   -62,    72,    60,   -62,
      61,   -62,    67,    89,    80,   -62,   -62,   -62,   -62,    69,
      69,    69,   141,    87,    93,    33,   -27,   -62,   158,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,   113,   -62,   175,   110,   -62,   145,   175,    33,   -62,
      33,   -62,   -62,   -24,   -62,   192,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,   -62,   116,
     300,   300,   138,   -62,   -19,   -19,   -19,   -19,   254,   128,
     -19,   -19,   -27,   -27,   -62,   -62,    33,   -62,    27,    75,
     139,   167,   -62,   -62,   -62,   111,   111,   111,   111,   267,
     280,   111,   111,   -24,   -24,   -62,   -62,   140,   -62,   146,
     190,   156,   -62,   -62,   -62,   209,   -62,    27,    27,    69,
     155,   -62,   160,   -62,   -62,   -62,   198,   104,   -62,   300,
     -62,    27,   -62,    27,   -62,   -62,   140,   -62,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,    28,   -62,   120,    -6,   185,   -62,   -62,   -62,   -62,
     -62,   126,   -62,   -62,   -62,   -62,   -62,    53,   112,   134,
     165,    63,   -61,   -62,   -62,   -21,    -7,   -22,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    52,    45,    54,    56,    30,    32,    47,   103,   104,
     105,    89,    90,    63,   116,   117,    31,    87,    88,    89,
      90,    76,    77,    78,    59,     9,    10,    11,    12,    13,
      93,    14,    33,    50,    97,    49,    36,    37,    38,    39,
      40,    41,    51,    48,    55,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    58,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      42,    16,    65,    43,    66,    44,    67,    68,    92,    57,
      38,    39,    40,    53,    73,    74,     1,     2,     3,    75,
       4,     5,   142,     6,    91,    94,     7,     8,     9,    10,
      11,    12,    13,    98,    14,    99,    69,   100,   177,    70,
     101,    71,    42,   160,   160,    43,   164,    44,   165,    15,
      30,   102,    16,     9,    10,    11,    12,    13,    34,   120,
     163,   106,   107,   108,   109,   121,   110,   111,   112,   113,
     114,   115,   116,   117,   136,   175,   176,   114,   115,   116,
     117,   182,   139,    63,   169,    79,    80,    81,    82,   185,
     157,   187,    85,    86,    87,    88,    89,    90,   106,   107,
     108,   109,   160,   110,   111,   112,   113,   114,   115,   116,
     117,   162,   166,   168,   118,    79,    80,    81,    82,   171,
      83,    84,    85,    86,    87,    88,    89,    90,   172,   173,
     178,   123,    79,    80,    81,    82,   179,    83,    84,    85,
      86,    87,    88,    89,    90,   180,   140,    64,   137,   106,
     107,   108,   109,   141,   110,   111,   112,   113,   114,   115,
     116,   117,   184,   161,   143,   144,    79,    80,    81,    82,
     122,    83,    84,    85,    86,    87,    88,    89,    90,   188,
       0,     0,   174,    79,    80,    81,    82,     0,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    95,    79,    80,
      81,    82,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    79,    80,    81,    82,     0,     0,    84,    85,    86,
      87,    88,    89,    90,   106,   107,   108,   109,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   106,   107,   108,
     109,     0,     0,     0,   112,   113,   114,   115,   116,   117,
       9,    10,    11,    12,    13
};

static const yytype_int16 yycheck[] =
{
       7,    23,     8,    24,    26,    31,    42,    14,    69,    70,
      71,    38,    39,     8,    38,    39,    42,    36,    37,    38,
      39,    42,    43,    44,    30,    20,    21,    22,    23,    24,
      51,    26,    42,    41,    55,     0,     3,     4,     5,     6,
       7,     8,    42,    15,    42,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    29,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      37,    44,     3,    40,     5,    42,     7,     8,    50,     8,
       5,     6,     7,     8,     8,     8,     8,     9,    10,    42,
      12,    13,    98,    15,     8,    11,    18,    19,    20,    21,
      22,    23,    24,    31,    26,    45,    37,    46,   169,    40,
      43,    42,    37,   120,   121,    40,   138,    42,   139,    41,
      31,    41,    44,    20,    21,    22,    23,    24,    25,    42,
     136,    27,    28,    29,    30,    42,    32,    33,    34,    35,
      36,    37,    38,    39,    31,   167,   168,    36,    37,    38,
      39,    47,    42,     8,    14,    27,    28,    29,    30,   181,
      44,   183,    34,    35,    36,    37,    38,    39,    27,    28,
      29,    30,   179,    32,    33,    34,    35,    36,    37,    38,
      39,    43,    43,    16,    43,    27,    28,    29,    30,    43,
      32,    33,    34,    35,    36,    37,    38,    39,     8,    43,
      45,    43,    27,    28,    29,    30,    46,    32,    33,    34,
      35,    36,    37,    38,    39,    17,    96,    32,    43,    27,
      28,    29,    30,    97,    32,    33,    34,    35,    36,    37,
      38,    39,   179,   121,   100,    43,    27,    28,    29,    30,
      75,    32,    33,    34,    35,    36,    37,    38,    39,   186,
      -1,    -1,    43,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    27,    28,    29,    30,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    27,    28,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    27,    28,    29,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    12,    13,    15,    18,    19,    20,
      21,    22,    23,    24,    26,    41,    44,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    64,    74,    75,    76,
      31,    42,    42,    42,    25,    74,     3,     4,     5,     6,
       7,     8,    37,    40,    42,    52,    73,    74,    49,     0,
      41,    42,    75,     8,    73,    42,    75,     8,    49,    52,
      52,    67,    68,     8,    53,     3,     5,     7,     8,    37,
      40,    42,    70,     8,     8,    42,    73,    73,    73,    27,
      28,    29,    30,    32,    33,    34,    35,    36,    37,    38,
      39,     8,    49,    73,    11,    41,    61,    73,    31,    45,
      46,    43,    41,    70,    70,    70,    27,    28,    29,    30,
      32,    33,    34,    35,    36,    37,    38,    39,    43,    60,
      42,    42,    68,    43,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    31,    43,    59,    42,
      51,    59,    52,    67,    43,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    44,    65,    66,
      74,    66,    43,    52,    75,    73,    43,    62,    16,    14,
      69,    43,     8,    43,    43,    75,    75,    70,    45,    46,
      17,    63,    47,    71,    65,    75,    72,    75,    69
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
        case 5:

/* Line 1455 of yacc.c  */
#line 58 "parser.y"
    {       
                                                                symTable->insert((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].type));
                                                        }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    { 
                                                                symTable->insert((yyvsp[(2) - (4)].string), (yyvsp[(1) - (4)].type), (yyvsp[(4) - (4)].val)->value);
                                                                symTable->setValue((yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].val));
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)(yyvsp[(2) - (4)].string));
                                                                else
                                                                        cout << "POP " << (yyvsp[(2) - (4)].string) << endl;
                                                        }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    {       symTable->insert((yyvsp[(3) - (5)].string), (yyvsp[(2) - (5)].type), (yyvsp[(5) - (5)].val)->value, true);
                                                                if(forCount > 0)
                                                                        forStack.push("POP " + (string)(yyvsp[(3) - (5)].string));
                                                                else
                                                                        cout << "POP " << (yyvsp[(3) - (5)].string) << endl;
                                                        }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { symTable->setValue((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].val));
                                                          if(forCount > 0){
                                                                forStack.push("POP " + (string)(yyvsp[(1) - (3)].string));
                                                          }
                                                          else
                                                              cout << "POP " << (yyvsp[(1) - (3)].string) << endl;
                                                        }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {cout << "CALL " << (yyvsp[(1) - (4)].string) << endl;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { 
                                                                                cout << "JMP Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    { 
                                                                                cout << "JZ Label" << labelsStack.top() << endl << "OutLabel" << labelsStack.top() << ": " << endl << endl;
                                                                                labelsStack.pop();
                                                                                }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
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
#line 124 "parser.y"
    { cout << "OutLabel" << switchStack.top() << ":" << endl;                                                                       switchStack.pop(); labelsStack.pop(); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { cout << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { cout << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {
                                    if(!funcStack.top().first) { throwError("function declaration without return\n"); }
                                    funcStack.pop();

                                 }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { cout << "CALL " << (yyvsp[(1) - (4)].string) << endl; }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {
                                    if(funcStack.empty()) { throwError("return statement outside function\n"); }
                                    else if(funcStack.top().second != (yyvsp[(2) - (2)].val)->type) {throwError("return type mismatch\n");}
                                    funcStack.pop();
                                    funcStack.push(std::make_pair(true, (yyvsp[(2) - (2)].val)->type));
                                 }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {
                                    if(funcStack.empty()) { throwError("return statement outside function\n"); }
                                    else if(funcStack.top().second != Type::TYPE_VOID) { throwError("return type mismatch\n");}
                                 }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { 
                                        cout << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { 
                                        cout << endl << "Label" << labels << ": " << endl;
                                        labelsStack.push(labels++);
                                }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { 
                                                cout << endl << "Label" << labels << ": " << endl;
                                                labelsStack.push(labels++);
                                        }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { 
                                                labelsStack.push(labels++); 
                                        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    { cout << "JZ OutLabel" << labelsStack.top() << endl; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { cout << "POP $t" << labels << endl; labelsStack.push(labels++); switchStack.push(labels++);
                cout << "Stack top in endCaseExpression: " << labelsStack.top() << endl; }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { cout << "JZ OutLabel" << labelsStack.top() << endl; forCount++; forStack.push("@"); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    { forCount--; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    { cout << "JMP OutLabel" << labels << '\n' << "OutLabel" << labelsStack.top() << ":" << endl; labelsStack.pop(); labelsStack.push(labels++); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { funcStack.push(std::make_pair(false, (yyvsp[(2) - (6)].type))); printf("function declaration\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    { funcStack.push(std::make_pair(true, Type::TYPE_VOID)); printf("function declaration\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { 
                                                                        // cout << "JMP OutLabel" << switchStack.top() << endl << "label" << labelsStack.top() << ":" << endl;
                                                                        // labelsStack.pop();
                                                                        cout << "Stack top in case: " << labelsStack.top() << endl;
                                                                }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { 
                                                                        // cout << "JMP OutLabel" << switchStack.top() << endl << "label" << labelsStack.top() << ":" << endl;
                                                                        // labelsStack.pop();
                                                                        cout << "Stack top in case case: " << labelsStack.top() << endl;
                                                                }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {  
                                                (yyval.val) = (yyvsp[(1) - (1)].val);
                                                cout << "PUSH " << *(int*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { 
                                                (yyval.val) = (yyvsp[(1) - (1)].val);
                                                cout << "PUSH " << *(bool*)(yyvsp[(1) - (1)].val)->value << endl ;
                                        }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    { 
                                                (yyval.val) = (yyvsp[(1) - (1)].val);
                                                cout << "PUSH " << *(char*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    { 
                                                Type t = symTable->getType((yyvsp[(1) - (1)].string));
                                                if(t == Type::TYPE_INT || t == Type::TYPE_BOOL || t == Type::TYPE_CHAR)
                                                    (yyval.val) = new Value{symTable->getValue((yyvsp[(1) - (1)].string)), symTable->getType((yyvsp[(1) - (1)].string))};
                                                else
                                                        throwError("invalid case expression\n");
                                                cout << "PUSH " << (yyvsp[(1) - (1)].string) << endl;
                                        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    { implementOperation(OP::LeT, forCount,&forStack);  (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    { implementOperation(OP::GrT, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    { implementOperation(OP::LeE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    { implementOperation(OP::GrE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    { implementOperation(OP::EQQ, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { implementOperation(OP::NoE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    { implementOperation(OP::OR, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    { implementOperation(OP::AND, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    { implementOperation(OP::PLUS, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    { implementOperation(OP::MINUS, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { implementOperation(OP::MULTIPLY, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    { implementOperation(OP::DIVIDE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    { implementOperation(OP::NOT, forCount,&forStack); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    { implementOperation(OP::NEG, forCount,&forStack); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val);}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {   
                                        cout << "PUSH $t" << labelsStack.top() << endl << "EQ" << endl << "JZ label" << labels << endl; 
                                        labelsStack.push(labels++); 
                                        cout << "Stack top in caseColon: " << labelsStack.top() << endl;
                                }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { 
                                        cout << "JMP OutLabel" << switchStack.top() << endl << "label " << labelsStack.top() << ":" << endl;
                                        labelsStack.pop();
                                        cout << "Stack top in caseScope: " << labelsStack.top() << endl;
                                }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(int*)(yyvsp[(1) - (1)].val)->value));
                                            else
                                                cout << "PUSH " << *(int*)(yyvsp[(1) - (1)].val)->value << endl;
                                        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val);
                                            if(forCount > 0)
                                                forStack.push("PUSH " + std::to_string(*(bool*)(yyvsp[(1) - (1)].val)->value));
                                            else
                                                cout << "PUSH " << *(int*)(yyvsp[(1) - (1)].val)->value << endl ;
                                        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    { (yyval.val) = new Value{symTable->getValue((yyvsp[(1) - (1)].string)), symTable->getType((yyvsp[(1) - (1)].string))};
                                            if(forCount > 0)
                                                forStack.push("PUSH " + (string)(yyvsp[(1) - (1)].string));
                                            else
                                                cout << "PUSH " << (yyvsp[(1) - (1)].string) << endl;
                                        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    { implementOperation(OP::LeT, forCount,&forStack);  (yyval.val) = (yyvsp[(1) - (3)].val); /* TODO: check on type and propagate*/}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    { implementOperation(OP::GrT, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    { implementOperation(OP::LeE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    { implementOperation(OP::GrE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    { implementOperation(OP::EQQ, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    { implementOperation(OP::NoE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    { implementOperation(OP::OR, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    { implementOperation(OP::AND, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    { implementOperation(OP::PLUS, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { implementOperation(OP::MINUS, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { implementOperation(OP::MULTIPLY, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    { implementOperation(OP::DIVIDE, forCount,&forStack); (yyval.val) = (yyvsp[(1) - (3)].val);}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { implementOperation(OP::NOT, forCount,&forStack); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { implementOperation(OP::NEG, forCount,&forStack); (yyval.val) = (yyvsp[(2) - (2)].val);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val);}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    { (yyval.type) = Type::TYPE_INT; }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { (yyval.type) = Type::TYPE_FLOAT; }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    { (yyval.type) = Type::TYPE_BOOL; }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    { (yyval.type) = Type::TYPE_CHAR; }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 332 "parser.y"
    { (yyval.type) = Type::TYPE_CHAR_ARRAY; }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 336 "parser.y"
    {symTable = symTable->getParentTable();}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    {symTable = new SymbolTable(symTable);}
    break;



/* Line 1455 of yacc.c  */
#line 2237 "y.tab.c"
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
#line 360 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

void throwError(string s) {
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

