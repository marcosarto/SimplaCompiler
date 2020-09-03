/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y" /* yacc.c:337  */

#include "def.h"
#include "table.h"
#include "semantica.h"
#include "interprete.h"
#include "writeToFile.h"
#define YYSTYPE Pnode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
Pnode root = NULL;

#line 84 "parser.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    REAL = 259,
    STRING = 260,
    BOOLEAN = 261,
    VOID = 262,
    ID = 263,
    FUNC = 264,
    BODY = 265,
    END = 266,
    BREAK = 267,
    EQU = 268,
    NEQ = 269,
    GEQ = 270,
    LEQ = 271,
    AND = 272,
    OR = 273,
    IF = 274,
    ELSE = 275,
    INTCONST = 276,
    NOT = 277,
    REALCONST = 278,
    STRCONST = 279,
    THEN = 280,
    BOOLCONST = 281,
    DO = 282,
    FOR = 283,
    READ = 284,
    RETURN = 285,
    TO = 286,
    WHILE = 287,
    GRT = 288,
    LSS = 289,
    WRITE = 290,
    WRITELN = 291,
    PLUS = 292,
    STAR = 293,
    MINUS = 294,
    EQUAL = 295,
    DIV = 296,
    ADDR = 297,
    NEW = 298,
    PRINTSTACK = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

