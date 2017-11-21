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
void printtree (node *tree);
#define YYSTYPE struct node *
%}
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR
%token NUM, PLUS, MINUS
%token LEFTPAREN,RIGHTPAREN
%left PLUS MINUS
%start s
%%
s: expr     {printf ("ok\n");   printtree ($1); }
expr:       expr    PLUS    expr    {$$ = mknode ("+", $1, NULL, $3); }
               | expr    MINUS    expr {$$ = mknode ("-", $1, NULL $3); }
               | NUM                   {$$ = mknode (yytext, NULL, NULL, NULL); } ;
               
 
 statements: IF_statements  {} |
             LOOP_statements {} |
             IN.OUT_statements {};
               
               
               
               
               
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

void printtree (node *tree){
    printf ("%s\n", tree -> token);
    if (tree -> left)
        printtree (tree-> left);
    if (tree -> right)
        printtree (tree-> right); 
    if (tree -> middle)
        printtree (tree-> middle);     
}
int yyerror(){
    printf ("MY ERROR\n");
    return 0;
}
