/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "src/part2.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode{
    char *token;
    struct treeNode *left;
    struct treeNode *middle;
    struct treeNode *right;
} treeNode;

typedef struct symbolNode{
	char* id;
	char* type;
	int data;
	struct symbolNode *next;
} symbolNode;


treeNode *mktreeNode (char *token, treeNode *left, treeNode* middle, treeNode *right);
void printtree (treeNode *tree, int tab);
#define YYSTYPE struct treeNode *
#line 44 "bin/y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define BOOL 257
#define CHAR 258
#define INT 259
#define STRING 260
#define INTPTR 261
#define CHARPTR 262
#define ID 263
#define VOID 264
#define QUOTES 265
#define NADA 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define FOR 270
#define DO 271
#define MAIN 272
#define RETURN 273
#define BOOLTRUE 274
#define BOOLFALSE 275
#define CSNULL 276
#define INTEGER_POS 277
#define INTEGER_NEG 278
#define CHAR_CONST 279
#define STRING_CONST 280
#define HEX_CONST 281
#define OCTAL_CONST 282
#define BINARY_CONST 283
#define ASSIGNMENT 284
#define AND 285
#define DIVISION 286
#define EQUAL 287
#define GREATER 288
#define GREATEREQUAL 289
#define LESS 290
#define LESSEQUAL 291
#define MINUS 292
#define NOT 293
#define NOTEQUAL 294
#define OR 295
#define PLUS 296
#define MULTI 297
#define ADDRESS 298
#define DEREFERENCE 299
#define ABSUOLUTE 300
#define SEMICOLON 301
#define COLON 302
#define COMMA 303
#define LEFTBRACE 304
#define RIGHTBRACE 305
#define LEFTPAREN 306
#define RIGHTPAREN 307
#define LEFTBRACKET 308
#define RIGHTBRACKET 309
#define PERCENT 310
#define LOWER_THAN_ELSE 311
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    4,    4,    3,    6,    5,
   10,    9,    9,   13,   13,   14,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   17,   19,   11,   11,    7,    7,    7,
   23,   23,   22,   21,   18,   18,   18,   18,   18,   18,
   18,    8,   24,   24,   24,   24,   24,   26,   25,   25,
   27,   28,   29,   30,   30,   31,   31,   16,   20,   20,
   20,   32,   33,   33,   35,   35,   35,   35,   35,   39,
   39,   36,   36,   41,   37,   37,   37,   42,   43,   44,
   45,   46,   46,   46,   47,   47,   48,   48,   40,   38,
   38,   49,   12,   12,   12,   12,   12,   50,   50,   50,
   50,   51,   51,   51,   51,   34,   34,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    2,    1,    1,    1,    5,    6,    5,
    2,    0,    1,    3,    1,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    2,
    1,    1,    1,    3,    1,    6,    5,    1,    5,    4,
    1,    3,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    4,    0,    1,    3,    1,    2,    2,    1,
    1,    2,    2,    1,    1,    1,    1,    2,    2,    1,
    1,    3,    4,    2,    1,    1,    1,    3,    4,    4,
    6,    0,    1,    1,    0,    1,    0,    1,    3,    3,
    3,    6,    1,    1,    1,    1,    1,    6,    1,    3,
    4,    3,    3,    1,    1,    2,    2,
};
static const YYINT yydefred[] = {                         0,
  103,  104,  105,  106,  107,    0,    0,    1,    0,    3,
    5,    6,    7,    0,    0,   52,    0,    0,    2,    4,
    0,   11,    0,    0,    0,    0,   13,    0,    0,    0,
    0,   16,    0,    0,    8,   38,    0,    0,   10,   14,
    0,    0,    0,    0,    0,    0,    0,    0,   44,   77,
    0,    0,    0,    0,   43,    0,    0,   70,    0,    0,
   75,   76,    0,   85,   86,   87,    9,    0,    0,    0,
    0,  117,    0,    0,    0,    0,    0,    0,   41,   81,
   80,    0,    0,   68,    0,    0,    0,    0,  116,    0,
    0,   78,   69,   72,   73,   79,   59,   60,   58,   54,
   53,   62,   61,   55,   56,   57,    0,    0,    0,    0,
    0,   31,   32,   33,   46,   47,   48,   49,   50,   51,
    0,    0,    0,    0,    0,   88,    0,    0,    0,   94,
    0,   35,    0,    0,    0,   40,    0,    0,    0,   65,
    0,    0,    0,    0,    0,   30,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  110,   99,    0,   83,    0,   90,   42,   89,
    0,   63,    0,  112,  113,   39,   34,    0,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   37,
    0,    0,   84,    0,    0,   66,   36,    0,    0,    0,
  102,  108,    0,   98,   91,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   10,   50,   12,   13,   35,  110,   25,   14,
   39,   15,   27,   28,  111,  112,  113,  114,  133,   54,
   55,   79,   80,  115,  116,  117,  118,  119,  120,  139,
  140,   57,   58,   59,   60,   61,   62,   63,   82,   74,
  166,   64,   65,   66,   77,  131,  195,  205,   71,   72,
   89,
};
static const YYINT yysindex[] = {                       -96,
    0,    0,    0,    0,    0, -190,    0,    0,  -96,    0,
    0,    0,    0, -283, -234,    0, -253, -246,    0,    0,
   33,    0, -230,   33, -222, -234,    0, -225, -223, -221,
 -215,    0,   33,  -62,    0,    0, -223,   56,    0,    0,
 -234, -234, -214, -214, -211,    4, -203, -234,    0,    0,
 -276, -256, -183, -164,    0, -189,   73,    0, -188,   89,
    0,    0, -186,    0,    0,    0,    0,    6, -157, -182,
 -174,    0,    6,    4,    4,    6, -168,  -45,    0,    0,
    0, -144, -158,    0,    6,  215, -245, -162,    0,    6,
 -153,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    6, -234,    6, -156,
  301,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6, -178, -234,  104, -116,    0, -276,  -39, -183,    0,
 -143,    0,    4, -158, -214,    0,  -39, -146, -147,    0,
 -256, -256,  -39, -158,  -39,    0,  104,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6, -158,
  318, -142,    0,    0,    4,    0,    6,    0,    0,    0,
  215,    0, -245,    0,    0,    0,    0, -273,    0, -141,
 -141, -141, -141, -141, -273, -141, -273, -273,    0,    0,
 -158, -219,    0,  -39, -117,    0,    0,  -98, -234, -256,
    0,    0,  -97,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -121,    0,    0, -121,    0,    0,    0, -115,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -229,    0,    0, -226,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -111,    0,    0,    0,    0, -189,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -104, -290,  -95,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -29,    0,  335,  -91,  352,    0,
    0,    0,    0,    0,    0,    0, -170, -103,    0,    0,
    0,    0, -169,    0, -118,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -81,    0,    0,    0,
    0,    0,  -80,    0,    0,    0,    0,  118,    0,  212,
  220,  241,  249,  270,  139,  278,  160,  181,    0,    0,
    0,  -78,    0, -186,    0,    0,    0,    0,    0,  -76,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  182,   74,    0,    0,  190,   -6,  221,    0,
    0,   86,  203,    0,   21,  -19,    0,  -83, -110,  -26,
  -73,   38,    0,  117,    0,    0,   61,    0,  -12,    0,
   93,    0,  217,    0,  -25,    0,    0,  -51,  -69,  -42,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -119,
 -124,
};
#define YYTABLESIZE 653
static const YYINT yytable[] = {                         18,
   88,   75,  138,  163,  125,  126,   16,   85,   22,  136,
  115,   69,  149,  164,   53,   11,  174,  175,   53,   32,
   81,   56,   21,  159,  130,   56,   53,   51,   16,   86,
   93,   51,   53,   56,   70,   18,  177,   53,   85,   51,
   53,   84,   48,   71,   56,   87,   74,   56,   81,   81,
   51,  134,   23,   51,   53,   53,  129,  141,   53,   24,
  169,   56,   56,  168,  198,   56,   36,   51,   51,  127,
  176,   51,   16,   11,   36,   71,   29,   33,   74,  202,
   34,   17,   20,  199,   31,   37,  190,  138,   38,   88,
   88,   73,  170,  124,   76,  193,  128,   83,  100,  101,
   90,  146,  104,  105,  106,  137,   26,   81,   91,   26,
  143,   92,   94,   53,   96,  121,   70,  197,   26,   52,
   56,   53,   53,   52,  135,  122,   51,  145,  123,  147,
  100,  101,  100,  101,  173,  173,  100,  101,  132,   81,
  142,  161,   52,  148,  149,   53,   49,  144,  204,   86,
  155,  165,   56,  157,  158,  159,  171,  167,   51,  172,
    1,    2,    3,   52,    4,    5,  192,    6,  178,  179,
  180,  181,  182,  183,  184,  185,  186,  187,  188,  189,
   53,  103,   29,  200,   29,   12,   85,  194,   29,  109,
   19,   15,   70,  203,    1,    2,    3,   41,    4,    5,
   16,   42,   64,   67,   43,  114,   44,   45,   46,   93,
   47,    1,    2,    3,   41,    4,    5,   16,   42,   95,
  115,   43,  111,   44,   45,   46,   67,   82,   82,   82,
   97,   82,   82,   82,   82,   40,   48,   82,  162,   82,
   82,   82,   49,   82,   30,  148,  149,  150,  151,  152,
  153,  154,  155,   48,  156,  157,  158,  159,  201,   49,
    1,    2,    3,  196,    4,    5,   16,   42,   16,   82,
   43,    0,   44,   45,   46,   82,   95,    0,    0,   97,
   98,   99,  100,  101,  102,  103,  104,  105,  106,    1,
    2,    3,    0,    4,    5,    0,    0,    0,  107,    0,
    0,    0,   48,  108,   48,    0,    0,   78,    0,    0,
    0,  109,    1,    2,    3,   41,    4,    5,   16,   42,
    0,    0,   43,    0,   44,   45,   46,    0,   68,    1,
    2,    3,   41,    4,    5,   16,   42,    0,    0,   43,
    0,   44,   45,   46,    0,    1,    2,    3,    0,    4,
    5,   16,   42,    0,   48,   43,    0,   44,   45,   46,
    0,    0,    0,   45,   45,   45,   45,   45,   45,   45,
   45,   48,   45,   45,   45,   45,    0,    0,    0,   45,
    0,   45,    0,    0,    0,   45,    0,   48,  148,  149,
  150,  151,  152,  153,  154,  155,    0,  156,  157,  158,
  159,    0,   27,    0,   27,   27,   27,   27,   27,   27,
  132,   27,   27,   27,    0,    0,    0,    0,   27,    0,
   27,    0,    0,   18,   27,   18,   18,   18,   18,   18,
   18,    0,   18,   18,   18,    0,    0,    0,    0,   18,
    0,   18,    0,    0,   28,   18,   28,   28,   28,   28,
   28,   28,    0,   28,   28,   28,    0,    0,    0,    0,
   28,    0,   28,    0,    0,   17,   28,   17,   17,   17,
   17,   17,   17,    0,   17,   17,   17,   16,    0,    0,
    0,   17,    0,   17,    0,    0,    0,   17,   97,   98,
   99,  100,  101,  102,  103,  104,  105,  106,   21,   21,
   21,   21,   21,    0,    0,   21,   22,   22,   22,   22,
   22,    0,   21,   22,   21,    0,    0,    0,   21,    0,
   22,    0,   22,    0,    0,    0,   22,   23,   23,   23,
   23,   23,    0,    0,   23,   24,   24,   24,   24,   24,
    0,   23,   24,   23,    0,    0,    0,   23,    0,   24,
    0,   24,    0,    0,    0,   24,   25,   25,   25,   25,
   25,    0,    0,   25,   26,   26,   26,   26,   26,    0,
   25,   26,   25,    0,    0,    0,   25,    0,   26,    0,
   26,    0,    0,    0,   26,  148,  149,  150,  151,  152,
  153,  154,  155,    0,  156,  157,  158,  159,    0,    0,
    0,  160,  148,  149,  150,  151,  152,  153,  154,  155,
    0,  156,  157,  158,  159,    0,    0,    0,  191,   45,
   45,   45,   45,   45,   45,   45,   45,    0,   45,   45,
   45,   45,    0,    0,    0,   45,   31,   31,   31,   31,
   31,   31,   31,   31,    0,   31,   31,   31,   31,    0,
    0,    0,   31,
};
static const YYINT yycheck[] = {                          6,
   52,   44,   86,  123,   74,   75,  263,  284,   15,   83,
  301,   38,  286,  124,   34,  306,  141,  142,   38,   26,
   46,   34,  306,  297,   76,   38,   46,   34,  263,  306,
   57,   38,   52,   46,   41,   42,  147,   57,  284,   46,
   60,   48,  299,  273,   57,   52,  273,   60,   74,   75,
   57,   78,  306,   60,   74,   75,   76,  303,   78,  306,
  134,   74,   75,  133,  284,   78,   29,   74,   75,   76,
  144,   78,  263,    0,   37,  305,  307,  303,  305,  199,
  304,  272,    9,  303,  307,  307,  160,  171,  304,  141,
  142,  306,  135,   73,  306,  165,   76,  301,  277,  278,
  284,  108,  281,  282,  283,   85,   21,  133,  273,   24,
   90,  301,  301,  133,  301,  273,  123,  191,   33,   34,
  133,  141,  142,   38,  269,  308,  133,  107,  303,  109,
  301,  301,  303,  303,  141,  142,  307,  307,  307,  165,
  303,  121,   57,  285,  286,  165,  305,  301,  200,  306,
  292,  268,  165,  295,  296,  297,  303,  301,  165,  307,
  257,  258,  259,   78,  261,  262,  309,  264,  148,  149,
  150,  151,  152,  153,  154,  155,  156,  157,  158,  159,
  200,  280,  301,  301,  303,  307,  284,  167,  307,  301,
    9,  307,  199,  200,  257,  258,  259,  260,  261,  262,
  263,  264,  307,  307,  267,  301,  269,  270,  271,  301,
  273,  257,  258,  259,  260,  261,  262,  263,  264,  301,
  301,  267,  301,  269,  270,  271,   37,  257,  258,  259,
  307,  261,  262,  263,  264,   33,  299,  267,  122,  269,
  270,  271,  305,  273,   24,  285,  286,  287,  288,  289,
  290,  291,  292,  299,  294,  295,  296,  297,  198,  305,
  257,  258,  259,  171,  261,  262,  263,  264,  263,  299,
  267,   -1,  269,  270,  271,  305,   60,   -1,   -1,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  257,
  258,  259,   -1,  261,  262,   -1,   -1,   -1,  293,   -1,
   -1,   -1,  299,  298,  299,   -1,   -1,  304,   -1,   -1,
   -1,  306,  257,  258,  259,  260,  261,  262,  263,  264,
   -1,   -1,  267,   -1,  269,  270,  271,   -1,  273,  257,
  258,  259,  260,  261,  262,  263,  264,   -1,   -1,  267,
   -1,  269,  270,  271,   -1,  257,  258,  259,   -1,  261,
  262,  263,  264,   -1,  299,  267,   -1,  269,  270,  271,
   -1,   -1,   -1,  285,  286,  287,  288,  289,  290,  291,
  292,  299,  294,  295,  296,  297,   -1,   -1,   -1,  301,
   -1,  303,   -1,   -1,   -1,  307,   -1,  299,  285,  286,
  287,  288,  289,  290,  291,  292,   -1,  294,  295,  296,
  297,   -1,  285,   -1,  287,  288,  289,  290,  291,  292,
  307,  294,  295,  296,   -1,   -1,   -1,   -1,  301,   -1,
  303,   -1,   -1,  285,  307,  287,  288,  289,  290,  291,
  292,   -1,  294,  295,  296,   -1,   -1,   -1,   -1,  301,
   -1,  303,   -1,   -1,  285,  307,  287,  288,  289,  290,
  291,  292,   -1,  294,  295,  296,   -1,   -1,   -1,   -1,
  301,   -1,  303,   -1,   -1,  285,  307,  287,  288,  289,
  290,  291,  292,   -1,  294,  295,  296,  263,   -1,   -1,
   -1,  301,   -1,  303,   -1,   -1,   -1,  307,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  287,  288,
  289,  290,  291,   -1,   -1,  294,  287,  288,  289,  290,
  291,   -1,  301,  294,  303,   -1,   -1,   -1,  307,   -1,
  301,   -1,  303,   -1,   -1,   -1,  307,  287,  288,  289,
  290,  291,   -1,   -1,  294,  287,  288,  289,  290,  291,
   -1,  301,  294,  303,   -1,   -1,   -1,  307,   -1,  301,
   -1,  303,   -1,   -1,   -1,  307,  287,  288,  289,  290,
  291,   -1,   -1,  294,  287,  288,  289,  290,  291,   -1,
  301,  294,  303,   -1,   -1,   -1,  307,   -1,  301,   -1,
  303,   -1,   -1,   -1,  307,  285,  286,  287,  288,  289,
  290,  291,  292,   -1,  294,  295,  296,  297,   -1,   -1,
   -1,  301,  285,  286,  287,  288,  289,  290,  291,  292,
   -1,  294,  295,  296,  297,   -1,   -1,   -1,  301,  285,
  286,  287,  288,  289,  290,  291,  292,   -1,  294,  295,
  296,  297,   -1,   -1,   -1,  301,  285,  286,  287,  288,
  289,  290,  291,  292,   -1,  294,  295,  296,  297,   -1,
   -1,   -1,  301,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 311
#define YYUNDFTOKEN 365
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BOOL","CHAR","INT","STRING",
"INTPTR","CHARPTR","ID","VOID","QUOTES","NADA","IF","ELSE","WHILE","FOR","DO",
"MAIN","RETURN","BOOLTRUE","BOOLFALSE","CSNULL","INTEGER_POS","INTEGER_NEG",
"CHAR_CONST","STRING_CONST","HEX_CONST","OCTAL_CONST","BINARY_CONST",
"ASSIGNMENT","AND","DIVISION","EQUAL","GREATER","GREATEREQUAL","LESS",
"LESSEQUAL","MINUS","NOT","NOTEQUAL","OR","PLUS","MULTI","ADDRESS",
"DEREFERENCE","ABSUOLUTE","SEMICOLON","COLON","COMMA","LEFTBRACE","RIGHTBRACE",
"LEFTPAREN","RIGHTPAREN","LEFTBRACKET","RIGHTBRACKET","PERCENT",
"LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : global",
"global : procedures procMain",
"global : procMain",
"procedures : procedures proc",
"procedures : proc",
"proc : procValue",
"proc : procVoid",
"procMain : VOID MAIN LEFTPAREN RIGHTPAREN block_return_void_statements",
"procVoid : VOID id LEFTPAREN params RIGHTPAREN block_return_void_statements",
"procValue : procID LEFTPAREN params RIGHTPAREN block_return_value_statements",
"procID : varType id",
"params :",
"params : paramsDeclare",
"paramsDeclare : param COMMA paramsDeclare",
"paramsDeclare : param",
"param : varType id",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MULTI expr",
"expr : expr DIVISION expr",
"expr : expr EQUAL expr",
"expr : expr GREATER expr",
"expr : expr GREATEREQUAL expr",
"expr : expr LESS expr",
"expr : expr LESSEQUAL expr",
"expr : expr NOTEQUAL expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
"expr : ADDRESS id",
"expr : derefID",
"expr : Pexpr",
"expr : consts",
"Pexpr : LEFTPAREN expr rightParen",
"rightParen : RIGHTPAREN",
"block_return_value_statements : LEFTBRACE newline RETURN expr SEMICOLON rightbrace",
"block_return_value_statements : LEFTBRACE RETURN expr SEMICOLON rightbrace",
"block_return_void_statements : emptyBlock",
"block_return_void_statements : LEFTBRACE newline RETURN SEMICOLON rightbrace",
"block_return_void_statements : LEFTBRACE RETURN SEMICOLON rightbrace",
"block_statements : emptyBlock",
"block_statements : LEFTBRACE newline rightbrace",
"emptyBlock : LEFTBRACE rightbrace",
"rightbrace : RIGHTBRACE",
"consts : id",
"consts : numbers",
"consts : booleans",
"consts : csnull",
"consts : strings",
"consts : chars",
"consts : procCall",
"id : ID",
"numbers : INTEGER_NEG",
"numbers : INTEGER_POS",
"numbers : HEX_CONST",
"numbers : OCTAL_CONST",
"numbers : BINARY_CONST",
"csnull : CSNULL",
"booleans : BOOLTRUE",
"booleans : BOOLFALSE",
"strings : STRING_CONST",
"chars : CHAR_CONST",
"procCall : id LEFTPAREN args RIGHTPAREN",
"args :",
"args : argsDeclare",
"argsDeclare : consts COMMA argsDeclare",
"argsDeclare : consts",
"derefID : DEREFERENCE id",
"newline : declarations newline",
"newline : statements",
"newline : declarations",
"declarations : variable_declare_statements SEMICOLON",
"statements : statement statements",
"statements : statement",
"statement : IF_statements",
"statement : LOOP_statements",
"statement : proc",
"statement : procCall SEMICOLON",
"statement : ASSIGNMENT_statement SEMICOLON",
"statements_type : statement",
"statements_type : block_statements",
"IF_statements : IF cond statements_type",
"IF_statements : IF cond statements_type else",
"else : ELSE statements_type",
"LOOP_statements : while",
"LOOP_statements : whileDO",
"LOOP_statements : for",
"while : WHILE cond statements_type",
"whileDO : DO statements_type WHILE cond",
"for : FOR for_cond rightParen statements_type",
"for_cond : LEFTPAREN preCondition SEMICOLON postCondition SEMICOLON iteration",
"preCondition :",
"preCondition : expr",
"preCondition : ASSIGNMENT_statement",
"postCondition :",
"postCondition : expr",
"iteration :",
"iteration : ASSIGNMENT_statement",
"cond : LEFTPAREN expr rightParen",
"ASSIGNMENT_statement : id ASSIGNMENT expr",
"ASSIGNMENT_statement : derefID ASSIGNMENT expr",
"str_ASSIGNMENT_statement : id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT strings",
"varType : BOOL",
"varType : CHAR",
"varType : INT",
"varType : INTPTR",
"varType : CHARPTR",
"StringDeclare : id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare",
"StringDeclare : str_ASSIGNMENT_statement",
"StringDeclare : str_ASSIGNMENT_statement COMMA StringDeclare",
"StringDeclare : id LEFTBRACKET numbers RIGHTBRACKET",
"variablesDeclare : id COMMA variablesDeclare",
"variablesDeclare : ASSIGNMENT_statement COMMA variablesDeclare",
"variablesDeclare : ASSIGNMENT_statement",
"variablesDeclare : id",
"variable_declare_statements : varType variablesDeclare",
"variable_declare_statements : STRING StringDeclare",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 217 "src/part2.y"

#include "lex.yy.c"
int main(){
    return yyparse();
}

treeNode *mktreeNode    (char *token, treeNode *left, treeNode* middle, treeNode *right){
    treeNode *newtreeNode = (treeNode*)malloc (sizeof(treeNode));
    char    *newstr = (char*)malloc (sizeof(token)+1);
    strcpy (newstr, token);
    newtreeNode -> left = left;
    newtreeNode -> right = right;
    newtreeNode -> middle = middle;
    newtreeNode -> token = newstr;
    return newtreeNode;
}

void printtree (treeNode *tree, int tab){
    int i; 
    for (i = 0; i< tab; i++)
        printf ("\t");
    char* token = tree->token;
/*     if (strlen(token) > 0) */
        printf ("[%s]\n", token);
    if (tree -> left)
        printtree (tree-> left, tab + 1);
    if (tree -> middle)
        printtree (tree-> middle, tab + 1);     
    if (tree -> right)
        printtree (tree-> right, tab + 1); 
}
int yyerror(char* s){
    printf ("%s: at line %d found token [%s]\n",  s,counter, yytext);
    return 0;
}


// A complete working C program to delete a node in a linked list
// at a given position



/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct symbolNode** head_ref, char* id, char* type, int new_data)
{
	struct symbolNode* new_node = (struct symbolNode*) malloc(sizeof(struct symbolNode));
	new_node->data = new_data;
	new_node->id = (char*)(malloc (sizeof(id) + 1));
	strncpy(new_node->id, id, sizeof(id)+1);
	
	new_node->type = (char*)(malloc (sizeof(type) + 1));
	strncpy(new_node->type, type, sizeof(type)+1);
	
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position */
void deletesymbolNode(struct symbolNode **head_ref, int position)
{
// If linked list is empty
if (*head_ref == NULL)
	return;

// Store head node
struct symbolNode* temp = *head_ref;

	// If head needs to be removed
	if (position == 0)
	{
		*head_ref = temp->next; // Change head
		free(temp->id);
		free(temp);			 // free old head
		return;
	}

	// Find previous node of the node to be deleted
	for (int i=0; temp!=NULL && i<position-1; i++)
		temp = temp->next;

	// If position is more than number of ndoes
	if (temp == NULL || temp->next == NULL)
		return;

	// symbolNode temp->next is the node to be deleted
	// Store pointer to the next of node to be deleted
	struct symbolNode *next = temp->next->next;

	// Unlink the node from linked list
	// Free memory
	free(temp->id);
	free(temp->type);
	free(temp->next); 

	temp->next = next; // Unlink the deleted node from list
}

// This function prints contents of linked list starting from
// the given node
void printList(struct symbolNode *node)
{
	while (node != NULL)
	{
		printf("id:{%s}, type:{%s}, data{%d} \n", node->id, node->type, node->data);
		node = node->next;
	}
}

struct symbolNode* head = NULL;

/* Drier program to test above functions*/
int main2()
{
	/* Start with the empty list */
	

	push(&head, "a", "int", 7);
	push(&head, "b", "float", 1);
	push(&head, "c", "char", 3);
	push(&head, "d1", "string", 2);
	push(&head, "e23", "bool", 8);

	puts("Created Linked List: ");
	printList(head);
	deletesymbolNode(&head, 4);
	puts("\nLinked List after Deletion at position 4: ");
	printList(head);
	return 0;
}

#line 706 "bin/y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 40 "src/part2.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 2:
#line 41 "src/part2.y"
	{yyval = mktreeNode ("global", yystack.l_mark[-1],NULL,yystack.l_mark[0]); }
break;
case 3:
#line 42 "src/part2.y"
	{yyval = mktreeNode ("global", yystack.l_mark[0],NULL,NULL); }
break;
case 4:
#line 46 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-1],NULL, NULL); }
break;
case 5:
#line 47 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 8:
#line 50 "src/part2.y"
	{yyval = mktreeNode ("main", yystack.l_mark[0],NULL, NULL); }
break;
case 9:
#line 51 "src/part2.y"
	{yyval = mktreeNode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 10:
#line 52 "src/part2.y"
	{yyval = mktreeNode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 11:
#line 53 "src/part2.y"
	{yyval = mktreeNode ("procID", yystack.l_mark[-1], yystack.l_mark[0], NULL); }
break;
case 13:
#line 59 "src/part2.y"
	{yyval = mktreeNode ("params:", yystack.l_mark[0], NULL, NULL); }
break;
case 14:
#line 60 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 64 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 69 "src/part2.y"
	{yyval = mktreeNode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 70 "src/part2.y"
	{yyval = mktreeNode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 71 "src/part2.y"
	{yyval = mktreeNode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 72 "src/part2.y"
	{yyval = mktreeNode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 73 "src/part2.y"
	{ yyval = mktreeNode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 74 "src/part2.y"
	{ yyval = mktreeNode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 75 "src/part2.y"
	{ yyval = mktreeNode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 24:
#line 76 "src/part2.y"
	{ yyval = mktreeNode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 25:
#line 77 "src/part2.y"
	{ yyval = mktreeNode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 26:
#line 78 "src/part2.y"
	{ yyval = mktreeNode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 27:
#line 79 "src/part2.y"
	{yyval = mktreeNode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 28:
#line 80 "src/part2.y"
	{yyval = mktreeNode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 29:
#line 81 "src/part2.y"
	{yyval = mktreeNode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 30:
#line 82 "src/part2.y"
	{yyval = mktreeNode ("&", yystack.l_mark[0], NULL,NULL ); }
break;
case 34:
#line 89 "src/part2.y"
	{yyval = mktreeNode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 35:
#line 90 "src/part2.y"
	{yyval = mktreeNode (")", NULL, NULL, NULL); }
break;
case 36:
#line 91 "src/part2.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 37:
#line 92 "src/part2.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 39:
#line 94 "src/part2.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-3], NULL, yystack.l_mark[-1]); }
break;
case 40:
#line 95 "src/part2.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 42:
#line 98 "src/part2.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 43:
#line 102 "src/part2.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[0], NULL, NULL); }
break;
case 44:
#line 103 "src/part2.y"
	{yyval = mktreeNode (")", NULL, NULL,NULL ); }
break;
case 52:
#line 111 "src/part2.y"
	{yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 53:
#line 113 "src/part2.y"
	{yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 54:
#line 114 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 55:
#line 115 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 56:
#line 116 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 57:
#line 117 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 58:
#line 118 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 59:
#line 119 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 60:
#line 120 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 61:
#line 121 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 62:
#line 122 "src/part2.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 63:
#line 123 "src/part2.y"
	{ yyval = mktreeNode ("func call", yystack.l_mark[-3], NULL, yystack.l_mark[-1]); }
break;
case 65:
#line 126 "src/part2.y"
	{yyval = mktreeNode ("args:", yystack.l_mark[0], NULL, NULL); }
break;
case 66:
#line 127 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 68:
#line 131 "src/part2.y"
	{char* t = yystack.l_mark[0]->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); yyval = mktreeNode (s,NULL, NULL, NULL); }
break;
case 69:
#line 134 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 73:
#line 144 "src/part2.y"
	{yyval = mktreeNode ("STATEMENT", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 82:
#line 158 "src/part2.y"
	{yyval = mktreeNode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 83:
#line 159 "src/part2.y"
	{yyval = mktreeNode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 84:
#line 161 "src/part2.y"
	{yyval = mktreeNode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 88:
#line 167 "src/part2.y"
	{yyval=mktreeNode("while", yystack.l_mark[-1],NULL, yystack.l_mark[0]);}
break;
case 89:
#line 168 "src/part2.y"
	{yyval=mktreeNode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 90:
#line 170 "src/part2.y"
	{yyval=mktreeNode("for", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]);}
break;
case 91:
#line 172 "src/part2.y"
	{yyval=mktreeNode("for conditions:", yystack.l_mark[-4],yystack.l_mark[-2], yystack.l_mark[0]);}
break;
case 99:
#line 179 "src/part2.y"
	{yyval = mktreeNode ("(COND", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 100:
#line 183 "src/part2.y"
	{yyval = mktreeNode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 101:
#line 184 "src/part2.y"
	{yyval = mktreeNode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 102:
#line 185 "src/part2.y"
	{yyval = mktreeNode ("=", yystack.l_mark[-5], NULL, yystack.l_mark[0]); }
break;
case 103:
#line 190 "src/part2.y"
	{yyval = mktreeNode ("boolean", NULL, NULL, NULL); }
break;
case 104:
#line 191 "src/part2.y"
	{yyval = mktreeNode ("char", NULL, NULL, NULL); }
break;
case 105:
#line 192 "src/part2.y"
	{yyval = mktreeNode ("integer", NULL, NULL, NULL); }
break;
case 106:
#line 194 "src/part2.y"
	{yyval = mktreeNode ("intptr", NULL, NULL, NULL); }
break;
case 107:
#line 195 "src/part2.y"
	{yyval = mktreeNode ("charptr", NULL, NULL, NULL); }
break;
case 108:
#line 201 "src/part2.y"
	{yyval = mktreeNode ("STRING", yystack.l_mark[-5], NULL, yystack.l_mark[0]); }
break;
case 109:
#line 202 "src/part2.y"
	{yyval = mktreeNode ("STRING", yystack.l_mark[0], NULL,NULL); }
break;
case 110:
#line 203 "src/part2.y"
	{yyval = mktreeNode ("STRING", yystack.l_mark[-2],yystack.l_mark[0], NULL); }
break;
case 111:
#line 204 "src/part2.y"
	{yyval = mktreeNode ("STRING", yystack.l_mark[-3],NULL, NULL); }
break;
case 112:
#line 207 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 113:
#line 208 "src/part2.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 116:
#line 212 "src/part2.y"
	{yyval = mktreeNode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 117:
#line 213 "src/part2.y"
	{yyval = mktreeNode ("DECLARE", yystack.l_mark[0], NULL, NULL); }
break;
#line 1212 "bin/y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
