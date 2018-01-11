%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
int checkExist(char * name);	//check if name can be defined as var~
int checkNameExists(char * name);	//check if name is in symboltable so we can reach him~
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
char* freshVar(char *type); 
int get_int_len();
void CallProcedureParasTreat(char * proName,node * paras);
void checkFuncParam(char * proName,node * paras,node * nameAndParas);
symbolTable* reverseST(symbolTable * st);
symbolTable* dupST(char * proName,symbolTable * st);
void UpdateParameterType(node * tempTree);
void addProcedureParametersToST(char * proName,node * paras);
static symbolTable * current;
static symbolTable * procedureParas; 
static labelStruct * labelHead;
static char * currentReturnType;
char * freshLabel();
void ConditionTreatment(node * condition);
void SwapSides(node * condition);
void MakeIfIntoIfZ(node * condition,char * nextLabel, char * elseLabel);
void InsertLabelsIntoCondition(node * condition,char * thenLabel,char * nextLabel, char * elseLabel);
int ThereisAND(node * condition);
void _3ACForAssignment(node * tree);
void _3ACMain(node * tree);
void TAC_PrintCode(node * tree);
void TAC_FillCode(node * tree); 
char * _3ACForOperations(node * tree);
int _3ACForProcedureParameters(node * tree);
char* _3ACForProcedureActivate(node * tree);
void _3ACForProcedureDefine(node * tree);
void _3ACForReturn(node * tree);
int numberOfBytes (char *type); 
void _3ACForVar(node * tree); 
int countNumberOfParameters(node *tree); 
void deleteNameOfParameters(int numberOfParametersToDelete); 
char* _3ACString(node* tree);
void recursivePrint(node* tree);
void checkIfConditionTypeIsBoolean(node *cond); 
void printFixedCode();
void buildLabelStruct();
//void checkIDForCond(node * forCond);
//#define YYDEBUG 1 
int yylex();
int yyerror();
char *yytext;
//int yydebug=1;

%}

%union 
{
struct
    {
	char* type;
	char* string;
	node* tree;
    }IST;
}

%token BOOLEAN CONST_BOOLEAN CHAR INTEGER STRING VOID //Types
%token INTPTR CHARPTR //PtrTypes
%token IF ELSE WHILE FOR //condition and loop
%token VAR ASSIGN
%token EQ GT GE LT LE NE NOT //comparison
%token MINUS PLUS MUL DIVISION //operators
%token ADDRESS VAL_POINTER AMPERSAND VALUE_ADDRESS ARRAY PROCEDURE RETURN NIL AND OR VBAR CHAR_CONST BINARY OCTAL INTEGER_CONST STRING_CONST SEMICOLON COLON SEPERATOR START_BLOCK_OF_CODE END_BLOCK_OF_CODE BEGIN_PARAMETER_LIST END_PARAMETER_LIST  BEGIN_STRING_INDEX END_STRING_INDEX IDENTIFIER HEXADECIMAL ERR //COMMENT
%left PLUS MINUS DIVISION MUL START_BLOCK_OF_CODE END_BLOCK_OF_CODE  BEGIN_PARAMETER_LIST END_PARAMETER_LIST BEGIN_STRING_INDEX END_STRING_INDEX EQUAL LT LE NE NOT
%right ELSE

%%


S:Start {buildST($<IST.tree>1); printtree($<IST.tree>1);
if (isMain != 0) printST(); else printf("Cannot find Main() function! Error!\n");
_3ACMain($<IST.tree>1); TAC_FillCode($<IST.tree>1); strcat(codebuffer,"\0"); //printf("%s\n",codebuffer); //TAC_PrintCode($<IST.tree>1);
buildLabelStruct(); printFixedCode();
};


Start: Procedure Start {$<IST.tree>$=mknode("BLOCK","BLOCK",$<IST.tree>1,$<IST.tree>2);}
//| COMMENT Start {$<IST.tree>$=mknode("COMMENT","COMMENT", mknode($<IST.string>1,$<IST.type>1, NULL,NULL), $<IST.tree>2);}
| {$<IST.tree>$=NULL;};

