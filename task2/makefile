all:
	rm -f bin/lex.yy.c bin/y.tab.c
	rm -f part2
	lex -o bin/lex.yy.c src/part2.l
	yacc -v -d -o bin/y.tab.c src/part2.y
	cc -g bin/y.tab.c -o part2 -ll -Ly


