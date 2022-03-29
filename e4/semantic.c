#include "semantic.h"

int SemanticErros = 0;

void check_and_set_identifier(AST *node, int symbol) { 
    if (node->symbol) {
        //fprintf(stdout, " %s %d\n",node->symbol->text, node->symbol->type);
        if ( node->symbol->type != SYMBOL_IDENTIFIER) {
            fprintf(stdout, " %s %d %d %d\n",node->symbol->text, node->symbol->type, node->son[0]->type, symbol);
            fprintf(stderr, "Semantic ERROR: variable %s already declared\n", node->symbol->text);
            ++SemanticErros;
        }
        else {
            node->symbol->type = symbol;
            if (node->son[0]) {
                //fprintf(stdout, " %s %d %d %d\n",node->symbol->text, node->symbol->type, node->son[0]->type, symbol);
                switch (node->son[0]->type) {
                    case AST_KW_INT:
                        node->symbol->datatype = DATATYPE_INT;
                        break;
                    case AST_KW_CHAR:
                        node->symbol->datatype = DATATYPE_CHAR;
                        break;

                    case AST_KW_FLOAT:
                        node->symbol->datatype = DATATYPE_FLOAT;
                        break;
                    default:
                        //fprintf(stdout, " %s %d\n",node->symbol->text, node->symbol->type);
                        break;
                }
            }
        }
    }
}

void check_and_set_declarations(AST *node) {
    int i = 0;
    if (node == 0)
        return;

    switch (node->type) {
        case AST_GLOBAL_VARIABLE_TYPE_A:
        case AST_GLOBAL_VARIABLE_TYPE_B:
        case AST_GLOBAL_VARIABLE_TYPE_C:
            check_and_set_identifier(node, SYMBOL_VARIABLE); 
            break;
        case AST_FUNCTION: check_and_set_identifier(node, SYMBOL_FUNCTION); break;
        case AST_FUNCTION_ARGUMENT: check_and_set_identifier(node, SYMBOL_VARIABLE); break;
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; i++)
        check_and_set_declarations(node->son[i]);
}

int is_number(AST *son) {
    return (son->type == AST_ADD 
            || son->type == AST_SUB
            || son->type == AST_MUL
            || son->type == AST_DIV 
            || (son->type == AST_SYMBOL && 
                    son->symbol->type == SYMBOL_LIT_INT)
            || (son->type == AST_FUNCTION_CALL_TYPE_A
                || son->type == AST_ASSIGMENT_TYPE_B
                && (son->symbol->datatype == DATATYPE_FLOAT
                    || son->symbol->datatype == DATATYPE_INT)));

}

void check_operands(AST *node) {
    int i;
    fprintf(stdout, "aqui");
    if (node == 0)
        return;
    switch (node->type)
    {
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
    case AST_LT:
    case AST_GT:
    case AST_LE:
    case AST_GE:
    case AST_EQ:
    case AST_DIF:
        if (!is_number(node->son[0])) {
                fprintf(stderr, "Semantic ERROR: Invalid left operands %s for arithimetic operation\n", node->symbol->text);
                ++SemanticErros;
        }
        if (!is_number(node->son[1])) {
            fprintf(stderr, "Semantic ERROR: Invalid right operands %s for arithimetic operation\n", node->symbol->text);
            ++SemanticErros;
        }
        break;
    
    default:
        break;
    }    

    for (int i=0; i<MAX_SONS; i++)
        check_operands(node->son[i]);

}

void check_undeclared() {
    fprintf(stdout, "aqui");
    SemanticErros += hashCheckUndeclared();
}

// int check_if_value_in_array(int value, int *array) {

//     int arrLen = sizeof(*array) / sizeof(array[0]);
     
//     for (int i = 0; i < arrLen; i++) {
//         if (array[i] == value) {
//             return 1;
//         }
//     }
     
//     return 0;
// }