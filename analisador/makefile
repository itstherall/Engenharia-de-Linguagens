all: potrexcompiler

potrexcompiler: lex.yy.c y.tab.c 
	gcc lex.yy.c y.tab.c ./lib/potrex.c -lm -o compiler

potrex.c:
	gcc /lib/potrex.c

lex.yy.c: lexer.l
	lex lexer.l

y.tab.c: parser.y  
	yacc parser.y -d -v

clean:
	rm -rf lex.yy.c y.tab.* compiler output.txt y.output