#define YYUNDEFTOK  2
#define YYMAXUTOK   299

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,     2,     2,    48,     2,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    47,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    25,    26,    28,    32,    32,    33,    35,
      36,    37,    38,    39,    41,    42,    44,    44,    51,    53,
      55,    56,    58,    58,    62,    64,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    78,    78,    82,
      87,    88,    90,    92,    96,    96,   102,   105,   106,   108,
     111,   115,   116,   118,   119,   121,   125,   127,   128,   130,
     134,   136,   137,   138,   139,   140,   141,   143,   146,   148,
     149,   151,   154,   156,   157,   159,   161,   162,   163,   163,
     165,   166,   167,   168,   171,   172,   174,   175,   176,   177,
     179,   179,   183,   184,   186,   191,   192
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "STRING", "BOOLEAN",
  "VOID", "ID", "FUNC", "BODY", "END", "BREAK", "EQU", "NEQ", "GEQ", "LEQ",
  "AND", "OR", "IF", "ELSE", "INTCONST", "NOT", "REALCONST", "STRCONST",
  "THEN", "BOOLCONST", "DO", "FOR", "READ", "RETURN", "TO", "WHILE", "GRT",
  "LSS", "WRITE", "WRITELN", "PLUS", "STAR", "MINUS", "EQUAL", "DIV",
  "ADDR", "NEW", "PRINTSTACK", "'.'", "':'", "';'", "','", "'('", "')'",
  "$accept", "program", "var_decl_list", "var_decl", "id_list", "@1",
  "type", "func_decl_list", "func_decl", "@2", "opt_param_list",
  "param_list", "param_decl", "@3", "body", "stat_list", "stat",
  "assign_stat", "@4", "if_stat", "opt_else_stat", "print_stack",
  "while_stat", "for_stat", "@5", "return_stat", "opt_expr", "read_stat",
  "write_stat", "write_op", "expr_list", "expr", "logic_op", "bool_term",
  "rel_op", "rel_term", "low_prec_op", "low_term", "high_prec_op",
  "factor", "@6", "unary_op", "const", "func_call", "@7", "opt_expr_list",
  "cond_expr", "cast", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    46,    58,    59,    44,    40,
      41
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -91

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       3,   -24,    27,    25,     3,     6,   -12,   -83,    41,    60,
      25,   -83,    99,     3,   -83,    45,    10,   -83,   -83,   -83,
     -83,   -83,   -83,    29,   -83,    34,    48,   -83,     9,    91,
      51,     9,     9,   -83,   -83,    59,    98,    65,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,    64,   -83,   -83,   -83,
     107,    79,    68,   -83,   -83,    48,     9,   -83,   -83,   -83,
     -83,   -83,   -83,   110,     9,    42,   -83,    77,   -18,   -83,
       9,   -83,   -83,   -83,    71,   -83,     3,   -83,    78,    23,
      72,   -83,    45,     9,   -83,    73,   -83,    76,     9,     9,
      69,   -83,    -8,   -83,   -83,    45,     9,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,     9,     9,   -83,   -83,     9,
     -83,     9,    81,    80,    45,   -83,   -83,    82,    -3,    83,
      87,   107,    78,   -83,    84,     9,   -83,   -83,   106,   -83,
     -21,   -18,   -83,     4,     9,   -83,   116,   -83,     9,    99,
      99,   -83,   -83,    26,    45,   124,   -83,     8,   -83,   -83,
     -83,     3,     9,   -83,   -83,     9,    60,    54,    61,    89,
     -83,    45,   -83,   126,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     8,     0,    15,     4,     0,     0,     1,     0,     0,
      15,     3,     0,     0,    16,     0,     0,    14,     9,    10,
      11,    12,    13,     0,     7,     0,    37,    36,     0,     0,
       0,    48,     0,    51,    52,     0,     0,     0,    27,    28,
      35,    29,    30,    31,    32,    33,     0,    34,     2,     5,
      19,     0,     0,    95,    96,    77,     0,    86,    85,    87,
      88,    89,    84,     0,     0,     0,    56,    60,    68,    72,
       0,    80,    81,    82,     0,    44,     0,    46,    47,     0,
       0,    24,    26,     0,    22,     0,    18,    21,     0,    93,
       0,    78,     0,    57,    58,     0,     0,    61,    62,    64,
      66,    63,    65,    69,    70,     0,     0,    73,    74,     0,
      75,     0,     0,     0,     0,    42,    25,     0,    54,     0,
       0,     0,    38,    92,     0,     0,    79,    76,    41,    55,
      59,    67,    71,     0,     0,    49,     0,    50,     0,     0,
       0,    20,    91,     0,     0,     0,    83,     0,    43,    53,
      23,     4,     0,    40,    39,     0,     0,     0,     0,     0,
      94,     0,    17,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,    -4,   -83,   -10,   -83,   -77,   128,   -83,   -83,
     -83,    18,   -83,   -83,   -16,   -76,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -82,   -27,   -83,    46,   -83,    36,   -83,    37,   -83,   -62,
     -83,   -83,   -83,   -13,   -83,   -83,   -83,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    23,     9,    10,    25,
      85,    86,    87,   119,    16,    36,    37,    38,    51,    39,
     145,    40,    41,    42,   112,    43,    77,    44,    45,    46,
     117,   118,    96,    66,   105,    67,   106,    68,   109,    69,
     126,    70,    71,    72,    52,   124,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    65,    47,    24,    78,    79,   116,   123,   110,    93,
      94,     1,    53,    54,    93,    94,   103,    55,   104,   128,
     107,    93,    94,   108,    -6,    93,    94,     7,    56,    90,
      57,    58,    59,    60,     8,    61,    13,    92,   136,   155,
      93,    94,   127,    93,    94,   138,   152,   132,    62,    14,
     114,    63,    12,    26,   146,    48,   149,    27,    64,    93,
      94,   122,   150,   151,    28,   160,   113,    95,   153,    47,
      15,    93,    94,    29,    30,    31,    49,    32,    93,    94,
      33,    34,    47,    50,   133,   163,    93,    94,   161,    35,
      97,    98,    99,   100,   125,    93,    94,   -90,   143,    75,
      76,    47,    18,    19,    20,    21,    22,   147,    80,    81,
     101,   102,    82,    83,   103,    84,   104,    89,    91,    88,
     111,   134,   115,   120,   121,   157,   144,   148,   158,   139,
     135,    47,   137,   140,   142,   154,   162,   164,    17,   141,
     159,   130,   129,   131,     0,     0,     0,   156,    47
};

