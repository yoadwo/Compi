%{
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
    int isProc; //0 if primitive symbol, 1 if is procedure
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
	int ScopeLevel;
	symbolNode *symbolTable;
	struct scopeNode *next;
} scopeNode;

typedef struct astNode{
        char* key;
        struct astNode *left;
        struct astNode *right;
} astNode;


symbolNode* head = NULL;
scopeNode* topStack = NULL;
astNode* ast = NULL;
int ScopeNum=0;

void startSematics(treeNode *root);
astNode* BuildASTNode(treeNode *root);
symbolNode* scopeLookup (char* token);
//bool checkEvaluation(treeNode* tNode);
void printInfo(treeNode *head);
treeNode *mktreeNode (char *token, treeNode *left, treeNode* middle, treeNode *right);
void printtree (treeNode *tree, int tab);
int isCompileErrors(scopeNode *root);
int isSimilarSymbols(char* scopeName, struct symbolNode* root);
int checkDuplicateSymbols(scopeNode* root);
void pushStatements(treeNode* tNode,int scopeLevel);
void pushScopeStatements(treeNode* tNode);
void pushSymbols( char* type,treeNode* tNode);
void pushProcSymbols( treeNode* tNode);
void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params);
void pushScopeToStack(struct scopeNode** head_ref, char* scopeName,treeNode* tNode,int scopeLevel);
void printSymbolTable(struct scopeNode *node);
void printScopes(struct scopeNode *node);
symbolNode* symbolLookup (struct symbolNode** head_ref, char* token);
int isConst(treeNode* tNode);
int isParamsMatch(treeNode* callParams, treeNode* declaredParams/*, struct symbolNode* currentSymTab*/);
int checkDuplicateSymbols(scopeNode *root);
int checkDuplicateProcs(scopeNode *root);
symbolNode *funcTreeToParamsList(symbolNode **head_ref, treeNode *tNode);
int compareCallDeclare( char *token, treeNode *callParams);
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
s:      global {    if (!isCompileErrors(topStack)){YYERROR;}; startSematics($1); };
global:  procedures procMain  {$$ = mktreeNode ("global", $1,NULL,$2); }
            |procMain  {$$ = mktreeNode ("global", $1,NULL,NULL); }     ;
       
       
       /*________________________________________________PROCEDURES________________________________________________*/
procedures: procedures proc   {$$ = mktreeNode ("", $1,NULL, NULL); }
                | proc    {$$ = mktreeNode ("", $1, NULL,NULL);};
                  
proc:  procValue  | procVoid ; 
procMain: VOID MAIN LEFTPAREN RIGHTPAREN block_return_void_statements { $$ = mktreeNode ("main", $5,NULL, NULL); };
procVoid: procID LEFTPAREN params RIGHTPAREN  block_return_void_statements {$$ = mktreeNode ("procedure", $1, $3, $5);};
procValue: procID LEFTPAREN params RIGHTPAREN  block_return_value_statements {$$ = mktreeNode ("procedure", $1, $3, $5); };
procID: varType id {$$ = mktreeNode ("procID", $1, NULL, $2); }
        | void id {$$ = mktreeNode ("procID", $1, NULL, $2); };



      /*________________________________________________PARAMS DECLARE______________________________________________*/
params: /* no params  */
        | paramsDeclare {$$ = mktreeNode ("params:", $1, NULL, NULL); };
paramsDeclare: param COMMA  paramsDeclare  {$$ = mktreeNode (",", $1, NULL, $3); }   
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
        | address 
        | derefID 
        | Pexpr
        | consts ;

        
        /*______________________________________________________BLOCKS_____________________________________________________*/
Pexpr:  LEFTPAREN expr rightParen {$$ = mktreeNode ("(", $2, NULL, $3); };
rightParen: RIGHTPAREN {$$ = mktreeNode (")", NULL, NULL, NULL); };
block_return_value_statements: LEFTBRACE newline RETURN expr SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, $4, $6); }
            | LEFTBRACE RETURN expr SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $3, NULL, $5); };
block_return_void_statements :   emptyBlock 
            | LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $5); }
            | LEFTBRACE RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", NULL, NULL, $4); };

block_statements: emptyBlock
            | LEFTBRACE newline rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $3);};
            //| LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $4);};  //why is this working?? enables any block to end with RETURN

            
