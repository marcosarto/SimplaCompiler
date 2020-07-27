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
#define YYSTYPE Pnode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
Pnode root = NULL;

#line 80 "parser.c" /* yacc.c:337  */
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
    WRITELN = 291
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
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      41,    42,    46,    44,    40,    45,    37,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    39,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    16,    16,    21,    22,    24,    28,    28,    29,    31,
      32,    33,    34,    35,    37,    38,    40,    40,    47,    49,
      51,    52,    54,    54,    57,    59,    60,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    72,    72,    76,    81,
      82,    84,    88,    88,    94,    97,    98,   100,   103,   107,
     108,   110,   113,   115,   116,   118,   121,   123,   124,   125,
     126,   127,   128,   130,   133,   135,   136,   138,   141,   143,
     144,   146,   148,   149,   149,   150,   151,   152,   153,   156,
     157,   159,   160,   161,   162,   164,   164,   167,   168,   170,
     171,   173,   177,   178
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
  "LSS", "WRITE", "WRITELN", "'.'", "':'", "';'", "','", "'('", "')'",
  "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "program", "var_decl_list",
  "var_decl", "id_list", "@1", "type", "func_decl_list", "func_decl", "@2",
  "opt_param_list", "param_list", "param_decl", "@3", "body", "stat_list",
  "stat", "assign_stat", "@4", "if_stat", "opt_else_stat", "while_stat",
  "for_stat", "@5", "return_stat", "opt_expr", "read_stat", "write_stat",
  "write_op", "expr", "logic_op", "bool_term", "rel_op", "rel_term",
  "low_prec_op", "low_term", "high_prec_op", "factor", "@6", "unary_op",
  "const", "func_call", "@7", "opt_expr_list", "expr_list", "cond_expr",
  "cast", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    46,    58,    59,
      44,    40,    41,    61,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -22,    20,    17,     1,    10,     3,   -79,    37,    40,
      17,   -79,   101,     1,   -79,    32,    15,   -79,   -79,   -79,
     -79,   -79,   -79,    16,   -79,    18,    38,   -79,    13,    48,
      53,    13,    13,   -79,   -79,    62,    61,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,    72,   -79,   -79,   -79,   103,    71,
      74,   -79,   -79,    38,    13,   -79,   -79,   -79,   -79,   -79,
      13,   -79,    64,   -79,    -3,   -32,   -79,    13,   -79,   -79,
     -79,    75,   -79,     1,   -79,    11,    57,   -79,    32,    13,
     -79,    76,   -79,    77,    13,    13,   -79,    70,     5,   -79,
     -79,    32,    13,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,    13,    13,   -79,   -79,    13,   -79,    13,    78,    81,
      32,   -79,    52,    82,    88,    89,   103,    11,    86,   -79,
      13,   -79,   100,   -79,    46,   -32,   -79,     7,    13,   -79,
     118,    13,   -79,   101,   101,   -79,   -79,    92,    32,   119,
     -79,    54,   -79,   -79,   -79,     1,    13,   -79,   -79,    13,
      40,    85,    59,    93,   -79,    32,   -79,   120,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     8,     0,    15,     4,     0,     0,     1,     0,     0,
      15,     3,     0,     0,    16,     0,     0,    14,     9,    10,
      11,    12,    13,     0,     7,     0,    36,    35,     0,     0,
       0,    46,     0,    49,    50,     0,     0,    27,    28,    29,
      30,    31,    32,    33,     0,    34,     2,     5,    19,     0,
       0,    92,    93,    73,     0,    81,    80,    82,    83,    84,
       0,    79,     0,    52,    56,    64,    68,     0,    75,    76,
      77,     0,    42,     0,    44,    45,     0,    24,    26,     0,
      22,     0,    18,    21,     0,    88,    74,     0,     0,    53,
      54,     0,     0,    57,    58,    60,    62,    59,    61,    65,
      66,     0,     0,    69,    70,     0,    71,     0,     0,     0,
       0,    25,    90,     0,     0,     0,     0,    37,     0,    87,
       0,    72,    40,    51,    55,    63,    67,     0,     0,    47,
       0,     0,    48,     0,     0,    20,    86,     0,     0,     0,
      78,     0,    41,    89,    23,     4,     0,    39,    38,     0,
       0,     0,     0,     0,    91,     0,    17,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,    -4,   -79,   -10,   -79,   -35,   123,   -79,   -79,
     -79,    19,   -79,   -79,   -16,   -72,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -27,
     -79,    44,   -79,    36,   -79,    41,   -79,   -59,   -79,   -79,
     -79,   -13,   -79,   -79,   -78,   -79,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    23,     9,    10,    25,
      81,    82,    83,   114,    16,    35,    36,    37,    49,    38,
     139,    39,    40,   108,    41,    74,    42,    43,    44,   112,
      92,    63,   101,    64,   102,    65,   105,    66,    86,    67,
      68,    69,    50,   118,   113,    70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    62,    45,    24,    75,    76,   111,   119,   106,     1,
      93,    94,    95,    96,   103,   104,    51,    52,    -6,   122,
       7,    53,    89,    90,    89,    90,     8,    87,    89,    90,
      97,    98,    54,    88,    55,    56,    57,    58,   130,    59,
      26,    99,   100,    13,    27,    14,   126,   121,    12,   140,
      15,    28,    46,   143,    60,    47,    72,   117,    61,    48,
      29,    30,    31,   109,    32,    45,   147,    33,    34,    89,
      90,    89,    90,    77,    89,    90,    89,    90,    45,   -85,
     127,    89,    90,   157,   110,   149,   155,    89,    90,    91,
      99,   100,   131,   137,    73,   120,   154,    45,   144,   145,
      78,   141,    89,    90,    18,    19,    20,    21,    22,    89,
      90,    80,   146,    79,    84,    85,   107,   116,   115,   151,
     138,   128,   152,   129,   132,    45,   133,   134,   136,   142,
     148,   158,   156,    17,   153,   135,   123,   124,     0,     0,
       0,   150,    45,   125
};

