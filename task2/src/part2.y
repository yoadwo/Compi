%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode{
    char *token;
    struct treeNode *left;
    struct treeNode *middle;
    struct treeNode *right;
} treeNode;

typedef struct symbolNode{
	char* id;
	char* type;
	char* data;
	struct symbolNode *next;
} symbolNode;


 symbolNode* head = NULL;

treeNode *mktreeNode (char *token, treeNode *left, treeNode* middle, treeNode *right);
void printtree (treeNode *tree, int tab);
void pushSymbols(char* type,treeNode* tNode);
void push(struct symbolNode** head_ref, char* id, char* type, char* new_data);
#define YYSTYPE struct treeNode *
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
s:      global {printf ("ok\n");  printList(head);printf("\n"); printtree ($1,0); };
global:  procedures procMain  {$$ = mktreeNode ("global", $1,NULL,$2); }
            |procMain  {$$ = mktreeNode ("global", $1,NULL,NULL); }     ;
       
       
       /*________________________________________________PROCEDURES________________________________________________*/
procedures: procedures proc   {$$ = mktreeNode ("", $1,NULL, NULL); }
                | proc    {$$ = mktreeNode ("", $1, NULL,NULL); };
                
proc:  procValue | procVoid;
procMain: VOID MAIN LEFTPAREN RIGHTPAREN block_return_void_statements {$$ = mktreeNode ("main", $5,NULL, NULL); };
procVoid: VOID id LEFTPAREN params RIGHTPAREN  block_return_void_statements {$$ = mktreeNode ("procedure", $2, $4, $6); };
procValue: procID LEFTPAREN params RIGHTPAREN  block_return_value_statements {$$ = mktreeNode ("procedure", $1, $3, $5); };
procID: varType id {$$ = mktreeNode ("procID", $1, $2, NULL); };



      /*________________________________________________PARAMS DECLARE______________________________________________*/
params: /* no params  */
        | paramsDeclare {$$ = mktreeNode ("params:", $1, NULL, NULL); };
paramsDeclare: param COMMA  paramsDeclare  {$$ = mktreeNode ("", $1, NULL, $3); }   
        | param ;
/* to change tree design\print, toggle between following: 1) [type id] 2) [][type][id] */
/*param: varType id {char *s = " "; s=  strcat ($1->token,s);  $$ = mktreeNode (strcat($1->token,$2->token), NULL, NULL, NULL); }   ;*/
param: varType id {$$ = mktreeNode ("", $1, NULL, $2); }   ;
  
  
  
       /*______________________________________________EXPR____________________________________________________________*/
expr:     expr PLUS expr    {$$ = mktreeNode ("+", $1, NULL, $3); }
        | expr MINUS expr {$$ = mktreeNode ("-", $1, NULL, $3); }
        | expr MULTI expr {$$ = mktreeNode ("*", $1, NULL, $3); }
        | expr DIVISION expr  {$$ = mktreeNode ("/", $1, NULL, $3); }
        | expr EQUAL expr  { $$ = mktreeNode ("==", $1, NULL, $3); }
        | expr GREATER expr  { $$ = mktreeNode (">", $1, NULL, $3); }
        | expr GREATEREQUAL expr { $$ = mktreeNode (">=", $1, NULL, $3); }
        | expr LESS expr { $$ = mktreeNode ("<", $1, NULL, $3); }
        | expr LESSEQUAL expr { $$ = mktreeNode ("<=", $1, NULL, $3); }
        | expr NOTEQUAL expr { $$ = mktreeNode ("!=", $1, NULL, $3); }
        | expr AND expr {$$ = mktreeNode ("&&", $1, NULL, $3); }
        | expr OR expr {$$ = mktreeNode ("||", $1, NULL, $3); }
        | NOT expr {$$ = mktreeNode ("NOT", NULL, NULL, $2); }
        | ADDRESS id  {$$ = mktreeNode ("&", $2, NULL,NULL ); }
        | derefID 
        | Pexpr
        | consts ;

        
        /*______________________________________________________BLOCKS_____________________________________________________*/
Pexpr:  LEFTPAREN expr rightParen {$$ = mktreeNode ("(", $2, NULL, $3); };
rightParen: RIGHTPAREN {$$ = mktreeNode (")", NULL, NULL, NULL); };
block_return_value_statements: LEFTBRACE newline RETURN expr SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, $4, $6); }
            | LEFTBRACE RETURN expr SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $3, NULL, $5); };
