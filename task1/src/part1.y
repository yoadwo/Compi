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
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR, ID, VOID,QUOTES,NADA
%token IF, ELSE, WHILE, FOR ,DO
%token MAIN,  RETURN
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER_POS, INTEGER_NEG, CHAR_CONST, STRING_CONST, HEX_CONST, OCTAL_CONST, BINARY_CONST 
%token ASSIGNMENT,AND,DIVISION,EQUAL,GREATER,GREATEREQUAL,LESS,LESSEQUAL,MINUS,NOT,NOTEQUAL,OR,PLUS,MULTI,ADDRESS,DEREFERENCE,ABSUOLUTE,SEMICOLON,COLON,COMMA,LEFTBRACE,RIGHTBRACE,LEFTPAREN,RIGHTPAREN,LEFTBRACKET,RIGHTBRACKET,PERCENT, QUOTES

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGNMENT NOT SEMICOLON MAIN
%left LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN
%left EQUAL GREATER GREATEREQUAL LESSEQUAL LESS NOTEQUAL
%left PLUS MINUS AND OR
%left MULTI DIVISION
%start s
%%
s:      global {printf ("ok\n");   printtree ($1,0); };
global:  procedures procMain  {$$ = mknode ("global", $1,NULL,$2); }
            |procMain  {$$ = mknode ("global", $1,NULL,NULL); }     ;
       
       
       /*________________________________________________PROCEDURES________________________________________________*/
procedures: procedures proc   {$$ = mknode ("", $1,NULL, NULL); }
                | proc    {$$ = mknode ("", $1, NULL,NULL); };
                
proc:  procValue | procVoid;
procMain: VOID MAIN LEFTPAREN RIGHTPAREN block_return_void_statements {$$ = mknode ("main", $5,NULL, NULL); };
procVoid: VOID id LEFTPAREN params RIGHTPAREN  block_return_void_statements {$$ = mknode ("procedure", $2, $4, $6); };
procValue: procID LEFTPAREN params RIGHTPAREN  block_return_value_statements {$$ = mknode ("procedure", $1, $3, $5); };
procID: varType id {$$ = mknode ("procID", $1, $2, NULL); };



      /*________________________________________________PARAMS DECLARE______________________________________________*/
params: /* no params  */
        | paramsDeclare {$$ = mknode ("params:", $1, NULL, NULL); };
paramsDeclare: param COMMA  paramsDeclare  {$$ = mknode ("", $1, NULL, $3); }   
        | param ;
/* to change tree design\print, toggle between following: 1) [type id] 2) [][type][id] */
/*param: varType id {char *s = " "; s=  strcat ($1->token,s);  $$ = mknode (strcat($1->token,$2->token), NULL, NULL, NULL); }   ;*/
param: varType id {$$ = mknode ("", $1, NULL, $2); }   ;
  
  
  
       /*______________________________________________EXPR____________________________________________________________*/
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
        | ADDRESS id  {$$ = mknode ("&", $2, NULL,NULL ); }
        | derefID 
        | Pexpr
        | consts ;

        
        /*______________________________________________________BLOCKS_____________________________________________________*/
Pexpr:  LEFTPAREN expr rightParen {$$ = mknode ("(", $2, NULL, $3); };
rightParen: RIGHTPAREN {$$ = mknode (")", NULL, NULL, NULL); };
block_return_value_statements: LEFTBRACE newline RETURN expr SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $2, $4, $6); }
            | LEFTBRACE RETURN expr SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $3, NULL, $5); };
block_return_void_statements :   emptyBlock 
            | LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $4); }
            | LEFTBRACE RETURN SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $4); };

block_statements: emptyBlock
            | LEFTBRACE newline rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $3); };
            //| LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $4);};  //why is this working?? enables any block to end with RETURN

            
emptyBlock: LEFTBRACE rightbrace {$$ = mknode ("(BLOCK", $2, NULL, NULL); };
rightbrace: RIGHTBRACE  {$$ = mknode (")", NULL, NULL,NULL ); };





              /*_________________________________________________TYPES________________________________________________*/
consts: id | numbers | booleans | csnull | strings|chars  ;
id:   ID            {$$ = mknode (yytext, NULL, NULL, NULL); }  ;

numbers: INTEGER_NEG {$$ = mknode (yytext, NULL, NULL, NULL); } 
            | INTEGER_POS  { $$ = mknode (yytext, NULL, NULL, NULL); }
            | HEX_CONST { $$ = mknode (yytext, NULL, NULL, NULL); }
            | OCTAL_CONST { $$ = mknode (yytext, NULL, NULL, NULL); }
            | BINARY_CONST { $$ = mknode (yytext, NULL, NULL, NULL); };
