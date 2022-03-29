#ifndef SEMANTIC_HEADER

#define SEMANTIC_HEADER
#include "ast.h"
#include "hash.h"
#include <string.h>

extern int SemanticErros;


void check_and_set_identifier(AST *node, int symbol);
void check_and_set_declarations(AST *node);
void check_operands(AST *node);
void check_undeclared();
int is_number(AST *son);
//int check_value_in_array(int value, int *array);

#endif