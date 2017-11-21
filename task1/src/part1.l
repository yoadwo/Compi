/*
%{
	int counter=1;
%}
*/
%x comment
%%
[ ]+ ;
"boolean" return BOOL;
"char" return CHAR;
"integer" return INT;
"string" return STRING;
"intptr" return INTPTR;
"charptr" return CHARPTR;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"main" return MAIN;
"procedure" return PROCEDURE;
"return" return RETURN;
"true" return BOOLTRUE;
"false" return BOOLFALSE;
"null" return NULLL;
"=" return ASSIGNMENT;
"&&" return AND;
\/ return DIVISION;
"==" return EQUAL;
">" return GREATER;
">=" return GREATEREQUAL;
"<" return LESS;
"<=" return LESSEQUAL;
"-" return MINUS;
"!" return NOT;
"!=" return NOTEQUAL;
"||" return OR;
"+" return PLUS;
"*" return MULTI;
"&" return ADDRESS;
"^" return DEREFERENCE;
"|" return ABSUOLUTE;
";" return SEMICOLON;
":" return COLON;
"," return COMMA;
"{" return LEFTBRACE;
"}" return RIGHTBRACE;
"(" return LEFTPAREN;
")" return RIGHTPAREN;
"[" return LEFTBRACKET;
"]" return RIGHTBRACKET;
"%" return PERCENT;
"/*" BEGIN comment;
<comment>[^\n] ;
<comment>\n     ;/*counter++;*/
<comment>"*/" BEGIN 0;
[a-zA-Z][a-zA-Z0-9_]* return ID;
[1-9][0-9]*|-?0 return INTEGER_CONST;
\-[1-9]+ return NEGATIVE_NUM;
[\'].[\'] return CHAR_CONST;
[\"][^\"]*[\"] return STRING_CONST;
0(x|X)[0-9A-Fa-f]+ return HEX_CONST;
0[0-7]+ return OCTAL_CONST;
(0|1)+b return BINARY_CONST;
\n      ;/*counter++;*/
[ \t] ;
. ;
%%
