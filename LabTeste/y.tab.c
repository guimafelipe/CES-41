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
#line 1 "tsimb.y" /* yacc.c:339  */


/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */

#define 	LT 		    1
#define 	LE 	    	2
#define		GT			3
#define		GE			4
#define		EQ			5
#define		NE			6
#define		MAIS        7
#define		MENOS       8
#define		MULT    	9
#define		DIV   	    10
#define		RESTO   	11

/*   Definicao dos tipos de identificadores   */

#define 	IDPROG		1
#define 	IDVAR		2

/*  Definicao dos tipos de variaveis   */

#define 	NAOVAR		0
#define 	INTEIRO		1
#define 	LOGICO		2
#define 	REAL		3
#define 	CARACTERE	4

/*   Definicao de outras constantes   */

#define	NCLASSHASH	23
#define	VERDADE		1
#define	FALSO		0

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[3] = {" ", "IDPROG", "IDVAR"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[5] = {"NAOVAR",
	"INTEIRO", "LOGICO", "REAL", "CARACTERE"
};

/*    Declaracoes para a tabela de simbolos     */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
struct celsimb {
	char *cadeia;
	int tid, tvar;
	char inic, ref;
	simbolo prox;
};

/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb;

/*
	Prototipos das funcoes para a tabela de simbolos
    	e analise semantica
 */

void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int);
int hash (char *);
simbolo ProcuraSimb (char *);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);


#line 149 "y.tab.c" /* yacc.c:339  */

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
    ID = 258,
    CHARCT = 259,
    INTCT = 260,
    FLOATCT = 261,
    STRING = 262,
    OR = 263,
    AND = 264,
    NOT = 265,
    RELOP = 266,
    ADOP = 267,
    MULTOP = 268,
    NEG = 269,
    OPPAR = 270,
    CLPAR = 271,
    OPBRACE = 272,
    CLBRACE = 273,
    OPBRAK = 274,
    CLBRAK = 275,
    OPTRIP = 276,
    CLTRIP = 277,
    COMMA = 278,
    SCOLON = 279,
    COLON = 280,
    ASSIGN = 281,
    CHAR = 282,
    FALSE = 283,
    FLOAT = 284,
    INT = 285,
    LOGIC = 286,
    STATEMENTS = 287,
    TRUE = 288,
    VAR = 289,
    CALL = 290,
    DO = 291,
    IF = 292,
    ELSE = 293,
    MAIN = 294,
    READ = 295,
    REPEAT = 296,
    RETURN = 297,
    THEN = 298,
    VOID = 299,
    WHILE = 300,
    WRITE = 301,
    FOR = 302,
    INVAL = 303
  };
#endif
/* Tokens.  */
#define ID 258
#define CHARCT 259
#define INTCT 260
#define FLOATCT 261
#define STRING 262
#define OR 263
#define AND 264
#define NOT 265
#define RELOP 266
#define ADOP 267
#define MULTOP 268
#define NEG 269
#define OPPAR 270
#define CLPAR 271
#define OPBRACE 272
#define CLBRACE 273
#define OPBRAK 274
#define CLBRAK 275
#define OPTRIP 276
#define CLTRIP 277
#define COMMA 278
#define SCOLON 279
#define COLON 280
#define ASSIGN 281
#define CHAR 282
#define FALSE 283
#define FLOAT 284
#define INT 285
#define LOGIC 286
#define STATEMENTS 287
#define TRUE 288
#define VAR 289
#define CALL 290
#define DO 291
#define IF 292
#define ELSE 293
#define MAIN 294
#define READ 295
#define REPEAT 296
#define RETURN 297
#define THEN 298
#define VOID 299
#define WHILE 300
#define WRITE 301
#define FOR 302
#define INVAL 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 86 "tsimb.y" /* yacc.c:355  */

	char string[50];
	int atr, valor;
	float valfloat;
	char carac;