emptyBlock: LEFTBRACE rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, NULL);};
rightbrace: RIGHTBRACE  {$$ = mktreeNode (")", NULL, NULL,NULL ); };





              /*_________________________________________________TYPES________________________________________________*/
              
/*consts: id { symbolNode *s = scopeLookup($1->token);
                    if (s == NULL ) 
                    {
                        yyerror("unknown variable is used"); 
                        YYERROR;
                    };
                }
                    | numbers | booleans | csnull | chars | procCall | strings ; */
consts: id | numbers | booleans | csnull | strings |chars | procCall ;


id:   ID            {$$ = mktreeNode (yytext, NULL, NULL, NULL); }  ;

 numbers: INTEGER_NEG {$$ = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("neg",NULL,NULL,NULL)); } 
            | INTEGER_POS  {$$ = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("pos",NULL,NULL,NULL)); } 
            | HEX_CONST {$$ = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("hex",NULL,NULL,NULL)); } 
            | OCTAL_CONST {$$ = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("oct",NULL,NULL,NULL)); } 
            | BINARY_CONST {$$ = mktreeNode (yytext, mktreeNode("integer", NULL,NULL,NULL), NULL, mktreeNode("bin",NULL,NULL,NULL)); } ; 

csnull: CSNULL  { $$ = mktreeNode (yytext, NULL, NULL, NULL); };

booleans: BOOLTRUE { $$ = mktreeNode (yytext, mktreeNode("boolean", NULL,NULL,NULL), NULL, NULL); }
            | BOOLFALSE { $$ = mktreeNode (yytext, mktreeNode("boolean", NULL,NULL,NULL), NULL, NULL); };

strings: STRING_CONST {$$ = mktreeNode (yytext, mktreeNode("charp", NULL,NULL,NULL), NULL, NULL); } ;

chars: CHAR_CONST {$$ = mktreeNode (yytext, mktreeNode("char", NULL,NULL,NULL), NULL, NULL); };

/*procCall: id LEFTPAREN args RIGHTPAREN { $$ = mktreeNode ("func call", $1, NULL, $3); };*/

procCall: id LEFTPAREN args RIGHTPAREN 
                    { 
                    /*
                    if (!compareCallDeclare  (topStack, $1->left->token,$3)   ){
                        yyerror("function params mismatch"); YYERROR;
                    }*/
                    $$ = mktreeNode ("func call", $1, NULL, $3);
                    }; 

args: /* no params  */
        | argsDeclare {$$ = mktreeNode ("args:", $1, NULL, NULL); };
argsDeclare: consts COMMA  argsDeclare  {$$ = mktreeNode (",", $1, NULL, $3); }   
        | consts ;

address : ADDRESS id            { symbolNode *sym = symbolLookup(&head,$2->token);
                                                if (strcmp(sym->type, "char") && strcmp(sym->type, "integer")) 
                                                        { yyerror("pointer-type variables cannot be referenced"); YYERROR;} 
                                                char* t = $2->token; char *s = malloc(strlen(t)+strlen("&")+1); strcat (s,"&"); strcat(s,t); 
                                                $$ = mktreeNode (s,NULL, NULL, NULL); };        
        
              /*_________________________________________________________________________________________________________*/
derefID: DEREFERENCE id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); $$ = mktreeNode (s,NULL, NULL, NULL); } ;
/*derefID: DEREFERENCE id  { symbolNode *sym = symbolLookup(&head,$2->token);
                                                if (strcmp(sym->type, "charp") && strcmp(sym->type, "intp")) 
                                                        { yyerror("non-pointer-type variables cannot be dereferenced"); YYERROR;} 
                                                char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); 
                                                $$ = mktreeNode (s,NULL, NULL, NULL); 
                                                } ;*/
                                                
/*_______________________________________________________BLOCK_BODY_STRUCTURE_________________________________________*/

newline:  
        declarations newline   {$$ = mktreeNode ("", $1, NULL,$2); }
           | statements  
           | declarations ;
           
declarations:  
             variable_declare_statements SEMICOLON;
            //| SEMICOLON; //no integer can be declared with type first

            
            /*_________________________________________________________STATEMENTS___________________________________________________*/
statements: statement statements {$$ = mktreeNode ("STATEMENT", $1, NULL,$2); }
            | statement {$$ = mktreeNode ("STATEMENT", $1, NULL,NULL); };

