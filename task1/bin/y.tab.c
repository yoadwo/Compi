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

union{
 char *string;
}

token <string> STRING

node *mknode (char *token, node *left, node* middle, node *right);
void printtree (node *tree, int tab);
#define YYSTYPE struct node *
#line 42 "bin/y.tab.c"

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
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define DO 270
#define MAIN 271
#define RETURN 272
#define BOOLTRUE 273
#define BOOLFALSE 274
#define CSNULL 275
#define INTEGER_POS 276
#define INTEGER_NEG 277
#define CHAR_CONST 278
#define STRING_CONST 279
#define HEX_CONST 280
#define OCTAL_CONST 281
#define BINARY_CONST 282
#define ASSIGNMENT 283
#define AND 284
#define DIVISION 285
#define EQUAL 286
#define GREATER 287
#define GREATEREQUAL 288
#define LESS 289
#define LESSEQUAL 290
#define MINUS 291
#define NOT 292
#define NOTEQUAL 293
#define OR 294
#define PLUS 295
#define MULTI 296
#define ADDRESS 297
#define DEREFERENCE 298
#define ABSUOLUTE 299
#define SEMICOLON 300
#define COLON 301
#define COMMA 302
#define LEFTBRACE 303
#define RIGHTBRACE 304
#define LEFTPAREN 305
#define RIGHTPAREN 306
#define LEFTBRACKET 307
#define RIGHTBRACKET 308
#define PERCENT 309
#define LOWER_THAN_ELSE 310
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    2,    2,    4,    4,    3,    6,    5,   10,
    9,    9,   13,   13,   14,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   16,   18,   11,   11,    7,    7,    7,   22,   22,   21,
   20,   17,   17,   17,   17,    8,   23,   23,   23,   23,
   23,   25,   24,   24,   19,   19,   26,   26,   26,   26,
   26,   30,   30,   27,   27,   32,   28,   28,   28,   33,
   34,   35,   36,   37,   37,   37,   38,   38,   39,   39,
   31,   40,   41,   29,   29,   12,   12,   12,   12,   12,
   12,   43,   43,   43,   43,   42,   42,   42,   42,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    1,    1,    1,    5,    6,    5,    2,
    0,    1,    3,    1,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    3,    1,    6,    5,    1,    5,    4,    1,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    4,    2,    1,    1,    1,    3,
    4,    4,    6,    0,    1,    1,    0,    1,    0,    1,
    3,    3,    5,    2,    2,    1,    1,    1,    1,    1,
    1,    6,    1,    3,    4,    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   86,   87,   88,   89,   90,   91,    0,    0,    1,    0,
    4,    5,    6,    0,    0,   46,    0,    0,    2,    3,
    0,   10,    0,    0,    0,    0,   12,    0,    0,    0,
    0,   15,    0,    0,    0,    0,    9,   13,    0,    8,
   35,    7,    0,    0,    0,    0,    0,   61,   59,    0,
    0,    0,   57,   58,   60,   67,   68,   69,    0,   41,
    0,   40,    0,    0,    0,    0,    0,    0,   38,   63,
   62,    0,   53,   54,   52,   48,   47,   49,   50,   51,
    0,    0,   42,    0,   29,   30,   43,   44,   45,    0,
    0,    0,   84,   85,    0,   55,    0,    0,    0,    0,
   70,    0,    0,    0,   76,   32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   37,    0,   81,    0,   65,    0,   72,   39,   71,   31,
    0,   19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,   34,    0,    0,   96,    0,   97,    0,   94,
    0,   36,   66,    0,    0,    0,   33,    0,   83,    0,
    0,   73,   80,   92,
};
static const YYINT yydgoto[] = {                          8,
    9,   10,   19,   49,   12,   13,   40,   83,   25,   14,
   37,   50,   27,   28,   84,   85,   86,  107,   51,   62,
   69,   70,   87,   88,   89,   71,   53,   54,   55,   72,
   64,  135,   56,   57,   58,   67,  104,  165,  172,   91,
   92,   93,   94,
};
static const YYINT yysindex[] = {                       -93,
    0,    0,    0,    0,    0,    0, -261,    0,    0,  -44,
    0,    0,    0, -283, -261,    0, -277, -211,    0,    0,
    6,    0,    6, -250, -249, -261,    0, -244, -226, -225,
 -212,    0,    6, -207, -207,  604,    0,    0,  507,    0,
    0,    0, -213, -213, -194,  588, -187,    0,    0, -261,
 -159,  637,    0,    0,    0,    0,    0,    0, -186,    0,
 -157,    0, -187,  588,  588, -187, -190,  571,    0,    0,
    0, -151,    0,    0,    0,    0,    0,    0,    0,    0,
 -187, -187,    0,  624,    0,    0,    0,    0,    0, -269,
 -182, -179,    0,    0, -187,    0, -172, -175,   29, -131,
    0, -146,   79, -162,    0,    0,  588, -172, -213,   79,
   29, -187, -187, -187, -187, -187, -187, -187, -187, -187,
 -187, -187, -187, -172, -187, -261, -198, -261, -261,  645,
    0, -172,    0,  588,    0, -187,    0,    0,    0,    0,
 -240,    0,  129,  129,  129,  129,  129, -240,  129, -240,
 -240,    0,    0,   79, -260,    0, -169,    0, -166,    0,
 -172,    0,    0,   79, -155, -251,    0, -261,    0, -261,
 -146,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -163,    0, -163,    0,    0,    0,    0, -153,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -263,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -145,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  406,
  422,  470,    0,    0,    0,    0,    0,    0,    0,  555,
    0,  662, -130,    0,    0,    0,    0,    0,    0,  340,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -128,    0,    0,    0,    0,
 -160,    0,   40,   90,  140,  190,  240, -110,  290,  -60,
  -10,    0,    0,  356,  486,    0,    0,    0,    0,    0,
    0,    0,    0, -127,    0,  534,    0, -124,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   25,    0,    0,  151,   -7,  152,    0,
    0,   16,  154,    0,  -51,    0,    0,  -94,  -32,  -84,
   19,    0,   61,    0,    0,  -18,    0,    0,    0,  -61,
  -34,    0,    0,    0,    0,    0,    0,    0,    0,  -65,
    0,  -99, -123,
};
#define YYTABLESIZE 962
static const YYINT yytable[] = {                         17,
  105,   16,  100,  101,  133,  160,   61,   22,   56,   65,
   17,   99,  131,  125,  103,   15,  140,   52,   32,   96,
   52,   21,  125,  138,   11,   15,  156,   23,  158,  110,
  111,  169,  126,   52,   20,  108,   26,  127,   26,  153,
   56,  126,   90,  130,  113,  137,  174,  162,   26,   52,
  170,   16,   41,   41,   30,  123,   31,   33,  102,   24,
  141,  142,  143,  144,  145,  146,  147,  148,  149,  150,
  151,  152,  163,  154,  139,   16,  167,   76,   77,   34,
   35,   78,   79,   80,  164,   73,   74,   75,   76,   77,
   36,   63,   78,   79,   80,   39,   26,   26,   26,   26,
   26,   26,  173,   26,   81,   26,   26,   26,   26,   26,
   66,   26,   95,   97,   98,  106,  109,   82,  155,  128,
  155,  159,  129,   26,  132,   26,   26,   26,   26,   26,
   26,   60,   26,   26,   26,  134,  125,  136,  166,   26,
  127,   26,   11,   26,  168,   26,   17,   17,   17,   17,
   17,   17,   14,   17,   74,   17,   17,   17,   17,   17,
  171,   17,  159,    1,    2,    3,    4,    5,    6,   75,
    7,   77,   78,   17,   29,   17,   17,   17,   17,   17,
   17,   79,   17,   17,   17,   42,   38,  157,    0,   17,
    0,   17,    0,   17,    0,   17,   27,   27,   27,   27,
   27,   27,    0,   27,    0,   27,   27,   27,   27,   27,
    0,   27,    1,    2,    3,    4,    5,    6,    0,   18,
    0,    0,    0,   27,    0,   27,   27,   27,   27,   27,
   27,    0,   27,   27,   27,    0,    0,    0,    0,   27,
    0,   27,    0,   27,    0,   27,   16,   16,   16,   16,
   16,   16,    0,   16,    0,   16,   16,   16,   16,   16,
    0,   16,    1,    2,    3,    4,    5,    6,    0,    0,
    0,    0,    0,   16,    0,   16,   16,   16,   16,   16,
   16,    0,   16,   16,   16,    0,    0,    0,    0,   16,
    0,   16,    0,   16,    0,   16,   20,   20,   20,   20,
   20,   20,    0,   20,    0,   20,   20,   20,   20,   20,
    0,   20,  112,  113,  114,  115,  116,  117,  118,  119,
    0,  120,  121,  122,  123,   20,   20,   20,   20,   20,
    0,    0,   20,    0,  106,    0,    0,    0,    0,   20,
    0,   20,    0,   20,    0,   20,   21,   21,   21,   21,
   21,   21,    0,   21,    0,   21,   21,   21,   21,   21,
    0,   21,  112,  113,  114,  115,  116,  117,  118,  119,
    0,  120,  121,  122,  123,   21,   21,   21,   21,   21,
    0,    0,   21,    0,    0,    0,    0,    0,    0,   21,
    0,   21,    0,   21,    0,   21,   22,   22,   22,   22,
   22,   22,    0,   22,    0,   22,   22,   22,   22,   22,
    0,   22,  112,  113,    0,    0,    0,    0,    0,  119,
    0,    0,  121,  122,  123,   22,   22,   22,   22,   22,
    0,    0,   22,    0,    0,    0,    0,    0,    0,   22,
    0,   22,    0,   22,    0,   22,   23,   23,   23,   23,
   23,   23,    0,   23,    0,   23,   23,   23,   23,   23,
    0,   23,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,   23,   23,   23,   23,
    0,    0,   23,    0,    0,    0,    0,    0,    0,   23,
    0,   23,    0,   23,    0,   23,   24,   24,   24,   24,
   24,   24,    0,   24,    0,   24,   24,   24,   24,   24,
    0,   24,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   24,   24,   24,   24,   24,
    0,    0,   24,    0,    0,    0,    0,    0,    0,   24,
    0,   24,    0,   24,    0,   24,   25,   25,   25,   25,
   25,   25,    0,   25,    0,   25,   25,   25,   25,   25,
    0,   25,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,   25,   25,   25,   25,
    0,    0,   25,    0,    0,    0,    0,    0,    0,   25,
    0,   25,    0,   25,    0,   25,   28,   28,   28,   28,
   28,   28,    0,   28,    0,   28,   28,   28,   28,   28,
    0,   28,   82,   82,   82,   82,   82,   82,    0,   82,
    0,   82,   82,   82,   82,   82,    0,   82,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
    0,   28,    0,   28,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   82,    0,   82,    0,   82,
    0,   82,   99,   99,   99,   99,   99,   99,    0,   99,
    0,   99,   99,   99,   99,   99,    0,   99,   98,   98,
   98,   98,   98,   98,    0,   98,    0,   98,   98,   98,
   98,   98,    0,   98,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   99,    0,    0,    0,   99,
   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   98,    0,    0,    0,   98,   93,   93,   93,   93,
   93,   93,    0,   93,    0,   93,   93,   93,   93,   93,
    0,   93,   99,   99,   99,   99,   99,   99,    0,   99,
    0,   99,   99,   99,   99,   99,    0,   99,    0,    0,
    0,    0,    0,    1,    2,    3,    4,    5,    6,   93,
    7,    0,   43,   93,   44,   45,   46,    0,   59,    0,
    0,    0,    0,    0,    0,   99,    0,    0,    0,   99,
   95,   95,   95,   95,   95,   95,    0,   95,    0,   95,
   95,   95,   95,   95,    0,   95,   48,    0,    0,    0,
   60,   64,   64,   64,   64,   64,   64,    0,   64,    0,
   64,    0,   64,   64,   64,    0,   64,    1,    2,    3,
    4,    5,    6,   95,    7,    0,   43,   95,   44,   45,
   46,    0,    0,    0,    1,    2,    3,    4,    5,    6,
    0,    7,    0,   43,   64,   44,   45,   46,   64,    0,
    1,    2,    3,    4,    5,    6,    0,    7,    0,   43,
   48,   44,   45,   46,   60,   47,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,    0,    0,
   68,    0,    0,    1,    2,    3,    4,    5,    6,    0,
    7,    0,   43,   48,   44,   45,   46,  112,  113,  114,
  115,  116,  117,  118,  119,    0,  120,  121,  122,  123,
    0,    0,    0,  124,    0,    0,    0,    0,  112,  113,
  114,  115,  116,  117,  118,  119,   48,  120,  121,  122,
  123,    0,    0,    0,  161,   42,   42,   42,   42,   42,
   42,   42,   42,    0,   42,   42,   42,   42,    0,    0,
    0,   42,
};
static const YYINT yycheck[] = {                          7,
   66,  263,   64,   65,   99,  129,   39,   15,  272,   44,
   18,   63,   97,  283,   66,    0,  111,   36,   26,   52,
   39,  305,  283,  108,    0,   10,  126,  305,  128,   81,
   82,  283,  302,   52,   10,   68,   21,  307,   23,  124,
  304,  302,   50,   95,  285,  107,  170,  132,   33,   68,
  302,  263,   34,   35,  305,  296,  306,  302,   66,  271,
  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,
  122,  123,  134,  125,  109,  263,  161,  276,  277,  306,
  306,  280,  281,  282,  136,  273,  274,  275,  276,  277,
  303,  305,  280,  281,  282,  303,  257,  258,  259,  260,
  261,  262,  168,  264,  292,  266,  267,  268,  269,  270,
  305,  272,  272,  300,  272,  306,  268,  305,  126,  302,
  128,  129,  302,  284,  300,  286,  287,  288,  289,  290,
  291,  304,  293,  294,  295,  267,  283,  300,  308,  300,
  307,  302,  306,  304,  300,  306,  257,  258,  259,  260,
  261,  262,  306,  264,  300,  266,  267,  268,  269,  270,
  168,  272,  170,  257,  258,  259,  260,  261,  262,  300,
  264,  300,  300,  284,   23,  286,  287,  288,  289,  290,
  291,  306,  293,  294,  295,   35,   33,  127,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  257,  258,  259,  260,  261,  262,   -1,  264,
   -1,   -1,   -1,  284,   -1,  286,  287,  288,  289,  290,
  291,   -1,  293,  294,  295,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  257,  258,  259,  260,  261,  262,   -1,   -1,
   -1,   -1,   -1,  284,   -1,  286,  287,  288,  289,  290,
  291,   -1,  293,  294,  295,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,  293,  294,  295,  296,  286,  287,  288,  289,  290,
   -1,   -1,  293,   -1,  306,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,  293,  294,  295,  296,  286,  287,  288,  289,  290,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  284,  285,   -1,   -1,   -1,   -1,   -1,  291,
   -1,   -1,  294,  295,  296,  286,  287,  288,  289,  290,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,  289,  290,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,  289,  290,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,  289,  290,
   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  257,  258,  259,  260,  261,  262,   -1,  264,
   -1,  266,  267,  268,  269,  270,   -1,  272,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,
   -1,  302,   -1,  304,   -1,  306,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  300,   -1,  302,   -1,  304,
   -1,  306,  257,  258,  259,  260,  261,  262,   -1,  264,
   -1,  266,  267,  268,  269,  270,   -1,  272,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  300,   -1,   -1,   -1,  304,
  305,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,   -1,   -1,  304,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  267,  268,  269,  270,
   -1,  272,  257,  258,  259,  260,  261,  262,   -1,  264,
   -1,  266,  267,  268,  269,  270,   -1,  272,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  300,
  264,   -1,  266,  304,  268,  269,  270,   -1,  272,   -1,
   -1,   -1,   -1,   -1,   -1,  300,   -1,   -1,   -1,  304,
  257,  258,  259,  260,  261,  262,   -1,  264,   -1,  266,
  267,  268,  269,  270,   -1,  272,  300,   -1,   -1,   -1,
  304,  257,  258,  259,  260,  261,  262,   -1,  264,   -1,
  266,   -1,  268,  269,  270,   -1,  272,  257,  258,  259,
  260,  261,  262,  300,  264,   -1,  266,  304,  268,  269,
  270,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
   -1,  264,   -1,  266,  300,  268,  269,  270,  304,   -1,
  257,  258,  259,  260,  261,  262,   -1,  264,   -1,  266,
  300,  268,  269,  270,  304,  272,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,   -1,   -1,
  303,   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,
  264,   -1,  266,  300,  268,  269,  270,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,  293,  294,  295,  296,
   -1,   -1,   -1,  300,   -1,   -1,   -1,   -1,  284,  285,
  286,  287,  288,  289,  290,  291,  300,  293,  294,  295,
  296,   -1,   -1,   -1,  300,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,  293,  294,  295,  296,   -1,   -1,
   -1,  300,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 310
#define YYUNDFTOKEN 356
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
"INTPTR","CHARPTR","ID","VOID","QUOTES","IF","ELSE","WHILE","FOR","DO","MAIN",
"RETURN","BOOLTRUE","BOOLFALSE","CSNULL","INTEGER_POS","INTEGER_NEG",
"CHAR_CONST","STRING_CONST","HEX_CONST","OCTAL_CONST","BINARY_CONST",
"ASSIGNMENT","AND","DIVISION","EQUAL","GREATER","GREATEREQUAL","LESS",
"LESSEQUAL","MINUS","NOT","NOTEQUAL","OR","PLUS","MULTI","ADDRESS",
"DEREFERENCE","ABSUOLUTE","SEMICOLON","COLON","COMMA","LEFTBRACE","RIGHTBRACE",
"LEFTPAREN","RIGHTPAREN","LEFTBRACKET","RIGHTBRACKET","PERCENT",
"LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : global",
"global : procedures procMain",
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
"id : ID",
"numbers : INTEGER_NEG",
"numbers : INTEGER_POS",
"numbers : HEX_CONST",
"numbers : OCTAL_CONST",
"numbers : BINARY_CONST",
"csnull : CSNULL",
"booleans : BOOLTRUE",
"booleans : BOOLFALSE",
"newline : statement newline",
"newline : statement",
"statement : IF_statements",
"statement : LOOP_statements",
"statement : proc",
"statement : variable_declare_statements",
"statement : SEMICOLON",
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
"str_ASSIGNMENT_statement : id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT",
"variable_declare_statements : varType variablesDeclare",
"variable_declare_statements : varType StringDeclare",
"varType : BOOL",
"varType : CHAR",
"varType : INT",
"varType : STRING",
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
#line 164 "src/part1.y"

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
#line 635 "bin/y.tab.c"

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
#line 38 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 2:
#line 39 "src/part1.y"
	{yyval = mknode ("global", yystack.l_mark[-1],NULL,yystack.l_mark[0]); }
break;
case 3:
#line 42 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1],NULL, NULL); }
break;
case 4:
#line 43 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 7:
#line 46 "src/part1.y"
	{yyval = mknode ("main", yystack.l_mark[0],NULL, NULL); }
break;
case 8:
#line 47 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 9:
#line 48 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 10:
#line 49 "src/part1.y"
	{yyval = mknode ("procID", yystack.l_mark[-1], yystack.l_mark[0], NULL); }
break;
case 12:
#line 51 "src/part1.y"
	{yyval = mknode ("params:", yystack.l_mark[0], NULL, NULL); }
break;
case 13:
#line 52 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 15:
#line 56 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 58 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 59 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 60 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 61 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 62 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 63 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 64 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 65 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 24:
#line 66 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 25:
#line 67 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 26:
#line 68 "src/part1.y"
	{yyval = mknode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 27:
#line 69 "src/part1.y"
	{yyval = mknode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 28:
#line 70 "src/part1.y"
	{yyval = mknode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 31:
#line 75 "src/part1.y"
	{yyval = mknode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 32:
#line 76 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 33:
#line 77 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 34:
#line 78 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 36:
#line 80 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-3], NULL, yystack.l_mark[-1]); }
break;
case 37:
#line 81 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 39:
#line 84 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 40:
#line 88 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[0], NULL, NULL); }
break;
case 41:
#line 89 "src/part1.y"
	{yyval = mknode (")", NULL, NULL,NULL ); }
break;
case 46:
#line 91 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 47:
#line 92 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 48:
#line 93 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 49:
#line 94 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 50:
#line 95 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 51:
#line 96 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 52:
#line 97 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 53:
#line 98 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 54:
#line 99 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 55:
#line 101 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 64:
#line 119 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 65:
#line 120 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 66:
#line 122 "src/part1.y"
	{yyval = mknode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 70:
#line 127 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],NULL, yystack.l_mark[0]);}
break;
case 71:
#line 128 "src/part1.y"
	{yyval=mknode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 72:
#line 130 "src/part1.y"
	{yyval=mknode("for", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]);}
break;
case 73:
#line 132 "src/part1.y"
	{yyval=mknode("for conditions:", yystack.l_mark[-4],yystack.l_mark[-2], yystack.l_mark[0]);}
break;
case 81:
#line 136 "src/part1.y"
	{yyval = mknode ("(COND", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 82:
#line 140 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 83:
#line 141 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-4], NULL, NULL); }
break;
case 84:
#line 142 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 85:
#line 143 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 86:
#line 145 "src/part1.y"
	{yyval = mknode ("boolean", NULL, NULL, NULL); }
break;
case 87:
#line 146 "src/part1.y"
	{yyval = mknode ("char", NULL, NULL, NULL); }
break;
case 88:
#line 147 "src/part1.y"
	{yyval = mknode ("integer", NULL, NULL, NULL); }
break;
case 89:
#line 148 "src/part1.y"
	{yyval = mknode ("string", NULL, NULL, NULL); }
break;
case 90:
#line 149 "src/part1.y"
	{yyval = mknode ("intptr", NULL, NULL, NULL); }
break;
case 91:
#line 150 "src/part1.y"
	{yyval = mknode ("charptr", NULL, NULL, NULL); }
break;
case 92:
#line 152 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-5], NULL, yystack.l_mark[-1]); }
break;
case 93:
#line 153 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 94:
#line 154 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2],NULL, yystack.l_mark[0]); }
break;
case 96:
#line 158 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 97:
#line 159 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 1101 "bin/y.tab.c"
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
