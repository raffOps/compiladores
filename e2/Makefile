etapa2: clean parser lex
	gcc lex.yy.c -o etapa2 

lex: scanner.l
	lex scanner.l

parser: parser.y
	yacc parser.y -d

clean:
	rm -f *.o lex.yy.c etapa1 etapa2 .DS_Store y.tab.c y.tab.h
