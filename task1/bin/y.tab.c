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
    0,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    4,
    7,    8,    9,    5,    5,   10,   11,   11,   12,   12,
    2,    2,    2,    2,   16,   13,   13,   17,   14,   14,
   14,   15,   15,    6,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    1,    1,    1,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    1,    3,    4,    2,    3,    3,
    4,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
   26,    0,    0,    0,    0,   42,   43,   28,   27,    0,
    0,    0,    0,    3,    0,   17,   18,   19,    0,   25,
   31,   32,   33,    0,    0,    0,    0,    0,   29,   30,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   34,    0,    0,   39,
   40,    0,    0,   21,   20,    0,    7,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    6,    0,    0,   37,
   23,   22,   41,   38,
};
static const YYINT yydgoto[] = {                         12,
   13,   29,   15,   16,   17,   18,   55,   30,   72,   19,
   20,   31,   21,   22,   23,   25,   70,
};
static const YYINT yysindex[] = {                      -182,
    0, -196, -196, -196, -202,    0,    0,    0,    0, -196,
 -196,    0, -182,    0, -258,    0,    0,    0, -280,    0,
    0,    0,    0, -146, -202, -202, -202, -182,    0,    0,
 -263, -146, -169,    0, -196, -196, -196, -196, -196, -196,
 -196, -196, -196, -196, -196, -196,    0, -196, -261,    0,
    0, -297, -196,    0,    0, -284,    0, -133, -133, -133,
 -133, -133, -284, -133, -284, -284,    0, -146, -202,    0,
    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    9,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,  537,    0,    0,    0,    0,    0,    0,
    0,  474,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  554,    0,
    0,    0,    0,    0,    0,   44,    0,  216,  259,  302,
  345,  388,   87,  431,  130,  173,    0,  494,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    5,   10,    0,    0,    0,    0,    0,    0,    0,
    0,  -10,    0,    0,    0,    4,    0,
};
#define YYTABLESIZE 858
static const YYINT yytable[] = {                         36,
   24,   48,   53,   69,   14,   71,   26,   27,    1,    0,
   46,   24,   24,   24,   49,   50,   51,   34,    0,   32,
   33,    0,    0,    0,   35,   36,   37,   38,   39,   40,
   41,   42,   52,   43,   44,   45,   46,    0,    0,    0,
   47,    0,    0,   14,   56,   57,   58,   59,   60,   61,
   62,   63,   64,   65,   66,   67,   73,   68,   74,    0,
    1,    2,   24,    3,    4,    5,    1,    0,    0,    6,
    7,    0,    8,    9,    0,    0,    0,    0,    8,    9,
    1,    2,    0,    3,    4,    5,    5,    0,   10,    6,
    7,    0,    8,    9,   10,    0,    0,    0,    0,   28,
    0,   11,    0,    0,    0,    0,    0,   11,   10,    0,
    0,    0,    0,   35,   36,   37,   38,   39,   40,   41,
   42,   11,   43,   44,   45,   46,    0,    0,    0,   15,
    0,    0,    0,    0,    0,   54,   35,   36,   37,   38,
   39,   40,   41,   42,    0,   43,   44,   45,   46,   35,
   36,    0,    0,    0,    0,    0,   42,    0,    0,   44,
   45,   46,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    8,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
    0,    0,    0,   24,   24,   24,   24,   24,   24,    0,
    0,    0,   24,   24,    0,   24,   24,    0,    0,    0,
    0,    0,    0,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,    0,    0,    0,   24,
    0,   10,   24,   24,   24,   24,   14,   14,   14,   14,
   14,   14,    0,    0,    0,   14,   14,    0,   14,   14,
    0,    0,    0,    0,    0,    0,   14,    0,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,    0,    0,
    0,    0,   14,    0,   11,   14,   14,   14,   14,    5,
    5,    5,    5,    5,    5,    0,    0,    0,    5,    5,
    0,    5,    5,    0,    0,    0,    0,    0,    0,    5,
    0,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    0,    0,    0,    0,    5,    0,   12,    5,    5,
    5,    5,   15,   15,   15,   15,   15,   15,    0,    0,
    0,   15,   15,    0,   15,   15,    0,    0,    0,    0,
    0,    0,   15,    0,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,    0,    0,    0,    0,   15,    0,
   13,   15,   15,   15,   15,    4,    4,    4,    4,    4,
    4,    0,    0,    0,    4,    4,    0,    4,    4,    0,
    0,    0,    0,    0,    0,    4,    0,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    0,    0,    0,
    0,    4,    0,   16,    4,    4,    4,    4,    8,    8,
    8,    8,    8,    8,    0,    0,    0,    8,    8,    0,
    8,    8,    0,   44,    0,    0,    0,    0,    0,    0,
    8,    8,    8,    8,    8,    0,    8,    8,    0,    0,
    0,    0,    0,    0,    8,    0,    0,    8,    8,    8,
    8,    9,    9,    9,    9,    9,    9,    0,    0,    0,
    9,    9,    0,    9,    9,    0,   35,    0,    0,    0,
    0,    0,    0,    9,    9,    9,    9,    9,    0,    9,
    9,    0,    0,   36,    0,    0,    0,    9,    0,    0,
    9,    9,    9,    9,   10,   10,   10,   10,   10,   10,
    0,    0,    0,   10,   10,    0,   10,   10,    0,    0,
    0,    0,    0,    0,    0,    0,   10,   10,   10,   10,
   10,    0,   10,   10,    0,    0,    0,    0,    0,    0,
   10,    0,    0,   10,   10,   10,   10,   11,   11,   11,
   11,   11,   11,    0,    0,    0,   11,   11,    0,   11,
   11,    0,    0,    0,    0,    0,    0,    0,    0,   11,
   11,   11,   11,   11,    0,   11,   11,    0,    0,    0,
    0,    0,    0,   11,    0,    0,   11,   11,   11,   11,
   12,   12,   12,   12,   12,   12,    0,    0,    0,   12,
   12,    0,   12,   12,    0,    0,    0,    0,    0,    0,
    0,    0,   12,   12,   12,   12,   12,    0,   12,   12,
    0,    0,    0,    0,    0,    0,   12,    0,    0,   12,
   12,   12,   12,   13,   13,   13,   13,   13,   13,    0,
    0,    0,   13,   13,    0,   13,   13,    0,    0,    0,
    0,    0,    0,    0,    0,   13,   13,   13,   13,   13,
    0,   13,   13,    0,    0,    0,    0,    0,    0,   13,
    0,    0,   13,   13,   13,   13,   16,   16,   16,   16,
   16,   16,    0,    0,    0,   16,   16,    0,   16,   16,
    0,    0,    0,    0,    0,    0,   44,   44,   44,   44,
   44,   44,    0,    0,   16,   44,   44,    0,   44,   44,
    0,    0,   16,    0,    0,   16,   16,   16,   16,    0,
    0,    0,    0,    0,   44,    0,    0,    0,    0,    0,
    0,    0,   44,    0,    0,   44,   44,   44,   44,   35,
   35,   35,   35,   35,   35,    0,    0,    0,   35,   35,
    0,   35,   35,    0,    0,    0,   36,   36,    0,   36,
   36,   36,    0,    0,    0,   36,   36,   35,   36,   36,
    0,    0,    0,    0,    0,    0,    0,    0,   35,   35,
   35,    0,    0,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,   36,
};
static const YYINT yycheck[] = {                        284,
    0,  282,  266,  265,    0,  303,    3,    4,    0,   -1,
  295,    2,    3,    4,   25,   26,   27,   13,   -1,   10,
   11,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,   28,  292,  293,  294,  295,   -1,   -1,   -1,
  299,   -1,   -1,    0,   35,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   53,   48,   69,   -1,
  263,  264,   53,  266,  267,  268,  263,   -1,   -1,  272,
  273,   -1,  275,  276,   -1,   -1,   -1,   -1,  275,  276,
  263,  264,   -1,  266,  267,  268,    0,   -1,  291,  272,
  273,   -1,  275,  276,  291,   -1,   -1,   -1,   -1,  302,
   -1,  304,   -1,   -1,   -1,   -1,   -1,  304,  291,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  304,  292,  293,  294,  295,   -1,   -1,   -1,    0,
   -1,   -1,   -1,   -1,   -1,  305,  283,  284,  285,  286,
  287,  288,  289,  290,   -1,  292,  293,  294,  295,  283,
  284,   -1,   -1,   -1,   -1,   -1,  290,   -1,   -1,  293,
  294,  295,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,   -1,   -1,   -1,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  294,  295,   -1,   -1,   -1,  299,
   -1,    0,  302,  303,  304,  305,  263,  264,  265,  266,
  267,  268,   -1,   -1,   -1,  272,  273,   -1,  275,  276,
   -1,   -1,   -1,   -1,   -1,   -1,  283,   -1,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,   -1,   -1,
   -1,   -1,  299,   -1,    0,  302,  303,  304,  305,  263,
  264,  265,  266,  267,  268,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,  283,
   -1,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,   -1,   -1,   -1,   -1,  299,   -1,    0,  302,  303,
  304,  305,  263,  264,  265,  266,  267,  268,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,   -1,   -1,   -1,   -1,
   -1,   -1,  283,   -1,  285,  286,  287,  288,  289,  290,
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
  292,   -1,   -1,    0,   -1,   -1,   -1,  299,   -1,   -1,
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
   -1,  275,  276,   -1,   -1,   -1,  263,  264,   -1,  266,
  267,  268,   -1,   -1,   -1,  272,  273,  291,  275,  276,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  302,  303,
  304,   -1,   -1,   -1,  291,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  303,  304,
};
#define YYFINAL 12
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 309
#define YYUNDFTOKEN 329
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
"LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : newline",
"newline : newline statements",
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
"statements_type : statements",
"statements_type : block_statements",
"statements : IF_statements",
"statements : LOOP_statements",
"statements : BOOLEAN_statements",
"statements : expr SEMICOLON",
"cond : expr",
"IF_statements : IF cond statements_type",
"IF_statements : IF cond statements_type else",
"else : ELSE statements_type",
"LOOP_statements : WHILE cond statements_type",
"LOOP_statements : FOR cond statements_type",
"LOOP_statements : DO statements_type WHILE cond",
"BOOLEAN_statements : BOOLTRUE",
"BOOLEAN_statements : BOOLFALSE",
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
#line 503 "bin/y.tab.c"

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
	{yyval = mknode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 4:
#line 41 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 5:
#line 42 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 6:
#line 43 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 7:
#line 44 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 8:
#line 45 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 9:
#line 46 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 10:
#line 47 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 11:
#line 48 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 12:
#line 49 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 13:
#line 50 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 14:
#line 51 "src/part1.y"
	{yyval = mknode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 15:
#line 52 "src/part1.y"
	{yyval = mknode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 53 "src/part1.y"
	{yyval = mknode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 20:
#line 58 "src/part1.y"
	{yyval = mknode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 59 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 22:
#line 60 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 61 "src/part1.y"
	{yyval = mknode (")", NULL, NULL,NULL ); }
break;
case 26:
#line 63 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 27:
#line 64 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 28:
#line 65 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 36:
#line 79 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 37:
#line 80 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 38:
#line 82 "src/part1.y"
	{yyval = mknode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 39:
#line 84 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 40:
#line 85 "src/part1.y"
	{yyval=mknode("for", yystack.l_mark[-1],yystack.l_mark[0], NULL);}
break;
case 41:
#line 86 "src/part1.y"
	{yyval=mknode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 42:
#line 88 "src/part1.y"
	{yyval = mknode ("true", NULL,NULL, NULL); }
break;
case 43:
#line 89 "src/part1.y"
	{yyval = mknode ("false", NULL, NULL, NULL); }
break;
case 44:
#line 92 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 829 "bin/y.tab.c"
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