// ProcedureSignature ProcedureBlock {$<IST.tree>$=mknode("procedure","procedure",$<IST.tree>1,$<IST.tree>2);};

Procedure: ProcVoid | ProcValue;
ProcVoid: VoidProcedureSignature VoidProcedureBlock {$<IST.tree>$=mknode("procedure","procedure",$<IST.tree>1,$<IST.tree>2);};
ProcValue: ProcedureSignature ProcedureBlock {$<IST.tree>$=mknode("procedure","procedure",$<IST.tree>1,$<IST.tree>2);};

ProcedureBlock: START_BLOCK_OF_CODE Block Return END_BLOCK_OF_CODE {$<IST.tree>$=mknode("","",$<IST.tree>2,$<IST.tree>3);};
VoidProcedureBlock: START_BLOCK_OF_CODE Block VoidReturn END_BLOCK_OF_CODE {$<IST.tree>$=mknode("","",$<IST.tree>2,$<IST.tree>3);};

Block:Define Block {$<IST.tree>$=mknode("NewRow","NewRow",$<IST.tree>1,$<IST.tree>2);}
|Assignment SEMICOLON Block {$<IST.tree>$=mknode("NewRow","NewRow",$<IST.tree>1,$<IST.tree>3);}
|Procedure Block {$<IST.tree>$=mknode("NewRow","NewRow",$<IST.tree>1,$<IST.tree>2);}
|Loop Block {$<IST.tree>$=mknode("NewRow","NewRow",$<IST.tree>1,$<IST.tree>2);}
|If Block{$<IST.tree>$=mknode("NewRow","NewRow",$<IST.tree>1,$<IST.tree>2);}
|For Block{$<IST.tree>$=mknode("NewRow","NewRow",$<IST.tree>1,$<IST.tree>2);}
//|COMMENT Block {$<IST.tree>$=mknode("COMMENT","COMMENT", mknode($<IST.string>1,$<IST.type>1, NULL,NULL), $<IST.tree>2);}
|START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE Block {$<IST.tree>$=mknode("NewBlock","NewBlock",mknode("NewRow","NewRow",$<IST.tree>2, mknode("EndBlock","EndBlock",NULL,NULL)), $<IST.tree>4);}
| {$<IST.tree>$=NULL;};

ProcedureSignature: Types ID BEGIN_PARAMETER_LIST Parameters END_PARAMETER_LIST  {
char * e=strchr($<IST.string>$,'_');
if(e!=NULL && (int)(e-$<IST.string>1)==0)
{
	yyerror("syntax error");
	YYERROR;
}
$<IST.tree>$=mknode($<IST.string>2,"procedure",$<IST.tree>4,mknode("return","return",$<IST.tree>1,NULL));};

VoidProcedureSignature: TypeVoid ID BEGIN_PARAMETER_LIST Parameters END_PARAMETER_LIST  {
char * e=strchr($<IST.string>$,'_');
if(e!=NULL && (int)(e-$<IST.string>1)==0)
{
	yyerror("syntax error");
	YYERROR;
}
$<IST.tree>$=mknode($<IST.string>2,"procedure",$<IST.tree>4,mknode("return","return",$<IST.tree>1,NULL));};

Parameters: SomeParameters IDENTIFIER  {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,NULL);}
| SomeParameters IDENTIFIER SEPERATOR Parameters {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>4);}
|{$<IST.tree>$=NULL;}
|IDENTIFIER StringParameter {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>2,NULL);};

StringParameter: ArrayType {$<IST.tree>$ = $<IST.tree>1;};

SomeParameters: SEPERATOR IDENTIFIER SomeParameters {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>3,NULL);}
| Types {$<IST.tree>$=mknode(":",":",$<IST.tree>1,NULL);};

Types: BOOLEAN {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 ,NULL,NULL);}
|CHAR {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 ,NULL,NULL);}
|INTEGER {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 ,NULL,NULL);}
//|VOID {$<IST.tree>$ = mknode("integer","int" ,NULL,NULL);}
|STRING {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1, NULL,NULL);}
|PtrTypes {$<IST.tree>$ = $<IST.tree>1;}
|ArrayType {$<IST.tree>$ = $<IST.tree>1;};

