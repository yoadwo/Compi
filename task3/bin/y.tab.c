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

#line 2 "src/part3.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct treeNode{
    char *token;
    struct treeNode *left;
    struct treeNode *middle;
    struct treeNode *right;
} treeNode;

typedef struct symbolNode{
    int isProc; /*0 if primitive symbol, 1 if is procedure*/
	char* id;
	char* type;
	char* data;
	int scopeID;
	struct treeNode *params;
	struct symbolNode *next;
} symbolNode;

typedef struct scopeNode{
	char* scopeName;
	int scopeNum;
	int scopeLevel;
	symbolNode *symbolTable;
	struct scopeNode *next;
} scopeNode;


symbolNode* head = NULL;
scopeNode* topStack = NULL;
int SCOPE_NUM=0;

void startSematics(treeNode *root);
symbolNode* scopeLookup (char* token);
char* checkEvaluation(treeNode* tNode);
void printInfo(treeNode *head);
treeNode *mktreeNode (char *token, treeNode *left, treeNode* middle, treeNode *right);
void printtree (treeNode *tree, int tab);
int isCompileErrors(scopeNode *root,treeNode* tNode);
int isSimilarSymbols(char* scopeName, struct symbolNode* root);
int checkDuplicateSymbols(scopeNode* root);
int checkDuplicateProcs(scopeNode *root);
int checkBracketsExpression(treeNode *tNode);
void pushStatements(treeNode* tNode,int scopeLevel);
void pushScopeStatements(treeNode* tNode);
void pushSymbols( char* type,treeNode* tNode);
void pushProcSymbols( treeNode* tNode);
void pushSignatureParamsToTable(scopeNode **currentScope, treeNode *params);
void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params);
void pushScopeToStack(struct scopeNode** head_ref, char* scopeName,treeNode *params, treeNode* statements,int scopeLevel);

void printSymbolTable(struct scopeNode *node);
void printScopes(struct scopeNode *node);

symbolNode* symbolLookup (struct symbolNode** head_ref, char* token);
int isConst(treeNode* tNode);
int isParamsMatch(treeNode* callParams, treeNode* declaredParams/*, struct symbolNode* currentSymTab*/);
int isReturnTypeMatch(treeNode *tNode);


