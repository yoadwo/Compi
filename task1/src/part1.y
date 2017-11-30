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
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR, ID
%token IF, ELSE, WHILE, FOR ,DO
%token MAIN, PROCEDURE, RETURN
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER_POS, INTEGER_NEG, CHAR_CONST, STRING_CONST, HEX_CONST, OCTAL_CONST, BINARY_CONST
%token ASSIGNMENT,AND,DIVISION,EQUAL,GREATER,GREATEREQUAL,LESS,LESSEQUAL,MINUS,NOT,NOTEQUAL,OR,PLUS,MULTI,ADDRESS,DEREFERENCE,ABSUOLUTE,SEMICOLON,COLON,COMMA,LEFTBRACE,RIGHTBRACE,LEFTPAREN,RIGHTPAREN,LEFTBRACKET,RIGHTBRACKET,PERCENT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGNMENT  NOT SEMICOLON 
%left LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN
%left EQUAL GREATER GREATEREQUAL LESSEQUAL LESS NOTEQUAL
%left PLUS MINUS AND OR
%left MULTI DIVISION
%start s
%%
s:      
        newline {printf ("ok\n");   printtree ($1,0); };
     
    
newline: newline statement   {$$ = mknode ("", $1, NULL,$2); }
           |statement;
                                  
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
        | ASSIGNMENT_statement;

Pexpr:  LEFTPAREN expr rightParen {$$ = mknode ("(", $2, NULL, $3); };
rightParen: RIGHTPAREN {$$ = mknode (")", NULL, NULL, NULL); };
block_statements: LEFTBRACE newline rightbrace {$$ = mknode ("(BLOCK", $2, NULL, $3); };   
rightbrace: RIGHTBRACE  {$$ = mknode (")", NULL, NULL,NULL ); };
consts: id | numbers    ;
id:   ID            {$$ = mknode (yytext, NULL, NULL, NULL); }  ;
numbers: INTEGER_NEG {$$ = mknode (yytext, NULL, NULL, NULL); } 
            | INTEGER_POS  { $$ = mknode (yytext, NULL, NULL, NULL); };

             
statement: IF_statements 
            | LOOP_statements  
           /* | IN.OUT_statements*/
            | BOOLEAN_statements
            | variable_declare_statements
            | expr SEMICOLON;

statements_type: statement
                 |block_statements;
                    
IF_statements: IF cond statements_type {$$ = mknode ("IF", $2,$3,NULL); } %prec LOWER_THAN_ELSE
             | IF cond statements_type else{$$ = mknode ("IF", $2,$3, $4); };
               
else:    ELSE statements_type{$$ = mknode ("ELSE", $2,NULL, NULL); };

LOOP_statements: WHILE cond statements_type {$$=mknode("while", $2,$3, NULL);} 
                 | FOR cond statements_type{$$=mknode("for", $2,$3, NULL);}
                 | DO statements_type WHILE cond  {$$=mknode("do-while", $2,NULL, $4);};
                 
cond:expr;
                 
BOOLEAN_statements: BOOLTRUE {$$ = mknode ("true", NULL,NULL, NULL); } 
                    | BOOLFALSE {$$ = mknode ("false", NULL, NULL, NULL); }; 
                 
/*IN.OUT_statements:;*/
ASSIGNMENT_statement: id ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); };

variable_declare_statements: varType mul_id SEMICOLON {$$ = mknode ("DECLARE", $1, NULL, $2); };

varType: BOOL              {$$ = mknode ("boolean: ", NULL, NULL, NULL); }
            | CHAR          {$$ = mknode ("char: ", NULL, NULL, NULL); }
            | INT              {$$ = mknode ("integer: ", NULL, NULL, NULL); }
            | STRING       {$$ = mknode ("string: ", NULL, NULL, NULL); }
            | INTPTR        {$$ = mknode ("integer ptr: ", NULL, NULL, NULL); }
            | CHARPTR    {$$ = mknode ("char ptr: ", NULL, NULL, NULL); };

mul_id: mul_id COMMA id    {$$ = mknode ("", $1, NULL, $3); }
            | mul_id COMMA ASSIGNMENT_statement    {$$ = mknode ("", $1, NULL, $3); }
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