TypeVoid: VOID {$<IST.tree>$ = mknode("void","void" ,NULL,NULL);};

PtrTypes:INTPTR {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 ,NULL,NULL);}
|CHARPTR {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 ,NULL,NULL);};

ArrayType:STRING BEGIN_STRING_INDEX INTEGER_CONST END_STRING_INDEX {$<IST.tree>$ = mknode("string[]","string[]", mknode($<IST.string>3,$<IST.type>3,NULL, NULL), NULL);};

CONST_INT: INTEGER_CONST {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1, NULL,NULL);}
|BINARY {$<IST.tree>$ = mknode(binToDec($<IST.string>1),$<IST.type>1, NULL,NULL);}
|OCTAL {$<IST.tree>$ = mknode(octalToDec($<IST.string>1),$<IST.type>1, NULL,NULL);}
|HEXADECIMAL {$<IST.tree>$ = mknode(HexaToDec($<IST.string>1),$<IST.type>1, NULL,NULL);};

E: T {$<IST.tree>$ = $<IST.tree>1;}
|E PLUS T {$<IST.tree>$ = mknode("+","+", $<IST.tree>1,$<IST.tree>3);}
| E MINUS T {$<IST.tree>$ = mknode("-","-", $<IST.tree>1,$<IST.tree>3);};


T: F {$<IST.tree>$ = $<IST.tree>1;}
|T MUL F {$<IST.tree>$ = mknode("*","*", $<IST.tree>1,$<IST.tree>3);}
|T DIVISION F {$<IST.tree>$ = mknode("/","/", $<IST.tree>1,$<IST.tree>3);};

F: BEGIN_PARAMETER_LIST E END_PARAMETER_LIST {$<IST.tree>$ = $<IST.tree>2;}
|ID {$<IST.tree>$ = $<IST.tree>1;}
|CONST_INT {$<IST.tree>$ = $<IST.tree>1;}
|Absolute {$<IST.tree>$ = $<IST.tree>1;}
|StringLenth {$<IST.tree>$ = $<IST.tree>1;};



//AddressID: AMPERSAND IDENTIFIER {$<IST.tree>$ = mknode(strcat($<IST.string>1,$<IST.string>2), strcat($<IST.type>1,$<IST.type>2),NULL,NULL);}
//|AMPERSAND BEGIN_PARAMETER_LIST IDENTIFIER END_PARAMETER_LIST {$<IST.tree>$ = mknode(strcat($<IST.string>1,$<IST.string>3),strcat($<IST.type>1,$<IST.type>3), NULL,NULL);}; 

AddressID: AMPERSAND ID {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 , $<IST.tree>2,NULL);};

ValueAddressID: VALUE_ADDRESS E {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 , $<IST.tree>2,NULL);};


//Assignment:ID ASSIGN E SEMICOLON {$<IST.tree>$=mknode("=","=",$<IST.tree>1,$<IST.tree>3);}
//|ID ASSIGN AddressID SEMICOLON {$<IST.tree>$=mknode("=","=",$<IST.tree>1,$<IST.tree>3);} 
//|ID ASSIGN ID BEGIN_PARAMETER_LIST EmptyOrPara END_PARAMETER_LIST SEMICOLON {$<IST.tree>$=mknode("=","=",$<IST.tree>1,mknode($<IST.tree>3->token,$<IST.tree>3->type, $<IST.tree>5,NULL));
//if($<IST.tree>$->right->constType != NULL)
//free($<IST.tree>$->right->constType);
//$<IST.tree>$->right->constType = strdup("procedure");
//}