int compareCallDeclare( char *token, treeNode *callParams);
#define YYSTYPE struct treeNode *
#line 86 "bin/y.tab.c"

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
#define ABSOLUTE 300
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
   10,    8,    9,    9,   15,   15,   16,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   22,   22,   22,   22,
   22,   22,   22,   23,   23,   23,   23,   23,   18,   24,
   11,   11,    7,    7,    7,   26,   26,   28,   28,   27,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   35,
   13,   29,   29,   29,   29,   29,   31,   30,   30,   32,
   33,   34,   37,   38,   38,   36,   36,   19,   20,   25,
   25,   25,   25,   39,   40,   40,   40,   40,   42,   42,
   42,   42,   42,   47,   47,   43,   43,   44,   44,   49,
   45,   45,   45,   50,   51,   52,   53,   54,   54,   55,
   55,   56,   56,   48,   46,   46,   57,   12,   12,   12,
   12,   12,   12,   14,   58,   58,   58,   58,   59,   59,
   59,   59,   41,   41,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    2,    1,    1,    1,    5,    5,    5,
    2,    2,    0,    1,    3,    1,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    1,    1,    3,    1,
    5,    4,    1,    5,    3,    2,    1,    2,    4,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    4,    1,    3,    1,    4,    4,    2,    2,    2,
    1,    1,    1,    2,    2,    1,    2,    1,    1,    1,
    1,    2,    2,    1,    1,    1,    3,    3,    4,    2,
    1,    1,    1,    3,    4,    4,    6,    0,    1,    0,
    1,    0,    1,    3,    3,    3,    6,    1,    1,    1,
    1,    1,    1,    1,    6,    3,    4,    1,    3,    3,
    1,    1,    2,    2,
};
static const YYINT yydefred[] = {                         0,
  128,  129,  130,  131,  132,  133,    0,    0,    1,    0,
    3,    5,    6,    7,    0,    0,    0,    0,    0,    2,
    4,    0,    0,   71,   11,   12,    0,    0,    0,   14,
    0,    0,    0,    0,   17,    0,    0,    0,    8,   53,
    9,   15,    0,   10,  134,    0,    0,    0,    0,    0,
    0,   91,    0,   60,  101,    0,    0,    0,    0,   58,
  106,    0,    0,   92,    0,    0,    0,   99,  100,    0,
  111,  112,  113,    0,    0,    0,    0,    0,    0,    0,
    0,  104,  105,    0,    0,   89,    0,    0,    0,    0,
  144,  143,    0,    0,    0,    0,   55,  102,   90,   94,
   95,   97,  103,   78,   79,   77,   73,   72,   81,   80,
   74,   75,   76,    0,    0,    0,    0,    0,    0,    0,
   34,   35,   36,    0,    0,   62,   63,   64,   65,   66,
   67,   68,   69,    0,    0,    0,    0,  114,    0,  119,
    0,   50,    0,    0,   59,  107,    0,    0,    0,    0,
    0,    0,    0,   83,    0,    0,    0,   88,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   52,  124,
    0,  109,    0,  116,  115,    0,  139,    0,  140,    0,
  136,    0,   82,   54,   70,   49,    0,    0,   21,   29,
    0,    0,    0,    0,   20,   28,   33,   25,    0,    0,
    0,    0,   32,   24,    0,   38,   39,   40,   41,   42,
   43,   44,   45,   51,  110,    0,    0,    0,   84,   87,
   86,    0,    0,    0,  123,  117,  127,  135,
};
static const YYINT yydgoto[] = {                          8,
    9,   10,   11,   55,   13,   14,   39,   15,   28,   16,
   44,   17,  118,   18,   30,   31,  119,  120,  121,  122,
  123,  124,  152,  143,   59,   76,   60,   61,  126,  127,
  128,  129,  130,  131,  132,  133,  153,  154,   63,   64,
   65,   66,   67,   68,   69,   70,   84,   78,  182,   71,
   72,   73,   81,  141,  227,  236,   90,   91,   92,
};
static const YYINT yysindex[] = {                       322,
    0,    0,    0,    0,    0,    0, -190,    0,    0,  322,
    0,    0,    0,    0, -239, -203, -153, -153, -189,    0,
    0,  338,  338,    0,    0,    0, -184, -176, -153,    0,
 -185, -172, -158, -158,    0,  338, -157,  -85,    0,    0,
    0,    0,  -18,    0,    0, -168, -168, -156,   45, -152,
 -153,    0,  -85,    0,    0, -254, -237, -121, -257,    0,
    0, -141,   30,    0, -134,   45,   45,    0,    0, -132,
    0,    0,    0,   76, -102, -104,   76,   45,   45, -254,
 -106,    0,    0,  -67, -101,    0, -101, -225,  -94,  -93,
    0,    0,   76,   76,   76,  -88,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76, -153, -153,   76, -242,   25,   27,
    0,    0,    0,  300, -170,    0,    0,    0,    0,    0,
    0,    0,    0,  -83, -101, -227,  -47,    0,  -54,    0,
  -30,    0,   45, -168,    0,    0, -254,   55, -254, -153,
 -170, -166,  -60,    0, -170, -101, -170,    0,  -27, -227,
 -124,  109,  109,  109,  109,  109,  109,  109,  109,  109,
  109,  109,  109,  109,  109,   76,   76, -101,    0,    0,
   45,    0,   76,    0,    0, -274,    0,  -34,    0,  -31,
    0,   76,    0,    0,    0,    0,  -33,  -25,    0,    0,
 -262, -205, -262, -205,    0,    0,    0,    0, -262, -205,
 -262, -205,    0,    0,   27,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -170,  -22, -270,    0,    0,
    0, -254,    2, -153,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -12,  -12,    0,    0,    0,    0,    0,    0,    0,
  -11,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -251,    0,    0, -250, -248,    0,    0,    0,
    0,    0,    0,  -16,    0,    0,    0,    0,    0,   -3,
    0,    0,    0,    0,    0,    0,    0, -192,    9,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -29,  -96, -179,
    0,    0,    0,  -95,   29,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -35,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -120,   11,    0,    0,  -70,    0,  -53,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,    0,   39,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  110,  131,  152,  173,    0,    0,    0,    0,  194,  215,
  236,  257,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,   42,    0,    0,
    0,   13,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  315,  142,    0,    0,  292,    0,  305,    0,
    0,   98,  -17,    0,  306,    0,  198,  403,    0,  -36,
    0,  431,  -21,  -84,   41,  270,   -8,  -15,  -75,    0,
    0,  113,    0,   22,    0,    0,    0,  155,    0,   24,
    0,  -41,  -38,    0,    0,  -52,  -73,  -32,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -147,   19,
};
#define YYTABLESIZE 606
static const YYINT yytable[] = {                         25,
   26,   58,  191,   89,  137,  138,   58,   82,   24,   93,
   83,   35,   58,  233,   79,   96,   58,   40,   40,   58,
   57,   93,   96,  162,   98,   57,   58,  140,  147,   58,
   58,   57,  234,   86,  165,   57,   82,   82,   88,   83,
   83,   58,   58,   58,   51,   57,   93,   54,   57,   57,
   97,  180,  125,   93,   96,  136,   98,  176,   93,   62,
   57,   57,  139,   94,   62,  161,   22,  177,   94,  184,
   62,  151,  188,  155,   62,  196,  145,  147,  146,  142,
  166,   19,  148,   75,   62,  198,  238,   62,   62,  101,
  102,  169,  157,   87,   89,  160,   89,  158,  159,   62,
   62,   82,   23,   99,   83,   48,   58,  225,  141,   24,
   58,  185,   58,   11,  176,   48,   27,   36,  176,   29,
   29,   48,   33,   48,  177,   57,  179,   48,  177,  186,
   34,  186,  190,   29,   37,   56,  192,   77,   24,   82,
   56,   12,   83,  197,   58,   38,   43,  194,   85,   80,
   56,   21,  107,  108,  222,  223,  111,  112,  113,   98,
   56,  226,   95,   57,   62,  187,  100,  189,  103,  224,
   74,    1,    2,    3,    4,    5,    6,   24,   45,  235,
  125,   46,  125,   47,   48,   49,  125,   50,   37,   47,
   37,   37,   37,   37,   37,   58,  135,   37,   37,   47,
  142,  144,   62,   54,   37,   47,   37,   47,  149,  150,
   37,   47,  156,   51,  139,   52,  190,  178,   53,   54,
  181,  108,  108,  108,  108,  108,  108,  108,  108,   93,
  126,  108,  126,  108,  108,  108,  126,  108,    1,    2,
    3,    4,    5,    6,   24,   45,  193,   46,   46,   46,
   47,   48,   49,   46,   74,   61,   61,   61,   61,   61,
   61,   61,   61,  108,   61,   61,   61,   61,  108,  108,
  183,   61,  195,   61,  228,  230,  148,   61,  232,  134,
   51,  110,   52,  231,   57,   53,    1,    2,    3,    4,
    5,    6,   24,   45,   13,   16,   46,  118,   47,   48,
   49,    1,    2,    3,    4,    5,    6,   24,   45,  142,
  162,   46,  166,   47,   48,   49,  163,   85,  167,  122,
  164,  165,  168,  169,   20,   41,  138,   32,   51,   56,
   52,  107,  108,   53,  120,  111,  112,  113,   24,  141,
  121,   42,  137,   51,  134,  237,  229,    0,   53,  104,
  105,  106,  107,  108,  109,  110,  111,  112,  113,  199,
  201,  203,  205,  207,  209,  211,  213,    0,  114,    0,
    0,   24,    0,  115,   51,  116,    0,    0,    0,    0,
    0,  117,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,    0,    0,   19,    0,   19,   19,   19,   19,
   19,   19,    0,   19,   19,   19,  115,   51,  116,    0,
   19,    0,   19,    0,  117,   27,   19,   27,   27,   27,
   27,   27,   27,    0,   27,   27,   27,    0,    0,    0,
    0,   27,    0,   27,    0,    0,   18,   27,   18,   18,
   18,   18,   18,   18,    0,   18,   18,   18,    0,    0,
    0,    0,   18,    0,   18,    0,    0,   26,   18,   26,
   26,   26,   26,   26,   26,    0,   26,   26,   26,    0,
    0,    0,    0,   26,    0,   26,    0,    0,   31,   26,
   31,   31,   31,   31,   31,   31,    0,   31,   31,   31,
    0,    0,    0,    0,   31,    0,   31,    0,    0,   23,
   31,   23,   23,   23,   23,   23,   23,    0,   23,   23,
   23,    0,    0,    0,    0,   23,    0,   23,    0,    0,
   30,   23,   30,   30,   30,   30,   30,   30,    0,   30,
   30,   30,    0,    0,    0,    0,   30,    0,   30,    0,
    0,   22,   30,   22,   22,   22,   22,   22,   22,    0,
   22,   22,   22,    0,    0,    0,    0,   22,    0,   22,
    0,    0,    0,   22,  200,  202,  204,  206,  208,  210,
  212,  214,  215,  215,  215,  215,  215,  215,    1,    2,
    3,    4,    5,    6,    0,    7,  170,  171,  172,  173,
  174,    0,    0,  175,    1,    2,    3,    4,    5,    6,
  216,  217,  218,  219,  220,  221,
};
static const YYINT yycheck[] = {                         17,
   18,   38,  150,   56,   78,   79,   43,   49,  263,  284,
   49,   29,   49,  284,   47,  273,   53,   33,   34,   56,
   38,  273,  273,  286,  273,   43,   63,   80,  303,   66,
   67,   49,  303,   51,  297,   53,   78,   79,   56,   78,
   79,   78,   79,   80,  299,   63,  284,  305,   66,   67,
   59,  136,   74,  305,  305,   77,  305,  285,  284,   38,
   78,   79,   80,  306,   43,  308,  306,  295,  306,  143,
   49,   93,  148,   95,   53,  160,   85,  303,   87,  307,
  286,  272,  308,   43,   63,  161,  234,   66,   67,   66,
   67,  297,  114,   53,  147,  117,  149,  115,  116,   78,
   79,  143,  306,   63,  143,  285,  143,  181,  301,  263,
  147,  144,  149,  306,  285,  295,  306,  303,  285,   22,
   23,  301,  307,  303,  295,  143,  135,  307,  295,  147,
  307,  149,  150,   36,  307,   38,  303,  306,  263,  181,
   43,    0,  181,  161,  181,  304,  304,  156,  301,  306,
   53,   10,  277,  278,  176,  177,  281,  282,  283,  301,
   63,  183,  284,  181,  143,  147,  301,  149,  301,  178,
  273,  257,  258,  259,  260,  261,  262,  263,  264,  232,
  301,  267,  303,  269,  270,  271,  307,  273,  285,  285,
  287,  288,  289,  290,  291,  232,  301,  294,  295,  295,
  307,  269,  181,  305,  301,  301,  303,  303,  303,  303,
  307,  307,  301,  299,  232,  301,  234,  301,  304,  305,
  268,  257,  258,  259,  260,  261,  262,  263,  264,  284,
  301,  267,  303,  269,  270,  271,  307,  273,  257,  258,
  259,  260,  261,  262,  263,  264,  307,  301,  267,  303,
  269,  270,  271,  307,  273,  285,  286,  287,  288,  289,
  290,  291,  292,  299,  294,  295,  296,  297,  304,  305,
  301,  301,  300,  303,  309,  309,  308,  307,  301,  263,
  299,  280,  301,  309,  301,  304,  257,  258,  259,  260,
  261,  262,  263,  264,  307,  307,  267,  301,  269,  270,
  271,  257,  258,  259,  260,  261,  262,  263,  264,  301,
  286,  267,  286,  269,  270,  271,  292,  307,  292,  307,
  296,  297,  296,  297,   10,   34,  301,   23,  299,  301,
  301,  277,  278,  304,  301,  281,  282,  283,  263,  301,
  301,   36,  301,  299,   75,  233,  192,   -1,  304,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  162,
  163,  164,  165,  166,  167,  168,  169,   -1,  293,   -1,
   -1,  263,   -1,  298,  299,  300,   -1,   -1,   -1,   -1,
   -1,  306,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,   -1,   -1,  285,   -1,  287,  288,  289,  290,
  291,  292,   -1,  294,  295,  296,  298,  299,  300,   -1,
  301,   -1,  303,   -1,  306,  285,  307,  287,  288,  289,
  290,  291,  292,   -1,  294,  295,  296,   -1,   -1,   -1,
   -1,  301,   -1,  303,   -1,   -1,  285,  307,  287,  288,
  289,  290,  291,  292,   -1,  294,  295,  296,   -1,   -1,
   -1,   -1,  301,   -1,  303,   -1,   -1,  285,  307,  287,
  288,  289,  290,  291,  292,   -1,  294,  295,  296,   -1,
   -1,   -1,   -1,  301,   -1,  303,   -1,   -1,  285,  307,
  287,  288,  289,  290,  291,  292,   -1,  294,  295,  296,
   -1,   -1,   -1,   -1,  301,   -1,  303,   -1,   -1,  285,
  307,  287,  288,  289,  290,  291,  292,   -1,  294,  295,
  296,   -1,   -1,   -1,   -1,  301,   -1,  303,   -1,   -1,
  285,  307,  287,  288,  289,  290,  291,  292,   -1,  294,
  295,  296,   -1,   -1,   -1,   -1,  301,   -1,  303,   -1,
   -1,  285,  307,  287,  288,  289,  290,  291,  292,   -1,
  294,  295,  296,   -1,   -1,   -1,   -1,  301,   -1,  303,
   -1,   -1,   -1,  307,  162,  163,  164,  165,  166,  167,
  168,  169,  170,  171,  172,  173,  174,  175,  257,  258,
  259,  260,  261,  262,   -1,  264,  287,  288,  289,  290,
  291,   -1,   -1,  294,  257,  258,  259,  260,  261,  262,
  170,  171,  172,  173,  174,  175,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 311
#define YYUNDFTOKEN 373
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
"DEREFERENCE","ABSOLUTE","SEMICOLON","COLON","COMMA","LEFTBRACE","RIGHTBRACE",
"LEFTPAREN","RIGHTPAREN","LEFTBRACKET","RIGHTBRACKET","PERCENT",
"LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"procVoid : procIDVoid LEFTPAREN params RIGHTPAREN block_return_void_statements",
"procValue : procIDValue LEFTPAREN params RIGHTPAREN block_return_value_statements",
"procIDValue : varType id",
"procIDVoid : void id",
"params :",
"params : paramsDeclare",
"paramsDeclare : param COMMA paramsDeclare",
"paramsDeclare : param",
"param : varType id",
"operator : operator PLUS operator",
"operator : operator MINUS operator",
"operator : operator MULTI operator",
"operator : operator DIVISION operator",
"operator : Pexpr PLUS Pexpr",
"operator : Pexpr MINUS Pexpr",
"operator : Pexpr MULTI Pexpr",
"operator : Pexpr DIVISION Pexpr",
"operator : operator PLUS Pexpr",
"operator : operator MINUS Pexpr",
"operator : operator MULTI Pexpr",
"operator : operator DIVISION Pexpr",
"operator : Pexpr PLUS operator",
"operator : Pexpr MINUS operator",
"operator : Pexpr MULTI operator",
"operator : Pexpr DIVISION operator",
"operator : address",
"operator : derefID",
"operator : consts",
"compBoolExpr : operator",
"compBoolExpr : compBoolExpr EQUAL compBoolExpr",
"compBoolExpr : compBoolExpr GREATER compBoolExpr",
"compBoolExpr : compBoolExpr GREATEREQUAL compBoolExpr",
"compBoolExpr : compBoolExpr LESS compBoolExpr",
"compBoolExpr : compBoolExpr LESSEQUAL compBoolExpr",
"compBoolExpr : compBoolExpr NOTEQUAL compBoolExpr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
"expr : compBoolExpr",
"expr : Pexpr",
"Pexpr : LEFTPAREN expr rightParen",
"rightParen : RIGHTPAREN",
"block_return_value_statements : LEFTBRACE newline return SEMICOLON rightbrace",
"block_return_value_statements : LEFTBRACE return SEMICOLON rightbrace",
"block_return_void_statements : emptyBlock",
"block_return_void_statements : LEFTBRACE newline RETURN SEMICOLON rightbrace",
"block_return_void_statements : LEFTBRACE newline rightbrace",
"return : RETURN expr",
"return : RETURN",
"emptyBlock : LEFTBRACE rightbrace",
"emptyBlock : LEFTBRACE RETURN SEMICOLON rightbrace",
"rightbrace : RIGHTBRACE",
"consts : id",
"consts : numbers",
"consts : booleans",
"consts : csnull",
"consts : strings",
"consts : chars",
"consts : procCall",
"consts : absolute",
"consts : stringArray",
"absolute : ABSOLUTE id ABSOLUTE",
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
"args : argsDeclare",
"argsDeclare : expr COMMA argsDeclare",
"argsDeclare : expr",
"stringArray : id LEFTBRACKET numbers RIGHTBRACKET",
"stringArray : id LEFTBRACKET id RIGHTBRACKET",
"address : ADDRESS id",
"derefID : DEREFERENCE id",
"newline : declarations newline",
"newline : SEMICOLON",
"newline : statements",
"newline : declarations",
"declarations : variable_declare_statements SEMICOLON",
"statements : statement statements",
"statements : statement",
"statements : block_statements statements",
"statements : block_statements",
"statement : IF_statements",
"statement : LOOP_statements",
"statement : proc",
"statement : procCall SEMICOLON",
"statement : ASSIGNMENT_statement SEMICOLON",
"statements_type : statement",
"statements_type : block_statements",
"block_statements : emptyBlock",
"block_statements : LEFTBRACE newline rightbrace",
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
"varType : STRING",
"varType : INTPTR",
"varType : CHARPTR",
"void : VOID",
"StringDeclare : id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare",
"StringDeclare : str_ASSIGNMENT_statement COMMA StringDeclare",
"StringDeclare : id LEFTBRACKET numbers RIGHTBRACKET",
"StringDeclare : str_ASSIGNMENT_statement",
"variablesDeclare : id COMMA variablesDeclare",
"variablesDeclare : ASSIGNMENT_statement COMMA variablesDeclare",
"variablesDeclare : id",
"variablesDeclare : ASSIGNMENT_statement",
"variable_declare_statements : varType variablesDeclare",
"variable_declare_statements : varType StringDeclare",

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
#line 321 "src/part3.y"

#include "lex.yy.c"
int main(){
    return yyparse();
}

/* START SEMANTICS:  
    start top down creation and semantics check of tree created by grammar rules
    */
void startSematics(treeNode *root){
      
    // create a stack of scopes, each one has its own list of symbols (symbol table)
    pushStatements(root, 1);
    // print scopes, symbol tables and concrete syntax tree
    // check for duplicate symbols, calls for non existing symbols and type checking
    if (!isCompileErrors(topStack,root))
        printf ("build failed, check compile errors\n");
    printInfo(root);
    
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

/*  IS COMPILE ERRORS
    return 1 if all checks pass, otherwise 0;
    */

    
    // perform all checks, accumulate results and return final test result
int isCompileErrors(scopeNode *root,treeNode* tNode){
    // return 1 if all checks pass, otherwise 0;
    int pass = 1;
    pass = checkDuplicateSymbols(root) && pass;
    return pass;
}

/* IS DECLARED
    functions checks if used symbol was indeed declared earlier
    */
int isDeclared(treeNode *tNode){
    // bad cases: "procedure", '('
    if (!strcmp(tNode->token, ")"))
        return 1;
    if (!strcmp(tNode->token, "procedure"))
        return 1;
    
        
    //base 1: node has no children -> node is identifier, do scope lookup
    if (tNode->left == NULL && tNode->middle == NULL  && tNode->right == NULL ){
        // ')' can also be seen as a leaf
        char sign = (tNode->token)[0];
        if (sign == '&' || sign == '^'){
            if (sizeof tNode->token == 2){
                char* id;
                id[0] = (tNode->token)[1];
                symbolNode *symbol =  scopeLookup(id);
                if (symbol == NULL){
                    printf ("undefined variable [%s]\n", tNode->token); //add scope?
                    return 0;
                    }
                else
                    return 1;
            }
            else{
                char* id = (char*)(malloc (sizeof(tNode->token) + 1));
                //copy tNode->token from [1] to end into id
                int i = 1;
                for (i; i < sizeof((tNode->token)-1); i++){
                    id[i-1] = tNode->token[i];
                    }
                symbolNode *symbol =  scopeLookup(id);
                if (symbol == NULL){
                    printf ("undefined variable [%s]\n", tNode->token); //add scope
                    return 0;
                    }
                else
                    return 1;
                }
        }
        symbolNode *symbol =  scopeLookup(tNode->token);
        if (symbol == NULL){
            printf ("undefined variable [%s]\n", tNode->token); //add scope
            return 0;
            }
        else
            return 1;
        }
    //base 2: node has children -> node is ABS (identifier), do scope lookup
    if (!strcmp(tNode->token,"ABS")){
        symbolNode *symbol =  scopeLookup(tNode->middle->token);
        if (symbol == NULL){
            printf ("undefined variable [%s]\n", tNode->middle->token); //add scope?
                return 0;
                    }
                else
                    return 1;
    }
    //base 3: node has children -> node is ARRAY (string[const\id]), return 1 if has const child or scopelookup result if has id child)
    if (!strcmp(tNode->token,"ARRAY")){
        if (isConst(tNode->right))
            return 1;
        else{
            symbolNode *symbol =  scopeLookup(tNode->right->token);
            if (symbol == NULL){
                printf ("undefined variable [%s]\n", tNode->right->token); //add scope?
                return 0;
            }
            else
                return 1;
        }
    }
            
    //base 4: node is const
    if (isConst(tNode))
        return 1;
    // else - recursive call
    int result = 1;
    if (tNode->left != NULL  && strcmp(tNode->left->token, "STATEMENT"))
        result = isDeclared(tNode->left ) && result;
    if (tNode->middle != NULL && strcmp(tNode->middle->token, "STATEMENT"))
        result =  isDeclared(tNode->middle ) && result;
    if (tNode->right != NULL && strcmp(tNode->right->token, "STATEMENT"))
        result =  isDeclared(tNode->right) && result;
    return result;
    
}

/*  CHECK DUPLICATE SYMBOLS
    check if two symbols were declared in same scope 
*/
int checkDuplicateSymbols(scopeNode* root){
    struct scopeNode * currentScope=root;
    // iterate all scopes
    while(currentScope!=NULL){
        //only check if within one scope, some symbol exists twices
        if(!isSimilarSymbols(currentScope->scopeName, currentScope->symbolTable))
            return 0;
        currentScope=currentScope->next;
    }
    // if all scopes pass, return 1
    return 1;
}

/*  COMPARE CALL DECLARE
    check ALL scopes, each symbol table in scope, if there exists any function's' params that match the called function's' params  
    function return 1 if some function with matching signature exists, 0 otherwise 
*/ 
int compareCallDeclare(char *token, treeNode *callParams){
    // var currentScope iterates all scopes
    // var currentSymtab iterates symbols in current scope (root)
    scopeNode *currentScope = topStack;
    symbolNode *currentSymTab;
    while (currentScope != NULL){
        currentSymTab = currentScope->symbolTable;
        if (currentSymTab != NULL){
        // search for proc in current scope
            symbolNode *funcSymbol = symbolLookup(&currentSymTab, token);
            if (funcSymbol !=NULL)
                if (isParamsMatch(callParams, funcSymbol->params/*, currentSymTab*/))
                    return 1;
        }
        currentScope = currentScope->next; 
    }
    printf ("no procedure was defined with arguements matching called function (%s)\n", token);
    return 0;
    
}
/*  CHECK BRACKETS EXPRESSION
    functions checks if expression inside brackets is from type integer
    tNode is the ARRAY node

*/
int checkBracketsExpression(treeNode *tNode){
    symbolNode* bracketExpression = scopeLookup (tNode->right->token);
    if (bracketExpression){
        //printf("checking Brackets Expression for variable %s\n",bracketExpression->id);
        if ( strcmp (bracketExpression->type, "integer")){
            printf ("Brackets expression type for string must be integer (not %s)\n",bracketExpression->type );
        }
    }
        
    
}

char* checkEvaluation(treeNode* tNode){
    
    if (isConst(tNode)){
        return (tNode->left->token);
    }
    
    /*else if the node is variable (we will look for him in symbol table)*/
    else if(!isConst(tNode) && tNode->left == NULL && tNode->middle == NULL && tNode->right == NULL){
        char* varType;
        symbolNode* node;
        node=scopeLookup(tNode->token);
        if(node!=NULL){
            varType=node->type;
            //string types are saved as strings but are treated as charp ~~~
            if (!strcmp(varType,"STRING"))
                return "charp";
            else
                return varType;
        }
        else
            return "null";
    }
    
    if (!strcmp(tNode->token,"ARRAY")){
            checkBracketsExpression(tNode);
            return "char";
    }
    
    
    if(!strcmp(tNode->token,"+")||!strcmp(tNode->token,"-")||!strcmp(tNode->token,"*")||!strcmp(tNode->token,"/")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "integer";
        
        else {
            if (strcmp(right, "expressionError") && strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }
    }
    if(!strcmp(tNode->token,">")||!strcmp(tNode->token,"<")||!strcmp(tNode->token,">=")||!strcmp(tNode->token,"<=")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "boolean";
        
        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }
    
    }
    if(!strcmp(tNode->token,"&&")||!strcmp(tNode->token,"||")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"boolean")&&!strcmp(right,"boolean"))
            return "boolean";
        
        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }

    }
    if(!strcmp(tNode->token,"==")||!strcmp(tNode->token,"!=")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"boolean")&&!strcmp(right,"boolean"))
            return "boolean";
            
        else if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "boolean";
            
        else if(!strcmp(left,"intp")&&!strcmp(right,"intp"))
            return "boolean";  
            
        else if(!strcmp(left,"char")&&!strcmp(right,"char"))
            return "boolean";
            
        else if(!strcmp(left,"charp")&&!strcmp(right,"charp"))
            return "boolean";     
            

        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }

    }
    
    if(!strcmp(tNode->token,"=")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"boolean")&&!strcmp(right,"boolean"))
            return "boolean";
            
        else if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "integer";
            
        else if(!strcmp(left,"intp")&&!strcmp(right,"intp"))
            return "intp";  
            
        else if(!strcmp(left,"char")&&!strcmp(right,"char"))
            return "char";
            
        else if(!strcmp(left,"charp")&&!strcmp(right,"charp"))
            return "charp";     
            

        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }

    }

    if(!strcmp(tNode->token,"NOT")){

        char*  left;
        left=checkEvaluation(tNode->left);
        if(!strcmp(left,"boolean"))
            return "boolean";

        else {
            if (strcmp(left, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s\n",tNode->token,left);
            return "expressionError";
        }
    }
    
    if (!strcmp(tNode->token,"(")){
        char* left;
        left = checkEvaluation(tNode->left);
        return left;
    }
    
    if (tNode->left != NULL){
        checkEvaluation(tNode->left);
    }
    if (tNode->middle != NULL){
        checkEvaluation(tNode->middle);
    }
    if (tNode->right != NULL){
        checkEvaluation(tNode->right);
    }
}


/* PUSH STATEMENTS
    iterates all statements. statements that should open a new scope also call "push scope to stack"
    else, recursive call to all statements children
*/
void pushStatements(treeNode* tNode,int scopeLevel){
    if(tNode==NULL)
        return;
        
    //int scopeID=0;
    // struct scopeNode* currentStack;
    // currentStack= (struct scopeNode*) malloc(sizeof(struct scopeNode));
    // memcpy(&currentStack,&topStack,sizeof(topStack));
    if(!strcmp(tNode->token,"IF")){
        scopeLevel++;
        pushScopeToStack(&topStack, "IF",NULL, tNode->middle,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"ELSE")){
        scopeLevel++;
        pushScopeToStack(&topStack, "ELSE",NULL, tNode->left,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"while")){
        scopeLevel++;
        pushScopeToStack(&topStack,"while",NULL, tNode->right,scopeLevel);
        //  return;
    }
    if(!strcmp(tNode->token,"do-while")){
        scopeLevel++;
        pushScopeToStack(&topStack, "do-while",NULL, tNode->left,scopeLevel);
        // return;
    }
     if(!strcmp(tNode->token,"NESTED")){
        scopeLevel++;
        pushScopeToStack(&topStack, "NESTED",NULL, tNode->left,scopeLevel);
        // return;
    }
    
    if(!strcmp(tNode->token,"BLOCK")){
        pushStatements(tNode->left,scopeLevel);
    }
    
    if(!strcmp(tNode->token,"for")){
        scopeLevel++;
        pushScopeToStack(&topStack, "for",NULL, tNode->right,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"procedure")){
        //pushProcSymbols(tNode);
        scopeLevel++;
        pushScopeToStack(&topStack,"procedure",tNode->middle, tNode->right,scopeLevel);
        isReturnTypeMatch(tNode);
        //return;
    }
    if(!strcmp(tNode->token,"NESTED")){
        //pushProcSymbols(tNode);
        scopeLevel++;
        pushScopeToStack(&topStack,"NESTED",NULL, tNode->left,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"main")){
        scopeLevel++;
        pushScopeToStack(&topStack, "main",NULL, tNode->left->left,scopeLevel);
        //return;
    }
   
    // if(!strcmp(tNode->token,"DECLARE")){
    //  pushSymbols(tNode1->left->token,tNode1->right);
    //  return;
    // }
    
    pushStatements(tNode->left,scopeLevel);
    pushStatements(tNode->middle,scopeLevel);
    pushStatements(tNode->right,scopeLevel);
   

    }

/*  PUSH SCOPE STATEMENTES
    
    
*/
void pushScopeStatements(treeNode* tNode){
    if(tNode==NULL)
        return;
    
    /*
    for any of the following statements, we do not want to explore them recursively
    so we return upon seeing them
    */
    if(!strcmp(tNode->token,"ELSE")){
        return;
    }
    if (!strcmp(tNode->token, "NESTED")){
        return;
    }
    if(!strcmp(tNode->token,"while")){
     if(!strcmp(tNode->left->token,"(COND")){
        if(strcmp(checkEvaluation(tNode->left->left),"boolean"))
            printf("Type mismatch: while condition dosn't match type boolean\n");
    }
        return;
    }
    if(!strcmp(tNode->token,"IF")){
     if(!strcmp(tNode->left->token,"(COND")){
        if(strcmp(checkEvaluation(tNode->left->left),"boolean"))
            printf("Type mismatch: IF condition dosn't match type boolean\n");
    }
        return;
    }

    if(!strcmp(tNode->token,"do-while")){ 
        return;
    }
    if(!strcmp(tNode->token,"for")){
        return;
    }
    if(!strcmp(tNode->token,"procedure")){
        pushProcSymbols(tNode);
        return;
    }
   
    
                                            
    
    if(!strcmp(tNode->token,"DECLARE")){
        pushSymbols(tNode->left->token,tNode->right);
        //YYERROR;
        return;
    }
    
     if (!strcmp(tNode->token, "func call")){
        compareCallDeclare( tNode->left->token, tNode->right);      
    }
    
    if (!strcmp(tNode->token, "ARRAY")){
        //if (bracketExpression !=NULL)
           checkBracketsExpression(tNode);
        //if (isDeclared(tNode->right))
        
         
    }
    
     if (!strcmp(tNode->token, "STATEMENT")){
        int check;
        if (!strcmp(tNode->left->token, "IF")){
            check = isDeclared(tNode->left->left->left);
            if (check){
                //checkEvaluation(tNode);
                checkEvaluation(tNode->left->left->left);
            }
        }
        else if (!strcmp(tNode->left->token, "=")){
            check = isDeclared(tNode->left);
            if (check){
                char *left = scopeLookup(tNode->left->left->token)->type;
                char *right = checkEvaluation(tNode->left->right);
                if (strcmp(right,left))
                    printf("Assignment Error mismatch: cannot assign %s to %s (identifier %s)\n", right, left, tNode->left->left->token);
                
            }
        }
        else if ((!strcmp(tNode->left->token, "for"))){
            check = isDeclared(tNode->left->left);
            if (check){
                checkEvaluation(tNode->left->left->left);
                checkEvaluation(tNode->left->left->middle);
                checkEvaluation(tNode->left->left->right);
            }
        }
        else if(!strcmp(tNode->left->token, "while")){
            check = isDeclared(tNode->left->left->left);
            if (check){
                checkEvaluation(tNode->left->left->left);
            }
        }
    }
    
    pushScopeStatements(tNode->left);
    pushScopeStatements(tNode->middle);
    pushScopeStatements(tNode->right);
    
}
    
/*  PUSH SYMBOLS
    following a DECLARE node (<type> <id1>, <id2>...) push all symbols under same type
    base cases are  1) seeing an id with a value, 2) without value
*/
void pushSymbols( char* type,treeNode* tNode)
{
    /*symbolNode* head = (*head_ref)->symbolTable;*/
        // pass 0 to PushSymbols to signify not a proc
        /*node is aasignment*/
        if(!strcmp(tNode->token,"=")){

        pushSymbolsToTable( &topStack,tNode->left->token,type,tNode->right->token, 0, NULL);
            return;
        }
    /* node is an ID */
        if (strcmp(tNode->token,"=") && strcmp(tNode->token,"")){
            pushSymbolsToTable(&topStack,tNode->token,type,NULL, 0, NULL);
            return;
            }
        pushSymbols( type,tNode->left);
        pushSymbols( type, tNode->right);
        
}

/* PUSH PROCEDURE SYMBOLS 
    wrapper function to add procedures to symbol table */
/* pass on to "push" with value "1" to identify it as a fucntion   */
void pushProcSymbols(treeNode* tNode)
{
   /* symbolNode* head = (*head_ref)->symbolTable;*/
    //params is tNode->middle;
    int isProc = 1;
                                        //scope,    , id,                                       , type,                                 data,                       params
    pushSymbolsToTable(&topStack, tNode->left->right->token, tNode->left->left->token, "function",isProc, tNode->middle);
}

/* 
PUSH SYMBOLS TO SYMBOL LIST (TABLE)
Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. 
*/
void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params)
{
        //malloc a new block
	struct symbolNode* new_node = (struct symbolNode*) malloc(sizeof(struct symbolNode));
	
	new_node->isProc = isProc;
	
	//malloc string in block
	new_node->id = (char*)(malloc (sizeof(id) + 1));
	strncpy(new_node->id, id, sizeof(id)+1);
	
	//malloc data in block
	if (new_data != NULL)
	{
            new_node->data = (char*)(malloc (sizeof(new_data) + 1));
            strncpy(new_node->data, new_data, sizeof(new_data)+1);
	}
	new_node->type = (char*)(malloc (sizeof(type) + 1));
	strncpy(new_node->type, type, sizeof(type)+1);
	
	//scopeNum or scopeLevel?
	new_node->scopeID=(*node)->scopeNum;
	
	//new_node->params = params;
	// cause seg fault, params is empty even in functions(?)
        if (params != NULL)
        {
            new_node->params = (treeNode*) (malloc(sizeof(treeNode)) );
            memcpy(new_node->params, params, sizeof(treeNode) );
        }
        else
            new_node->params = NULL;
            
        //make new block the new head, and previous head now points to it
	new_node->next =(*node)->symbolTable;
	(*node)->symbolTable = new_node;
}
/*  PUSH SCOPE TO STACK
    given a scope name and paramters, append it to the scopes stack
    each scope has a scope level, which matches its "father" scope

*/
void pushScopeToStack(struct scopeNode** head_ref, char* scopeName,treeNode* params, treeNode* statements ,int scopeLevel)
{     /*declare shouldn't get here*/  
      if(strcmp(scopeName,"DECLARE")){
        
            // malloc new block
            struct scopeNode* new_scope = (struct scopeNode*) malloc(sizeof(struct scopeNode));
        
            //malloc new id
            new_scope->scopeName = (char*)(malloc (sizeof(scopeName) + 1));
            strncpy(new_scope->scopeName, scopeName, sizeof(scopeName)+1);
	
            // update total number of scope
            SCOPE_NUM++;
            // bind scope number and level
            new_scope->scopeNum=SCOPE_NUM;
            new_scope->scopeLevel=scopeLevel-1;
        
            // if functions had any parameters, push them to its symbol table
            if (params){
                pushSignatureParamsToTable(&new_scope, params);
            }
            
            // make new block the new head, and previous head now points to it
            new_scope->next = (*head_ref);
            (*head_ref) = new_scope;
            }
	
	pushScopeStatements(statements);
}

