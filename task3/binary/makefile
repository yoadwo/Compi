all:
	rm -f bin/lex.yy.c bin/y.tab.c
	rm -f part3bin
	lex -o bin/lex.yy.c src/part3bin.l
	yacc -v -d -o bin/y.tab.c src/part3bin.y
	gcc -g bin/y.tab.c -lm -o part3bin -ll -Ly


