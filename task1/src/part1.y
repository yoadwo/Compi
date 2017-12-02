%{
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
%}
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR, ID, VOID
%token IF, ELSE, WHILE, FOR ,DO
%token MAIN,  RETURN
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER_POS, INTEGER_NEG, CHAR_CONST, STRING_CONST, HEX_CONST, OCTAL_CONST, BINARY_CONST
%token ASSIGNMENT,AND,DIVISION,EQUAL,GREATER,GREATEREQUAL,LESS,LESSEQUAL,MINUS,NOT,NOTEQUAL,OR,PLUS,MULTI,ADDRESS,DEREFERENCE,ABSUOLUTE,SEMICOLON,COLON,COMMA,LEFTBRACE,RIGHTBRACE,LEFTPAREN,RIGHTPAREN,LEFTBRACKET,RIGHTBRACKET,PERCENT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGNMENT NOT SEMICOLON 
%left LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN
%left EQUAL GREATER GREATEREQUAL LESSEQUAL LESS NOTEQUAL
%left PLUS MINUS AND OR
%left MULTI DIVISION
%start s
%%
s:      global {printf ("ok\n");   printtree ($1,0); };
global:  procsBeforeMain procMain {$$ = mknode ("global", $1,NULL, $2); };

procsBeforeMain:  
                  procsBeforeMain proc {$$ = mknode ("", $1,NULL, $2); }
                | proc   {$$ = mknode ("", $1, NULL,NULL); };
            

proc:  procValue | procVoid;
procMain: VOID MAIN LEFTPAREN RIGHTPAREN block_statements {$$ = mknode ("main", $5,NULL, NULL); };
procVoid: VOID id LEFTPAREN params RIGHTPAREN  block_statements {$$ = mknode ("procedure", $2, $4, $6); };
procValue: procID LEFTPAREN params RIGHTPAREN  block_return_statements {$$ = mknode ("procedure", $1, $3, $5); };
procID: varType id {$$ = mknode ("procID", $1, $2, NULL); };
params: /* no params  */
        | paramsDeclare {$$ = mknode ("params:", $1, NULL, NULL); };
paramsDeclare: param COMMA  paramsDeclare  {$$ = mknode ("", $1, NULL, $3); }   
        | param ;
/* to change tree design\print, toggle between following: 1) [type id] 2) [][type][id] */
/*param: varType id {char *s = " "; s=  strcat ($1->token,s);  $$ = mknode (strcat($1->token,$2->token), NULL, NULL, NULL); }   ;*/
param: varType id {$$ = mknode ("", $1, NULL, $2); }   ;
        
        
newline:  
        statement newline   {$$ = mknode ("", $1, NULL,$2); }
           | statement;
                                  
expr:     expr PLUS expr    {$$ = mknode ("+", $1, NULL, $3); }
        | expr MINUS expr {$$ = mknode ("-", $1, NULL, $3); }
        | expr MULTI expr {$$ = mknode ("*", $1, NULL, $3); }
        | expr DIVISION expr  {$$ = mknode ("/", $1, NULL, $3); }
        | expr EQUAL expr  { $$ = mknode ("==", $1, NULL, $3); }
        | expr GREATER expr  { $$ = mknode (">", $1, NULL, $3); }
        | expr GREATEREQUAL expr { $$ = mknode (">=", $1, NULL, $3); }
        | expr LESS expr { $$ = mknode ("<", $1, NULL, $3); }
        | expr LESSEQUAL expr { $$ = mknode ("<=", $1, NULL, $3); }
        | expr NOTEQUAL expr { $$ = mknode ("!=", $1, NULL, $3); }
        | expr AND expr {$$ = mknode ("&&", $1, NULL, $3); }
        | expr OR expr {$$ = mknode ("||", $1, NULL, $3); }
        | NOT expr {$$ = mknode ("NOT", NULL, NULL, $2); }
        | Pexpr
        | consts 
        /*| ASSIGNMENT_statement*/;

Pexpr:  LEFTPAREN expr rightParen {$$ = mknode ("(", $2, NULL, $3); };
rightParen: RIGHTPAREN {$$ = mknode (")", NULL, NULL, NULL); };
block_return_statements: LEFTBRACE newline RETURN expr SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $2, $4, $6); }
            | LEFTBRACE RETURN expr SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $3, NULL, $5); };


block_statements: emptyBlock
            | LEFTBRACE newline rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $3); };
            
emptyBlock: LEFTBRACE rightbrace {$$ = mknode ("(BLOCK", $2, NULL, NULL); };   
=======
block_statements: LEFTBRACE newline rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $3); };   
>>>>>>> Stashed changes
rightbrace: RIGHTBRACE  {$$ = mknode (")", NULL, NULL,NULL ); };
consts: id | numbers    ;
id:   ID            {$$ = mknode (yytext, NULL, NULL, NULL); }  ;
numbers: INTEGER_NEG {$$ = mknode (yytext, NULL, NULL, NULL); } 
            | INTEGER_POS  { $$ = mknode (yytext, NULL, NULL, NULL); };

             
statement: IF_statements 
            | LOOP_statements  
           /* | IN.OUT_statements*/
            | BOOLEAN_statements
<<<<<<< Updated upstream
            | variable_declare_statements
            | /*expr */SEMICOLON; //no integer can be declared with type first
=======
            | expr SEMICOLON;
            
>>>>>>> Stashed changes

statements_type: statement
                 |block_statements;
                    
IF_statements: IF cond statements_type {$$ = mknode ("IF", $2,$3,NULL); } %prec LOWER_THAN_ELSE
             | IF cond statements_type else{$$ = mknode ("IF", $2,$3, $4); };
               
else:    ELSE statements_type{$$ = mknode ("ELSE", $2,NULL, NULL); };

LOOP_statements: WHILE cond statements_type {$$=mknode("while", $2,$3, NULL);} 
                 | FOR cond statements_type{$$=mknode("for", $2,$3, NULL);}
                 | DO statements_type WHILE cond  {$$=mknode("do-while", $2,NULL, $4);};
                 
/*cond:expr;*/
cond: LEFTPAREN expr rightParen {$$ = mknode ("(COND", $2, NULL, $3); };
                 
BOOLEAN_statements: BOOLTRUE {$$ = mknode ("true", NULL,NULL, NULL); } 
                    | BOOLFALSE {$$ = mknode ("false", NULL, NULL, NULL); }; 
                 
/*IN.OUT_statements:;*/
ASSIGNMENT_statement: id ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); };

variable_declare_statements: varType variablesDeclare /*SEMICOLON*/ {$$ = mknode ("DECLARE", $1, NULL, $2); };
/*
procType: VOID      {$$ = mknode ("void", NULL, NULL, NULL); }
            | varType;*/
varType: BOOL        {$$ = mknode ("boolean", NULL, NULL, NULL); }
            | CHAR          {$$ = mknode ("char", NULL, NULL, NULL); }
            | INT              {$$ = mknode ("integer", NULL, NULL, NULL); }
            | STRING       {$$ = mknode ("string", NULL, NULL, NULL); }
            | INTPTR        {$$ = mknode ("intptr", NULL, NULL, NULL); }
            | CHARPTR    {$$ = mknode ("charptr", NULL, NULL, NULL); };

variablesDeclare: id COMMA variablesDeclare    {$$ = mknode ("", $1, NULL, $3); }
            |  ASSIGNMENT_statement COMMA  variablesDeclare   {$$ = mknode ("", $1, NULL, $3); }
            | ASSIGNMENT_statement 
            | id;
            
%%

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
