/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "src/asin.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"

#line 74 "asin.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "asin.h".  */
#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    STRUCT_ = 258,
    INT_ = 259,
    BOOL_ = 260,
    READ_ = 261,
    PRINT_ = 262,
    WHILE_ = 263,
    FOR_ = 264,
    IF_ = 265,
    ELSE_ = 266,
    SEP_ = 267,
    SEMICOL_ = 268,
    MAS_ = 269,
    MENOS_ = 270,
    NOT_ = 271,
    POR_ = 272,
    DIV_ = 273,
    MOD_ = 274,
    MASMAS_ = 275,
    MENOSMENOS_ = 276,
    APAR_ = 277,
    CPAR_ = 278,
    ACOR_ = 279,
    CCOR_ = 280,
    ALLAV_ = 281,
    CLLAV_ = 282,
    AND_ = 283,
    OR_ = 284,
    ASIG_ = 285,
    MASASIG_ = 286,
    MENOSASIG_ = 287,
    PORASIG_ = 288,
    DIVASIG_ = 289,
    ASIGASIG_ = 290,
    NOTASIG_ = 291,
    MAYOR_ = 292,
    MENOR_ = 293,
    MAYORASIG_ = 294,
    MENORASIG_ = 295,
    ID_ = 296,
    CTE_ = 297,
    TRUE_ = 298,
    FALSE_ = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "src/asin.y" /* yacc.c:355  */

    char *id;
    int cte;
    int tipo;
    LCSTRUCT lcstr;
    CTESTRUCT ctestr;
    JMPSTRUCT jmpstr;

#line 168 "asin.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "asin.c" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    43,    45,    46,    48,    49,    51,    62,
      77,    92,   104,   108,   113,   119,   133,   134,   135,   136,
     137,   138,   140,   141,   143,   156,   170,   191,   169,   202,
     206,   201,   225,   226,   228,   233,   258,   309,   346,   351,
     377,   382,   404,   409,   438,   443,   462,   467,   486,   491,
     510,   529,   534,   552,   588,   600,   623,   630,   635,   640,
     646,   655,   659,   663,   667,   672,   677,   683,   687,   692,
     696,   700,   704,   709,   713,   718,   722,   726,   731,   736,
     741,   748,   752
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRUCT_", "INT_", "BOOL_", "READ_",
  "PRINT_", "WHILE_", "FOR_", "IF_", "ELSE_", "SEP_", "SEMICOL_", "MAS_",
  "MENOS_", "NOT_", "POR_", "DIV_", "MOD_", "MASMAS_", "MENOSMENOS_",
  "APAR_", "CPAR_", "ACOR_", "CCOR_", "ALLAV_", "CLLAV_", "AND_", "OR_",
  "ASIG_", "MASASIG_", "MENOSASIG_", "PORASIG_", "DIVASIG_", "ASIGASIG_",
  "NOTASIG_", "MAYOR_", "MENOR_", "MAYORASIG_", "MENORASIG_", "ID_",
  "CTE_", "TRUE_", "FALSE_", "$accept", "programa", "$@1",
  "secuenciaSentencias", "sentencia", "declaracion", "tipoSimple",
  "listaCampos", "instruccion", "listaInstrucciones",
  "instruccionEntradaSalida", "instruccionSeleccion", "@2", "$@3",
  "instruccionIteracion", "@4", "$@5", "instruccionExpresion", "expresion",
  "expresionLogica", "expresionIgualdad", "expresionRelacional",
  "expresionAditiva", "expresionMultiplicativa", "expresionUnaria",
  "expresionSufija", "constante", "operadorAsignacion", "operadorLogico",
  "operadorIgualdad", "operadorRelacional", "operadorAditivo",
  "operadorMultiplicativo", "operadorUnario", "operadorIncremento", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -88

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,   -88,    14,   163,   -88,    -1,   -88,   -88,    -6,     5,
     -88,    20,   -88,   -88,   -88,   -88,   -88,   -88,    -3,    42,
     256,   -88,   -88,   -88,   121,   -88,   -88,     3,   -88,   -88,
     -88,   -88,   -88,    48,   -21,    18,    33,    45,    17,   -88,
     -88,   -88,   250,    10,    73,    24,    -3,    65,    -3,    23,
     -88,   -88,   202,    47,    -3,   -88,   -88,   -88,   -88,   -88,
      -3,   -88,   -88,   -88,     2,   -88,   -88,   -88,   250,   -88,
     -88,   250,   -88,   -88,   -88,   -88,   250,   -88,   -88,   250,
     -88,   -88,   -88,   250,    55,   -88,   -88,    49,     1,    66,
      69,    -3,    70,   -88,   -88,   -88,   -10,    71,   -88,   -88,
      52,    38,    18,    33,    45,    17,   -88,    54,    -3,    84,
      57,    59,    88,    89,    80,   -88,    -3,   -10,    79,    92,
     -88,    81,   -88,    94,    95,   -88,   -88,   -88,   241,   -88,
      -3,    97,   -88,   -88,   -88,   -88,   241,   -88,   -88,   -88,
     -88,   100,   241,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,    12,    13,     0,     0,
      29,     0,    33,    78,    79,    80,    81,    82,     0,     0,
      54,    57,    58,    59,     0,     4,     6,     0,     7,    18,
      19,    20,    21,     0,    34,    38,    40,    42,    44,    46,
      48,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    22,     0,     0,     0,    60,    61,    62,    63,    64,
       0,    52,     3,     5,     0,    32,    65,    66,     0,    67,
      68,     0,    69,    70,    71,    72,     0,    73,    74,     0,
      75,    76,    77,     0,    54,    49,    50,     0,     0,     0,
       0,     0,     0,    51,    17,    23,    55,     0,    35,     8,
       0,     0,    39,    41,    43,    45,    47,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    53,     0,     0,
      55,     0,    14,     0,     0,    24,    25,    30,     0,    37,
       0,     0,     9,    53,    11,    15,     0,    27,    36,    10,
      31,     0,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,   -88,    90,   -88,   -41,   -88,   -19,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -17,   -88,
      44,    50,    39,    37,   -38,   -88,    19,   -87,   -88,   -88,
     -88,   -88,   -88,   -88,   -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    24,    25,    26,    27,    88,    28,    52,
      29,    30,   128,   141,    31,    47,   136,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    60,    68,    71,
      76,    79,    83,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    49,    61,    87,    85,     6,     7,    66,    67,   116,
       1,    13,    14,    15,     4,    99,    45,    16,    17,    18,
      55,    56,    57,    58,    59,    44,   100,    46,   110,    90,
     130,    92,   101,    95,    80,    81,    82,    97,    20,    21,
      22,    23,    48,    98,    64,   106,    93,   111,     8,     9,
      10,    86,    11,    69,    70,    12,    13,    14,    15,    77,
      78,    65,    16,    17,    18,    89,    61,   107,    19,    50,
      72,    73,    74,    75,   114,    16,    17,     6,     7,   108,
      21,    22,    23,    20,    21,    22,    23,    91,    96,   112,
     109,   121,   113,   115,   118,   120,   117,   122,   123,   129,
     124,   125,   126,   127,   131,   132,   133,   134,   135,   137,
     139,   142,   102,   138,    63,   104,   105,   140,     0,     0,
     119,   103,     0,   143,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,    12,    13,    14,    15,     0,     0,
       0,    16,    17,    18,     0,     0,     0,    19,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,    22,    23,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,    12,    13,    14,    15,
       0,     0,     0,    16,    17,    18,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,    22,    23,     8,     9,
      10,     0,    11,     0,     0,    12,    13,    14,    15,     0,
       0,     0,    16,    17,    18,     0,     0,     0,    19,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,    22,    23,     8,     9,    10,
       0,    11,     0,     0,    12,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    13,    14,    15,    19,    53,     0,
      16,    17,    18,     0,     0,     0,    16,    17,     0,     0,
      54,     0,    20,    21,    22,    23,    55,    56,    57,    58,
      59,    84,    21,    22,    23
};