block_return_void_statements :   emptyBlock 
            | LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $4); }
            | LEFTBRACE RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $4); };

block_statements: emptyBlock
            | LEFTBRACE newline rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $3); };
            //| LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $4);};  //why is this working?? enables any block to end with RETURN

            
emptyBlock: LEFTBRACE rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, NULL); };
rightbrace: RIGHTBRACE  {$$ = mktreeNode (")", NULL, NULL,NULL ); };





              /*_________________________________________________TYPES________________________________________________*/
consts: id | numbers | booleans | csnull | strings|chars | procCall ;
id:   ID            {$$ = mktreeNode (yytext, NULL, NULL, NULL); }  ;

numbers: INTEGER_NEG {$$ = mktreeNode (yytext, NULL, NULL, NULL); } 
            | INTEGER_POS  { $$ = mktreeNode (yytext, NULL, NULL, NULL); }
            | HEX_CONST { $$ = mktreeNode (yytext, NULL, NULL, NULL); }
            | OCTAL_CONST { $$ = mktreeNode (yytext, NULL, NULL, NULL); }
            | BINARY_CONST { $$ = mktreeNode (yytext, NULL, NULL, NULL); };
csnull: CSNULL  { $$ = mktreeNode (yytext, NULL, NULL, NULL); };
booleans: BOOLTRUE { $$ = mktreeNode (yytext, NULL, NULL, NULL); }
            | BOOLFALSE { $$ = mktreeNode (yytext, NULL, NULL, NULL); };
strings: STRING_CONST { $$ = mktreeNode (yytext, NULL, NULL, NULL); };
chars: CHAR_CONST { $$ = mktreeNode (yytext, NULL, NULL, NULL); };
procCall: id LEFTPAREN args RIGHTPAREN { $$ = mktreeNode ("func call", $1, NULL, $3); };

args: /* no params  */
        | argsDeclare {$$ = mktreeNode ("args:", $1, NULL, NULL); };
argsDeclare: consts COMMA  argsDeclare  {$$ = mktreeNode ("", $1, NULL, $3); }   
        | consts ;

              /*_________________________________________________________________________________________________________*/
derefID: DEREFERENCE id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); $$ = mktreeNode (s,NULL, NULL, NULL); } ;

newline:  
        declarations newline   {$$ = mktreeNode ("", $1, NULL,$2); }
           | statements
           | declarations;
           
declarations:  
             variable_declare_statements SEMICOLON;
            //| SEMICOLON; //no integer can be declared with type first

            
            /*_________________________________________________________STATEMENTS___________________________________________________*/
statements: statement statements {$$ = mktreeNode ("STATEMENT", $1, NULL,$2); }
            | statement;

statement: /* | IN.OUT_statements*/
            IF_statements 
            | LOOP_statements  
            | proc
            | procCall SEMICOLON
            | ASSIGNMENT_statement SEMICOLON;
        

statements_type: statement
                 |block_statements;
                    
IF_statements: IF cond statements_type {$$ = mktreeNode ("IF", $2,$3,NULL); } %prec LOWER_THAN_ELSE
             | IF cond statements_type else{$$ = mktreeNode ("IF", $2,$3, $4); };
               
else:    ELSE statements_type{$$ = mktreeNode ("ELSE", $2,NULL, NULL); };


            /*_______________________________________LOOP STATEMENTS___________________________________*/
LOOP_statements: while | whileDO | for;
//note: while\DO's right paren is their right grand-child
while: WHILE cond statements_type {$$=mktreeNode("while", $2,NULL, $3);} ;
whileDO: DO statements_type WHILE cond  {$$=mktreeNode("do-while", $2,NULL, $4);};
//note: for right paren is its right child
for:  FOR for_cond  rightParen statements_type{$$=mktreeNode("for", $2,$3, $4);};
                 
for_cond: LEFTPAREN preCondition SEMICOLON postCondition SEMICOLON iteration {$$=mktreeNode("for conditions:", $2,$4, $6);};



preCondition: /* empty */ |  expr | ASSIGNMENT_statement;
postCondition: /* empty */ | expr;
iteration: /* empty */ | ASSIGNMENT_statement;
cond: LEFTPAREN expr rightParen {$$ = mktreeNode ("(COND", $2, NULL, $3); };


            /*________________________________ASSIGNMENT STATEMENTS____________________________________*/
