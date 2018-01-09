all:
	rm -f bin/lex.yy.c bin/y.tab.c part3
	lex -o bin/lex.yy.c src/part3.l
	yacc -v -d -o bin/y.tab.c src/part3.y
	cc -g bin/y.tab.c -o part3 -ll -Ly