static const yytype_int16 yycheck[] =
{
      19,    18,    20,    44,    42,     4,     5,    28,    29,    96,
      26,    14,    15,    16,     0,    13,    22,    20,    21,    22,
      30,    31,    32,    33,    34,    26,    24,    22,    27,    46,
     117,    48,    30,    52,    17,    18,    19,    54,    41,    42,
      43,    44,    22,    60,    41,    83,    23,    88,     6,     7,
       8,    41,    10,    35,    36,    13,    14,    15,    16,    14,
      15,    13,    20,    21,    22,    41,    84,    12,    26,    27,
      37,    38,    39,    40,    91,    20,    21,     4,     5,    24,
      42,    43,    44,    41,    42,    43,    44,    22,    41,    23,
      41,   108,    23,    23,    42,    41,    25,    13,    41,   116,
      41,    13,    13,    23,    25,    13,    25,    13,    13,   128,
      13,    11,    68,   130,    24,    76,    79,   136,    -1,    -1,
     101,    71,    -1,   142,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,     6,     7,
       8,    -1,    10,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,     6,     7,     8,
      -1,    10,    -1,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    20,    21,    22,    14,    15,    16,    26,    12,    -1,
      20,    21,    22,    -1,    -1,    -1,    20,    21,    -1,    -1,
      24,    -1,    41,    42,    43,    44,    30,    31,    32,    33,
      34,    41,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    46,    47,     0,     3,     4,     5,     6,     7,
       8,    10,    13,    14,    15,    16,    20,    21,    22,    26,
      41,    42,    43,    44,    48,    49,    50,    51,    53,    55,
      56,    59,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    78,    79,    26,    22,    22,    60,    22,    63,
      27,    53,    54,    12,    24,    30,    31,    32,    33,    34,
      72,    79,    27,    49,    41,    13,    28,    29,    73,    35,
      36,    74,    37,    38,    39,    40,    75,    14,    15,    76,
      17,    18,    19,    77,    41,    69,    41,    51,    52,    41,
      63,    22,    63,    23,    27,    53,    41,    63,    63,    13,
      24,    30,    65,    66,    67,    68,    69,    12,    24,    41,
      27,    51,    23,    23,    63,    23,    72,    25,    42,    71,
      41,    63,    13,    41,    41,    13,    13,    23,    57,    63,
      72,    25,    13,    25,    13,    13,    61,    53,    63,    13,
      53,    58,    11,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    57,    58,    56,    60,
      61,    59,    62,    62,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     1,     2,     1,     1,     3,     5,
       6,     6,     1,     1,     3,     4,     2,     3,     1,     1,
       1,     1,     1,     2,     5,     5,     0,     0,     9,     0,
       0,     7,     2,     1,     1,     3,     6,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     3,     2,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yyreduce -- Do a reduction.  |
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
#line 43 "src/asin.y" /* yacc.c:1646  */
    { dvar = 0; si = 0; }
#line 1402 "asin.c" /* yacc.c:1646  */
    break;

  case 3:
#line 43 "src/asin.y" /* yacc.c:1646  */
    { if (verTDS) { verTdS(); } }
#line 1408 "asin.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "src/asin.y" /* yacc.c:1646  */
    {
                                SIMB sim = obtTdS((yyvsp[-1].id));
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la variable: variable ya declarada.");
                                }
                                else {
                                    insTdS((yyvsp[-1].id), (yyvsp[-2].tipo), dvar, -1);
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
                            }
#line 1423 "asin.c" /* yacc.c:1646  */
    break;

  case 9:
#line 63 "src/asin.y" /* yacc.c:1646  */
    {
                                SIMB sim = obtTdS((yyvsp[-3].id));
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la variable: variable ya declarada.");
                                }
                                else if ((yyvsp[-4].tipo) != (yyvsp[-1].ctestr).tipo) {
                                    yyerror("Error en la declaracion de la variable: error de incompatibilidad de tipos.");
                                }
                                else {
                                    insTdS((yyvsp[-3].id), (yyvsp[-4].tipo), dvar, -1);
                                    emite(EASIG, crArgEnt((yyvsp[-1].ctestr).pos), crArgNul(), crArgPos(dvar));
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
                            }
#line 1442 "asin.c" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "src/asin.y" /* yacc.c:1646  */
    {
                                SIMB sim = obtTdS((yyvsp[-4].id));
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion del vector: vector ya declarado.");
                                }
                                else if ((yyvsp[-2].cte) <= 0) {
                                    yyerror("Error en la declaracion del vector: talla inapropiada.");
                                }
                                else {
                                    int arrayRef = insTdA((yyvsp[-5].tipo), (yyvsp[-2].cte));
                                    insTdS((yyvsp[-4].id), T_ARRAY, dvar, arrayRef);
                                    dvar += TALLA_TIPO_SIMPLE * (yyvsp[-2].cte);
                                }
                            }
