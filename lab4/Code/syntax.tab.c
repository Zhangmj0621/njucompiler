/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "./syntax.y"

    
    #include "tree.h"
    #include "lex.yy.c"
    #include<stdio.h>

#line 77 "./syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    SEMI = 260,
    COMMA = 261,
    TYPE = 262,
    STRUCT = 263,
    ID = 264,
    LC = 265,
    RC = 266,
    LB = 267,
    RB = 268,
    LP = 269,
    RP = 270,
    RETURN = 271,
    IF = 272,
    ELSE = 273,
    WHILE = 274,
    ASSIGNOP = 275,
    AND = 276,
    OR = 277,
    RELOP = 278,
    PLUS = 279,
    MINUS = 280,
    STAR = 281,
    DIV = 282,
    NOT = 283,
    DOT = 284,
    LOWER_THAN_ELSE = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "./syntax.y"

    tNode* type_node;

#line 164 "./syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

#define YYUNDEFTOK  2
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    32,    32,    34,    35,    37,    66,    67,    71,    72,
      73,    75,    76,    79,    80,    82,   101,   120,   121,   124,
     126,   127,   133,   135,   143,   152,   153,   154,   156,   157,
     159,   171,   173,   174,   176,   177,   178,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   195,   196,
     198,   233,   234,   236,   237,   239,   240,   254,   282,   293,
     304,   317,   330,   343,   357,   370,   371,   382,   393,   417,
     436,   473,   505,   539,   549,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   570,   571
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "SEMI", "COMMA", "TYPE",
  "STRUCT", "ID", "LC", "RC", "LB", "RB", "LP", "RP", "RETURN", "IF",
  "ELSE", "WHILE", "ASSIGNOP", "AND", "OR", "RELOP", "PLUS", "MINUS",
  "STAR", "DIV", "NOT", "DOT", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   331,   -65,    -2,    16,   -65,    76,    77,   -65,   -65,
      14,    36,    63,   -65,   -65,   -65,    17,   -65,    71,    83,
       8,    98,   -65,   132,   -65,    94,   118,   -65,    95,    57,
     132,   -65,    78,   107,   132,   -65,    95,   105,   122,   120,
     -65,   129,   -65,   -65,   135,   142,    96,   140,    91,    44,
     151,   -65,   -65,   134,   -65,   132,   -65,   -65,   -65,   -65,
      39,   -65,   -65,   148,    47,   176,   149,   158,   185,   202,
     -65,   145,    96,    42,   -65,   298,   -65,   -65,    95,   -65,
     -65,   298,   167,   159,   355,   160,    69,   211,   298,   -65,
       3,   -65,    -3,   -65,   -65,   168,   -65,   220,   237,   246,
     255,   272,   281,   290,   307,   316,   174,   437,   -65,   371,
     169,   -65,   325,   172,   -65,   -65,   -65,   -65,   -65,   178,
     387,   403,   -65,   183,   421,   -65,   437,   -65,   444,   -65,
     444,   -65,   453,   -65,     3,   -65,     3,   -65,    -3,   -65,
      -3,   -65,   133,   -65,   298,   -65,   113,   150,   133,   -65,
     -65,   -65,   -65,   133,   -65,     7,   173,   -65,   -65,   133,
     133,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,    17,     0,     2,     0,     0,    14,     9,
       0,    19,     0,    16,     1,     4,     0,     6,    20,     0,
      11,     0,    10,    48,     8,     0,     0,     5,     0,     0,
      48,     7,     0,     0,    48,    27,     0,     0,    29,     0,
      24,     0,    20,    12,     0,     0,     0,     0,    55,     0,
      53,    15,    49,    30,    26,     0,    25,    23,    22,    21,
       0,    73,    74,    72,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,    51,     0,    52,    50,     0,    28,
      40,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      66,    86,    67,    31,    33,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    54,     0,
       0,    69,    89,     0,    87,    65,    43,    42,    36,     0,
       0,     0,    41,     0,     0,    75,    57,    76,    58,    77,
      59,    78,    60,    79,    61,    80,    62,    81,    63,    82,
      64,    71,     0,    83,     0,    68,     0,     0,     0,    84,
      70,    47,    88,     0,    44,     0,    37,    39,    46,     0,
       0,    45,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   191,   -65,   170,     2,   -65,   -65,   -65,   -26,
     -65,   -13,   -65,   179,   130,   213,    25,   -65,   131,   -65,
     -64,    64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    19,    32,     8,    12,    13,    20,
      21,    37,    38,    70,    71,    72,    33,    34,    49,    50,
      73,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    86,     7,    10,    90,    92,    48,    11,     7,    97,
      53,   107,    80,    41,    28,    97,    14,   109,   112,    22,
      29,    81,    24,   120,   121,   159,   106,    36,    36,   104,
     105,    25,   106,   124,   126,   128,   130,   132,   134,   136,
     138,   140,    79,    95,    80,    76,   -18,    96,    83,    77,
      61,    62,    48,    81,    97,    46,    63,    36,    44,    52,
      45,    64,    98,    99,   100,   101,   102,   103,   104,   105,
     117,   106,    68,    23,   118,    69,    -3,     1,    16,    47,
     112,    97,    17,     2,     3,    26,    18,    42,    27,    98,
      99,   100,   101,   102,   103,   104,   105,    60,   106,    61,
      62,     2,     3,    29,    42,    63,    30,   -32,    30,    35,
      64,    75,    65,    66,    60,    67,    61,    62,    51,    39,
      54,    68,    63,    30,    69,     2,     3,    64,    55,    65,
      66,   153,    67,    40,    60,    56,    61,    62,    68,     2,
       3,    69,    63,    30,    57,    74,    29,    64,    58,    65,
      66,   155,    67,    61,    62,    59,    93,    78,    68,    63,
      30,    69,    82,    87,    64,   116,    65,    66,   110,    67,
      61,    62,    88,   122,   114,    68,    63,    85,    69,    61,
      62,    64,   111,   141,   143,    63,    89,   145,    61,    62,
      64,   160,    68,   146,    63,    69,   149,    15,    43,    64,
      31,    68,    94,    91,    69,    61,    62,     0,   152,   108,
      68,    63,   119,    69,    61,    62,    64,     0,     0,     0,
      63,   123,     0,    61,    62,    64,     0,    68,     0,    63,
      69,     0,     0,     0,    64,     0,    68,     0,   125,    69,
      61,    62,     0,     0,     0,    68,    63,   127,    69,    61,
      62,    64,     0,     0,     0,    63,   129,     0,    61,    62,
      64,     0,    68,     0,    63,    69,     0,     0,     0,    64,
       0,    68,     0,   131,    69,    61,    62,     0,     0,     0,
      68,    63,   133,    69,    61,    62,    64,     0,     0,     0,
      63,   135,     0,    61,    62,    64,     0,    68,     0,    63,
      69,    61,    62,     0,    64,     0,    68,    63,   137,    69,
      61,    62,    64,     0,     0,    68,    63,   139,    69,    61,
      62,    64,     0,    68,     0,    63,    69,     0,     0,     0,
      64,   144,    68,     0,     0,    69,     9,    97,     2,     3,
       0,    68,     0,     0,    69,    98,    99,   100,   101,   102,
     103,   104,   105,     0,   106,   151,     0,     0,     0,   154,
     156,   157,     0,     0,     0,     0,   158,    97,     0,     0,
     115,     0,   161,   162,     0,    98,    99,   100,   101,   102,
     103,   104,   105,    97,   106,     0,   142,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,    97,
     106,     0,   147,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,    97,   106,     0,   148,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,     0,   106,    97,   150,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,    97,
     106,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    97,   106,   101,   102,   103,
     104,   105,     0,   106,     0,     0,     0,   102,   103,   104,
     105,     0,   106
};

