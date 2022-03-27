#include "semantic.h"

int SemanticErros = 0;

void check_and_set_identifier(AST *node, int symbol) {
    if (node->symbol) {
        if ( node->symbol->type != SYMBOL_IDENTIFIER) {
            fprintf(stderr, "Semantic ERROR: variable %s already declared\n", node->symbol->text);
            ++SemanticErros;
        }
        else {
            //fprintf(stdout, " dfsfasdfasdfasdffffff   %d     ds", symbol);
            node->symbol->type = symbol;
            if (node->son[0]) {
                switch (node->son[0]->type) {
                case AST_INT:
                    node->symbol->datatype = DATATYPE_INT;
                    break;
                case AST_CHAR:
                    node->symbol->datatype = DATATYPE_CHAR;
                    break;

                case AST_FLOAT:
                    node->symbol->datatype = DATATYPE_FLOAT;
                    break;
                default:
                fprintf(stderr, "dpçoifsjf");
                    break;
                }
        }
    }
}}

void check_and_set_declarations(AST *node) {
    int i = 0;
    if (node == 0)
        return;

    switch (node->type) {
        case AST_VAR_DEC: check_and_set_identifier(node, SYMBOL_VARIABLE); break;
        case AST_FUNCTION_DEC: check_and_set_identifier(node, SYMBOL_FUNCTION); break;
        case AST_FUNCTION_ARGUMENT: check_and_set_identifier(node, SYMBOL_VARIABLE); break;
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; i++)
        check_and_set_declarations(node->son[i]);
}

// void check_undeclared() {
//     SemanticErros += hashCheckUndeclared();
// }