statement: /* | IN.OUT_statements*/
            IF_statements 
            | LOOP_statements  
            | proc
            | procCall SEMICOLON
            | ASSIGNMENT_statement SEMICOLON;
/*statement: /* | IN.OUT_statements
            IF_statements 
            | LOOP_statements  
            | proc
            | procCall SEMICOLON
            //change to updateSymbols (head, $1)
            | ASSIGNMENT_statement SEMICOLON { if (!isSimilarSymbols(&head, $1->left)) { yyerror("unknown variable is being assigned to"); YYERROR;};};*/

statements_type: statement
                 |block_statements;

                 /*_______________________________________CONDITIONAL_STATEMENTS___________________________________*/ 
IF_statements: IF cond statements_type {$$ = mktreeNode ("IF", $2,$3,NULL);} %prec LOWER_THAN_ELSE
             | IF cond statements_type else{$$ = mktreeNode ("IF", $2,$3, $4);};
               
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
            | STRING       {$$ = mktreeNode ("string", NULL, NULL, NULL); }
            | INTPTR        {$$ = mktreeNode ("intptr", NULL, NULL, NULL); }
            | CHARPTR    {$$ = mktreeNode ("charptr", NULL, NULL, NULL); };
void: VOID        {$$ = mktreeNode ("void", NULL, NULL, NULL); };
            
            
            /*____________________________________DECLARATIONS_______________________________________*/
            
StringDeclare:id LEFTBRACKET numbers RIGHTBRACKET COMMA StringDeclare {$$ = mktreeNode ("STRING", $1, NULL, $6); }
              | str_ASSIGNMENT_statement{/*$$ = mktreeNode ("STRING", $1, NULL,NULL); */}
              |str_ASSIGNMENT_statement COMMA StringDeclare {$$ = mktreeNode ("STRING", $1,$3, NULL); }
              |id LEFTBRACKET numbers RIGHTBRACKET     {/*$$ = mktreeNode ("STRING", $1,NULL, NULL);*/ };
                          

variablesDeclare: id COMMA variablesDeclare    {$$ = mktreeNode ("", $1, NULL, $3); }
            |  ASSIGNMENT_statement COMMA  variablesDeclare   {$$ = mktreeNode ("", $1, NULL, $3); }
            | ASSIGNMENT_statement 
            | id;
  
variable_declare_statements: varType variablesDeclare /*SEMICOLON*/ {/*pushSymbols( $1->token,$2);*/ $$ = mktreeNode ("DECLARE", $1, NULL, $2);}
                              |varType StringDeclare {/*pushSymbols("String",$2);*/ $$ = mktreeNode ("DECLARE", $1, NULL, $2); };
/*variable_declare_statements: 
                            varType variablesDeclare  { if (!pushSymbols(&head, $1->token,$2)){ yyerror("duplicate identifier found"); YYERROR;};
                                                                                                                        $$ = mktreeNode ("DECLARE", $1, NULL, $2);}
                          | STRING StringDeclare       { if (!pushSymbols(&head, "charp",$2)){ yyerror("duplicate identifier found"); YYERROR;};
                                                                                                                        $$ = mktreeNode ("DECLARE", mktreeNode ("charp", NULL, NULL, NULL), NULL, $2); };*/
  
%%

#include "lex.yy.c"
int main(){
    return yyparse();
}

void startSematics(treeNode *root){
    pushStatements(root, 1);
    printInfo(root);
    ast = BuildASTNode(root);
}

astNode* BuildASTNode(treeNode *root){
    
}

