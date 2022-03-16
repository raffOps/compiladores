#include "ast.h"
#include <stdlib.h>

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3){
    AST *newnode;
    newnode = (AST*) calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;

    return newnode;
}

void astPrint(AST *node, int level) {
    if (node == 0)
        return;

    for (int i=0; i<level; i++)
        fprintf(stderr, "  ");
    fprintf(stderr, "ast(");
    switch (node->type) {
    case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL");
        break;
    case AST_ADD: fprintf(stderr, "AST_ADD");
        break;
    
    case AST_SUB: fprintf(stderr, "AST_SUB");
        break;

    case AST_MUL: fprintf(stderr, "AST_MUL");
        break;
    
    case AST_DIV: fprintf(stderr, "AST_DIV");
        break;

    case AST_GT: fprintf(stderr, "AST_GT");
        break;
    
    case AST_LT: fprintf(stderr, "AST_LT");
        break;

    case AST_LE: fprintf(stderr, "AST_LE");
        break;
    
    case AST_GE: fprintf(stderr, "AST_GE");
        break;

    case AST_EQ: fprintf(stderr, "AST_EQ");
        break;
    
    case AST_DIF: fprintf(stderr, "AST_DIF");
        break;

    case AST_LCMD: fprintf(stderr, "AST_LCMD");
        break;

    case AST_LABEL: fprintf(stderr, "AST_LABEL");
        break;
    
    case AST_PARAM_LIST: fprintf(stderr, "AST_PARAM_LIST");
        break;

    case AST_PRINT_FUN: fprintf(stderr, "AST_PRINT_FUN");
        break;

    case AST_PRINT_ARGS: fprintf(stderr, "AST_PRINT_ARGS");
        break;
    
    case AST_RETURN: fprintf(stderr, "AST_RETURN");
        break;

    case AST_IF: fprintf(stderr, "AST_IF");
        break;

    case AST_IF_ELSE: fprintf(stderr, "AST_IF_ELSE");
        break;

    case AST_THEN: fprintf(stderr, "AST_THEN");
        break;

    case AST_WHILE: fprintf(stderr, "AST_WHILE");
        break;

    case AST_GOTO: fprintf(stderr, "AST_GOTO");
        break;

    case AST_FUNCTION: fprintf(stderr, "AST_FUNCTION");
        break;

    case AST_FUNCTION_ARGUMENT: fprintf(stderr, "AST_FUNCTION_ARGUMENT");
        break;

    case AST_FUNCTION_ARGUMENTS: fprintf(stderr, "AST_FUNCTION_ARGUMENTS");
        break;

    case AST_LIT_LIST: fprintf(stderr, "AST_LIT_LIST");
        break;
        
    case AST_DECL: fprintf(stderr, "AST_DECL");
        break;

    case AST_GLOBAL_VARIABLE_TYPE_A: fprintf(stderr, "AST_GLOBAL_VARIABLE_TYPE_A");
        break;

    case AST_GLOBAL_VARIABLE_TYPE_B: fprintf(stderr, "AST_GLOBAL_VARIABLE_TYPE_B");
        break;

    case AST_GLOBAL_VARIABLE_TYPE_C: fprintf(stderr, "AST_GLOBAL_VARIABLE_TYPE_C");
        break;
    
    case AST_INT: fprintf(stderr, "AST_INT");
        break;

    case AST_CHAR: fprintf(stderr, "AST_CHAR");
        break;

    case AST_FLOAT: fprintf(stderr, "AST_FLOAT");
        break;

    case AST_READ: fprintf(stderr, "AST_READ");
        break;

    case AST_BLOCK_COMMAND: fprintf(stderr, "AST_BLOCK_COMMAND");
        break;

    case AST_EXPRESSION_TYPE_A: fprintf(stderr, "EXPRESSION_TYPE_A");
        break;

    case AST_EXPRESSION_TYPE_B: fprintf(stderr, "EXPRESSION_TYPE_B");
        break;

    case AST_EXPRESSION_TYPE_C: fprintf(stderr, "EXPRESSION_TYPE_C");
        break;

    case AST_ASSIGMENT_TYPE_A: fprintf(stderr, "AST_ASSIGMENT_TYPE_A");
        break;

    case AST_ASSIGMENT_TYPE_B: fprintf(stderr, "AST_ASSIGMENT_TYPE_B");
        break;

    default: fprintf(stderr, "AST_UNKNOW");
        break;
    }

    if (node->symbol != 0) {
        fprintf(stderr, ", %s)\n", node->symbol->text);
    }
    else {
        fprintf(stderr, ", 0)\n");
    }

    for (int i=0; i<MAX_SONS; i++)
        astPrint(node->son[i], level+1);
}