#line 289 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 306 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   147,   150,   151,   151,   154,   154,   156,
     158,   159,   160,   161,   162,   164,   164,   164,   166,   166,
     168,   169,   169,   171,   172,   173,   175,   176,   178,   180,
     180,   181,   181,   183,   184,   184,   186,   188,   190,   192,
     192,   194,   194,   197,   198,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   202,   202,   202,   204,
     205,   205,   207,   207,   207,   209,   209,   209,   211,   211,
     211,   211,   211,   211,   213,   213,   215,   216,   216,   218,
     218,   220,   221,   221,   223,   224,   226,   226,   228,   229,
     231,   232,   232,   234,   234,   237,   238,   238,   240,   240,
     240,   242,   242,   242,   244,   244,   244,   246,   247,   247,
     259,   260,   260,   268,   269,   269,   278,   279,   280,   281,
     282,   283,   284,   284,   285,   285,   286,   288,   288,   290,
     291,   291,   293,   294,   295,   297,   297,   299,   299,   301,
     301
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CHARCT", "INTCT", "FLOATCT",
  "STRING", "OR", "AND", "NOT", "RELOP", "ADOP", "MULTOP", "NEG", "OPPAR",
  "CLPAR", "OPBRACE", "CLBRACE", "OPBRAK", "CLBRAK", "OPTRIP", "CLTRIP",
  "COMMA", "SCOLON", "COLON", "ASSIGN", "CHAR", "FALSE", "FLOAT", "INT",
  "LOGIC", "STATEMENTS", "TRUE", "VAR", "CALL", "DO", "IF", "ELSE", "MAIN",
  "READ", "REPEAT", "RETURN", "THEN", "VOID", "WHILE", "WRITE", "FOR",
  "INVAL", "$accept", "Prog", "$@1", "Decls", "$@2", "DeclList",
  "Declaration", "Type", "ElemList", "$@3", "Elem", "$@4", "Dims", "$@5",
  "DimList", "ModList", "Module", "ModHeader", "$@6", "$@7", "ParamList",
  "$@8", "Parameter", "ModBody", "MainMod", "Stats", "$@9", "CompStat",
  "$@10", "StatList", "Statement", "IfStat", "$@11", "$@12", "ElseStat",
  "$@13", "WhileStat", "$@14", "$@15", "RepeatStat", "$@16", "$@17",
  "ForStat", "$@18", "$@19", "$@20", "$@21", "$@22", "ReadStat", "$@23",
  "ReadList", "$@24", "WriteStat", "$@25", "WriteList", "$@26",
  "WriteElem", "CallStat", "$@27", "Arguments", "ReturnStat", "$@28",
  "AssignStat", "$@29", "ExprList", "$@30", "Expression", "$@31",
  "AuxExpr1", "$@32", "AuxExpr2", "$@33", "AuxExpr3", "$@34", "AuxExpr4",
  "$@35", "Term", "$@36", "Factor", "$@37", "$@38", "Variable", "$@39",
  "Subscripts", "$@40", "SubscrList", "TwoSubscr", "$@41", "ThreeSubscr",
  "$@42", "FuncCall", "$@43", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,    38,    25,  -123,  -123,    40,    67,  -123,  -123,    22,
      -7,  -123,  -123,  -123,  -123,    40,  -123,    76,  -123,    40,
      70,   -13,  -123,    91,    85,  -123,    86,  -123,  -123,  -123,
    -123,  -123,    65,  -123,  -123,  -123,   102,    83,  -123,  -123,
     105,   103,    -7,  -123,  -123,    91,  -123,  -123,  -123,   120,
      59,  -123,   122,  -123,  -123,  -123,  -123,  -123,   106,   110,
      23,    -7,   126,  -123,  -123,  -123,  -123,   134,  -123,   123,
    -123,   101,  -123,   124,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   115,  -123,   119,   127,
     128,   130,  -123,    69,  -123,   130,   130,  -123,   144,  -123,
     143,  -123,  -123,  -123,   135,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,     1,   140,  -123,  -123,    79,   138,  -123,
    -123,  -123,   144,   112,     4,    -4,    93,   146,   130,  -123,
     150,   130,  -123,   150,   150,   130,  -123,  -123,  -123,  -123,
    -123,  -123,    62,  -123,  -123,  -123,  -123,  -123,    64,  -123,
     151,  -123,    11,    44,   142,   145,  -123,   153,   147,   151,
     130,  -123,  -123,    13,   130,    69,   130,   150,   150,   150,
     148,  -123,   130,    69,   149,  -123,   150,  -123,  -123,  -123,
    -123,   152,  -123,   155,  -123,   140,   129,  -123,   154,   138,
    -123,  -123,   144,    26,  -123,  -123,    93,    18,   150,   150,
    -123,   130,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   154,
     154,   151,    69,   130,  -123,     2,  -123,   150,    -1,  -123,
      69,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     4,     0,    26,     5,     0,
       0,    12,    11,    10,    13,     4,    14,     0,    27,     4,
       0,     0,     7,     0,     0,    38,     0,    28,     3,     6,
       8,    18,     0,    15,    39,    37,    31,    20,    16,     9,
       0,     0,     0,    21,    19,     0,    41,    40,    30,     0,
       0,    33,     0,    17,    43,    36,    32,    34,    23,     0,
       0,     0,     0,    22,   127,    42,    55,     0,    56,     0,
      65,    91,    62,     0,    68,    45,    44,    46,    47,    48,
      49,    50,    51,    53,    54,    52,     0,    35,    24,   129,
       0,     0,    74,     0,    90,     0,     0,    79,     0,    93,
       0,   130,   128,    86,   127,   119,   117,   118,   105,   122,
     124,   121,   120,     0,    98,   101,   104,   107,   110,   113,
     116,   126,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    88,   139,     0,     0,     0,    99,    57,   102,   108,
     111,   114,     0,    76,    66,    92,    63,    84,     0,    81,
      85,    69,     0,   132,     0,   133,   134,     0,    89,    95,
      88,   106,   123,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,    82,     0,    94,   135,   131,
     137,     0,    96,     0,   125,   100,    59,   103,   109,   112,
     115,    75,     0,     0,    64,    80,     0,     0,     0,     0,
      87,     0,   140,    60,    58,    78,    67,    83,    70,   136,
     138,    97,     0,     0,    61,     0,    71,     0,     0,    72,
       0,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,   169,  -123,  -123,   156,    -6,  -123,  -123,
     136,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   114,   160,  -123,  -123,  -123,   157,  -123,  -123,
     -92,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   -16,  -123,  -123,    24,
    -123,  -123,  -123,  -123,  -123,  -123,   -89,  -123,    21,  -123,
      16,  -123,    53,  -123,  -122,  -123,    19,  -123,  -121,  -123,
    -123,   -60,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    24,    10,    21,    22,    23,    32,    45,
      33,    37,    44,    52,    59,     9,    18,    19,    41,    42,
      50,    61,    51,    25,    20,    35,    40,    75,    54,    60,
      76,    77,    91,   165,   204,   212,    78,    96,   173,    79,
      93,   172,    80,    98,   176,   213,   217,   220,    81,   122,
     142,   192,    82,   126,   148,   196,   149,    83,   131,   157,
      84,    95,    85,   128,   158,   201,   150,   164,   114,   166,
     115,   133,   116,   167,   117,   168,   118,   169,   119,   134,
     135,   120,    89,   102,   130,   154,   155,   198,   156,   199,
     121,   160
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   123,   113,    17,   136,    29,   124,   125,   153,   136,
     136,   140,   136,   162,    11,   219,    12,    13,    14,   136,
      11,   136,    12,    13,    14,     4,    64,   216,   145,   184,
     140,    16,   146,    86,   136,   177,    49,    16,   127,   152,
      46,    65,   159,   208,   137,   188,   163,    66,   190,    11,
     206,    12,    13,    14,   197,    49,   140,     1,    67,     3,
      68,    15,   143,    69,    70,    71,    16,   178,    72,    73,
      74,   159,    64,   186,     6,    56,   209,   210,   170,    26,
     174,   194,    57,   193,     8,   171,    46,   175,    38,    39,
     139,   140,    28,    66,    31,   218,   104,   105,   106,   107,
     147,    36,    43,   108,    67,    86,    68,   109,   110,    69,
      70,    71,   211,    86,    72,    73,    74,    34,   -29,    48,
     214,   111,    46,    55,   215,    94,   112,    58,   221,    62,
      63,    88,   205,   104,   105,   106,   107,    90,    92,    97,
     108,    99,   100,   103,   109,   110,   101,    64,   129,   138,
     132,   141,    86,   104,   105,   106,   107,   144,   111,   136,
      86,   151,   179,   112,   109,   110,   140,   203,   180,   181,
     182,   202,   191,   195,     7,    87,   200,    30,   111,    27,
     207,    53,   187,   112,   183,   185,   161,   189,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47
};

