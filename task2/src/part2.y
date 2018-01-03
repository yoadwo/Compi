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
	int scopeLevel;
	symbolNode *symbolTable;
	struct scopeNode *next;
} scopeNode;


symbolNode* head = NULL;
scopeNode* topStack = NULL;
int SCOPE_NUM=0;

void startSematics(treeNode *root);
symbolNode* scopeLookup (char* token);
char* checkEvaluation(treeNode* tNode);
void printInfo(treeNode *head);
treeNode *mktreeNode (char *token, treeNode *left, treeNode* middle, treeNode *right);
void printtree (treeNode *tree, int tab);
int isCompileErrors(scopeNode *root,treeNode* tNode);
int isSimilarSymbols(char* scopeName, struct symbolNode* root);
int checkDuplicateSymbols(scopeNode* root);
int checkDuplicateProcs(scopeNode *root);
void pushStatements(treeNode* tNode,int scopeLevel);
void pushScopeStatements(treeNode* tNode);
void pushSymbols( char* type,treeNode* tNode);
void pushProcSymbols( treeNode* tNode);
void pushSignatureParamsToTable(scopeNode **currentScope, treeNode *params);
void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params);
void pushScopeToStack(struct scopeNode** head_ref, char* scopeName,treeNode *params, treeNode* statements,int scopeLevel);

void printSymbolTable(struct scopeNode *node);
void printScopes(struct scopeNode *node);

symbolNode* symbolLookup (struct symbolNode** head_ref, char* token);
int isConst(treeNode* tNode);
int isParamsMatch(treeNode* callParams, treeNode* declaredParams/*, struct symbolNode* currentSymTab*/);
int isReturnTypeMatch(treeNode *tNode);


int compareCallDeclare( char *token, treeNode *callParams);
#define YYSTYPE struct treeNode *
%}
%token BOOL, CHAR, INT, STRING, INTPTR, CHARPTR, ID, VOID,QUOTES,NADA
%token IF, ELSE, WHILE, FOR ,DO
%token MAIN,  RETURN
%token BOOLTRUE, BOOLFALSE, CSNULL, INTEGER_POS, INTEGER_NEG, CHAR_CONST, STRING_CONST, HEX_CONST, OCTAL_CONST, BINARY_CONST 
%token ASSIGNMENT,AND,DIVISION,EQUAL,GREATER,GREATEREQUAL,LESS,LESSEQUAL,MINUS,NOT,NOTEQUAL,OR,PLUS,MULTI,ADDRESS,DEREFERENCE,ABSOLUTE,SEMICOLON,COLON,COMMA,LEFTBRACE,RIGHTBRACE,LEFTPAREN,RIGHTPAREN,LEFTBRACKET,RIGHTBRACKET,PERCENT, QUOTES

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right ASSIGNMENT SEMICOLON MAIN NOT
%left LEFTBRACE RIGHTBRACE LEFTPAREN RIGHTPAREN 
%left PLUS MINUS
%left MULTI DIVISION
%left EQUAL GREATER GREATEREQUAL LESSEQUAL LESS NOTEQUAL
%left  AND OR
%start s
%%
s:      global {   startSematics($1);  };
global:  procedures procMain  {$$ = mktreeNode ("global", $1,NULL,$2); }
            | procMain  {$$ = mktreeNode ("global", $1,NULL,NULL); }     ;
       
       
       /*________________________________________________PROCEDURES________________________________________________*/
procedures:    procedures proc {$$ = mktreeNode ("", $1,NULL, $2); }
                | proc    {$$ = mktreeNode ("", $1, NULL,NULL);};
                  
proc:  procValue  | procVoid ; 
procMain: VOID MAIN LEFTPAREN RIGHTPAREN block_return_void_statements { $$ = mktreeNode ("main", $5,NULL, NULL); };
procVoid: procIDVoid LEFTPAREN params RIGHTPAREN  block_return_void_statements {$$ = mktreeNode ("procedure", $1, $3, $5);};
procValue: procIDValue LEFTPAREN params RIGHTPAREN  block_return_value_statements {$$ = mktreeNode ("procedure", $1, $3, $5); };
procIDValue: varType id {$$ = mktreeNode ("procID", $1, NULL, $2); };
procIDVoid: void id {$$ = mktreeNode ("procID", $1, NULL, $2); };



      /*________________________________________________PARAMS DECLARE______________________________________________*/
