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
#define IF 264
#define ELSE 265
#define WHILE 266
#define FOR 267
#define DO 268
#define MAIN 269
#define PROCEDURE 270
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
    0,    2,    2,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    4,    7,    8,    9,    5,    5,   10,   11,   11,
   12,   13,   13,    1,    1,    1,    1,    1,   17,   17,
   14,   14,   18,   15,   15,   15,   15,   16,    6,
};
static const YYINT yylen[] = {                            2,
    1,    3,    2,    1,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    1,    3,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    4,    2,    3,    3,    4,    3,    0,    3,
};
static const YYINT yydefred[] = {                         0,
   28,    0,    0,    0,    0,   39,   40,   30,   29,    0,
    4,    0,    0,    0,    0,    0,   19,   20,   21,    0,
   27,   34,   35,   36,   37,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    5,   33,
    0,    5,   44,   45,    0,    0,   23,   22,    2,    0,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,    0,   42,   25,   24,   46,   43,
};
static const YYINT yydgoto[] = {                         13,
   49,   15,   16,   17,   18,   19,   58,   50,   76,   20,
   21,   27,   51,   22,   23,   24,   25,   74,
};
static const YYINT yysindex[] = {                      -178,
    0, -263, -263, -263, -299,    0,    0,    0,    0, -263,
    0, -263,    0,    0, -263, -138,    0,    0,    0, -278,
    0,    0,    0,    0,    0, -101, -200, -200, -299, -178,
 -261, -101, -152, -118, -263, -263, -263, -263, -263, -263,
 -263, -263, -263, -263, -263, -263,    0, -263,    0,    0,
 -259,    0,    0,    0, -282, -263,    0,    0,    0, -273,
    0, -183, -183, -183, -183, -183, -273, -183, -273, -273,
    0, -101, -200,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                        23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  108,   10,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,  537,   15,   15,    0, -276,
    0,  474,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   65,    0,    0,    0, -256,    0,    0,    0,    0,   44,
    0,  216,  259,  302,  345,  388,   87,  431,  130,  173,
    0,  494,   15,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    2,    0,   14,    0,    0,    0,    0,    9,    0,    0,
    0,    5,  -48,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 841
static const YYINT yytable[] = {                          1,
   26,   14,   30,   48,   56,   73,    5,   28,   29,   38,
   36,    8,    9,   31,   48,   26,   26,   26,    5,    5,
   75,   46,   48,   32,   78,   33,   48,   10,   34,   52,
    0,   55,    0,    0,    5,    0,   53,   54,    0,    0,
   12,    0,    0,   16,    0,    0,    0,    5,   60,   61,
   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   77,   72,    1,    2,   41,    3,    4,    5,    0,   26,
    0,    6,    7,    0,    8,    9,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    2,    7,    3,    4,    5,
   10,    0,    0,    6,    7,    0,    8,    9,   11,   35,
   36,   30,    0,   12,    0,    0,   42,    1,    0,   44,
   45,   46,   10,    0,    0,    0,    0,    0,    0,    0,
   11,    0,    0,    0,    0,   12,    0,    0,    0,   17,
   35,   36,   37,   38,   39,   40,   41,   42,    0,   43,
   44,   45,   46,    0,   35,   36,   37,   38,   39,   40,
   41,   42,   57,   43,   44,   45,   46,    0,    0,    0,
   47,    0,    0,    0,   35,   36,   37,   38,   39,   40,
   41,   42,    6,   43,   44,   45,   46,    0,    0,    0,
   59,   35,   36,   37,   38,   39,   40,   41,   42,    0,
   43,   44,   45,   46,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   10,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   11,    0,
    0,    0,    0,   26,   26,   26,   26,   26,   26,    0,
    0,    0,   26,   26,   38,   26,   26,    0,    0,   48,
    0,    0,    0,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,    0,    0,    0,   26,
    0,   12,   26,   26,   26,   26,   16,   16,   16,   16,
   16,   16,   38,    0,    0,   16,   16,   48,   16,   16,
    0,    0,    0,    0,    0,    0,   16,   41,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,    0,   41,
   41,    0,   16,    0,   13,   16,   16,   16,   16,    7,
    7,    7,    7,    7,    7,   41,    0,    0,    7,    7,
    0,    7,    7,    0,    0,    0,    0,   41,   41,    7,
    5,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    0,    5,    5,    0,    7,    0,   14,    7,    7,
    7,    7,   17,   17,   17,   17,   17,   17,    5,    0,
    0,   17,   17,    0,   17,   17,    0,    0,    0,    0,
    0,    5,   17,    0,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,    0,    0,    0,    0,   17,    0,
   15,   17,   17,   17,   17,    6,    6,    6,    6,    6,
    6,    0,    0,    0,    6,    6,    0,    6,    6,    0,
    0,    0,    0,    0,    0,    6,    0,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    0,    0,    0,
    0,    6,    0,   18,    6,    6,    6,    6,   10,   10,
   10,   10,   10,   10,    0,    0,    0,   10,   10,    0,
   10,   10,    0,   49,    0,    0,    0,    0,    0,    0,
   10,   10,   10,   10,   10,    0,   10,   10,    0,    0,
    0,    0,    0,    0,   10,    0,    0,   10,   10,   10,
   10,   11,   11,   11,   11,   11,   11,    0,    0,    0,
   11,   11,    0,   11,   11,    0,   31,    0,    0,    0,
    0,    0,    0,   11,   11,   11,   11,   11,    0,   11,
   11,    0,    0,    0,    0,    0,    0,   11,    0,    0,
   11,   11,   11,   11,   12,   12,   12,   12,   12,   12,
    0,    0,    0,   12,   12,    0,   12,   12,    0,    0,
    0,    0,    0,    0,    0,    0,   12,   12,   12,   12,
   12,    0,   12,   12,    0,    0,    0,    0,    0,    0,
   12,    0,    0,   12,   12,   12,   12,   13,   13,   13,
   13,   13,   13,    0,    0,    0,   13,   13,    0,   13,
   13,    0,    0,    0,    0,    0,    0,    0,    0,   13,
   13,   13,   13,   13,    0,   13,   13,    0,    0,    0,
    0,    0,    0,   13,    0,    0,   13,   13,   13,   13,
   14,   14,   14,   14,   14,   14,    0,    0,    0,   14,
   14,    0,   14,   14,    0,    0,    0,    0,    0,    0,
    0,    0,   14,   14,   14,   14,   14,    0,   14,   14,
    0,    0,    0,    0,    0,    0,   14,    0,    0,   14,
   14,   14,   14,   15,   15,   15,   15,   15,   15,    0,
    0,    0,   15,   15,    0,   15,   15,    0,    0,    0,
    0,    0,    0,    0,    0,   15,   15,   15,   15,   15,
    0,   15,   15,    0,    0,    0,    0,    0,    0,   15,
    0,    0,   15,   15,   15,   15,   18,   18,   18,   18,
   18,   18,    0,    0,    0,   18,   18,    0,   18,   18,
    0,    0,    0,    0,    0,    0,   49,   49,   49,   49,
   49,   49,    0,    0,   18,   49,   49,    0,   49,   49,
    0,    0,   18,    0,    0,   18,   18,   18,   18,    0,
    0,    0,    0,    0,   49,    0,    0,    0,    0,    0,
    0,    0,   49,    0,    0,   49,   49,   49,   49,   31,
   31,   31,   31,   31,   31,    0,    0,    0,   31,   31,
    0,   31,   31,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
    0,    0,    0,    0,    0,   31,    0,    0,   31,   31,
   31,
};
static const YYINT yycheck[] = {                        263,
    0,    0,  302,  282,  266,  265,  263,    3,    4,    0,
  284,  275,  276,    5,    0,    2,    3,    4,  275,  276,
  303,  295,    0,   10,   73,   12,  303,  291,   15,   28,
   -1,   30,   -1,   -1,  291,   -1,   28,   29,   -1,   -1,
  304,   -1,   -1,    0,   -1,   -1,   -1,  304,   35,   36,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
   56,   48,  263,  264,    0,  266,  267,  268,   -1,   56,
   -1,  272,  273,   -1,  275,  276,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,  264,    0,  266,  267,  268,
  291,   -1,   -1,  272,  273,   -1,  275,  276,  299,  283,
  284,  302,   -1,  304,   -1,   -1,  290,    0,   -1,  293,
  294,  295,  291,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,   -1,   -1,  304,   -1,   -1,   -1,    0,
  283,  284,  285,  286,  287,  288,  289,  290,   -1,  292,
  293,  294,  295,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  305,  292,  293,  294,  295,   -1,   -1,   -1,
  299,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,    0,  292,  293,  294,  295,   -1,   -1,   -1,
  299,  283,  284,  285,  286,  287,  288,  289,  290,   -1,
  292,  293,  294,  295,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,  272,  273,  265,  275,  276,   -1,   -1,  265,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  295,   -1,   -1,   -1,  299,
   -1,    0,  302,  303,  304,  305,  263,  264,  265,  266,
  267,  268,  303,   -1,   -1,  272,  273,  303,  275,  276,
   -1,   -1,   -1,   -1,   -1,   -1,  283,  263,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,   -1,  275,
  276,   -1,  299,   -1,    0,  302,  303,  304,  305,  263,
  264,  265,  266,  267,  268,  291,   -1,   -1,  272,  273,
   -1,  275,  276,   -1,   -1,   -1,   -1,  303,  304,  283,
  263,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,   -1,  275,  276,   -1,  299,   -1,    0,  302,  303,
  304,  305,  263,  264,  265,  266,  267,  268,  291,   -1,
   -1,  272,  273,   -1,  275,  276,   -1,   -1,   -1,   -1,
   -1,  304,  283,   -1,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,   -1,   -1,   -1,   -1,  299,   -1,
    0,  302,  303,  304,  305,  263,  264,  265,  266,  267,
  268,   -1,   -1,   -1,  272,  273,   -1,  275,  276,   -1,
   -1,   -1,   -1,   -1,   -1,  283,   -1,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,   -1,   -1,   -1,
   -1,  299,   -1,    0,  302,  303,  304,  305,  263,  264,
  265,  266,  267,  268,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,
  285,  286,  287,  288,  289,   -1,  291,  292,   -1,   -1,
   -1,   -1,   -1,   -1,  299,   -1,   -1,  302,  303,  304,
  305,  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,
  272,  273,   -1,  275,  276,   -1,    0,   -1,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,  288,  289,   -1,  291,
  292,   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,
  302,  303,  304,  305,  263,  264,  265,  266,  267,  268,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,  288,
  289,   -1,  291,  292,   -1,   -1,   -1,   -1,   -1,   -1,
  299,   -1,   -1,  302,  303,  304,  305,  263,  264,  265,
  266,  267,  268,   -1,   -1,   -1,  272,  273,   -1,  275,
  276,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
  286,  287,  288,  289,   -1,  291,  292,   -1,   -1,   -1,
   -1,   -1,   -1,  299,   -1,   -1,  302,  303,  304,  305,
  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  285,  286,  287,  288,  289,   -1,  291,  292,
   -1,   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,  302,
  303,  304,  305,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  285,  286,  287,  288,  289,
   -1,  291,  292,   -1,   -1,   -1,   -1,   -1,   -1,  299,
   -1,   -1,  302,  303,  304,  305,  263,  264,  265,  266,
  267,  268,   -1,   -1,   -1,  272,  273,   -1,  275,  276,
   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,  291,  272,  273,   -1,  275,  276,
   -1,   -1,  299,   -1,   -1,  302,  303,  304,  305,   -1,
   -1,   -1,   -1,   -1,  291,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  299,   -1,   -1,  302,  303,  304,  305,  263,
  264,  265,  266,  267,  268,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  299,   -1,   -1,  302,  303,
  304,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 309
#define YYUNDFTOKEN 330
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
"INTPTR","CHARPTR","ID","IF","ELSE","WHILE","FOR","DO","MAIN","PROCEDURE",
"RETURN","BOOLTRUE","BOOLFALSE","CSNULL","INTEGER_POS","INTEGER_NEG",
"CHAR_CONST","STRING_CONST","HEX_CONST","OCTAL_CONST","BINARY_CONST",
"ASSIGNMENT","AND","DIVISION","EQUAL","GREATER","GREATEREQUAL","LESS",
"LESSEQUAL","MINUS","NOT","NOTEQUAL","OR","PLUS","MULTI","ADDRESS",
"DEREFERENCE","ABSUOLUTE","SEMICOLON","COLON","COMMA","LEFTBRACE","RIGHTBRACE",
"LEFTPAREN","RIGHTPAREN","LEFTBRACKET","RIGHTBRACKET","PERCENT",
"LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : statements",
"newline : newline expr SEMICOLON",
"newline : expr SEMICOLON",
"newline : SEMICOLON",
"newline : statements",
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
"block_statements : LEFTBRACE statements rightbrace",
"rightbrace : RIGHTBRACE",
"consts : id",
"consts : numbers",
"id : ID",
"numbers : INTEGER_NEG",
"numbers : INTEGER_POS",
"cond : expr",
"statements_type : statements",
"statements_type : block_statements",
"statements : IF_statements",
"statements : LOOP_statements",
"statements : IN.OUT_statements",
"statements : BOOLEAN_statements",
"statements : newline",
"BOOLEAN_statements : BOOLTRUE",
"BOOLEAN_statements : BOOLFALSE",
"IF_statements : IF cond statements_type",
"IF_statements : IF cond statements_type else",
"else : ELSE statements_type",
"LOOP_statements : WHILE cond block_statements",
"LOOP_statements : FOR cond block_statements",
"LOOP_statements : DO block_statements WHILE cond",
"LOOP_statements : WHILE cond statements",
"IN.OUT_statements :",
"ASSIGNMENT_statement : id ASSIGNMENT expr",

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
#line 94 "src/part1.y"

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
    printf ("%s\n", token);
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
#line 506 "bin/y.tab.c"

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
#line 36 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 6:
#line 41 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 7:
#line 42 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 8:
#line 43 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 9:
#line 44 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 10:
#line 45 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 11:
#line 46 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 12:
#line 47 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 13:
#line 48 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 14:
#line 49 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 15:
#line 50 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 51 "src/part1.y"
	{yyval = mknode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 52 "src/part1.y"
	{yyval = mknode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 53 "src/part1.y"
	{yyval = mknode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 22:
#line 58 "src/part1.y"
	{yyval = mknode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 59 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 24:
#line 60 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 25:
#line 61 "src/part1.y"
	{yyval = mknode (")", NULL, NULL,NULL ); }
break;
case 28:
#line 63 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 29:
#line 64 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 30:
#line 65 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 39:
#line 78 "src/part1.y"
	{yyval = mknode ("true", NULL,NULL, NULL); }
break;
case 40:
#line 79 "src/part1.y"
	{yyval = mknode ("false", NULL, NULL, NULL); }
break;
case 41:
#line 81 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 42:
#line 82 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 43:
#line 84 "src/part1.y"
	{yyval = mknode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 44:
#line 86 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 45:
#line 87 "src/part1.y"
	{yyval=mknode("for", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 46:
#line 88 "src/part1.y"
	{yyval=mknode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 47:
#line 89 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 49:
#line 92 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 836 "bin/y.tab.c"
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