static const yytype_int16 yycheck[] =
{
      60,    93,    91,     9,     8,    18,    95,    96,   130,     8,
       8,    12,     8,   134,    27,    16,    29,    30,    31,     8,
      27,     8,    29,    30,    31,     0,     3,    25,    24,    16,
      12,    44,    36,    93,     8,    24,    42,    44,    98,   128,
      17,    18,   131,    25,    43,   167,   135,    24,   169,    27,
      24,    29,    30,    31,   176,    61,    12,     3,    35,    21,
      37,    39,   122,    40,    41,    42,    44,    23,    45,    46,
      47,   160,     3,   165,    34,    16,   198,   199,    16,     3,
      16,   173,    23,   172,    17,    23,    17,    23,    23,    24,
      11,    12,    22,    24,     3,   217,     3,     4,     5,     6,
       7,    15,    19,    10,    35,   165,    37,    14,    15,    40,
      41,    42,   201,   173,    45,    46,    47,    32,    16,    16,
     212,    28,    17,     3,   213,    24,    33,     5,   220,    23,
      20,     5,   192,     3,     4,     5,     6,     3,    15,    15,
      10,    26,    23,    15,    14,    15,    19,     3,     5,     9,
      15,    13,   212,     3,     4,     5,     6,    45,    28,     8,
     220,    15,    20,    33,    14,    15,    12,    38,    23,    16,
      23,    16,    24,    24,     5,    61,    24,    21,    28,    19,
     196,    45,   166,    33,   160,   164,   133,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    21,     0,    51,    34,    52,    17,    64,
      53,    27,    29,    30,    31,    39,    44,    56,    65,    66,
      73,    54,    55,    56,    52,    72,     3,    72,    22,    18,
      55,     3,    57,    59,    32,    74,    15,    60,    23,    24,
      75,    67,    68,    19,    61,    58,    17,    76,    16,    56,
      69,    71,    62,    59,    77,     3,    16,    23,     5,    63,
      78,    70,    23,    20,     3,    18,    24,    35,    37,    40,
      41,    42,    45,    46,    47,    76,    79,    80,    85,    88,
      91,    97,   101,   106,   109,   111,   130,    71,     5,   131,
       3,    81,    15,    89,    24,   110,    86,    15,    92,    26,
      23,    19,   132,    15,     3,     4,     5,     6,    10,    14,
      15,    28,    33,   115,   117,   119,   121,   123,   125,   127,
     130,   139,    98,    79,   115,   115,   102,   130,   112,     5,
     133,   107,    15,   120,   128,   129,     8,    43,     9,    11,
      12,    13,    99,   130,    45,    24,    36,     7,   103,   105,
     115,    15,   115,   123,   134,   135,   137,   108,   113,   115,
     140,   121,   127,   115,   116,    82,   118,   122,   124,   126,
      16,    23,    90,    87,    16,    23,    93,    24,    23,    20,
      23,    16,    23,   108,    16,   117,    79,   119,   123,   125,
     127,    24,   100,   115,    79,    24,   104,   123,   136,   138,
      24,   114,    16,    38,    83,   130,    24,   105,    25,   123,
     123,   115,    84,    94,    79,   115,    25,    95,   123,    16,
      96,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    50,    52,    53,    52,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    58,    57,    60,    59,
      61,    62,    61,    63,    63,    63,    64,    64,    65,    67,
      66,    68,    66,    69,    70,    69,    71,    72,    73,    75,
      74,    77,    76,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    81,    82,    80,    83,
      84,    83,    86,    87,    85,    89,    90,    88,    92,    93,
      94,    95,    96,    91,    98,    97,    99,   100,    99,   102,
     101,   103,   104,   103,   105,   105,   107,   106,   108,   108,
     109,   110,   109,   112,   111,   113,   114,   113,   115,   116,
     115,   117,   118,   117,   119,   120,   119,   121,   122,   121,
     123,   124,   123,   125,   126,   125,   127,   127,   127,   127,
     127,   127,   128,   127,   129,   127,   127,   131,   130,   132,
     133,   132,   134,   134,   134,   136,   135,   138,   137,   140,
     139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     0,     5,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     3,
       0,     0,     4,     1,     3,     5,     0,     2,     2,     0,
       5,     0,     6,     1,     0,     4,     2,     2,     2,     0,
       3,     0,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     7,     0,
       0,     3,     0,     0,     6,     0,     0,     7,     0,     0,
       0,     0,     0,    15,     0,     6,     1,     0,     4,     0,
       6,     1,     0,     4,     1,     1,     0,     7,     0,     1,
       2,     0,     4,     0,     5,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     1,     0,     3,     1,     0,     4,
       1,     0,     4,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     0,     3,     0,     4,     1,     0,     3,     0,
       0,     4,     1,     1,     1,     0,     4,     0,     4,     0,
       5
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
#line 147 "tsimb.y" /* yacc.c:1646  */
    {printf ("%s {{{\n", (yyvsp[-1].string));}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 148 "tsimb.y" /* yacc.c:1646  */
    {printf ("}}}\n");}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "tsimb.y" /* yacc.c:1646  */
    {printf ("var {\n");}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 152 "tsimb.y" /* yacc.c:1646  */
    {printf ("}\n");}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 156 "tsimb.y" /* yacc.c:1646  */
    {printf (";\n");}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 158 "tsimb.y" /* yacc.c:1646  */
    {printf ("int ");}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 159 "tsimb.y" /* yacc.c:1646  */
    {printf ("float ");}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 160 "tsimb.y" /* yacc.c:1646  */
    {printf ("char ");}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "tsimb.y" /* yacc.c:1646  */
    {printf ("logic ");}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "tsimb.y" /* yacc.c:1646  */
    {printf("void ");}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "tsimb.y" /* yacc.c:1646  */
    {printf (", ");}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "tsimb.y" /* yacc.c:1646  */
    {printf ("%s ", (yyvsp[0].string));}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "tsimb.y" /* yacc.c:1646  */
    {printf("[");}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "tsimb.y" /* yacc.c:1646  */
    {printf("]");}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 171 "tsimb.y" /* yacc.c:1646  */
    {printf ("%d", (yyvsp[0].valor));}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 172 "tsimb.y" /* yacc.c:1646  */
    {printf("%d, %d", (yyvsp[-2].valor), (yyvsp[0].valor));}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "tsimb.y" /* yacc.c:1646  */
    {printf("%d, %d, %d", (yyvsp[-4].valor), (yyvsp[-2].valor), (yyvsp[0].valor));}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "tsimb.y" /* yacc.c:1646  */
    {printf("(");}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "tsimb.y" /* yacc.c:1646  */
    {printf(")");}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 181 "tsimb.y" /* yacc.c:1646  */
    {printf("(");}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "tsimb.y" /* yacc.c:1646  */
    {printf(")");}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 184 "tsimb.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 192 "tsimb.y" /* yacc.c:1646  */
    {printf ("statements ");}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "tsimb.y" /* yacc.c:1646  */
    {printf ("{\n");}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 195 "tsimb.y" /* yacc.c:1646  */
    {printf ("}\n");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 200 "tsimb.y" /* yacc.c:1646  */
    {printf(";");}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 202 "tsimb.y" /* yacc.c:1646  */
    {printf("if ");}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 202 "tsimb.y" /* yacc.c:1646  */
    {printf("then ");}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 205 "tsimb.y" /* yacc.c:1646  */
    {printf("else ");}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 207 "tsimb.y" /* yacc.c:1646  */
    {printf("while ");}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 207 "tsimb.y" /* yacc.c:1646  */
    {printf("do ");}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 209 "tsimb.y" /* yacc.c:1646  */
    {printf("repeat ");}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 209 "tsimb.y" /* yacc.c:1646  */
    {printf("while ");}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 209 "tsimb.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 211 "tsimb.y" /* yacc.c:1646  */
    {printf("for ");}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 211 "tsimb.y" /* yacc.c:1646  */
    {printf("(");}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "tsimb.y" /* yacc.c:1646  */
    {printf(":");}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 211 "tsimb.y" /* yacc.c:1646  */
    {printf(":");}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 211 "tsimb.y" /* yacc.c:1646  */
    {printf(")");}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "tsimb.y" /* yacc.c:1646  */
    {printf("read(");}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 213 "tsimb.y" /* yacc.c:1646  */
    {printf(");\n");}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 216 "tsimb.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 218 "tsimb.y" /* yacc.c:1646  */
    {printf("write(");}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 218 "tsimb.y" /* yacc.c:1646  */
    {printf(");\n");}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 221 "tsimb.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 223 "tsimb.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].string));}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 226 "tsimb.y" /* yacc.c:1646  */
    {printf("call %s(", (yyvsp[-1].string));}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 226 "tsimb.y" /* yacc.c:1646  */
    {printf(");\n");}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 231 "tsimb.y" /* yacc.c:1646  */
    {printf("return;\n");}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 232 "tsimb.y" /* yacc.c:1646  */
    {printf("return ");}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 232 "tsimb.y" /* yacc.c:1646  */
    {printf(";\n");}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 234 "tsimb.y" /* yacc.c:1646  */
    {printf (":= ");}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 235 "tsimb.y" /* yacc.c:1646  */
    {printf (";\n");}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 238 "tsimb.y" /* yacc.c:1646  */
    {printf(", ");}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 240 "tsimb.y" /* yacc.c:1646  */
    {printf ("|| ");}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 242 "tsimb.y" /* yacc.c:1646  */
    {printf ("&& ");}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 244 "tsimb.y" /* yacc.c:1646  */
    {printf ("! ");}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 247 "tsimb.y" /* yacc.c:1646  */
    {
                        /*switch ($2) {
                            case LT: printf ("< "); break;
                            case LE: printf ("<= "); break;
                            case EQ: printf ("= "); break;
                            case NE: printf ("!= "); break;
                            case GT: printf ("> "); break;
                            case GE: printf (">= "); break;
                        }*/
						printf("%s ", (yyvsp[0].string));
                    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 260 "tsimb.y" /* yacc.c:1646  */
    {
                        /*switch ($2) {
                            case MAIS: printf ("+ "); break;
                            case MENOS: printf ("- "); break;
                        }*/
						printf("%s ", (yyvsp[0].string));
                    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 269 "tsimb.y" /* yacc.c:1646  */
    {
                        /*switch ($2) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case RESTO: printf ("%% "); break;
                        }*/
						printf("%s ", (yyvsp[0].string));
                    }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 279 "tsimb.y" /* yacc.c:1646  */
    {printf ("%d ", (yyvsp[0].valor));}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 280 "tsimb.y" /* yacc.c:1646  */
    {printf ("%g ", (yyvsp[0].valfloat));}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 281 "tsimb.y" /* yacc.c:1646  */
    {printf ("%s ", (yyvsp[0].string));}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 282 "tsimb.y" /* yacc.c:1646  */
    {printf ("true ");}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 283 "tsimb.y" /* yacc.c:1646  */
    {printf ("false ");}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 284 "tsimb.y" /* yacc.c:1646  */
    {printf ("~ ");}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 285 "tsimb.y" /* yacc.c:1646  */
    {printf ("( ");}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 285 "tsimb.y" /* yacc.c:1646  */
    {printf (") ");}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 288 "tsimb.y" /* yacc.c:1646  */
    {printf ("%s ", (yyvsp[0].string));}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 291 "tsimb.y" /* yacc.c:1646  */
    {printf("[");}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 291 "tsimb.y" /* yacc.c:1646  */
    {printf("]");}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 297 "tsimb.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 299 "tsimb.y" /* yacc.c:1646  */
    {printf(", ");}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 301 "tsimb.y" /* yacc.c:1646  */
    {printf("%s(",(yyvsp[-1].string));}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 301 "tsimb.y" /* yacc.c:1646  */
    {printf(")");}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2033 "y.tab.c" /* yacc.c:1646  */
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
#line 303 "tsimb.y" /* yacc.c:1906  */


/* Inclusao do analisador lexico  */

#include "lex.yy.c"

/*  InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
	int i;
	for (i = 0; i < NCLASSHASH; i++)
		tabsimb[i] = NULL;
}

/*
	ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia) {
	simbolo s; int i;
	i = hash (cadeia);
	for (s = tabsimb[i]; (s!=NULL) && strcmp(cadeia, s->cadeia);
		s = s->prox);
	return s;
}

/*
	InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador e com tvar como
	tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar) {
	int i; simbolo aux, s;
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->tid = tid;		s->tvar = tvar;
	s->inic = FALSO;	s->ref = FALSO;
	s->prox = aux;	return s;
}

/*
	hash (cadeia): funcao que determina e retorna a classe
	de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
	int i, h;
	for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}

/* ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
	int i; simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			printf ("Classe %d:\n", i);
			for (s = tabsimb[i]; s!=NULL; s = s->prox){
				printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
				if (s->tid == IDVAR)
					printf (", %s, %d, %d",
						nometipvar[s->tvar], s->inic, s->ref);
				printf(")\n");
			}
		}
}

/*  Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
    printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
    printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