/* PUSH SIGNATURE PARAMS TO TABLE
    push paramters of procedure to its symbol table
    works recursively, base case is found "" and its children are name and type
*/
void pushSignatureParamsToTable(scopeNode **currentScope, treeNode *params){
        // reached non existing leaf
        if (!params){
            return;
        }
//void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params)
    /* node is an ID */
        if (!strcmp(params->token,"")){
            pushSymbolsToTable(currentScope,params->right->token,params->left->token,NULL, 0, NULL);
            return;
            }
        pushSignatureParamsToTable(currentScope, params->left);
        pushSignatureParamsToTable(currentScope, params->right);
}

/*  DELETE SYMBOL NODE
Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position 
*/
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

/*  IS NUMERIC
    return 1 if token is a number, 0 otherwise (any of its digits is not in [0-9])
*/
int isNumeric(char* token){
    int len = strlen(token), i;
    //check if every char in the string is a digit
    for (i = 0; i<len; i++){
        if ( !isdigit(token[i]))
            return 0;
    }
    return 1;
}

/*  IS CONST
    check if a given token is in [ booleans | csnull |  numbers | strings | chars ]
*/
int isConst(treeNode* tNode){
    /*check if id */
    if (tNode->left == NULL)
        return 0;
    else if (!strcmp(tNode->left->token, "boolean"))
        return 1;
    else if (!strcmp(tNode->token, "null"))
        return 1;
    else if (!strcmp(tNode->left->token, "integer"))
        return 1;
    else if (!strcmp(tNode->left->token, "charp"))
        return 1;
    else if (tNode->left != NULL && tNode->right && NULL && !strcmp(tNode->left->token, "char"))
        return 1;
    else if (!strcmp(tNode->token, "ABS"))
        return 1;
    //possibly unnecessary due to left token holding type data
    else if (isNumeric(tNode->token))
        return 1;
    return 0;
              
}