#line 1461 "asin.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "src/asin.y" /* yacc.c:1646  */
    {
                                SIMB sim = obtTdS((yyvsp[-1].id));
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la estructura: estructura ya declarada.");
                                }
                                else {
                                    insTdS((yyvsp[-1].id), T_RECORD, dvar, (yyvsp[-3].lcstr).regRef);
                                    dvar += (yyvsp[-3].lcstr).talla;
                                }
                            }
#line 1476 "asin.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = T_ENTERO;
                            }
#line 1484 "asin.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = T_LOGICO;
                            }
#line 1492 "asin.c" /* yacc.c:1646  */
    break;

  case 14:
#line 114 "src/asin.y" /* yacc.c:1646  */
    {
                                int regRef = insTdR(-1, (yyvsp[-1].id), (yyvsp[-2].tipo), 0);
                                (yyval.lcstr).talla = TALLA_TIPO_SIMPLE;
                                (yyval.lcstr).regRef = regRef;
                            }
#line 1502 "asin.c" /* yacc.c:1646  */
    break;

  case 15:
#line 120 "src/asin.y" /* yacc.c:1646  */
    {
                                CAMP sim = obtTdR((yyvsp[-3].lcstr).regRef, (yyvsp[-1].id));
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la estructura: campo duplicado");
                                }
                                /* No se tiene que comprobar si ya existe en la tabla
                                de simbolos, porque es un campo del registro y no una
                                variable del programa */
                                insTdR((yyvsp[-3].lcstr).regRef, (yyvsp[-1].id), (yyvsp[-2].tipo), (yyvsp[-3].lcstr).talla);
                                (yyval.lcstr).talla += TALLA_TIPO_SIMPLE;
                                (yyval.lcstr).regRef = (yyvsp[-3].lcstr).regRef;
                            }
#line 1519 "asin.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "src/asin.y" /* yacc.c:1646  */
    {
                                SIMB sim = obtTdS((yyvsp[-2].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la instruccion de lectura: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la instruccion de lectura: la variable no es de tipo entero.");
                                }
                                else {
                                    emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.desp));
                                }
                            }
