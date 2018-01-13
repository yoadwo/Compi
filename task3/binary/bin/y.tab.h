#define BOOLEAN 257
#define CONST_BOOLEAN 258
#define CHAR 259
#define INTEGER 260
#define STRING 261
#define VOID 262
#define INTPTR 263
#define CHARPTR 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define VAR 269
#define ASSIGN 270
#define EQ 271
#define GT 272
#define GE 273
#define LT 274
#define LE 275
#define NE 276
#define NOT 277
#define MINUS 278
#define PLUS 279
#define MUL 280
#define DIVISION 281
#define ADDRESS 282
#define VAL_POINTER 283
#define AMPERSAND 284
#define VALUE_ADDRESS 285
#define ARRAY 286
#define PROCEDURE 287
#define RETURN 288
#define NIL 289
#define AND 290
#define OR 291
#define VBAR 292
#define CHAR_CONST 293
#define BINARY 294
#define OCTAL 295
#define INTEGER_CONST 296
#define STRING_CONST 297
#define SEMICOLON 298
#define COLON 299
#define SEPERATOR 300
#define START_BLOCK_OF_CODE 301
#define END_BLOCK_OF_CODE 302
#define BEGIN_PARAMETER_LIST 303
#define END_PARAMETER_LIST 304
#define BEGIN_STRING_INDEX 305
#define END_STRING_INDEX 306
#define IDENTIFIER 307
#define HEXADECIMAL 308
#define ERR 309
#define EQUAL 310
#define StringParameter 311
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
