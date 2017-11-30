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

#line 2 "src/part1.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *token;
    struct node *left;
    struct node *middle;
    struct node *right;
} node;

node *mknode (char *token, node *left, node* middle, node *right);
void printtree (node *tree, int tab);
#define YYSTYPE struct node *
#line 36 "bin/y.tab.c"

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
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define DO 269
#define MAIN 270
#define RETURN 271
#define BOOLTRUE 272
#define BOOLFALSE 273
#define CSNULL 274
#define INTEGER_POS 275
#define INTEGER_NEG 276
#define CHAR_CONST 277
#define STRING_CONST 278
#define HEX_CONST 279
#define OCTAL_CONST 280
#define BINARY_CONST 281
#define ASSIGNMENT 282
#define AND 283
#define DIVISION 284
#define EQUAL 285
#define GREATER 286
#define GREATEREQUAL 287
#define LESS 288
#define LESSEQUAL 289
#define MINUS 290
#define NOT 291
#define NOTEQUAL 292
#define OR 293
#define PLUS 294
#define MULTI 295
#define ADDRESS 296
#define DEREFERENCE 297
#define ABSUOLUTE 298
#define SEMICOLON 299
#define COLON 300
#define COMMA 301
#define LEFTBRACE 302
#define RIGHTBRACE 303
#define LEFTPAREN 304
#define RIGHTPAREN 305
#define LEFTBRACKET 306
#define RIGHTBRACKET 307
#define PERCENT 308
#define LOWER_THAN_ELSE 309
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    2,    3,    3,    7,    7,    9,    9,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   12,   15,    4,   16,   13,
   13,    6,   17,   17,   10,   10,   10,   10,   10,   22,
   22,   18,   18,   24,   19,   19,   19,   23,   20,   20,
   14,   21,    5,    5,    8,    8,    8,    8,    8,    8,
   25,   25,   25,   25,
};
static const YYINT yylen[] = {                            2,
    1,    5,    2,    0,    1,    4,    2,    2,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    1,    1,    1,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    4,    2,    3,    3,    4,    1,    1,    1,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   55,   56,   57,   58,   59,   60,   53,    0,    1,    0,
    0,   54,    0,   32,    3,    0,    0,    0,    0,    0,
    7,    0,    2,    0,    0,    0,    0,    0,   49,   50,
   39,    0,    0,    9,   35,   36,   37,   38,    6,   34,
   33,    0,    0,    0,    0,   23,   24,   25,   31,    0,
    0,    0,   41,   40,    0,    0,   63,    0,   29,    8,
   28,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   45,   46,    0,
   52,    0,   27,   26,    0,    0,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   12,    0,   43,   47,
    0,   62,   44,
};
static const YYINT yydgoto[] = {                          8,
    9,   10,   16,   53,   11,   44,   17,   32,   33,   54,
   45,   46,   47,   48,   84,   61,   49,   35,   36,   37,
   38,   55,   50,   99,   58,
};
static const YYINT yysindex[] = {                      -124,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -299,
 -255,    0,  -78,    0,    0, -293, -269, -255, -254,  -78,
    0,  466,    0, -255, -172, -172, -172,  430,    0,    0,
    0, -255,  380,    0,    0,    0,    0,    0,    0,    0,
    0, -172, -172, -246,  488,    0,    0,    0,    0,  430,
  430,  430,    0,    0, -213, -246,    0, -295,    0,    0,
    0,  488,  474, -172, -172, -172, -172, -172, -172, -172,
 -172, -172, -172, -172, -172, -172, -189,    0,    0, -172,
    0, -255,    0,    0,  488, -264,    0, -256, -256, -256,
 -256, -256, -264, -256, -264, -264,    0,  430,    0,    0,
 -246,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -227,    0,    0,    0, -223,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -243,  363,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -266,    0,    0,    0,    0,
    0,  297,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  413,    0,    0,    0,
    0,    0,    0,    0,  314, -193,    0,    3,   52,  101,
  150,  199, -144,  248,  -95,  -46,    0,    0,    0,    0,
 -238,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   64,    0,  -11,    0,   85,    0,   48,
  676,    0,    0,  -29,    0,    0,    0,    0,    0,    0,
    0,  -41,  -25,    0,    0,
};
#define YYTABLESIZE 783
static const YYINT yytable[] = {                         15,
   51,   52,   57,   81,   13,   82,   21,   14,   77,   78,
   79,   19,   39,   30,   30,   30,   30,   30,   30,   66,
   56,   30,   30,   30,   30,   30,   65,   66,   30,   30,
   76,   20,   64,   72,   64,   64,   74,   75,   76,   30,
   30,   30,   30,   30,   30,   30,   30,   22,   30,   30,
   30,   30,  102,   80,  100,   30,  103,   30,   30,   30,
   61,   30,   61,   20,   20,   20,   20,   20,   20,   34,
  101,   20,   20,   20,   20,   20,   98,    4,   20,   20,
   60,    5,   23,    0,   12,    0,    0,    0,    0,   20,
   14,   20,   20,   20,   20,   20,   20,   18,   20,   20,
   20,    0,   40,   41,   24,   20,    0,   20,   20,   20,
    0,   20,   11,   11,   11,   11,   11,   11,   42,    0,
   11,   11,   11,   11,   11,    0,    0,   11,   11,    0,
    0,   43,    1,    2,    3,    4,    5,    6,   11,    7,
   11,   11,   11,   11,   11,   11,    0,   11,   11,   11,
    0,    0,    0,    0,   11,    0,   11,   11,   11,    0,
   11,   21,   21,   21,   21,   21,   21,    0,    0,   21,
   21,   21,   21,   21,    0,    0,   21,   21,    1,    2,
    3,    4,    5,    6,    0,    0,    0,   21,    0,   21,
   21,   21,   21,   21,   21,    0,   21,   21,   21,    0,
    0,    0,    0,   21,    0,   21,   21,   21,    0,   21,
   10,   10,   10,   10,   10,   10,    0,    0,   10,   10,
   10,   10,   10,    0,    0,   10,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,    0,   10,   10,
   10,   10,   10,   10,    0,   10,   10,   10,    0,    0,
    0,    0,   10,    0,   10,   10,   10,    0,   10,   14,
   14,   14,   14,   14,   14,    0,    0,   14,   14,   14,
   14,   14,    0,    0,   14,   14,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   14,   14,   14,
   14,   14,    0,    0,   14,    0,    0,    0,    0,    0,
    0,   14,    0,   14,   14,   14,    0,   14,   15,   15,
   15,   15,   15,   15,    0,    0,   15,   15,   15,   15,
   15,    0,    0,   15,   15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,   15,   15,   15,
   15,    0,    0,   15,    0,    0,    0,    0,    0,    0,
   15,    0,   15,   15,   15,    0,   15,   16,   16,   16,
   16,   16,   16,    0,    0,   16,   16,   16,   16,   16,
    0,    0,   16,   16,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   16,   16,   16,   16,   16,
    0,    0,   16,    0,    0,    0,    0,    0,    0,   16,
    0,   16,   16,   16,    0,   16,   17,   17,   17,   17,
   17,   17,    0,    0,   17,   17,   17,   17,   17,    0,
    0,   17,   17,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   17,   17,   17,   17,   17,    0,
    0,   17,    0,    0,    0,    0,    0,    0,   17,    0,
   17,   17,   17,    0,   17,   18,   18,   18,   18,   18,
   18,    0,    0,   18,   18,   18,   18,   18,    0,    0,
   18,   18,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,   18,   18,   18,   18,    0,    0,
   18,    0,    0,    0,    0,    0,    0,   18,    0,   18,
   18,   18,    0,   18,   19,   19,   19,   19,   19,   19,
    0,    0,   19,   19,   19,   19,   19,    0,    0,   19,
   19,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   19,   19,   19,   19,   19,    0,    0,   19,
    0,    0,    0,    0,    0,    0,   19,    0,   19,   19,
   19,    0,   19,   22,   22,   22,   22,   22,   22,    0,
    0,   22,   22,   22,   22,   22,    0,    0,   22,   22,
   51,   51,   51,   51,   51,   51,    0,    0,   51,   51,
   51,   51,   51,    0,    0,   51,   51,    0,    0,    0,
    0,    0,    0,    0,    0,   22,    0,   22,   22,   22,
    0,   22,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   51,    0,   51,   51,   51,    0,   51,   48,
   48,   48,   48,   48,   48,    0,    0,   48,   48,   48,
   48,   48,    0,    0,   48,   48,    1,    2,    3,    4,
    5,    6,    0,    0,   25,    0,   26,   27,   28,    0,
    0,   29,   30,    0,    0,    0,    0,    0,    0,    0,
    0,   48,    0,    0,   48,   48,    0,    0,    0,   42,
   42,   42,   42,   42,   42,    0,    0,   42,   31,   42,
   42,   42,   59,    0,   42,   42,    1,    2,    3,    4,
    5,    6,    0,    0,   25,    0,   26,   27,   28,    0,
    0,   29,   30,    0,    0,    0,    0,    0,    0,    0,
    0,   42,    0,    0,    0,   42,    0,   62,   63,    0,
    0,    0,    1,    2,    3,    4,    5,    6,   31,    0,
   25,   22,   26,   27,   28,    0,    0,   29,   30,   85,
   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,    0,    0,    0,    0,   65,   66,   67,   68,
   69,   70,   71,   72,   31,   73,   74,   75,   76,    0,
   65,   66,   67,   68,   69,   70,   71,   72,   83,   73,
   74,   75,   76,
};
static const YYINT yycheck[] = {                         11,
   26,   27,   32,  299,  304,  301,   18,  263,   50,   51,
   52,  305,   24,  257,  258,  259,  260,  261,  262,  284,
   32,  265,  266,  267,  268,  269,  283,  284,  272,  273,
  295,  301,  299,  290,  301,  282,  293,  294,  295,  283,
  284,  285,  286,  287,  288,  289,  290,  302,  292,  293,
  294,  295,   82,  267,   80,  299,   98,  301,  302,  303,
  299,  305,  301,  257,  258,  259,  260,  261,  262,   22,
   82,  265,  266,  267,  268,  269,  266,  305,  272,  273,
   33,  305,   19,   -1,    0,   -1,   -1,   -1,   -1,  283,
  263,  285,  286,  287,  288,  289,  290,   13,  292,  293,
  294,   -1,  275,  276,   20,  299,   -1,  301,  302,  303,
   -1,  305,  257,  258,  259,  260,  261,  262,  291,   -1,
  265,  266,  267,  268,  269,   -1,   -1,  272,  273,   -1,
   -1,  304,  257,  258,  259,  260,  261,  262,  283,  264,
  285,  286,  287,  288,  289,  290,   -1,  292,  293,  294,
   -1,   -1,   -1,   -1,  299,   -1,  301,  302,  303,   -1,
  305,  257,  258,  259,  260,  261,  262,   -1,   -1,  265,
  266,  267,  268,  269,   -1,   -1,  272,  273,  257,  258,
  259,  260,  261,  262,   -1,   -1,   -1,  283,   -1,  285,
  286,  287,  288,  289,  290,   -1,  292,  293,  294,   -1,
   -1,   -1,   -1,  299,   -1,  301,  302,  303,   -1,  305,
  257,  258,  259,  260,  261,  262,   -1,   -1,  265,  266,
  267,  268,  269,   -1,   -1,  272,  273,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  283,   -1,  285,  286,
  287,  288,  289,  290,   -1,  292,  293,  294,   -1,   -1,
   -1,   -1,  299,   -1,  301,  302,  303,   -1,  305,  257,
  258,  259,  260,  261,  262,   -1,   -1,  265,  266,  267,
  268,  269,   -1,   -1,  272,  273,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,
  288,  289,   -1,   -1,  292,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,  301,  302,  303,   -1,  305,  257,  258,
  259,  260,  261,  262,   -1,   -1,  265,  266,  267,  268,
  269,   -1,   -1,  272,  273,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,  288,
  289,   -1,   -1,  292,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,  301,  302,  303,   -1,  305,  257,  258,  259,
  260,  261,  262,   -1,   -1,  265,  266,  267,  268,  269,
   -1,   -1,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  285,  286,  287,  288,  289,
   -1,   -1,  292,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,  301,  302,  303,   -1,  305,  257,  258,  259,  260,
  261,  262,   -1,   -1,  265,  266,  267,  268,  269,   -1,
   -1,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  285,  286,  287,  288,  289,   -1,
   -1,  292,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,
  301,  302,  303,   -1,  305,  257,  258,  259,  260,  261,
  262,   -1,   -1,  265,  266,  267,  268,  269,   -1,   -1,
  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,  288,  289,   -1,   -1,
  292,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,  301,
  302,  303,   -1,  305,  257,  258,  259,  260,  261,  262,
   -1,   -1,  265,  266,  267,  268,  269,   -1,   -1,  272,
  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  285,  286,  287,  288,  289,   -1,   -1,  292,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,  301,  302,
  303,   -1,  305,  257,  258,  259,  260,  261,  262,   -1,
   -1,  265,  266,  267,  268,  269,   -1,   -1,  272,  273,
  257,  258,  259,  260,  261,  262,   -1,   -1,  265,  266,
  267,  268,  269,   -1,   -1,  272,  273,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,  301,  302,  303,
   -1,  305,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,  301,  302,  303,   -1,  305,  257,
  258,  259,  260,  261,  262,   -1,   -1,  265,  266,  267,
  268,  269,   -1,   -1,  272,  273,  257,  258,  259,  260,
  261,  262,   -1,   -1,  265,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,  302,  303,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,   -1,   -1,  265,  299,  267,
  268,  269,  303,   -1,  272,  273,  257,  258,  259,  260,
  261,  262,   -1,   -1,  265,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  299,   -1,   -1,   -1,  303,   -1,   42,   43,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,  299,   -1,
  265,  302,  267,  268,  269,   -1,   -1,  272,  273,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
   75,   76,   -1,   -1,   -1,   -1,  283,  284,  285,  286,
  287,  288,  289,  290,  299,  292,  293,  294,  295,   -1,
  283,  284,  285,  286,  287,  288,  289,  290,  305,  292,
  293,  294,  295,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 309
#define YYUNDFTOKEN 337
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
"INTPTR","CHARPTR","ID","VOID","IF","ELSE","WHILE","FOR","DO","MAIN","RETURN",
"BOOLTRUE","BOOLFALSE","CSNULL","INTEGER_POS","INTEGER_NEG","CHAR_CONST",
"STRING_CONST","HEX_CONST","OCTAL_CONST","BINARY_CONST","ASSIGNMENT","AND",
"DIVISION","EQUAL","GREATER","GREATEREQUAL","LESS","LESSEQUAL","MINUS","NOT",
"NOTEQUAL","OR","PLUS","MULTI","ADDRESS","DEREFERENCE","ABSUOLUTE","SEMICOLON",
"COLON","COMMA","LEFTBRACE","RIGHTBRACE","LEFTPAREN","RIGHTPAREN","LEFTBRACKET",
"RIGHTBRACKET","PERCENT","LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : procValue",
"procValue : procID LEFTPAREN params RIGHTPAREN block_statements",
"procID : procType id",
"params :",
"params : paramsDeclare",
"paramsDeclare : paramsDeclare COMMA varType id",
"paramsDeclare : varType id",
"newline : newline statement",
"newline : statement",
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
"expr : Pexpr",
"expr : consts",
"expr : ASSIGNMENT_statement",
"Pexpr : LEFTPAREN expr rightParen",
"rightParen : RIGHTPAREN",
"block_statements : LEFTBRACE newline rightbrace",
"rightbrace : RIGHTBRACE",
"consts : id",
"consts : numbers",
"id : ID",
"numbers : INTEGER_NEG",
"numbers : INTEGER_POS",
"statement : IF_statements",
"statement : LOOP_statements",
"statement : BOOLEAN_statements",
"statement : variable_declare_statements",
"statement : SEMICOLON",
"statements_type : statement",
"statements_type : block_statements",
"IF_statements : IF cond statements_type",
"IF_statements : IF cond statements_type else",
"else : ELSE statements_type",
"LOOP_statements : WHILE cond statements_type",
"LOOP_statements : FOR cond statements_type",
"LOOP_statements : DO statements_type WHILE cond",
"cond : expr",
"BOOLEAN_statements : BOOLTRUE",
"BOOLEAN_statements : BOOLFALSE",
"ASSIGNMENT_statement : id ASSIGNMENT expr",
"variable_declare_statements : varType variablesDeclare SEMICOLON",
"procType : VOID",
"procType : varType",
"varType : BOOL",
"varType : CHAR",
"varType : INT",
"varType : STRING",
"varType : INTPTR",
"varType : CHARPTR",
"variablesDeclare : variablesDeclare COMMA id",
"variablesDeclare : variablesDeclare COMMA ASSIGNMENT_statement",
"variablesDeclare : ASSIGNMENT_statement",
"variablesDeclare : id",

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
#line 117 "src/part1.y"

#include "lex.yy.c"
int main(){
    return yyparse();
}

node *mknode    (char *token, node *left, node* middle, node *right){
    node *newnode = (node*)malloc (sizeof(node));
    char    *newstr = (char*)malloc (sizeof(token)+1);
    strcpy (newstr, token);
    newnode -> left = left;
    newnode -> right = right;
    newnode -> middle = middle;
    newnode -> token = newstr;
    return newnode;
}

void printtree (node *tree, int tab){
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
#line 525 "bin/y.tab.c"

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
#line 33 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 2:
#line 35 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 3:
#line 36 "src/part1.y"
	{yyval = mknode ("procID", yystack.l_mark[-1], yystack.l_mark[0], NULL); }
break;
case 5:
#line 38 "src/part1.y"
	{yyval = mknode ("params:", yystack.l_mark[0], NULL, NULL); }
break;
case 6:
#line 39 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-3], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 7:
#line 40 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], yystack.l_mark[0], NULL); }
break;
case 8:
#line 43 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 10:
#line 46 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 11:
#line 47 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 12:
#line 48 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 13:
#line 49 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 14:
#line 50 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 15:
#line 51 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 52 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 53 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 54 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 55 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 56 "src/part1.y"
	{yyval = mknode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 57 "src/part1.y"
	{yyval = mknode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 58 "src/part1.y"
	{yyval = mknode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 26:
#line 63 "src/part1.y"
	{yyval = mknode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 27:
#line 64 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 28:
#line 65 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 29:
#line 66 "src/part1.y"
	{yyval = mknode (")", NULL, NULL,NULL ); }
break;
case 32:
#line 68 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 33:
#line 69 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 34:
#line 70 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 42:
#line 83 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 43:
#line 84 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 44:
#line 86 "src/part1.y"
	{yyval = mknode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 45:
#line 88 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 46:
#line 89 "src/part1.y"
	{yyval=mknode("for", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 47:
#line 90 "src/part1.y"
	{yyval=mknode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 49:
#line 94 "src/part1.y"
	{yyval = mknode ("true", NULL,NULL, NULL); }
break;
case 50:
#line 95 "src/part1.y"
	{yyval = mknode ("false", NULL, NULL, NULL); }
break;
case 51:
#line 98 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 52:
#line 100 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-2], NULL, yystack.l_mark[-1]); }
break;
case 53:
#line 102 "src/part1.y"
	{yyval = mknode ("void", NULL, NULL, NULL); }
break;
case 55:
#line 104 "src/part1.y"
	{yyval = mknode ("boolean", NULL, NULL, NULL); }
break;
case 56:
#line 105 "src/part1.y"
	{yyval = mknode ("char", NULL, NULL, NULL); }
break;
case 57:
#line 106 "src/part1.y"
	{yyval = mknode ("integer", NULL, NULL, NULL); }
break;
case 58:
#line 107 "src/part1.y"
	{yyval = mknode ("string", NULL, NULL, NULL); }
break;
case 59:
#line 108 "src/part1.y"
	{yyval = mknode ("intptr", NULL, NULL, NULL); }
break;
case 60:
#line 109 "src/part1.y"
	{yyval = mknode ("charptr", NULL, NULL, NULL); }
break;
case 61:
#line 111 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 62:
#line 112 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 911 "bin/y.tab.c"
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