/* IS PARAMS MATCH
    compare callParams and declaredParams trees 
    callParams: node has token value and no childs ["X"]
    declaredParams: node has empty parent [""] and two children ["int"] ["X"]
*/
int isParamsMatch(treeNode* callParams, treeNode* declaredParams/*, struct symbolNode* currentSymTab*/)
{

    // fail if empty node
    if (callParams == NULL || declaredParams == NULL)
        return 0;
    
    //token begins as "args", skip it
    if (!strcmp(callParams->token, "args:"))
        callParams = callParams->left;
    //token begins as "params", skip it
    if (!strcmp(declaredParams->token, "params:"))
        declaredParams = declaredParams->left;
    
    // base case: callParams and declaredParams both point to a single node, 'not equal to a COMMA node'
    if (strcmp(callParams->token, ",") && strcmp(declaredParams->token, ","))
    {
        
        //symbolNode *parameter = symbolLookup(&currentSymTab, callParams->token);
        symbolNode *parameter = scopeLookup(callParams->token);
        // if current called Paramter is not null. then it is a  variable, look it up on symbol table(s)
        if (parameter !=NULL)
            {
                if (!strcmp(parameter->type, declaredParams->left->token))
                    return 1;
                else
                    return 0;
            }
        // if current paramter is null, it was either undeclared or a  const (otherwise will be declared unkown before entering function
        else if (parameter == NULL){
            // current callParam was undeclared, return 0
            if (callParams->left == NULL && callParams->right == NULL)
                return 0;
            // then it is a const
            if (!strcmp ( callParams->left->token, declaredParams->left->token ) )
                return 1;
            else
                return 0;
        }
            
    }
    // base case: callParams and declaredParams are unbalanced (unmatched)
    else if (   (!strcmp(callParams->token, ",") && strcmp(declaredParams->token, ",") ) 
                    ||
                    ((strcmp(callParams->token, ",") && !strcmp(declaredParams->token, ",")) ) )
        return 0;
    else
        return isParamsMatch(callParams->left, declaredParams->left/*, currentSymTab*/) && isParamsMatch(callParams->right, declaredParams->right/*, currentSymTab*/);
}