//|ID ASSIGN Consts SEMICOLON{$<IST.tree>$=mknode("=","=",$<IST.tree>1,$<IST.tree>3);}
//|ID Array ASSIGN IndexedAssign SEMICOLON {$<IST.tree>$ = mknode("=","=", mknode("[]","[]", $<IST.tree>1, $<IST.tree>2), $<IST.tree>4);}
//|ID ASSIGN AddressID Array SEMICOLON {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, mknode("[]","[]", $<IST.tree>3, $<IST.tree>4));} /* ( x = &arr[2]; )*/
//|ID ASSIGN ValueAddressID SEMICOLON {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, $<IST.tree>3);} /*( z = ^(x-5); )*/
//|ValueAddressID ASSIGN E SEMICOLON {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, $<IST.tree>3);}
//|ValueAddressID ASSIGN CHAR_CONST SEMICOLON {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, $<IST.tree>3);}
//|ID ASSIGN NIL SEMICOLON {$<IST.tree>$ = mknode("=","=" ,$<IST.tree>1, mknode($<IST.string>3,$<IST.type>3 , NULL,NULL));}
//|ID ASSIGN LogicOp SEMICOLON {$<IST.tree>$ = mknode("=","=" ,$<IST.tree>1,$<IST.tree>3);};

Assignment:ID ASSIGN E  {$<IST.tree>$=mknode("=","=",$<IST.tree>1,$<IST.tree>3);}
|ID ASSIGN AddressID  {$<IST.tree>$=mknode("=","=",$<IST.tree>1,$<IST.tree>3);} 
|ID ASSIGN ID BEGIN_PARAMETER_LIST EmptyOrPara END_PARAMETER_LIST  {$<IST.tree>$=mknode("=","=",$<IST.tree>1,mknode($<IST.tree>3->token,$<IST.tree>3->type, $<IST.tree>5,NULL));
if($<IST.tree>$->right->constType != NULL)
free($<IST.tree>$->right->constType);
$<IST.tree>$->right->constType = strdup("procedure");
}

|ID ASSIGN Consts {$<IST.tree>$=mknode("=","=",$<IST.tree>1,$<IST.tree>3);}
|ID Array ASSIGN IndexedAssign  {$<IST.tree>$ = mknode("=","=", mknode("[]","[]", $<IST.tree>1, $<IST.tree>2), $<IST.tree>4);}
|ID ASSIGN AddressID Array  {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, mknode("[]","[]", $<IST.tree>3, $<IST.tree>4));} /* ( x = &arr[2]; )*/
|ID ASSIGN ValueAddressID  {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, $<IST.tree>3);} /*( z = ^(x-5); )*/
|ValueAddressID ASSIGN E  {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, $<IST.tree>3);}
|ValueAddressID ASSIGN CHAR_CONST  {$<IST.tree>$ = mknode("=","=",$<IST.tree>1, $<IST.tree>3);}
|ID ASSIGN NIL  {$<IST.tree>$ = mknode("=","=" ,$<IST.tree>1, mknode($<IST.string>3,$<IST.type>3 , NULL,NULL));}
|ID ASSIGN LogicOp  {$<IST.tree>$ = mknode("=","=" ,$<IST.tree>1,$<IST.tree>3);};



IndexedAssign: ID {$<IST.tree>$ = $<IST.tree>1;}
|CHAR_CONST {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 , NULL,NULL);};

/*Define: VAR IDents COLON Types SEMICOLON {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 ,$<IST.tree>2,$<IST.tree>4);};*/
Define: Types IDents SEMICOLON {$<IST.tree>$ = mknode("var","var" ,$<IST.tree>2,$<IST.tree>1);};
// right subtree is type. left subtree is variable/variables

IDents: IDENTIFIER SEPERATOR IDents {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1 ,mknode($<IST.string>2,$<IST.type>2 ,NULL,NULL),$<IST.tree>3);}
|IDENTIFIER {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 , NULL,NULL);}
|Assignment SEPERATOR IDents  {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,mknode($<IST.string>2,$<IST.type>2 ,$<IST.tree>1,NULL) ,$<IST.tree>3);}
//|Assignment SEPERATOR IDents 
//{$<IST.tree>$=mknode("","",$<IST.tree>1 ,mknode($<IST.string>3, $<IST.type>3,  mknode($<IST.string>2,$<IST.type>2 ,NULL,NULL)   ,$<IST.tree>3->right ));}
|Assignment {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 , $<IST.tree>1,NULL);};

