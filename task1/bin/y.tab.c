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

<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes

node *mknode (char *token, node *left, node* middle, node *right);
void printtree (node *tree, int tab);
#define YYSTYPE struct node *
<<<<<<< Updated upstream
#line 38 "bin/y.tab.c"
=======
#line 37 "bin/y.tab.c"
>>>>>>> Stashed changes

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
   20,   17,   17,   17,   17,   17,    8,   23,   23,   23,
   23,   23,   25,   24,   24,   26,   19,   19,   27,   27,
   27,   27,   27,   31,   31,   28,   28,   33,   29,   29,
   29,   34,   35,   36,   37,   38,   38,   38,   39,   39,
   40,   40,   32,   41,   42,   30,   30,   12,   12,   12,
   12,   12,   12,   44,   44,   44,   44,   43,   43,   43,
   43,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    1,    1,    1,    5,    6,    5,    2,
    0,    1,    3,    1,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    3,    1,    6,    5,    1,    5,    4,    1,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    4,    2,    1,    1,
    1,    3,    4,    4,    6,    0,    1,    1,    0,    1,
<<<<<<< Updated upstream
    0,    1,    3,    3,    6,    2,    2,    1,    1,    1,
=======
    0,    1,    3,    3,    5,    2,    2,    1,    1,    1,
>>>>>>> Stashed changes
    1,    1,    1,    6,    1,    3,    4,    3,    3,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
   88,   89,   90,   91,   92,   93,    0,    0,    1,    0,
    4,    5,    6,    0,    0,   47,    0,    0,    2,    3,
    0,   10,    0,    0,    0,    0,   12,    0,    0,    0,
    0,   15,    0,    0,    0,    0,    9,   13,    0,    8,
   35,    7,    0,    0,    0,    0,    0,   63,   61,    0,
    0,    0,   59,   60,   62,   69,   70,   71,    0,   41,
    0,   40,    0,    0,    0,    0,    0,    0,   38,   65,
   64,    0,   54,   55,   53,   49,   48,   56,   50,   51,
   52,    0,    0,   42,    0,   29,   30,   43,   44,   45,
   46,    0,    0,    0,   86,   87,    0,   57,    0,    0,
    0,    0,   72,    0,    0,    0,   78,   32,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   37,    0,   83,    0,   67,    0,   74,   39,
   73,   31,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,   34,    0,    0,   98,    0,   99,
    0,   96,    0,   36,   68,    0,    0,    0,   33,    0,
<<<<<<< Updated upstream
    0,    0,    0,   75,   82,   85,   94,
=======
   85,    0,    0,   75,   82,   94,