params: /* no params  */
        | paramsDeclare {$$ = mktreeNode ("params:", $1, NULL, NULL); };
paramsDeclare: param COMMA  paramsDeclare  {$$ = mktreeNode (",", $1, NULL, $3); }   
        | param ;
/* to change tree design\print, toggle between following: 1) [type id] 2) [][type][id] */
/*param: varType id {char *s = " "; s=  strcat ($1->token,s);  $$ = mktreeNode (strcat($1->token,$2->token), NULL, NULL, NULL); }   ;*/
param: varType id {$$ = mktreeNode ("", $1, NULL, $2); }   ;
  
  
       /*______________________________________________EXPR____________________________________________________________*/

        
operator:     operator PLUS operator    {$$ = mktreeNode ("+", $1, NULL, $3); }
        | operator MINUS operator {$$ = mktreeNode ("-", $1, NULL, $3); }
        | operator MULTI operator {$$ = mktreeNode ("*", $1, NULL, $3); }
        | operator DIVISION operator  {$$ = mktreeNode ("/", $1, NULL, $3); }
        | Pexpr PLUS Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }
        | Pexpr MINUS Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }
        | Pexpr MULTI Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }       
        | Pexpr DIVISION Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }
        | operator PLUS Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }
        | operator MINUS Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }
        | operator MULTI Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }       
        | operator DIVISION Pexpr {$$ = mktreeNode ("/", $1, NULL, $3); }
        | Pexpr PLUS operator {$$ = mktreeNode ("/", $1, NULL, $3); }
        | Pexpr MINUS operator {$$ = mktreeNode ("/", $1, NULL, $3); }
        | Pexpr MULTI operator {$$ = mktreeNode ("/", $1, NULL, $3); }       
        | Pexpr DIVISION operator {$$ = mktreeNode ("/", $1, NULL, $3); }
        | address 
        | derefID 
        //| Pexpr
        | consts ;

compBoolExpr:   operator
        | operator EQUAL operator  { $$ = mktreeNode ("==", $1, NULL, $3); }
        | operator GREATER operator  { $$ = mktreeNode (">", $1, NULL, $3); }
        | operator GREATEREQUAL operator { $$ = mktreeNode (">=", $1, NULL, $3); }
        | operator LESS operator { $$ = mktreeNode ("<", $1, NULL, $3); }
        | operator LESSEQUAL operator { $$ = mktreeNode ("<=", $1, NULL, $3); }
        | operator NOTEQUAL operator { $$ = mktreeNode ("!=", $1, NULL, $3); };


expr:  Pexpr  
        | expr AND expr {$$ = mktreeNode ("&&", $1, NULL, $3); }
        | expr OR expr {$$ = mktreeNode ("||", $1, NULL, $3); }
        | NOT expr {$$ = mktreeNode ("NOT", $1, NULL, NULL); }
        | compBoolExpr;
        
        
        /*______________________________________________________BLOCKS_____________________________________________________*/

Pexpr:  LEFTPAREN expr rightParen {$$ = mktreeNode ("(", $2, NULL, $3); };
rightParen: RIGHTPAREN {$$ = mktreeNode (")", NULL, NULL, NULL); };
block_return_value_statements: LEFTBRACE newline return SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, $3, $5); }
            | LEFTBRACE return SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", NULL, $2, $4); };
block_return_void_statements :   emptyBlock 
            | LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, $3, $5); }
            | LEFTBRACE newline SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $4); };


return: RETURN expr {$$ = mktreeNode ("RETURN", $2, NULL, NULL);}
        | RETURN {$$ = mktreeNode ("RETURN", NULL, NULL, NULL);};
            
emptyBlock: LEFTBRACE rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, NULL);}
            | LEFTBRACE RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", NULL, NULL, $4); };
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
consts: id | numbers | booleans | csnull | strings |chars | procCall | absolute ;