void printInfo(treeNode *root){
    printf ("ok\n"); 
    
    printf("print symbol table:\n");
    printSymbolTable(topStack);
    printf("\n"); 
    printf("print scopes:\n");
    printScopes(topStack);
    
    printf("\n"); 

    printtree (root,0);
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

int isCompileErrors(scopeNode *root){
    // return 1 if all checks pass, otherwise 0;
    int pass = 1;
    pass = pass && checkDuplicateSymbols(root);
    
    return pass;
}

int isDeclared(treeNode *tNode){
    // bad cases: "procedure", '('
    if (!strcmp(tNode->token, ")"))
        return 1;
    if (!strcmp(tNode->token, "procedure"))
        return 1;
    
        
    //base 1: node has no children -> node is identifier, do scope lookup
    if (tNode->left == NULL && tNode->middle == NULL  && tNode->right == NULL ){
        // ')' can also be seen as a leaf
                symbolNode *symbol =  scopeLookup(tNode->token);
                if (symbol == NULL){
                    printf ("undefined variable [%s]\n", tNode->token); //add scope
                    return 0;
                    }
                else
                    return 1;
        }
                
    //base 2: node is const
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
    //result = isDeclared(tNode->right) && result;
    return result;
    
}

/* check if two symbols were declared in same scope */
int checkDuplicateSymbols(scopeNode* root){
    struct scopeNode * currentScope=root;
    while(currentScope!=NULL){
        if(isSimilarSymbols(currentScope->scopeName, currentScope->symbolTable)==0)
            return 0;
        currentScope=currentScope->next;
    }
    return 1;
}

symbolNode *funcTreeToParamsList(symbolNode **head_ref, treeNode *tNode){
        
    return NULL;
}

/* check ALL scopes, each symbol table in scope, if called params match some functions params */ 
/* function return 1 if some function with matching signature exists, 0 otherwise */
int compareCallDeclare(char *token, treeNode *callParams){
    // currentScope iterates all scopes
    // current iterates symbols in current scope (root)
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


void pushStatements(treeNode* tNode,int scopeLevel){
    if(tNode==NULL)
        return;
    //int scopeID=0;
    // struct scopeNode* currentStack;
    // currentStack= (struct scopeNode*) malloc(sizeof(struct scopeNode));
    // memcpy(&currentStack,&topStack,sizeof(topStack));

    if(!strcmp(tNode->token,"ELSE")){
        scopeLevel++;
        pushScopeToStack(&topStack, "ELSE",tNode->left,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"while")){
        scopeLevel++;
        pushScopeToStack(&topStack,"while",tNode->right,scopeLevel);
        //  return;
    }
    if(!strcmp(tNode->token,"IF")){
        scopeLevel++;
        pushScopeToStack(&topStack, "IF",tNode->middle,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"ELSE")){
        pushScopeToStack(&topStack, "ELSE",tNode->left,scopeLevel);
        //return;
    }
    
    if(!strcmp(tNode->token,"BLOCK")){
        pushStatements(tNode->left,scopeLevel);
    }
    if(!strcmp(tNode->token,"do-while")){
        scopeLevel++;
        pushScopeToStack(&topStack, "do-while",tNode->left,scopeLevel);
        // return;
    }
    if(!strcmp(tNode->token,"for")){
        scopeLevel++;
        pushScopeToStack(&topStack, "for",tNode->right,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"procedure")){
        //pushProcSymbols(tNode);
        scopeLevel++;
        pushScopeToStack(&topStack,"procedure",tNode->right,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"main")){
        scopeLevel++;
        pushScopeToStack(&topStack, "main",tNode->left->left,scopeLevel);
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

// A complete working C program to delete a node in a linked list
// at a given position

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


/* wrapper function to add procedures to symbol table */
/* pass on to "push" with value "1" to identify it as a fucntion   */
void pushProcSymbols(treeNode* tNode)
{
   /* symbolNode* head = (*head_ref)->symbolTable;*/
    //params is tNode->middle;
    int isProc = 1;
    pushSymbolsToTable(&topStack, tNode->left->right->token, tNode->left->left->token, "function",1, tNode->middle);
}

/* 
PUSH SYMBOLS TO SYMBOL LIST (TABLE)
Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params)
{
	struct symbolNode* new_node = (struct symbolNode*) malloc(sizeof(struct symbolNode));
	
	new_node->isProc = isProc;
	
	new_node->id = (char*)(malloc (sizeof(id) + 1));
	strncpy(new_node->id, id, sizeof(id)+1);
	
	if (new_data != NULL)
	{
            new_node->data = (char*)(malloc (sizeof(new_data) + 1));
            strncpy(new_node->data, new_data, sizeof(new_data)+1);
	}
	new_node->type = (char*)(malloc (sizeof(type) + 1));
	strncpy(new_node->type, type, sizeof(type)+1);
	
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
            
	new_node->next =(*node)->symbolTable;
	(*node)->symbolTable = new_node;
}
  
void pushScopeToStack(struct scopeNode** head_ref, char* scopeName,treeNode* tNode,int scopeLevel)
{     /*declare shouldn't get here*/  
      if(strcmp(scopeName,"DECLARE")){
     ScopeNum++;
        //printf ("adding scope: %s\n",scopeName);
	struct scopeNode* new_scope = (struct scopeNode*) malloc(sizeof(struct scopeNode));
        
	new_scope->scopeName = (char*)(malloc (sizeof(scopeName) + 1));
	strncpy(new_scope->scopeName, scopeName, sizeof(scopeName)+1);
	
        new_scope->scopeNum=ScopeNum;
        new_scope->ScopeLevel=scopeLevel-1;
		
	new_scope->next = (*head_ref);
	(*head_ref) = new_scope;
	}
	pushScopeStatements(tNode);
}

void pushScopeStatements(treeNode* tNode){
    
    
    if(tNode==NULL)
        return;
    
    if(!strcmp(tNode->token,"ELSE")){
        return;
    }
    if(!strcmp(tNode->token,"while")){
        return;
    }
    if(!strcmp(tNode->token,"IF")){
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
    // if(!strcmp(tNode->token,"main")){
    // return;
    // }
    if(!strcmp(tNode->token,"DECLARE")){
        pushSymbols(tNode->left->token,tNode->right);
        //YYERROR;
        return;
    }
    
     if (!strcmp(tNode->token, "func call")){
        compareCallDeclare( tNode->left->token, tNode->right);      
    }
    
     if (!strcmp(tNode->token, "STATEMENT")){
        //isDeclared(tNode);
    }
    
    pushScopeStatements(tNode->left);
    pushScopeStatements(tNode->middle);
    pushScopeStatements(tNode->right);
    
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
		printf("scope id:{%s} scopeNum:{%d} ScopeLevel:{%d}\n", current->scopeName,current->scopeNum,current->ScopeLevel);
		current = current->next;
	}
    printf("num of scopes:{%d}\n",ScopeNum);
	
}

int isNumeric(char* token){
    int len = strlen(token), i;
    for (i = 0; i<len; i++){
        if ( !isdigit(token[i]))
            return 0;
    }
    return 1;
}

int isConst(treeNode* tNode){
// booleans | csnull |  numbers | strings | chars |  ;
// procCall / id
    if (!strcmp(tNode->left->token, "boolean"))
        return 1;
    else if (!strcmp(tNode->token, "null"))
        return 1;
    else if (!strcmp(tNode->left->token, "integer"))
        return 1;
    else if (!strcmp(tNode->left->token, "charp"))
        return 1;
    else if (!strcmp(tNode->left->token, "char"))
        return 1;
    else if (isNumeric(tNode->token))
        return 1;
    return 0;
              
}

int isParamsMatch(treeNode* callParams, treeNode* declaredParams/*, struct symbolNode* currentSymTab*/)
{
    // compare callParams and declaredParams trees //
    // callParams: node has token value and no childs ["X"]
    // declaredParams: node has empty parent [""] and two children ["int"] ["X"]
    
    if (!strcmp(callParams->token, "args:"))
        callParams = callParams->left;
    
    if (!strcmp(declaredParams->token, "params:"))
        declaredParams = declaredParams->left;
    
    
    if (callParams == NULL || declaredParams == NULL)
        return 0;
    
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
        // if current paramter is null, it must be a const (otherwise will be declared unkown before entering function)
        else if (parameter == NULL){
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

int isSimilarSymbols(char* scopeName, struct symbolNode* root)
{
    /* return 0 if given symbol already exists  */
    symbolNode* s1=root;
    symbolNode* s2=root;
    
    
  while(s1!= NULL){
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


symbolNode* scopeLookup (char* token){
    /* function returns the symbol  if  already declared, otherwise NULL */
    /* inputs: head_ref, the scope from which to start looking, and token = id of symbol */
    struct scopeNode* currentScope = topStack;
    struct symbolNode* result;
    int currentLevel;
    while (currentScope != NULL)
    {  
       currentLevel=currentScope->ScopeLevel;
        result=symbolLookup(&currentScope->symbolTable,token);
        if(result!=NULL)
            return result;
    
        while (currentScope->ScopeLevel > 1 &&  currentScope->ScopeLevel >= currentLevel);
            currentScope = currentScope->next;
    }
    return NULL;
}

symbolNode* symbolLookup (struct symbolNode** head_ref, char* token){
    /* function returns the node of the symbol  if symbol already declared, otherwise NULL */
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
