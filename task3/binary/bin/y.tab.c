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

#line 2 "src/part3bin.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int tabCounter=0;
int isMain=0;
int scopeCounter = 0;
int ReturnFlag = 0;
int varCounter = 0;
int byteCounter = 0;
int labelCounter=0;
char codebuffer[10000]="";
typedef struct node
{
    char * type;
    char * token;
    struct node * left;
    struct node * right;
    char * next;
    char * code;
    char * var;
    char * trueLabel;
    char * falseLabel;
    char* constType;	
}node;

typedef struct symbolTable
{
char * name;
char * type;
char * scope;
int scopeNumber;
struct symbolTable * prevST;
}symbolTable;
typedef struct labelStruct
{
char oldLabelNumber[50];
char newLabelNumber[50];
struct labelStruct * next;
}labelStruct;

typedef enum type
{
    BOOLEAN_t, CHAR_t, INT_t, STRING_t, STRINGARRAY_t, INTPTR_t, CHARPTR_t, RETURN_t, Null_t, ELSE_t
}type;

node * mknode(char * token,char *type, node * left, node * right);
void printtree(node * tree);
char * binToDec(char * bin);
char * octalToDec(char * oct);
char * HexaToDec(char * hex);
void buildST(node * tree);
int CheckID(node * tempTree);
char * buildVarOfProcedure(node * tree, char * procedureName);
void printST();
int checkExist(char * name);	/*check if name can be defined as var~*/
int checkNameExists(char * name);	/*check if name is in symboltable so we can reach him~*/
void buildVar(node * tree);
type typeOf(char* str);
char* assignment(char* st1, char* st2);
char* arithmetics(char* op, char* st1, char* st2);
char* andOr(char* st1, char* st2);
char* smallerBigger(char* st1, char* st2);
char* equalNotEqual(char* st1, char* st2);
char* absolute(char* str);
char* not(char* str);
char* checkAddressOf(char* str);
char* checkPointAt(char* str);
char* equalReturnTypes(char* st1, char* st2);
char* checkBinaryOperations(char* op, char* st1, char* st2);
char* checkUnaryOperations(char* op, char* str);
void UpdateIDType(node * tempTree);
char * ReturnIDType(char * name);
int checkIfProcedure(char * name);
char* freshVar(char *type); /*last*/
int get_int_len();/*last*/
void CallProcedureParasTreat(char * proName,node * paras);/*orel*/
void checkFuncParam(char * proName,node * paras,node * nameAndParas);/*orel*/
symbolTable* reverseST(symbolTable * st);/*orel*/
symbolTable* dupST(char * proName,symbolTable * st);/*orel*/
void UpdateParameterType(node * tempTree);/*orel &&michael*/
void addProcedureParametersToST(char * proName,node * paras);
static symbolTable * current;
static symbolTable * procedureParas; 
static labelStruct * labelHead;
static char * currentReturnType;
char * freshLabel();
void ConditionTreatment(node * condition);
void SwapSides(node * condition);
void MakeIfIntoIfZ(node * condition,char * nextLabel, char * elseLabel);
void InsertLabelsIntoCondition(node * condition,char * thenLabel,char * nextLabel, char * elseLabel);
int ThereisAND(node * condition);
void _3ACForAssignment(node * tree);
void _3ACMain(node * tree);
void TAC_PrintCode(node * tree);
void TAC_FillCode(node * tree); 
char * _3ACForOperations(node * tree);
int _3ACForProcedureParameters(node * tree);
char* _3ACForProcedureActivate(node * tree);
void _3ACForProcedureDefine(node * tree);
void _3ACForReturn(node * tree);
int numberOfBytes (char *type); 
void _3ACForVar(node * tree); 
int countNumberOfParameters(node *tree); 
void deleteNameOfParameters(int numberOfParametersToDelete); 
char* _3ACString(node* tree);
void recursivePrint(node* tree);
void checkIfConditionTypeIsBoolean(node *cond); 
void printFixedCode();
void buildLabelStruct();
/*void checkIDForCond(node * forCond);*/
/*#define YYDEBUG 1 */
int yylex();
int yyerror();
char *yytext;
/*int yydebug=1;*/