static const yytype_int16 yycheck[] =
{
       4,    28,    15,    13,    31,    32,    78,    85,    67,     8,
      13,    14,    15,    16,    46,    47,     3,     4,    40,    91,
       0,     8,    17,    18,    17,    18,     9,    54,    17,    18,
      33,    34,    19,    60,    21,    22,    23,    24,   110,    26,
       8,    44,    45,    40,    12,     8,   105,    42,    38,    42,
      10,    19,    37,   131,    41,    39,     8,    84,    45,    41,
      28,    29,    30,    73,    32,    78,   138,    35,    36,    17,
      18,    17,    18,    11,    17,    18,    17,    18,    91,    41,
     107,    17,    18,   155,    27,    31,    27,    17,    18,    25,
      44,    45,    40,   120,    41,    25,    11,   110,   133,   134,
      39,   128,    17,    18,     3,     4,     5,     6,     7,    17,
      18,     8,    20,    41,    43,    41,    41,    40,    42,   146,
      20,    43,   149,    42,    42,   138,    38,    38,    42,    11,
      11,    11,    39,    10,   150,   116,    92,   101,    -1,    -1,
      -1,   145,   155,   102
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    49,    50,    51,    52,    53,     0,     9,    55,
      56,    50,    38,    40,     8,    10,    62,    55,     3,     4,
       5,     6,     7,    54,    52,    57,     8,    12,    19,    28,
      29,    30,    32,    35,    36,    63,    64,    65,    67,    69,
      70,    72,    74,    75,    76,    89,    37,    39,    41,    66,
      90,     3,     4,     8,    19,    21,    22,    23,    24,    26,
      41,    45,    77,    79,    81,    83,    85,    87,    88,    89,
      93,    94,     8,    41,    73,    77,    77,    11,    39,    41,
       8,    58,    59,    60,    43,    41,    86,    77,    77,    17,
      18,    25,    78,    13,    14,    15,    16,    33,    34,    44,
      45,    80,    82,    46,    47,    84,    85,    41,    71,    52,
      27,    63,    77,    92,    61,    42,    40,    77,    91,    92,
      25,    42,    63,    79,    81,    83,    85,    77,    43,    42,
      63,    40,    42,    38,    38,    59,    42,    77,    20,    68,
      42,    77,    11,    92,    54,    54,    20,    63,    11,    31,
      50,    77,    77,    62,    11,    27,    39,    63,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    53,    52,    52,    54,
      54,    54,    54,    54,    55,    55,    57,    56,    58,    58,
      59,    59,    61,    60,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    66,    65,    67,    68,
      68,    69,    71,    70,    72,    73,    73,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    85,    85,    85,    85,    85,    87,
      87,    88,    88,    88,    88,    90,    89,    91,    91,    92,
      92,    93,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     2,     0,     0,    11,     1,     0,
       3,     1,     0,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     6,     2,
       0,     5,     0,    10,     2,     1,     0,     4,     4,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     2,     3,     0,     2,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     0,     5,     1,     0,     3,
       1,     7,     1,     1
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
#line 16 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NPROGRAM);
                                                yyval->c1 = yyvsp[-3];
                                                yyval->c2 = yyvsp[-2];
                                                yyval->b = yyvsp[-1];}
