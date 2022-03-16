etapa3: clean hash.o ast.o main.o y.tab.o lex.yy.o
	@gcc main.o hash.o ast.o lex.yy.o y.tab.o -o etapa3

main.o: main.c
	@gcc -c main.c

ast.o: ast.c
	@gcc -c ast.c

lex.yy.o: lex.yy.c
	@gcc -c lex.yy.c

hash.o: hash.c
	@gcc -c hash.c

y.tab.o: y.tab.c
	@gcc -c y.tab.c

lex.yy.c: scanner.l
	@lex scanner.l

y.tab.c: parser.y
	@yacc -d parser.y

test: etapa3
	@./etapa3 input.txt output3.txt

zip:
	@tar cvzf etapa3.tgz .

clean:
	@rm -f *.o *.tgz lex.yy.c etapa* .DS_Store y.tab.c y.tab.h *output* *vscode*