csnull: CSNULL  { $$ = mknode (yytext, NULL, NULL, NULL); };
booleans: BOOLTRUE { $$ = mknode (yytext, NULL, NULL, NULL); }
            | BOOLFALSE { $$ = mknode (yytext, NULL, NULL, NULL); };
strings: STRING_CONST { $$ = mknode (yytext, NULL, NULL, NULL); };
chars: CHAR_CONST { $$ = mknode (yytext, NULL, NULL, NULL); };
              /*_________________________________________________________________________________________________________*/
derefID: DEREFERENCE id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); $$ = mknode (s,NULL, NULL, NULL); } ;

newline:  
        declarations newline   {$$ = mknode ("", $1, NULL,$2); }
           | statements
           | declarations;
           
declarations:  
             variable_declare_statements SEMICOLON;
            //| SEMICOLON; //no integer can be declared with type first

            
            /*_________________________________________________________STATEMENTS___________________________________________________*/
statements: statement statements {$$ = mknode ("STATEMENT", $1, NULL,$2); }
            | statement;

statement: /* | IN.OUT_statements*/
            IF_statements 
            | LOOP_statements  
            | proc
            | ASSIGNMENT_statement SEMICOLON;
        

statements_type: statement
                 |block_statements;
                    
IF_statements: IF cond statements_type {$$ = mknode ("IF", $2,$3,NULL); } %prec LOWER_THAN_ELSE
             | IF cond statements_type else{$$ = mknode ("IF", $2,$3, $4); };
               
else:    ELSE statements_type{$$ = mknode ("ELSE", $2,NULL, NULL); };


            /*_______________________________________LOOP STATEMENTS___________________________________*/
LOOP_statements: while | whileDO | for;
//note: while\DO's right paren is their right grand-child
while: WHILE cond statements_type {$$=mknode("while", $2,NULL, $3);} ;
whileDO: DO statements_type WHILE cond  {$$=mknode("do-while", $2,NULL, $4);};
//note: for right paren is its right child
for:  FOR for_cond  rightParen statements_type{$$=mknode("for", $2,$3, $4);};
                 
for_cond: LEFTPAREN preCondition SEMICOLON postCondition SEMICOLON iteration {$$=mknode("for conditions:", $2,$4, $6);};



preCondition: /* empty */ |  expr | ASSIGNMENT_statement;
postCondition: /* empty */ | expr;
iteration: /* empty */ | ASSIGNMENT_statement;
cond: LEFTPAREN expr rightParen {$$ = mknode ("(COND", $2, NULL, $3); };


            /*________________________________ASSIGNMENT STATEMENTS____________________________________*/
ASSIGNMENT_statement: id ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); } 
            | derefID ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); } ;
str_ASSIGNMENT_statement: id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT strings  {$$ = mknode ("=", $1, NULL, $6); };

                            
                              

varType: BOOL        {$$ = mknode ("boolean", NULL, NULL, NULL); }
            | CHAR          {$$ = mknode ("char", NULL, NULL, NULL); }
            | INT              {$$ = mknode ("integer", NULL, NULL, NULL); }
           /* | STRING       {$$ = mknode ("string", NULL, NULL, NULL); }*/
            | INTPTR        {$$ = mknode ("intptr", NULL, NULL, NULL); }
            | CHARPTR    {$$ = mknode ("charptr", NULL, NULL, NULL); };
            
            
            
            /*____________________________________DECLARATIONS_______________________________________*/
            
StringDeclare:id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare {$$ = mknode ("STRING", $1, NULL, $6); }
              | str_ASSIGNMENT_statement{$$ = mknode ("STRING", $1, NULL,NULL); }
              |str_ASSIGNMENT_statement COMMA StringDeclare {$$ = mknode ("STRING", $1,$3, NULL); }
              |id LEFTBRACKET numbers RIGHTBRACKET;
                          

variablesDeclare: id COMMA variablesDeclare    {$$ = mknode ("", $1, NULL, $3); }
            |  ASSIGNMENT_statement COMMA  variablesDeclare   {$$ = mknode ("", $1, NULL, $3); }
            | ASSIGNMENT_statement 
            | id;
  
variable_declare_statements: varType variablesDeclare /*SEMICOLON*/ {$$ = mknode ("DECLARE", $1, NULL, $2); }
                              |STRING StringDeclare {$$ = mknode ("DECLARE", $2, NULL, NULL); };
  
  
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
