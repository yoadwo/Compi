all:
	rm -f bin/lex.yy.c bin/y.tab.c part1
	lex -o bin/lex.yy.c src/part1.l
	yacc -v -d -o bin/y.tab.c src/part1.y
	cc bin/y.tab.c -o part1 -ll -Ly