#line 1536 "asin.c" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "src/asin.y" /* yacc.c:1646  */
    {
                                if ((yyvsp[-2].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-2].ctestr).tipo != T_ENTERO) {
                                    yyerror("Error en la instruccion de escritura: la variable no es de tipo entero.");
                                }
                                else {
                                    emite(EWRITE, crArgNul(), crArgNul(), crArgPos((yyvsp[-2].ctestr).pos));
                                }
                            }
#line 1552 "asin.c" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "src/asin.y" /* yacc.c:1646  */
    {
                                // TODO: meter código a mitad de regla xd
                                // Si hay $$ a mitad de regla no va a la parte izquierda de la regla!!
                                // Cómo ir a la parte izquierda?
                                // Solución: bison crea un no-terminal @1, @2, ..., por lo que OJO! Los $<número> se modifican
                                // Hay que especificar el tipo de $$ en cada secuencia a mitad de regla tal que así:
                                // $< <tipo-variable> >$.[...]
                                // Y después podemos usar este bloque de código tal que así. Imaginando que nos referimos al primer bloque (nuevo no-terminal 2):
                                // $< <tipo-variable> >2.[...]
                                if ((yyvsp[-1].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-1].ctestr).tipo != T_LOGICO) {
                                    yyerror("Error en la expresion condicional: expresion no valida en la guarda.");
                                }
                                else{
                                    (yyval.jmpstr).jmpf = creaLans(si);
                                    emite(EIGUAL, crArgPos((yyvsp[-1].ctestr).pos), crArgEnt(FALSE), crArgEnt(-1));
                                }
                            }
#line 1577 "asin.c" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "src/asin.y" /* yacc.c:1646  */
    {
                               (yyvsp[-1].jmpstr).fin = creaLans(si);
                               emite(GOTOS, crArgNul(), crArgNul(), crArgEnt(-1)); 
                               completaLans((yyvsp[-1].jmpstr).jmpf, crArgEtq(si));
                            }
#line 1587 "asin.c" /* yacc.c:1646  */
    break;

  case 28:
#line 197 "src/asin.y" /* yacc.c:1646  */
    {
                                completaLans((yyvsp[-4].jmpstr).fin, crArgEtq(si));
                            }
#line 1595 "asin.c" /* yacc.c:1646  */
    break;

  case 29:
#line 202 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.jmpstr).ini = si;
                            }
#line 1603 "asin.c" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "src/asin.y" /* yacc.c:1646  */
    {
                                // TODO: meter código a mitad de regla xd
                                if ((yyvsp[-1].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-1].ctestr).tipo != T_LOGICO) {
                                    yyerror("Error en la expresion de bucle: expresion no valida en la guarda.");
                                }
                                else{
                                    (yyvsp[-3].jmpstr).jmpf = creaLans(si);
                                    emite(EIGUAL, crArgPos((yyvsp[-1].ctestr).pos), crArgEnt(FALSE), crArgEnt(-1));
                                }
                            }
#line 1621 "asin.c" /* yacc.c:1646  */
    break;

  case 31:
#line 220 "src/asin.y" /* yacc.c:1646  */
    {
                                emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-5].jmpstr).ini));
                                completaLans((yyvsp[-5].jmpstr).jmpf, crArgEtq(si));
                            }
#line 1630 "asin.c" /* yacc.c:1646  */
    break;

  case 34:
#line 229 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1639 "asin.c" /* yacc.c:1646  */
    break;

  case 35:
