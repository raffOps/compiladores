etapa2: clean parser lex
	@gcc lex.yy.c -o etapa2 

lex: scanner.l
	@lex scanner.l

parser: parser.y
	@yacc parser.y -d

test: etapa2
	@./etapa2 input.txt

zip:
	tar cvzf etapa2.tgz .

clean:
	@rm -rf *.o *.tgz lex.yy.c etapa* .DS_Store y.tab.c y.tab.h *output* .vscode