/* IS RETURN TYPE MATCH
    function is called only AFTER function is added to scope\symbol symbolTable
    evaluate the type of returned expression and compare it to declare procedure type
*/
int isReturnTypeMatch(treeNode *tNode){
    char *procType = tNode->left->left->token;
    char *returnedType;
    
    // if proctype is void and not exists return -> pass
    if (!strcmp(procType,"void") && tNode->right->middle == NULL)
        return 1;
    //if proctype is void and exists return and has no left child -> pass
    else if (!strcmp(procType,"void") && tNode->right->middle->left == NULL)
        return 1;
    //if proctype is void and exists return and return has left child -> fail
    else if (!strcmp(procType,"void") && tNode->right->middle->left != NULL){
        printf ("A void function (%s) cannot return a value\n", tNode->left->right->token);
        return 0;
    }
    returnedType = checkEvaluation(tNode->right->middle->left);
    if (!strcmp(returnedType,"expressionError")){
        printf("One or more variables in function return expression were used before defined (%s)\n", tNode->left->right->token);
        return 0;
    }
    // if proctype is NOT void and exists return and proctype == return type -> pass
     if (strcmp(procType,"void") &&  !strcmp(procType, returnedType))
        return 1;
    // if proctype is NOT void and exists return and proctype != return type -> fail
    else if (strcmp(procType,"void") && strcmp(returnedType,"null") &&  strcmp(procType, returnedType)){
        printf ("Function %s return value (%s) does not match returned expression\'s value (%s)\n", tNode->left->right->token,procType, returnedType);
        return 0;
    }
    // if proctype is NOT void and exists return and return has no left child-> fail
    else if (strcmp(procType,"void") && tNode->right->middle->left == NULL ){
        printf ("Function return value (%s) must return matching value\n", procType);
        return 0;
    }
    
}