#line 234 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[-2].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la asignacion: variable no declarada.");
                                }
                                else if ((yyvsp[0].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if (sim.tipo != (yyvsp[0].ctestr).tipo) {
                                    yyerror("Error en la asignacion: error de incompatibilidad de tipos.");
                                }
                                else {
                                    (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    if((yyvsp[-1].tipo) != EASIG){
                                        emite((yyvsp[-1].tipo), crArgPos(sim.desp), crArgPos((yyvsp[0].ctestr).pos),  crArgPos(sim.desp));
                                    }
                                    else {
                                        emite(EASIG, crArgPos((yyvsp[0].ctestr).pos), crArgNul(), crArgPos(sim.desp));
                                    }
                                    emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos((yyval.ctestr).pos));
                                }
                            }
#line 1668 "asin.c" /* yacc.c:1646  */
    break;

  case 36:
#line 259 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[-5].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la asignacion: vector no declarado.");
                                }
                                else if (sim.tipo != T_ARRAY) {
                                    yyerror("Error en la asignacion: la variable no ha sido declarada como un vector.");
                                }
                                else {
                                    DIM arr = obtTdA(sim.ref);
                                    if (arr.telem == T_ERROR) {
                                        yyerror("Error en la asignacion: la variable no es un vector valido.");
                                    }
                                    else if ((yyvsp[-3].ctestr).tipo != T_ENTERO) {
                                        yyerror("Error en la asignacion: el indice del vector no es de tipo entero.");
                                    }
                                    else if ((yyvsp[0].ctestr).tipo == T_ERROR) {
                                        // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                    }
                                    else if (arr.telem != (yyvsp[0].ctestr).tipo) {
                                        yyerror("Error en la asignacion: error de incompatibilidad de tipos.");
                                    }
                                    else {
                                        (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                        // Nota: no multiplicamos la expresión por TALLA_TIPO_SIMPLE porque es 1
                                        // Si expresion < 0 entonces peto
                                        emite(EMEN, crArgPos((yyvsp[-3].ctestr).pos), crArgEnt(0), crArgEtq(si + 2));

                                        // No he petado aún; si expresion < arr.nelem entonces sigo
                                        emite(EMEN, crArgPos((yyvsp[-3].ctestr).pos), crArgEnt(arr.nelem), crArgEtq(si + 2));
                                        
                                        // He petado. Acabo el programa.
                                        emite(FIN, crArgNul(), crArgNul(), crArgNul());
                                        
                                        // No he petado en esta instrucción. Prosigo normalmente.
                                        int aux = creaVarTemp();
                                        (yyval.ctestr).pos = creaVarTemp();
                                        if((yyvsp[-1].tipo) != EASIG){
                                            emite((yyvsp[-1].tipo), crArgPos(sim.desp), crArgPos((yyvsp[-3].ctestr).pos),  crArgPos(aux));
                                            emite(EVA, crArgPos(sim.desp), crArgPos((yyvsp[-3].ctestr).pos), crArgPos(aux));
                                            emite(EASIG, crArgPos(aux), crArgNul(), crArgPos((yyval.ctestr).pos));
                                        }
                                        else {
                                            emite(EVA, crArgPos(sim.desp), crArgPos((yyvsp[-3].ctestr).pos), crArgPos((yyvsp[0].ctestr).pos));
                                            emite(EASIG, crArgPos((yyvsp[0].ctestr).pos), crArgNul(), crArgPos((yyval.ctestr).pos));
                                        }    
                                    }
                                }
                            }
#line 1723 "asin.c" /* yacc.c:1646  */
    break;

  case 37:
#line 310 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[-4].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la asignacion: estructura no declarada.");
                                }
                                else if (sim.tipo != T_RECORD) {
                                    yyerror("Error en la asignacion: la variable no es de tipo 'struct'.");
                                }
                                else {
                                    CAMP camp = obtTdR(sim.ref, (yyvsp[-2].id));
                                    if (camp.tipo == T_ERROR) {
                                        yyerror("Error en la asignacion: el campo referenciado no es un campo de la estructura.");
                                    }
                                    else if ((yyvsp[0].ctestr).tipo == T_ERROR) {
                                        // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                    }
                                    else if (camp.tipo != (yyvsp[0].ctestr).tipo) {
                                        yyerror("Error en la asignacion: error de incompatibilidad de tipos.");
                                    }
                                    else {
                                        (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                        (yyval.ctestr).pos = creaVarTemp();
                                        int absDesp = sim.desp + camp.desp;

                                        if((yyvsp[-1].tipo) != EASIG){
                                            emite((yyvsp[-1].tipo), crArgPos(absDesp), crArgPos((yyvsp[0].ctestr).pos),  crArgPos(absDesp));
                                        }
                                        else {
                                            emite(EASIG, crArgPos((yyvsp[0].ctestr).pos), crArgNul(), crArgPos(absDesp));
                                        }
                                        emite(EASIG, crArgPos(absDesp), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    }
                                }
                            }
#line 1763 "asin.c" /* yacc.c:1646  */
    break;

  case 38:
#line 347 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1772 "asin.c" /* yacc.c:1646  */
    break;

  case 39:
#line 352 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                if ((yyvsp[-2].ctestr).tipo == T_ERROR || (yyvsp[0].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-2].ctestr).tipo != T_LOGICO) {
                                    yyerror("Error en la expresion logica: el primer operando no es de tipo logico.");
                                }
                                else if ((yyvsp[0].ctestr).tipo != T_LOGICO) {
                                   yyerror("Error en la expresion logica: el segundo operando no es de tipo logico."); 
                                }
                                else {
                                    (yyval.ctestr).tipo = T_LOGICO;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    emite((yyvsp[-1].tipo), crArgPos((yyvsp[-2].ctestr).pos), crArgPos((yyvsp[0].ctestr).pos), crArgPos((yyval.ctestr).pos));
                                    if ((yyvsp[-1].tipo) == ESUM) {
                                        // OR
                                        // Si eran los dos TRUE, la suma es 2
                                        // Hay que comprobar si esto pasa para asignar TRUE
                                        emite(EMEN, crArgPos((yyval.ctestr).pos), crArgEnt(2), crArgEtq(si + 2));
                                        emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    }
                                }
                            }
#line 1801 "asin.c" /* yacc.c:1646  */
    break;

  case 40:
#line 378 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1810 "asin.c" /* yacc.c:1646  */
    break;

  case 41:
#line 383 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                if ((yyvsp[-2].ctestr).tipo == T_ERROR || (yyvsp[0].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-2].ctestr).tipo != (yyvsp[0].ctestr).tipo) {
                                    yyerror("Error en la expresion de igualdad: error de incompatibilidad de tipos.");
                                }
                                else {
                                    (yyval.ctestr).tipo = T_LOGICO;
                                    (yyval.ctestr).pos = creaVarTemp();

                                    // Ver expresionRelacional
                                    emite((yyvsp[-1].tipo), crArgPos((yyvsp[-2].ctestr).pos), crArgPos((yyvsp[0].ctestr).pos), crArgEtq(si + 3));
                                    emite(EASIG, crArgEnt(FALSE), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(si + 2));
                                    emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos((yyval.ctestr).pos));

                                }
                            }
#line 1835 "asin.c" /* yacc.c:1646  */
    break;

  case 42:
#line 405 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1844 "asin.c" /* yacc.c:1646  */
    break;

  case 43:
#line 410 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                if ((yyvsp[-2].ctestr).tipo == T_ERROR || (yyvsp[0].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-2].ctestr).tipo != T_ENTERO) {
                                    yyerror("Error en la expresion relacional: el primer operando no es de tipo entero.");
                                }
                                else if ((yyvsp[0].ctestr).tipo != T_ENTERO) {
                                   yyerror("Error en la expresion relacional: el segundo operando no es de tipo entero."); 
                                }
                                else {
                                    (yyval.ctestr).tipo = T_LOGICO;
                                    // Si se cumple exprRel opRel exprAd, entonces ponemos 1. Si no, ponemos 0
                                    (yyval.ctestr).pos = creaVarTemp();

                                    // Paso 0: si se cumple exprRel opRel exprAd, entonces saltamos a Paso 3.
                                    emite((yyvsp[-1].tipo), crArgPos((yyvsp[-2].ctestr).pos), crArgPos((yyvsp[0].ctestr).pos), crArgEtq(si + 3));
                                    // Paso 1: lo de arriba era falso. Ponemos falso.
                                    emite(EASIG, crArgEnt(FALSE), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    // Paso 2: Saltamos al Paso 4
                                    emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(si + 2));
                                    // Paso 3: lo de arriba era verdadero. Ponemos verdadero.
                                    emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    // Paso 4: se continúa la ejecución
                                }
                            }
#line 1876 "asin.c" /* yacc.c:1646  */
    break;

  case 44:
#line 439 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1885 "asin.c" /* yacc.c:1646  */
    break;

  case 45:
#line 444 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                if ((yyvsp[-2].ctestr).tipo == T_ERROR || (yyvsp[0].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-2].ctestr).tipo != T_ENTERO) {
                                    yyerror("Error en la expresion aditiva: el primer operando no es de tipo entero.");
                                }
                                else if ((yyvsp[0].ctestr).tipo != T_ENTERO) {
                                   yyerror("Error en la expresion aditiva: el segundo operando no es de tipo entero."); 
                                }
                                else {
                                    (yyval.ctestr).tipo = T_ENTERO;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    emite((yyvsp[-1].tipo), crArgPos((yyvsp[-2].ctestr).pos), crArgPos((yyvsp[0].ctestr).pos), crArgPos((yyval.ctestr).pos));
                                }
                            }
#line 1907 "asin.c" /* yacc.c:1646  */
    break;

  case 46:
#line 463 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1916 "asin.c" /* yacc.c:1646  */
    break;

  case 47:
#line 468 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                if ((yyvsp[-2].ctestr).tipo == T_ERROR || (yyvsp[0].ctestr).tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ((yyvsp[-2].ctestr).tipo != T_ENTERO) {
                                    yyerror("Error en la expresion multiplicativa: el primer operando no es de tipo entero.");
                                }
                                else if ((yyvsp[0].ctestr).tipo != T_ENTERO) {
                                   yyerror("Error en la expresion multiplicativa: el segundo operando no es de tipo entero."); 
                                }
                                else {
                                    (yyval.ctestr).tipo = T_ENTERO;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    emite((yyvsp[-1].tipo), crArgPos((yyvsp[-2].ctestr).pos), crArgPos((yyvsp[0].ctestr).pos), crArgPos((yyval.ctestr).pos));
                                }
                            }
#line 1938 "asin.c" /* yacc.c:1646  */
    break;

  case 48:
#line 487 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[0].ctestr).pos;
                            }
#line 1947 "asin.c" /* yacc.c:1646  */
    break;

  case 49:
#line 492 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                if ((yyvsp[-1].ctestr).tipo != (yyvsp[0].ctestr).tipo) {
                                    yyerror("Error en la expresion unaria: error de incompatibilidad de tipos.");
                                }
                                else {
                                    (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    if ((yyvsp[-1].ctestr).tipo == T_ENTERO) {
                                        emite((yyvsp[-1].ctestr).pos, crArgEnt(0), crArgPos((yyvsp[0].ctestr).pos), crArgPos((yyval.ctestr).pos));
                                    }
                                    else {
                                        // T_LOGICO
                                        // resultado = 1 - valor
                                        emite((yyvsp[-1].ctestr).pos, crArgEnt(1), crArgPos((yyvsp[0].ctestr).pos), crArgPos((yyval.ctestr).pos));
                                    }
                                }
                            }