#line 122 "src/part3bin.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union 
{
struct
    {
	char* type;
	char* string;
	node* tree;
    }IST;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 157 "bin/y.tab.c"

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

#define BOOLEAN 257
#define CONST_BOOLEAN 258
#define CHAR 259
#define INTEGER 260
#define STRING 261
#define VOID 262
#define INTPTR 263
#define CHARPTR 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define VAR 269
#define ASSIGN 270
#define EQ 271
#define GT 272
#define GE 273
#define LT 274
#define LE 275
#define NE 276
#define NOT 277
#define MINUS 278
#define PLUS 279
#define MUL 280
#define DIVISION 281
#define ADDRESS 282
#define VAL_POINTER 283
#define AMPERSAND 284
#define VALUE_ADDRESS 285
#define ARRAY 286
#define PROCEDURE 287
#define RETURN 288
#define NIL 289
#define AND 290
#define OR 291
#define VBAR 292
#define CHAR_CONST 293
#define BINARY 294
#define OCTAL 295
#define INTEGER_CONST 296
#define STRING_CONST 297
#define SEMICOLON 298
#define COLON 299
#define SEPERATOR 300
#define START_BLOCK_OF_CODE 301
#define END_BLOCK_OF_CODE 302
#define BEGIN_PARAMETER_LIST 303
#define END_PARAMETER_LIST 304
#define BEGIN_STRING_INDEX 305
#define END_STRING_INDEX 306
#define IDENTIFIER 307
#define HEXADECIMAL 308
#define ERR 309
#define EQUAL 310
#define StringParameter 311
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    4,    8,    6,    9,
    9,    9,    9,    9,    9,    9,    9,    7,    5,   19,
   19,   19,   19,   21,   21,   17,   17,   17,   17,   17,
   17,   20,   22,   22,   23,   24,   24,   24,   24,   25,
   25,   25,   26,   26,   26,   27,   27,   27,   27,   27,
   30,   31,   13,   13,   13,   13,   13,   13,   13,   13,
   13,   13,   13,   35,   35,   12,   37,   37,   37,   37,
   38,   38,   38,   38,   38,   38,   32,   32,   18,   28,
   29,   33,   33,   39,   39,   39,   39,   39,   39,   39,
   36,   36,   40,   40,   41,   41,   41,   42,   42,   42,
   42,   42,   42,   42,   42,   42,   42,   42,   42,   42,
   42,   42,   42,   42,   42,   42,   42,   42,   10,   10,
   10,   10,   10,   10,   10,   11,   11,   14,   14,   15,
   15,   15,   15,   16,   43,   44,   45,   46,   47,   34,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    1,    2,    2,    4,    4,    2,
    3,    2,    2,    2,    2,    4,    0,    5,    5,    2,
    4,    0,    2,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    4,    1,    1,    1,    1,    1,
    3,    3,    1,    3,    3,    3,    1,    1,    1,    1,
    2,    2,    3,    3,    6,    3,    4,    4,    3,    3,
    3,    3,    3,    1,    1,    3,    3,    1,    3,    1,
    3,    3,    3,    1,    1,    1,    1,    0,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    1,    3,    1,    3,    1,    1,    3,    3,    3,
    3,    4,    3,    3,    4,    3,    3,    5,    4,    4,
    4,    4,    3,    3,    3,    3,    2,    2,    3,    3,
    3,    3,    4,    6,    3,    2,    0,    7,    7,   11,
   11,    7,    7,    7,    2,    2,    3,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
   26,   27,   28,    0,   32,   33,   34,    0,    1,    0,
    4,    5,    0,    0,    0,    0,   30,   31,    0,    2,
    0,    6,    0,    7,   79,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   35,    0,    0,    0,
    0,   37,   38,   36,    0,   39,   47,   48,    0,    0,
   43,   49,   50,    0,   12,    0,    0,   10,    0,   13,
   14,   15,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   97,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  126,    9,   11,    0,    0,   66,
   62,    0,   83,    0,    0,    0,    0,   56,   63,    0,
    0,   61,    0,    0,    0,    0,   82,    0,    0,    0,
    0,    8,   25,    0,   23,   18,    0,   19,   84,   85,
   86,   87,   88,   89,   90,    0,  118,  117,   51,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  136,    0,    0,  138,  135,    0,   81,
   80,   46,    0,    0,   44,   45,   16,   67,   69,    0,
   58,  140,   65,   64,   57,  121,    0,  125,    0,  119,
  122,  120,   24,    0,  114,    0,    0,  107,   95,    0,
    0,  116,    0,    0,  100,  113,  104,  103,  106,    0,
    0,   99,    0,   91,   93,    0,    0,    0,    0,    0,
    0,    0,    0,   77,  123,    0,   21,  112,    0,  111,
    0,    0,  105,  110,  102,    0,    0,    0,    0,  139,
  137,    0,    0,   55,    0,    0,    0,  108,    0,  128,
  129,  134,   73,   71,   72,  124,    0,    0,    0,    0,
    0,    0,  130,  131,
};
static const YYINT yydgoto[] = {                          8,
    9,   34,   11,   12,   13,   22,   14,   24,   35,   82,
   67,   36,   37,   38,   39,   40,   41,   42,   86,   16,
   87,   17,   18,   58,   95,   60,   61,   62,   63,   96,
   43,  232,  233,  165,  195,   98,   76,  234,  166,   99,
  100,  101,  105,  106,  178,  179,  251,
};
static const YYINT yysindex[] = {                       413,
    0,    0,    0, -297,    0,    0,    0,    0,    0,  413,
    0,    0, -281, -254, -253, -253,    0,    0, -231,    0,
   47,    0,   47,    0,    0, -221, -216, -204, -198, -192,
 -174,  -63,   47,   47, -155,   47, -153,   47,   47,   47,
 -237, -230, -115, -122,  -81,  -81,    0, -145, -145, -213,
   26,    0,    0,    0,  -63,    0,    0,    0, -142, -121,
    0,    0,    0, -120,    0, -123, -106,    0,   47,    0,
    0,    0,  -93,  -85, -219,  -78,   -5,  -63,  -34,  331,
   66,  -50,  421,  -43,  -33,  -36,  -26,  -22,  415, -236,
 -253,  415, -145, -127,  390,  415,  415,  -19,  -37,    3,
    0, -112,   -8,   15,   12,   72,   25,  -57, -189,  -63,
  -63,  -63,  -63,   47,    0,    0,    0, -237, -237,    0,
    0,  415,    0, -210,  390,   65,  415,    0,    0, -218,
 -248,    0, -142,   30,  -63,   37,    0,   16, -178,   45,
   46,    0,    0,  -75,    0,    0,   52,    0,    0,    0,
    0,    0,    0,    0,    0,   95,    0,    0,    0, -213,
   40,  287,   22,   70,  415, -124, -275,  308,   71, -145,
 -145,   75,   76,    0,   77,  415,    0,    0,   48,    0,
    0,    0, -121, -121,    0,    0,    0,    0,    0,   89,
    0,    0,    0,    0,    0,    0, -160,    0,   89,    0,
    0,    0,    0,  -81,    0, -142,   40,    0,    0,   47,
  314,    0,   40, -142,    0,    0,    0,    0,    0,   40,
 -142,    0,   47,    0,    0,   47,   47,   47, -213,   88,
 -172,   90,   93,    0,    0,   91,    0,    0,   97,    0,
   40, -142,    0,    0,    0,   98,   99,  112,  121,    0,
    0,   89,   89,    0,   89,  130,  164,    0,  165,    0,
    0,    0,    0,    0,    0,    0,  135,  138,   47,   47,
  133,  149,    0,    0,
};
static const YYINT yyrindex[] = {                       437,
    0,    0,    0, -182,    0,    0,    0,    0,    0,  437,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -158,    0,  167,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  151, -158,  157, -158,    0, -158, -158, -158,
    0,    0,    0,    0,  156,  156,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  219,  134,
    0,    0,    0,    0,    0,    0,    0,    0, -158,    0,
    0,    0, -220,  169,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -110,    0,
    0,    0,    0,  379,    0,    0,    0,    0,  -31,  276,
    0,  379,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -158,    0,    0,    0,    0,    0,    0,
    0,   -3,    0,  253,   27,  117,  118,    0,    0,    0,
    0,    0,  154,    0,    0,    0,    0,   -4,    0,    0,
    0,    0,    0,    0,    0,    0,  161,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  264,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  171,  208,    0,    0,    0,    0,    0,  168,
    0,    0,    0,    0,    0,    0,    0,    0,  168,    0,
    0,    0,    0,  156,    0,  129,    0,    0,    0,  151,
    0,    0,  292,  166,    0,    0,    0,    0,    0,  292,
  342,    0,  151,    0,    0,  151,  151,  151,    0,  170,
  172,    0,  184,    0,    0,    0,    0,    0,    0,    0,
  292,  345,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -51,    0,   -2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  151,  151,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  458,   28,    0,    0,    0,    0,    0,    0,  -23,    0,
    0,    0,  -38,    0,    0,    0,   21,  -14,  -40,    0,
  329,    0,    0,    0,  -25,  132,  136,    0,    0,  -58,
  -44,  298,  -52,  -18,    0,  -35,  152,  -54,  -53,  330,
    0,  396,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 692
static const YYINT yytable[] = {                         44,
   26,   27,   74,   97,   97,   88,   59,   19,   91,   64,
   65,  104,   68,  103,   70,   71,   72,   57,  126,   21,
   15,  157,  140,   79,  128,  108,   75,   10,  141,  109,
   15,   25,  127,   94,  102,  156,   57,   10,  160,   77,
   57,  129,  167,  168,  193,  117,   23,   32,   97,   79,
   77,  125,  130,   25,  133,  139,   79,  163,   25,  110,
  111,   97,  124,   57,   28,   57,   57,  162,  160,   73,
   25,   32,  167,  168,   78,  158,  159,   68,  161,   74,
   74,   45,   79,   45,   79,   78,   46,  192,  110,  111,
  187,  161,  190,   25,   78,   57,   57,   57,   57,  110,
  111,   47,   29,  143,   48,  110,  111,  191,  218,  197,
   49,  211,   89,  216,  182,  208,  194,  110,  111,  200,
   57,  215,  156,  222,   29,   97,   97,  253,   50,   17,
  206,   90,   66,  212,  224,  110,  111,  235,   91,   32,
  214,   57,  221,   17,   69,  207,   51,   92,   52,   53,
   54,  213,  217,  220,   80,  161,  161,   93,  112,  113,
   32,   25,   56,  237,  231,   81,  243,   51,  137,   52,
   53,   54,  123,  231,  115,   57,  164,   78,   55,   96,
   96,  114,   25,   56,   57,  242,  239,   96,  238,   96,
  250,  172,   78,   96,  244,  116,  241,  263,  264,  246,
  265,  245,  247,  248,  249,  132,  118,  132,  132,  132,
  132,  132,  132,  132,  119,  132,  132,   83,   84,  120,
  110,  111,  258,   83,   84,   85,  231,  231,   51,  231,
   52,   53,   54,  132,  181,  131,  132,   57,   57,   55,
   57,  183,  184,   25,   56,  271,  272,  185,  186,  132,
  132,  142,   89,  170,  133,  132,  133,  133,  133,  133,
  133,  133,  133,  144,  133,  133,   92,  146,   92,  188,
  189,   90,   92,   79,   79,   79,   79,  145,   91,   32,
  147,  148,  133,  121,  169,  133,   51,  122,   52,   53,
   54,  123,  171,   79,   82,  173,   82,   93,  133,  133,
   82,   25,   56,    1,  133,    2,    3,    4,    5,    6,
    7,   29,  174,   30,   31,  175,  180,   51,  199,   52,
   53,   54,  107,  134,   53,  209,   53,  196,   55,  176,
   53,   32,   25,   56,  198,  149,  150,  151,  152,  153,
  154,  155,  201,  202,   78,  229,  230,   33,   90,   91,
  135,  204,  205,   25,  136,   91,   32,   51,  137,   52,
   53,   54,  123,   51,   92,   52,   53,   54,   55,   78,
  210,  223,  138,   56,   55,  226,  227,  228,   25,   56,
   51,  137,   52,   53,   54,  123,   51,  252,   52,   53,
   54,   55,  255,  254,  256,   25,   56,   55,  257,  259,
  260,   25,   56,   40,   40,   40,   40,   40,   40,   40,
   40,   40,   40,  261,   54,   59,   54,   59,  115,  115,
   54,   59,  262,   40,   40,   40,  115,  266,  115,  267,
  268,   40,  115,   40,  273,  269,    3,   40,  270,   40,
   42,   42,   42,   42,   42,   42,   42,   42,   42,   42,
  274,   60,   17,   60,   17,   98,   98,   60,  127,   22,
   42,   42,   42,   98,   20,   98,   70,   20,   42,   98,
   42,   78,  203,   76,   42,   74,   42,   41,   41,   41,
   41,   41,   41,   41,   41,   41,   41,   75,   52,   52,
   52,   52,   52,   52,   52,   52,  236,   41,   41,   41,
  225,  177,    0,    0,    0,   41,    0,   41,   52,   52,
    0,   41,    0,   41,    0,    0,   52,    0,   52,    0,
    0,    0,   52,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,    0,    0,    0,    0,    0,
   47,    0,   47,    0,    0,    0,   47,  149,  150,  151,
  152,  153,  154,  155,  110,  111,   94,   47,    0,   47,
   47,   47,   47,   94,    0,   94,    0,    0,    0,   94,
    0,   47,   47,    0,    0,    0,    0,    0,    0,   47,
  182,   47,   32,    0,    0,   47,    0,    0,   32,   51,
  219,   52,   53,   54,    0,   51,  240,   52,   53,   54,
   55,    0,    0,    0,   25,   56,   55,    0,    0,    0,
   25,   56,   51,  132,   52,   53,   54,    0,    0,    0,
    0,  101,  101,   55,  109,  109,    0,   25,   56,  101,
    0,  101,  109,    0,  109,  101,    0,    0,  109,   47,
   47,   47,   47,   47,   47,   47,   47,   47,   47,   47,
  149,  150,  151,  152,  153,  154,  155,  110,  111,    1,
    0,    2,    3,    4,    5,    6,    7,    1,    0,    2,
    3,    4,    0,    6,    7,  149,  150,  151,  152,  153,
  154,  155,
};
static const YYINT yycheck[] = {                         23,
   15,   16,   41,   48,   49,   46,   32,  305,  284,   33,
   34,   50,   36,   49,   38,   39,   40,   32,   77,  301,
    0,  258,   81,   42,   77,   51,   41,    0,   81,   55,
   10,  307,   77,   48,   49,   89,   51,   10,   92,  270,
   55,   77,   96,   97,  293,   69,  301,  285,   93,  270,
  270,   77,   78,  307,   80,   81,   75,   93,  307,  278,
  279,  106,   77,   78,  296,   80,   81,   93,  122,  307,
  307,  285,  126,  127,  305,   90,   91,  298,   93,  118,
  119,  303,  303,  303,  305,  305,  303,  306,  278,  279,
  114,  106,  303,  307,  305,  110,  111,  112,  113,  278,
  279,  306,  285,   83,  303,  278,  279,  126,  167,  135,
  303,  165,  258,  166,  304,  160,  131,  278,  279,  298,
  135,  166,  176,  168,  307,  170,  171,  300,  303,  288,
  156,  277,  288,  258,  170,  278,  279,  298,  284,  285,
  166,  156,  168,  302,  298,  160,  292,  293,  294,  295,
  296,  166,  167,  168,  270,  170,  171,  303,  280,  281,
  285,  307,  308,  204,  190,  288,  211,  292,  293,  294,
  295,  296,  297,  199,  298,  190,  304,  305,  303,  290,
  291,  302,  307,  308,  199,  211,  210,  298,  207,  300,
  229,  304,  305,  304,  213,  302,  211,  252,  253,  223,
  255,  220,  226,  227,  228,  257,  300,  259,  260,  261,
  262,  263,  264,  265,  300,  267,  268,  299,  300,  298,
  278,  279,  241,  299,  300,  307,  252,  253,  292,  255,
  294,  295,  296,  285,  292,  270,  288,  252,  253,  303,
  255,  110,  111,  307,  308,  269,  270,  112,  113,  301,
  302,  302,  258,  291,  257,  307,  259,  260,  261,  262,
  263,  264,  265,  307,  267,  268,  298,  304,  300,  118,
  119,  277,  304,  278,  279,  280,  281,  311,  284,  285,
  307,  304,  285,  289,  304,  288,  292,  293,  294,  295,
  296,  297,  290,  298,  298,  304,  300,  303,  301,  302,
  304,  307,  308,  257,  307,  259,  260,  261,  262,  263,
  264,  265,  298,  267,  268,  304,  292,  292,  303,  294,
  295,  296,  297,  258,  298,  304,  300,  298,  303,  258,
  304,  285,  307,  308,  298,  271,  272,  273,  274,  275,
  276,  277,  298,  298,  305,  298,  258,  301,  277,  284,
  285,  300,  258,  307,  289,  284,  285,  292,  293,  294,
  295,  296,  297,  292,  293,  294,  295,  296,  303,  305,
  301,  301,  307,  308,  303,  301,  301,  301,  307,  308,
  292,  293,  294,  295,  296,  297,  292,  300,  294,  295,
  296,  303,  300,  304,  304,  307,  308,  303,  302,  302,
  302,  307,  308,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  302,  298,  298,  300,  300,  290,  291,
  304,  304,  302,  290,  291,  292,  298,  298,  300,  266,
  266,  298,  304,  300,  302,  301,    0,  304,  301,  306,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  302,  298,  302,  300,  288,  290,  291,  304,  302,  304,
  290,  291,  292,  298,  304,  300,  298,   10,  298,  304,
  300,  304,  144,  304,  304,  304,  306,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  304,  270,  271,
  272,  273,  274,  275,  276,  277,  199,  290,  291,  292,
  171,  106,   -1,   -1,   -1,  298,   -1,  300,  290,  291,
   -1,  304,   -1,  306,   -1,   -1,  298,   -1,  300,   -1,
   -1,   -1,  304,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,
  298,   -1,  300,   -1,   -1,   -1,  304,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  291,  304,   -1,  278,
  279,  280,  281,  298,   -1,  300,   -1,   -1,   -1,  304,
   -1,  290,  291,   -1,   -1,   -1,   -1,   -1,   -1,  298,
  304,  300,  285,   -1,   -1,  304,   -1,   -1,  285,  292,
  293,  294,  295,  296,   -1,  292,  293,  294,  295,  296,
  303,   -1,   -1,   -1,  307,  308,  303,   -1,   -1,   -1,
  307,  308,  292,  293,  294,  295,  296,   -1,   -1,   -1,
   -1,  290,  291,  303,  290,  291,   -1,  307,  308,  298,
   -1,  300,  298,   -1,  300,  304,   -1,   -1,  304,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  257,
   -1,  259,  260,  261,  262,  263,  264,  257,   -1,  259,
  260,  261,   -1,  263,  264,  271,  272,  273,  274,  275,
  276,  277,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 311
#define YYUNDFTOKEN 361
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BOOLEAN","CONST_BOOLEAN","CHAR",
"INTEGER","STRING","VOID","INTPTR","CHARPTR","IF","ELSE","WHILE","FOR","VAR",
"ASSIGN","EQ","GT","GE","LT","LE","NE","NOT","MINUS","PLUS","MUL","DIVISION",
"ADDRESS","VAL_POINTER","AMPERSAND","VALUE_ADDRESS","ARRAY","PROCEDURE",
"RETURN","NIL","AND","OR","VBAR","CHAR_CONST","BINARY","OCTAL","INTEGER_CONST",
"STRING_CONST","SEMICOLON","COLON","SEPERATOR","START_BLOCK_OF_CODE",
"END_BLOCK_OF_CODE","BEGIN_PARAMETER_LIST","END_PARAMETER_LIST",
"BEGIN_STRING_INDEX","END_STRING_INDEX","IDENTIFIER","HEXADECIMAL","ERR",
"EQUAL","StringParameter",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : S",
"S : Start",
"Start : Procedure Start",
"Start :",
"Procedure : ProcVoid",
"Procedure : ProcValue",
"ProcVoid : VoidProcedureSignature VoidProcedureBlock",
"ProcValue : ProcedureSignature ProcedureBlock",
"ProcedureBlock : START_BLOCK_OF_CODE Block Return END_BLOCK_OF_CODE",
"VoidProcedureBlock : START_BLOCK_OF_CODE Block VoidReturn END_BLOCK_OF_CODE",
"Block : Define Block",
"Block : Assignment SEMICOLON Block",
"Block : Procedure Block",
"Block : Loop Block",
"Block : If Block",
"Block : For Block",
"Block : START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE Block",
"Block :",
"ProcedureSignature : Types ID BEGIN_PARAMETER_LIST Parameters END_PARAMETER_LIST",
"VoidProcedureSignature : TypeVoid ID BEGIN_PARAMETER_LIST Parameters END_PARAMETER_LIST",
"Parameters : SomeParameters IDENTIFIER",
"Parameters : SomeParameters IDENTIFIER SEPERATOR Parameters",
"Parameters :",
"Parameters : IDENTIFIER StringParameter",
"SomeParameters : SEPERATOR IDENTIFIER SomeParameters",
"SomeParameters : COLON Types",
"Types : BOOLEAN",
"Types : CHAR",
"Types : INTEGER",
"Types : STRING",
"Types : PtrTypes",
"Types : ArrayType",
"TypeVoid : VOID",
"PtrTypes : INTPTR",
"PtrTypes : CHARPTR",
"ArrayType : STRING BEGIN_STRING_INDEX INTEGER_CONST END_STRING_INDEX",
"CONST_INT : INTEGER_CONST",
"CONST_INT : BINARY",
"CONST_INT : OCTAL",
"CONST_INT : HEXADECIMAL",
"E : T",
"E : E PLUS T",
"E : E MINUS T",
"T : F",
"T : T MUL F",
"T : T DIVISION F",
"F : BEGIN_PARAMETER_LIST E END_PARAMETER_LIST",
"F : ID",
"F : CONST_INT",
"F : Absolute",
"F : StringLenth",
"AddressID : AMPERSAND ID",
"ValueAddressID : VALUE_ADDRESS E",
"Assignment : ID ASSIGN E",
"Assignment : ID ASSIGN AddressID",
"Assignment : ID ASSIGN ID BEGIN_PARAMETER_LIST EmptyOrPara END_PARAMETER_LIST",
"Assignment : ID ASSIGN Consts",
"Assignment : ID Array ASSIGN IndexedAssign",
"Assignment : ID ASSIGN AddressID Array",
"Assignment : ID ASSIGN ValueAddressID",
"Assignment : ValueAddressID ASSIGN E",
"Assignment : ValueAddressID ASSIGN CHAR_CONST",
"Assignment : ID ASSIGN NIL",
"Assignment : ID ASSIGN LogicOp",
"IndexedAssign : ID",
"IndexedAssign : CHAR_CONST",
"Define : Types IDents SEMICOLON",
"IDents : IDENTIFIER SEPERATOR IDents",
"IDents : IDENTIFIER",
"IDents : Assignment SEPERATOR IDents",
"IDents : Assignment",
"IDentsWithEmpty : E SEPERATOR IDentsWithEmpty",
"IDentsWithEmpty : Consts SEPERATOR IDentsWithEmpty",
"IDentsWithEmpty : CONST_BOOLEAN SEPERATOR IDentsWithEmpty",
"IDentsWithEmpty : E",
"IDentsWithEmpty : Consts",
"IDentsWithEmpty : CONST_BOOLEAN",
"EmptyOrPara : IDentsWithEmpty",
"EmptyOrPara :",
"ID : IDENTIFIER",
"Absolute : VBAR E VBAR",
"StringLenth : VBAR STRING_CONST VBAR",
"Consts : CHAR_CONST",
"Consts : STRING_CONST",
"CompOp : EQ",
"CompOp : GT",
"CompOp : GE",
"CompOp : LT",
"CompOp : LE",
"CompOp : NE",
"CompOp : NOT",
"LogicOp : condWithAnd OR LogicOp",
"LogicOp : condWithAnd",
"condWithAnd : condWithBrackets AND condWithAnd",
"condWithAnd : condWithBrackets",
"condWithBrackets : BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST",
"condWithBrackets : CONST_BOOLEAN",
"condWithBrackets : Condition",
"Condition : E CompOp E",
"Condition : ValueAddressID CompOp ValueAddressID",
"Condition : E CompOp ValueAddressID",
"Condition : ValueAddressID CompOp E",
"Condition : ValueAddressID CompOp ID Array",
"Condition : AddressID CompOp AddressID",
"Condition : AddressID CompOp ID",
"Condition : ID Array CompOp ValueAddressID",
"Condition : ValueAddressID CompOp CHAR_CONST",
"Condition : CHAR_CONST CompOp ValueAddressID",
"Condition : ID Array CompOp ID Array",
"Condition : ID Array CompOp E",
"Condition : E CompOp ID Array",
"Condition : ID Array CompOp CHAR_CONST",
"Condition : CHAR_CONST CompOp ID Array",
"Condition : E CompOp Consts",
"Condition : CONST_BOOLEAN CompOp CONST_BOOLEAN",
"Condition : CONST_BOOLEAN CompOp E",
"Condition : E CompOp CONST_BOOLEAN",
"Condition : NOT ID",
"Condition : NOT CONST_BOOLEAN",
"Return : RETURN E SEMICOLON",
"Return : RETURN Consts SEMICOLON",
"Return : RETURN CONST_BOOLEAN SEMICOLON",
"Return : RETURN AddressID SEMICOLON",
"Return : RETURN VALUE_ADDRESS E SEMICOLON",
"Return : RETURN IDENTIFIER BEGIN_PARAMETER_LIST EmptyOrPara END_PARAMETER_LIST SEMICOLON",
"Return : RETURN NIL SEMICOLON",
"VoidReturn : RETURN SEMICOLON",
"VoidReturn :",
"Loop : WHILE BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"Loop : WHILE BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE ELSE START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE ELSE START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"For : FOR BEGIN_PARAMETER_LIST forCondition END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"forCondition : initCond endAndStep",
"initCond : Assignment SEMICOLON",
"endAndStep : endCond SEMICOLON Step",
"endCond : Condition",
"Step : Assignment",
"Array : BEGIN_STRING_INDEX E END_STRING_INDEX",

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
#line 436 "src/part3bin.y"

#include "lex.yy.c"
int main(){
    return yyparse();
}

node* mknode(char *token,char *type,  node *left,  node *right){
    node * newnode = (node*)malloc(sizeof(node));
    newnode->left=left;
    newnode->right=right;
    newnode->token=strdup(token);
    newnode->type=strdup(type);
    newnode->code=strdup("");
    newnode->var=strdup("");
    newnode->next=strdup(""); 
    newnode->trueLabel=strdup(""); 
    newnode->falseLabel=strdup(""); 
    newnode->constType = strdup(type);
    return newnode;
}

//print tabs function start
void addAndPrintTab(){
    int i;
    tabCounter++;
    printf("\n");
    for(i=0;i<tabCounter;i++){
        printf("  ");
    }
}
void subAndPrintTab(){
    int i;
    if(tabCounter>0)
        tabCounter--;
    printf(")\n");
    for(i=0;i<tabCounter;i++){
        printf("  ");
    }   
}
int checkGrandchildrenFromLeftSan(node * tree){
    if(tree->left)
        if(tree->left->left || tree->left->right)
            return 1;
    return 0; 
}
int checkGrandchildrenFromRightSan(node * tree){
    if(tree->right)
        if(tree->right->left || tree->right->right)
            return 1;
    return 0; 
}
int checkGrandchildren(node * tree){
    if(checkGrandchildrenFromLeftSan(tree))
        return 1;
    if(checkGrandchildrenFromRightSan(tree))
        return 1;
    return 0;   
}
int checkChildren(node * tree){
    if(tree->left||tree->right)
        return 1;
    return 0;
}
//print tabs function end

//binary to decimal
char * binToDec(char * bin){
    int i = 0, remainder;
    char * stringedInt;
    long num, decimalNumber = 0;
    bin[strlen(bin)-1] = '\0';
    num = atoi(bin);
    while (num!=0){
        remainder = num%10;
        num /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    stringedInt = (char*)malloc(sizeof(char)*(i+1));
    sprintf(stringedInt, "%ld", decimalNumber);
    return stringedInt;
}

//octal to decimal
char * octalToDec(char * oct){
    long decimalNumber = 0, num;
    int i = 0;
    char * stringedOct;
    num = atoi(oct);
    while(num != 0){
        decimalNumber += (num%10) * pow(8,i);
        ++i;
        num/=10;
    }
    stringedOct = (char*)malloc(sizeof(char)*(i+1));
    sprintf(stringedOct, "%ld", decimalNumber);
    return stringedOct;
}

//hex to decimal
char * HexaToDec(char * hex){
    long decimalNumber = 0;
    int i, len, val;
    char * stringedHex;
    hex += 2;
    len = strlen(hex)-1;
    for(i=0; hex[i]!='\0'; i++){
        switch(hex[i]){
            case '0':
                val = 0;
                break;
            case '1':
                val = 1;
                break;
            case '2':
                val = 2;
                break;
            case '3':
                val = 3;
                break;
            case '4':
                val = 4;
                break;
            case '5':
                val = 5;
                break;
            case '6':
                val = 6;
                break;
            case '7':
                val = 7;
                break;
            case '8':
                val = 8;
                break;
            case '9':
                val = 9;
                break;
            case 'a':
            case 'A':
                val = 10;
                break;
            case 'b':
            case 'B':
                val = 11;
                break;
            case 'c':
            case 'C':
                val = 12;
                break;
            case 'd':
            case 'D':
                val = 13;
                break;
            case 'e':
            case 'E':
                val = 14;
                break;
            case 'f':
            case 'F':
                val = 15;
                break;
        }
        decimalNumber += val * pow(16, len);
        len--;
    }
    stringedHex = (char*)malloc(sizeof(char)*(i+1));
    sprintf(stringedHex, "%ld", decimalNumber);
    return stringedHex;
}
void InsertLabelsIntoCondition(node * condition,char * thenLabel,char * nextLabel, char * elseLabel)
{
	if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
		return;
	else if(strcmp(condition->token,"||")==0 && strcmp(condition->left->token,"&&")==0)
	{
		char * otherNext=strdup(freshLabel());
		if(strcmp(condition->trueLabel,"")==0)
			condition->trueLabel=strdup(otherNext);
		if(strcmp(condition->left->falseLabel,"")==0)
			condition->left->falseLabel=strdup(thenLabel);
		if(elseLabel)
			InsertLabelsIntoCondition(condition->left,thenLabel,otherNext,otherNext);
		else
			InsertLabelsIntoCondition(condition->left,thenLabel,otherNext,NULL);
		if(strcmp(condition->right->token,"||")!=0 && strcmp(condition->right->token,"&&")!=0)
		{
			condition->right->next=strdup(thenLabel);
		}
		else
		{
			condition->right->left->var=strdup(otherNext);
			InsertLabelsIntoCondition(condition->right,thenLabel,nextLabel,elseLabel);
		}
	}
	else if(strcmp(condition->token,"&&")==0 && strcmp(condition->left->token,"||")==0)
	{
		char * otherThen=strdup(freshLabel());
		if(strcmp(condition->trueLabel,"")==0)
			condition->trueLabel=strdup(otherThen);
		if(elseLabel)
			InsertLabelsIntoCondition(condition->left,otherThen,nextLabel,elseLabel);
		else
			InsertLabelsIntoCondition(condition->left,otherThen,nextLabel,elseLabel);
		if(strcmp(condition->right->token,"||")!=0 && strcmp(condition->right->token,"&&")!=0)
		{
			condition->right->next=strdup(elseLabel);
		}
		else
		{
			condition->right->left->var=strdup(otherThen);
			InsertLabelsIntoCondition(condition->right,thenLabel,nextLabel,elseLabel);
		}
	}
	else 
	{
		if(strcmp(condition->left->token,"||")==0 || strcmp(condition->left->token,"&&")==0)
		{
			InsertLabelsIntoCondition(condition->left,thenLabel,nextLabel,elseLabel);
		}
		else
		{
			
			if(strcmp(condition->token,"||")==0)
				condition->left->next=strdup(thenLabel);
			else if(strcmp(condition->token,"&&")==0)
			{
				if(elseLabel)
				{
					condition->left->next=strdup(elseLabel);
				}
				else
				{
					condition->left->next=strdup(nextLabel);
				}
			}
		}
		if(strcmp(condition->right->token,"||")==0 || strcmp(condition->right->token,"&&")==0)
		{
			InsertLabelsIntoCondition(condition->right,thenLabel,nextLabel,elseLabel);
		}
		else
		{
			if(strcmp(condition->token,"||")==0)
				condition->right->next=strdup(thenLabel);
			else if(strcmp(condition->token,"&&")==0)
			{
				if(elseLabel)
				{
					condition->right->next=strdup(elseLabel);
				}
				else
				{
					condition->right->next=strdup(nextLabel);
				}
			}
			
		}
	}
}
void ConditionTreatment(node * condition)
{
	char * rightSideVar;
	char * leftSideVar;
	char bufferLeft[2048]="";
	char bufferRight[2048]="";
	if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
		return;
	if(strcmp(condition->left->token,"||")==0 || strcmp(condition->left->token,"&&")==0)
	{
		ConditionTreatment(condition->left);
	}
	else
		leftSideVar=_3ACForOperations(condition->left);
	if(strcmp(condition->right->token,"||")==0 || strcmp(condition->right->token,"&&")==0)
	{
		ConditionTreatment(condition->right);
	}
	else
		rightSideVar=_3ACForOperations(condition->right);
	if(strcmp(condition->token,"||")==0)
	{
		if(leftSideVar!=NULL)
		{
			strcat(bufferLeft,condition->left->code);
			strcat(bufferLeft," \nif ");
			strcat(bufferLeft,leftSideVar);
			strcat(bufferLeft," goto ");
			strcat(bufferLeft,condition->left->next);
			strcat(bufferLeft,"\0");
			condition->left->code=strdup(bufferLeft);
			
		}
		if(rightSideVar!=NULL)
		{
			strcat(bufferRight,condition->right->code);
			if(strcmp(condition->right->falseLabel,"")==0)
			{
				strcat(bufferRight," \nif ");
				strcat(bufferRight,rightSideVar);
				strcat(bufferRight," goto ");
				strcat(bufferRight,condition->right->next);
			}
			else
			{
				strcat(bufferRight," \nifz ");
				strcat(bufferRight,rightSideVar);
				strcat(bufferRight," goto ");
				strcat(bufferRight,condition->right->falseLabel);
			}
			strcat(bufferRight,"\0");
			condition->right->code=strdup(bufferRight);
		}
		
	}
	else if(strcmp(condition->token,"&&")==0)
	{
		if(leftSideVar!=NULL)
		{
			strcat(bufferLeft,condition->left->code);
			strcat(bufferLeft," \nifz ");
			strcat(bufferLeft,leftSideVar);
			strcat(bufferLeft," goto ");
			strcat(bufferLeft,condition->left->next);
			strcat(bufferLeft,"\0");
			condition->left->code=strdup(bufferLeft);
			
		}
		if(rightSideVar!=NULL)
		{
			strcat(bufferRight,condition->right->code);
			if(strcmp(condition->falseLabel,"")!=0 && condition->falseLabel[0]=='L')
			{
				strcat(bufferRight," \nif ");
				strcat(bufferRight,rightSideVar);
				strcat(bufferRight," goto ");
				strcat(bufferRight,condition->falseLabel);
			}
			else
			{
				strcat(bufferRight," \nifz ");
				strcat(bufferRight,rightSideVar);
				strcat(bufferRight," goto ");
				strcat(bufferRight,condition->right->next);
			}
			strcat(bufferRight,"\0");
			condition->right->code=strdup(bufferRight);
		}
		
	}
	
}
int ThereisAND(node * condition)
{
	int flag=0;
	if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
		return 0;
	if(strcmp(condition->token,"&&")==0)
		return 1;
	flag=ThereisAND(condition->left);
	if(flag==1)
		return flag;
	flag=ThereisAND(condition->right);
	return flag;
	
}
void MakeIfIntoIfZ(node * condition,char * nextLabel, char * elseLabel)
{
	if(ThereisAND(condition)==1)
	{
		int flag=0;
		node * cond=condition->left;
		if(cond->right==NULL)
			flag=1;
		while(!flag && (strcmp(cond->right->token,"||")==0 || strcmp(cond->right->token,"&&")==0))
		{
			cond=cond->right;
		}
		if(!flag && elseLabel==NULL)
			cond->right->falseLabel=strdup(nextLabel);
		else 
		{
			if(!flag)
				cond->right->falseLabel=strdup(elseLabel);
		}
		flag=0;
		if(condition->right==NULL)
			flag=1;
		while(!flag && (strcmp(condition->right->token,"||")==0 || strcmp(condition->right->token,"&&")==0))
		{
			condition=condition->right;
		}
		if(!flag && elseLabel==NULL)
			condition->right->falseLabel=strdup(nextLabel);
		else
		{ 
			if(!flag)
				condition->right->falseLabel=strdup(elseLabel);
		}
	}
}
void SwapSides(node * condition)
{
	if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
	{
		return;
	}
	SwapSides(condition->left);
	SwapSides(condition->right);
	if(strcmp(condition->token,"||")==0 || strcmp(condition->token,"&&")==0 )
	{
		if(strcmp(condition->right->token,"||")!=0 && strcmp(condition->right->token,"&&")!=0)
		{
			if(strcmp(condition->left->token,"||")==0 || strcmp(condition->left->token,"&&")==0)
			{
				node * swap=condition->right;
				condition->right=condition->left;
				condition->left=swap;
			}
		}
	}
}
//add to mknode initial code =""
void TAC_PrintCode(node * tree)
{
	
	if(strcmp(tree->token,"while")==0)//need to fix to put the label before the ifz and not before the variables.
	{
		printf("%s:\n",tree->trueLabel);
		TAC_PrintCode(tree->left);
		printf("%s:\n",tree->left->trueLabel);
		TAC_PrintCode(tree->right);
		printf("%s",tree->code);
		printf("%s:\n",tree->next);	
	}
        else if(strcmp(tree->token,"for")==0)//need to fix to put the label before the ifz and not before the variables.
	{
		printf("%s:\n",tree->trueLabel);
		TAC_PrintCode(tree->left);
		printf("%s:\n",tree->left->trueLabel);
		TAC_PrintCode(tree->right);
		printf("%s",tree->code);
		printf("%s:\n",tree->next);	
	}
	
	else if(strcmp(tree->token,"COND")==0 )
	{
		
		TAC_PrintCode(tree->left->left);
		printf("%s:\n",tree->left->trueLabel);
		TAC_PrintCode(tree->left->right);
		printf("%s",tree->left->code);
		if (tree->right)
		{
			printf("%s:\n",tree->right->falseLabel);
			TAC_PrintCode(tree->right->left);
			printf("%s:\n",tree->next);
		}
		
	}
	else if(strcmp(tree->token,"for-COND")==0 )
	{
                
	}
	
	else
	{
		if(tree->left && strcmp(tree->token,"!")==0)//only print for not
		{
			if(strcmp(tree->var,"")!=0 && tree->var[0]=='L')
			{
				printf("%s:\n",tree->var);
			}
			TAC_PrintCode(tree->left);
			
		}
		else
		{
			if (tree->left)
				TAC_PrintCode(tree->left);
			if(strcmp(tree->var,"")!=0 && tree->var[0]=='L')
			{
				printf("%s:\n",tree->var);
			}
		}
		if (tree->right)
			TAC_PrintCode(tree->right);
		if(strcmp(tree->code,"")!=0) 
		{
			printf("%s\n",tree->code);
		}
	}
}
void TAC_FillCode(node * tree)
{
	
	if(strcmp(tree->token,"while")==0)//need to fix to put the label before the ifz and not before the variables.
	{
		strcat(codebuffer,tree->trueLabel);
		strcat(codebuffer,":\n");
		TAC_FillCode(tree->left);
		strcat(codebuffer,tree->left->trueLabel);
		strcat(codebuffer,":\n");
		//only if has statements in code, otherwise block is not build (right child is null)
		if (tree->right != NULL)
                    TAC_FillCode(tree->right);
		strcat(codebuffer,tree->code);
		strcat(codebuffer,tree->next);
		strcat(codebuffer,":\n");	
	}
	
	else if(strcmp(tree->token,"for")==0)//need to fix to put the label before the ifz and not before the variables.
	{
		strcat(codebuffer,tree->left->right->left->trueLabel);
		strcat(codebuffer,":\n");
		TAC_FillCode(tree->left);
		strcat(codebuffer,tree->right->trueLabel);
		strcat(codebuffer,":\n");
		//only if has statements in code, otherwise block is not build (right child is null)
		if (tree->right != NULL)
                    TAC_FillCode(tree->right);
		strcat(codebuffer,tree->code);
		strcat(codebuffer,tree->next);
		strcat(codebuffer,":\n");	
	}
	
	else if(strcmp(tree->token,"COND")==0 )
	{
		
		TAC_FillCode(tree->left->left);
		strcat(codebuffer,tree->left->trueLabel);
		strcat(codebuffer,":\n");
		//only if has statements in code, otherwise block is not build (right child is null)
		if (tree->left->right != NULL)
                    TAC_FillCode(tree->left->right);
		strcat(codebuffer,tree->left->code);
		if (tree->right)
		{
			strcat(codebuffer,tree->right->falseLabel);
			strcat(codebuffer,":\n");
			TAC_FillCode(tree->right->left);
			strcat(codebuffer,tree->next);
			strcat(codebuffer,":\n");
		}
		
	}
	
	else
	{
		if(tree->left && strcmp(tree->token,"!")==0)//only print for not
		{
			if(strcmp(tree->var,"")!=0 && tree->var[0]=='L')
			{
				strcat(codebuffer,tree->var);
				strcat(codebuffer,":\n");
			}
			TAC_FillCode(tree->left);
			
		}
		else
		{
			if (tree->left)
				TAC_FillCode(tree->left);
			if(strcmp(tree->var,"")!=0 && tree->var[0]=='L')
			{
				strcat(codebuffer,tree->var);
				strcat(codebuffer,":\n");
			}
		}
		if (tree->right)
			TAC_FillCode(tree->right);
		if(strcmp(tree->code,"")!=0) 
		{
			strcat(codebuffer,tree->code);
			strcat(codebuffer,"\n");
		}
	}
}
void buildLabelStruct()
{
	int index=0;
	
	int rowcount=0;
	labelHead=(labelStruct*)malloc(sizeof(labelStruct));
	labelStruct* temp=labelHead;
	while(codebuffer[index]!='\0')
	{
		if(codebuffer[index]=='L')
		{
			int flagifLabel=1;
			char labelBuffer[50]="";
			int indexlabel=0;
			index++;
			while(codebuffer[index]!=':')
			{
				if(codebuffer[index]=='\n')
				{
					rowcount++;
					flagifLabel=0;
					break;
				}
				labelBuffer[indexlabel]=codebuffer[index];
				indexlabel++;
				index++;
			}
			if(flagifLabel)//to be or function name or label
			{
				index++;//to be on \n
				strcat(labelBuffer,"\0");
				index++;//to be on next row
				if(codebuffer[index]=='B')
				{
					rowcount=-1;
					flagifLabel=0;
				}
				else//we are sure that it's label
				{
					//printf("%s OOO", labelBuffer);
					temp->next=(labelStruct*)malloc(sizeof(labelStruct));
					strcpy(temp->next->oldLabelNumber,labelBuffer);
					sprintf(temp->next->newLabelNumber,"%d",rowcount);
					temp=temp->next;
				}
			}
			
		}
		else if(codebuffer[index]=='\n')
		{
			rowcount++;
		}
		else if(codebuffer[index]==':' && codebuffer[index+2]=='B')
		{
			rowcount=0;//it 0 and not -1 cuz we jumped over \n
			index++;//to be on \n
			index++;//to be on B
		}
		index++;
	}
}



void printFixedCode()
{
	
	int index=0;
	labelHead=labelHead->next;
	while(codebuffer[index]!='\0')
	{
		if(codebuffer[index]=='L')
		{
			labelStruct * temp=labelHead;
			char labelBuffer[50]="";
			int indexlabel=0;
			int isFunc=0;
			int isColon=0;
			int subindex=index+1;
			
			while(codebuffer[subindex]!='\n')
			{
				if(codebuffer[subindex]==':')
				{
					isColon=1;
					if(codebuffer[subindex+2]=='B')
						isFunc=1;
						break;
				}
				labelBuffer[indexlabel]=codebuffer[subindex];
				indexlabel++;
				subindex++;
			}
			if(!isFunc)
			{
				strcat(labelBuffer,"\0");
				while(temp!=NULL && strcmp(temp->oldLabelNumber,labelBuffer)!=0)
				{
					temp=temp->next;
				}
				if(temp!=NULL)
				{
					printf("L");					
					printf("%s",temp->newLabelNumber);
					
					if(isColon)
						printf(":");
					while(codebuffer[index]!='\n')//index is on L
						index++;
				}
			}
			
			
		}
		printf("%c",codebuffer[index]);
		index++;
	}
}
void _3ACMain(node * tree)
{
	int notToEnterLeft=0;
	int notToEnterRight=0;
	if (tree->code && strcmp(tree->code,"")!= 0)
		return;
	if (tree->left==NULL&&tree->right == NULL) // if leaves
		return;
	if (strcmp(tree->token,"procedure")==0)
	{
		int varCounterLOCAL = varCounter; // save localy the global var counter //
		int byteCounterLOCAL = byteCounter; // save localy the global byte counter //
		_3ACForProcedureDefine(tree);
		varCounter = varCounterLOCAL;
		byteCounter = byteCounterLOCAL;	            
		notToEnterLeft = 1;
		notToEnterRight = 1; 	
	}
	else if(strcmp(tree->token,"NewRow")==0)//if the left is condition or while, ill put in next of cond or while the next code after it to jump
	{
		if(strcmp(tree->left->token,"COND")==0 || strcmp(tree->left->token,"while")==0)
		{	
			if(strcmp(tree->left->next,"")==0)//first time to put label
			{	
				tree->left->next=strdup(freshLabel());//next label
			}
		}
		
	}
	else if(strcmp(tree->token,"COND")==0 && strcmp(tree->left->trueLabel,"")==0)//to avoid 2nd enter because of variables calc.
	{ 
		char * thenLabel;
		char thencode[2000]="";
		char ifcode[2000]="";
		node * condition=tree->left->left;//if(x>y) => condition= '>')
		notToEnterLeft=1;
		notToEnterRight=1;
		thenLabel=strdup(freshLabel());
                // if FOR\COND has an empty block then right child will be null
                if (tree->left->right != NULL)
                    _3ACMain(tree->left->right);//then block 
		tree->left->trueLabel=strdup(thenLabel);
		if(tree->right)
		{
			char * elseLabel;
			char elsecode[2000]="";
			char elseblockcode[2000]="";
			_3ACMain(tree->right->left);//else block
			elseLabel=strdup(freshLabel());
			tree->right->falseLabel=strdup(elseLabel);
			if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
			{
				char * buffer=(char *) malloc(300);
				char * cond3AC=_3ACForOperations(condition);
				strcat(buffer,condition->code);
				strcat(buffer," \nifz ");
				strcat(buffer,cond3AC);
				strcat(buffer," goto ");
				strcat(buffer,elseLabel);
				strcat(buffer,"\0");
				condition->code=strdup(buffer);
			}
			else
			{
				SwapSides(condition);
				InsertLabelsIntoCondition(condition,thenLabel,tree->next,elseLabel);
				MakeIfIntoIfZ(condition,tree->next, elseLabel);
				ConditionTreatment(condition);
			}
			strcat(ifcode,"goto ");
			strcat(ifcode,tree->next);
			strcat(ifcode,"\n");
			strcat(ifcode,"\0");
			tree->left->code=strdup(ifcode);
			
			
		}
		else
		{
			if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
			{
				char * buffer=(char *) malloc(300);
				char * cond3AC=_3ACForOperations(condition);
				strcat(buffer,condition->code);
				strcat(buffer," \nifz ");
				strcat(buffer,cond3AC);
				strcat(buffer," goto ");
				strcat(buffer,tree->next);
				strcat(buffer,"\0");
				condition->code=strdup(buffer);
			}
			else
			{
				SwapSides(condition);
				InsertLabelsIntoCondition(condition,thenLabel,tree->next,NULL);
				MakeIfIntoIfZ(condition,tree->next, NULL);
				ConditionTreatment(condition);
			}
			strcat(ifcode,tree->next);
			strcat(ifcode,":\n");
			strcat(ifcode,"\0");
			tree->left->code=strdup(ifcode);
		}
			
		
	}
	else if(strcmp(tree->token,"while")==0 && strcmp(tree->trueLabel,"")==0)
	{ 
		
		char * thenLabel;
		char * whileLabel;
		//char thencode[2000]="";
		char whilecode[2000]="";
		node * condition=tree->left;//if(x>y) => condition= '>')
		notToEnterLeft=1;
		notToEnterRight=1;
		thenLabel=strdup(freshLabel());
		whileLabel=strdup(freshLabel());
		// if WHILE has an empty block then right child will be null
		if (tree->right !=NULL)
                    _3ACMain(tree->right);//then block 
		tree->trueLabel=strdup(whileLabel);
		tree->left->trueLabel=strdup(thenLabel);
		if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
		{ //@@@@@
			char * buffer=(char *) malloc(300);
			char * cond3AC=_3ACForOperations(condition);
			strcat(buffer,condition->code);
			strcat(buffer," \nifz ");
			strcat(buffer,cond3AC);
			strcat(buffer," goto ");
			strcat(buffer,tree->next);
			strcat(buffer,"\0");
			condition->code=strdup(buffer);
		}
		else
		{
			SwapSides(condition);
			InsertLabelsIntoCondition(condition,thenLabel,tree->next,NULL);
			MakeIfIntoIfZ(condition,tree->next, NULL);
			ConditionTreatment(condition);
		}
		strcat(whilecode,"goto ");
		strcat(whilecode,whileLabel);
		strcat(whilecode,"\n");
		strcat(whilecode,"\0");
		tree->code=strdup(whilecode);
		
	}
	else if(strcmp(tree->token,"for")==0 && strcmp(tree->trueLabel,"")==0)
	{ 
		
		char * thenLabel;
		char * forLabel;
		//char thencode[2000]="";
		char forcode[2000]="";
		_3ACForAssignment(tree->left->left->left);//init the for loop
		node * condition=tree->left->right->left;//if(x>y) => condition= '>')
		notToEnterLeft=1;
		notToEnterRight=1;
		thenLabel=strdup(freshLabel());
		forLabel=strdup(freshLabel());
		// if FOR has an empty block then right child will be null
		if (tree->right !=NULL)
                    _3ACMain(tree->right);//then block  //code
		tree->trueLabel=strdup(forLabel);
		// give the condition's label its "then label"'
		tree->left->right->left->trueLabel=strdup(thenLabel);
		if(strcmp(condition->token,"||")!=0 && strcmp(condition->token,"&&")!=0)
		{ //@@@@@
			char * buffer=(char *) malloc(300);
			char * cond3AC=_3ACForOperations(condition);
			strcat(buffer,condition->code);
			strcat(buffer," \nifz ");
			strcat(buffer,cond3AC);
			strcat(buffer," goto ");
			strcat(buffer,tree->next);
			strcat(buffer,"\0");
			condition->code=strdup(buffer);
		}
		else
		{
			SwapSides(condition);
			InsertLabelsIntoCondition(condition,thenLabel,tree->next,NULL);
			MakeIfIntoIfZ(condition,tree->next, NULL);
			ConditionTreatment(condition);
		}
		strcat(forcode,"goto ");
		strcat(forcode,forLabel);
		strcat(forcode,"\n");
		strcat(forcode,"\0");
		tree->code=strdup(forcode);
		
	}
	else if(strcmp(tree->token,"=")==0)
	{
		_3ACForAssignment(tree);
		
	}
	else if(strcmp(tree->token,"return")==0)
	{
		_3ACForReturn(tree);
		
	}
	if(strcmp(tree->token,"var")==0)
	{
		_3ACForVar(tree);
		return;
	}
	if ( tree->left && !notToEnterLeft)
		_3ACMain(tree->left);
	if (tree->right && !notToEnterRight)
		_3ACMain(tree->right);
	//print
	//if(strcmp(tree->code,"")!=0) //if empty, not print
	//	printf("%s\n",tree->code);

}

// if left son token = . the next only right
//example: a = b+c-d*d ==> t0=d*d, t1=b+c, t2=t1-t0, t3 = t2 


// if left son token = . the next only right
//example: a = b+c-d*d ==> t0=d*d, t1=b+c, t2=t1-t0, t3 = t2 
void recursivePrint(node* tree){//its a function that helps to understand the tree. do not delete this function
	printf("tree->token = %s  tree->type = %s\n",tree->token,tree->type);
	if(tree->left){
		printf("start tree->left:\n");
		recursivePrint(tree->left);
		printf("end tree->left:\n");
	}
	if(tree->right){
		printf("start tree->right:\n");
		recursivePrint(tree->right);
		printf("end tree->right:\n");
	}
}

char* _3ACString(node* tree){//x[1] or &x[1] will produce 2 lines: 1. t0 = 1  2. t1 = x + t0
	char buffer[256]="";	
	char * newVar1;
	char * newVar2;
	newVar1=strdup(freshVar(tree->type));
	strcat(buffer,newVar1);//t0
	strcat(buffer," = ");//=
	strcat(buffer,tree->right->token);//1
	strcat(buffer,"\n");//\n
	newVar2=strdup(freshVar(tree->type));
	strcat(buffer,newVar2);//t1
	strcat(buffer," = ");//=
	if(strcmp(tree->left->type,"string[]")==0){
		strcat(buffer,tree->left->token);//x
	}
	else if(strcmp(tree->left->type,"charptr")==0){
		strcat(buffer,tree->left->left->token);//x
	}
	strcat(buffer," + ");//+
	strcat(buffer,newVar1);//t0
	tree->code=strdup(buffer);
	//t0
	return newVar2;//t1
	
}

void _3ACForAssignment(node * tree) //new
{	
	//recursivePrint(tree);
	char buffer[256]="";
	char * newVar;
	if(strcmp(tree->left->token,"[]")==0){
		strcat(buffer,"*(");
		newVar = strdup(_3ACString(tree->left));
		strcat(buffer,newVar);
		strcat(buffer,") = ");
	}
	else{
		if(strcmp(tree->left->token,"^")==0)
		{
			strcat(buffer,"^");
			strcat(buffer,tree->left->left->token);
		}
		else	
			strcat(buffer,tree->left->token);
		strcat(buffer," = ");
	}
	if (strcmp(tree->right->constType,"procedure")==0) // michael
		strcat(buffer,_3ACForProcedureActivate(tree->right));
	else
		strcat(buffer,_3ACForOperations(tree->right));

	tree->code=strdup(buffer);
	//print
	//if(strcmp(tree->code,"")!=0) //if empty, not print
	//	printf("%s\n",tree->code);
}
int checkIsConst(node* tree)
{
	if(strcmp(tree->constType,"var")!=0)//check if is of type const
		return 1;
	return 0;
}

char * _3ACForOperations(node * tree)
{
	char * newVar;
	char * newVar2; //for <= or >= because need 2 variables
	char * chainingVar;
	char buffer[128]="";
	char bufferLeft[128]="";
	char bufferRight[128]="";
	char bufferToken[2]=""; 
	if (tree && tree->left==NULL&&tree->right == NULL)//if leaves
	{
		//printf("treetoken = %s Origintype = %s Actualtype = %s\n",tree->token, tree->constType,tree->type);
		if(strcmp(tree->constType,"procedure")==0){
			return _3ACForProcedureActivate(tree);
		}
			
		if(checkIsConst(tree) == 1)
		{
			newVar = strdup(freshVar(tree->type));
			strcat(buffer,newVar);
			strcat(buffer," = ");
			strcat(buffer,tree->token);
			tree->code = strdup(buffer);
			return newVar;
		}
		if(strcmp(tree->constType,"var")==0 && strcmp(tree->type,"boolean")==0) // if (ID) // michaell
		{
			newVar=strdup(freshVar(tree->type));
			strcat(buffer,newVar);
			strcat(buffer," = ");
			strcat(buffer,tree->token);

			tree->code=strdup(buffer);
			return newVar;
		}
		tree->code = strdup("");
		return tree->token;
	}
	if(strcmp(tree->token,"+")==0 || strcmp(tree->token,"*")==0 || strcmp(tree->token,"-")==0 || strcmp(tree->token,"/")==0 
			|| strcmp(tree->token,"==")==0 || strcmp(tree->token,"<")==0 || strcmp(tree->token,">")==0 
			|| strcmp(tree->token,"!=")==0 || strcmp(tree->token,"&&")==0 || strcmp(tree->token,"||")==0) 
	{
		strcat(bufferLeft,_3ACForOperations(tree->left));
		strcat(bufferRight,_3ACForOperations(tree->right));
		newVar=strdup(freshVar(tree->type)); // michaelll update last
		strcat(buffer,newVar);
		strcat(buffer," = ");
		strcat(buffer,bufferLeft);
		strcat(buffer,tree->token);
		strcat(buffer,bufferRight);

		tree->code=strdup(buffer);
	}
	if(strcmp(tree->token,"!")==0) // michaell
	{
		strcat(bufferRight,_3ACForOperations(tree->left));
		newVar=strdup(freshVar(tree->left->type));
		strcat(buffer,newVar);
		strcat(buffer," = ");
		strcat(buffer,tree->token);
		strcat(buffer,bufferRight);
		tree->code=strdup(buffer);
	}
	if(strcmp(tree->token,"|")==0)//ruben fix
	{
		newVar = strdup(freshVar(tree->type));
		strcat(buffer,newVar);
		strcat(buffer," = ");
		strcat(buffer,"|");
		strcat(buffer,_3ACForOperations(tree->left));	
		strcat(buffer,"|");
		tree->code=strdup(buffer);
	}
	if(strcmp(tree->token,">=")==0||strcmp(tree->token,"<=")==0)
	{
		strcat(bufferLeft,_3ACForOperations(tree->left));
		strcat(bufferRight,_3ACForOperations(tree->right));
		newVar=strdup(freshVar(tree->type)); // boolean 
		strcat(buffer,newVar);
		strcat(buffer," = ");
		strcat(buffer,bufferLeft);
		bufferToken[0]=tree->token[0]; //take only > or <
		bufferToken[1]='\0'; //convert to string 
		strcat(buffer,bufferToken);  
		strcat(buffer,bufferRight);
		strcat(buffer,"\n");
		newVar2=strdup(freshVar(tree->type));// boolean 
		strcat(buffer,newVar2);
		strcat(buffer," = ");
		strcat(buffer,bufferLeft);
		strcat(buffer,"==");
		strcat(buffer,bufferRight);
		
		// the format of return: newVar || newVar2
		// those rows create this foramt
		chainingVar = strdup(freshVar(tree->type));
		strcat(buffer,"\n");
		printf("chainingVar = %s\n",chainingVar);
		strcat(buffer,chainingVar);
		strcat(buffer," = ");
		strcat(buffer,newVar);
		strcat(buffer,"||");
		strcat(buffer,newVar2);
		tree->code=strdup(buffer);
		return chainingVar;

	}
	if(strcmp(tree->token,"[]")==0)//&a[4]
	{
		newVar = strdup(_3ACString(tree));
	}	
	if(strcmp(tree->token,"&")==0)//&a
	{
		newVar=strdup(freshVar(tree->type));
		strcat(buffer,newVar);
		strcat(buffer," = ");
		strcat(buffer,tree->left->token);
		tree->code = strdup(buffer);
		return newVar;
	}
//ruben start
	if(strcmp(tree->token,"^")==0)
	{
		if(strcmp(tree->left->token,"+")==0 || strcmp(tree->left->token,"*")==0 || strcmp(tree->left->token,"-")==0 || strcmp(tree->left->token,"/")==0)
		{
		strcat(bufferLeft,_3ACForOperations(tree->left));
		newVar=strdup(freshVar(tree->left->type));
		strcat(buffer,newVar);
		strcat(buffer," = ");
		strcat(buffer,"^(");
		strcat(buffer,bufferLeft);
		strcat(buffer,")");
		tree->code=strdup(buffer);
		}
		
	}
//ruben end
/*
	if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0){
		newVar=strdup(freshVar(tree->type));
		strcat(buffer,newVar);
	
	}
*/
	return newVar;
	
}


int _3ACForProcedureParameters(node * tree)
{
	// parameter: procedure parameter node //
	char buffer[128] = "";
	int counter = 0;

	if (strcmp(tree->token,",")!=0)
	{ // if parameter then update tree->code //
		strcpy(buffer,"PushParam ");
		strcat(buffer,tree->token);
		tree->code = strdup(buffer);
		counter = 1;		
	}
	else
	{ // if seperator (,) //
		counter += _3ACForProcedureParameters(tree->left);
		if (tree->right)
			counter += _3ACForProcedureParameters(tree->right);
	}
	return counter;
	
}

void _3ACForReturn(node * tree)
{
	// parameter: return node //
	char buffer[128] = "";

	strcpy(buffer,"return "); // insert into buffer 'return' //

	strcat(buffer,_3ACForOperations(tree->left)); // insert into buffer t0 //

	tree->code = strdup(buffer);	
}

void _3ACForVar(node * tree)
{
	// parameter: 'var'
	int idCounter = 1; // counter for amount of id //
	int bytesByType = numberOfBytes(tree->right->type); // counter of amount of bytes for the type //

	tree = tree->left; // go to first ID //
	while (tree->right)
	{
		idCounter += 1;
		// tree->left->left points to "=" node
		if (tree->left->left)
                    _3ACForAssignment(tree->left->left);
            
		tree = tree->right;
	}
	// loop ended before reaching last node
	if (tree->left!=NULL)
                _3ACForAssignment(tree->left);
	//printf("idCounter: %d\tbyteCounter: %d\n",idCounter,bytesByType);
	byteCounter += idCounter*bytesByType; // update global counter of bytes //
}

char* _3ACForProcedureActivate(node * tree)
{
	// parameter: procedure name node. 	Example: x=foo(a) OR return foo(a) //
	char buffer[128] = "";
	char byteNum[128];
	char *freshVarToReturn;
	int counter = 0;
	
	if (tree->left) // if there are parameters //
		counter = _3ACForProcedureParameters(tree->left);

	freshVarToReturn = strdup(freshVar(tree->type)); // allocate new t0 // 
	strcpy(buffer,freshVarToReturn); // get fresh var //
	strcat(buffer," = LCall ");
	strcat(buffer,tree->token); // copy the function name //
	if (counter != 0) // michaelll last update
	{
		strcat(buffer,"\nPopParams ");
   		sprintf(byteNum,"%d",counter*4); // convert the counter from int to string //
		strcat(buffer,byteNum);
	}
	tree->code = strdup(buffer);

	return freshVarToReturn;	
}

void _3ACForProcedureDefine(node * tree)
{
	// parameter: 'procedure' node //
	char buffer[128] = "";
	char byteNum[128];

	strcpy(buffer,tree->left->token); // insert the name of the procedure to the buffer // 
	strcat(buffer,":");
	strcat(buffer,"\nBeginFunc ");
	varCounter = 0; // reset varCounter //
	byteCounter = 0; // reset byteCounter //

	_3ACMain(tree->right); // now call the main 3AC function //
	 
    	sprintf(byteNum,"%d",byteCounter); // convert the byteCounter from int to string //
	strcat(buffer,byteNum);
	tree->left->code = strdup(buffer);
	strcpy(tree->left->code,buffer); // copy buffer to procedureName node (the left son of procedure) //
	tree->code = strdup("EndFunc"); // insert into 'procedure' node //
}

//end part4

void CallProcedureParasTreat(char * proName,node * paras)// ariel && michael
{
	symbolTable * startOfProcedureParams=NULL; 
	symbolTable * procedureRow=current;
	symbolTable * temp;
	int flag = 0;
	while(1>0)//to find the paramaters of procedure in the symbol table
	{
		if(strcmp(procedureRow->scope,proName)==0 && !flag) // save the first parameter of the function //
		{
			flag = 1;
			startOfProcedureParams=procedureRow;
		}
		else if (strcmp(procedureRow->scope,"procedure")==0 && strcmp(procedureRow->name,proName)==0)
			break;
		procedureRow=procedureRow->prevST;
	}
	strcpy(paras->type,procedureRow->type);//to update the type of function.
	//if foo has parameters
	//procedureRow=foo row in ST
	//startOfProcedureParams= p(first parameter of foo) row in ST
	//if foo has no parameters
	//startOfProcedureParams=procedureRow=foo row in ST
	temp=startOfProcedureParams;

	if (temp == NULL && paras->left) // if there are no parameters // michaell
	{
		printf("Procedure %s has no paramaters!\n",proName);
		exit(1);
	}

	if (temp == NULL && paras->left == NULL) // if there are no parameters // michaell
		return;

	//printf("temp->scope: %s\ttempName: %s\n",temp->scope,temp->name);
/*
	while(strcmp(temp->scope,"var")==0)
	{
		//printf("temp->scope: %s\tproName: %s\n",temp->scope,proName);
		temp->scope=strdup(proName);
		temp=temp->prevST;
	}
*/
	if(startOfProcedureParams==NULL) //procName not exists
	{
		printf("Procedure %s not exists!\n",proName);
		exit(1);
	}
/*
	else if(startOfProcedureParams==procedureRow)//there are no paras to procedure proName
	{
		if(paras->left!=NULL)
		{		
			printf("Procedure %s has no paramaters!\n",proName);
			exit(1);
		}
	}
*/
	else //must be on his paras,need to treat it
	{
		procedureParas=dupST(proName,startOfProcedureParams);
		procedureParas=reverseST(procedureParas);
		checkFuncParam(proName,paras->left,paras);
	}
}


symbolTable* dupST(char * proName,symbolTable * st) //new
{
	symbolTable * temp;
	if(strcmp(st->scope,"procedure")==0)
		return NULL;
	temp=(symbolTable*)malloc(sizeof(symbolTable));
	temp->name=strdup(st->name);
	temp->type=strdup(st->type);
	temp->scope=strdup(st->scope);
	temp->prevST=dupST(proName,st->prevST);
	return temp;

}

symbolTable* reverseST(symbolTable * st)//new
{
	
	if(st->prevST==NULL) //for one no need reverse
		return st;
	if(st->prevST->prevST==NULL) //for two
	{
		symbolTable * swap=st->prevST;
		swap->prevST=st;
		st->prevST=NULL;
		return swap;
	}
	//for 3 and more to do reverse
	symbolTable * prevOfNew=NULL; //point to next of new st
	symbolTable * prevOfOriginal; 
	symbolTable * nextOldST;
	while ( st->prevST!=NULL )
	{
		//printf("Name: %s, Type: %s, scope : %s \n",st->name,st->type,st->scope);
		prevOfOriginal=st->prevST;    
		st->prevST=prevOfNew; 
		if(prevOfOriginal->prevST!=NULL) 
			nextOldST=prevOfOriginal->prevST;
		else
			nextOldST=NULL;
		prevOfOriginal->prevST=st;
		prevOfNew=prevOfOriginal;
		st=nextOldST;
	}
	st->prevST=prevOfNew; 
	printf("Name: %s, Type: %s, scope : %s \n",st->name,st->type,st->scope);
	return st;
}	

void UpdateParameterType(node * tempTree)
{
    if(tempTree!=NULL)
    {
        UpdateParameterType(tempTree->left);
        if (tempTree->right && (strcmp(tempTree->right->token,",")!=0)) // go right only if not seperator //
            UpdateParameterType(tempTree->right);
	//printf("tempTree->token: %s\ttempTree->type: %s\n",tempTree->token, tempTree->type);
        if(strcmp(tempTree->type,"var")==0) // b
        {
            if(!CheckID(tempTree))
            {
                printf("ID Not exists!\n");
                exit(1);
            }
            strcpy(tempTree->type,ReturnIDType(tempTree->token)); // may change the current ST pointer ? //
        }

        else if((strcmp(tempTree->type,"+")==0) || (strcmp(tempTree->type,"-")==0) || 
                (strcmp(tempTree->type,"*")==0) || (strcmp(tempTree->type,"/")==0))
            tempTree->type = strdup(checkBinaryOperations(tempTree->token,tempTree->left->type,tempTree->right->type)); 

        if (strcmp(tempTree->token,",")==0)
            strcpy(tempTree->type,tempTree->left->type); // update the type of seperator //                
    }    
}
void checkFuncParam(char * proName,node * paras,node * nameAndParas) 
{
    if(paras!=NULL)
    {
	if(strcmp(paras->token,",")==0 && paras->right!=NULL)//go to the last parameter
        	checkFuncParam(proName,paras->right,nameAndParas);
	UpdateParameterType(paras);
	if(procedureParas==NULL)
	{
		printf("too many parameters\n");
		exit(1);
	}
	else if(strcmp(paras->type,procedureParas->type)!=0)
	{
		printf("function parameters don't match %s : %s\n",paras->type,procedureParas->type);
                exit(1);
	}
	
	else if(procedureParas->prevST!=NULL && nameAndParas->left==paras)
    	{
		printf("too few parameters\n");	
		exit(1);
    	}
	else
	{
		procedureParas=procedureParas->prevST;
	}
    }
    if(paras==NULL && nameAndParas->left==NULL && procedureParas!=NULL)
    {
	printf("too few parameters\n");	
	exit(1);
    }

}
int checkIfProcedure(char * name)//orel --check if need?
{
	symbolTable * temp=current;
	while(temp!=NULL)
		{
			if(strcmp(temp->name,name)==0 && strcmp(temp->scope,"procedure")==0 )//&& temp->scopeNumber>=scopeNumber)
			{
				return 1;
			}
			else
				temp=temp->prevST;
		}
	return 0;
}

//check recrusivly that all ID's in the "for" loop are declared
// void checkIDForCond(node * forCond)
// {
//     while (forCond != NULL)
//     {
//         if (!strcmp(forCond->type,"var")
//         {
//             if(!CheckID(forCond))
//             {
//                     printf("ID Not exists!\n");
//                     exit(1);
//             }
//         }
//         checkIDForCond(forCond->left);
//         checkIDForCond(forCond->right);
//     }
//     return;
// }

void buildST(node * tree)
{	
	if (tree == NULL)
		return;
	if (strcmp(tree->token, "NewBlock") == 0)
		scopeCounter = scopeCounter + 1;
	if (strcmp(tree->token, "EndBlock") == 0)
	{
		while(current->scopeNumber == scopeCounter)
			current = current->prevST;
		scopeCounter = scopeCounter - 1;
	}
	int flagLeftSubTree = 0; // flag if need to go to the left sub tree //
	int flagRightSubTree = 0; // flag if need to go to the right sub tree //
	symbolTable * temp;
	if(strcmp(tree->token,"procedure")==0)
	{
	    if(strcmp("Main", tree->left->token) == 0)
            {
		    if (isMain == 0)
                    {
			    isMain = 1;
		    }
                    else
                    {
                        printf("Function Main already exists!");
                            exit(1);
                    }
                    if (tree->left->left != NULL)
                    {
                            printf("Function Main cannot accept any arguments");
                            exit(1);
                    }
            }
            char* saveStateOfReturnType; // create local return type to use if i have nested functions //
            symbolTable * currentState;
            int parameterCounter = 0;

            if(checkExist(tree->left->token))
            {
                    printf("The name %s exists\n",tree->left->token);
                    exit(1);
            }
            scopeCounter = scopeCounter+1;
            temp=(symbolTable*)malloc(sizeof(symbolTable));
            temp->scopeNumber = scopeCounter;
            temp->prevST=current; // point the new ST to the previous //
            // change current state //
            current=temp;
            current->name=strdup(tree->left->token);
            current->type=strdup(tree->left->right->left->type);
            //printf("current %s\t scope number: %d\n",current->name,scopeCounter);
            if (currentReturnType != NULL)
                    saveStateOfReturnType = currentReturnType; // save the current return type to use in the end of this block //
            // change current return type //		
            currentReturnType = current->type; // use global variable of return type //
            current->scope=strdup(tree->token);
            if (tree->left->left != NULL)
            {
                    buildVarOfProcedure(tree->left->left,tree->left->token); 
                    parameterCounter = countNumberOfParameters(tree->left->left);
            }

            currentState = current; //save state before changing current //

            // michael update - do NOT DELETE!!:
            // it saves in the SymbolTable the function + the parameters it should get.
            // the problem is that the names of the parameters are also saved. Therefore we can't use those names anymore (because they already exist)
            // Example:		procedure foo(a,b: integer) return integer {...}
            //			Now in other functions, i can't use 'a' or 'b'.
            // Solution: we need to delete the name when we finish with this function (delete only the name) //	



            flagLeftSubTree = 1;
            if (tree->right->left != NULL)
                    buildST(tree->right->left);
            //buildST(tree->right); // i have to make it here so i will return to the exact point (in case of nested functions) //
            //scopeCounter = scopeCounter - 1;
            if (tree->right->right != NULL)
                    buildST(tree->right->right);	
            flagRightSubTree = 1;	
            currentReturnType = saveStateOfReturnType; // save the privious return type //
            if (currentState != NULL)
            {
                    current = currentState; // save the privious Symbol table state //
                    deleteNameOfParameters(parameterCounter); // delete the names of the parameters
            }

		
		
	}

	
		//scopeCounter = scopeCounter - 1;
	else if(strcmp(tree->token,"var")==0)
	{
		buildVar(tree);
		flagLeftSubTree = 1;
		flagRightSubTree = 1;
	}
	else if(strcmp(tree->token,"COND")==0)
	{ 
		symbolTable * curr=current;//save state
		node * ifcond=tree->left->left;//if condition
		node * ifblock=tree->left->right;//if block
		if(!CheckID(ifcond))//check all ids there if something is used when it not declared
		{
			printf("ID Not exists!\n");
			exit(1);
		}
		UpdateIDType(ifcond);
		buildST(ifcond);

		checkIfConditionTypeIsBoolean(ifcond); // michaell

		scopeCounter = scopeCounter + 1;
		buildST(ifblock);//continue
		scopeCounter = scopeCounter - 1;
		current=curr;//back state- after i got back from the block,i need to go back up to latest
		if(tree->right)//there is else
		{
			node * elseblock=tree->right->left;//go in else block
			curr=current;//save state again before else
			scopeCounter = scopeCounter + 1;
			buildST(elseblock);
			scopeCounter = scopeCounter - 1;
			current=curr;
                }
		flagLeftSubTree = 1;
		flagRightSubTree = 1;
	}
	else if(strcmp(tree->token,"while")==0) 
	{ 
		char * lvaltype;
		char * rvaltype;
		node * whilecond=tree->left;
		node * whileblock;
		symbolTable * curr=current;//save state before
		//if has a non-empty block
                if(!CheckID(whilecond))
                {
                        printf("ID Not exists!\n");
                        exit(1);
                }
                UpdateIDType(whilecond);
                buildST(whilecond);
                checkIfConditionTypeIsBoolean(whilecond); // michaell
                
		if (tree->right){
                        if(strcmp(tree->right->token,"")==0)
                        {
                                whileblock=tree->right->left;
                        }
                        else
                        {
                                whileblock=tree->right;
                        }

                        scopeCounter = scopeCounter + 1;  
                        buildST(whileblock);
                        scopeCounter = scopeCounter - 1; 
                        current=curr;
                        flagLeftSubTree = 1;
                        flagRightSubTree = 1;
		}
	}
	else if(strcmp(tree->token,"for")==0) 
	{ 
		char * lvaltype;
		char * rvaltype;
		node * forCond=tree->left->right->left;
		node * forBlock;
		symbolTable * curr=current;//save state before
		forBlock=tree->right;
		node * tempForCond = forCond;
		//checkIDForCond(forCond);
		UpdateIDType(forCond);
		buildST(forCond);

		//checkIfConditionTypeIsBoolean(forCond); // michaell

		scopeCounter = scopeCounter + 1;  
		buildST(forBlock);
		scopeCounter = scopeCounter - 1; 
		current=curr;
		flagLeftSubTree = 1;
		flagRightSubTree = 1;
        }
	else if(strcmp(tree->token,"return")==0)
	{ 
                //only non-void functions have "return"->left, and therefore enter
                // void functions have no left child
                if (tree->left != NULL)
                {// check if current function was already declared (proc->right return)
                        if(checkIfProcedure(tree->left->token))
                        {
                                //printf("BEFORE -> procedure Name: |%s|\n",tree->left->token); 
                                CallProcedureParasTreat(tree->left->token,tree->left);//foo,params with foo
                                //printf("AFTER -> procedure Name: |%s|\n",tree->left->token); 
                        }
                        else
                        {
                                char * lvaltype;
                                if(!CheckID(tree->left))
                                {
                                        printf("ID Not exists!\n");
                                        exit(1);
                                }
                                UpdateIDType(tree->left); // get the type of left node //
                                buildST(tree->left); // 
                                if (strcmp(tree->left->type,"string")==0)
                                {
                                        printf("return type can not be of type string!\n");
                                        exit(1);
                                }
                
                                lvaltype=strdup(tree->left->type);
                                
                                //printf("return type: |%s|\n",lvaltype); // temp //
                                //printf("actual return type: |%s|\tdeclared type: |%s|\n",lvaltype,currentReturnType); // temp //
                                strcpy(tree->type,(checkBinaryOperations("return",lvaltype,currentReturnType))); 
                        }
		}
	}
	else if((strcmp(tree->token,"||")==0) || (strcmp(tree->token,"&&")==0) || (strcmp(tree->token,">")==0) || (strcmp(tree->token,">=")==0) || (strcmp(tree->token,"<")==0) || (strcmp(tree->token,"<=")==0) || (strcmp(tree->token,"==")==0) || (strcmp(tree->token,"!=")==0) || (strcmp(tree->token,"=")==0) || (strcmp(tree->token,"+")==0) || (strcmp(tree->token,"-")==0) || (strcmp(tree->token,"*")==0) || (strcmp(tree->token,"/")==0))
	{
		//printf("token: |%s|\ttype: |%s|\tconstType: |%s|\n",tree->right->token,tree->right->type,tree->right->constType); 			
		if(strcmp(tree->token,"=")==0 && checkIfProcedure(tree->right->token))
		{	
			char *lvaltype;
			char *rvaltype;
			CallProcedureParasTreat(tree->right->token,tree->right);
			
			UpdateIDType(tree->left);
			lvaltype=strdup(tree->left->type);
			rvaltype=strdup(tree->right->type);

			tree->type = strdup(checkBinaryOperations(tree->token,lvaltype,rvaltype)); 
		}
		else
		{
			char * lvaltype;
			char * rvaltype;
			if(!CheckID(tree->left) || !CheckID(tree->right))
			{
				printf("ID Not exists!\n");
				exit(1);
			}

			UpdateIDType(tree);
			buildST(tree->left); 
			buildST(tree->right);
			
			lvaltype=strdup(tree->left->type);
			rvaltype=strdup(tree->right->type);
			//printf("token: |%s|\tleft: |%s|\tright: |%s|\n",tree->token,lvaltype,rvaltype);
			tree->type = strdup(checkBinaryOperations(tree->token,lvaltype,rvaltype)); 
			//printf("tree->type: |%s|\n",tree->type);
		}
	}
	else if ((strcmp(tree->token,"^")==0) || (strcmp(tree->token,"&")==0) || (strcmp(tree->token,"[]")==0) || (strcmp(tree->token,"!")==0))
		{
		char * lvaltype;
		if(!CheckID(tree->left))
		{
			printf("ID Not exists!\n");
			exit(1);
		}
		UpdateIDType(tree->left);

		buildST(tree->left); 
		buildST(tree->right);
		lvaltype=strdup(tree->left->type);
		tree->type = strdup(checkUnaryOperations(tree->token,lvaltype)); 
		}
	else if (strcmp(tree->token,"|")==0 && tree->left != NULL) // absolute //
		{
		char * lvaltype;
		if(!CheckID(tree->left))
		{
			printf("ID Not exists!\n");
			exit(1);
		}
		
		UpdateIDType(tree->left);
		buildST(tree->left); 
		lvaltype=strdup(tree->left->type);
		tree->type = strdup(checkUnaryOperations("||",lvaltype)); 
		}
	//printf("token: |%s|\ttype: |%s|\n",tree->token, tree->type);
		
	if(tree->left && !flagLeftSubTree)
		buildST(tree->left);
	
	if(strcmp(tree->token, "BLOCK") == 0 )
	{
	    
	    while(current && strcmp(current->scope, "var") == 0 && scopeCounter==current->scopeNumber)
		{
			current = current->prevST;
		}
		
	}
	
	if(tree->right && !flagRightSubTree)
		buildST(tree->right);	
	if (ReturnFlag == 1)
	{
		scopeCounter = scopeCounter - 1;
		ReturnFlag = 0;
	}
	if (strcmp(tree->token, "return") == 0)
		ReturnFlag = 1;
		
}

void checkIfConditionTypeIsBoolean(node *cond) // michaell
{
	// we will use this function ONLY when we have an ID in the condition (AND ONLY THAT ID).
	// Example:	if (ID)		when (ID)... 
	if (strcmp(cond->type,"boolean")==0)
		return;
	printf("Error! Condition Type is not boolean.\nActual type: %s\n",cond->type); 
	exit(1);
}
void deleteNameOfParameters(int numberOfParametersToDelete)
{
	// at first current is pointing at the first parameter //

	symbolTable * saveCurrent = current;
	while (strcmp(current->scope,"procedure")!=0)
	{
		//printf("BEFORE:\tcurrent-> %s\ttype: %s\tscope: %s\n",current->name,current->type,current->scope);
		strcpy(current->name,"");
		//printf("AFTER:\tcurrent-> %s\ttype: %s\tscope: %s\n",current->name,current->type,current->scope);
		current = current->prevST;
	}

	current = saveCurrent;
}

int countNumberOfParameters(node *tree)
{
	// parameter: tree is the first parameter //
	node * saveNodeOfFirstParameter;
	int parameterCounter = 0;

	while (tree != NULL)
	{
		saveNodeOfFirstParameter = tree;
		while(strcmp(tree->token,":")!=0)
		{
			if (strcmp(tree->token,",")!=0)
				parameterCounter += 1;
			tree = tree->left;
		}	
		tree = saveNodeOfFirstParameter;
		tree = tree->right;
	}
	return parameterCounter;
}

char * buildVarOfProcedure(node * tree, char * procedureName) // ariel && michael
{
	char * type;
	if (tree->left==NULL)
		return tree->type;
	if (tree->right!=NULL)
		buildVarOfProcedure(tree->right, procedureName);
	
	type=buildVarOfProcedure(tree->left, procedureName);
	if(strcmp(tree->token,",")!=0 && strcmp(tree->token,":")!=0)
	{
		symbolTable * temp=(symbolTable*)malloc(sizeof(symbolTable));
		temp->scopeNumber = scopeCounter;
		temp->prevST=current;
		current=temp;
		current->name=strdup(tree->token);
		current->type=strdup(type);
		current->scope=strdup(procedureName); // ariel && michael
		//current->scope=strdup("var");
	}
	return type;
}

void buildVar(node * tree)
{
	//symbolTable * originalCurrent = current; //save state before
	node * tempTree=tree,* saveTree=NULL ;
	char * type= tempTree->right->type;
	//printf("var type: |%s|\tcurrent type: |%s|\n",type, current->type);
	tempTree=tempTree->left;
	int exist=0;
	while(tempTree&&!exist)
	{
	    
		if(checkExist(tempTree->token))
			exist=1;
		else
		{
           
			tempTree->type = strdup(type); // 
			symbolTable * temp=(symbolTable*)malloc(sizeof(symbolTable));
			temp->scopeNumber = scopeCounter;
			temp->prevST=current;
			current=temp;
			current->name=strdup(tempTree->token);
			current->type=strdup(type);
			current->scope=strdup("var");
			
                
			//printf("name: |%s|\ttype: |%s|\tscope: |%s|\n",current->name, current->type,current->scope);
			tempTree=tempTree->right;
		}
		//current = originalCurrent;
	}
	if(exist)
	{
		printf("The name %s exists\n",tempTree->token); 
		exit(1);
	}
}
int CheckID(node * tempTree)
{
	int flag=1;
	if(tempTree!=NULL)
	{
		if(strcmp(tempTree->type,"var")==0)
			if(!checkNameExists(tempTree->token))
			{
				printf("The name %s not exists\n",tempTree->token);
				exit(1);
			}
		flag=CheckID(tempTree->left);
		if(!flag)
			return 0;
		flag=CheckID(tempTree->right);
		if(!flag)
			return 0;
			
	}
	return 1;
	
}

void UpdateIDType(node * tempTree)
{

	if(tempTree!=NULL)
	{
		UpdateIDType(tempTree->left);
		UpdateIDType(tempTree->right);
		if(strcmp(tempTree->type,"var")==0)
		{
			//printf("BEFORE\ttoken: %s\ttype: %s\n",tempTree->token,tempTree->type);
			strcpy(tempTree->type,ReturnIDType(tempTree->token));
			//printf("AFTER\ttoken: %s\ttype: %s\n",tempTree->token,tempTree->type);
		}
	}
	
}

char * ReturnIDType(char * name)
{
	symbolTable * temp = current;
	while(temp)
	{
		if(strcmp(temp->name,name)==0)
			return temp->type;
		temp=temp->prevST;
	}
	//printf("ERROR");
	return "ERROR"; // it should never get here //
}

void printST()
{
	symbolTable * temp=current;
	while(temp){
		printf("name: %s\ttype: %s\tscope: %s\n",temp->name,temp->type,temp->scope);
		temp = temp->prevST;

	}
}
int checkExist(char * name)
{
	symbolTable * temp=current;
	while(temp){
		//printf("%s %d %s %d\n", temp->name, temp->scopeNumber, name, scopeCounter);
		if (temp->scopeNumber < scopeCounter)
		{
		    //printf("%d YYYYYY %d" , temp->scopeNumber, scopeCounter);
		    return 0;
		}
		if(strcmp(temp->name,name)==0 && (scopeCounter == temp->scopeNumber))
		{
		    //printf("%d XXXX %d" , temp->scopeNumber, scopeCounter);
		    return 1;
		}
		else
		{
		    temp=temp->prevST;
		}
	}
	return 0;
}

int checkNameExists(char * name)
{
	symbolTable * temp=current;
	while(temp){
		if(strcmp(temp->name,name)==0)
		{
		    return 1;
		}
		else
		{
		    temp=temp->prevST;
		}
	}
	return 0;
}
type typeOf(char* str) {
	if (strcmp(str, "boolean") == 0)
		return BOOLEAN_t;
	if (strcmp(str, "char") == 0)
		return CHAR_t;
	if (strcmp(str, "int") == 0)
		return INT_t;
	if (strcmp(str, "string") == 0)
		return STRING_t;
	if (strcmp(str, "string[]") == 0)
		return STRINGARRAY_t;
	if (strcmp(str, "intptr") == 0)
		return INTPTR_t;
	if (strcmp(str, "charptr") == 0)
		return CHARPTR_t;
	if (strcmp(str, "return") == 0)
		return RETURN_t;
	if (strcmp(str, "null") == 0)
		return Null_t;
	else return ELSE_t;
}

//15
// operators:=///////////////////////////////////dont know the type of string[i]
char* assignment(char* st1, char* st2) {
	if (typeOf(st1) == typeOf(st2)) {
		return st1;
	}
	if (strcmp(st1,"string[]")==0 && strcmp(st2,"string")==0) {
        	return st1;
    	}
	if ((typeOf(st1) == INTPTR_t || typeOf(st1) == CHARPTR_t) && typeOf(st2) == Null_t)
		return st1;
	printf("assignment error\n");
	exit(1);
	return "";
}
//16.1 and 17
// operators:+-*/
char* arithmetics(char* op, char* st1, char* st2) {
	if (typeOf(st1) == typeOf(st2) && typeOf(st1) == INT_t) {
		return "int";
	}
	if ((strcmp(op, "+") == 0 || strcmp(op, "-") == 0) && (typeOf(st1) == INTPTR_t || typeOf(st1) == CHARPTR_t) && typeOf(st2) == INT_t)
		return st1;
	printf("arithmetics error\n");
	exit(1);
	return "";
}
//16.2
// operators:&&||
char* andOr(char* st1, char* st2) {
	if (!(typeOf(st1) == typeOf(st2) && typeOf(st1) == BOOLEAN_t)) {
		printf("andOr error\n");
		exit(1);
	}
	return "boolean";
}
//16.3
//operators:>,<,<=,>=
char* smallerBigger(char* st1, char* st2) {
	if (!(typeOf(st1) == typeOf(st2) && typeOf(st1) == INT_t)) {
		printf("smallerBigger error\n");
		exit(1);
	}
	return "boolean";
}
////16.4
////operators:!=,==
char* equalNotEqual(char* st1, char* st2) {
	if (typeOf(st1) != typeOf(st2)) {
		printf("equalNotEqual error\n");
		exit(1);
	}
	if (typeOf(st1) == INT_t || typeOf(st1) == BOOLEAN_t || typeOf(st1) == CHAR_t || typeOf(st1) == INTPTR_t || typeOf(st1) == CHARPTR_t)
		return "boolean";
	printf("equalNotEqual error\n");
	exit(1);
	return "";
}
////16.5
////operators:| |
char* absolute(char* str) {
	if (typeOf(str) == INT_t || typeOf(str) == STRINGARRAY_t)
		return "int";
	printf("absolute error\n");
	exit(1);
	return "";
}
//16.6
//operators:!
char* not(char* str) {
	if (typeOf(str) == BOOLEAN_t)
		return "boolean";
	printf("not error\n");
	exit(1);
	return "";

}
////18
////operators:&
char* checkAddressOf(char* str) {
	if (typeOf(str) == INT_t)
		return "intptr";
	if (typeOf(str) == CHAR_t)
		return "charptr";
	if (strcmp(str,"string[]")==0)
		return "charptr";
	printf("checkAddressOf error\n");
	exit(1);
	return "";
}
////18
////operators: [] (for string[i])
char* checkAddressOfArray(char* str) {
	if (typeOf(str) == STRINGARRAY_t)
		return "char";
	if (typeOf(str) == CHARPTR_t)
		return "charptr";
	printf("checkAddressOfArray error\n");
	exit(1);
	return "";
}
////19
////operators:^
char* checkPointAt(char* str) {
	if (typeOf(str) == INTPTR_t)
		return "int"; 
	if (typeOf(str) == CHARPTR_t)
		return "char";
	printf("checkPointAt error\n");
	exit(1);
	return "";
}

// compare return types
char* equalReturnTypes(char* st1, char* st2) {
	if (strcmp(st1,st2)==0)
		return st1;
	printf("Error! return type don't match\n");
	exit(1);
	return "";
}

int numberOfBytes(char *type) // michael
{
	if (!type)
	{
		printf("Error in numberOfBytes Function: type parameter is empty\n");
		exit(1);
	}
	//ruben add the last || in the if
	if (typeOf(type) == INT_t || typeOf(type) == STRINGARRAY_t || typeOf(type) == INTPTR_t || typeOf(type) == CHARPTR_t || typeOf(type) == STRING_t)
		return 4;
	else if (typeOf(type) == BOOLEAN_t || typeOf(type) == CHAR_t)
		return 1;
	else
	{
		printf("Error in numberOfBytes Function: type parameter is wrong: %s\n",type);
		exit(1);
	}
}

char * freshVar(char *type)//last
{
	int bytes = numberOfBytes(type);
	char * newVar = (char*)malloc(sizeof(get_int_len())+1);
	sprintf(newVar,"%d",varCounter);
	varCounter = varCounter + 1; 
	byteCounter += bytes; // update number of bytes //
	char * newVarWithT = (char*)malloc(sizeof(newVar)+1);
	newVarWithT[0] = 't';
	strcat(newVarWithT,newVar);
	return newVarWithT;	
}
char * freshLabel()//orel
{
	char * newLabel;
	int l=1;
	int value = labelCounter+1;
	char * newLabelWithT;
	newLabel = (char*)malloc(sizeof(l)+1);
	labelCounter = labelCounter + 1;
	sprintf(newLabel,"%d",labelCounter);
	newLabelWithT = (char*)malloc(sizeof(newLabel)+1);
	newLabelWithT[0] = 'L';
	strcat(newLabelWithT,newLabel);
	return newLabelWithT;	
}

int get_int_len(){
	int value = varCounter;
  	int l=1;
  	while(value>9)
	{
	l++; 
	value/=10;
	}
  	return l;
}

char* checkBinaryOperations(char* op, char* st1, char* st2) {
	if (strcmp(op, "=") == 0)
		return assignment(st1, st2);
	if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
		return arithmetics(op, st1, st2);
	if (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0)
		return andOr(st1, st2);
	if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0 || strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0)
		return smallerBigger(st1, st2);
	if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
		return equalNotEqual(st1, st2);
	if (strcmp(op, "return") == 0)
		return equalReturnTypes(st1, st2);
	printf("checkBinaryOperations error\n");
	exit(1);
	return "";
}

char* checkUnaryOperations(char* op, char* str) {
	if (strcmp(op, "||") == 0)
		return absolute(str);
	if (strcmp(op, "!") == 0)
		return not(str);
	if (strcmp(op, "&") == 0)
		return checkAddressOf(str);
	if (strcmp(op, "^") == 0)
		return checkPointAt(str);
	if (strcmp(op, "[]") == 0)
		return checkAddressOfArray(str);
	printf("checkUnaryOperations error\n");
	exit(1);
	return "";
}

void printtree(node * tree){

    if(!tree) 
        return;
    if(checkChildren(tree))
        printf("(");
    if(strcmp(tree->token,"procedure") || strcmp(tree->token,"if") || strcmp(tree->token,"else") 
        || strcmp(tree->token,"while") || strcmp(tree->token,"COND")){
	printf("%s ", tree->token); 
    }
    else if(strcmp(tree->token,"COND")!=0)//to deny the print of "COND"
	printf("%s ", tree->token); 
    if (tree->left){   
        if(checkGrandchildrenFromLeftSan(tree)){
	    addAndPrintTab();        
	}
        printtree(tree->left);    
    }
    if (tree->right){
        if(checkGrandchildrenFromRightSan(tree)){
	    addAndPrintTab();        
	}
        printtree(tree->right);         
    }
    if(checkChildren(tree))
        subAndPrintTab();

}
int yyerror(char * x){
	
	printf("%s, in line: %d:\n'%s'\n", x, yylineno, yytext);
	return 0;
}
#line 2991 "bin/y.tab.c"

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
#line 145 "src/part3bin.y"
	{buildST(yystack.l_mark[0].IST.tree); printtree(yystack.l_mark[0].IST.tree);
if (isMain != 0) printST(); else printf("Cannot find Main() function! Error!\n");
_3ACMain(yystack.l_mark[0].IST.tree); TAC_FillCode(yystack.l_mark[0].IST.tree); strcat(codebuffer,"\0"); /*printf("%s\n",codebuffer); //TAC_PrintCode($<IST.tree>1);*/
buildLabelStruct(); printFixedCode();
}
break;
case 2:
#line 152 "src/part3bin.y"
	{yyval.IST.tree=mknode("BLOCK","BLOCK",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 3:
#line 154 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 6:
#line 159 "src/part3bin.y"
	{yyval.IST.tree=mknode("procedure","procedure",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 7:
#line 160 "src/part3bin.y"
	{yyval.IST.tree=mknode("procedure","procedure",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 8:
#line 162 "src/part3bin.y"
	{yyval.IST.tree=mknode("","",yystack.l_mark[-2].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 9:
#line 163 "src/part3bin.y"
	{yyval.IST.tree=mknode("","",yystack.l_mark[-2].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 10:
#line 165 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 11:
#line 166 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 12:
#line 167 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 13:
#line 168 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 14:
#line 169 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 15:
#line 170 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 16:
#line 172 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewBlock","NewBlock",mknode("NewRow","NewRow",yystack.l_mark[-2].IST.tree, mknode("EndBlock","EndBlock",NULL,NULL)), yystack.l_mark[0].IST.tree);}
break;
case 17:
#line 173 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 18:
#line 175 "src/part3bin.y"
	{
char * e=strchr(yyval.IST.string,'_');
if(e!=NULL && (int)(e-yystack.l_mark[-4].IST.string)==0)
{
  yyerror("syntax error");
  YYERROR;
}
yyval.IST.tree=mknode(yystack.l_mark[-3].IST.string,"procedure",yystack.l_mark[-1].IST.tree,mknode("return","return",yystack.l_mark[-4].IST.tree,NULL));}
break;
case 19:
#line 184 "src/part3bin.y"
	{
char * e=strchr(yyval.IST.string,'_');
if(e!=NULL && (int)(e-yystack.l_mark[-4].IST.string)==0)
{
	yyerror("syntax error");
	YYERROR;
}
yyval.IST.tree=mknode(yystack.l_mark[-3].IST.string,"procedure",yystack.l_mark[-1].IST.tree,mknode("return","return",yystack.l_mark[-4].IST.tree,NULL));}
break;
case 20:
#line 193 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 21:
#line 194 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-3].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 22:
#line 195 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 23:
#line 196 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 24:
#line 200 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 25:
#line 201 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 26:
#line 203 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 27:
#line 204 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 28:
#line 205 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 29:
#line 207 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 30:
#line 208 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 31:
#line 209 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 32:
#line 211 "src/part3bin.y"
	{yyval.IST.tree = mknode("void","void" ,NULL,NULL);}
break;
case 33:
#line 213 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 34:
#line 214 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 35:
#line 216 "src/part3bin.y"
	{yyval.IST.tree = mknode("string[]","string[]", mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL, NULL), NULL);}
break;
case 36:
#line 218 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 37:
#line 219 "src/part3bin.y"
	{yyval.IST.tree = mknode(binToDec(yystack.l_mark[0].IST.string),yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 38:
#line 220 "src/part3bin.y"
	{yyval.IST.tree = mknode(octalToDec(yystack.l_mark[0].IST.string),yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 39:
#line 221 "src/part3bin.y"
	{yyval.IST.tree = mknode(HexaToDec(yystack.l_mark[0].IST.string),yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 40:
#line 223 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 41:
#line 224 "src/part3bin.y"
	{yyval.IST.tree = mknode("+","+", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 42:
#line 225 "src/part3bin.y"
	{yyval.IST.tree = mknode("-","-", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 43:
#line 228 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 44:
#line 229 "src/part3bin.y"
	{yyval.IST.tree = mknode("*","*", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 45:
#line 230 "src/part3bin.y"
	{yyval.IST.tree = mknode("/","/", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 46:
#line 232 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[-1].IST.tree;}
break;
case 47:
#line 233 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 48:
#line 234 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 49:
#line 235 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 50:
#line 236 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 51:
#line 243 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type , yystack.l_mark[0].IST.tree,NULL);}
break;
case 52:
#line 245 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type , yystack.l_mark[0].IST.tree,NULL);}
break;
case 53:
#line 248 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 54:
#line 249 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 55:
#line 250 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-5].IST.tree,mknode(yystack.l_mark[-3].IST.tree->token,yystack.l_mark[-3].IST.tree->type, yystack.l_mark[-1].IST.tree,NULL));
if(yyval.IST.tree->right->constType != NULL)
free(yyval.IST.tree->right->constType);
yyval.IST.tree->right->constType = strdup("procedure");
}
break;
case 56:
#line 256 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 57:
#line 257 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=", mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree), yystack.l_mark[0].IST.tree);}
break;
case 58:
#line 258 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-3].IST.tree, mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 59:
#line 259 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-2].IST.tree, yystack.l_mark[0].IST.tree);}
break;
case 60:
#line 260 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-2].IST.tree, yystack.l_mark[0].IST.tree);}
break;
case 61:
#line 261 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-2].IST.tree, yystack.l_mark[0].IST.tree);}
break;
case 62:
#line 263 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=" ,yystack.l_mark[-2].IST.tree, mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL));}
break;
case 63:
#line 264 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=" ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 64:
#line 267 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 65:
#line 268 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL);}
break;
case 66:
#line 271 "src/part3bin.y"
	{yyval.IST.tree = mknode("var","var" ,yystack.l_mark[-1].IST.tree,yystack.l_mark[-2].IST.tree);}
break;
case 67:
#line 274 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type ,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,NULL,NULL),yystack.l_mark[0].IST.tree);}
break;
case 68:
#line 275 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL);}
break;
case 69:
#line 276 "src/part3bin.y"
	{yyval.IST.tree=mknode( yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,NULL),yystack.l_mark[0].IST.tree);}
break;
case 70:
#line 277 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,yystack.l_mark[0].IST.tree,NULL);}
break;
case 71:
#line 289 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 72:
#line 290 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 73:
#line 291 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 74:
#line 292 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 75:
#line 293 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 76:
#line 294 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 77:
#line 296 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 78:
#line 297 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 79:
#line 301 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL);}
break;
case 80:
#line 304 "src/part3bin.y"
	{yyval.IST.tree=mknode("|","|",yystack.l_mark[-1].IST.tree,mknode("|","|",NULL,NULL));}
break;
case 81:
#line 307 "src/part3bin.y"
	{yyval.IST.tree=mknode("|","|",yystack.l_mark[-1].IST.tree,mknode("|","|",NULL,NULL));}
break;
case 82:
#line 309 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 83:
#line 311 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 84:
#line 314 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 85:
#line 315 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 86:
#line 316 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 87:
#line 317 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 88:
#line 318 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 89:
#line 319 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 90:
#line 320 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 91:
#line 335 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 92:
#line 336 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 93:
#line 338 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 94:
#line 339 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 95:
#line 341 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[-1].IST.tree;}
break;
case 96:
#line 342 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL);}
break;
case 97:
#line 343 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 98:
#line 347 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 99:
#line 348 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 100:
#line 349 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 101:
#line 350 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 102:
#line 351 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-3].IST.tree, mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 103:
#line 352 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 104:
#line 353 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 105:
#line 355 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree), yystack.l_mark[0].IST.tree);}
break;
case 106:
#line 356 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL, NULL));}
break;
case 107:
#line 357 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, NULL, NULL),yystack.l_mark[0].IST.tree);}
break;
case 108:
#line 367 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, mknode("[]","[]", yystack.l_mark[-4].IST.tree, yystack.l_mark[-3].IST.tree),mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 109:
#line 368 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type, mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree),yystack.l_mark[0].IST.tree);}
break;
case 110:
#line 369 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, yystack.l_mark[-3].IST.tree,mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 111:
#line 370 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type, mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree),mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL, NULL));}
break;
case 112:
#line 371 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type, NULL, NULL), mknode("[]","[]" ,yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 113:
#line 372 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 114:
#line 373 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,NULL,NULL),mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL));}
break;
case 115:
#line 374 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,NULL,NULL),yystack.l_mark[0].IST.tree);}
break;
case 116:
#line 375 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL));}
break;
case 117:
#line 376 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 118:
#line 377 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL),NULL);}
break;
case 119:
#line 383 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 120:
#line 384 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 121:
#line 385 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL,NULL),NULL);}
break;
case 122:
#line 386 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 123:
#line 387 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL),NULL);}
break;
case 124:
#line 388 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-5].IST.string,yystack.l_mark[-5].IST.type,mknode(yystack.l_mark[-4].IST.string,yystack.l_mark[-4].IST.type,yystack.l_mark[-2].IST.tree,NULL),NULL);}
break;
case 125:
#line 389 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL,NULL),NULL);}
break;
case 126:
#line 391 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL,NULL);}
break;
case 127:
#line 392 "src/part3bin.y"
	{yyval.IST.tree=mknode("","",NULL,NULL);}
break;
case 128:
#line 401 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 129:
#line 402 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 130:
#line 405 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-10].IST.string,yystack.l_mark[-10].IST.type,yystack.l_mark[-8].IST.tree,yystack.l_mark[-5].IST.tree),mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,yystack.l_mark[-1].IST.tree,NULL));
}
break;
case 131:
#line 409 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-10].IST.string,yystack.l_mark[-10].IST.type,yystack.l_mark[-8].IST.tree,yystack.l_mark[-5].IST.tree),mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,yystack.l_mark[-1].IST.tree,NULL));
}
break;
case 132:
#line 413 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree),NULL);
}
break;
case 133:
#line 417 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree),NULL);
}
break;
case 134:
#line 423 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,  yystack.l_mark[-4].IST.tree,  yystack.l_mark[-1].IST.tree   );  }
break;
case 135:
#line 426 "src/part3bin.y"
	{yyval.IST.tree=mknode("for-COND","COND",yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree);}
break;
case 136:
#line 427 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,yystack.l_mark[-1].IST.tree, NULL);}
break;
case 137:
#line 428 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree, yystack.l_mark[0].IST.tree);}
break;
case 138:
#line 429 "src/part3bin.y"
	{}
break;
case 139:
#line 430 "src/part3bin.y"
	{}
break;
case 140:
#line 433 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[-1].IST.tree;}
break;
#line 3775 "bin/y.tab.c"
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
