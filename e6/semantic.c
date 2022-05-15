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
            switch (node->son[0]->type)
            {
                case AST_KW_INT:
                    check_and_set_identifier(node, SYMBOL_VARIABLE_INT);
                    break;
                case AST_KW_CHAR:
                    check_and_set_identifier(node, SYMBOL_VARIABLE_CHAR);
                    break;
                case AST_KW_FLOAT:
                    check_and_set_identifier(node, SYMBOL_VARIABLE_FLOAT);
                    break;
                default:
                    break;
            }
            break;
        case AST_FUNCTION:
            switch (node->son[0]->type)
            {
                case AST_KW_INT:
                    check_and_set_identifier(node, SYMBOL_FUNCTION_INT);
                    break;
                case AST_KW_CHAR:
                    check_and_set_identifier(node, SYMBOL_FUNCTION_CHAR);
                    break;
                case AST_KW_FLOAT:
                    check_and_set_identifier(node, SYMBOL_FUNCTION_FLOAT);
                    break;
                default:
                    break;
            }
            break;
        case AST_FUNCTION_PARAM:
            switch (node->son[0]->type)
            {
                case AST_KW_INT:
                    check_and_set_identifier(node, SYMBOL_VARIABLE_INT);
                    break;
                case AST_KW_CHAR:
                    check_and_set_identifier(node, SYMBOL_VARIABLE_CHAR);
                    break;
                case AST_KW_FLOAT:
                    check_and_set_identifier(node, SYMBOL_VARIABLE_FLOAT);
                    break;
                default:
                    break;
            }
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; i++)
        check_and_set_declarations(node->son[i]);
}

int is_number(AST *son) {
    //fprintf(stdout, "%s %d\n", son->symbol->text, son->symbol->type);
    return (son->type == AST_ADD 
            || son->type == AST_SUB
            || son->type == AST_MUL
            || son->type == AST_DIV 
            || (son->type == AST_SYMBOL && 
                    (son->symbol->type == SYMBOL_VARIABLE_INT
                        || son->symbol->type == SYMBOL_VARIABLE_CHAR
                        || son->symbol->type == SYMBOL_VARIABLE_FLOAT )
            || (son->type == AST_INT)
            || (son->type == AST_CHAR)
            || (son->symbol &&  (
                    hashFind(son->symbol->text)->type == AST_INT 
                    || hashFind(son->symbol->text)->type == AST_CHAR)
                    || hashFind(son->symbol->text)->type == AST_FLOAT))
            || (son->type == AST_FUNCTION_CALL_TYPE_A
                || son->type == AST_ASSIGMENT_TYPE_B
                && (son->symbol->datatype == DATATYPE_CHAR
                    || son->symbol->datatype == DATATYPE_INT)));

}

void check_operands(AST *node) {
    int i;
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
            fprintf(stderr, "Semantic ERROR: Invalid left operands %s for logic/arithimetic operation\n", node->son[0]->symbol->text);
            ++SemanticErros;
        }
        if (!is_number(node->son[1])) {
            fprintf(stderr, "Semantic ERROR: Invalid right operands %s for logic/arithimetic operation\n", node->son[1]->symbol->text);
            ++SemanticErros;
        }
        break;
    
    default:
        break;
    }    

    for (int i=0; i<MAX_SONS; i++)
        check_operands(node->son[i]);

}

void check_variables_functions_use(AST *node) {
    int i;
    if (node == 0)
        return;
    switch (node->type)
    {
    case AST_FUNCTION_CALL_TYPE_A:
    case AST_FUNCTION_CALL_TYPE_B:
        switch (hashFind(node->symbol->text)->type) {
            case AST_GLOBAL_VARIABLE_TYPE_A:
            case AST_GLOBAL_VARIABLE_TYPE_B:
            case AST_GLOBAL_VARIABLE_TYPE_C:
                fprintf(stderr, "Semantic ERROR: variable %s used as function", node->symbol->text);
                ++SemanticErros;
                break;
        }
        break;    
    case AST_SYMBOL:
        switch (hashFind(node->symbol->text)->type) {
            case AST_FUNCTION:
                fprintf(stderr, "Semantic ERROR: function %s used as variable", node->symbol->text);
                ++SemanticErros;
                break;
        }
        break;
    
    default:
        break;
    }    

    for (int i=0; i<MAX_SONS; i++)
        check_operands(node->son[i]);

}

void check_undeclared() {
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