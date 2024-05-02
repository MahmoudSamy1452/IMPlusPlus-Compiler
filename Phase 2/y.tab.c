
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
#line 6 "parser.y"

    #include <stdio.h>
    void yyerror(char *);
    int yylex(void);
    extern FILE *yyin;
    
    SymbolTable* symTable = new SymbolTable();


/* Line 189 of yacc.c  */
#line 83 "y.tab.c"

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



/* Line 209 of yacc.c  */
#line 114 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 15 "parser.y"

    float value;                /* float value */
    char* string;               /* string value */
    Type type;                  /* data type */
    Value* val;                 /* value */



/* Line 214 of yacc.c  */
#line 200 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 212 "y.tab.c"

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  177

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
      31,    33,    35,    40,    42,    44,    46,    52,    59,    69,
      77,    79,    86,    95,   103,   111,   116,   119,   121,   124,
     129,   131,   132,   136,   138,   140,   141,   146,   152,   153,
     155,   157,   159,   161,   165,   169,   173,   177,   181,   185,
     189,   193,   197,   201,   205,   209,   212,   215,   219,   221,
     223,   225,   227,   231,   235,   239,   243,   247,   251,   255,
     259,   263,   267,   271,   275,   278,   281,   285,   287,   289,
     291,   293,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    54,    41,    49,    -1,    -1,    41,    49,
      -1,    63,     6,    -1,    63,     6,    31,    52,    -1,    19,
      63,     6,    31,    52,    -1,     6,    31,    52,    -1,    62,
      -1,     7,    -1,     8,    -1,     6,    42,    58,    43,    -1,
      50,    -1,    51,    -1,    53,    -1,     9,    42,    62,    43,
      64,    -1,    10,    64,    11,    42,    62,    43,    -1,    12,
      42,    53,    41,    62,    41,    51,    43,    64,    -1,    13,
      42,    62,    43,    44,    59,    45,    -1,    64,    -1,    15,
      42,    62,    43,    16,    64,    -1,    15,    42,    62,    43,
      16,    64,    17,    64,    -1,    25,    63,     6,    42,    56,
      43,    64,    -1,    25,    24,     6,    42,    56,    43,    64,
      -1,     6,    42,    58,    43,    -1,    18,    52,    -1,    18,
      -1,    63,     6,    -1,    63,     6,    46,    55,    -1,    55,
      -1,    -1,    52,    46,    57,    -1,    52,    -1,    57,    -1,
      -1,    14,    60,    47,    64,    -1,    14,    60,    47,    64,
      59,    -1,    -1,     7,    -1,    61,    -1,     3,    -1,     5,
      -1,    61,    34,    61,    -1,    61,    35,    61,    -1,    61,
      21,    61,    -1,    61,    20,    61,    -1,    61,    22,    61,
      -1,    61,    23,    61,    -1,    61,    32,    61,    -1,    61,
      33,    61,    -1,    61,    36,    61,    -1,    61,    37,    61,
      -1,    61,    38,    61,    -1,    61,    39,    61,    -1,    40,
      61,    -1,    37,    61,    -1,    42,    61,    43,    -1,     4,
      -1,     3,    -1,     5,    -1,     6,    -1,    62,    34,    62,
      -1,    62,    35,    62,    -1,    62,    21,    62,    -1,    62,
      20,    62,    -1,    62,    22,    62,    -1,    62,    23,    62,
      -1,    62,    32,    62,    -1,    62,    33,    62,    -1,    62,
      36,    62,    -1,    62,    37,    62,    -1,    62,    38,    62,
      -1,    62,    39,    62,    -1,    40,    62,    -1,    37,    62,
      -1,    42,    62,    43,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    44,    49,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    42,    43,    47,    48,    49,    53,    57,
      58,    59,    60,    64,    65,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    85,    86,
      90,    91,    95,    96,   100,   101,   105,   106,   109,   110,
     111,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   157,   158,   159,
     160,   161,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOATING", "BOOLEAN",
  "VARIABLE", "CHAR", "CHARARRAY", "WHILE", "REPEAT", "UNTIL", "FOR",
  "SWITCH", "CASE", "IF", "THEN", "ELSE", "RETURN", "CONST", "GE", "LE",
  "EQ", "NE", "VOID", "FUNCTION", "INT", "FLOAT", "BOOL", "CHARACTER",
  "STRING", "'='", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'~'", "';'", "'('", "')'", "'{'", "'}'", "','", "':'", "$accept",
  "program", "declaration", "assignment", "assignmentValue",
  "initialization", "statement", "argumentsList", "arguments",
  "parametersList", "parameters", "case", "caseCondition",
  "caseExpression", "expression", "datatype", "scope", 0
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
      54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     2,     4,     5,     3,     1,
       1,     1,     4,     1,     1,     1,     5,     6,     9,     7,
       1,     6,     8,     7,     7,     4,     2,     1,     2,     4,
       1,     0,     3,     1,     1,     0,     4,     5,     0,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     1,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      77,    78,    79,    80,    81,     3,     3,     0,    13,    14,
      15,     0,     0,    20,     0,    35,     0,     0,     0,     0,
       0,    59,    58,    60,    61,    10,    11,     0,     0,     0,
      26,     9,     0,     0,     0,     4,     0,     1,     3,     5,
       8,    33,    34,     0,    61,     0,     0,     0,     0,     0,
       0,    35,    75,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     2,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    76,    65,    64,    66,    67,    68,    69,    62,    63,
      70,    71,    72,    73,     0,    31,    31,     6,    32,    16,
       0,     0,     0,     0,    12,     7,    30,     0,     0,     0,
      17,     0,    38,     0,    21,     0,    28,     0,     0,    41,
      42,    39,     0,     0,     0,     0,    40,    19,     0,    24,
       0,    23,     0,    56,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      29,    18,    57,    36,    46,    45,    47,    48,    49,    50,
      43,    44,    51,    52,    53,    54,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    51,    20,    21,   116,   117,    52,
      53,   123,   135,   136,    41,    22,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int16 yypact[] =
{
      77,    31,   -28,    -8,    -1,    14,    15,    18,   -17,    85,
     -29,   -29,   -29,   -29,   -29,    77,    77,    34,   -29,   -29,
     -29,    20,    33,   -29,    18,    18,    26,    48,   138,    26,
      26,   -29,   -29,   -29,    27,   -29,   -29,    26,    26,    26,
     -29,   305,    65,    69,    70,   -29,    35,   -29,    77,    50,
     -29,    38,   -29,    42,   -29,   139,    46,    60,    52,   163,
     187,    18,   -20,   -29,   211,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    63,    55,    59,
     -29,   -29,    18,    18,   -29,    -8,    26,    26,    64,   100,
      74,   -29,    89,    89,    89,    89,   333,   360,    89,    89,
     -20,   -20,   -29,   -29,    18,   -17,   -17,   -29,   -29,   -29,
     235,   283,   105,    -8,   -29,   -29,   -29,    80,   114,    86,
     -29,   128,    30,    91,   120,    -8,    92,    -8,    97,   -29,
     -29,   -29,    37,    37,    37,    94,   313,   -29,    -8,   -29,
     -17,   -29,    -8,   -11,   -29,   259,    -8,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,   -29,
     -29,   -29,   -29,   105,   151,   151,   151,   151,   340,   366,
     151,   151,   -11,   -11,   -29,   -29,   -29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -29,   -10,   -29,    21,    -4,   130,   -29,    23,    73,    87,
     108,    17,   -29,    -2,   -22,    -7,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    42,    44,    40,    55,    45,    46,    59,    60,    10,
      11,    12,    13,    14,    26,    62,    63,    64,    75,    76,
      50,    31,    32,    33,    34,    35,    36,   157,   158,    31,
      32,    33,    54,   129,    47,   130,    16,   131,    81,    49,
     129,    28,   130,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    37,    29,    30,    38,    56,
      39,    48,    24,    37,   110,   111,    38,   132,    39,    61,
     133,    77,   134,    25,   132,    78,    79,   133,   107,   134,
      80,    82,   109,     1,    83,    84,     2,     3,    86,     4,
       5,    24,     6,    87,   104,     7,     8,   105,   118,   118,
     115,   106,     9,    10,    11,    12,    13,    14,   112,    43,
     124,    10,    11,    12,    13,    14,   113,   114,    15,   122,
     126,    16,   139,   125,   141,    73,    74,    75,    76,   127,
     143,   144,   145,   118,    57,   159,   137,   138,   140,   161,
     142,   146,   128,   163,    57,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     8,    58,    65,
      66,    67,    68,   160,    10,    11,    12,    13,    14,    90,
     108,    69,    70,    71,    72,    73,    74,    75,    76,   119,
     176,     0,    85,    65,    66,    67,    68,   155,   156,   157,
     158,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,     0,    88,    65,    66,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      89,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    91,    65,    66,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,   120,   147,
     148,   149,   150,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,     0,
       0,     0,   162,    65,    66,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,   121,    65,    66,    67,    68,     0,
       0,     0,     0,   147,   148,   149,   150,    69,    70,    71,
      72,    73,    74,    75,    76,   151,   152,   153,   154,   155,
     156,   157,   158,    65,    66,    67,    68,     0,     0,     0,
     147,   148,   149,   150,     0,     0,    70,    71,    72,    73,
      74,    75,    76,   152,   153,   154,   155,   156,   157,   158,
      65,    66,    67,    68,     0,     0,   147,   148,   149,   150,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
     153,   154,   155,   156,   157,   158
};