>>>>>>> Stashed changes
};
static const YYINT yydgoto[] = {                          8,
    9,   10,   19,   49,   12,   13,   40,   84,   25,   14,
   37,   50,   27,   28,   85,   86,   87,  109,   51,   62,
   69,   70,   88,   89,   90,   91,   71,   53,   54,   55,
   72,   64,  137,   56,   57,   58,   67,  106,  167,  174,
   93,   94,   95,   96,
};
static const YYINT yysindex[] = {                       -91,
    0,    0,    0,    0,    0,    0, -248,    0,    0,  -42,
    0,    0,    0, -253, -248,    0, -249, -245,    0,    0,
 -164,    0, -164, -247, -246, -248,    0, -225, -228, -219,
 -214,    0, -164, -196, -196,  590,    0,    0,  509,    0,
    0,    0, -192, -192, -190, -178,  618,    0,    0, -248,
 -215,  606,    0,    0,    0,    0,    0,    0, -184,    0,
 -155,    0,  618, -178, -178,  618, -188,  573,    0,    0,
    0, -149,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  618,  618,    0,  631,    0,    0,    0,    0,    0,
    0, -274, -182, -175,    0,    0,  618,    0, -170, -162,
   31, -128,    0, -143,   81, -159,    0,    0, -178, -170,
 -192,   81,   31,  618,  618,  618,  618,  618,  618,  618,
  618,  618,  618,  618,  618, -170,  618, -248,  -11, -248,
 -248,  648,    0, -170,    0, -178,    0,  618,    0,    0,
    0,    0, -271,    0,  131,  131,  131,  131,  131, -271,
  131, -271, -271,    0,    0,   81, -267,    0, -165,    0,
 -160,    0, -170,    0,    0,   81, -145, -261,    0, -248,
<<<<<<< Updated upstream
 -134, -248, -143,    0,    0,    0,    0,
=======
    0, -248, -143,    0,    0,    0,
>>>>>>> Stashed changes
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
<<<<<<< Updated upstream
 -132,    0, -132,    0,    0,    0,    0, -131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -270,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -123,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  408,  424,  472,    0,    0,    0,    0,    0,    0,
    0,  557,    0,  665, -116,    0,    0,    0,    0,    0,
    0,  342,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -112,    0,    0,
    0,    0, -158,    0,   42,   92,  142,  192,  242, -108,
  292,  -58,   -8,    0,    0,  358,  488,    0,    0,    0,
    0,    0,    0,    0,    0, -111,    0,  536,    0, -115,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   45,    0,    0,  122,   -7,  149,    0,
    0,   17,  157,    0,  -53,    0,    0,  -59,  -32,  -87,
   -3,    0,   64,    0,    0,   24,  -15,    0,    0,    0,
=======
 -161,    0, -161,    0,    0,    0,    0, -134,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -270,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -125,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  408,  424,  472,    0,    0,    0,    0,    0,    0,
    0,  557,    0,  665, -123,    0,    0,    0,    0,    0,
    0,  342,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -116,    0,    0,
    0,    0, -158,    0,   42,   92,  142,  192,  242, -108,
  292,  -58,   -8,    0,    0,  358,  488,    0,    0,    0,
    0,    0,    0,    0,    0, -112,    0,  536,    0, -132,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   45,    0,    0,  122,   -7,  166,    0,
    0,   17,  157,    0,  -53,    0,    0,  -59,  -32,  -87,
   -3,    0,   62,    0,    0,    0,  -15,    0,    0,    0,
>>>>>>> Stashed changes
  -61,  -38,    0,    0,    0,    0,    0,    0,    0,    0,
  -65,    0,  -79, -126,
};
#define YYTABLESIZE 965
static const YYINT yytable[] = {                         17,
  107,   58,  102,  103,  162,   65,   61,   22,  127,  101,
   17,  133,  105,  115,   16,  127,   15,   16,   32,   98,
   52,  171,  140,   52,  125,   24,   15,  128,  112,  113,
   41,   41,  129,   58,  128,  110,   52,   26,  155,   26,
<<<<<<< Updated upstream
  172,  135,   92,  132,   11,  177,  164,  139,  158,   26,
=======
  172,  135,   92,  132,   11,  176,  164,  139,  158,   26,
>>>>>>> Stashed changes
  160,   21,   52,  142,   20,   23,   97,   30,  104,   31,
  143,  144,  145,  146,  147,  148,  149,  150,  151,  152,
  153,  154,  141,  156,  165,  169,   33,   34,    1,    2,
    3,    4,    5,    6,  166,    7,   35,   43,   36,   44,
   45,   46,    1,    2,    3,    4,    5,    6,   26,   26,
   26,   26,   26,   26,  175,   26,   39,   26,   26,   26,
   26,   26,   63,   26,   66,   99,  100,  108,  111,  130,
  157,   48,  157,  161,   68,   26,  131,   26,   26,   26,
   26,   26,   26,   60,   26,   26,   26,  134,  136,  127,
<<<<<<< Updated upstream
  138,   26,  168,   26,   78,   26,  129,   26,   17,   17,
   17,   17,   17,   17,  170,   17,   42,   17,   17,   17,
   17,   17,  173,   17,  161,    1,    2,    3,    4,    5,
    6,   29,    7,   11,   14,   17,   76,   17,   17,   17,
   17,   17,   17,   77,   17,   17,   17,   79,   80,   38,
   81,   17,  159,   17,  176,   17,    0,   17,   27,   27,
=======
  138,   26,  168,   26,   11,   26,  129,   26,   17,   17,
   17,   17,   17,   17,  170,   17,   42,   17,   17,   17,
   17,   17,  173,   17,  161,    1,    2,    3,    4,    5,
    6,   14,    7,   81,   76,   17,   77,   17,   17,   17,
   17,   17,   17,   79,   17,   17,   17,   80,   29,   38,
  159,   17,    0,   17,    0,   17,    0,   17,   27,   27,
>>>>>>> Stashed changes
   27,   27,   27,   27,    0,   27,    0,   27,   27,   27,
   27,   27,    0,   27,    1,    2,    3,    4,    5,    6,
    0,   18,    0,    0,    0,   27,    0,   27,   27,   27,
   27,   27,   27,    0,   27,   27,   27,    0,    0,    0,
    0,   27,    0,   27,    0,   27,    0,   27,   16,   16,
   16,   16,   16,   16,    0,   16,    0,   16,   16,   16,
   16,   16,    0,   16,   76,   77,    0,    0,   79,   80,
   81,    0,    0,    0,    0,   16,    0,   16,   16,   16,
   16,   16,   16,    0,   16,   16,   16,    0,    0,    0,
    0,   16,    0,   16,    0,   16,    0,   16,   20,   20,
   20,   20,   20,   20,    0,   20,    0,   20,   20,   20,
   20,   20,    0,   20,  114,  115,  116,  117,  118,  119,
  120,  121,    0,  122,  123,  124,  125,   20,   20,   20,
   20,   20,    0,    0,   20,    0,  108,    0,    0,    0,
    0,   20,    0,   20,    0,   20,    0,   20,   21,   21,
   21,   21,   21,   21,    0,   21,    0,   21,   21,   21,
   21,   21,    0,   21,  114,  115,  116,  117,  118,  119,
  120,  121,    0,  122,  123,  124,  125,   21,   21,   21,
   21,   21,    0,    0,   21,    0,    0,    0,    0,    0,
    0,   21,    0,   21,    0,   21,    0,   21,   22,   22,
   22,   22,   22,   22,    0,   22,    0,   22,   22,   22,
   22,   22,    0,   22,  114,  115,    0,    0,    0,    0,
    0,  121,    0,    0,  123,  124,  125,   22,   22,   22,
   22,   22,    0,    0,   22,    0,    0,    0,    0,    0,
    0,   22,    0,   22,    0,   22,    0,   22,   23,   23,
   23,   23,   23,   23,    0,   23,    0,   23,   23,   23,
   23,   23,    0,   23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,   23,   23,
   23,   23,    0,    0,   23,    0,    0,    0,    0,    0,
    0,   23,    0,   23,    0,   23,    0,   23,   24,   24,
   24,   24,   24,   24,    0,   24,    0,   24,   24,   24,
   24,   24,    0,   24,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   24,   24,   24,
   24,   24,    0,    0,   24,    0,    0,    0,    0,    0,
    0,   24,    0,   24,    0,   24,    0,   24,   25,   25,
   25,   25,   25,   25,    0,   25,    0,   25,   25,   25,
   25,   25,    0,   25,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   25,   25,   25,
   25,   25,    0,    0,   25,    0,    0,    0,    0,    0,
    0,   25,    0,   25,    0,   25,    0,   25,   28,   28,
   28,   28,   28,   28,    0,   28,    0,   28,   28,   28,
   28,   28,    0,   28,   84,   84,   84,   84,   84,   84,
    0,   84,    0,   84,   84,   84,   84,   84,    0,   84,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   28,    0,   28,    0,   28,    0,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   84,    0,   84,
    0,   84,    0,   84,  101,  101,  101,  101,  101,  101,
    0,  101,    0,  101,  101,  101,  101,  101,    0,  101,
  100,  100,  100,  100,  100,  100,    0,  100,    0,  100,
  100,  100,  100,  100,    0,  100,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  101,    0,    0,
    0,  101,   10,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  100,    0,    0,    0,  100,   95,   95,
   95,   95,   95,   95,    0,   95,    0,   95,   95,   95,
   95,   95,    0,   95,  101,  101,  101,  101,  101,  101,
    0,  101,    0,  101,  101,  101,  101,  101,    0,  101,
    0,    0,    0,    0,    0,    1,    2,    3,    4,    5,
    6,   95,    7,    0,   43,   95,   44,   45,   46,    0,
   59,    0,    0,    0,    0,    0,    0,  101,    0,    0,
    0,  101,   97,   97,   97,   97,   97,   97,    0,   97,
    0,   97,   97,   97,   97,   97,    0,   97,   48,    0,
    0,    0,   60,   66,   66,   66,   66,   66,   66,    0,
   66,    0,   66,    0,   66,   66,   66,    0,   66,    1,
    2,    3,    4,    5,    6,   97,    7,    0,   43,   97,
   44,   45,   46,    0,    0,    0,    1,    2,    3,    4,
    5,    6,    0,    7,    0,   43,   66,   44,   45,   46,
   66,   47,    1,    2,    3,    4,    5,    6,    0,    7,
    0,   43,   48,   44,   45,   46,   60,    0,    0,    0,
   16,    0,    0,    0,    0,    0,    0,    0,    0,   48,
   73,   74,   75,   76,   77,    0,   78,   79,   80,   81,
    0,    0,    0,    0,    0,   48,    0,    0,    0,   82,
    0,    0,    0,    0,  114,  115,  116,  117,  118,  119,
  120,  121,   83,  122,  123,  124,  125,    0,    0,    0,
  126,  114,  115,  116,  117,  118,  119,  120,  121,    0,
  122,  123,  124,  125,    0,    0,    0,  163,   42,   42,
   42,   42,   42,   42,   42,   42,    0,   42,   42,   42,
   42,    0,    0,    0,   42,
};
static const YYINT yycheck[] = {                          7,
   66,  272,   64,   65,  131,   44,   39,   15,  283,   63,
   18,   99,   66,  285,  263,  283,    0,  263,   26,   52,
   36,  283,  110,   39,  296,  271,   10,  302,   82,   83,
   34,   35,  307,  304,  302,   68,   52,   21,  126,   23,
  302,  101,   50,   97,    0,  172,  134,  109,  128,   33,
  130,  305,   68,  113,   10,  305,  272,  305,   66,  306,
  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,
  124,  125,  111,  127,  136,  163,  302,  306,  257,  258,
  259,  260,  261,  262,  138,  264,  306,  266,  303,  268,
  269,  270,  257,  258,  259,  260,  261,  262,  257,  258,
  259,  260,  261,  262,  170,  264,  303,  266,  267,  268,
  269,  270,  305,  272,  305,  300,  272,  306,  268,  302,
  128,  300,  130,  131,  303,  284,  302,  286,  287,  288,
  289,  290,  291,  304,  293,  294,  295,  300,  267,  283,
<<<<<<< Updated upstream
  300,  300,  308,  302,  279,  304,  307,  306,  257,  258,
  259,  260,  261,  262,  300,  264,   35,  266,  267,  268,
  269,  270,  170,  272,  172,  257,  258,  259,  260,  261,
  262,   23,  264,  306,  306,  284,  300,  286,  287,  288,
  289,  290,  291,  300,  293,  294,  295,  300,  300,   33,
  306,  300,  129,  302,  171,  304,   -1,  306,  257,  258,
=======
  300,  300,  308,  302,  306,  304,  307,  306,  257,  258,
  259,  260,  261,  262,  300,  264,   35,  266,  267,  268,
  269,  270,  170,  272,  172,  257,  258,  259,  260,  261,
  262,  306,  264,  306,  300,  284,  300,  286,  287,  288,
  289,  290,  291,  300,  293,  294,  295,  300,   23,   33,
  129,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
>>>>>>> Stashed changes
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  257,  258,  259,  260,  261,  262,
   -1,  264,   -1,   -1,   -1,  284,   -1,  286,  287,  288,
  289,  290,  291,   -1,  293,  294,  295,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  276,  277,   -1,   -1,  280,  281,
  282,   -1,   -1,   -1,   -1,  284,   -1,  286,  287,  288,
  289,  290,  291,   -1,  293,  294,  295,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,  293,  294,  295,  296,  286,  287,  288,
  289,  290,   -1,   -1,  293,   -1,  306,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,  293,  294,  295,  296,  286,  287,  288,
  289,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  284,  285,   -1,   -1,   -1,   -1,
   -1,  291,   -1,   -1,  294,  295,  296,  286,  287,  288,
  289,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
  289,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
  289,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
  289,  290,   -1,   -1,  293,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  257,  258,  259,  260,  261,  262,
   -1,  264,   -1,  266,  267,  268,  269,  270,   -1,  272,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  300,   -1,  302,   -1,  304,   -1,  306,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,   -1,  302,
   -1,  304,   -1,  306,  257,  258,  259,  260,  261,  262,
   -1,  264,   -1,  266,  267,  268,  269,  270,   -1,  272,
  257,  258,  259,  260,  261,  262,   -1,  264,   -1,  266,
  267,  268,  269,  270,   -1,  272,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,   -1,   -1,
   -1,  304,  305,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  300,   -1,   -1,   -1,  304,  257,  258,
  259,  260,  261,  262,   -1,  264,   -1,  266,  267,  268,
  269,  270,   -1,  272,  257,  258,  259,  260,  261,  262,
   -1,  264,   -1,  266,  267,  268,  269,  270,   -1,  272,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,  300,  264,   -1,  266,  304,  268,  269,  270,   -1,
  272,   -1,   -1,   -1,   -1,   -1,   -1,  300,   -1,   -1,
   -1,  304,  257,  258,  259,  260,  261,  262,   -1,  264,
   -1,  266,  267,  268,  269,  270,   -1,  272,  300,   -1,
   -1,   -1,  304,  257,  258,  259,  260,  261,  262,   -1,
  264,   -1,  266,   -1,  268,  269,  270,   -1,  272,  257,
  258,  259,  260,  261,  262,  300,  264,   -1,  266,  304,
  268,  269,  270,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,  264,   -1,  266,  300,  268,  269,  270,
  304,  272,  257,  258,  259,  260,  261,  262,   -1,  264,
   -1,  266,  300,  268,  269,  270,  304,   -1,   -1,   -1,
  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,
  273,  274,  275,  276,  277,   -1,  279,  280,  281,  282,
   -1,   -1,   -1,   -1,   -1,  300,   -1,   -1,   -1,  292,
   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
  290,  291,  305,  293,  294,  295,  296,   -1,   -1,   -1,
  300,  284,  285,  286,  287,  288,  289,  290,  291,   -1,
  293,  294,  295,  296,   -1,   -1,   -1,  300,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,  293,  294,  295,
  296,   -1,   -1,   -1,  300,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 310
#define YYUNDFTOKEN 357
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"consts : strings",
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
<<<<<<< Updated upstream
"str_ASSIGNMENT_statement : id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT strings",
=======
"str_ASSIGNMENT_statement : id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT",
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
#line 161 "src/part1.y"
=======
#line 160 "src/part1.y"
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
#line 635 "bin/y.tab.c"
=======
#line 634 "bin/y.tab.c"
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
#line 34 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 2:
#line 35 "src/part1.y"
	{yyval = mknode ("global", yystack.l_mark[-1],NULL,yystack.l_mark[0]); }
break;
case 3:
#line 38 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1],NULL, NULL); }
break;
case 4:
#line 39 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 7:
#line 42 "src/part1.y"
	{yyval = mknode ("main", yystack.l_mark[0],NULL, NULL); }
break;
case 8:
#line 43 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 9:
#line 44 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 10:
#line 45 "src/part1.y"
	{yyval = mknode ("procID", yystack.l_mark[-1], yystack.l_mark[0], NULL); }
break;
case 12:
#line 47 "src/part1.y"
	{yyval = mknode ("params:", yystack.l_mark[0], NULL, NULL); }
break;
case 13:
#line 48 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 15:
#line 52 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 54 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 55 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 56 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 57 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 58 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 59 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 60 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 61 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 24:
#line 62 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 25:
#line 63 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 26:
#line 64 "src/part1.y"
	{yyval = mknode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 27:
#line 65 "src/part1.y"
	{yyval = mknode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 28:
#line 66 "src/part1.y"
	{yyval = mknode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 31:
#line 71 "src/part1.y"
	{yyval = mknode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 32:
#line 72 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 33:
#line 73 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 34:
#line 74 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 36:
#line 76 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-3], NULL, yystack.l_mark[-1]); }
break;
case 37:
#line 77 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 39:
#line 80 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 40:
#line 84 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[0], NULL, NULL); }
break;
case 41:
#line 85 "src/part1.y"
	{yyval = mknode (")", NULL, NULL,NULL ); }
break;
case 47:
#line 87 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 48:
#line 88 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 49:
#line 89 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 50:
#line 90 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 51:
#line 91 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 52:
#line 92 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 53:
#line 93 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 54:
#line 94 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 55:
#line 95 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 56:
#line 96 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 57:
#line 98 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 66:
#line 116 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 67:
#line 117 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 68:
#line 119 "src/part1.y"
	{yyval = mknode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 72:
#line 124 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],NULL, yystack.l_mark[0]);}
break;
case 73:
#line 125 "src/part1.y"
	{yyval=mknode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 74:
#line 127 "src/part1.y"
	{yyval=mknode("for", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]);}
break;
case 75:
#line 129 "src/part1.y"
	{yyval=mknode("for conditions:", yystack.l_mark[-4],yystack.l_mark[-2], yystack.l_mark[0]);}
break;
case 83:
#line 133 "src/part1.y"
	{yyval = mknode ("(COND", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 84:
#line 137 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 85:
#line 138 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-5], NULL, yystack.l_mark[0]); }
break;
case 86:
#line 139 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 87:
#line 140 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 88:
#line 142 "src/part1.y"
	{yyval = mknode ("boolean", NULL, NULL, NULL); }
break;
case 89:
#line 143 "src/part1.y"
	{yyval = mknode ("char", NULL, NULL, NULL); }
break;
case 90:
#line 144 "src/part1.y"
	{yyval = mknode ("integer", NULL, NULL, NULL); }
break;
case 91:
#line 145 "src/part1.y"
=======
#line 33 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 2:
#line 34 "src/part1.y"
	{yyval = mknode ("global", yystack.l_mark[-1],NULL,yystack.l_mark[0]); }
break;
case 3:
#line 37 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1],NULL, NULL); }
break;
case 4:
#line 38 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 7:
#line 41 "src/part1.y"
	{yyval = mknode ("main", yystack.l_mark[0],NULL, NULL); }
break;
case 8:
#line 42 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 9:
#line 43 "src/part1.y"
	{yyval = mknode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 10:
#line 44 "src/part1.y"
	{yyval = mknode ("procID", yystack.l_mark[-1], yystack.l_mark[0], NULL); }
break;
case 12:
#line 46 "src/part1.y"
	{yyval = mknode ("params:", yystack.l_mark[0], NULL, NULL); }
break;
case 13:
#line 47 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 15:
#line 51 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 16:
#line 53 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 54 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 55 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 56 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 57 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 58 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 59 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 60 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 24:
#line 61 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 25:
#line 62 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 26:
#line 63 "src/part1.y"
	{yyval = mknode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 27:
#line 64 "src/part1.y"
	{yyval = mknode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 28:
#line 65 "src/part1.y"
	{yyval = mknode ("NOT", NULL, NULL, yystack.l_mark[0]); }
break;
case 31:
#line 70 "src/part1.y"
	{yyval = mknode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 32:
#line 71 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 33:
#line 72 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 34:
#line 73 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 36:
#line 75 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-3], NULL, yystack.l_mark[-1]); }
break;
case 37:
#line 76 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 39:
#line 79 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 40:
#line 83 "src/part1.y"
	{yyval = mknode ("(BLOCK", yystack.l_mark[0], NULL, NULL); }
break;
case 41:
#line 84 "src/part1.y"
	{yyval = mknode (")", NULL, NULL,NULL ); }
break;
case 47:
#line 86 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 48:
#line 87 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 49:
#line 88 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 50:
#line 89 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 51:
#line 90 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 52:
#line 91 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 53:
#line 92 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 54:
#line 93 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 55:
#line 94 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 56:
#line 95 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 57:
#line 97 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 66:
#line 115 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 67:
#line 116 "src/part1.y"
	{yyval = mknode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 68:
#line 118 "src/part1.y"
	{yyval = mknode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 72:
#line 123 "src/part1.y"
	{yyval=mknode("while", yystack.l_mark[-1],NULL, yystack.l_mark[0]);}
break;
case 73:
#line 124 "src/part1.y"
	{yyval=mknode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 74:
#line 126 "src/part1.y"
	{yyval=mknode("for", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]);}
break;
case 75:
#line 128 "src/part1.y"
	{yyval=mknode("for conditions:", yystack.l_mark[-4],yystack.l_mark[-2], yystack.l_mark[0]);}
break;
case 83:
#line 132 "src/part1.y"
	{yyval = mknode ("(COND", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 84:
#line 136 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 85:
#line 137 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-4], NULL, NULL); }
break;
case 86:
#line 138 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 87:
#line 139 "src/part1.y"
	{yyval = mknode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 88:
#line 141 "src/part1.y"
	{yyval = mknode ("boolean", NULL, NULL, NULL); }
break;
case 89:
#line 142 "src/part1.y"
	{yyval = mknode ("char", NULL, NULL, NULL); }
break;
case 90:
#line 143 "src/part1.y"
	{yyval = mknode ("integer", NULL, NULL, NULL); }
break;
case 91:
#line 144 "src/part1.y"
>>>>>>> Stashed changes
	{yyval = mknode ("string", NULL, NULL, NULL); }
break;
case 92:
#line 145 "src/part1.y"
	{yyval = mknode ("intptr", NULL, NULL, NULL); }
break;
case 93:
#line 146 "src/part1.y"
<<<<<<< Updated upstream
	{yyval = mknode ("intptr", NULL, NULL, NULL); }
break;
case 93:
#line 147 "src/part1.y"
	{yyval = mknode ("charptr", NULL, NULL, NULL); }
break;
case 94:
#line 149 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-5], NULL, yystack.l_mark[0]); }
break;
case 95:
#line 150 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 96:
#line 151 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2],yystack.l_mark[0], NULL); }
break;
case 98:
#line 155 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 99:
#line 156 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 1105 "bin/y.tab.c"
=======
	{yyval = mknode ("charptr", NULL, NULL, NULL); }
break;
case 94:
#line 148 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-5], NULL, yystack.l_mark[-1]); }
break;
case 95:
#line 149 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[0], NULL,NULL); }
break;
case 96:
#line 150 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2],NULL, yystack.l_mark[0]); }
break;
case 98:
#line 154 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 99:
#line 155 "src/part1.y"
	{yyval = mknode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 1104 "bin/y.tab.c"
>>>>>>> Stashed changes
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
