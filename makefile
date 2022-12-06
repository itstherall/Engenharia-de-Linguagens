all: potrexcompiler

potrexcompiler: analisador/lex.yy.c analisador/y.tab.c 
	gcc analisador/lex.yy.c analisador/y.tab.c ./lib/potrex.c -o compiler

lex.yy.c: analisador/lexer.l
	lex analisador/lexer.l

y.tab.c: analisador/parser.y  
	yacc analisador/parser.y -d -v

clean:
	rm -rf analisador/lex.yy.c analisador/y.tab.* compiler output.txt y.output