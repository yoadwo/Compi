#define BOOLEAN 257
#define CONST_BOOLEAN 258
#define CHAR 259
#define INTEGER 260
#define STRING 261
#define INTPTR 262
#define CHARPTR 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define VAR 267
#define ASSIGN 268
#define EQ 269
#define GT 270
#define GE 271
#define LT 272
#define LE 273
#define NE 274
#define NOT 275
#define MINUS 276
#define PLUS 277
#define MUL 278
#define DIVISION 279
#define ADDRESS 280
#define VAL_POINTER 281
#define AMPERSAND 282
#define VALUE_ADDRESS 283
#define ARRAY 284
#define PROCEDURE 285
#define RETURN 286
#define NIL 287
#define AND 288
#define OR 289
#define VBAR 290
#define CHAR_CONST 291
#define BINARY 292
#define OCTAL 293
#define INTEGER_CONST 294
#define STRING_CONST 295
#define SEMICOLON 296
#define COLON 297
#define SEPERATOR 298
#define START_BLOCK_OF_CODE 299
#define END_BLOCK_OF_CODE 300
#define BEGIN_PARAMETER_LIST 301
#define END_PARAMETER_LIST 302
#define BEGIN_STRING_INDEX 303
#define END_STRING_INDEX 304
#define IDENTIFIER 305
#define HEXADECIMAL 306
#define ERR 307
#define EQUAL 308
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union 
{
struct
    {
	char* type;
	char* string;
	node* tree;
    }IST;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