/* IS SIMILAR SYMBOLS
    return 0 if given symbol already exists twice in given scope
*/
int isSimilarSymbols(char* scopeName, struct symbolNode* root)
{
    
    symbolNode* s1=root;
    symbolNode* s2;
    
    // for symbol s1 against any other symbol s2
  while(s1!= NULL){
        s2 = s1;
        while (s2 != NULL)
        {
           //check for same name, excluding self
            if (!strcmp(s1->id, s2->id) && s1!=s2 ){
                if (s1->isProc)
                    printf ("scope [%s]: re-declaration of procedure (%s)\n", scopeName, s1->id);
                else
                    printf ("scope [%s]: re-declaration of variable (%s)\n", scopeName, s1->id);
                return 0;
                }
                
            s2 =s2->next;
        }
        s1 =s1->next;
    }
    return 1;
}

/*  SCOPE LOOKUP
 function returns the symbol  if  already declared, otherwise NULL 
 inputs: head_ref, the scope from which to start looking, and token = id of symbol 
*/
symbolNode* scopeLookup (char* token){
    // var currentScope iterates all scopes
    // var currentLevel only iterates scopes that are bound to father scope
   
   char sign = (token)[0];
    char* id;
    if (sign == '&' || sign == '^'){
        if (sizeof token == 2){
            id[0] = (token)[1];
            }
        else{
            id = (char*)(malloc (sizeof(token) + 1));
            int i = 1;
            for (i; i < sizeof((token)-1); i++){
                id[i-1] = token[i];
                }
            }
            token = id;
        }
    

    struct scopeNode* currentScope = topStack;
    struct symbolNode* result;
    int currentLevel;
    while (currentScope != NULL)
    {  
       currentLevel=currentScope->scopeLevel;
        result=symbolLookup(&currentScope->symbolTable,token);
        // found some symbol
        // result may be null - because does not exist in current scope
        // however it may still exist in other scopes, so we do not fail lookup yet
        if(result!=NULL)
            return result;
        // if reached top level, variable was not found
          if(currentLevel==1)
            return NULL;
          
        while (currentScope->scopeLevel > 1 &&  currentScope->scopeLevel >= currentLevel)
            currentScope = currentScope->next;
    }
    return NULL;
}

