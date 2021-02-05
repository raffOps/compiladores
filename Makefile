flex:
	flex scanner.l

gcc_l:
	gcc lex.yy.c -o analisador -lfl

run: flex gcc_l
	./analisador

test:
	cat exemplos.txt | make run