#line 1970 "asin.c" /* yacc.c:1646  */
    break;

  case 50:
#line 511 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[0].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion unaria: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion unaria: operacion invalida para este tipo.");
                                }
                                else {
                                    (yyval.ctestr).tipo = T_ENTERO;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    emite((yyvsp[-1].tipo), crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
                                    // También asignar al padre el valor del hijo
                                    emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos((yyval.ctestr).pos));
                                }
                            }
#line 1992 "asin.c" /* yacc.c:1646  */
    break;

  case 51:
#line 530 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[-1].ctestr).tipo;
                                (yyval.ctestr).pos = (yyvsp[-1].ctestr).pos;
                            }
#line 2001 "asin.c" /* yacc.c:1646  */
    break;

  case 52:
#line 535 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[-1].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion sufija: operacion invalida para este tipo.");
                                }
                                else {
                                    (yyval.ctestr).tipo = T_ENTERO;
                                    (yyval.ctestr).pos = creaVarTemp();
                                    // También asignar al padre el valor del hijo
                                    emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    emite((yyvsp[0].tipo), crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
                                }
                            }
#line 2023 "asin.c" /* yacc.c:1646  */
    break;

  case 53:
#line 553 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[-3].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: vector no declarado.");
                                }
                                else if (sim.tipo != T_ARRAY) {
                                    yyerror("Error en la expresion sufija: la variable no es un vector.");
                                }
                                else {
                                    DIM arr = obtTdA(sim.ref);
                                    if (arr.telem == T_ERROR) {
                                        yyerror("Error en la expresion sufija: el vector referenciado no es un vector valido.");
                                    }
                                    else if ((yyvsp[-1].ctestr).tipo != T_ENTERO) {
                                        yyerror("Error en la expresion sufija: el indice del vector no es de tipo entero.");
                                    }
                                    else {
                                        (yyval.ctestr).tipo = arr.telem;
                                        // Se comprueba en tiempo de ejecución, por lo que LO COMPROBAMOS LUEGO XD
                                        int aux = creaVarTemp();
                                        // Nota: no multiplicamos la expresión por TALLA_TIPO_SIMPLE porque es 1
                                        // Si expresion < 0 entonces peto
                                        emite(EMEN, crArgPos((yyvsp[-1].ctestr).pos), crArgEnt(0), crArgEtq(si + 2));
                                        // No he petado aún; si expresion < arr.nelem entonces sigo
                                        emite(EMEN, crArgPos((yyvsp[-1].ctestr).pos), crArgEnt(arr.nelem), crArgEtq(si + 2));
                                        // He petado. Acabo el programa.
                                        emite(FIN, crArgNul(), crArgNul(), crArgNul());
                                        // No he petado en esta instrucción. Prosigo normalmente.
                                        emite(ESUM, crArgPos(sim.desp), crArgPos((yyvsp[-1].ctestr).pos), crArgPos(aux));
                                        (yyval.ctestr).pos = creaVarTemp();
                                        emite(EASIG, crArgPos(aux), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    }
                                }
                            }
#line 2063 "asin.c" /* yacc.c:1646  */
    break;

  case 54:
#line 589 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[0].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: variable no declarada.");
                                }
                                else {
                                    (yyval.ctestr).tipo = sim.tipo;
                                    (yyval.ctestr).pos = sim.desp;
                                }
                            }
#line 2079 "asin.c" /* yacc.c:1646  */
    break;

  case 55:
#line 601 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ERROR;
                                SIMB sim = obtTdS((yyvsp[-2].id));
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: estructura no declarada.");
                                }
                                else if (sim.tipo != T_RECORD) {
                                    yyerror("Error en la expresion sufija: la variable no es de tipo 'struct'.");
                                }
                                else {
                                    CAMP camp = obtTdR(sim.ref, (yyvsp[0].id));
                                    if (camp.tipo == T_ERROR) {
                                        yyerror("Error en la expresion sufija: el campo referenciado no es un campo de la estructura.");
                                    }
                                    else {
                                        (yyval.ctestr).tipo = camp.tipo;
                                        int absDesp = sim.desp + camp.desp;
                                        (yyval.ctestr).pos = creaVarTemp();
                                        emite(EASIG, crArgPos(absDesp), crArgNul(), crArgPos((yyval.ctestr).pos));
                                    }
                                }
                            }
#line 2106 "asin.c" /* yacc.c:1646  */
    break;

  case 56:
#line 624 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = (yyvsp[0].ctestr).tipo;
                                (yyval.ctestr).pos = creaVarTemp();
                                emite(EASIG, crArgEnt((yyvsp[0].ctestr).pos), crArgNul(), crArgPos((yyval.ctestr).pos));
                            }