static const yytype_int16 yycheck[] =
{
      64,    65,     0,     1,    68,    69,    32,     9,     6,    12,
      36,    75,     5,    26,     6,    12,     0,    81,    82,     5,
      12,    14,     5,    87,    88,    18,    29,    25,    26,    26,
      27,    14,    29,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    55,     1,     5,     1,    10,     5,     1,     5,
       3,     4,    78,    14,    12,    30,     9,    55,     1,    34,
       3,    14,    20,    21,    22,    23,    24,    25,    26,    27,
       1,    29,    25,    10,     5,    28,     0,     1,     1,     1,
     144,    12,     5,     7,     8,    14,     9,     9,     5,    20,
      21,    22,    23,    24,    25,    26,    27,     1,    29,     3,
       4,     7,     8,    12,     9,     9,    10,    11,    10,    15,
      14,    20,    16,    17,     1,    19,     3,     4,    11,     1,
      15,    25,     9,    10,    28,     7,     8,    14,     6,    16,
      17,    18,    19,    15,     1,    15,     3,     4,    25,     7,
       8,    28,     9,    10,    15,     5,    12,    14,    13,    16,
      17,     1,    19,     3,     4,    13,    11,     6,    25,     9,
      10,    28,    14,    14,    14,     5,    16,    17,     1,    19,
       3,     4,    14,     5,    15,    25,     9,     1,    28,     3,
       4,    14,    15,     9,    15,     9,     1,    15,     3,     4,
      14,    18,    25,    15,     9,    28,    13,     6,    28,    14,
      21,    25,    72,     1,    28,     3,     4,    -1,   144,    78,
      25,     9,     1,    28,     3,     4,    14,    -1,    -1,    -1,
       9,     1,    -1,     3,     4,    14,    -1,    25,    -1,     9,
      28,    -1,    -1,    -1,    14,    -1,    25,    -1,     1,    28,
       3,     4,    -1,    -1,    -1,    25,     9,     1,    28,     3,
       4,    14,    -1,    -1,    -1,     9,     1,    -1,     3,     4,
      14,    -1,    25,    -1,     9,    28,    -1,    -1,    -1,    14,
      -1,    25,    -1,     1,    28,     3,     4,    -1,    -1,    -1,
      25,     9,     1,    28,     3,     4,    14,    -1,    -1,    -1,
       9,     1,    -1,     3,     4,    14,    -1,    25,    -1,     9,
      28,     3,     4,    -1,    14,    -1,    25,     9,     1,    28,
       3,     4,    14,    -1,    -1,    25,     9,     1,    28,     3,
       4,    14,    -1,    25,    -1,     9,    28,    -1,    -1,    -1,
      14,     6,    25,    -1,    -1,    28,     5,    12,     7,     8,
      -1,    25,    -1,    -1,    28,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,   142,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    12,    -1,    -1,
      15,    -1,   159,   160,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    12,    29,    -1,    15,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    12,
      29,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    12,    29,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    12,
      29,    -1,    -1,    -1,    -1,    -1,    12,    20,    21,    22,
      23,    24,    25,    26,    27,    12,    29,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    32,    33,    34,    36,    37,     5,
      36,     9,    38,    39,     0,    33,     1,     5,     9,    35,
      40,    41,     5,    10,     5,    14,    14,     5,     6,    12,
      10,    44,    36,    47,    48,    15,    36,    42,    43,     1,
      15,    42,     9,    35,     1,     3,    47,     1,    40,    49,
      50,    11,    47,    40,    15,     6,    15,    15,    13,    13,
       1,     3,     4,     9,    14,    16,    17,    19,    25,    28,
      44,    45,    46,    51,     5,    20,     1,     5,     6,    42,
       5,    14,    14,     1,    51,     1,    51,    14,    14,     1,
      51,     1,    51,    11,    45,     1,     5,    12,    20,    21,
      22,    23,    24,    25,    26,    27,    29,    51,    49,    51,
       1,    15,    51,    52,    15,    15,     5,     1,     5,     1,
      51,    51,     5,     1,    51,     1,    51,     1,    51,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    51,     1,
      51,     9,    15,    15,     6,    15,    15,    15,    15,    13,
      13,    46,    52,    18,    46,     1,    46,    46,    46,    18,
      18,    46,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      34,    35,    35,    36,    36,    37,    37,    38,    38,    39,
      40,    40,    40,    41,    41,    41,    41,    41,    42,    42,
      43,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    47,    47,
      48,    48,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     3,     2,
       3,     1,     3,     1,     1,     5,     2,     0,     1,     1,
       1,     4,     4,     4,     3,     4,     4,     3,     3,     1,
       2,     4,     0,     2,     2,     1,     3,     5,     7,     5,
       2,     3,     3,     3,     5,     7,     6,     5,     0,     2,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     3,
       4,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     2,     2,     3,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 32 "./syntax.y"
                    {(yyval.type_node)=addNode("Program",1,(yyvsp[0].type_node));}
#line 1621 "./syntax.tab.c"
    break;

  case 3:
#line 34 "./syntax.y"
            {(yyval.type_node)=addNode("ExtDefList",0,-1);}
#line 1627 "./syntax.tab.c"
    break;

  case 4:
#line 35 "./syntax.y"
                     {(yyval.type_node)=addNode("ExtDefList",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1633 "./syntax.tab.c"
    break;

  case 5:
#line 37 "./syntax.y"
                                  {
    (yyval.type_node)=addNode("ExtDef",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //对每个varDec进行添加
    //printf("you have come tothe extdef\n");
    tNode* child=(yyvsp[-1].type_node)->child;
    while(child!=NULL)
    {
      //printf("child->name: %s\n",child->name);
      if(strcmp(child->name,"VarDec")==0)
      {
        int iffindBasic=findBasic(child);
        //printf("you have come to the iffindarray\n");
        int iffindArray=findArray(child);
        //printf("you have end the iffindarray\n");
        if(iffindBasic==1 || iffindArray==1)
          printf("Error type 3 at Line %d: Redefined variable \'%s\'.\n",yylineno,child->content);
        else if(iffindBasic==2 || iffindBasic==2)
          printf("Error type 15 at Line %d: Redefined field \'%s\'.\n",yylineno,child->content);
        else if(child->tag==1) newBasic(2,(yyvsp[-2].type_node),child);
        else if(child->tag==4) newArray(2,(yyvsp[-2].type_node),child);
        child=child->nextsibling;
      }
      else if(strcmp(child->name,"ExtDecList")==0)
      {
        child=child->child;
      }
      else child=child->nextsibling;
    }
  }
#line 1667 "./syntax.tab.c"
    break;

  case 6:
#line 66 "./syntax.y"
                  {(yyval.type_node)=addNode("ExtDef",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1673 "./syntax.tab.c"
    break;

  case 7:
#line 67 "./syntax.y"
                           {
    (yyval.type_node)=addNode("ExtDef",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    newFunc(1,(yyvsp[-2].type_node));
  }
#line 1682 "./syntax.tab.c"
    break;

  case 8:
#line 71 "./syntax.y"
                        {yyerror("initialized or invalid global variable");}
#line 1688 "./syntax.tab.c"
    break;

  case 9:
#line 72 "./syntax.y"
              {yyerror("error 0");}
#line 1694 "./syntax.tab.c"
    break;

  case 10:
#line 73 "./syntax.y"
                        {yyerror("error 2");}
#line 1700 "./syntax.tab.c"
    break;

  case 11:
#line 75 "./syntax.y"
                   {(yyval.type_node)=addNode("ExtDecList",1,(yyvsp[0].type_node));(yyval.type_node)->type=(yyvsp[0].type_node)->type;}
#line 1706 "./syntax.tab.c"
    break;

  case 12:
#line 76 "./syntax.y"
                           {(yyval.type_node)=addNode("ExtDecList",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));(yyval.type_node)->type=(yyvsp[-2].type_node)->type;}
#line 1712 "./syntax.tab.c"
    break;

  case 13:
#line 79 "./syntax.y"
                {(yyval.type_node)=addNode("Specifier",1,(yyvsp[0].type_node));(yyval.type_node)->type=(yyvsp[0].type_node)->type;}
#line 1718 "./syntax.tab.c"
    break;

  case 14:
#line 80 "./syntax.y"
                   {(yyval.type_node)=addNode("Specifier",1,(yyvsp[0].type_node));(yyval.type_node)->type=(yyvsp[0].type_node)->type;}
#line 1724 "./syntax.tab.c"
    break;

  case 15:
#line 82 "./syntax.y"
                                             {
    (yyval.type_node)=addNode("StructSpecifier",5,(yyvsp[-4].type_node),(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //是否找到同名结构体或变量
    int iffindStruct=findIfStruct((yyvsp[-3].type_node));
    int iffindBasic=findBasic((yyvsp[-3].type_node));
    int iffindArray=findArray((yyvsp[-3].type_node));
    if(iffindStruct==1 || iffindBasic==1 || iffindArray==1)
      printf("Error type 16 at Line %d: Duplicated name \'%s\'.\n",structopttagline[stackTop],(yyvsp[-3].type_node)->content);
    else if(strcmp((yyvsp[-3].type_node)->content,"{")!=0) newStruct(2,(yyval.type_node),(yyvsp[-3].type_node));  //在这一部中对structspecifier的type赋值
    else
    {
      //Opttag->
      //此时仅需修改structspecifier的type
      newStructNoname(1,(yyval.type_node));
    }
    stackIndexTop--;
    //printf("the stacktop insturct is %d\n",stackTop);
    stackTop--;
  }
#line 1748 "./syntax.tab.c"
    break;

  case 16:
#line 101 "./syntax.y"
              {
    (yyval.type_node)=addNode("StructSpecifier",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //发现此时的struct是使用而非定义
    stackTop--;
    maxStructNum--;
    stackIndexTop--;
    //如果tag未被定义，则输出错误17
    int iffindStruct=findIfStruct((yyvsp[0].type_node));
    if(iffindStruct==0)
    {
      printf("Error type 17 at Line %d: Undefined structure \'%s\'.\n",yylineno,(yyvsp[0].type_node)->content);
    }
    else
    {
      (yyval.type_node)->content=(yyvsp[0].type_node)->content;
      (yyval.type_node)->type=getStructByName((yyvsp[0].type_node)->content)->type;
    }
  }
#line 1771 "./syntax.tab.c"
    break;

  case 17:
#line 120 "./syntax.y"
         {(yyval.type_node)=addNode("OptTag",0,-1);}
#line 1777 "./syntax.tab.c"
    break;

  case 18:
#line 121 "./syntax.y"
       {(yyval.type_node)=addNode("OptTag",1,(yyvsp[0].type_node)); }
#line 1783 "./syntax.tab.c"
    break;

  case 19:
#line 124 "./syntax.y"
       {(yyval.type_node)=addNode("Tag",1,(yyvsp[0].type_node));}
#line 1789 "./syntax.tab.c"
    break;

  case 20:
#line 126 "./syntax.y"
            {(yyval.type_node)=addNode("VarDec",1,(yyvsp[0].type_node));(yyval.type_node)->tag=1;}
#line 1795 "./syntax.tab.c"
    break;

  case 21:
#line 127 "./syntax.y"
                    {
    (yyval.type_node)=addNode("VarDec",4,(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[-3].type_node)->content;
    (yyval.type_node)->tag=4;
    createNewArrayBody((yyvsp[-1].type_node));
  }
#line 1806 "./syntax.tab.c"
    break;

  case 22:
#line 133 "./syntax.y"
                      {yyerror("invalid expression between \'[]\'");}
#line 1812 "./syntax.tab.c"
    break;

  case 23:
#line 135 "./syntax.y"
                         {
    (yyval.type_node)=addNode("FunDec",4,(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[-3].type_node)->content;
    (yyval.type_node)->tag=2;
    if(findFunc((yyvsp[-3].type_node))==1)
      printf("Error type 4 at Line %d: Redefined function \'%s\'.\n",yylineno,(yyvsp[-3].type_node)->content);
    else newFunc(2,(yyvsp[-3].type_node),(yyvsp[-1].type_node));
  }
#line 1825 "./syntax.tab.c"
    break;

  case 24:
#line 143 "./syntax.y"
            {
    (yyval.type_node)=addNode("FunDec",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[-2].type_node)->content;
    (yyval.type_node)->tag=2;
    //printf("the funcid is %s\n",$$->content);
    if(findFunc((yyvsp[-2].type_node))==1)
      printf("Error type 4 at Line %d: Redefined function \'%s\'.\n",yylineno,(yyvsp[-2].type_node)->content);
    else newFunc(2,(yyvsp[-2].type_node),NULL);
  }
#line 1839 "./syntax.tab.c"
    break;

  case 25:
#line 152 "./syntax.y"
                  {yyerror("invalid varlist");}
#line 1845 "./syntax.tab.c"
    break;

  case 26:
#line 153 "./syntax.y"
                       {yyerror("invalid function name");}
#line 1851 "./syntax.tab.c"
    break;

  case 27:
#line 154 "./syntax.y"
               {yyerror("invalid function name");}
#line 1857 "./syntax.tab.c"
    break;

  case 28:
#line 156 "./syntax.y"
                                {(yyval.type_node)=addNode("VarList",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1863 "./syntax.tab.c"
    break;

  case 29:
#line 157 "./syntax.y"
            {(yyval.type_node)=addNode("VarList",1,(yyvsp[0].type_node));}
#line 1869 "./syntax.tab.c"
    break;

  case 30:
#line 159 "./syntax.y"
                            {
    (yyval.type_node)=addNode("ParamDec",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
    int iffindBasic=findBasic((yyvsp[0].type_node));
    int iffindArray=findArray((yyvsp[0].type_node));
    if(iffindBasic==1 || iffindArray==1)
      printf("Error type 3 at Line %d: Redefined variable \'%s\'.\n",yylineno,(yyvsp[0].type_node)->content);
    else if((yyvsp[0].type_node)->tag==1)
      newBasic(2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
    else if((yyvsp[0].type_node)->tag==4)
      newArray(2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
  }
#line 1885 "./syntax.tab.c"
    break;

  case 31:
#line 171 "./syntax.y"
                                {(yyval.type_node)=addNode("CompSt",4,(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1891 "./syntax.tab.c"
    break;

  case 32:
#line 173 "./syntax.y"
           {(yyval.type_node)=addNode("StmList",0,-1);}
#line 1897 "./syntax.tab.c"
    break;

  case 33:
#line 174 "./syntax.y"
                 {(yyval.type_node)=addNode("StmtList",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1903 "./syntax.tab.c"
    break;

  case 34:
#line 176 "./syntax.y"
               {(yyval.type_node)=addNode("Stmt",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1909 "./syntax.tab.c"
    break;

  case 35:
#line 177 "./syntax.y"
          {(yyval.type_node)=addNode("Stmt",1,(yyvsp[0].type_node));}
#line 1915 "./syntax.tab.c"
    break;

  case 36:
#line 178 "./syntax.y"
                   {
    (yyval.type_node)=addNode("Stmt",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    getFuncReturnType((yyvsp[-1].type_node));
  }
#line 1924 "./syntax.tab.c"
    break;

  case 37:
#line 182 "./syntax.y"
                     {(yyval.type_node)=addNode("Stmt",5,(yyvsp[-4].type_node),(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1930 "./syntax.tab.c"
    break;

  case 38:
#line 183 "./syntax.y"
                               {(yyval.type_node)=addNode("Stmt",7,(yyvsp[-6].type_node),(yyvsp[-5].type_node),(yyvsp[-4].type_node),(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1936 "./syntax.tab.c"
    break;

  case 39:
#line 184 "./syntax.y"
                        {(yyval.type_node)=addNode("Stmt",5,(yyvsp[-4].type_node),(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 1942 "./syntax.tab.c"
    break;

  case 40:
#line 185 "./syntax.y"
              {yyerror("invalid statement or cannot define variable before \';\'");}
#line 1948 "./syntax.tab.c"
    break;

  case 41:
#line 186 "./syntax.y"
                  {yyerror("invalid expression near \';\'");}
#line 1954 "./syntax.tab.c"
    break;

  case 42:
#line 187 "./syntax.y"
                    {yyerror("invalid expression near \'return\'");}
#line 1960 "./syntax.tab.c"
    break;

  case 43:
#line 188 "./syntax.y"
                     {yyerror("invalid expression between \'return\' and \';\'");}
#line 1966 "./syntax.tab.c"
    break;

  case 44:
#line 189 "./syntax.y"
                                             {yyerror("invalid statement of if");}
#line 1972 "./syntax.tab.c"
    break;

  case 45:
#line 190 "./syntax.y"
                                {yyerror("invalid statement of if");}
#line 1978 "./syntax.tab.c"
    break;

  case 46:
#line 191 "./syntax.y"
                            {yyerror("invalid statement of if");}
#line 1984 "./syntax.tab.c"
    break;

  case 47:
#line 192 "./syntax.y"
                        {yyerror("invalid statement of if");}
#line 1990 "./syntax.tab.c"
    break;

  case 48:
#line 195 "./syntax.y"
          {(yyval.type_node)=addNode("DefList",0,-1);}
#line 1996 "./syntax.tab.c"
    break;

  case 49:
#line 196 "./syntax.y"
               {(yyval.type_node)=addNode("DefList",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 2002 "./syntax.tab.c"
    break;

  case 50:
#line 198 "./syntax.y"
                            {
    (yyval.type_node)=addNode("Def",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //对每个varDec进行添加
    tNode* child=(yyvsp[-1].type_node)->child;
    //if(child==NULL) printf("the declist has no child\n");
    while(child!=NULL)
    {
      //printf("the declist indef child name is: %s\n",child->name);
      if(strcmp(child->name,"Dec")==0)
      {
        tNode* temp=child->child;
        int iffindBasic=findBasic(temp);
        int iffindArray=findArray(temp);
        //printf("child->tag: %d\n",child->tag);
        //if(temp->type_name!=NULL) printf("temp->type_name: $s\n",temp->type_name);
        if(iffindBasic==1 || iffindArray==1)
          printf("Error type 3 at Line %d: Redefined variable \'%s\'.\n",yylineno,temp->content);
        else if(iffindBasic==2 || iffindBasic==2)
          printf("Error type 15 at Line %d: Redefined field \'%s\'.\n",yylineno,temp->content);
        //如果有等号，徐判断类型是否一致
        else if(temp->type!=NULL && isSameType(temp->type,(yyvsp[-2].type_node)->type)!=0)
        {
          printf("Error type 5 at Line %d: Type mismatched for assignment.\n",yylineno);
        }
        else if(child->tag==1) newBasic(2,(yyvsp[-2].type_node),temp);
        else if(child->tag==4) newArray(2,(yyvsp[-2].type_node),temp);
        child=child->nextsibling;
      }
      else if(strcmp(child->name,"DecList")==0)
      {
        child=child->child;
      }
      else child=child->nextsibling;
    }
  }
#line 2042 "./syntax.tab.c"
    break;

  case 51:
#line 233 "./syntax.y"
                        {yyerror("invalid variable or expected expression before \';\'");}
#line 2048 "./syntax.tab.c"
    break;

  case 52:
#line 234 "./syntax.y"
                           {yyerror("missing \';\' or invalid token");}
#line 2054 "./syntax.tab.c"
    break;

  case 53:
#line 236 "./syntax.y"
             {(yyval.type_node)=addNode("DecList",1,(yyvsp[0].type_node));}
#line 2060 "./syntax.tab.c"
    break;

  case 54:
#line 237 "./syntax.y"
                     {(yyval.type_node)=addNode("DecList",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));(yyval.type_node)->tag=(yyvsp[0].type_node)->tag;}
#line 2066 "./syntax.tab.c"
    break;

  case 55:
#line 239 "./syntax.y"
            {(yyval.type_node)=addNode("Dec",1,(yyvsp[0].type_node));}
#line 2072 "./syntax.tab.c"
    break;

  case 56:
#line 240 "./syntax.y"
                       {
    (yyval.type_node)=addNode("Dec",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[-2].type_node)->content;
    (yyval.type_node)->tag=(yyvsp[-2].type_node)->tag;
    (yyvsp[-2].type_node)->type_name=(yyvsp[0].type_node)->type_name;
    //printf("$$->type_name: %s\n",$$->type_name);
    (yyvsp[-2].type_node)->type=(yyvsp[0].type_node)->type;
    if(stackTop!=-1)
    {
      printf("Error type 15 at Line %d: Illegal use of assignment.\n",yylineno);
    }
  }
#line 2089 "./syntax.tab.c"
    break;

  case 57:
#line 254 "./syntax.y"
                      {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //如果出现一边变量未被定义，不做任何输出，错误信息前面以及输出
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL)
    {
      //printf("%s type_name is zero\n",$1->content);
    }
    else
    {
      //printf("int Exp ASSIGNOP Exp,use Type_ to compare node's type,may cause fault!\n");
      // if(strcmp($1->type_name,$3->type_name)!=0)
      //如果在结构体中赋值，报15号错误
      if(stackTop!=-1)
      {
        printf("Error type 15 at Line %d: Illegal use of assignment.\n",yylineno);
      }
      if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) != 0)
        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",yylineno);
      if(checkIfLeft((yyvsp[-2].type_node))==0)
        printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n",yylineno);
      // if(strcmp($1->type_name,$3->type_name)==0 && checkIfLeft($1)==1)
      if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) == 0 && checkIfLeft((yyvsp[-2].type_node))==1)
      {
        (yyval.type_node)->type_name=(yyvsp[-2].type_node)->type_name;
        (yyval.type_node)->type=(yyvsp[-2].type_node)->type;
      }
    }
  }
#line 2122 "./syntax.tab.c"
    break;

  case 58:
#line 282 "./syntax.y"
               {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    else if((yyvsp[-2].type_node)->type!=type_int || (yyvsp[0].type_node)->type!=type_int)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name="int";
      (yyval.type_node)->type=type_int;
    }
  }
#line 2138 "./syntax.tab.c"
    break;

  case 59:
#line 293 "./syntax.y"
              {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    else if((yyvsp[-2].type_node)->type!=type_int || (yyvsp[0].type_node)->type!=type_int)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name="int";
      (yyval.type_node)->type=type_int;
    }
  }
#line 2154 "./syntax.tab.c"
    break;

  case 60:
#line 304 "./syntax.y"
                 {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //printf("int Exp RELOP Exp,use Type_ to compare node's type,may cause fault!\n");
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    // else if(strcmp($1->type_name,$3->type_name))
    else if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name="int";
      (yyval.type_node)->type=type_int;
    }
  }
#line 2172 "./syntax.tab.c"
    break;

  case 61:
#line 317 "./syntax.y"
                {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    else if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if((yyvsp[-2].type_node)->type!=type_int && (yyvsp[-2].type_node)->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name=(yyvsp[-2].type_node)->type_name;
      (yyval.type_node)->type=(yyvsp[-2].type_node)->type;
    }
  }
#line 2190 "./syntax.tab.c"
    break;

  case 62:
#line 330 "./syntax.y"
                 {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    else if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if((yyvsp[-2].type_node)->type!=type_int && (yyvsp[-2].type_node)->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name=(yyvsp[-2].type_node)->type_name;
      (yyval.type_node)->type=(yyvsp[-2].type_node)->type;
    }
  }
#line 2208 "./syntax.tab.c"
    break;

  case 63:
#line 343 "./syntax.y"
                {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    else if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if((yyvsp[-2].type_node)->type!=type_int && (yyvsp[-2].type_node)->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name=(yyvsp[-2].type_node)->type_name;
      (yyval.type_node)->type=(yyvsp[-2].type_node)->type;
      //printf("the exp*exp type: %d  basic: %d\n",$$->type->kind,$$->type->u.basic);
    }
  }
#line 2227 "./syntax.tab.c"
    break;

  case 64:
#line 357 "./syntax.y"
               {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[-2].type_node)->type==NULL || (yyvsp[0].type_node)->type==NULL){}
    else if(isSameTypeByNode((yyvsp[-2].type_node),(yyvsp[0].type_node)) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if((yyvsp[-2].type_node)->type!=type_int && (yyvsp[-2].type_node)->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name=(yyvsp[-2].type_node)->type_name;
      (yyval.type_node)->type=(yyvsp[-2].type_node)->type;
    }
  }
#line 2245 "./syntax.tab.c"
    break;

  case 65:
#line 370 "./syntax.y"
             {(yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));(yyval.type_node)->type_name=(yyvsp[-1].type_node)->type_name;(yyval.type_node)->type=(yyvsp[-1].type_node)->type;}
#line 2251 "./syntax.tab.c"
    break;

  case 66:
#line 371 "./syntax.y"
             {
    (yyval.type_node)=addNode("Exp",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[0].type_node)->type==NULL){}
    else if((yyvsp[0].type_node)->type!=type_int && (yyvsp[0].type_node)->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name=(yyvsp[0].type_node)->type_name;
      (yyval.type_node)->type=(yyvsp[0].type_node)->type;
    }
  }
#line 2267 "./syntax.tab.c"
    break;

  case 67:
#line 382 "./syntax.y"
           {
    (yyval.type_node)=addNode("Exp",2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
    if((yyvsp[0].type_node)->type==NULL){}
    else if((yyvsp[0].type_node)->type!=type_int && (yyvsp[0].type_node)->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      (yyval.type_node)->type_name=(yyvsp[0].type_node)->type_name;
      (yyval.type_node)->type=(yyvsp[0].type_node)->type;
    }
  }
#line 2283 "./syntax.tab.c"
    break;

  case 68:
#line 393 "./syntax.y"
                 {
    (yyval.type_node)=addNode("Exp",4,(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //对普通变量使用（）调用，报错误11
    if(!findFunc((yyvsp[-3].type_node)) && (findBasic((yyvsp[-3].type_node)) || findArray((yyvsp[-3].type_node))))
    {
      printf("Error type 11 at Line %d: \'%s\' is not a function.\n",yylineno,(yyvsp[-3].type_node)->content);
    }
    //函数调用时未定义，报错误2
    else if(!findFunc((yyvsp[-3].type_node)))
    {
      printf("Error type 2 at Line %d: Undefined function \'%s\'.\n",yylineno,(yyvsp[-3].type_node)->content);
    }
    //检查参数数量和类型,报错误9
    else if(checkType((yyvsp[-3].type_node),(yyvsp[-1].type_node))==0)
    {
      printf("Error type 9 at Line %d: Function parameter type error.\n",yylineno);
    }
    else
    {
      Func_* temp=getFunc((yyvsp[-3].type_node));
      (yyval.type_node)->type_name=temp->type_name;
      (yyval.type_node)->type=temp->returnType;
    }
  }
#line 2312 "./syntax.tab.c"
    break;

  case 69:
#line 417 "./syntax.y"
            {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    //对普通变量使用（）调用，报错误11
    if(!findFunc((yyvsp[-2].type_node)) && (findBasic((yyvsp[-2].type_node)) || findArray((yyvsp[-2].type_node))))
    {
      printf("Error type 11 at Line %d: \'%s\' is not a function.\n",yylineno,(yyvsp[-2].type_node)->content);
    }
    //函数调用时未定义，报错误2
    else if(!findFunc((yyvsp[-2].type_node)))
    {
      printf("Error type 2 at Line %d: Undefined function \'%s\'.\n",yylineno,(yyvsp[-2].type_node)->content);
    }
    else
    {
      Func_* temp=getFunc((yyvsp[-2].type_node));
      (yyval.type_node)->type_name=temp->type_name;
      (yyval.type_node)->type=temp->returnType;
    }
  }
#line 2336 "./syntax.tab.c"
    break;

  case 70:
#line 436 "./syntax.y"
                 {
    //printf("you have come to the exp->exp lb exp rb\n");
    (yyval.type_node)=addNode("Exp",4,(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[-3].type_node)->content;
    (yyval.type_node)->tag=(yyvsp[-3].type_node)->tag;
    //printf("tag: %d\n",$$->tag);
    //对非数组变量采用[]报错误10
    if((yyval.type_node)->tag!=4 && (yyval.type_node)->tag>0)
    {
      printf("Error type 10 at Line %d: \'%s\' is not an array.\n",yylineno,(yyvsp[-3].type_node)->content);
    }
    //数组变量名未定义，报错误1
    else if((yyval.type_node)->tag!=4)
    {
      //printf("$$->tag: %d\n",$$->tag);
      printf("Error type 1 at Line %d: Undefined variable \'%s\'.\n",yylineno,(yyvsp[-3].type_node)->content);
    }
    else
    {
      //中间不是int变量，报12号错误
      if((yyvsp[-1].type_node)->type==type_float)
      {
        printf("Error type 12 at Line %d: \'%s\' is not an integer.\n",yylineno,(yyvsp[-1].type_node)->content);
      }
      else
      {
        (yyval.type_node)->type_name=(yyvsp[-3].type_node)->type_name;
        (yyval.type_node)->type=(yyvsp[-3].type_node)->type->u.array.elem;
        if((yyval.type_node)->type->kind!=ARRAY)
        {
          (yyval.type_node)->tag=1;
        }
        //printf("you have exit the exp->exp LB Exp RB");
      }
    }
    
  }
#line 2378 "./syntax.tab.c"
    break;

  case 71:
#line 473 "./syntax.y"
              {
    (yyval.type_node)=addNode("Exp",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[-2].type_node)->content;
    //获取exp所在的structnum
    if((yyvsp[-2].type_node)->type==NULL){}
    else
    {
      if((yyvsp[-2].type_node)->type->kind!=STRUCTURE)
      {
        printf("Error type 13 at Line %d: Illegal use of \'.\'.\n",yylineno);
      }
      else
      {
        //printf("Line: %d $1->type: %d\n",yylineno,$1->type->kind);
        //通过type里的structure去找$3->content
        FieldList_* it=getfield((yyvsp[-2].type_node)->type,(yyvsp[0].type_node)->content);
        if(it==NULL){
          //没找到，报错误14
          printf("Error type 14 at Line %d: Non-existent field \'%s\'.\n",yylineno,(yyvsp[0].type_node)->content);
        }
        else
        {
          (yyval.type_node)->content=it->name;
          (yyval.type_node)->type=it->type;
          if((yyval.type_node)->type->kind==ARRAY){
            (yyval.type_node)->tag=4;
          }
          else (yyval.type_node)->tag=1;
        }
      }
    }
  }
#line 2415 "./syntax.tab.c"
    break;

  case 72:
#line 505 "./syntax.y"
      {
    (yyval.type_node)=addNode("Exp",1,(yyvsp[0].type_node));
    (yyval.type_node)->content=(yyvsp[0].type_node)->content;
    //如果变量未定义，输出错误1
    if(!findBasic((yyvsp[0].type_node)) && !findArray((yyvsp[0].type_node)))
    {
      printf("Error type 1 at Line %d: Undefined variable \'%s\'.\n",yylineno,(yyvsp[0].type_node)->content);
      (yyval.type_node)->tag=0;
    }
    else
    {
      if(findBasic((yyvsp[0].type_node)))
      {
        //printf("you have find the basicvariable\n");
        Basic_* temp=getBasic((yyvsp[0].type_node));
        //printf("you have get the basic\n");
        (yyval.type_node)->type=temp->type;
        (yyval.type_node)->type_name=temp->type_name;
        (yyval.type_node)->content=temp->name;
        (yyval.type_node)->tag=1;
        //printf("you have left the exp->id\n");
      }
      if(findArray((yyvsp[0].type_node)))
      {
        //printf("you have find the arryvariable\n");
        Array_* temp=getArray((yyvsp[0].type_node));
        (yyval.type_node)->type_name=temp->type_name;
        (yyval.type_node)->type=temp->type;
        (yyval.type_node)->content=temp->name;
        (yyval.type_node)->tag=4;
        //printf("$$->content: %s  $$->tag: %d\n",$$->content,$$->tag);
      }
    }
  }
#line 2454 "./syntax.tab.c"
    break;

  case 73:
#line 539 "./syntax.y"
       {
    //printf("exp->int\n");
    (yyval.type_node)=addNode("Exp",1,(yyvsp[0].type_node));
    //printf("exp->int\n");
    (yyval.type_node)->tag=3;
    (yyval.type_node)->type_name="int";
    (yyval.type_node)->type=(yyvsp[0].type_node)->type;
    (yyval.type_node)->content=(yyvsp[0].type_node)->content;
    //printf("you have success left the exp->int\n");
  }
#line 2469 "./syntax.tab.c"
    break;

  case 74:
#line 549 "./syntax.y"
         {
    (yyval.type_node)=addNode("Exp",1,(yyvsp[0].type_node));
    (yyval.type_node)->tag=3;
    (yyval.type_node)->type_name="float";
    (yyval.type_node)->type=(yyvsp[0].type_node)->type;
    (yyval.type_node)->content=(yyvsp[0].type_node)->content;
  }
#line 2481 "./syntax.tab.c"
    break;

  case 75:
#line 556 "./syntax.y"
                      {yyerror("invalid token near \'=\'");}
#line 2487 "./syntax.tab.c"
    break;

  case 76:
#line 557 "./syntax.y"
                 {yyerror("invalid token near \'&&\'");}
#line 2493 "./syntax.tab.c"
    break;

  case 77:
#line 558 "./syntax.y"
                {yyerror("invalid token near \'||\'");}
#line 2499 "./syntax.tab.c"
    break;

  case 78:
#line 559 "./syntax.y"
                   {yyerror("invalid token near \'RELOP\'");}
#line 2505 "./syntax.tab.c"
    break;

  case 79:
#line 560 "./syntax.y"
                  {yyerror("invalid token near \'+\'");}
#line 2511 "./syntax.tab.c"
    break;

  case 80:
#line 561 "./syntax.y"
                   {yyerror("invalid token near \'-\'");}
#line 2517 "./syntax.tab.c"
    break;

  case 81:
#line 562 "./syntax.y"
                  {yyerror("invalid token near \'*\'");}
#line 2523 "./syntax.tab.c"
    break;

  case 82:
#line 563 "./syntax.y"
                 {yyerror("invalid token near \'/\'");}
#line 2529 "./syntax.tab.c"
    break;

  case 83:
#line 564 "./syntax.y"
                  {yyerror("invalid expression between \'[]\'");}
#line 2535 "./syntax.tab.c"
    break;

  case 84:
#line 565 "./syntax.y"
                   {yyerror("invalid expression between \'[]\'");}
#line 2541 "./syntax.tab.c"
    break;

  case 85:
#line 566 "./syntax.y"
               {yyerror("invalid token after \'-\'");}
#line 2547 "./syntax.tab.c"
    break;

  case 86:
#line 567 "./syntax.y"
             {yyerror("invalid token after \'!\'");}
#line 2553 "./syntax.tab.c"
    break;

  case 87:
#line 568 "./syntax.y"
               {yyerror("invalid expression between \'[]\'");}
#line 2559 "./syntax.tab.c"
    break;

  case 88:
#line 570 "./syntax.y"
                     {(yyval.type_node)=addNode("Args",3,(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));}
#line 2565 "./syntax.tab.c"
    break;

  case 89:
#line 571 "./syntax.y"
       {(yyval.type_node)=addNode("Args",1,(yyvsp[0].type_node));}
#line 2571 "./syntax.tab.c"
    break;


#line 2575 "./syntax.tab.c"

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
  *++yylsp = yyloc;

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 573 "./syntax.y"

//#include "lex.yy.c"
#include"tree.h"