/*
//old
IDentsWithEmpty: E SEPERATOR IDentsWithEmpty {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1 ,mknode($<IST.string>2,$<IST.type>2 ,NULL,NULL),$<IST.tree>3);}
|Consts SEPERATOR IDentsWithEmpty {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1 ,mknode($<IST.string>2,$<IST.type>2 ,NULL,NULL),$<IST.tree>3);}
|CONST_BOOLEAN SEPERATOR IDentsWithEmpty {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1 ,mknode($<IST.string>2,$<IST.type>2 ,NULL,NULL),$<IST.tree>3);}
|E {$<IST.tree>$ = $<IST.tree>1;}	
|Consts {$<IST.tree>$ = $<IST.tree>1;}	
|CONST_BOOLEAN {$<IST.tree>$ = $<IST.tree>1;};
*/

//new
IDentsWithEmpty: E SEPERATOR IDentsWithEmpty {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2 ,$<IST.tree>1,$<IST.tree>3);}
|Consts SEPERATOR IDentsWithEmpty {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2 ,$<IST.tree>1,$<IST.tree>3);}
|CONST_BOOLEAN SEPERATOR IDentsWithEmpty {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2 ,$<IST.tree>1,$<IST.tree>3);}
|E {$<IST.tree>$ = $<IST.tree>1;}	
|Consts {$<IST.tree>$ = $<IST.tree>1;}	
|CONST_BOOLEAN {$<IST.tree>$ = $<IST.tree>1;};

EmptyOrPara: IDentsWithEmpty {$<IST.tree>$=$<IST.tree>1;}
| {$<IST.tree>$=NULL;};



ID: IDENTIFIER {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1 , NULL,NULL);};//use later for leaf's

Absolute: 
VBAR E VBAR {$<IST.tree>$=mknode("|","|",$<IST.tree>2,mknode("|","|",NULL,NULL));};

StringLenth:
VBAR STRING_CONST VBAR {$<IST.tree>$=mknode("|","|",$<IST.tree>2,mknode("|","|",NULL,NULL));};

Consts:CHAR_CONST {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1, NULL,NULL);}	//without const int HEX OCT BIN, const ints will go to E
//|CONST_BOOLEAN {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1, NULL,NULL);}
|STRING_CONST {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1, NULL,NULL);};


