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
#define MAIN 268
#define PROCEDURE 269
#define RETURN 270
#define BOOLTRUE 271
#define BOOLFALSE 272
#define CSNULL 273
#define INTEGER_POS 274
#define INTEGER_NEG 275
#define CHAR_CONST 276
#define STRING_CONST 277
#define HEX_CONST 278
#define OCTAL_CONST 279
#define BINARY_CONST 280
#define ASSIGNMENT 281
#define AND 282
#define DIVISION 283
#define EQUAL 284
#define GREATER 285
#define GREATEREQUAL 286
#define LESS 287
#define LESSEQUAL 288
#define MINUS 289
#define NOT 290
#define NOTEQUAL 291
#define OR 292
#define PLUS 293
#define MULTI 294
#define ADDRESS 295
#define DEREFERENCE 296
#define ABSUOLUTE 297
#define SEMICOLON 298
#define COLON 299
#define COMMA 300
#define LEFTBRACE 301
#define RIGHTBRACE 302
#define LEFTPAREN 303
#define RIGHTPAREN 304
#define LEFTBRACKET 305
#define RIGHTBRACKET 306
#define PERCENT 307
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,
    5,    4,    7,    8,    6,    6,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    2,    2,   13,   13,    9,
    9,   10,   10,   11,   12,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    3,    3,    3,    3,    1,    1,    1,
    1,    3,    1,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    0,    3,
};
static const YYINT yydefred[] = {                         0,
   11,   30,   31,   32,   33,   28,   29,   16,   15,   13,
    0,    0,    2,    3,    8,    0,   10,    0,   23,   24,
   25,   26,   27,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    9,    7,    0,    0,    0,
    0,    0,    0,    0,    0,    6,    0,   14,   12,
};
static const YYINT yydgoto[] = {                         11,
   12,   13,   14,   15,   36,   17,   18,   49,   19,   20,
   21,   22,   23,
};
static const YYINT yysindex[] = {                      -259,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -253,    0,    0,    0, -281,    0, -254,    0,    0,
    0,    0,    0, -254, -254, -254, -254, -254, -254, -254,
 -254, -254, -254, -254, -265,    0,    0, -246, -246, -246,
 -246, -246, -280, -246, -280,    0, -246,    0,    0,
};
static const YYINT yyrindex[] = {                         2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   10,    0,    0,    0,   23,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   17,   19,   22,
   25,   26,    1,   42,   11,    0,   46,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   27,    0,    0,    0,   50,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 317
static const YYINT yytable[] = {                         34,
    5,   34,   24,    1,    2,    3,    4,    5,    1,    1,
    4,    6,    7,   33,    8,    9,   17,   24,   18,    8,
    9,   19,    9,   30,   20,   21,    0,   32,   33,   24,
   25,   26,   27,   28,   29,   30,   24,   31,   48,   32,
   33,   22,   30,   10,   35,   35,   32,   33,   10,   16,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    5,    5,    5,    5,    5,
    0,    5,    0,    5,    4,    4,    4,    4,    4,    4,
    0,    4,    0,    4,    5,    9,    9,    9,    9,    9,
    9,    9,    0,    9,    4,    9,    9,
};
static const YYINT yycheck[] = {                        281,
    0,    0,  283,  263,  264,  265,  266,  267,  263,    0,
    0,  271,  272,  294,  274,  275,    0,  283,    0,  274,
  275,    0,    0,  289,    0,    0,   -1,  293,  294,  283,
  284,  285,  286,  287,  288,  289,  283,  291,  304,  293,
  294,    0,  289,  303,   18,    0,  293,  294,  303,    0,
   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
   34,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
   -1,  291,   -1,  293,  284,  285,  286,  287,  288,  289,
   -1,  291,   -1,  293,  304,  283,  284,  285,  286,  287,
  288,  289,   -1,  291,  304,  293,  294,
};
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 323
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
"INTPTR","CHARPTR","ID","IF","ELSE","WHILE","FOR","MAIN","PROCEDURE","RETURN",
"BOOLTRUE","BOOLFALSE","CSNULL","INTEGER_POS","INTEGER_NEG","CHAR_CONST",
"STRING_CONST","HEX_CONST","OCTAL_CONST","BINARY_CONST","ASSIGNMENT","AND",
"DIVISION","EQUAL","GREATER","GREATEREQUAL","LESS","LESSEQUAL","MINUS","NOT",
"NOTEQUAL","OR","PLUS","MULTI","ADDRESS","DEREFERENCE","ABSUOLUTE","SEMICOLON",
"COLON","COMMA","LEFTBRACE","RIGHTBRACE","LEFTPAREN","RIGHTPAREN","LEFTBRACKET",
"RIGHTBRACKET","PERCENT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : s",
"s : expr",
"s : statements",
"s : bool_expr",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MULTI expr",
"expr : expr DIVISION expr",
"expr : Pexpr",
"expr : id",
"expr : numbers",
"id : ID",
"Pexpr : leftParen expr rightParen",
"leftParen : LEFTPAREN",
"rightParen : RIGHTPAREN",
"numbers : INTEGER_NEG",
"numbers : INTEGER_POS",
"bool_expr : expr EQUAL expr",
"bool_expr : expr GREATER expr",
"bool_expr : expr GREATEREQUAL expr",
"bool_expr : expr LESS expr",
"bool_expr : expr LESSEQUAL expr",
"bool_expr : expr NOTEQUAL expr",
"statements : IF_statements",
"statements : LOOP_statements",
"statements : IN.OUT_statements",
"statements : ASSIGNMENT_statements",
"statements : BOOLEAN_statements",
"BOOLEAN_statements : BOOLTRUE",
"BOOLEAN_statements : BOOLFALSE",
"IF_statements : IF",
"IF_statements : ELSE",
"LOOP_statements : WHILE",
"LOOP_statements : FOR",
"IN.OUT_statements :",
"ASSIGNMENT_statements : id ASSIGNMENT expr",

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
#line 67 "src/part1.y"

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
#line 372 "bin/y.tab.c"

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
#line 30 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 2:
#line 31 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 3:
#line 32 "src/part1.y"
	{printf ("ok\n");   printtree (yystack.l_mark[0],0); }
break;
case 4:
#line 33 "src/part1.y"
	{yyval = mknode ("+", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 5:
#line 34 "src/part1.y"
	{yyval = mknode ("-", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 6:
#line 35 "src/part1.y"
	{yyval = mknode ("*", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 7:
#line 36 "src/part1.y"
	{yyval = mknode ("/", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 11:
#line 40 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 12:
#line 41 "src/part1.y"
	{yyval = mknode ("PARENTHESES", yystack.l_mark[-2], yystack.l_mark[-1], yystack.l_mark[0]); }
break;
case 13:
#line 42 "src/part1.y"
	{yyval = mknode ("(", NULL, NULL, NULL); }
break;
case 14:
#line 43 "src/part1.y"
	{yyval = mknode (")", NULL, NULL, NULL); }
break;
case 15:
#line 44 "src/part1.y"
	{yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 16:
#line 45 "src/part1.y"
	{ yyval = mknode (yytext, NULL, NULL, NULL); }
break;
case 17:
#line 47 "src/part1.y"
	{ yyval = mknode ("==", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 18:
#line 48 "src/part1.y"
	{ yyval = mknode (">", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 19:
#line 49 "src/part1.y"
	{ yyval = mknode (">=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 20:
#line 50 "src/part1.y"
	{ yyval = mknode ("<", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 21:
#line 51 "src/part1.y"
	{ yyval = mknode ("<=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 22:
#line 52 "src/part1.y"
	{ yyval = mknode ("!=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
case 28:
#line 60 "src/part1.y"
	{yyval = mknode ("true", NULL,NULL, NULL); }
break;
case 29:
#line 61 "src/part1.y"
	{yyval = mknode ("false", NULL, NULL, NULL); }
break;
case 35:
#line 65 "src/part1.y"
	{yyval = mknode ("=", yystack.l_mark[-2], NULL, yystack.l_mark[0]); }
break;
#line 662 "bin/y.tab.c"
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