absolute: ABSOLUTE id ABSOLUTE {$$ = mktreeNode ("ABS",mktreeNode("integer", NULL,NULL,NULL),$2,mktreeNode("pos",NULL,NULL,NULL));};

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

procCall: id LEFTPAREN args RIGHTPAREN {$$ = mktreeNode ("func call", $1, NULL, $3); }; 

args: argsDeclare {$$ = mktreeNode ("args:", $1, NULL, NULL); };
argsDeclare: expr COMMA  argsDeclare  {$$ = mktreeNode (",", $1, NULL, $3); }   
        | expr ;

address : ADDRESS id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("&")+1); strcat (s,"&"); strcat(s,t); 
                            $$ = mktreeNode (s,NULL, NULL, NULL); };        
        
              /*_________________________________________________________________________________________________________*/
derefID: DEREFERENCE id  {char* t = $2->token; char *s = malloc(strlen(t)+strlen("^")+1); strcat (s,"^"); strcat(s,t); $$ = mktreeNode (s,NULL, NULL, NULL); } ;

                                                
/*_______________________________________________________BLOCK_BODY_STRUCTURE_________________________________________*/

newline:  
        declarations newline   {$$ = mktreeNode ("", $1, NULL,$2); }
                    | SEMICOLON
           | statements  
           | declarations ;
           
declarations:  
             variable_declare_statements SEMICOLON;
            //| SEMICOLON; //no integer can be declared with type first

            
            /*_________________________________________________________STATEMENTS___________________________________________________*/
statements: statement statements {$$ = mktreeNode ("STATEMENT", $1, NULL,$2); }
            | statement {$$ = mktreeNode ("STATEMENT", $1, NULL,NULL); }
            | block_statements statements  {$$ = mktreeNode ("NESTED", $1, NULL,$2);}
            | block_statements {$$ = mktreeNode ("NESTED", $1, NULL,NULL);};

statement: 
             IF_statements 
            | LOOP_statements  
            | proc
            | procCall SEMICOLON
            | ASSIGNMENT_statement SEMICOLON;


statements_type: statement
                 |block_statements;

block_statements: emptyBlock
            | LEFTBRACE newline rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $3);};
            //| LEFTBRACE newline RETURN SEMICOLON rightbrace {$$ = mktreeNode ("(BLOCK", $2, NULL, $4);};  //why is this working?? enables any block to end with RETURN
            
                 /*_______________________________________CONDITIONAL_STATEMENTS___________________________________*/ 
IF_statements: IF cond statements_type {$$ = mktreeNode ("IF", $2,$3,NULL); } %prec LOWER_THAN_ELSE
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



preCondition: /* empty *//* |  expr*/ | ASSIGNMENT_statement;
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
            | INTPTR        {$$ = mktreeNode ("intp", NULL, NULL, NULL); }
            | CHARPTR    {$$ = mktreeNode ("charp", NULL, NULL, NULL); };
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

/* START SEMANTICS:  
    start top down creation and semantics check of tree created by grammar rules
    */
