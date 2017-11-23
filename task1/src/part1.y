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
%token IF, ELSE, WHILE, FOR
%token MAIN, PROCEDURE, RETURN
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER_POS, INTEGER_NEG, CHAR_CONST, STRING_CONST, HEX_CONST, OCTAL_CONST, BINARY_CONST
%token ASSIGNMENT,AND,DIVISION,EQUAL,GREATER,GREATEREQUAL,LESS,LESSEQUAL,MINUS,NOT,NOTEQUAL,OR,PLUS,MULTI,ADDRESS,DEREFERENCE,ABSUOLUTE,SEMICOLON,COLON,COMMA,LEFTBRACE,RIGHTBRACE,LEFTPAREN,RIGHTPAREN,LEFTBRACKET,RIGHTBRACKET,PERCENT

%right ASSIGNMENT ELSE 
%left LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN
%left EQUAL GREATER GREATEREQUAL LESSEQUAL LESS NOTEQUAL
%left PLUS MINUS AND OR 
%left MULTI DIVISION
%start s
%%
s:  expr                 {printf ("ok\n");   printtree ($1,0); }
        | statements  {printf ("ok\n");   printtree ($1,0); }
        | comp_expr {printf ("ok\n");   printtree ($1,0); };
expr:       expr PLUS expr    {$$ = mknode ("+", $1, NULL, $3); }
               | expr MINUS expr {$$ = mknode ("-", $1, NULL, $3); }
               | expr MULTI expr {$$ = mknode ("*", $1, NULL, $3); }
               | expr DIVISION expr {$$ = mknode ("/", $1, NULL, $3); }
               | Pexpr
               | id
               | numbers                   ;
id: ID                         {$$ = mknode (yytext, NULL, NULL, NULL); }  ;
Pexpr:  leftParen expr rightParen {$$ = mknode ("PARENTHESES", $1, $2, $3); };
leftParen: LEFTPAREN {$$ = mknode ("(", NULL, NULL, NULL); };
rightParen: RIGHTPAREN {$$ = mknode (")", NULL, NULL, NULL); };
numbers: INTEGER_NEG {$$ = mknode (yytext, NULL, NULL, NULL); } 
            |      INTEGER_POS  { $$ = mknode (yytext, NULL, NULL, NULL); };
bool_expr: bool_expr AND bool_expr {$$ = mknode ("&&", $1, NULL, $3); }
            | bool_expr OR bool_expr {$$ = mknode ("||", $1, NULL, $3); }
            | NOT bool_expr {$$ = mknode ("!", NULL, NULL, $2); }
            | comp_expr;

comp_expr: expr EQUAL expr { $$ = mknode ("==", $1, NULL, $3); }
                | expr GREATER expr { $$ = mknode (">", $1, NULL, $3); }
                | expr GREATEREQUAL expr { $$ = mknode (">=", $1, NULL, $3); }
                | expr LESS expr { $$ = mknode ("<", $1, NULL, $3); }
                | expr LESSEQUAL expr { $$ = mknode ("<=", $1, NULL, $3); }
                | expr NOTEQUAL expr { $$ = mknode ("!=", $1, NULL, $3); };
                
statements: IF_statements 
            |  LOOP_statements  
            |  IN.OUT_statements 
            |  ASSIGNMENT_statements 
            | BOOLEAN_statements ;

BOOLEAN_statements: BOOLTRUE {$$ = mknode ("true", NULL,NULL, NULL); }
                    | BOOLFALSE {$$ = mknode ("false", NULL, NULL, NULL); };
IF_statements: IF | ELSE;
LOOP_statements: WHILE | FOR;
IN.OUT_statements: ;
ASSIGNMENT_statements: id ASSIGNMENT expr  {$$ = mknode ("=", $1, NULL, $3); };
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