CompOp: EQ {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
|GT {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
|GE {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
|LT {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
|LE {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
|NE {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
|NOT {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;};

//LogicCond:AND {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;}
//|OR {$<IST.string>$=$<IST.string>1; $<IST.type>$=$<IST.type>1;};

/*
LogicOp:Condition LogicCond LogicOp {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|Condition {$<IST.tree>$=$<IST.tree>1;}
|PreLogicOp LogicCond LogicOp{$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|PreLogicOp {$<IST.tree>$=$<IST.tree>1;}
|CONST_BOOLEAN LogicCond LogicOp {$<IST.tree>$=mknode($<IST.string>2 ,$<IST.type>2,mknode($<IST.string>1,$<IST.type>1, NULL,NULL),$<IST.tree>3);}
|CONST_BOOLEAN {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,NULL,NULL);};
*/

//new
LogicOp:condWithAnd OR LogicOp {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|condWithAnd {$<IST.tree>$=$<IST.tree>1;};

condWithAnd:condWithBrackets AND condWithAnd {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|condWithBrackets{$<IST.tree>$=$<IST.tree>1;};

condWithBrackets:BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST {$<IST.tree>$=$<IST.tree>2;}
|CONST_BOOLEAN {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,NULL,NULL);}
|Condition {$<IST.tree>$=$<IST.tree>1;};
//end new


Condition:E CompOp E {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|ValueAddressID CompOp ValueAddressID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|E CompOp ValueAddressID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|ValueAddressID CompOp E {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|ValueAddressID CompOp ID Array {$<IST.tree>$ = mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1, mknode("[]","[]", $<IST.tree>3, $<IST.tree>4));}
|AddressID CompOp AddressID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
|AddressID CompOp ID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
//|IDENTIFIER CompOp AddressID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);} //ohad not working???
|ID Array CompOp ValueAddressID {$<IST.tree>$ = mknode($<IST.string>3,$<IST.type>3,mknode("[]","[]", $<IST.tree>1, $<IST.tree>2), $<IST.tree>4);}
|ValueAddressID CompOp CHAR_CONST {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,mknode($<IST.string>3,$<IST.type>3, NULL, NULL));}
|CHAR_CONST CompOp ValueAddressID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,mknode($<IST.string>1,$<IST.type>1, NULL, NULL),$<IST.tree>3);}
//|ValueAddressID CompOp Absolute {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
//|Absolute CompOp ValueAddressID {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
//|Absolute CompOp Absolute {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
//|Absolute CompOp CHAR_CONST {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,mknode($<IST.string>3,$<IST.type>3, NULL, NULL));}
//|CHAR_CONST CompOp Absolute {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,mknode($<IST.string>1,$<IST.type>1, NULL, NULL),$<IST.tree>3);}
//|Absolute CompOp E {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
//|E CompOp Absolute {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}
//|Absolute CompOp ID Array {$<IST.tree>$ = mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1, mknode("[]","[]", $<IST.tree>3, $<IST.tree>4));}
//|ID Array CompOp Absolute {$<IST.tree>$ = mknode($<IST.string>3,$<IST.type>3, mknode("[]","[]", $<IST.tree>1, $<IST.tree>2),$<IST.tree>4);}
|ID Array CompOp ID Array {$<IST.tree>$ = mknode($<IST.string>3,$<IST.type>3, mknode("[]","[]", $<IST.tree>1, $<IST.tree>2),mknode("[]","[]", $<IST.tree>4, $<IST.tree>5));}
|ID Array CompOp E {$<IST.tree>$ = mknode($<IST.string>3,$<IST.type>3, mknode("[]","[]", $<IST.tree>1, $<IST.tree>2),$<IST.tree>4);}
|E CompOp ID Array {$<IST.tree>$ = mknode($<IST.string>2,$<IST.type>2, $<IST.tree>1,mknode("[]","[]", $<IST.tree>3, $<IST.tree>4));}
|ID Array CompOp CHAR_CONST {$<IST.tree>$ = mknode($<IST.string>3,$<IST.type>3, mknode("[]","[]", $<IST.tree>1, $<IST.tree>2),mknode($<IST.string>4,$<IST.type>4, NULL, NULL));}
|CHAR_CONST CompOp ID Array {$<IST.tree>$ = mknode($<IST.string>2,$<IST.type>2, mknode($<IST.string>1,$<IST.type>1, NULL, NULL), mknode("[]","[]" ,$<IST.tree>3, $<IST.tree>4));}
|E CompOp Consts {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,$<IST.tree>3);}	
|CONST_BOOLEAN CompOp CONST_BOOLEAN {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,mknode($<IST.string>1,$<IST.type>1,NULL,NULL),mknode($<IST.string>3,$<IST.type>3,NULL,NULL));}
|CONST_BOOLEAN CompOp E {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,mknode($<IST.string>1,$<IST.type>1,NULL,NULL),$<IST.tree>3);}
|E CompOp CONST_BOOLEAN {$<IST.tree>$=mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1,mknode($<IST.string>3,$<IST.type>3,NULL,NULL));}
|NOT ID {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>2,NULL);} // NOT (!x)
|NOT CONST_BOOLEAN {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,mknode($<IST.string>2,$<IST.type>2,NULL,NULL),NULL);}; 


//PreLogicOp:BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST {$<IST.tree>$=$<IST.tree>2;};

Return: 
RETURN E SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>2,NULL);}
|RETURN Consts SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>2,NULL);}
|RETURN CONST_BOOLEAN SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,mknode($<IST.string>2,$<IST.type>2,NULL,NULL),NULL);} // michael
|RETURN AddressID SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>2,NULL);}
|RETURN VALUE_ADDRESS E SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,mknode($<IST.string>2,$<IST.type>2,$<IST.tree>3,NULL),NULL);}
|RETURN IDENTIFIER BEGIN_PARAMETER_LIST EmptyOrPara END_PARAMETER_LIST SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,mknode($<IST.string>2,$<IST.type>2,$<IST.tree>4,NULL),NULL);}
|RETURN NIL SEMICOLON {$<IST.tree>$ = mknode($<IST.string>1,$<IST.type>1,mknode($<IST.string>2,$<IST.type>2,NULL,NULL),NULL);};

