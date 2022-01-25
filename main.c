/*
Função principal para impressão de tokens.

Este arquivo será posterioremente substituído, não acrescente nada.
*/
#include <stdio.h>
#include "tokens.h"
extern int yylex(void);
extern int yylex_destroy(void);

extern FILE *yyin;
extern char *yytext;
extern int get_line_number (void);
#define print_nome(TOKEN) \
    printf("%d " #TOKEN " [%s]\n", get_line_number(), TOKEN);
// #define print_nome2(TOKEN) \
//    printf("%d TK_ESPECIAL [%c]\n", get_line_number(), TOKEN);

int main (int argc, char **argv)
{
  int token = 0;
  while (token = yylex()) {
    switch (token){
    case ',':
    case ';':
    case ':':
    case '(':
    case ')':
    case '[':
    case ']':
    case '{':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/':
    case '<':
    case '>':
    case '=': print_nome(token); break;

    case KW_CHAR: print_nome(KW_CHAR); break;
    case KW_INT: print_nome(KW_INT); break;
    case KW_FLOAT: print_nome(KW_FLOAT); break;

    case KW_IF: print_nome(KW_IF); break;
    case KW_THEN: print_nome(KW_THEN); break;
    case KW_ELSE: print_nome(KW_ELSE); break;

    case KW_WHILE: print_nome(KW_WHILE); break;
    case KW_GOTO: print_nome(KW_GOTO); break;
    case KW_READ: print_nome(KW_READ); break;
    case KW_PRINT: print_nome(KW_PRINT); break;
    case KW_RETURN: print_nome(KW_RETURN); break;

    case OPERATOR_LE: print_nome(OPERATOR_LE); break;
    case OPERATOR_GE: print_nome(OPERATOR_GE); break;
    case OPERATOR_EQ: print_nome(OPERATOR_EQ); break;
    case OPERATOR_DIF: print_nome(OPERATOR_DIF); break;

    case TK_IDENTIFIER: print_nome(TK_IDENTIFIER); break;
    
    case LIT_INTEGER: print_nome(LIT_INTEGER); break;
    case LIT_CHAR: print_nome(LIT_CHAR); break;
    case LIT_STRING: print_nome(LIT_STRING); break;

    case TOKEN_ERROR: print_nome(TOKEN_ERROR); break;
    default: printf ("<Invalid Token with code %d>\n", token); return 1; break;
    }
  }
  yylex_destroy();
  return 0;
}
