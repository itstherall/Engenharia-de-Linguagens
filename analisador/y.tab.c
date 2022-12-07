/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER_LITERAL = 259,
     STRING_LITERAL = 260,
     WHILE = 261,
     BLOCK_ENDWHILE = 262,
     FOR = 263,
     BLOCK_ENDFOR = 264,
     DO = 265,
     BLOCK_ENDDO = 266,
     BLOCK_END = 267,
     IF = 268,
     BLOCK_ENDIF = 269,
     THEN = 270,
     ELSE = 271,
     FUNCTION = 272,
     PROCEDURE = 273,
     RETURN = 274,
     PRINT = 275,
     DIMENSION = 276,
     NUMBER = 277,
     STRING = 278,
     BOOL = 279,
     MAP = 280,
     TRUE = 281,
     FALSE = 282,
     AND = 283,
     OR = 284,
     NOT = 285,
     OP_GEQ = 286,
     OP_LEQ = 287,
     OP_EQ = 288,
     OP_NEQ = 289,
     OP_INCREMENT = 290,
     OP_DECREMENT = 291,
     SUM_ASSIGN = 292,
     DIFFERENCE_ASSIGN = 293,
     PRODUCT_ASSIGN = 294,
     QUOTIENT_ASSIGN = 295,
     REMAINDER_ASSIGN = 296
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER_LITERAL 259
#define STRING_LITERAL 260
#define WHILE 261
#define BLOCK_ENDWHILE 262
#define FOR 263
#define BLOCK_ENDFOR 264
#define DO 265
#define BLOCK_ENDDO 266
#define BLOCK_END 267
#define IF 268
#define BLOCK_ENDIF 269
#define THEN 270
#define ELSE 271
#define FUNCTION 272
#define PROCEDURE 273
#define RETURN 274
#define PRINT 275
#define DIMENSION 276
#define NUMBER 277
#define STRING 278
#define BOOL 279
#define MAP 280
#define TRUE 281
#define FALSE 282
#define AND 283
#define OR 284
#define NOT 285
#define OP_GEQ 286
#define OP_LEQ 287
#define OP_EQ 288
#define OP_NEQ 289
#define OP_INCREMENT 290
#define OP_DECREMENT 291
#define SUM_ASSIGN 292
#define DIFFERENCE_ASSIGN 293
#define PRODUCT_ASSIGN 294
#define QUOTIENT_ASSIGN 295
#define REMAINDER_ASSIGN 296




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include "lib/potrex.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;





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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	struct node * nodeValue;  /* ??? */
	}
