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
     KW_CHAR = 258,
     KW_INT = 259,
     KW_FLOAT = 260,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_WHILE = 264,
     KW_GOTO = 265,
     KW_READ = 266,
     KW_PRINT = 267,
     KW_RETURN = 268,
     OPERATOR_LE = 269,
     OPERATOR_GE = 270,
     OPERATOR_EQ = 271,
     OPERATOR_DIF = 272,
     TK_IDENTIFIER = 273,
     LIT_INTEGER = 274,
     LIT_CHAR = 275,
     LIT_STRING = 276,
     TOKEN_ERROR = 277
   };
#endif
/* Tokens.  */
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_GOTO 265
#define KW_READ 266
#define KW_PRINT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define TK_IDENTIFIER 273
#define LIT_INTEGER 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"
    int yyerror();
    int getLineNumber();
    int yylex();
    FILE *output = NULL;


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
#line 12 "parser.y"
{
    HASH_NODE *symbol;
    AST *ast;
}
/* Line 193 of yacc.c.  */
#line 155 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 168 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    23,    25,    33,    26,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    30,
      27,    38,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    31,    34,    37,    39,    41,
      47,    54,    63,    66,    70,    72,    73,    80,    84,    87,
      90,    94,    97,   100,   102,   106,   113,   115,   117,   121,
     123,   125,   128,   131,   133,   135,   136,   140,   142,   146,
     151,   156,   158,   160,   162,   166,   170,   174,   178,   182,
     186,   190,   194,   198,   202,   206,   208,   213,   220,   224
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    42,    41,    -1,    -1,    48,
      -1,    51,    -1,     3,    -1,     4,    -1,     5,    -1,    19,
      -1,    18,    -1,    20,    -1,    19,    -1,    44,    24,    44,
      -1,    19,    47,    -1,    20,    47,    -1,    19,    -1,    20,
      -1,    43,    45,    29,    46,    30,    -1,    43,    45,    31,
      44,    32,    30,    -1,    43,    45,    31,    44,    32,    29,
      47,    30,    -1,    43,    45,    -1,    49,    33,    50,    -1,
      49,    -1,    -1,    43,    45,    34,    50,    35,    58,    -1,
      36,    54,    37,    -1,    36,    37,    -1,    45,    29,    -1,
      58,    30,    54,    -1,    53,    54,    -1,    58,    30,    -1,
      53,    -1,    45,    38,    60,    -1,    45,    31,    60,    32,
      38,    60,    -1,    21,    -1,    60,    -1,    56,    33,    57,
      -1,    56,    -1,    55,    -1,    12,    57,    -1,    13,    60,
      -1,    52,    -1,    61,    -1,    -1,    60,    33,    59,    -1,
      60,    -1,    45,    34,    35,    -1,    45,    34,    59,    35,
      -1,    45,    31,    60,    32,    -1,    18,    -1,    19,    -1,
      20,    -1,    60,    25,    60,    -1,    60,    26,    60,    -1,
      60,    23,    60,    -1,    60,    24,    60,    -1,    60,    27,
      60,    -1,    60,    28,    60,    -1,    60,    14,    60,    -1,
      60,    15,    60,    -1,    60,    16,    60,    -1,    60,    17,
      60,    -1,    34,    60,    35,    -1,    11,    -1,     6,    60,
       7,    58,    -1,     6,    60,     7,    58,     8,    58,    -1,
       9,    60,    58,    -1,    10,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    73,    74,    77,    78,    83,    84,    85,
      88,    91,    95,    96,    97,   100,   101,   102,   103,   106,
     107,   108,   113,   116,   117,   118,   121,   126,   127,   130,
     132,   133,   134,   135,   139,   140,   142,   143,   145,   146,
     148,   149,   150,   151,   152,   153,   157,   158,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   184,   185,   186,   187
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_GOTO", "KW_READ", "KW_PRINT",
  "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_DIF",
  "TK_IDENTIFIER", "LIT_INTEGER", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR",
  "'*'", "'/'", "'+'", "'-'", "'<'", "'>'", "':'", "';'", "'['", "']'",
  "','", "'('", "')'", "'{'", "'}'", "'='", "$accept", "program", "decl",
  "dec", "type", "lit_integer", "identifier", "literal", "lit_list",
  "global_variable", "function_argument", "function_arguments", "function",
  "block_command", "label", "command_list", "assignment", "print_argument",
  "print_arguments", "simple_command", "parameter_list", "expression",
  "control_flow", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    42,    47,    43,    45,    60,    62,    58,
      59,    91,    93,    44,    40,    41,   123,   125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    43,    43,
      44,    45,    46,    46,    46,    47,    47,    47,    47,    48,
      48,    48,    49,    50,    50,    50,    51,    52,    52,    53,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     5,
       6,     8,     2,     3,     1,     0,     6,     3,     2,     2,
       3,     2,     2,     1,     3,     6,     1,     1,     3,     1,
       1,     2,     2,     1,     1,     0,     3,     1,     3,     4,
       4,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     4,     6,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     7,     8,     9,     0,     2,     4,     0,     5,     6,
       1,     3,    11,     0,     0,     0,    25,    10,    12,     0,
       0,    10,     0,     0,    24,     0,     0,    19,     0,    22,
      25,    45,    14,     0,    20,    23,     0,     0,     0,     0,
       0,    45,     0,    43,    40,    26,    44,    17,    18,     0,
      65,    51,    52,    53,     0,     0,     0,    45,    69,    36,
      39,    41,    37,    42,    28,     0,    33,     0,     0,     0,
       0,    15,    16,    21,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
      29,    31,    27,    32,     0,    34,    64,     0,    48,     0,
      47,    66,    60,    61,    62,    63,    56,    57,    54,    55,
      58,    59,    38,    30,     0,    50,    49,     0,    45,     0,
      46,    67,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    19,    55,    20,    49,     8,
      24,    25,     9,    43,    66,    67,    44,    60,    61,    68,
      99,    62,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -64