void startSematics(treeNode *root){
      
    // create a stack of scopes, each one has its own list of symbols (symbol table)
    pushStatements(root, 1);
    // print scopes, symbol tables and concrete syntax tree
    // check for duplicate symbols, calls for non existing symbols and type checking
    if (!isCompileErrors(topStack,root))
        printf ("build failed, check compile errors\n");
    printInfo(root);
    
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

/*  IS COMPILE ERRORS
    return 1 if all checks pass, otherwise 0;
    */

    
    // perform all checks, accumulate results and return final test result
int isCompileErrors(scopeNode *root,treeNode* tNode){
    // return 1 if all checks pass, otherwise 0;
    int pass = 1;
    pass = pass && checkDuplicateSymbols(root);
    return pass;
}

/* IS DECLARED
    functions checks if used symbol was indeed declared earlier
    */
int isDeclared(treeNode *tNode){
    // bad cases: "procedure", '('
    if (!strcmp(tNode->token, ")"))
        return 1;
    if (!strcmp(tNode->token, "procedure"))
        return 1;
    
        
    //base 1: node has no children -> node is identifier, do scope lookup
    if (tNode->left == NULL && tNode->middle == NULL  && tNode->right == NULL ){
        // ')' can also be seen as a leaf
        char sign = (tNode->token)[0];
        if (sign == '&' || sign == '^'){
            if (sizeof tNode->token == 2){
                char* id;
                id[0] = (tNode->token)[1];
                symbolNode *symbol =  scopeLookup(id);
                if (symbol == NULL){
                    printf ("undefined variable [%s]\n", tNode->token); //add scope
                    return 0;
                    }
                else
                    return 1;
            }
            else{
                char* id = (char*)(malloc (sizeof(tNode->token) + 1));
                //copy tNode->token from [1] to end into id
                int i = 1;
                for (i; i < sizeof((tNode->token)-1); i++){
                    id[i-1] = tNode->token[i];
                    }
                symbolNode *symbol =  scopeLookup(id);
                if (symbol == NULL){
                    printf ("undefined variable [%s]\n", tNode->token); //add scope
                    return 0;
                    }
                else
                    return 1;
                }
        }
        symbolNode *symbol =  scopeLookup(tNode->token);
        if (symbol == NULL){
            printf ("undefined variable [%s]\n", tNode->token); //add scope
            return 0;
            }
        else
            return 1;
        }
    //base 2: node has children -> node is ABS (identifier), do scope lookup
    if (!strcmp(tNode->token,"ABS")){
        symbolNode *symbol =  scopeLookup(tNode->middle->token);
        if (symbol == NULL){
            printf ("undefined variable [%s]\n", tNode->middle->token); //add scope
                return 0;
                    }
                else
                    return 1;
    }
            
    //base 3: node is const
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
    return result;
    
}

/*  CHECK DUPLICATE SYMBOLS
    check if two symbols were declared in same scope 
*/
int checkDuplicateSymbols(scopeNode* root){
    struct scopeNode * currentScope=root;
    // iterate all scopes
    while(currentScope!=NULL){
        //only check if within one scope, some symbol exists twices
        if(!isSimilarSymbols(currentScope->scopeName, currentScope->symbolTable))
            return 0;
        currentScope=currentScope->next;
    }
    // if all scopes pass, return 1
    return 1;
}

/*  COMPARE CALL DECLARE
    check ALL scopes, each symbol table in scope, if there exists any function's' params that match the called function's' params  
    function return 1 if some function with matching signature exists, 0 otherwise 
*/ 
int compareCallDeclare(char *token, treeNode *callParams){
    // var currentScope iterates all scopes
    // var currentSymtab iterates symbols in current scope (root)
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


char* checkEvaluation(treeNode* tNode){
    
    if (isConst(tNode)){
        return (tNode->left->token);
    }
    
    /*else if the node is variable (we will look for him in symbol table)*/
    else if(!isConst(tNode) && tNode->left == NULL && tNode->middle == NULL && tNode->right == NULL){
        char* varType;
        symbolNode* node;
        node=scopeLookup(tNode->token);
        if(node!=NULL){
            varType=node->type;
            return varType;
        }
        else
            return "null";
    }

    
    if(!strcmp(tNode->token,"+")||!strcmp(tNode->token,"-")||!strcmp(tNode->token,"*")||!strcmp(tNode->token,"/")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "integer";
        
        else {
            if (strcmp(right, "expressionError") && strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }
    }
    if(!strcmp(tNode->token,">")||!strcmp(tNode->token,"<")||!strcmp(tNode->token,">=")||!strcmp(tNode->token,"<=")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "boolean";
        
        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }
    
    }
    if(!strcmp(tNode->token,"&&")||!strcmp(tNode->token,"||")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"boolean")&&!strcmp(right,"boolean"))
            return "boolean";
        
        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }

    }
    if(!strcmp(tNode->token,"==")||!strcmp(tNode->token,"!=")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"boolean")&&!strcmp(right,"boolean"))
            return "boolean";
            
        else if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "boolean";
            
        else if(!strcmp(left,"intp")&&!strcmp(right,"intp"))
            return "boolean";  
            
        else if(!strcmp(left,"char")&&!strcmp(right,"char"))
            return "boolean";
            
        else if(!strcmp(left,"charp")&&!strcmp(right,"charp"))
            return "boolean";     
            

        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }

    }
    
    if(!strcmp(tNode->token,"=")){
        char* left, *right;
        left=checkEvaluation(tNode->left);
        right=checkEvaluation(tNode->right);
        if(!strcmp(left,"boolean")&&!strcmp(right,"boolean"))
            return "boolean";
            
        else if(!strcmp(left,"integer")&&!strcmp(right,"integer"))
            return "integer";
            
        else if(!strcmp(left,"intp")&&!strcmp(right,"intp"))
            return "intp";  
            
        else if(!strcmp(left,"char")&&!strcmp(right,"char"))
            return "char";
            
        else if(!strcmp(left,"charp")&&!strcmp(right,"charp"))
            return "charp";     
            

        else {
            if (strcmp(right, "expressionError") || strcmp(right, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s, type right:%s\n",tNode->token,left,right);
            return "expressionError";
        }

    }

    if(!strcmp(tNode->token,"NOT")){

        char*  left;
        left=checkEvaluation(tNode->left);
        if(!strcmp(left,"boolean"))
            return "boolean";

        else {
            if (strcmp(left, "expressionError"))
                printf("expressionError: type mismatch in %s, type left: %s\n",tNode->token,left);
            return "expressionError";
        }
    }
    
    if (!strcmp(tNode->token,"(")){
        char* left;
        left = checkEvaluation(tNode->left);
        return left;
    }
    
    if (tNode->left != NULL){
        checkEvaluation(tNode->left);
    }
    if (tNode->middle != NULL){
        checkEvaluation(tNode->middle);
    }
    if (tNode->right != NULL){
        checkEvaluation(tNode->right);
    }
}


/* PUSH STATEMENTS
    iterates all statements. statements that should open a new scope also call "push scope to stack"
    else, recursive call to all statements children
*/
void pushStatements(treeNode* tNode,int scopeLevel){
    if(tNode==NULL)
        return;
    //int scopeID=0;
    // struct scopeNode* currentStack;
    // currentStack= (struct scopeNode*) malloc(sizeof(struct scopeNode));
    // memcpy(&currentStack,&topStack,sizeof(topStack));
    if(!strcmp(tNode->token,"IF")){
        scopeLevel++;
        pushScopeToStack(&topStack, "IF",NULL, tNode->middle,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"ELSE")){
        scopeLevel++;
        pushScopeToStack(&topStack, "ELSE",NULL, tNode->left,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"while")){
        scopeLevel++;
        pushScopeToStack(&topStack,"while",NULL, tNode->right,scopeLevel);
        //  return;
    }
    if(!strcmp(tNode->token,"do-while")){
        scopeLevel++;
        pushScopeToStack(&topStack, "do-while",NULL, tNode->left,scopeLevel);
        // return;
    }
    
    if(!strcmp(tNode->token,"BLOCK")){
        pushStatements(tNode->left,scopeLevel);
    }
    
    if(!strcmp(tNode->token,"for")){
        scopeLevel++;
        pushScopeToStack(&topStack, "for",NULL, tNode->right,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"procedure")){
        //pushProcSymbols(tNode);
        scopeLevel++;
        pushScopeToStack(&topStack,"procedure",tNode->middle, tNode->right,scopeLevel);
        isReturnTypeMatch(tNode);
        //return;
    }
    if(!strcmp(tNode->token,"NESTED")){
        //pushProcSymbols(tNode);
        scopeLevel++;
        pushScopeToStack(&topStack,"NESTED",NULL, tNode->left,scopeLevel);
        //return;
    }
    if(!strcmp(tNode->token,"main")){
        scopeLevel++;
        pushScopeToStack(&topStack, "main",NULL, tNode->left->left,scopeLevel);
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

/*  PUSH SCOPE STATEMENTES
    
    
*/
void pushScopeStatements(treeNode* tNode){
    if(tNode==NULL)
        return;
    
    /*
    for any of the following statements, we do not want to explore them recursively
    so we return upon seeing them
    */
    if(!strcmp(tNode->token,"ELSE")){
        return;
    }
    if (!strcmp(tNode->token, "NESTED")){
        return;
    }
    if(!strcmp(tNode->token,"while")){
     if(!strcmp(tNode->left->token,"(COND")){
        if(strcmp(checkEvaluation(tNode->left->left),"boolean"))
            printf("Type mismatch: while condition dosn't match type boolean\n");
    }
        return;
    }
    if(!strcmp(tNode->token,"IF")){
     if(!strcmp(tNode->left->token,"(COND")){
        if(strcmp(checkEvaluation(tNode->left->left),"boolean"))
            printf("Type mismatch: IF condition dosn't match type boolean\n");
    }
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
   
    
                                            
    
    if(!strcmp(tNode->token,"DECLARE")){
        pushSymbols(tNode->left->token,tNode->right);
        //YYERROR;
        return;
    }
    
     if (!strcmp(tNode->token, "func call")){
        compareCallDeclare( tNode->left->token, tNode->right);      
    }
    
     if (!strcmp(tNode->token, "STATEMENT")){
        int check;
        if (!strcmp(tNode->left->token, "IF")){
            check = isDeclared(tNode->left->left->left);
            if (check){
                //checkEvaluation(tNode);
                checkEvaluation(tNode->left->left->left);
            }
        }
        else if (!strcmp(tNode->left->token, "=")){
            check = isDeclared(tNode->left);
            if (check){
                char *left = scopeLookup(tNode->left->left->token)->type;
                char *right = checkEvaluation(tNode->left->right);
                if (strcmp(right,left))
                    printf("Assignment Error mismatch: cannot assign %s to %s (identifier %s)\n", right, left, tNode->left->left->token);
                
            }
        }
        else if ((!strcmp(tNode->left->token, "for"))){
            check = isDeclared(tNode->left->left);
            if (check){
                checkEvaluation(tNode->left->left->left);
                checkEvaluation(tNode->left->left->middle);
                checkEvaluation(tNode->left->left->right);
            }
        }
        else if(!strcmp(tNode->left->token, "while")){
            check = isDeclared(tNode->left->left->left);
            if (check){
                checkEvaluation(tNode->left->left->left);
            }
        }
    }
    
    pushScopeStatements(tNode->left);
    pushScopeStatements(tNode->middle);
    pushScopeStatements(tNode->right);
    
}
    
/*  PUSH SYMBOLS
    following a DECLARE node (<type> <id1>, <id2>...) push all symbols under same type
    base cases are  1) seeing an id with a value, 2) without value
*/
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

/* PUSH PROCEDURE SYMBOLS 
    wrapper function to add procedures to symbol table */
/* pass on to "push" with value "1" to identify it as a fucntion   */
void pushProcSymbols(treeNode* tNode)
{
   /* symbolNode* head = (*head_ref)->symbolTable;*/
    //params is tNode->middle;
    int isProc = 1;
                                        //scope,    , id,                                       , type,                                 data,                       params
    pushSymbolsToTable(&topStack, tNode->left->right->token, tNode->left->left->token, "function",isProc, tNode->middle);
}

/* 
PUSH SYMBOLS TO SYMBOL LIST (TABLE)
Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. 
*/
void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params)
{
        //malloc a new block
	struct symbolNode* new_node = (struct symbolNode*) malloc(sizeof(struct symbolNode));
	
	new_node->isProc = isProc;
	
	//malloc string in block
	new_node->id = (char*)(malloc (sizeof(id) + 1));
	strncpy(new_node->id, id, sizeof(id)+1);
	
	//malloc data in block
	if (new_data != NULL)
	{
            new_node->data = (char*)(malloc (sizeof(new_data) + 1));
            strncpy(new_node->data, new_data, sizeof(new_data)+1);
	}
	new_node->type = (char*)(malloc (sizeof(type) + 1));
	strncpy(new_node->type, type, sizeof(type)+1);
	
	//scopeNum or scopeLevel?
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
            
        //make new block the new head, and previous head now points to it
	new_node->next =(*node)->symbolTable;
	(*node)->symbolTable = new_node;
}
/*  PUSH SCOPE TO STACK
    given a scope name and paramters, append it to the scopes stack
    each scope has a scope level, which matches its "father" scope

*/
void pushScopeToStack(struct scopeNode** head_ref, char* scopeName,treeNode* params, treeNode* statements ,int scopeLevel)
{     /*declare shouldn't get here*/  
      if(strcmp(scopeName,"DECLARE")){
        
            // malloc new block
            struct scopeNode* new_scope = (struct scopeNode*) malloc(sizeof(struct scopeNode));
        
            //malloc new id
            new_scope->scopeName = (char*)(malloc (sizeof(scopeName) + 1));
            strncpy(new_scope->scopeName, scopeName, sizeof(scopeName)+1);
	
            // update total number of scope
            SCOPE_NUM++;
            // bind scope number and level
            new_scope->scopeNum=SCOPE_NUM;
            new_scope->scopeLevel=scopeLevel-1;
        
            // if functions had any parameters, push them to its symbol table
            if (params){
                pushSignatureParamsToTable(&new_scope, params);
            }
            
            // make new block the new head, and previous head now points to it
            new_scope->next = (*head_ref);
            (*head_ref) = new_scope;
            }
	
	pushScopeStatements(statements);
}

/* PUSH SIGNATURE PARAMS TO TABLE
    push paramters of procedure to its symbol table
    works recursively, base case is found "" and its children are name and type
*/
void pushSignatureParamsToTable(scopeNode **currentScope, treeNode *params){
        // reached non existing leaf
        if (!params){
            return;
        }
//void pushSymbolsToTable(struct scopeNode** node, char* id, char* type, char* new_data, int isProc, treeNode *params)
    /* node is an ID */
        if (!strcmp(params->token,"")){
            pushSymbolsToTable(currentScope,params->right->token,params->left->token,NULL, 0, NULL);
            return;
            }
        pushSignatureParamsToTable(currentScope, params->left);
        pushSignatureParamsToTable(currentScope, params->right);
}

/*  DELETE SYMBOL NODE
Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position 
*/
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

/*  IS NUMERIC
    return 1 if token is a number, 0 otherwise (any of its digits is not in [0-9])
*/
int isNumeric(char* token){
    int len = strlen(token), i;
    //check if every char in the string is a digit
    for (i = 0; i<len; i++){
        if ( !isdigit(token[i]))
            return 0;
    }
    return 1;
}

/*  IS CONST
    check if a given token is in [ booleans | csnull |  numbers | strings | chars ]
*/
int isConst(treeNode* tNode){
    /*check if id */
    if (tNode->left == NULL)
        return 0;
    else if (!strcmp(tNode->left->token, "boolean"))
        return 1;
    else if (!strcmp(tNode->token, "null"))
        return 1;
    else if (!strcmp(tNode->left->token, "integer"))
        return 1;
    else if (!strcmp(tNode->left->token, "charp"))
        return 1;
    else if (!strcmp(tNode->left->token, "char"))
        return 1;
    else if (!strcmp(tNode->token, "ABS"))
        return 1;
    //possibly unnecessary due to left token holding type data
    else if (isNumeric(tNode->token))
        return 1;
    return 0;
              
}

/* IS PARAMS MATCH
    compare callParams and declaredParams trees 
    callParams: node has token value and no childs ["X"]
    declaredParams: node has empty parent [""] and two children ["int"] ["X"]
*/
int isParamsMatch(treeNode* callParams, treeNode* declaredParams/*, struct symbolNode* currentSymTab*/)
{

    // fail if empty node
    if (callParams == NULL || declaredParams == NULL)
        return 0;
    
    //token begins as "args", skip it
    if (!strcmp(callParams->token, "args:"))
        callParams = callParams->left;
    //token begins as "params", skip it
    if (!strcmp(declaredParams->token, "params:"))
        declaredParams = declaredParams->left;
    
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
        // if current paramter is null, it was either undeclared or a  const (otherwise will be declared unkown before entering function
        else if (parameter == NULL){
            // current callParam was undeclared, return 0
            if (callParams->left == NULL && callParams->right == NULL)
                return 0;
            // then it is a const
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

/* IS RETURN TYPE MATCH
    function is called only AFTER function is added to scope\symbol symbolTable
    evaluate the type of returned expression and compare it to declare procedure type
*/
int isReturnTypeMatch(treeNode *tNode){
    char *procType = tNode->left->left->token;
    char *returnedType;
    
    // if proctype is void and not exists return -> pass
    if (!strcmp(procType,"void") && tNode->right->middle == NULL)
        return 1;
    //if proctype is void and exists return and has no left child -> pass
    else if (!strcmp(procType,"void") && tNode->right->middle->left == NULL)
        return 1;
    //if proctype is void and exists return and return has left child -> fail
    else if (!strcmp(procType,"void") && tNode->right->middle->left != NULL){
        printf ("A void function (%s) cannot return a value\n", tNode->left->right->token);
        return 0;
    }
    returnedType = checkEvaluation(tNode->right->middle->left);
    if (!strcmp(returnedType,"expressionError")){
        printf("One or more variables in function return expression were used before defined (%s)\n", tNode->left->right->token);
        return 0;
    }
    // if proctype is NOT void and exists return and proctype == return type -> pass
     if (strcmp(procType,"void") &&  !strcmp(procType, returnedType))
        return 1;
    // if proctype is NOT void and exists return and proctype != return type -> fail
    else if (strcmp(procType,"void") && strcmp(returnedType,"null") &&  strcmp(procType, returnedType)){
        printf ("Function %s return value (%s) does not match returned expression\'s value (%s)\n", tNode->left->right->token,procType, returnedType);
        return 0;
    }
    // if proctype is NOT void and exists return and return has no left child-> fail
    else if (strcmp(procType,"void") && tNode->right->middle->left == NULL ){
        printf ("Function return value (%s) must return matching value\n", procType);
        return 0;
    }
    
}

/* IS SIMILAR SYMBOLS
    return 0 if given symbol already exists twice in given scope
*/
int isSimilarSymbols(char* scopeName, struct symbolNode* root)
{
    
    symbolNode* s1=root;
    symbolNode* s2;
    
    // for symbol s1 against any other symbol s2
  while(s1!= NULL){
        s2 = s1;
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

/*  SCOPE LOOKUP
 function returns the symbol  if  already declared, otherwise NULL 
 inputs: head_ref, the scope from which to start looking, and token = id of symbol 
*/
symbolNode* scopeLookup (char* token){
    // var currentScope iterates all scopes
    // var currentLevel only iterates scopes that are bound to father scope
    struct scopeNode* currentScope = topStack;
    struct symbolNode* result;
    int currentLevel;
    while (currentScope != NULL)
    {  
       currentLevel=currentScope->scopeLevel;
        result=symbolLookup(&currentScope->symbolTable,token);
        // found some symbol
        // result may be null - because does not exist in current scope
        // however it may still exist in other scopes, so we do not fail lookup yet
        if(result!=NULL)
            return result;
        // if reached top level, variable was not found
          if(currentLevel==1)
            return NULL;
          
        while (currentScope->scopeLevel > 1 &&  currentScope->scopeLevel >= currentLevel)
            currentScope = currentScope->next;
    }
    return NULL;
}

/*  SYMBOL LOOKUP
     function returns the node of the symbol  if symbol declared, otherwise NULL 
     only check within one scope (not specified as argument, but head_ref is head of symtab in it)
*/
symbolNode* symbolLookup (struct symbolNode** head_ref, char* token){
    
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

void printInfo(treeNode *root){
    printf ("Syntax Tree:\n"); 
    
    /*printf("print symbol table:\n");
    printSymbolTable(topStack);
    printf("\n"); */
    /*
    printf("print scopes:\n");
    printScopes(topStack);
    printf("\n"); */

    printtree (root,0);
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
		printf("scope id:{%s} scopeNum:{%d} scopeLevel:{%d}\n", current->scopeName,current->scopeNum,current->scopeLevel);
		current = current->next;
	}
    printf("num of scopes:{%d}\n",SCOPE_NUM);
	
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