static const yytype_int16 yycheck[] =
{
       4,    28,    15,    13,    31,    32,    82,    89,    70,    17,
      18,     8,     3,     4,    17,    18,    37,     8,    39,    95,
      38,    17,    18,    41,    48,    17,    18,     0,    19,    56,
      21,    22,    23,    24,     9,    26,    48,    64,   114,    31,
      17,    18,    50,    17,    18,    48,    20,   109,    39,     8,
      27,    42,    46,     8,    50,    45,   138,    12,    49,    17,
      18,    88,   139,   140,    19,    11,    76,    25,   144,    82,
      10,    17,    18,    28,    29,    30,    47,    32,    17,    18,
      35,    36,    95,    49,   111,   161,    17,    18,    27,    44,
      13,    14,    15,    16,    25,    17,    18,    49,   125,     8,
      49,   114,     3,     4,     5,     6,     7,   134,    49,    11,
      33,    34,    47,    49,    37,     8,    39,    49,     8,    40,
      49,    40,    50,    50,    48,   152,    20,    11,   155,    46,
      50,   144,    50,    46,    50,    11,    47,    11,    10,   121,
     156,   105,    96,   106,    -1,    -1,    -1,   151,   161
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    52,    53,    54,    55,    56,     0,     9,    58,
      59,    53,    46,    48,     8,    10,    65,    58,     3,     4,
       5,     6,     7,    57,    55,    60,     8,    12,    19,    28,
      29,    30,    32,    35,    36,    44,    66,    67,    68,    70,
      72,    73,    74,    76,    78,    79,    80,    94,    45,    47,
      49,    69,    95,     3,     4,     8,    19,    21,    22,    23,
      24,    26,    39,    42,    49,    82,    84,    86,    88,    90,
      92,    93,    94,    97,    98,     8,    49,    77,    82,    82,
      49,    11,    47,    49,     8,    61,    62,    63,    40,    49,
      82,     8,    82,    17,    18,    25,    83,    13,    14,    15,
      16,    33,    34,    37,    39,    85,    87,    38,    41,    89,
      90,    49,    75,    55,    27,    50,    66,    81,    82,    64,
      50,    48,    82,    81,    96,    25,    91,    50,    66,    84,
      86,    88,    90,    82,    40,    50,    66,    50,    48,    46,
      46,    62,    50,    82,    20,    71,    50,    82,    11,    81,
      57,    57,    20,    66,    11,    31,    53,    82,    82,    65,
      11,    27,    47,    66,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    56,    55,    55,    57,
      57,    57,    57,    57,    58,    58,    60,    59,    61,    61,
      62,    62,    64,    63,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    69,    68,    70,
      71,    71,    72,    73,    75,    74,    76,    77,    77,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    91,    90,
      90,    90,    90,    90,    92,    92,    93,    93,    93,    93,
      95,    94,    96,    96,    97,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     2,     0,     0,    11,     1,     0,
       3,     1,     0,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     6,
       2,     0,     3,     5,     0,    10,     2,     1,     0,     4,
       4,     1,     1,     3,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     2,     3,     1,     0,     3,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     0,     7,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 20 "parser.y" /* yacc.c:1652  */
    {root = yyval = nontermnode(NPROGRAM);
                                                yyval->c1 = yyvsp[-3];
                                                yyval->c2 = yyvsp[-2];
                                                yyval->b = yyvsp[-1];}
#line 1382 "parser.c" /* yacc.c:1652  */
    break;

  case 3:
#line 25 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1]; yyvsp[-1]->b = yyvsp[0];}
#line 1388 "parser.c" /* yacc.c:1652  */
    break;

  case 4:
#line 26 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1394 "parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 28 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NVAR_DECL);
                                yyval->c1 = yyvsp[-3];
                                yyval->c2 = yyvsp[-1];}
#line 1402 "parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 32 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1408 "parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 32 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1414 "parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 33 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1420 "parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 35 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_INTEGER);}
#line 1426 "parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 36 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_REAL);}
#line 1432 "parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 37 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_STRING);}
#line 1438 "parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 38 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_BOOLEAN);}
#line 1444 "parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 39 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_VOID);}
#line 1450 "parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 41 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1]; yyvsp[-1]->b = yyvsp[0];}
#line 1456 "parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 42 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1462 "parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 44 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1468 "parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 44 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NFUNC_DECL);
                                                                                        yyval->c1 = yyvsp[-2];
                                                                                        yyval->c2 = yyvsp[-8];
                                                                                        yyvsp[-8]->c1 = yyvsp[-1];
                                                                                        yyvsp[-8]->c2 = yyvsp[-6];
                                                                                        yyvsp[-8]->b = yyvsp[-3];}
#line 1479 "parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 51 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NOPT_PARAM_LIST);
                        yyval->c1 = yyvsp[0];}