static const yytype_int16 yypact[] =
{
       8,   -64,   -64,   -64,    20,   -64,     8,     5,   -64,   -64,
     -64,   -64,   -64,   100,    29,    10,     8,    -5,   -64,    15,
      16,   -64,    39,     5,    52,    42,    10,   -64,    44,   -64,
       8,   104,   -64,   101,   -64,   -64,   128,   128,     5,   117,
     128,    -4,   -21,   -64,   -64,   -64,   -64,   101,   101,    57,
     -64,     6,   -64,   -64,   128,     7,   142,    66,   -64,   -64,
      72,   -64,   225,   225,   -64,    -3,    94,    78,    89,   128,
     128,   -64,   -64,   -64,   157,   128,   107,   104,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   -64,   117,
     -64,   -64,   -64,    94,   187,   225,   -64,   206,   -64,    88,
     172,   135,   -64,   -64,   -64,   -64,    28,    28,    81,    81,
     -64,   -64,   -64,   -64,   106,   -64,   -64,   128,   104,   128,
     -64,   -64,   225
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   139,   -64,    -9,   -11,    -7,   -64,    85,   -64,
     -64,   120,   -64,   -64,   -64,   -63,   -64,   -64,    63,   -30,
      36,   -18,   -64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -46
static const yytype_int8 yytable[] =
{
      13,    45,    36,    91,    22,    37,    38,    23,    39,    40,
      69,     1,     2,     3,    12,    32,    29,    70,    56,    57,
      10,    23,    63,    12,    42,   -13,    90,    88,    69,    21,
     113,    58,    41,    64,    65,    70,    74,   -11,    75,    26,
     -11,    76,    78,    79,    80,    81,    27,   101,    17,    18,
      42,    94,    95,    84,    85,    86,    87,    97,   100,    65,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      42,    28,    36,    33,    34,    37,    38,    31,    39,    40,
      78,    79,    80,    81,    12,    30,    65,    73,   121,    82,
      83,    84,    85,    86,    87,    78,    79,    80,    81,   100,
      36,   122,    41,    37,    38,    89,    39,    40,    86,    87,
      36,    42,    12,    37,    38,    92,    39,    40,    50,    93,
      47,    48,    12,   116,   -45,    51,    52,    53,    50,    14,
      41,    15,    71,    72,    16,    51,    52,    53,    59,    50,
      41,    54,    98,   118,   119,    11,    51,    52,    53,    77,
      35,    54,   112,   120,     0,     0,    78,    79,    80,    81,
       0,     0,    54,     0,     0,    82,    83,    84,    85,    86,
      87,    78,    79,    80,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    78,    79,    80,    81,
       0,     0,    96,     0,     0,    82,    83,    84,    85,    86,
      87,    78,    79,    80,    81,   117,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,   114,
      78,    79,    80,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,     0,     0,     0,   115,    78,
      79,    80,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87
};

static const yytype_int8 yycheck[] =
{
       7,    31,     6,    66,    15,     9,    10,    16,    12,    13,
      31,     3,     4,     5,    18,    26,    23,    38,    36,    37,
       0,    30,    40,    18,    31,    30,    29,    57,    31,    19,
      93,    38,    36,    37,    41,    38,    54,    31,    31,    24,
      34,    34,    14,    15,    16,    17,    30,    77,    19,    20,
      57,    69,    70,    25,    26,    27,    28,    75,    76,    66,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      77,    32,     6,    29,    30,     9,    10,    35,    12,    13,
      14,    15,    16,    17,    18,    33,    93,    30,   118,    23,
      24,    25,    26,    27,    28,    14,    15,    16,    17,   117,
       6,   119,    36,     9,    10,    33,    12,    13,    27,    28,
       6,   118,    18,     9,    10,    37,    12,    13,    11,    30,
      19,    20,    18,    35,    30,    18,    19,    20,    11,    29,
      36,    31,    47,    48,    34,    18,    19,    20,    21,    11,
      36,    34,    35,     8,    38,     6,    18,    19,    20,     7,
      30,    34,    89,   117,    -1,    -1,    14,    15,    16,    17,
      -1,    -1,    34,    -1,    -1,    23,    24,    25,    26,    27,
      28,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    14,    15,    16,    17,
      -1,    -1,    35,    -1,    -1,    23,    24,    25,    26,    27,
      28,    14,    15,    16,    17,    33,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    32,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    40,    41,    42,    43,    48,    51,
       0,    41,    18,    45,    29,    31,    34,    19,    20,    44,
      46,    19,    44,    43,    49,    50,    24,    30,    32,    45,
      33,    35,    44,    29,    30,    50,     6,     9,    10,    12,
      13,    36,    45,    52,    55,    58,    61,    19,    20,    47,
      11,    18,    19,    20,    34,    45,    60,    60,    45,    21,
      56,    57,    60,    60,    37,    45,    53,    54,    58,    31,
      38,    47,    47,    30,    60,    31,    34,     7,    14,    15,
      16,    17,    23,    24,    25,    26,    27,    28,    58,    33,
      29,    54,    37,    30,    60,    60,    35,    60,    35,    59,
      60,    58,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    57,    54,    32,    32,    35,    33,     8,    38,
      59,    58,    60
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
#line 70 "parser.y"
    {decompile((yyvsp[(1) - (1)].ast), 0, output);}
    break;

  case 3:
#line 73 "parser.y"
    { (yyval.ast) = astCreate(AST_DECL, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0);}
    break;

  case 4:
#line 74 "parser.y"
    { (yyval.ast) = 0;}
    break;

  case 5:
#line 77 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 6:
#line 78 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 7:
#line 83 "parser.y"
    { (yyval.ast) = astCreate(AST_CHAR, 0, 0, 0, 0, 0); }
    break;

  case 8:
#line 84 "parser.y"
    { (yyval.ast) = astCreate(AST_INT, 0, 0, 0, 0, 0); }
    break;

  case 9:
#line 85 "parser.y"
    { (yyval.ast) = astCreate(AST_FLOAT, 0, 0, 0, 0, 0); }
    break;

  case 10:
#line 88 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 11:
#line 91 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 12:
#line 95 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 13:
#line 96 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 14:
#line 97 "parser.y"
    {(yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 15:
#line 100 "parser.y"
    {(yyval.ast) = astCreate(AST_LIT_LIST, (yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;

  case 16:
#line 101 "parser.y"
    {(yyval.ast) = astCreate(AST_LIT_LIST, (yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;

  case 17:
#line 102 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 18:
#line 103 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 19:
#line 106 "parser.y"
    {(yyval.ast) = astCreate(AST_GLOBAL_VARIABLE_TYPE_A, 0, (yyvsp[(1) - (5)].ast), (yyvsp[(2) - (5)].ast), (yyvsp[(4) - (5)].ast), 0); }
    break;

  case 20:
#line 107 "parser.y"
    {(yyval.ast) = astCreate(AST_GLOBAL_VARIABLE_TYPE_B, 0, (yyvsp[(1) - (6)].ast), (yyvsp[(2) - (6)].ast), (yyvsp[(4) - (6)].ast), 0); }
    break;

  case 21:
#line 108 "parser.y"
    {(yyval.ast) = astCreate(AST_GLOBAL_VARIABLE_TYPE_C, 0, (yyvsp[(1) - (8)].ast), (yyvsp[(2) - (8)].ast), (yyvsp[(4) - (8)].ast), (yyvsp[(7) - (8)].ast)); }
    break;

  case 22:
#line 113 "parser.y"
    { (yyval.ast) = astCreate(AST_FUNCTION_ARGUMENT, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 23:
#line 116 "parser.y"
    { (yyval.ast) = astCreate(AST_FUNCTION_ARGUMENTS, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 24:
#line 117 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 25:
#line 118 "parser.y"
    { (yyval.ast) = 0;}
    break;

  case 26:
#line 121 "parser.y"
    { (yyval.ast) = astCreate(AST_FUNCTION, 0, (yyvsp[(1) - (6)].ast), (yyvsp[(2) - (6)].ast), (yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast)); }
    break;

  case 27:
#line 126 "parser.y"
    { (yyval.ast) = astCreate(AST_BLOCK_COMMAND, 0, (yyvsp[(2) - (3)].ast), 0, 0, 0); }
    break;

  case 28:
#line 127 "parser.y"
    { (yyval.ast) = astCreate(AST_BLOCK_COMMAND, 0, 0, 0, 0, 0); }
    break;

  case 29:
#line 130 "parser.y"
    { (yyval.ast) = astCreate(AST_LABEL, 0, (yyvsp[(1) - (2)].ast), 0, 0, 0); }
    break;

  case 30:
#line 132 "parser.y"
    { (yyval.ast) = astCreate(AST_LCMD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 31:
#line 133 "parser.y"
    { (yyval.ast) = astCreate(AST_LCMD, 0, (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast), 0, 0); }
    break;

  case 32:
#line 134 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (2)].ast); }
    break;

  case 33:
#line 135 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 34:
#line 139 "parser.y"
    { (yyval.ast) = astCreate(AST_ASSIGMENT_TYPE_A, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 35:
#line 140 "parser.y"
    {(yyval.ast) = astCreate(AST_ASSIGMENT_TYPE_B, 0, (yyvsp[(1) - (6)].ast), (yyvsp[(3) - (6)].ast), (yyvsp[(6) - (6)].ast), 0); }
    break;

  case 36:
#line 142 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 37:
#line 143 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 38:
#line 145 "parser.y"
    {(yyval.ast) = astCreate(AST_PRINT_ARGS, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 39:
#line 146 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 40:
#line 148 "parser.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 41:
#line 149 "parser.y"
    { (yyval.ast) = astCreate(AST_PRINT_FUN, 0, (yyvsp[(2) - (2)].ast), 0, 0,0 ); }
    break;

  case 42:
#line 150 "parser.y"
    { (yyval.ast) = astCreate(AST_RETURN, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0 ); }
    break;

  case 43:
#line 151 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 44:
#line 152 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 45:
#line 153 "parser.y"
    { (yyval.ast) = astCreate(AST_EMPTY_COMMAND, 0, 0, 0, 0, 0 ); }
    break;

  case 46:
#line 157 "parser.y"
    {(yyval.ast) = astCreate(AST_PARAM_LIST, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 47:
#line 158 "parser.y"
    { (yyval.ast) = (yyvsp[(1) - (1)].ast); }
    break;

  case 48:
#line 162 "parser.y"
    {(yyval.ast) = astCreate(AST_EXPRESSION_TYPE_A, 0, (yyvsp[(1) - (3)].ast),  0, 0, 0); }
    break;

  case 49:
#line 163 "parser.y"
    {(yyval.ast) = astCreate(AST_EXPRESSION_TYPE_B, 0, (yyvsp[(1) - (4)].ast),  (yyvsp[(3) - (4)].ast), 0, 0); }
    break;

  case 50:
#line 164 "parser.y"
    {(yyval.ast) = astCreate(AST_EXPRESSION_TYPE_C, 0, (yyvsp[(1) - (4)].ast), (yyvsp[(3) - (4)].ast), 0, 0); }
    break;

  case 51:
#line 165 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 52:
#line 166 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 53:
#line 167 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0,  0, 0, 0); }
    break;

  case 54:
#line 168 "parser.y"
    {(yyval.ast) = astCreate(AST_ADD, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 55:
#line 169 "parser.y"
    {(yyval.ast) = astCreate(AST_SUB, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 56:
#line 170 "parser.y"
    {(yyval.ast) = astCreate(AST_MUL, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 57:
#line 171 "parser.y"
    {(yyval.ast) = astCreate(AST_DIV, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 58:
#line 172 "parser.y"
    {(yyval.ast) = astCreate(AST_LT, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 59:
#line 173 "parser.y"
    {(yyval.ast) = astCreate(AST_GT, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 60:
#line 174 "parser.y"
    {(yyval.ast) = astCreate(AST_LE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 61:
#line 175 "parser.y"
    {(yyval.ast) = astCreate(AST_GE, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 62:
#line 176 "parser.y"
    {(yyval.ast) = astCreate(AST_EQ, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 63:
#line 177 "parser.y"
    {(yyval.ast) = astCreate(AST_DIF, 0, (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 64:
#line 178 "parser.y"
    { (yyval.ast) = (yyvsp[(2) - (3)].ast);}
    break;

  case 65:
#line 179 "parser.y"
    {(yyval.ast) = astCreate(AST_READ, 0, 0, 0, 0, 0); }
    break;

  case 66:
#line 184 "parser.y"
    { (yyval.ast) = astCreate(AST_IF, 0, (yyvsp[(2) - (4)].ast), (yyvsp[(4) - (4)].ast), 0, 0); }
    break;

  case 67:
#line 185 "parser.y"
    { (yyval.ast) = astCreate(AST_IF_ELSE, 0, (yyvsp[(2) - (6)].ast), (yyvsp[(4) - (6)].ast), (yyvsp[(6) - (6)].ast), 0); }
    break;

  case 68:
#line 186 "parser.y"
    { (yyval.ast) = astCreate(AST_WHILE, 0, (yyvsp[(2) - (3)].ast), (yyvsp[(3) - (3)].ast), 0, 0); }
    break;

  case 69:
#line 187 "parser.y"
    { (yyval.ast) = astCreate(AST_GOTO, 0, (yyvsp[(2) - (2)].ast), 0, 0, 0); }
    break;


/* Line 1267 of yacc.c.  */
#line 1837 "y.tab.c"
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


#line 190 "parser.y"

int yyerror () {
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}