static const yytype_int16 yycheck[] =
{
       3,     8,     9,     7,    26,    15,    16,    29,    30,    26,
      27,    28,    29,    30,    42,    37,    38,    39,    38,    39,
      24,     3,     4,     5,     6,     7,     8,    38,    39,     3,
       4,     5,     6,     3,     0,     5,    44,     7,    48,     6,
       3,    42,     5,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    37,    42,    42,    40,    11,
      42,    41,    31,    37,    86,    87,    40,    37,    42,    42,
      40,     6,    42,    42,    37,     6,     6,    40,    82,    42,
      45,    31,    85,     6,    46,    43,     9,    10,    42,    12,
      13,    31,    15,    41,    31,    18,    19,    42,   105,   106,
     104,    42,    25,    26,    27,    28,    29,    30,    44,    24,
     113,    26,    27,    28,    29,    30,    16,    43,    41,    14,
       6,    44,   125,    43,   127,    36,    37,    38,    39,    43,
     132,   133,   134,   140,     6,   138,    45,    17,    46,   142,
      43,    47,   121,   146,     6,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    19,    28,    20,
      21,    22,    23,   140,    26,    27,    28,    29,    30,    61,
      83,    32,    33,    34,    35,    36,    37,    38,    39,   106,
     163,    -1,    43,    20,    21,    22,    23,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    43,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    32,    33,    34,
      35,    36,    37,    38,    39,    32,    33,    34,    35,    36,
      37,    38,    39,    20,    21,    22,    23,    -1,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    33,    34,    35,    36,    37,    38,    39,
      20,    21,    22,    23,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      34,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     9,    10,    12,    13,    15,    18,    19,    25,
      26,    27,    28,    29,    30,    41,    44,    49,    50,    51,
      53,    54,    63,    64,    31,    42,    42,    64,    42,    42,
      42,     3,     4,     5,     6,     7,     8,    37,    40,    42,
      52,    62,    63,    24,    63,    49,    49,     0,    41,     6,
      52,    52,    57,    58,     6,    62,    11,     6,    53,    62,
      62,    42,    62,    62,    62,    20,    21,    22,    23,    32,
      33,    34,    35,    36,    37,    38,    39,     6,     6,     6,
      45,    49,    31,    46,    43,    43,    42,    41,    43,    43,
      58,    43,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    31,    42,    42,    52,    57,    64,
      62,    62,    44,    16,    43,    52,    55,    56,    63,    56,
      43,    41,    14,    59,    64,    43,     6,    43,    51,     3,
       5,     7,    37,    40,    42,    60,    61,    45,    17,    64,
      46,    64,    43,    61,    61,    61,    47,    20,    21,    22,
      23,    32,    33,    34,    35,    36,    37,    38,    39,    64,
      55,    64,    43,    64,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    59
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
#line 47 "parser.y"
    { symTable->insert((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].type)); printf("declaration\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 48 "parser.y"
    { symTable->insert((yyvsp[(2) - (4)].string), (yyvsp[(1) - (4)].type), (yyvsp[(4) - (4)].val)); printf("declaration = value\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 49 "parser.y"
    { symTable->insert((yyvsp[(3) - (5)].string), (yyvsp[(2) - (5)].type), (yyvsp[(5) - (5)].val), true); printf("const declaration\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 53 "parser.y"
    { symTable->setValue((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].val)); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 60 "parser.y"
    { (yyval.val) = 0;printf("function call\n"); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    { printf("initialization\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    { printf("while\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { printf("repeat\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { printf("for\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    { printf("switch\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    { printf("if\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { printf("if else\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { printf("function\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { printf("function\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { printf("function call\n"); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    { printf("case\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    { printf("case case\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { printf("boolean\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { /*$$ = $1 < $3;*/ printf("less than\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    { /*$$ = $1 > $3;*/ }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    { /*$$ = $1 <= $3;*/ }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { /*$$ = $1 >= $3;*/}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { /*$$ = $1 == $3;*/ }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { /*$$ = $1 != $3;*/}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { /*$$ = $1 || $3;*/ }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    { /*$$ = $1 && $3;*/ }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { /*$$ = $1 + $3;*/ printf("add\n");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { /*$$ = $1 - $3; printf("sub\n");*/}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { /*$$ = $1 * $3; printf("mul\n");*/}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { /*$$ = $1 / $3; printf("div\n");*/}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { /*$$ = !$2; */}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { /*$$ = -$2; */}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { /*$$ = $2; */}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].value); printf("float\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].value); printf("integer\n");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { (yyval.val) = (yyvsp[(1) - (1)].value); printf("boolean\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval.val) = symTable->getValue((yyvsp[(1) - (1)].string)); printf("variable\n");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { /*$$ = $1 < $3;*/ printf("less than\n");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { /*$$ = $1 > $3;*/ }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { /*$$ = $1 <= $3;*/ }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { /*$$ = $1 >= $3;*/}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { /*$$ = $1 == $3;*/ }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { /*$$ = $1 != $3;*/}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { /*$$ = $1 || $3;*/ }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { /*$$ = $1 && $3;*/ }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { /*$$ = $1 + $3;*/ printf("add\n");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    { /*$$ = $1 - $3; printf("sub\n");*/}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { /*$$ = $1 * $3; printf("mul\n");*/}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { /*$$ = $1 / $3; printf("div\n");*/}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { /*$$ = !$2; */}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { /*$$ = -$2; */}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { /*$$ = $2; */}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { (yyval.type) = enum Type.INT; }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval.type) = enum Type.FLOAT; }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { (yyval.type) = enum Type.BOOL; }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { (yyval.type) = enum Type.CHAR; }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval.type) = enum Type.STRING; }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { printf("scope\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2004 "y.tab.c"
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
#line 185 "parser.y"


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
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

