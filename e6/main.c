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
extern FILE *output;
extern FILE *asm_out;
extern int getLineNumber (void);
extern int isRunning (void);
extern void yyparse ();
extern int SemanticErros;

int main (int argc, char **argv)
{
  hashInit();
  if (argc < 4) {
    fprintf(stderr, "call: etapa2 filename_in filename_out asm_out\n");
    exit(1);
  }

  yyin = fopen(argv[1], "r");
  if (yyin == 0) {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    exit(2);
  }

  output = fopen(argv[2], "w+");
  if (output == 0) {
    fprintf(stderr, "Cannot open file %s\n", argv[2]);
    exit(2);
  }

  asm_out = fopen(argv[3], "w+");
  if (asm_out == 0) {
    fprintf(stderr, "Cannot open file %s\n", argv[3]);
    exit(2);
  }

  int token;
  yyparse();  
  hashPrint();
  if (SemanticErros == 0)
    fprintf(stderr, "\nCompilation successful!\n");
  else
    exit(4);

  fclose(output);
  fclose(asm_out);
  exit(0);
}