ASSIGNMENT_statement: id ASSIGNMENT expr  {$$ = mktreeNode ("=", $1, NULL, $3); } 
            | derefID ASSIGNMENT expr  {$$ = mktreeNode ("=", $1, NULL, $3); } ;
str_ASSIGNMENT_statement: id LEFTBRACKET numbers RIGHTBRACKET ASSIGNMENT strings  {$$ = mktreeNode ("=", $1, NULL, $6); };

                            
                              

varType: BOOL        {$$ = mktreeNode ("boolean", NULL, NULL, NULL); }
            | CHAR          {$$ = mktreeNode ("char", NULL, NULL, NULL); }
            | INT              {$$ = mktreeNode ("integer", NULL, NULL, NULL); }
           /* | STRING       {$$ = mktreeNode ("string", NULL, NULL, NULL); }*/
            | INTPTR        {$$ = mktreeNode ("intptr", NULL, NULL, NULL); }
            | CHARPTR    {$$ = mktreeNode ("charptr", NULL, NULL, NULL); };
            
            
            
            /*____________________________________DECLARATIONS_______________________________________*/
            
StringDeclare:id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare {$$ = mktreeNode ("STRING", $1, NULL, $6); }
              | str_ASSIGNMENT_statement{$$ = mktreeNode ("STRING", $1, NULL,NULL); }
              |str_ASSIGNMENT_statement COMMA StringDeclare {$$ = mktreeNode ("STRING", $1,$3, NULL); }
              |id LEFTBRACKET numbers RIGHTBRACKET     {$$ = mktreeNode ("STRING", $1,NULL, NULL); };
                          

variablesDeclare: id COMMA variablesDeclare    {$$ = mktreeNode ("", $1, NULL, $3); }
            |  ASSIGNMENT_statement COMMA  variablesDeclare   {$$ = mktreeNode ("", $1, NULL, $3); }
            | ASSIGNMENT_statement 
            | id;
  
variable_declare_statements: varType variablesDeclare /*SEMICOLON*/ {pushSymbols($1->token,$2); $$ = mktreeNode ("DECLARE", $1, NULL, $2);}
                              |STRING StringDeclare {$$ = mktreeNode ("DECLARE", $2, NULL, NULL); };
  
  
%%

#include "lex.yy.c"
int main(){
    return yyparse();
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


// A complete working C program to delete a node in a linked list
// at a given position

void pushSymbols(char* type,treeNode* tNode){
  /*left is id or assighment*/
  /*single assighment */
   
  if(!strcmp(tNode->token,"=")){
    push( &head,tNode->left->token,type,tNode->right->token);
   
    }
    
 
  
  ]
 /* else
    push(&head,tNode->left->token,type,NULL);
 if(!strcmp(tNode->right->token,"=")){
    push( &head,tNode->right->left->token,type,tNode->left->right->token);
 return;
 }
 
   pushSymbols(type,tNode->right);  */ 

}


/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct symbolNode** head_ref, char* id, char* type, char* new_data)
{
	struct symbolNode* new_node = (struct symbolNode*) malloc(sizeof(struct symbolNode));
	
	new_node->id = (char*)(malloc (sizeof(id) + 1));
	strncpy(new_node->id, id, sizeof(id)+1);
	
	new_node->data = (char*)(malloc (sizeof(new_data) + 1));
	strncpy(new_node->data, new_data, sizeof(new_data)+1);
	
	new_node->type = (char*)(malloc (sizeof(type) + 1));
	strncpy(new_node->type, type, sizeof(type)+1);
	
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position */
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

// This function prints contents of linked list starting from
// the given node
void printList(struct symbolNode *node)
{
	while (node != NULL)
	{
		printf("id:{%s}, type:{%s}, data{%s} \n", node->id, node->type, node->data);
		node = node->next;
	}
}



 /* Drier program to test above functions*/
  /* int main2()
  {
   Start with the empty list 


    push(&head, "a", "int", 7);
	push(&head, "b", "float", 1);
	push(&head, "c", "char", 3);
	push(&head, "d1", "string", 2);
	push(&head, "e23", "bool", 8);

	puts("Created Linked List: ");
	printList(head);
	deletesymbolNode(&head, 4);
	puts("\nLinked List after Deletion at position 4: ");
	printList(head);
	return 0;
 }*/

