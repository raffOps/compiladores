flex:
	flex scanner.l

gcc:
	gcc lex.yy.c -o analisador -lfl

run: flex gcc
	./analisador
