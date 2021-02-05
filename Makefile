flex:
	flex scanner.l

gcc_l:
	gcc lex.yy.c -o analisador -lfl

run: flex gcc_l
	./analisador

<<<<<<< HEAD
clean:
	rm lex.yy.c analisador
=======
test:
	cat exemplos.txt | make run

>>>>>>> main