/*  SYMBOL LOOKUP
     function returns the node of the symbol  if symbol declared, otherwise NULL 
     only check within one scope (not specified as argument, but head_ref is head of symtab in it)
*/
symbolNode* symbolLookup (struct symbolNode** head_ref, char* token){
    
    struct symbolNode* temp = *head_ref;
    
    while (temp != NULL)
    {
        if (!strcmp(temp->id, token)){
            return temp;
            }
        temp = temp->next;
    }
    return NULL;
}

void printInfo(treeNode *root){
    printf ("Syntax Tree:\n"); 
    /*
    printf("print symbol table:\n");
    printSymbolTable(topStack);
    printf("\n"); */
    /*
    printf("print scopes:\n");
    printScopes(topStack);
    printf("\n"); */

    printtree (root,0);
}

// This function prints contents of linked list starting from
// the given node
void printSymbolTable(struct scopeNode *node)
{  
   struct scopeNode *currentScope = node;
   struct symbolNode *currentSymbol;
   while(currentScope != NULL)
           {
               currentSymbol = currentScope->symbolTable;
        while (currentSymbol != NULL)
                {
                    printf("id:{%s}, type:{%s}, value{%s},scope{%d}", currentSymbol->id, currentSymbol->type, currentSymbol->data,currentSymbol->scopeID);
                    printf("\n");
                    currentSymbol = currentSymbol->next;
                }
         currentScope=currentScope->next;       
            }
}

void printScopes(struct scopeNode *node){

    struct scopeNode *current=node;
    while (current != NULL)	{
		printf("scope id:{%s} scopeNum:{%d} scopeLevel:{%d}\n", current->scopeName,current->scopeNum,current->scopeLevel);
		current = current->next;
	}
    printf("num of scopes:{%d}\n",SCOPE_NUM);
	
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
#line 1652 "bin/y.tab.c"

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
#line 83 "src/part3.y"
	{   startSematics(yystack.l_mark[0]);  }
break;
case 2:
#line 84 "src/part3.y"
	{yyval = mktreeNode ("global", yystack.l_mark[-1],NULL,yystack.l_mark[0]); }
break;
case 3:
#line 85 "src/part3.y"
	{yyval = mktreeNode ("global", yystack.l_mark[0],NULL,NULL); }
break;
case 4:
#line 89 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-1],NULL, yystack.l_mark[0]); }
break;
case 5:
#line 90 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[0], NULL,NULL);}
break;
case 8:
#line 93 "src/part3.y"
	{ yyval = mktreeNode ("main", yystack.l_mark[0],NULL, NULL); }
break;
case 9:
#line 94 "src/part3.y"
	{yyval = mktreeNode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]);}