/* Line 193 of yacc.c.  */
#line 199 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    60,     2,     2,    58,     2,     2,
      42,    43,    56,    54,    47,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    48,
      52,    51,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    23,    33,    35,    37,
      39,    41,    42,    44,    46,    50,    53,    55,    59,    61,
      64,    66,    69,    72,    76,    78,    80,    82,    84,    86,
      88,    90,    92,    94,    97,   101,   106,   110,   111,   114,
     116,   120,   123,   124,   127,   129,   131,   133,   135,   137,
     139,   144,   149,   154,   160,   167,   171,   175,   179,   183,
     185,   189,   191,   195,   199,   201,   205,   209,   213,   217,
     219,   223,   227,   229,   233,   237,   241,   243,   246,   250,
     252,   256,   260,   265,   268,   271,   273,   275,   277,   279,
     281,   288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    77,    63,    -1,    64,    -1,    64,    63,
      -1,    17,     3,    42,    66,    43,    44,    65,    45,    72,
      46,    12,    -1,    18,     3,    42,    66,    43,    45,    72,
      46,    12,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    -1,    67,    -1,    68,    -1,    68,    47,    67,    -1,
      70,     3,    -1,    88,    -1,    69,    47,    88,    -1,    65,
      -1,    65,    71,    -1,    21,    -1,    21,    71,    -1,    73,
      48,    -1,    73,    48,    72,    -1,    77,    -1,    76,    -1,
      82,    -1,    83,    -1,    84,    -1,    86,    -1,    96,    -1,
      98,    -1,     3,    -1,     3,    75,    -1,    49,    88,    50,
      -1,    49,    88,    50,    75,    -1,    74,    81,    88,    -1,
      -1,    70,    78,    -1,    79,    -1,    79,    47,    78,    -1,
       3,    80,    -1,    -1,    81,    88,    -1,    51,    -1,    37,
      -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,     6,
      87,    86,     7,    -1,     8,    87,    86,     9,    -1,    13,
      87,    86,    14,    -1,    13,    87,    86,    14,    85,    -1,
      16,    13,    87,    86,    14,    85,    -1,    16,    86,    14,
      -1,    45,    72,    46,    -1,    42,    88,    43,    -1,    89,
      29,    88,    -1,    89,    -1,    90,    28,    89,    -1,    90,
      -1,    91,    33,    90,    -1,    91,    34,    90,    -1,    91,
      -1,    92,    52,    91,    -1,    92,    32,    91,    -1,    92,
      53,    91,    -1,    92,    31,    91,    -1,    92,    -1,    93,
      54,    92,    -1,    93,    55,    92,    -1,    93,    -1,    94,
      56,    93,    -1,    94,    57,    93,    -1,    94,    58,    93,
      -1,    94,    -1,    30,    94,    -1,    95,    59,    95,    -1,
      95,    -1,    42,    88,    43,    -1,     3,    42,    43,    -1,
       3,    42,    69,    43,    -1,    74,    35,    -1,    74,    36,
      -1,     4,    -1,    26,    -1,    27,    -1,    74,    -1,    97,
      -1,    20,    42,    60,     5,    60,    43,    -1,    19,    73,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    51,    52,    64,    74,    85,    87,    89,
      91,    95,    96,    99,   100,   108,   116,   117,   120,   122,
     135,   136,   139,   144,   152,   153,   154,   155,   156,   157,
     158,   159,   162,   163,   166,   167,   170,   176,   177,   189,
     190,   193,   196,   197,   200,   201,   202,   203,   204,   205,
     208,   211,   214,   215,   218,   219,   222,   225,   228,   229,
     232,   233,   236,   237,   238,   241,   242,   243,   244,   245,
     248,   249,   250,   253,   254,   255,   256,   259,   260,   261,
     264,   265,   266,   267,   268,   269,   273,   274,   275,   278,
     281,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER_LITERAL", "STRING_LITERAL",
  "WHILE", "BLOCK_ENDWHILE", "FOR", "BLOCK_ENDFOR", "DO", "BLOCK_ENDDO",
  "BLOCK_END", "IF", "BLOCK_ENDIF", "THEN", "ELSE", "FUNCTION",
  "PROCEDURE", "RETURN", "PRINT", "DIMENSION", "NUMBER", "STRING", "BOOL",
  "MAP", "TRUE", "FALSE", "AND", "OR", "NOT", "OP_GEQ", "OP_LEQ", "OP_EQ",
  "OP_NEQ", "OP_INCREMENT", "OP_DECREMENT", "SUM_ASSIGN",
  "DIFFERENCE_ASSIGN", "PRODUCT_ASSIGN", "QUOTIENT_ASSIGN",
  "REMAINDER_ASSIGN", "'('", "')'", "':'", "'{'", "'}'", "','", "';'",
  "'['", "']'", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "'\"'", "$accept", "program", "subprograms", "subprogram", "tipo",
  "argumentos", "args", "argumento", "parameters", "tipo_inicial",
  "dimensions", "stmlist", "stm", "atom", "ops_access", "assignment",
  "declaration", "ids", "id", "init_opt", "assign", "while", "for", "if",
  "elseif", "block", "condition", "exp", "exp_lv8", "exp_lv7", "exp_lv6",
  "exp_lv5", "exp_lv4", "exp_lv3", "exp_lv2", "io", "print", "return", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    40,    41,    58,   123,   125,    44,    59,    91,
      93,    61,    60,    62,    43,    45,    42,    47,    37,    94,
      34
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    83,    84,    84,    85,    85,    86,    87,    88,    88,
      89,    89,    90,    90,    90,    91,    91,    91,    91,    91,
      92,    92,    92,    93,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      97,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,    11,     9,     1,     1,     1,
       1,     0,     1,     1,     3,     2,     1,     3,     1,     2,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     0,     2,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     6,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     3,     1,
       3,     3,     4,     2,     2,     1,     1,     1,     1,     1,
       6,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      37,     7,     8,     9,    10,     0,    18,     0,     0,     1,
      20,    19,    42,    38,    39,     0,     0,     2,     3,    21,
      45,    46,    47,    48,    49,    44,    41,     0,     0,     0,
       0,     4,    32,    85,    86,    87,     0,     0,    88,    43,
      59,    61,    64,    69,    72,    76,    79,    40,    11,    11,
       0,     0,    33,    77,     0,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,    81,     0,    16,     0,
      80,    58,    60,    62,    63,    68,    66,    65,    67,    70,
      71,    73,    74,    75,    78,     0,     0,    15,     0,    82,
       0,    34,     0,    14,    37,    17,    35,     0,    32,     0,
       0,     0,    37,     0,    37,     0,     0,     0,    25,    24,
      26,    27,    28,    29,    30,    89,    31,    37,     0,     0,
       0,     0,    91,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,    56,     6,    23,    36,     0,    57,
      50,    51,    52,     0,     5,     0,    53,     0,     0,     0,
      90,     0,    55,     0,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    17,    18,     6,    71,    72,    73,    77,     7,
      11,   115,   116,    38,    52,   118,   119,    13,    14,    26,
      27,   120,   121,   122,   156,   123,   129,    39,    40,    41,
      42,    43,    44,    45,    46,   124,   125,   126
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
      65,  -108,  -108,  -108,  -108,    11,    -4,    25,    17,  -108,
      -4,  -108,    64,  -108,   -15,    51,    68,  -108,    17,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     3,    25,     6,
      31,  -108,   -33,  -108,  -108,  -108,     3,     3,    62,  -108,
      30,    58,    46,    43,    63,    26,    55,  -108,    65,    65,
      34,     3,  -108,  -108,    49,  -108,  -108,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      39,    67,  -108,    69,   120,    81,  -108,   -24,  -108,    75,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,    82,    65,  -108,    83,  -108,
       3,    78,    65,  -108,    33,  -108,  -108,    84,    78,    88,
      88,    88,    33,    89,    33,    86,    85,    64,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,    33,     3,    90,
      90,    90,  -108,    74,    91,   124,     2,     3,    92,    96,
     133,   132,   128,   138,  -108,  -108,  -108,  -108,   134,  -108,
    -108,  -108,   129,    87,  -108,    -1,  -108,   101,    88,   135,
    -108,    90,  -108,   136,   129,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   130,  -108,    50,   102,    57,  -108,  -108,   -47,
     144,   -96,    47,   -42,    54,  -108,   156,   137,  -108,  -108,
      40,  -108,  -108,  -108,    -6,   -62,  -107,   -37,   103,    60,
      45,    56,    44,   126,    93,  -108,  -108,  -108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      54,    74,    74,   130,   131,   108,    32,    33,   109,    50,
     110,     9,   158,    78,    79,   111,    51,    10,   134,    99,
      81,   112,   113,   100,     1,     2,     3,     4,    12,    34,
      35,   138,    28,    36,    15,    16,   108,    32,    33,   109,
     146,   110,    32,    33,   114,    37,   111,   114,    48,    74,
     -37,   161,   112,   113,    29,     1,     2,     3,     4,    57,
      34,    35,   117,   105,    36,    34,    35,   140,   141,   142,
     117,    30,   117,    49,    61,    62,    37,    76,   114,    59,
      60,    37,    67,    68,    69,   117,    58,     1,     2,     3,
       4,   139,    80,   159,   117,    63,    64,    55,    56,   163,
     147,    20,    21,    22,    23,    24,    85,    86,    87,    88,
      95,    91,    92,    93,    70,    25,    96,    65,    66,    83,
      84,    89,    90,    97,    98,   101,   102,    51,   104,   127,
     128,   133,   135,   136,   143,   114,   145,   144,   148,   149,
     150,   151,   152,   153,   160,   155,   154,   157,    31,   162,
     164,    75,   107,   103,    19,   106,     8,   137,   165,   132,
       0,    82,    53,    94,     0,    47
};