void decompile(AST *ast, int level, FILE *out) {
    if (ast == NULL) {
        return;
    }
    else {
        for(int i=0; i<level; i++)
            fprintf(out, "  ");
        switch (ast->type)
        {

        case AST_SYMBOL:
            fprintf(out, "%s", ast->symbol->text);
            break;

        case AST_EXPRESSION_TYPE_A:
            decompile(ast->son[0], 0, out);
            fprintf(out, "(");
            fprintf(out, ")");
            break;

        case AST_EXPRESSION_TYPE_B:
            decompile(ast->son[0], 0, out);
            fprintf(out, "(");
            decompile(ast->son[1], 0, out);
            fprintf(out, ")");
            break;
        
        case AST_EXPRESSION_TYPE_C:
            decompile(ast->son[0], 0, out);
            fprintf(out, " [");
            decompile(ast->son[1], 0, out);
            fprintf(out, "]");
            break;

        case AST_ADD:
            decompile(ast->son[0], 0, out);
            fprintf(out, " + ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_SUB:
            decompile(ast->son[0], 0, out);
            fprintf(out, " - ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_MUL:
            decompile(ast->son[0], 0, out);
            fprintf(out, " * ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_DIV:
            decompile(ast->son[0], 0, out);
            fprintf(out, " / ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_GT:
            decompile(ast->son[0], 0, out);
            fprintf(out, " > ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_LT:
            decompile(ast->son[0], 0, out);
            fprintf(out, " < ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_GE:
            decompile(ast->son[0], 0, out);
            fprintf(out, " >= ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_LE:
            decompile(ast->son[0], 0, out);
            fprintf(out, " <= ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_EQ:
            decompile(ast->son[0], 0, out);
            fprintf(out, " == ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_DIF:
            decompile(ast->son[0], 0, out);
            fprintf(out, " != ");
            decompile(ast->son[1], 0, out);
            break;

        case AST_DECL:
            if (ast->son[0] != NULL) {
                decompile(ast->son[0], level, out);
                decompile(ast->son[1], level, out);
            }
            break;

        case AST_GLOBAL_VARIABLE_TYPE_A:
            decompile(ast->son[0], level, out);
            decompile(ast->son[1], level, out);
            fprintf(out, ": ");
            decompile(ast->son[2], level, out);
            fprintf(out, ";\n");
            break;
        case AST_GLOBAL_VARIABLE_TYPE_B:
            decompile(ast->son[0], level, out);
            decompile(ast->son[1], level, out);
            fprintf(out, "[");
            decompile(ast->son[2], level, out);
            fprintf(out, "]");
            fprintf(out, ";\n");
            break;

        case AST_GLOBAL_VARIABLE_TYPE_C:
            decompile(ast->son[0], level, out);
            decompile(ast->son[1], level, out);
            fprintf(out, "[");
            decompile(ast->son[2], level, out);
            fprintf(out, "]: ");
            decompile(ast->son[3], level, out);
            fprintf(out, ";\n");
            break;

        case AST_LIT_LIST:
            fprintf(out, "");
            fprintf(out, "%s ", ast->symbol->text);
            decompile(ast->son[0], level, out);
            break;
        case AST_INT:
            fprintf(out, "int ");
            break; 
        case AST_CHAR:
            fprintf(out, "char ");
            break; 
        case AST_FLOAT:
            fprintf(out, "float ");
            break;
        case AST_FUNCTION:
            decompile(ast->son[0], level, out);
            decompile(ast->son[1], level, out);
            fprintf(out, "(");
            decompile(ast->son[2], level, out);
            fprintf(out, ")");
            fprintf(out, "\n");
            if (ast->son[3]->type == AST_LCMD) {
                fprintf(out, "{\n");
                decompile(ast->son[3], level, out);
                fprintf(out, "}");
            } else
                decompile(ast->son[3], level, out);
            break;
        
        case AST_FUNCTION_ARGUMENTS:
            if (ast->son[0] != NULL)
                decompile(ast->son[0], level, out);
                fprintf(out, ",");
                if (ast->son[1] != NULL)
                    fprintf(out, " ");
                    decompile(ast->son[1], level, out);
            break;

        case AST_FUNCTION_ARGUMENT:
            decompile(ast->son[0], level, out);
            fprintf(out, " ");
            decompile(ast->son[1], level, out);
            break;

        case AST_ASSIGMENT_TYPE_A:
            decompile(ast->son[0], 0, out);
            fprintf(out, " = ");
            decompile(ast->son[1], 0, out);
            fprintf(out, ";\n");
            break;
        
        case AST_ASSIGMENT_TYPE_B:
            decompile(ast->son[0], 0, out);
            fprintf(out, "[");
            decompile(ast->son[1], 0, out);
            fprintf(out, "]");
            fprintf(out, " = ");
            decompile(ast->son[2], 0, out);
            fprintf(out, ";\n");
            break;
        
        case AST_PRINT_FUN:
            fprintf(out, "print ");
            decompile(ast->son[0], 0, out);
            fprintf(out, ";\n");
            break;
        
        case AST_PRINT_ARGS:
            
            if (ast->son[0] != NULL) {
                decompile(ast->son[0], 0, out);
                if (ast->son[1] != NULL) {
                    fprintf(out, ", ");
                    decompile(ast->son[1], 0, out);
                }
            }
            break;
        case AST_RETURN:
            fprintf(out, "return ");
            decompile(ast->son[0], 0, out);
            fprintf(out, ";\n");
            break;
        case AST_READ:
            fprintf(out, "read");
            break;

        case AST_LCMD:
            decompile(ast->son[0], level, out);
            decompile(ast->son[1], level, out);
            break;

        case AST_WHILE:
            fprintf(out, "while ");
            decompile(ast->son[0], 0, out);
            decompile(ast->son[1], level, out);
            break;

        case AST_IF:
            fprintf(out, "if ");
            decompile(ast->son[0], 0, out);
            fprintf(out, " then \n");
            decompile(ast->son[1], level+1, out);
            fprintf(out, "\n");
            break;
        
        case AST_IF_ELSE:
            fprintf(out, "if ");
            decompile(ast->son[0], 0, out);
            fprintf(out, " then \n");
            decompile(ast->son[1], level+1, out);
            fprintf(out, " else \n");
            decompile(ast->son[2], level+1, out);
            fprintf(out, "\n");
            break;

        case AST_GOTO:
            fprintf(out, "goto ");
            decompile(ast->son[0], 0, out);
            fprintf(out, ";");
            break;

        case AST_LABEL:
            //fprintf(out, "%s", ast->symbol->text);
            decompile(ast->son[0], 0, out);
            fprintf(out, ":\n");
            break;
            


        case AST_BLOCK_COMMAND:
            fprintf(out, "{\n");
            if (ast->son[0] != NULL)
                decompile(ast->son[0], level+1, out);
            for(int i=0; i<level+1; i++)
                fprintf(out, "  ");
            fprintf(out, "}\n");
            break;
        default:
            break;
        }
    }
    return;
}