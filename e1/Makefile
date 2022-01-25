cria_entregavel:
	flex scanner.l
	gcc lex.yy.c -o etapa1 -lfl

flex:
	flex scanner.l

gcc_l:
	gcc lex.yy.c -o analisador -lfl

run: flex gcc_l
	./analisador

test:
	cat exemplos.txt | make run

clean:
	rm *.o lex.yy.c etapa1
