
%{
	int counter=1;
        #include <string.h> 
%}
%x String 
%x comment
%%
[ ]+ ;
"boolean" return BOOL;
"char" return CHAR;
"integer" return INT;
"string" return STRING;
"intptr" return INTPTR;
"charptr" return CHARPTR;
"void" return VOID;
"if" return IF;
"else" return ELSE;
"do" return DO;
"while" return WHILE;
"for"   return FOR;
"main" return MAIN;
"return" return RETURN;
"true" return BOOLTRUE;
"false" return BOOLFALSE;
"null" return CSNULL;
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
"'"  return QUOTES;
"nada" return NADA;
"/*" BEGIN comment;
<comment>[^\n] ;
<comment>\n     ;/*counter++;*/
<comment>"*/" BEGIN 0;

[a-zA-Z][a-zA-Z0-9_]* return ID;
[1-9][0-9]*|-?0 return INTEGER_POS;
\-[1-9]+ return INTEGER_NEG;
[\'].[\'] return CHAR_CONST;
[\"][^\"]*[\"] return STRING_CONST;
0(x|X)[0-9A-Fa-f]+ return HEX_CONST;
0[0-7]+ return OCTAL_CONST;
(0|1)+b return BINARY_CONST;
\n      ;counter++;
[ \t] ;
. return yytext[0]; ;
%%
