/*
Função principal para impressão de tokens.

Este arquivo será posterioremente substituído, não acrescente nada.
*/
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
extern int yylex(void);
extern int yylex_destroy(void);

extern FILE *yyin;
extern char *yytext;
extern int getLineNumber (void);
extern int isRunning (void);
extern void yyparse (void);

int main (int argc, char **argv)
{
  hashInit();
  if (argc < 2) {
    fprintf(stderr, "call: etapa2 filename\n");
    exit(1);
  }

  yyin = fopen(argv[1], "r");
  if (yyin == 0) {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    exit(2);
  }
  int token;
  yyparse();  
  //hashPrint();
  fprintf(stderr, "\nCompilation successful!\n");
  exit(0);
}
