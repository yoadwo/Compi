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
#define ROWS 18
#define COLS 4
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
static symbolTable * procedureParas; /*orel*/
static labelStruct * labelHead;
static char * currentReturnType;
char * freshLabel();
void ConditionTreatment(node * condition);/*orel*/
void SwapSides(node * condition);/*orel*/
void MakeIfIntoIfZ(node * condition,char * nextLabel, char * elseLabel);/*orel*/
void InsertLabelsIntoCondition(node * condition,char * thenLabel,char * nextLabel, char * elseLabel);/*orel*/
int ThereisAND(node * condition);/*orel*/
void _3ACForAssignment(node * tree);/*ohad ariel*/
void _3ACMain(node * tree); /*ariel*/
void TAC_PrintCode(node * tree); /*ariel*/
void TAC_FillCode(node * tree); /*orel*/
char * _3ACForOperations(node * tree);
int _3ACForProcedureParameters(node * tree);
char* _3ACForProcedureActivate(node * tree);
void _3ACForProcedureDefine(node * tree);
void _3ACForReturn(node * tree); /* michael*/
int numberOfBytes (char *type); /* michael*/
void _3ACForVar(node * tree); /* michael*/
int countNumberOfParameters(node *tree); /* michael*/
void deleteNameOfParameters(int numberOfParametersToDelete); /* michael*/
char* _3ACString(node* tree);
void recursivePrint(node* tree);
void checkIfConditionTypeIsBoolean(node *cond); /* michael*/
void printFixedCode();
void buildLabelStruct();
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
#define INTPTR 262
#define CHARPTR 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define VAR 267
#define ASSIGN 268
#define EQ 269
#define GT 270
#define GE 271
#define LT 272
#define LE 273
#define NE 274
#define NOT 275
#define MINUS 276
#define PLUS 277
#define MUL 278
#define DIVISION 279
#define ADDRESS 280
#define VAL_POINTER 281
#define AMPERSAND 282
#define VALUE_ADDRESS 283
#define ARRAY 284
#define PROCEDURE 285
#define RETURN 286
#define NIL 287
#define AND 288
#define OR 289
#define VBAR 290
#define CHAR_CONST 291
#define BINARY 292
#define OCTAL 293
#define INTEGER_CONST 294
#define STRING_CONST 295
#define SEMICOLON 296
#define COLON 297
#define SEPERATOR 298
#define START_BLOCK_OF_CODE 299
#define END_BLOCK_OF_CODE 300
#define BEGIN_PARAMETER_LIST 301
#define END_PARAMETER_LIST 302
#define BEGIN_STRING_INDEX 303
#define END_STRING_INDEX 304
#define IDENTIFIER 305
#define HEXADECIMAL 306
#define ERR 307
#define EQUAL 308
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    4,    5,    5,    5,    5,    5,
    5,    5,    3,   12,   12,   12,   14,   14,   15,   15,
   15,   15,   15,   15,   16,   16,   17,   18,   18,   18,
   18,   19,   19,   19,   20,   20,   20,   21,   21,   21,
   21,   21,   24,   25,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,   29,   29,    7,   31,   31,
   32,   32,   32,   32,   32,   32,   26,   26,   11,   22,
   23,   27,   27,   33,   33,   33,   33,   33,   33,   33,
   30,   30,   34,   34,   35,   35,   35,   36,   36,   36,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   36,   36,   36,   36,   36,   36,   36,   36,    6,    6,
    6,    6,    6,    6,    6,   13,    9,    9,   10,   10,
   10,   10,   28,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    3,    4,    2,    2,    2,    2,    2,
    4,    0,    5,    2,    4,    0,    3,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    1,    1,    1,
    1,    3,    3,    1,    3,    3,    1,    3,    1,    1,
    1,    1,    2,    2,    4,    4,    7,    4,    5,    5,
    4,    4,    4,    4,    4,    1,    1,    5,    3,    1,
    3,    3,    3,    1,    1,    1,    1,    0,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    1,    3,    1,    3,    1,    1,    3,    3,    3,
    3,    4,    3,    3,    4,    3,    3,    5,    4,    4,
    4,    4,    3,    3,    3,    3,    2,    2,    3,    3,
    3,    3,    4,    6,    3,    2,    7,    7,   11,   11,
    7,    7,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    1,    0,   69,    0,    0,    2,    0,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   29,   30,   28,    0,   31,   39,   40,    0,    0,
   37,   41,   42,    0,    8,    0,    0,    6,    7,    9,
   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   72,   73,    0,
    0,    0,    0,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,   20,   21,    0,
   25,   26,   18,   23,   24,    0,    0,    0,   13,   74,
   75,   76,   77,   78,   79,   80,    0,  108,  107,   43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   59,    0,   71,   70,   38,    0,
    0,   35,   36,   11,  111,    0,  115,    0,  109,  112,
  110,   54,    0,   45,   46,    0,   51,   48,   55,  123,
   57,   56,    0,   53,   52,    0,   17,   15,  116,  104,
    0,    0,   97,   85,    0,    0,  106,    0,    0,   90,
  103,   94,   93,   96,    0,    0,   89,    0,   81,   83,
    0,    0,   58,  113,    0,    0,    0,    0,   67,    0,
   50,   49,    0,  102,    0,  101,    0,    0,   95,  100,
   92,    0,    0,    0,    0,    0,    0,    0,    0,   27,
    0,   98,    0,  117,  118,   63,   61,  114,   62,   47,
    0,    0,    0,    0,    0,    0,  119,  120,
};
static const YYINT yydgoto[] = {                          2,
    3,   17,    6,   10,   18,   47,   19,   20,   21,   22,
   37,   26,  119,   58,  113,  114,  115,   38,  206,   40,
   41,   42,   43,   67,   24,  207,  208,  136,  173,   69,
   30,  209,  137,   70,   71,   72,
};
static const YYINT yysindex[] = {                      -256,
 -274,    0,    0, -256,    0, -251, -243,    0, -166,    0,
 -237, -204, -183, -219,  288, -166, -166, -165, -166, -166,
 -166, -166, -236, -142,  -99, -179,  -43,  -43, -164, -153,
  265,    0,    0,    0,  288,    0,    0,    0,  -71,  -68,
    0,    0,    0, -127,    0,  -70, -125,    0,    0,    0,
    0, -129,  288,  -90,  271,  172, -123, -116,  -79,  346,
 -255, -274,  346,  -43,  -84,  337,  346,  346, -106,  -75,
  -72,    0,  -57,  -65, -219,  172,  -60, -200, -240,  288,
  288,  288,  288, -166,  -62,  288,  -41,    0,    0,  -45,
 -161,  -39,  -37,    0,  -36,  346, -289,  209,  168, -231,
  -35,  -32, -252, -112,  -13, -149,    0,    0,    0,  -31,
    0,    0,    0,    0,    0,  -99, -237,  172,    0,    0,
    0,    0,    0,    0,    0,    0,   -6,    0,    0,    0,
 -227,  -21,  186,  -23,  -10,  346, -199, -248,  231,   -8,
  -43,  -43,    4,    5,    0,  -11,    0,    0,    0,  -68,
  -68,    0,    0,    0,    0, -145,    0,  -25,    0,    0,
    0,    0,  -25,    0,    0,    9,    0,    0,    0,    0,
    0,    0,   17,    0,    0,   14,    0,    0,    0,    0,
  -71,  -21,    0,    0, -166,  248,    0,  -21,  -71,    0,
    0,    0,    0,    0,  -21,  -71,    0, -166,    0,    0,
 -166, -166,    0,    0,   16, -188,   -4,   31,    0,   28,
    0,    0,   27,    0,   34,    0,  -21,  -71,    0,    0,
    0,   36,   42,   43,  -25,  -25,   48,  -25,   52,    0,
   84,    0,   85,    0,    0,    0,    0,    0,    0,    0,
   53,   67, -166, -166,   68,   69,    0,    0,
};
static const YYINT yyrindex[] = {                       367,
    0,    0,    0,  367,    0,    0,    0,    0,   87,    0,
   75,    0,    0,    0,    0,   70, -144,    0, -144, -144,
 -144, -144,    0,    0,    0,    0,    0,    0,   74,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  134,   49,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   77,    0,  -94,
    0,    0,    0,    0,  326,    0,    0,    0,    0, -197,
 -215,    0,  326,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -144,    0,    0,    0,    0,    0,  -87,
    0,    0,    0,    0,    0,   89,  220,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -58,
    0,    0,    0,    0,    0,    0,   75,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  175,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   86,
  123,    0,    0,    0,    0,    0,    0,   78,    0,    0,
    0,    0,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   13,    0,    0,    0,   70,    0,    0,  224,   39,    0,
    0,    0,    0,    0,  224,   44,    0,   70,    0,    0,
   70,   70,    0,    0,   79,   81,    0,   99,    0,    0,
    0,    0,    0,    0,    0,    0,  224,   76,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7,    0,   11,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   70,   70,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  382,  167,    0,    0,  -15,    0,    0,    0,    0,    0,
   -1,  270,    0,  273,  -63,    0,    0,    0,   18,  146,
  171,    0,    0,  -29,  -17,  247,  -24,  -14,    0,    2,
  339,  -76,   12,  274,    0,    0,
};
#define YYTABLESIZE 621
static const YYINT yytable[] = {                          7,
   44,   45,  128,   48,   49,   50,   51,   23,   54,   68,
   68,  163,  146,   53,   23,   23,   92,   23,   23,   23,
   23,   93,   99,   80,   81,   65,   73,  101,    1,   74,
    5,   52,   39,   62,  100,   80,   81,  120,  121,  122,
  123,  124,  125,  126,   66,   66,   68,    9,   78,    5,
   97,  170,   79,  102,  179,   15,    5,   11,  187,  129,
  130,  149,  132,   91,  167,  134,   53,   25,  154,   98,
  103,  127,  106,   84,  131,   80,   81,    5,  138,  139,
   84,  133,   23,   15,  166,   29,   84,   80,   81,  148,
   31,   88,   32,   33,   34,   89,   27,   12,   82,   13,
   14,   35,  172,  156,   82,    5,   36,  131,  193,  226,
  138,  139,  191,  183,   80,   81,   15,   28,    1,  190,
   46,  197,   59,   68,   68,   55,   80,   81,   60,  182,
   80,   81,   16,   75,  159,  188,  192,  195,    5,  132,
  132,   12,  199,   76,  181,   61,  175,  186,  236,  237,
  204,  239,   62,   15,  189,   12,  196,   95,   66,   66,
   31,   96,   32,   33,   34,   89,    4,  214,  219,  215,
    4,   64,   84,  220,   94,    5,   36,  104,  171,  117,
  221,  116,  222,   23,  217,  223,  224,   85,   69,   69,
   69,   69,    5,   86,   86,  140,   23,   56,   57,   23,
   23,   86,  232,  218,   80,   81,  118,   86,   69,   82,
   83,   62,   86,  141,   60,  142,   87,  135,   53,   31,
   88,   32,   33,   34,   89,  150,  151,  245,  246,  147,
   35,   61,  205,  155,   90,   36,  144,   22,   62,   15,
   22,   23,   23,   22,  143,   53,   31,   63,   32,   33,
   34,  180,  152,  153,  157,  158,  160,   64,  161,  162,
  168,    5,   36,  169,   31,   88,   32,   33,   34,   89,
  121,  176,  121,  121,  122,   35,  122,  122,  184,    5,
   36,   53,  174,   31,  203,   32,   33,   34,  185,  121,
  198,  121,  121,  122,   35,  122,  122,  227,    5,   36,
  105,  105,  201,  202,  211,  121,  121,  213,  105,  122,
  122,  121,  212,  225,  105,  122,   34,   34,   34,   34,
   34,   34,   34,   34,   34,   34,   88,   88,  228,  229,
  230,   91,   91,  231,   88,  233,   34,   34,   34,   91,
   88,  234,  235,  238,   34,   91,   34,  240,  241,  242,
   34,  243,   34,   33,   33,   33,   33,   33,   33,   33,
   33,   33,   33,   99,   99,  244,    3,  247,  248,   12,
   60,   99,   12,   33,   33,   33,   16,   99,   14,   68,
   66,   33,   64,   33,   72,    8,  178,   33,  177,   33,
   32,   32,   32,   32,   32,   32,   32,   32,   32,   32,
   65,   44,   44,   44,   44,   44,   44,   44,   44,  210,
   32,   32,   32,  145,    0,  200,    0,    0,   32,    0,
   32,   44,   44,    0,   32,    0,   32,    0,  107,   44,
  108,  109,  110,  111,  112,   44,  120,  121,  122,  123,
  124,  125,  126,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,  120,  121,  122,  123,  124,  125,
  126,   80,   81,  165,    0,    0,    0,    0,    0,    0,
   53,    0,    0,    0,    0,    0,   39,  120,  121,  122,
  123,  124,  125,  126,   80,   81,    0,  149,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,    0,  164,    0,    0,    0,    0,    0,
    0,   39,   39,   15,    0,   39,    0,    0,    0,   39,
   31,  194,   32,   33,   34,   39,    0,    0,    0,    0,
   15,   35,    0,    0,    0,    5,   36,   31,  216,   32,
   33,   34,    0,    0,    0,    0,    0,    0,   35,    0,
    0,    0,    5,   36,   31,    0,   32,   33,   34,   77,
   31,  105,   32,   33,   34,   35,    0,    0,    0,    5,
   36,   35,    0,    0,    0,    5,   36,   31,    0,   32,
   33,   34,    0,    0,    0,    0,    0,    0,   35,    0,
    0,    0,    5,   36,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,  120,  121,  122,  123,  124,
  125,  126,   80,   81,  120,  121,  122,  123,  124,  125,
  126,
};
static const YYINT yycheck[] = {                          1,
   16,   17,  258,   19,   20,   21,   22,    9,   23,   27,
   28,  301,   76,  303,   16,   17,   46,   19,   20,   21,
   22,   46,   52,  276,  277,   27,   28,   52,  285,   28,
  305,  268,   15,  282,   52,  276,  277,  269,  270,  271,
  272,  273,  274,  275,   27,   28,   64,  299,   31,  305,
   52,  304,   35,   52,  118,  283,  305,  301,  258,   61,
   62,  302,   64,   46,  296,   64,  303,  305,   84,   52,
   53,   60,   55,  289,   63,  276,  277,  305,   67,   68,
  296,   64,   84,  283,   99,  305,  302,  276,  277,  290,
  290,  291,  292,  293,  294,  295,  301,  264,  296,  266,
  267,  301,  104,   86,  302,  305,  306,   96,  138,  298,
   99,  100,  137,  131,  276,  277,  283,  301,  285,  137,
  286,  139,  302,  141,  142,  268,  276,  277,  258,  131,
  276,  277,  299,  298,  296,  137,  138,  139,  305,  141,
  142,  286,  141,  297,  127,  275,  296,  136,  225,  226,
  296,  228,  282,  283,  137,  300,  139,  287,  141,  142,
  290,  291,  292,  293,  294,  295,    0,  182,  186,  185,
    4,  301,  300,  188,  300,  305,  306,  268,  291,  296,
  195,  305,  198,  185,  186,  201,  202,  258,  276,  277,
  278,  279,  305,  288,  289,  302,  198,  297,  298,  201,
  202,  296,  217,  186,  276,  277,  286,  302,  296,  278,
  279,  282,  283,  289,  258,  288,  287,  302,  303,  290,
  291,  292,  293,  294,  295,   80,   81,  243,  244,  290,
  301,  275,  258,  296,  305,  306,  302,  296,  282,  283,
  299,  243,  244,  302,  302,  303,  290,  291,  292,  293,
  294,  258,   82,   83,  296,  301,  296,  301,  296,  296,
  296,  305,  306,  296,  290,  291,  292,  293,  294,  295,
  264,  303,  266,  267,  264,  301,  266,  267,  302,  305,
  306,  303,  296,  290,  296,  292,  293,  294,  299,  283,
  299,  285,  286,  283,  301,  285,  286,  302,  305,  306,
  288,  289,  299,  299,  296,  299,  300,  294,  296,  299,
  300,  305,  296,  298,  302,  305,  268,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  288,  289,  298,  302,
  304,  288,  289,  300,  296,  300,  288,  289,  290,  296,
  302,  300,  300,  296,  296,  302,  298,  296,  265,  265,
  302,  299,  304,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  288,  289,  299,    0,  300,  300,  300,
  297,  296,  286,  288,  289,  290,  302,  302,  302,  302,
  302,  296,  302,  298,  296,    4,  117,  302,  116,  304,
  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  302,  268,  269,  270,  271,  272,  273,  274,  275,  163,
  288,  289,  290,   75,   -1,  142,   -1,   -1,  296,   -1,
  298,  288,  289,   -1,  302,   -1,  304,   -1,  257,  296,
  259,  260,  261,  262,  263,  302,  269,  270,  271,  272,
  273,  274,  275,  269,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  296,   -1,   -1,   -1,   -1,   -1,   -1,
  303,   -1,   -1,   -1,   -1,   -1,  302,  269,  270,  271,
  272,  273,  274,  275,  276,  277,   -1,  302,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  276,
  277,  278,  279,   -1,  296,   -1,   -1,   -1,   -1,   -1,
   -1,  288,  289,  283,   -1,  296,   -1,   -1,   -1,  296,
  290,  291,  292,  293,  294,  302,   -1,   -1,   -1,   -1,
  283,  301,   -1,   -1,   -1,  305,  306,  290,  291,  292,
  293,  294,   -1,   -1,   -1,   -1,   -1,   -1,  301,   -1,
   -1,   -1,  305,  306,  290,   -1,  292,  293,  294,  295,
  290,  291,  292,  293,  294,  301,   -1,   -1,   -1,  305,
  306,  301,   -1,   -1,   -1,  305,  306,  290,   -1,  292,
  293,  294,   -1,   -1,   -1,   -1,   -1,   -1,  301,   -1,
   -1,   -1,  305,  306,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  269,  270,  271,  272,  273,  274,
  275,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 347
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
"INTEGER","STRING","INTPTR","CHARPTR","IF","ELSE","WHILE","VAR","ASSIGN","EQ",
"GT","GE","LT","LE","NE","NOT","MINUS","PLUS","MUL","DIVISION","ADDRESS",
"VAL_POINTER","AMPERSAND","VALUE_ADDRESS","ARRAY","PROCEDURE","RETURN","NIL",
"AND","OR","VBAR","CHAR_CONST","BINARY","OCTAL","INTEGER_CONST","STRING_CONST",
"SEMICOLON","COLON","SEPERATOR","START_BLOCK_OF_CODE","END_BLOCK_OF_CODE",
"BEGIN_PARAMETER_LIST","END_PARAMETER_LIST","BEGIN_STRING_INDEX",
"END_STRING_INDEX","IDENTIFIER","HEXADECIMAL","ERR","EQUAL",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : S",
"S : Start",
"Start : Procedure Start",
"Start :",
"Procedure : PROCEDURE ProcedureSignature ProcedureBlock",
"ProcedureBlock : START_BLOCK_OF_CODE Block Return END_BLOCK_OF_CODE",
"Block : Define Block",
"Block : Assignment Block",
"Block : Procedure Block",
"Block : Loop Block",
"Block : If Block",
"Block : START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE Block",
"Block :",
"ProcedureSignature : ID BEGIN_PARAMETER_LIST Parameters END_PARAMETER_LIST ProcedureReturn",
"Parameters : IDENTIFIER SomeParameters",
"Parameters : IDENTIFIER SomeParameters SEMICOLON Parameters",
"Parameters :",
"SomeParameters : SEPERATOR IDENTIFIER SomeParameters",
"SomeParameters : COLON Types",
"Types : BOOLEAN",
"Types : CHAR",
"Types : INTEGER",
"Types : STRING",
"Types : PtrTypes",
"Types : ArrayType",
"PtrTypes : INTPTR",
"PtrTypes : CHARPTR",
"ArrayType : STRING BEGIN_STRING_INDEX INTEGER_CONST END_STRING_INDEX",
"CONST_INT : INTEGER_CONST",
"CONST_INT : BINARY",
"CONST_INT : OCTAL",
"CONST_INT : HEXADECIMAL",
"E : E PLUS T",
"E : E MINUS T",
"E : T",
"T : T MUL F",
"T : T DIVISION F",
"T : F",
"F : BEGIN_PARAMETER_LIST E END_PARAMETER_LIST",
"F : ID",
"F : CONST_INT",
"F : Absolute",
"F : StringLenth",
"AddressID : AMPERSAND ID",
"ValueAddressID : VALUE_ADDRESS E",
"Assignment : ID ASSIGN E SEMICOLON",
"Assignment : ID ASSIGN AddressID SEMICOLON",
"Assignment : ID ASSIGN ID BEGIN_PARAMETER_LIST EmptyOrPara END_PARAMETER_LIST SEMICOLON",
"Assignment : ID ASSIGN Consts SEMICOLON",
"Assignment : ID Array ASSIGN IndexedAssign SEMICOLON",
"Assignment : ID ASSIGN AddressID Array SEMICOLON",
"Assignment : ID ASSIGN ValueAddressID SEMICOLON",
"Assignment : ValueAddressID ASSIGN E SEMICOLON",
"Assignment : ValueAddressID ASSIGN CHAR_CONST SEMICOLON",
"Assignment : ID ASSIGN NIL SEMICOLON",
"Assignment : ID ASSIGN LogicOp SEMICOLON",
"IndexedAssign : ID",
"IndexedAssign : CHAR_CONST",
"Define : VAR IDents COLON Types SEMICOLON",
"IDents : IDENTIFIER SEPERATOR IDents",
"IDents : IDENTIFIER",
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
"ProcedureReturn : RETURN Types",
"Loop : WHILE BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"Loop : WHILE BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE ELSE START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE ELSE START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
"If : IF BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE",
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
#line 395 "src/part3bin.y"

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
void buildLabelStruct()//orel
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



void printFixedCode()//orel
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
		char thencode[2000]="";
		char whilecode[2000]="";
		node * condition=tree->left;//if(x>y) => condition= '>')
		notToEnterLeft=1;
		notToEnterRight=1;
		thenLabel=strdup(freshLabel());
		whileLabel=strdup(freshLabel());
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
	if (tree->left && !notToEnterLeft)
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
		tree = tree->right;
	}
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
	//printf("Name: %s, Type: %s, scope : %s \n",st->name,st->type,st->scope);
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
		if(strcmp(tree->right->token,"")==0)
		{
			whileblock=tree->right->left;
		}
		else
		{
			whileblock=tree->right;
		}
		if(!CheckID(whilecond))
		{
			printf("ID Not exists!\n");
			exit(1);
		}
		UpdateIDType(whilecond);
		buildST(whilecond);

		checkIfConditionTypeIsBoolean(whilecond); // michaell

		scopeCounter = scopeCounter + 1;  
		buildST(whileblock);
		scopeCounter = scopeCounter - 1; 
		current=curr;
		flagLeftSubTree = 1;
		flagRightSubTree = 1;
	}
	else if(strcmp(tree->token,"return")==0)
	{ 
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
	node * tempTree=tree;
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
		temp=temp->prevST;

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
#line 2799 "bin/y.tab.c"

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
buildLabelStruct(); printFixedCode();}
break;
case 2:
#line 151 "src/part3bin.y"
	{yyval.IST.tree=mknode("BLOCK","BLOCK",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 3:
#line 153 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 4:
#line 155 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 5:
#line 157 "src/part3bin.y"
	{yyval.IST.tree=mknode("","",yystack.l_mark[-2].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 6:
#line 159 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 7:
#line 160 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 8:
#line 161 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 9:
#line 162 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 10:
#line 163 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewRow","NewRow",yystack.l_mark[-1].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 11:
#line 165 "src/part3bin.y"
	{yyval.IST.tree=mknode("NewBlock","NewBlock",mknode("NewRow","NewRow",yystack.l_mark[-2].IST.tree, mknode("EndBlock","EndBlock",NULL,NULL)), yystack.l_mark[0].IST.tree);}
break;
case 12:
#line 166 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 13:
#line 168 "src/part3bin.y"
	{
char * e=strchr(yyval.IST.string,'_');
if(e!=NULL && (int)(e-yystack.l_mark[-4].IST.string)==0)
{
	yyerror("syntax error");
	YYERROR;
}
yyval.IST.tree=mknode(yystack.l_mark[-4].IST.string,"procedure",yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 14:
#line 177 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 15:
#line 178 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 16:
#line 179 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 17:
#line 181 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 18:
#line 182 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 19:
#line 184 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 20:
#line 185 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 21:
#line 186 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 22:
#line 187 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 23:
#line 188 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 24:
#line 189 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 25:
#line 191 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 26:
#line 192 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type ,NULL,NULL);}
break;
case 27:
#line 194 "src/part3bin.y"
	{yyval.IST.tree = mknode("string[]","string[]", mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL, NULL), NULL);}
break;
case 28:
#line 196 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 29:
#line 197 "src/part3bin.y"
	{yyval.IST.tree = mknode(binToDec(yystack.l_mark[0].IST.string),yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 30:
#line 198 "src/part3bin.y"
	{yyval.IST.tree = mknode(octalToDec(yystack.l_mark[0].IST.string),yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 31:
#line 199 "src/part3bin.y"
	{yyval.IST.tree = mknode(HexaToDec(yystack.l_mark[0].IST.string),yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 32:
#line 201 "src/part3bin.y"
	{yyval.IST.tree = mknode("+","+", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 33:
#line 202 "src/part3bin.y"
	{yyval.IST.tree = mknode("-","-", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 34:
#line 203 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 35:
#line 205 "src/part3bin.y"
	{yyval.IST.tree = mknode("*","*", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 36:
#line 206 "src/part3bin.y"
	{yyval.IST.tree = mknode("/","/", yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 37:
#line 207 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 38:
#line 209 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[-1].IST.tree;}
break;
case 39:
#line 210 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 40:
#line 210 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 41:
#line 211 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 42:
#line 212 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 43:
#line 219 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type , yystack.l_mark[0].IST.tree,NULL);}
break;
case 44:
#line 221 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type , yystack.l_mark[0].IST.tree,NULL);}
break;
case 45:
#line 224 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-3].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 46:
#line 225 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-3].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 47:
#line 226 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-6].IST.tree,mknode(yystack.l_mark[-4].IST.tree->token,yystack.l_mark[-4].IST.tree->type, yystack.l_mark[-2].IST.tree,NULL));
if(yyval.IST.tree->right->constType != NULL)
free(yyval.IST.tree->right->constType);
yyval.IST.tree->right->constType = strdup("procedure");
}
break;
case 48:
#line 232 "src/part3bin.y"
	{yyval.IST.tree=mknode("=","=",yystack.l_mark[-3].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 49:
#line 233 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=", mknode("[]","[]", yystack.l_mark[-4].IST.tree, yystack.l_mark[-3].IST.tree), yystack.l_mark[-1].IST.tree);}
break;
case 50:
#line 234 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-4].IST.tree, mknode("[]","[]", yystack.l_mark[-2].IST.tree, yystack.l_mark[-1].IST.tree));}
break;
case 51:
#line 235 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-3].IST.tree, yystack.l_mark[-1].IST.tree);}
break;
case 52:
#line 236 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-3].IST.tree, yystack.l_mark[-1].IST.tree);}
break;
case 53:
#line 237 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=",yystack.l_mark[-3].IST.tree, yystack.l_mark[-1].IST.tree);}
break;
case 54:
#line 239 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=" ,yystack.l_mark[-3].IST.tree, mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type , NULL,NULL));}
break;
case 55:
#line 240 "src/part3bin.y"
	{yyval.IST.tree = mknode("=","=" ,yystack.l_mark[-3].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 56:
#line 243 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 57:
#line 244 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL);}
break;
case 58:
#line 246 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-4].IST.string,yystack.l_mark[-4].IST.type ,yystack.l_mark[-3].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 59:
#line 249 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type ,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,NULL,NULL),yystack.l_mark[0].IST.tree);}
break;
case 60:
#line 250 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL);}
break;
case 61:
#line 263 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 62:
#line 264 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 63:
#line 265 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type ,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 64:
#line 266 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 65:
#line 267 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 66:
#line 268 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[0].IST.tree;}
break;
case 67:
#line 270 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 68:
#line 271 "src/part3bin.y"
	{yyval.IST.tree=NULL;}
break;
case 69:
#line 275 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type , NULL,NULL);}
break;
case 70:
#line 278 "src/part3bin.y"
	{yyval.IST.tree=mknode("|","|",yystack.l_mark[-1].IST.tree,mknode("|","|",NULL,NULL));}
break;
case 71:
#line 281 "src/part3bin.y"
	{yyval.IST.tree=mknode("|","|",yystack.l_mark[-1].IST.tree,mknode("|","|",NULL,NULL));}
break;
case 72:
#line 283 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 73:
#line 285 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL,NULL);}
break;
case 74:
#line 288 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 75:
#line 289 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 76:
#line 290 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 77:
#line 291 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 78:
#line 292 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 79:
#line 293 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 80:
#line 294 "src/part3bin.y"
	{yyval.IST.string=yystack.l_mark[0].IST.string; yyval.IST.type=yystack.l_mark[0].IST.type;}
break;
case 81:
#line 309 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 82:
#line 310 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 83:
#line 312 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 84:
#line 313 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 85:
#line 315 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[-1].IST.tree;}
break;
case 86:
#line 316 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL);}
break;
case 87:
#line 317 "src/part3bin.y"
	{yyval.IST.tree=yystack.l_mark[0].IST.tree;}
break;
case 88:
#line 321 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 89:
#line 322 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 90:
#line 323 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 91:
#line 324 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 92:
#line 325 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-3].IST.tree, mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 93:
#line 326 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 94:
#line 327 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 95:
#line 329 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree), yystack.l_mark[0].IST.tree);}
break;
case 96:
#line 330 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL, NULL));}
break;
case 97:
#line 331 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, NULL, NULL),yystack.l_mark[0].IST.tree);}
break;
case 98:
#line 341 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, mknode("[]","[]", yystack.l_mark[-4].IST.tree, yystack.l_mark[-3].IST.tree),mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 99:
#line 342 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type, mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree),yystack.l_mark[0].IST.tree);}
break;
case 100:
#line 343 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, yystack.l_mark[-3].IST.tree,mknode("[]","[]", yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 101:
#line 344 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type, mknode("[]","[]", yystack.l_mark[-3].IST.tree, yystack.l_mark[-2].IST.tree),mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type, NULL, NULL));}
break;
case 102:
#line 345 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type, mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type, NULL, NULL), mknode("[]","[]" ,yystack.l_mark[-1].IST.tree, yystack.l_mark[0].IST.tree));}
break;
case 103:
#line 346 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,yystack.l_mark[0].IST.tree);}
break;
case 104:
#line 347 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,NULL,NULL),mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL));}
break;
case 105:
#line 348 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,NULL,NULL),yystack.l_mark[0].IST.tree);}
break;
case 106:
#line 349 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[-2].IST.tree,mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL));}
break;
case 107:
#line 350 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 108:
#line 351 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,mknode(yystack.l_mark[0].IST.string,yystack.l_mark[0].IST.type,NULL,NULL),NULL);}
break;
case 109:
#line 356 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 110:
#line 357 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 111:
#line 358 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL,NULL),NULL);}
break;
case 112:
#line 359 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL);}
break;
case 113:
#line 360 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,yystack.l_mark[-1].IST.tree,NULL),NULL);}
break;
case 114:
#line 361 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-5].IST.string,yystack.l_mark[-5].IST.type,mknode(yystack.l_mark[-4].IST.string,yystack.l_mark[-4].IST.type,yystack.l_mark[-2].IST.tree,NULL),NULL);}
break;
case 115:
#line 362 "src/part3bin.y"
	{yyval.IST.tree = mknode(yystack.l_mark[-2].IST.string,yystack.l_mark[-2].IST.type,mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,NULL,NULL),NULL);}
break;
case 116:
#line 364 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-1].IST.string,yystack.l_mark[-1].IST.type,yystack.l_mark[0].IST.tree,NULL);}
break;
case 117:
#line 372 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 118:
#line 373 "src/part3bin.y"
	{yyval.IST.tree=mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree);}
break;
case 119:
#line 376 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-10].IST.string,yystack.l_mark[-10].IST.type,yystack.l_mark[-8].IST.tree,yystack.l_mark[-5].IST.tree),mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,yystack.l_mark[-1].IST.tree,NULL));
}
break;
case 120:
#line 380 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-10].IST.string,yystack.l_mark[-10].IST.type,yystack.l_mark[-8].IST.tree,yystack.l_mark[-5].IST.tree),mknode(yystack.l_mark[-3].IST.string,yystack.l_mark[-3].IST.type,yystack.l_mark[-1].IST.tree,NULL));
}
break;
case 121:
#line 384 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree),NULL);
}
break;
case 122:
#line 388 "src/part3bin.y"
	{
yyval.IST.tree=mknode("COND","COND",mknode(yystack.l_mark[-6].IST.string,yystack.l_mark[-6].IST.type,yystack.l_mark[-4].IST.tree,yystack.l_mark[-1].IST.tree),NULL);
}
break;
case 123:
#line 392 "src/part3bin.y"
	{yyval.IST.tree = yystack.l_mark[-1].IST.tree;}
break;
#line 3515 "bin/y.tab.c"
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