break;
case 10:
#line 95 "src/part3.y"
	{yyval = mktreeNode ("procedure", yystack.l_mark[-4], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 11:
#line 96 "src/part3.y"
	{yyval = mktreeNode ("procID", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 12:
#line 97 "src/part3.y"
	{yyval = mktreeNode ("procID", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 14:
#line 103 "src/part3.y"
	{yyval = mktreeNode ("params:", yystack.l_mark[0], NULL, NULL); }
break;
case 15:
#line 104 "src/part3.y"
	{yyval = mktreeNode (",", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 17:
#line 108 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 114 "src/part3.y"
	{yyval = mktreeNode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 115 "src/part3.y"
	{yyval = mktreeNode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 116 "src/part3.y"
	{yyval = mktreeNode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 117 "src/part3.y"
	{yyval = mktreeNode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 118 "src/part3.y"
	{yyval = mktreeNode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 23:
#line 119 "src/part3.y"
	{yyval = mktreeNode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 24:
#line 120 "src/part3.y"
	{yyval = mktreeNode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 25:
#line 121 "src/part3.y"
	{yyval = mktreeNode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 26:
#line 122 "src/part3.y"
	{yyval = mktreeNode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 27:
#line 123 "src/part3.y"
	{yyval = mktreeNode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 28:
#line 124 "src/part3.y"
	{yyval = mktreeNode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 29:
#line 125 "src/part3.y"
	{yyval = mktreeNode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 30:
#line 126 "src/part3.y"
	{yyval = mktreeNode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 31:
#line 127 "src/part3.y"
	{yyval = mktreeNode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 32:
#line 128 "src/part3.y"
	{yyval = mktreeNode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 33:
#line 129 "src/part3.y"
	{yyval = mktreeNode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 38:
#line 136 "src/part3.y"
	{ yyval = mktreeNode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 39:
#line 137 "src/part3.y"
	{ yyval = mktreeNode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 40:
#line 138 "src/part3.y"
	{ yyval = mktreeNode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 41:
#line 139 "src/part3.y"
	{ yyval = mktreeNode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 42:
#line 140 "src/part3.y"
	{ yyval = mktreeNode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 43:
#line 141 "src/part3.y"
	{ yyval = mktreeNode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 44:
#line 152 "src/part3.y"
	{yyval = mktreeNode ("&&", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 45:
#line 153 "src/part3.y"
	{yyval = mktreeNode ("||", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 46:
#line 154 "src/part3.y"
	{yyval = mktreeNode ("NOT", yystack.l_mark[0], NULL, NULL); }
break;
case 49:
#line 160 "src/part3.y"
	{yyval = mktreeNode ("(", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 50:
#line 162 "src/part3.y"
	{yyval = mktreeNode (")", NULL, NULL, NULL); }
break;
case 51:
#line 163 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-3], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 52:
#line 164 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", NULL, yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 54:
#line 166 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-3], yystack.l_mark[-2], yystack.l_mark[0]); }
break;
case 55:
#line 167 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 56:
#line 170 "src/part3.y"
	{yyval = mktreeNode ("RETURN", yystack.l_mark[0], NULL, NULL);}
break;
case 57:
#line 171 "src/part3.y"
	{yyval = mktreeNode ("RETURN", NULL, NULL, NULL);}
break;
case 58:
#line 173 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[0], NULL, NULL);}
break;
case 59:
#line 174 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", NULL, NULL, yystack.l_mark[0]); }
break;
case 60:
#line 175 "src/part3.y"
	{yyval = mktreeNode (")", NULL, NULL,NULL ); }
break;
case 70:
#line 191 "src/part3.y"
	{yyval = mktreeNode ("ABS",mktreeNode("integer", NULL,NULL,NULL),yystack.l_mark[-1],mktreeNode("pos",NULL,NULL,NULL));}
break;
case 71:
#line 193 "src/part3.y"
	{yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 72:
#line 195 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("neg",NULL,NULL,NULL)); }
break;
case 73:
#line 196 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("pos",NULL,NULL,NULL)); }
break;
case 74:
#line 197 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("hex",NULL,NULL,NULL)); }
break;
case 75:
#line 198 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("oct",NULL,NULL,NULL)); }
break;
case 76:
#line 199 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("bin",NULL,NULL,NULL)); }
break;
case 77:
#line 201 "src/part3.y"
	{ yyval = mktreeNode (yytext, NULL, NULL, NULL); }
break;
case 78:
#line 203 "src/part3.y"
	{ yyval = mktreeNode (yytext, mktreeNode("boolean", NULL,NULL,NULL), NULL, NULL); }
break;
case 79:
#line 204 "src/part3.y"
	{ yyval = mktreeNode (yytext, mktreeNode("boolean", NULL,NULL,NULL), NULL, NULL); }
break;
case 80:
#line 206 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("charp", NULL,NULL,NULL), NULL, NULL); }
break;
case 81:
#line 208 "src/part3.y"
	{yyval = mktreeNode (yytext, mktreeNode("char", NULL,NULL,NULL), NULL, NULL); }
break;
case 82:
#line 212 "src/part3.y"
	{yyval = mktreeNode ("func call", yystack.l_mark[-3], NULL, yystack.l_mark[-1]); }
break;
case 83:
#line 214 "src/part3.y"
	{yyval = mktreeNode ("args:", yystack.l_mark[0], NULL, NULL); }
break;
case 84:
#line 215 "src/part3.y"
	{yyval = mktreeNode (",", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 86:
#line 218 "src/part3.y"
	{yyval = mktreeNode ("ARRAY", mktreeNode("char", NULL,NULL,NULL), yystack.l_mark[-3], yystack.l_mark[-1]);}
break;
case 87:
#line 219 "src/part3.y"
	{yyval = mktreeNode ("ARRAY", mktreeNode("char", NULL,NULL,NULL), yystack.l_mark[-3], yystack.l_mark[-1]);}
break;
case 88:
#line 220 "src/part3.y"
	{char* t = yystack.l_mark[0]->token; char *s = malloc(strlen(t)+strlen("&")+1); strcat (s,"&"); strcat(s,t); 
                            yyval = mktreeNode (s,NULL, NULL, NULL); }
break;
case 89:
#line 224 "src/part3.y"
	{char* t = yystack.l_mark[0]->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); yyval = mktreeNode (s,NULL, NULL, NULL); }
break;
case 90:
#line 230 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 95:
#line 241 "src/part3.y"
	{yyval = mktreeNode ("STATEMENT", yystack.l_mark[-1], NULL,yystack.l_mark[0]); }
break;
case 96:
#line 242 "src/part3.y"
	{yyval = mktreeNode ("STATEMENT", yystack.l_mark[0], NULL,NULL); }
break;
case 97:
#line 243 "src/part3.y"
	{yyval = mktreeNode ("NESTED", yystack.l_mark[-1], NULL,yystack.l_mark[0]);}
break;
case 98:
#line 244 "src/part3.y"
	{yyval = mktreeNode ("NESTED", yystack.l_mark[0], NULL,NULL);}
break;
case 107:
#line 258 "src/part3.y"
	{yyval = mktreeNode ("(BLOCK", yystack.l_mark[-1], NULL, yystack.l_mark[0]);}
break;
case 108:
#line 262 "src/part3.y"
	{yyval = mktreeNode ("IF", yystack.l_mark[-1],yystack.l_mark[0],NULL); }
break;
case 109:
#line 263 "src/part3.y"
	{yyval = mktreeNode ("IF", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]);}
break;
case 110:
#line 265 "src/part3.y"
	{yyval = mktreeNode ("ELSE", yystack.l_mark[0],NULL, NULL); }
break;
case 114:
#line 271 "src/part3.y"
	{yyval=mktreeNode("while", yystack.l_mark[-1],NULL, yystack.l_mark[0]);}
break;
case 115:
#line 272 "src/part3.y"
	{yyval=mktreeNode("do-while", yystack.l_mark[-2],NULL, yystack.l_mark[0]);}
break;
case 116:
#line 274 "src/part3.y"
	{yyval=mktreeNode("for", yystack.l_mark[-2],yystack.l_mark[-1], yystack.l_mark[0]);}
break;
case 117:
#line 276 "src/part3.y"
	{yyval=mktreeNode("for conditions:", yystack.l_mark[-4],yystack.l_mark[-2], yystack.l_mark[0]);}
break;
case 124:
#line 283 "src/part3.y"
	{yyval = mktreeNode ("(COND", yystack.l_mark[-1], NULL, yystack.l_mark[0]); }
break;
case 125:
#line 287 "src/part3.y"
	{yyval = mktreeNode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 126:
#line 289 "src/part3.y"
	{yyval = mktreeNode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 127:
#line 290 "src/part3.y"
	{yyval = mktreeNode ("=", yystack.l_mark[-5], NULL, yystack.l_mark[0]); }
break;
case 128:
#line 293 "src/part3.y"
	{yyval = mktreeNode ("boolean", NULL, NULL, NULL); }
break;
case 129:
#line 294 "src/part3.y"
	{yyval = mktreeNode ("char", NULL, NULL, NULL); }
break;
case 130:
#line 295 "src/part3.y"
	{yyval = mktreeNode ("integer", NULL, NULL, NULL); }
break;
case 131:
#line 296 "src/part3.y"
	{yyval = mktreeNode ("string", NULL, NULL, NULL); }
break;
case 132:
#line 297 "src/part3.y"
	{yyval = mktreeNode ("intp", NULL, NULL, NULL); }
break;
case 133:
#line 298 "src/part3.y"
	{yyval = mktreeNode ("charp", NULL, NULL, NULL); }
break;
case 134:
#line 299 "src/part3.y"
	{yyval = mktreeNode ("void", NULL, NULL, NULL); }
break;
case 135:
#line 304 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-5], NULL, yystack.l_mark[0]); }
break;
case 136:
#line 305 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2],NULL, yystack.l_mark[0]); }
break;
case 137:
#line 306 "src/part3.y"
	{/*$$ = mktreeNode ("STRING", $1,NULL, NULL);*/ }
break;
case 138:
#line 307 "src/part3.y"
	{/*$$ = mktreeNode ("STRING", $1, NULL,NULL); */}
break;
case 139:
#line 310 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 140:
#line 311 "src/part3.y"
	{yyval = mktreeNode ("", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 143:
#line 316 "src/part3.y"
	{/*pushSymbols( $1->token,$2);*/ yyval = mktreeNode ("DECLARE", yystack.l_mark[-1], NULL, yystack.l_mark[0]);}
break;
case 144:
#line 317 "src/part3.y"
	{/*pushSymbols("String",$2);*/ yyval = mktreeNode ("DECLARE", mktreeNode ("STRING", NULL, NULL,NULL), NULL,yystack.l_mark[0]); }
break;
#line 2255 "bin/y.tab.c"
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