VoidReturn: RETURN SEMICOLON {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,NULL,NULL);}
|  {$<IST.tree>$=mknode("","",NULL,NULL);};



//ProcedureReturn:  Types {$<IST.tree>$=mknode("return","return",$<IST.tree>1,NULL);};
//ID {$<IST.tree>$=mknode($<IST.tree>1,$<IST.tree>1,NULL,NULL);} // if(x) // ~michael //


Loop:
WHILE BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>3,$<IST.tree>6);}
|WHILE BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE {$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,$<IST.tree>3,$<IST.tree>6);};

If:IF BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE ELSE START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE 
{
$<IST.tree>$=mknode("COND","COND",mknode($<IST.string>1,$<IST.type>1,$<IST.tree>3,$<IST.tree>6),mknode($<IST.string>8,$<IST.type>8,$<IST.tree>10,NULL));
}
|IF BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE ELSE START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE 
{
$<IST.tree>$=mknode("COND","COND",mknode($<IST.string>1,$<IST.type>1,$<IST.tree>3,$<IST.tree>6),mknode($<IST.string>8,$<IST.type>8,$<IST.tree>10,NULL));
}
|IF BEGIN_PARAMETER_LIST ID END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE
{
$<IST.tree>$=mknode("COND","COND",mknode($<IST.string>1,$<IST.type>1,$<IST.tree>3,$<IST.tree>6),NULL);
}
|IF BEGIN_PARAMETER_LIST LogicOp END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE
{
$<IST.tree>$=mknode("COND","COND",mknode($<IST.string>1,$<IST.type>1,$<IST.tree>3,$<IST.tree>6),NULL);
};


For: FOR BEGIN_PARAMETER_LIST forCondition END_PARAMETER_LIST START_BLOCK_OF_CODE Block END_BLOCK_OF_CODE 
{$<IST.tree>$=mknode($<IST.string>1,$<IST.type>1,  $<IST.tree>3,  $<IST.tree>6   );  };


forCondition: initCond  endAndStep {$<IST.tree>$=mknode("for-COND","COND",$<IST.tree>1, $<IST.tree>2);};
initCond:   Assignment SEMICOLON  {$<IST.tree>$ = mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1, NULL);};
endAndStep: endCond SEMICOLON Step {$<IST.tree>$ = mknode($<IST.string>2,$<IST.type>2,$<IST.tree>1, $<IST.tree>3);};
endCond: Condition {};
Step: Assignment {};


Array: BEGIN_STRING_INDEX E END_STRING_INDEX {$<IST.tree>$ = $<IST.tree>2;};