#line 2116 "asin.c" /* yacc.c:1646  */
    break;

  case 57:
#line 631 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ENTERO;
                                (yyval.ctestr).pos = (yyvsp[0].cte);
                            }
#line 2125 "asin.c" /* yacc.c:1646  */
    break;

  case 58:
#line 636 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_LOGICO;
                                (yyval.ctestr).pos = TRUE;
                            }
#line 2134 "asin.c" /* yacc.c:1646  */
    break;

  case 59:
#line 641 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_LOGICO;
                                (yyval.ctestr).pos = FALSE;
                            }
#line 2143 "asin.c" /* yacc.c:1646  */
    break;

  case 60:
#line 647 "src/asin.y" /* yacc.c:1646  */
    {
                                // Comprobaremos que no sea EASIG
                                // si no lo es, hacemos la operacion correspondiente
                                // fuera de ese if, para todos los casos, hacemos asignacion
                                // De esta forma, conseguimos que asig solo se haga una vez para asig
                                // y que para los demas se haga la operacion y luego se asigne 
                                (yyval.tipo) = EASIG;
                            }
#line 2156 "asin.c" /* yacc.c:1646  */
    break;

  case 61:
#line 656 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = ESUM;
                            }
#line 2164 "asin.c" /* yacc.c:1646  */
    break;

  case 62:
#line 660 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EDIF;
                            }
#line 2172 "asin.c" /* yacc.c:1646  */
    break;

  case 63:
#line 664 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EMULT;
                            }
#line 2180 "asin.c" /* yacc.c:1646  */
    break;

  case 64:
#line 668 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EDIVI;
                            }
#line 2188 "asin.c" /* yacc.c:1646  */
    break;

  case 65:
#line 673 "src/asin.y" /* yacc.c:1646  */
    {
                                // Multiplicamos, si da 1 true, si da 0 false
                                (yyval.tipo) = EMULT;
                            }
#line 2197 "asin.c" /* yacc.c:1646  */
    break;

  case 66:
#line 678 "src/asin.y" /* yacc.c:1646  */
    {
                                // Sumamos, si da >=1 true, si da <1 false
                                (yyval.tipo) = ESUM;
                            }
#line 2206 "asin.c" /* yacc.c:1646  */
    break;

  case 67:
#line 684 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EIGUAL;
                            }
#line 2214 "asin.c" /* yacc.c:1646  */
    break;

  case 68:
#line 688 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EDIST;
                            }
#line 2222 "asin.c" /* yacc.c:1646  */
    break;

  case 69:
#line 693 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EMAY;
                            }
#line 2230 "asin.c" /* yacc.c:1646  */
    break;

  case 70:
#line 697 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EMEN;
                            }
#line 2238 "asin.c" /* yacc.c:1646  */
    break;

  case 71:
#line 701 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EMAYEQ;
                            }
#line 2246 "asin.c" /* yacc.c:1646  */
    break;

  case 72:
#line 705 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EMENEQ;
                            }
#line 2254 "asin.c" /* yacc.c:1646  */
    break;

  case 73:
#line 710 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = ESUM;
                            }
#line 2262 "asin.c" /* yacc.c:1646  */
    break;

  case 74:
#line 714 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EDIF;
                            }
#line 2270 "asin.c" /* yacc.c:1646  */
    break;

  case 75:
#line 719 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EMULT;
                            }
#line 2278 "asin.c" /* yacc.c:1646  */
    break;

  case 76:
#line 723 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EDIVI;
                            }
#line 2286 "asin.c" /* yacc.c:1646  */
    break;

  case 77:
#line 727 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = RESTO;
                            }
#line 2294 "asin.c" /* yacc.c:1646  */
    break;

  case 78:
#line 732 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ENTERO;
                                (yyval.ctestr).pos = ESUM;
                            }
#line 2303 "asin.c" /* yacc.c:1646  */
    break;

  case 79:
#line 737 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.ctestr).tipo = T_ENTERO;
                                (yyval.ctestr).pos = EDIF;
                            }
#line 2312 "asin.c" /* yacc.c:1646  */
    break;

  case 80:
#line 742 "src/asin.y" /* yacc.c:1646  */
    {
                                // Restamos (1 - valor) ver arriba
                                (yyval.ctestr).tipo = T_LOGICO;
                                (yyval.ctestr).pos = EDIF;
                            }
#line 2322 "asin.c" /* yacc.c:1646  */
    break;

  case 81:
#line 749 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = ESUM;
                            }
#line 2330 "asin.c" /* yacc.c:1646  */
    break;

  case 82:
#line 753 "src/asin.y" /* yacc.c:1646  */
    {
                                (yyval.tipo) = EDIF;
                            }
#line 2338 "asin.c" /* yacc.c:1646  */
    break;


#line 2342 "asin.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 757 "src/asin.y" /* yacc.c:1906  */

/*****************************************************************************/