static const yytype_int16 yycheck[] =
{
      37,    48,    49,   110,   111,     3,     3,     4,     6,    42,
       8,     0,    13,    50,    51,    13,    49,    21,   114,    43,
      57,    19,    20,    47,    22,    23,    24,    25,     3,    26,
      27,   127,    47,    30,    17,    18,     3,     3,     4,     6,
     136,     8,     3,     4,    45,    42,    13,    45,    42,    96,
      48,   158,    19,    20,     3,    22,    23,    24,    25,    29,
      26,    27,   104,   100,    30,    26,    27,   129,   130,   131,
     112,     3,   114,    42,    31,    32,    42,    43,    45,    33,
      34,    42,    56,    57,    58,   127,    28,    22,    23,    24,
      25,   128,    43,   155,   136,    52,    53,    35,    36,   161,
     137,    37,    38,    39,    40,    41,    61,    62,    63,    64,
      43,    67,    68,    69,    59,    51,    47,    54,    55,    59,
      60,    65,    66,     3,    43,    50,    44,    49,    45,    45,
      42,    42,    46,    48,    60,    45,    12,    46,    46,    43,
       7,     9,    14,     5,    43,    16,    12,    60,    18,    14,
      14,    49,   102,    96,    10,   101,     0,   117,   164,   112,
      -1,    58,    36,    70,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    24,    25,    62,    65,    70,    77,     0,
      21,    71,     3,    78,    79,    17,    18,    63,    64,    71,
      37,    38,    39,    40,    41,    51,    80,    81,    47,     3,
       3,    63,     3,     4,    26,    27,    30,    42,    74,    88,
      89,    90,    91,    92,    93,    94,    95,    78,    42,    42,
      42,    49,    75,    94,    88,    35,    36,    29,    28,    33,
      34,    31,    32,    52,    53,    54,    55,    56,    57,    58,
      59,    66,    67,    68,    70,    66,    43,    69,    88,    88,
      43,    88,    89,    90,    90,    91,    91,    91,    91,    92,
      92,    93,    93,    93,    95,    43,    47,     3,    43,    43,
      47,    50,    44,    67,    45,    88,    75,    65,     3,     6,
       8,    13,    19,    20,    45,    72,    73,    74,    76,    77,
      82,    83,    84,    86,    96,    97,    98,    45,    42,    87,
      87,    87,    73,    42,    72,    46,    48,    81,    72,    88,
      86,    86,    86,    60,    46,    12,    72,    88,    46,    43,
       7,     9,    14,     5,    12,    16,    85,    60,    13,    86,
      43,    87,    14,    86,    14,    85
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 45 "parser.y"
    {fprintf(yyout, "%s\n%s", (yyvsp[(1) - (2)].nodeValue)->target_code, (yyvsp[(2) - (2)].nodeValue)->target_code);
								   freeNode((yyvsp[(1) - (2)].nodeValue));
                      			   freeNode((yyvsp[(2) - (2)].nodeValue));
								   }
    break;

  case 3:
#line 51 "parser.y"
    {(yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue);}
    break;

  case 4:
#line 52 "parser.y"
    {char *s = concat(3, (yyvsp[(1) - (2)].nodeValue)->target_code, "\n", (yyvsp[(2) - (2)].nodeValue)->target_code);
                             		   freeNode((yyvsp[(1) - (2)].nodeValue));
                             		   freeNode((yyvsp[(2) - (2)].nodeValue));
                             		   (yyval.nodeValue) = createNode(s);
                             		   free(s);
									  }
    break;

  case 5:
#line 65 "parser.y"
    {
					char *s1 = concat(9, (yyvsp[(7) - (11)].sValue), " ", (yyvsp[(2) - (11)].sValue), " (", (yyvsp[(4) - (11)].nodeValue)->target_code, ") ", "{\n", (yyvsp[(9) - (11)].nodeValue)->target_code, "}\n");
					free((yyvsp[(7) - (11)].sValue));
					free((yyvsp[(2) - (11)].sValue));
					freeNode((yyvsp[(4) - (11)].nodeValue));
					freeNode((yyvsp[(9) - (11)].nodeValue));
					(yyval.nodeValue) = createNode(s1);
					free(s1);
				}
    break;

  case 6:
#line 75 "parser.y"
    {
					char *s1 = concat(8, "void ", (yyvsp[(2) - (9)].sValue), " (", (yyvsp[(4) - (9)].nodeValue)->target_code, ") ", "{\n", (yyvsp[(7) - (9)].nodeValue)->target_code, "}\n");
					free((yyvsp[(2) - (9)].sValue));
					freeNode((yyvsp[(4) - (9)].nodeValue));
					freeNode((yyvsp[(7) - (9)].nodeValue));
					(yyval.nodeValue) = createNode(s1);
					free(s1);
				}
    break;

  case 7:
#line 85 "parser.y"
    { (yyval.sValue) = (yyvsp[(1) - (1)].sValue);
				  free((yyvsp[(1) - (1)].sValue));}
    break;

  case 8:
#line 87 "parser.y"
    { (yyval.sValue) = (yyvsp[(1) - (1)].sValue);
				  free((yyvsp[(1) - (1)].sValue));}
    break;

  case 9:
#line 89 "parser.y"
    { (yyval.sValue) = (yyvsp[(1) - (1)].sValue);
				  free((yyvsp[(1) - (1)].sValue));}
    break;

  case 10:
#line 91 "parser.y"
    {(yyval.sValue) = (yyvsp[(1) - (1)].sValue);
				  free((yyvsp[(1) - (1)].sValue));}
    break;

  case 11:
#line 95 "parser.y"
    {(yyval.nodeValue) = createNode("");}
    break;

  case 12:
#line 96 "parser.y"
    {(yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue);}
    break;

  case 13:
#line 99 "parser.y"
    {(yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue);}
    break;

  case 14:
#line 100 "parser.y"
    {char* s = concat(3, (yyvsp[(1) - (3)].nodeValue)->target_code, ", ", (yyvsp[(3) - (3)].nodeValue)->target_code);
	 								 freeNode((yyvsp[(1) - (3)].nodeValue));
									 freeNode((yyvsp[(3) - (3)].nodeValue));
									 (yyval.nodeValue) = createNode(s);
									 free(s);
									}
    break;

  case 15:
#line 108 "parser.y"
    {char* s = concat(3, (yyvsp[(1) - (2)].nodeValue)->target_code, " ", (yyvsp[(2) - (2)].sValue));
									 freeNode((yyvsp[(1) - (2)].nodeValue));
									 free((yyvsp[(2) - (2)].sValue));
									 (yyval.nodeValue) = createNode(s);
									 free(s);
									}
    break;

  case 16:
#line 116 "parser.y"
    {}
    break;

  case 17:
#line 117 "parser.y"
    {}
    break;

  case 18:
#line 120 "parser.y"
    {(yyval.nodeValue) = createNode((yyvsp[(1) - (1)].sValue));
									 free((yyvsp[(1) - (1)].sValue));}
    break;

  case 19:
#line 122 "parser.y"
    {}
    break;

  case 20:
#line 135 "parser.y"
    {}
    break;

  case 21:
#line 136 "parser.y"
    {}
    break;

  case 22:
#line 139 "parser.y"
    {char* s = concat(2, (yyvsp[(1) - (2)].nodeValue)->target_code, ";\n");
							freeNode((yyvsp[(1) - (2)].nodeValue));
							(yyval.nodeValue) = createNode(s);
							free(s);
							}
    break;

  case 23:
#line 144 "parser.y"
    {char* s = concat(3, (yyvsp[(1) - (3)].nodeValue)->target_code, ";\n", (yyvsp[(3) - (3)].nodeValue)->target_code);
	 					 	 freeNode((yyvsp[(1) - (3)].nodeValue));
							 freeNode((yyvsp[(3) - (3)].nodeValue));
							 (yyval.nodeValue) = createNode(s);
							 free(s);
							}
    break;

  case 24:
#line 152 "parser.y"
    {}
    break;

  case 25:
#line 153 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 26:
#line 154 "parser.y"
    {}
    break;

  case 27:
#line 155 "parser.y"
    {}
    break;

  case 28:
#line 156 "parser.y"
    {}
    break;

  case 29:
#line 157 "parser.y"
    {}
    break;

  case 30:
#line 158 "parser.y"
    {}
    break;

  case 31:
#line 159 "parser.y"
    {}
    break;

  case 32:
#line 162 "parser.y"
    { (yyval.nodeValue) = createNode((yyvsp[(1) - (1)].sValue)); }
    break;

  case 33:
#line 163 "parser.y"
    {}
    break;

  case 34:
#line 166 "parser.y"
    {}
    break;

  case 35:
#line 167 "parser.y"
    {}
    break;

  case 36:
#line 170 "parser.y"
    {char* s = concat(3, (yyvsp[(1) - (3)].nodeValue)->target_code, (yyvsp[(2) - (3)].sValue), (yyvsp[(3) - (3)].nodeValue)->target_code);
	 								 freeNode((yyvsp[(1) - (3)].nodeValue));
									 freeNode((yyvsp[(3) - (3)].nodeValue));
									 (yyval.nodeValue) = createNode(s);
									 free(s);}
    break;

  case 37:
#line 176 "parser.y"
    {(yyval.nodeValue) = createNode("");}
    break;

  case 38:
#line 177 "parser.y"
    {printf("tipo ids\n");}
    break;

  case 39:
#line 189 "parser.y"
    {printf("id;\n");}
    break;

  case 40:
#line 190 "parser.y"
    {printf("id, \n");}
    break;

  case 41:
#line 193 "parser.y"
    {printf("id init_op\n");}
    break;

  case 43:
#line 197 "parser.y"
    {printf(" = exp\n");}
    break;

  case 44:
#line 200 "parser.y"
    { (yyval.sValue) = &yytext[0]; }
    break;

  case 50:
#line 208 "parser.y"
    {}
    break;

  case 51:
#line 211 "parser.y"
    {}
    break;

  case 52:
#line 214 "parser.y"
    {}
    break;

  case 53:
#line 215 "parser.y"
    {}
    break;

  case 54:
#line 218 "parser.y"
    {}
    break;

  case 55:
#line 219 "parser.y"
    {}
    break;

  case 56:
#line 222 "parser.y"
    {}
    break;

  case 57:
#line 225 "parser.y"
    {}
    break;

  case 58:
#line 228 "parser.y"
    {}
    break;

  case 59:
#line 229 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 60:
#line 232 "parser.y"
    {}
    break;

  case 61:
#line 233 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 62:
#line 236 "parser.y"
    {}
    break;

  case 63:
#line 237 "parser.y"
    {}
    break;

  case 64:
#line 238 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 65:
#line 241 "parser.y"
    {}
    break;

  case 66:
#line 242 "parser.y"
    {}
    break;

  case 67:
#line 243 "parser.y"
    {}
    break;

  case 68:
#line 244 "parser.y"
    {}
    break;

  case 69:
#line 245 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 70:
#line 248 "parser.y"
    {}
    break;

  case 71:
#line 249 "parser.y"
    {}
    break;

  case 72:
#line 250 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 73:
#line 253 "parser.y"
    {}
    break;

  case 74:
#line 254 "parser.y"
    {}
    break;

  case 75:
#line 255 "parser.y"
    {}
    break;

  case 76:
#line 256 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue);}
    break;

  case 77:
#line 259 "parser.y"
    {}
    break;

  case 78:
#line 260 "parser.y"
    {}
    break;

  case 79:
#line 261 "parser.y"
    { (yyval.nodeValue) = (yyvsp[(1) - (1)].nodeValue); }
    break;

  case 80:
#line 264 "parser.y"
    {}
    break;

  case 81:
#line 265 "parser.y"
    {}
    break;

  case 82:
#line 266 "parser.y"
    {}
    break;

  case 83:
#line 267 "parser.y"
    {}
    break;

  case 84:
#line 268 "parser.y"
    {}
    break;

  case 85:
#line 269 "parser.y"
    { char * str;
									  sprintf(str, "%d", (yyvsp[(1) - (1)].iValue));
									  (yyval.nodeValue) = createNode(str);
									}
    break;

  case 86:
#line 273 "parser.y"
    {}
    break;

  case 87:
#line 274 "parser.y"
    {}
    break;

  case 88:
#line 275 "parser.y"
    {}
    break;

  case 91:
#line 284 "parser.y"
    {}
    break;


/* Line 1267 of yacc.c.  */
#line 2029 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 287 "parser.y"
 /* Fim da segunda seção */

int main (int argc, char ** argv) {
 	int codigo;

    if (argc != 3) {
       printf("Usage: $./compiler input.txt output.txt\nClosing application...\n");
       exit(0);
    }
    
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    codigo = yyparse();

    fclose(yyin);
    fclose(yyout);

	return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}