%%

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
        else if(strcmp(tree->token,"for")==0)//need to fix to put the label before the ifz and not before the variables.
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
		//only if has statements in code, otherwise block is not build (right child is null)
		if (tree->right)
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
		//only if has statements in code, otherwise block is not build (right child is null)
		if (tree->left->right)
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
		else if (strcmp(tree->left->token,"for")==0){
                        if(strcmp(tree->left->next,"")==0)//first time to put label)
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
                // if FOR\COND has an empty block then right child will be null
                if (tree->left->right != NULL)
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
		//char thencode[2000]="";
		char whilecode[2000]="";
		node * condition=tree->left;//if(x>y) => condition= '>')
		notToEnterLeft=1;
		notToEnterRight=1;
		thenLabel=strdup(freshLabel());
		whileLabel=strdup(freshLabel());
		// if WHILE has an empty block then right child will be null
		if (tree->right !=NULL)
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
	else if(strcmp(tree->token,"for")==0 && strcmp(tree->trueLabel,"")==0)
	{ 
		
		char * thenLabel;
		char * forLabel;
		//char thencode[2000]="";
		char forcode[2000]="";
		_3ACForAssignment(tree->left->left->left);//code
		node * condition=tree->left->right->left;//if(x>y) => condition= '>')
		notToEnterLeft=1;
		notToEnterRight=1;
		thenLabel=strdup(freshLabel());
		forLabel=strdup(freshLabel());
		// if FOR has an empty block then right child will be null
		if (tree->right !=NULL)
                    _3ACMain(tree->right);//then block  //code
		tree->trueLabel=strdup(forLabel);
		// give the condition's label its "then label"'
		tree->left->right->left->trueLabel=strdup(thenLabel);
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
		strcat(forcode,"AFTER \n");
		strcat(forcode,"goto ");
		strcat(forcode,forLabel);
		strcat(forcode,"\n");
		strcat(forcode,"\0");
		tree->code=strdup(forcode);
		
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
		// tree->left->left points to "=" node
		if (tree->left->left)
                    _3ACForAssignment(tree->left->left);
            
		tree = tree->right;
	}
	// loop ended before reaching last node
	if (tree->left!=NULL)
                _3ACForAssignment(tree->left);
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

//check recrusivly that all ID's in the "for" loop are declared
// void checkIDForCond(node * forCond)
// {
//     while (forCond != NULL)
//     {
//         if (!strcmp(forCond->type,"var")
//         {
//             if(!CheckID(forCond))
//             {
//                     printf("ID Not exists!\n");
//                     exit(1);
//             }
//         }
//         checkIDForCond(forCond->left);
//         checkIDForCond(forCond->right);
//     }
//     return;
// }

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
		//if has a non-empty block
                if(!CheckID(whilecond))
                {
                        printf("ID Not exists!\n");
                        exit(1);
                }
                UpdateIDType(whilecond);
                buildST(whilecond);
                checkIfConditionTypeIsBoolean(whilecond); // michaell
                
		if (tree->right){
                        if(strcmp(tree->right->token,"")==0)
                        {
                                whileblock=tree->right->left;
                        }
                        else
                        {
                                whileblock=tree->right;
                        }

                        scopeCounter = scopeCounter + 1;  
                        buildST(whileblock);
                        scopeCounter = scopeCounter - 1; 
                        current=curr;
                        flagLeftSubTree = 1;
                        flagRightSubTree = 1;
		}
	}
	else if(strcmp(tree->token,"for")==0) 
	{ 
		char * lvaltype;
		char * rvaltype;
		node * forCond=tree->left;
		node * forBlock;
		symbolTable * curr=current;//save state before
		forBlock=tree->right;
		node * tempForCond = forCond;
		//checkIDForCond(forCond);
		UpdateIDType(forCond);
		buildST(forCond);

		//checkIfConditionTypeIsBoolean(forCond); // michaell

		scopeCounter = scopeCounter + 1;  
		buildST(forBlock);
		scopeCounter = scopeCounter - 1; 
		current=curr;
		flagLeftSubTree = 1;
		flagRightSubTree = 1;
        }
	else if(strcmp(tree->token,"return")==0)
	{ 
                //only non-void functions have "return"->left, and therefore enter
                // void functions have no left child
                if (tree->left != NULL)
                {// check if current function was already declared (proc->right return)
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
	node * tempTree=tree, *saveTree = NULL;
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
                        // if we have an empty node followed by assignment node, jump to left child (holding new var)
                        if (!strcmp(tempTree->token, "")){
                                saveTree = tempTree;
                                tempTree = tempTree->left->left;
                        }
                        // we declare var with no value (and add to symbol table)
                
                        tempTree->type = strdup(type); // 
                        symbolTable * temp=(symbolTable*)malloc(sizeof(symbolTable));
                        temp->scopeNumber = scopeCounter;
                        temp->prevST=current;
                        current=temp;
                        current->name=strdup(tempTree->token);
                        current->type=strdup(type);
                        current->scope=strdup("var");
                        
                        // restore tree iterator to original address
                        if (saveTree)
                            tempTree = saveTree;
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
                // case 1: UpdateIDType was called when variable was declared with a value: <ID> = <value>
                
                // case 2: UpdateIDType was called when a previously declared variable was being re-assigned
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