#line 1365 "parser.c" /* yacc.c:1652  */
    break;

  case 3:
#line 21 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1]; yyvsp[-1]->b = yyvsp[0];}
#line 1371 "parser.c" /* yacc.c:1652  */
    break;

  case 4:
#line 22 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1377 "parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 24 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NVAR_DECL);
                                yyval->c1 = yyvsp[-3];
                                yyval->c2 = yyvsp[-1];}
#line 1385 "parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 28 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1391 "parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 28 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[-1];}
#line 1397 "parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 29 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1403 "parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 31 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_INTEGER);}
#line 1409 "parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 32 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_REAL);}
#line 1415 "parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 33 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_STRING);}
#line 1421 "parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 34 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_BOOLEAN);}
#line 1427 "parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 35 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_VOID);}
#line 1433 "parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 37 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1]; yyvsp[-1]->b = yyvsp[0];}
#line 1439 "parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 38 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1445 "parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 40 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1451 "parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 40 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NFUNC_DECL);
                                                                                        yyval->c1 = yyvsp[-2];
                                                                                        yyval->c2 = yyvsp[-1];
                                                                                        yyval->b = yyvsp[-8];
                                                                                        yyvsp[-8]->b = yyvsp[-3];
                                                                                        yyvsp[-3]->b = yyvsp[-6];}
#line 1462 "parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 47 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NOPT_PARAM_LIST);
                        yyval->c1 = yyvsp[0];}
#line 1469 "parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 49 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1475 "parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 51 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1481 "parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 54 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1487 "parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 54 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NPARAM_DECL);
                                        yyval->c1 = yyvsp[-2];
                                        yyval->c2 = yyvsp[0];}
#line 1495 "parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 57 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];}
#line 1501 "parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 59 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1507 "parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 60 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-1];}
#line 1513 "parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 70 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_BREAK);}
#line 1519 "parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 72 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1525 "parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 72 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NASSIGN_STAT);
                                        yyval->c1 = yyvsp[-2];
                                        yyval->c2 = yyvsp[0];}
#line 1533 "parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 76 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NIF_STAT);
                                                yyval->c1 = yyvsp[-4];
                                                yyval->c2 = yyvsp[-2];
                                                yyval->b = yyvsp[-1];}
#line 1542 "parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 81 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[0];}
#line 1548 "parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 82 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1554 "parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 84 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NWHILE_STAT);
                                        yyval->c1 = yyvsp[-3];
                                        yyval->c2 = yyvsp[-1];}
#line 1562 "parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 88 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1568 "parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 88 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NFOR_STAT);
                                                                yyval->c1 = yyvsp[-4];
                                                                yyval->c2 = yyvsp[-2];
                                                                yyval->b = yyvsp[-7];
                                                                yyvsp[-7]->b = yyvsp[-5];}
#line 1578 "parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 94 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NRETURN_STAT);
                        yyval->c1 = yyvsp[0];}
#line 1585 "parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 98 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1591 "parser.c" /* yacc.c:1652  */
    break;

  case 47:
#line 100 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NREAD_STAT);
                                yyval->c1 = yyvsp[-1];}
#line 1598 "parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 103 "parser.y" /* yacc.c:1652  */
    {yyval = nontermnode(NWRITE_STAT);
                                        yyval->c1 = yyvsp[-3];
                                        yyval->c2 = yyvsp[-1];}
#line 1606 "parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 107 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_WRITE);}
#line 1612 "parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 108 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_WRITELN);}
#line 1618 "parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 110 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-2];
                                yyval->c2 = yyvsp[-1];
                                yyval->b = yyvsp[0];}
#line 1626 "parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 113 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1632 "parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 115 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_AND);}
#line 1638 "parser.c" /* yacc.c:1652  */
    break;

  case 54:
#line 116 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_OR);}
#line 1644 "parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 118 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-2];
                                yyval->c2 = yyvsp[-1];
                                yyval->b = yyvsp[0];}
#line 1652 "parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 121 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1658 "parser.c" /* yacc.c:1652  */
    break;

  case 57:
#line 123 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_EQU);}
#line 1664 "parser.c" /* yacc.c:1652  */
    break;

  case 58:
#line 124 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_NEQ);}
#line 1670 "parser.c" /* yacc.c:1652  */
    break;

  case 59:
#line 125 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_GRT);}
#line 1676 "parser.c" /* yacc.c:1652  */
    break;

  case 60:
#line 126 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_GEQ);}
#line 1682 "parser.c" /* yacc.c:1652  */
    break;

  case 61:
#line 127 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_LSS);}
#line 1688 "parser.c" /* yacc.c:1652  */
    break;

  case 62:
#line 128 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_LEQ);}
#line 1694 "parser.c" /* yacc.c:1652  */
    break;

  case 63:
#line 130 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-2];
                                        yyval->c2 = yyvsp[-1];
                                        yyval->b = yyvsp[0];}
#line 1702 "parser.c" /* yacc.c:1652  */
    break;

  case 64:
#line 133 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1708 "parser.c" /* yacc.c:1652  */
    break;

  case 65:
#line 135 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_PLUS);}
#line 1714 "parser.c" /* yacc.c:1652  */
    break;

  case 66:
#line 136 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_MINUS);}
#line 1720 "parser.c" /* yacc.c:1652  */
    break;

  case 67:
#line 138 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-2];
                                        yyval->c2 = yyvsp[-1];
                                        yyval->b = yyvsp[0];}
#line 1728 "parser.c" /* yacc.c:1652  */
    break;

  case 68:
#line 141 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1734 "parser.c" /* yacc.c:1652  */
    break;

  case 69:
#line 143 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_STAR);}
#line 1740 "parser.c" /* yacc.c:1652  */
    break;

  case 70:
#line 144 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_DIV);}
#line 1746 "parser.c" /* yacc.c:1652  */
    break;

  case 71:
#line 146 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-1];
                        yyval->c2 = yyvsp[0];}
#line 1753 "parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 148 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-1];}
#line 1759 "parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 149 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1765 "parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 149 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1771 "parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 150 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1777 "parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 151 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1783 "parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 152 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[0];}
#line 1789 "parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 153 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-3];
                yyval->c2 = yyvsp[-1];}
#line 1796 "parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 156 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_MINUS);}
#line 1802 "parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 157 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_NOT);}
#line 1808 "parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 159 "parser.y" /* yacc.c:1652  */
    {yyval = intconstnode();}
#line 1814 "parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 160 "parser.y" /* yacc.c:1652  */
    {yyval = realconstnode();}
#line 1820 "parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 161 "parser.y" /* yacc.c:1652  */
    {yyval = strconstnode();}
#line 1826 "parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 162 "parser.y" /* yacc.c:1652  */
    {yyval = boolconstnode();}
#line 1832 "parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 164 "parser.y" /* yacc.c:1652  */
    {yyval = idnode();}
#line 1838 "parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 164 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-3];
                                                        yyval->c2 = yyvsp[-1];}
#line 1845 "parser.c" /* yacc.c:1652  */
    break;

  case 88:
#line 168 "parser.y" /* yacc.c:1652  */
    {yyval = NULL;}
#line 1851 "parser.c" /* yacc.c:1652  */
    break;

  case 89:
#line 170 "parser.y" /* yacc.c:1652  */
    {yyval = yyvsp[-2]; yyvsp[-2]->b = yyvsp[0];}
#line 1857 "parser.c" /* yacc.c:1652  */
    break;

  case 91:
#line 173 "parser.y" /* yacc.c:1652  */
    {yyval->c1 = yyvsp[-5];
                                        yyval->c2 = yyvsp[-3];
                                        yyval->b = yyvsp[-1];}
#line 1865 "parser.c" /* yacc.c:1652  */
    break;

  case 92:
#line 177 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_INTEGER);}
#line 1871 "parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 178 "parser.y" /* yacc.c:1652  */
    {yyval = keynode(T_REAL);}
#line 1877 "parser.c" /* yacc.c:1652  */
    break;


#line 1881 "parser.c" /* yacc.c:1652  */
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
#line 180 "parser.y" /* yacc.c:1918  */

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
  p->c1 = p->c2 = p->b = NULL;
  return(p);
}
int main()
{
    int result;

    yyin = stdin;
    if((result = yyparse()) == 0)
        treeprint(root, 0);
    return(result);
}

void yyerror()
{
  fprintf(stderr, "Line %d: syntax error on symbol \"%s\"\n",
          line, yytext);
  exit(-1);
}