#line 1486 "parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 53 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1492 "parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 55 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1498 "parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 58 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1504 "parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 58 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NPARAM_DECL);
                                        yyval->c1 = yyvsp[-2];
                                        yyval->c2 = yyvsp[0];}
#line 1512 "parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 62 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];}
#line 1518 "parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 64 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1524 "parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 65 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];}
#line 1530 "parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 76 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_BREAK);}
#line 1536 "parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 78 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1542 "parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 78 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NASSIGN_STAT);
                                                    yyval->c1 = yyvsp[-2];
                                                    yyval->c2 = yyvsp[0];}
#line 1550 "parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 82 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NIF_STAT);
                                                yyval->c1 = yyvsp[-4];
                                                yyval->c2 = yyvsp[-2];
                                                yyvsp[-4]->b = yyvsp[-1];}
#line 1559 "parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 87 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1565 "parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 88 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1571 "parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 90 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NPRINT_STACK);}
#line 1577 "parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 92 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NWHILE_STAT);
                                        yyval->c1 = yyvsp[-3];
                                        yyval->c2 = yyvsp[-1];}
#line 1585 "parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 96 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1591 "parser.c" /* yacc.c:1652  */
    break;

  case 45:
#line 96 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NFOR_STAT);
                                                                yyval->c1 = yyvsp[-7];
                                                                yyval->c2 = yyvsp[-1];
                                                                yyvsp[-7]->c1 = yyvsp[-5];
                                                                yyvsp[-7]->c2 = yyvsp[-3];}
#line 1601 "parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 102 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NRETURN_STAT);
                        yyval->c1 = yyvsp[0];}
#line 1608 "parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 106 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1614 "parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 108 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NREAD_STAT);
                                yyval->c1 = yyvsp[-1];}
#line 1621 "parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 111 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NWRITE_STAT);
                                        yyval->c1 = yyvsp[-3];
                                        yyval->c2 = yyvsp[-1];}
#line 1629 "parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 115 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_WRITE);}
#line 1635 "parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 116 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_WRITELN);}
#line 1641 "parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 118 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1647 "parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 121 "parser.y" /* yacc.c:1652  */
    {yyval= yyvsp[-1];
                                yyvsp[-1]->c1 = yyvsp[-2];
                                yyvsp[-1]->c2 = yyvsp[0];
                                }
#line 1656 "parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 125 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1662 "parser.c" /* yacc.c:1652  */
    break;

  case 57:
#line 127 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_AND);}
#line 1668 "parser.c" /* yacc.c:1652  */
    break;

  case 58:
#line 128 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_OR);}
#line 1674 "parser.c" /* yacc.c:1652  */
    break;

  case 59:
#line 130 "parser.y" /* yacc.c:1652  */
    {yyval=yyvsp[-1];
                                        yyvsp[-1]->c1=yyvsp[-2];
                                        yyvsp[-1]->c2=yyvsp[0];
                                        }
#line 1683 "parser.c" /* yacc.c:1652  */
    break;

  case 60:
#line 134 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1689 "parser.c" /* yacc.c:1652  */
    break;

  case 61:
#line 136 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_EQU);}
#line 1695 "parser.c" /* yacc.c:1652  */
    break;

  case 62:
#line 137 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_NEQ);}
#line 1701 "parser.c" /* yacc.c:1652  */
    break;

  case 63:
#line 138 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_GRT);}
#line 1707 "parser.c" /* yacc.c:1652  */
    break;

  case 64:
#line 139 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_GEQ);}
#line 1713 "parser.c" /* yacc.c:1652  */
    break;

  case 65:
#line 140 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_LSS);}
#line 1719 "parser.c" /* yacc.c:1652  */
    break;

  case 66:
#line 141 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_LEQ);}
#line 1725 "parser.c" /* yacc.c:1652  */
    break;

  case 67:
#line 143 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];
                                        yyvsp[-1]->c1 = yyvsp[-2];
                                        yyvsp[-1]->c2 = yyvsp[0];}
#line 1733 "parser.c" /* yacc.c:1652  */
    break;

  case 68:
#line 146 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1739 "parser.c" /* yacc.c:1652  */
    break;

  case 69:
#line 148 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_PLUS);}
#line 1745 "parser.c" /* yacc.c:1652  */
    break;

  case 70:
