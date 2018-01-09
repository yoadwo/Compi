%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "y.tab.h"

%}
 int flag = 0;
 
%%

.+ { if(flag==0) REJECT;} 
boolean {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("boolean"); return BOOLEAN;}
true {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("boolean"); return CONST_BOOLEAN;}
false {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("boolean"); return CONST_BOOLEAN;}
char {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("char"); return CHAR;}
integer	{yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("int"); return INTEGER;}
string {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("string"); return STRING;}
intptr {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("intptr"); return INTPTR;}
charptr	{yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("charptr"); return CHARPTR;}
if {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("if"); return IF;}
else {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("else"); return ELSE;}
while {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("while"); return WHILE;}
var {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("var"); return VAR;}
\= {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return ASSIGN;}
\== {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return EQ;}
\> {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return GT;}
\>= {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return GE;}
\< {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return LT;}
\<= {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return LE;}
\- {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return MINUS;}
\!= {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return NE;}
\! {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return NOT;}
\+ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return PLUS;}
\* {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return MUL;}
\/ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return DIVISION;}
\& {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("ampersand"); return AMPERSAND;}
\^ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("value_address"); return VALUE_ADDRESS;}
procedure {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("procedure"); return PROCEDURE;}
return {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("return"); return RETURN;}
null {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("null"); return NIL;}
\&& {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return AND;}
\|\| {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return OR;}
\| {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("operator"); return VBAR;}
'.' {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("char"); return CHAR_CONST;}
[0|1]+b {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("int"); return BINARY;}
0[0-7]+ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("int"); return OCTAL;}
0|[1-9][0-9]+? {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("int"); return INTEGER_CONST;}
\".*\" {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("string"); return STRING_CONST;}
\; {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("semicolon"); return SEMICOLON;}
\: {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("colon"); return COLON;}
\, {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("seperator"); return SEPERATOR;}
\{ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("startblock"); return START_BLOCK_OF_CODE;}
\} {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("endblock"); return END_BLOCK_OF_CODE;}
\( {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("startparamater"); return BEGIN_PARAMETER_LIST;}
\) {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("endparameter"); return END_PARAMETER_LIST;}
\[ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("startstring"); return BEGIN_STRING_INDEX;}
\] {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("endstring"); return END_STRING_INDEX;}
[a-zA-Z_][a-zA-Z0-9_]* {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("var"); return IDENTIFIER;}
[-]?0[x|X][A-Fa-f0-9]+ {yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("int"); return HEXADECIMAL;}
\/%.*%\/ ;
\n {yylineno = yylineno + 1;}
[ \t] ;
. {flag=1; yylval.IST.string=strdup(yytext); yylval.IST.type=strdup("err"); return ERR;}
%%

