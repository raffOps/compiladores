etapa1: lex
	gcc lex.yy.c -o etapa1 

lex:
	lex scanner.l

gcc_l: lex
	gcc lex.yy.c -o analisador 

run: gcc_l
	./analisador

test: gcc_l
	cat exemplos.txt | ./analisador

clean:
	rm -f *.o lex.yy.c etapa1 analisador .DS_Store