#line 149 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_MINUS);}
#line 1751 "parser.c" /* yacc.c:1652  */
    break;

  case 71:
#line 151 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];
                                        yyvsp[-1]->c1 = yyvsp[-2];
                                        yyvsp[-1]->c2 = yyvsp[0];}
#line 1759 "parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 154 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1765 "parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 156 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_STAR);}
#line 1771 "parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 157 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_DIV);}
#line 1777 "parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 159 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];
                        yyval->c1 = yyvsp[0];}
#line 1784 "parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 161 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];}
#line 1790 "parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 162 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1796 "parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 163 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1802 "parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 163 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_ADDR);
                            yyval->c1 = yyvsp[0];}
#line 1809 "parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 165 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1815 "parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 168 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-3];
                yyvsp[-3]->c1 = yyvsp[-1];}
#line 1822 "parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 171 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_MINUS);}
#line 1828 "parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 172 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_NOT);}
#line 1834 "parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 174 "parser.y" /* yacc.c:1652  */
    {yyval = intconstnode();}
#line 1840 "parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 175 "parser.y" /* yacc.c:1652  */
    {yyval = realconstnode();}
#line 1846 "parser.c" /* yacc.c:1652  */
    break;

  case 88:
#line 176 "parser.y" /* yacc.c:1652  */
    {yyval = strconstnode();}
#line 1852 "parser.c" /* yacc.c:1652  */
    break;

  case 89:
#line 177 "parser.y" /* yacc.c:1652  */
    {yyval = boolconstnode();}
#line 1858 "parser.c" /* yacc.c:1652  */
    break;

  case 90:
#line 179 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1864 "parser.c" /* yacc.c:1652  */
    break;

  case 91:
#line 179 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NFUNC_CALL);
                                                       yyval->c1 = yyvsp[-3];
                                                       yyvsp[-3]->c1 = yyvsp[-1];}
#line 1872 "parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 184 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1878 "parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 186 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NCOND_EXPR);
                                        yyval->b = yyvsp[-5];
                                        yyval->c1 = yyvsp[-3];
                                        yyval->c2 = yyvsp[-1];}
#line 1887 "parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 191 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_INTEGER);}
#line 1893 "parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 192 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_REAL);}
#line 1899 "parser.c" /* yacc.c:1652  */
    break;


#line 1903 "parser.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 194 "parser.y" /* yacc.c:1918  */

Pnode nontermnode(Nonterminal nonterm)
{
    Pnode p = newnode(T_NONTERMINAL);
    p->value.ival = nonterm;
    return(p);
}
Pnode idnode()
{
    Pnode p = newnode(T_ID);
    p->value.sval = lexval.sval;
    return(p);
}
Pnode keynode(Typenode keyword)
{
    return(newnode(keyword));
}
Pnode intconstnode()
{
    Pnode p = newnode(T_INTCONST);
    p->value.ival = lexval.ival;
    return(p);
}
Pnode strconstnode()
{
    Pnode p = newnode(T_STRCONST);
    p->value.sval = lexval.sval;
    return(p);
}
Pnode realconstnode()
{
    Pnode p = newnode(T_REALCONST);
    p->value.rval = lexval.rval;
    return(p);
}
Pnode boolconstnode()
{
  Pnode p = newnode(T_BOOLCONST);
  p->value.bval = lexval.bval;
  return(p);
}
Pnode newnode(Typenode tnode)
{
  Pnode p = malloc(sizeof(Node));
  p->type = tnode;
  p->linen = line;
  p->c1 = p->c2 = p->b = NULL;
  return(p);
}
int main(int argc, char **argv)
{
    int result;
    initTable();
    initWriteToFile();

    if(argc!=2) {
            printf("Inserisci un solo argomento\n");
            exit(-5);
        }

    yyin = fopen(argv[1], "r");

    if((result = yyparse()) == 0){
        //treeprint(root,0);
        Pnode semCheckRoot = root;
        evalType(semCheckRoot);
        print(getGlobale());
        runCode(root);
        closeWriteToFile();
        }
    return(result);
}


int yywrap()
{
        return 1;
}

void yyerror()
{
  fprintf(stderr, "Line %d: errSintattico del simbolo \"%s\"\n",
          line, yytext);
  exit(-1);
}
