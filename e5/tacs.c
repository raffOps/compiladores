#include "tacs.h"

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2) {
    TAC* newtac = 0;
    newtac = (TAC*) calloc(1, sizeof(TAC));

    newtac->type = type;
    newtac->res = res;
    newtac->op1 = op1;
    newtac->op2 = op2;
    newtac->prev = 0;
    newtac->next = 0;

    return newtac;
}

void tacPrint(TAC* tac) {
    if (!tac ||tac->type == TAC_SYMBOL || tac->type  == TAC_LIT)
        return;

    fprintf(stderr, "TAC(");
    //fprintf(stderr, "    %d    ", tac->type);
    switch (tac->type)
    {
    case TAC_SYMBOL:
        fprintf(stderr, "TAC_SYMBOL");
        break;

    case TAC_LIST:
        fprintf(stderr, "TAC_LIST");
        break;

    case TAC_MOVE:
        fprintf(stderr, "TAC_MOVE");
        break;
    
    case TAC_ADD: fprintf(stderr, "TAC_ADD");
        break;

    case TAC_SUB: fprintf(stderr, "TAC_SUB");
        break;

    case TAC_MUL: fprintf(stderr, "TAC_MUL");
        break;

    case TAC_DIV: fprintf(stderr, "TAC_DIV");
        break;

    case TAC_LE: fprintf(stderr, "TAC_LE");
        break;

    case TAC_LT: fprintf(stderr, "TAC_LT");
        break;

    case TAC_GE: fprintf(stderr, "TAC_GE");
        break;

    case TAC_GT: fprintf(stderr, "TAC_GT");
        break;

    case TAC_EQ: fprintf(stderr, "TAC_EQ");
        break;

    case TAC_DIF: fprintf(stderr, "TAC_DIF");
        break;

    case TAC_FUNCTION_CALL: fprintf(stderr, "TAC_FUNCTION_CALL");
        break;

    case TAC_BEGINGFUN: fprintf(stderr, "TAC_BEGINFUN");
        break;

    case TAC_ENDFUN: fprintf(stderr, "TAC_ENDFUN");
        break;

    case TAC_ARG: fprintf(stderr, "TAC_ARG");
        break;

    case TAC_PRINT: fprintf(stderr, "TAC_PRINT");
        break;

    case TAC_PRINT_ARGS: fprintf(stderr, "TAC_PRINT_ARGS");
        break;

    case TAC_RETURN: fprintf(stderr, "TAC_RETURN");
        break;

    case TAC_ARG_LIST: fprintf(stderr, "TAC_ARG_LIST");
        break;

    case TAC_FUNCTION_PARAMS: fprintf(stderr, "TAC_FUNCTION_PARAMS");
        break; 

    default:
        fprintf(stderr, "TAC_UNKNOW");
        break;
    }

    fprintf(stderr, " %s", (tac->res)?tac->res->text:"0");
    fprintf(stderr, ", %s", (tac->op1)?tac->op1->text:"0");
    fprintf(stderr, ", %s", (tac->op2)?tac->op2->text:"0");
    fprintf(stderr, ");\n");
}
void tacPrintBackwards(TAC* tac) {
    if (!tac) return;
    else {
        tacPrintBackwards(tac->prev);
        tacPrint(tac);
    }
}

TAC* tacJoin(TAC* l1, TAC* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    TAC* point;

    for(point=l2; point->prev!=0; point=point->prev) {
        ;
    }
    point->prev = l1;
    return l2;
}


int getTacType(int nodeType) {
    int tacType;
    switch (nodeType) {
    
    case AST_INT_LIST:
    case AST_CHAR_LIST:
        tacType = TAC_LIST;
        break;

    case AST_ADD:
        tacType = TAC_ADD;
        break;
    case AST_SUB:
        tacType = TAC_SUB;
        break;
    case AST_MUL:
        tacType = TAC_MUL;
        break;
    case AST_DIV:
        tacType = TAC_DIV;
        break;
    case AST_LE:
        tacType = TAC_DIV;
        break;   
    case AST_LT:
        tacType = TAC_LT;
        break;
    case AST_GE:
        tacType = TAC_GE;
        break;           
    case AST_GT:
        tacType = TAC_GT;
        break;
    case AST_EQ:
        tacType = TAC_EQ;
        break;        
    case AST_DIF:
        tacType = TAC_DIF;
        break;
    case AST_PRINT_FUN:
        tacType = TAC_PRINT;
        break;

    case AST_RETURN:
        tacType = TAC_RETURN;
        break;

    case AST_PRINT_ARGS:
        tacType = TAC_PRINT_ARGS;
        break;

    case AST_ARG_LIST:
        tacType = TAC_ARG_LIST;
        break;
    case AST_FUNCTION_PARAMS:
        tacType = TAC_FUNCTION_PARAMS;
    default:
        break;
    }
    return tacType;
}



TAC* generateCode(AST* node) {

    

    TAC* result = 0;
    TAC* preResult = 0;

    TAC* code[MAX_SONS];

    if (!node) return 0;

    for(int i=0; i<MAX_SONS; ++i) {
        code[i] = generateCode(node->son[i]);
    }

    //fprintf(stderr, "    %d    ", node->type);
    switch (node->type) {

        case AST_GLOBAL_VARIABLE_TYPE_A:
            preResult = tacCreate(TAC_MOVE, node->symbol, 
                                         code[0]?code[0]->res:0, 
                                         code[1]?code[1]->res:0);
            result = tacJoin(code[0], tacJoin(code[1], preResult));
            break;

        case AST_GLOBAL_VARIABLE_TYPE_B:
        case AST_GLOBAL_VARIABLE_TYPE_C:
            preResult = tacCreate(TAC_MOVE, node->symbol, 
                                         code[1]?code[1]->res:0, 
                                         code[2]?code[2]->res:0);
            result = tacJoin(code[1], tacJoin(code[2], preResult));
            break;


        case AST_ASSIGMENT_TYPE_A:
            preResult = tacCreate(TAC_MOVE, node->symbol, 
                                         code[0]?code[0]->res:0, 
                                         code[1]?code[1]->res:0);
            result = tacJoin(code[0], tacJoin(code[1], preResult));
            break;


        case AST_SYMBOL:
            result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
            break;

        case AST_INT:
        case AST_CHAR:
        case AST_STR:
            result = tacCreate(TAC_LIT, node->symbol, 0, 0);
            break;

        case AST_RETURN:
        case AST_PRINT_FUN:
            preResult = tacCreate(getTacType(node->type), node->symbol, 
                                        code[0]?code[0]->res:0, 
                                        0);
            result = tacJoin(code[0], preResult);
            break;

        case AST_INT_LIST:
        case AST_CHAR_LIST:
        case AST_PRINT_ARGS:
        case AST_FUNCTION_PARAMS:
        case AST_ARG_LIST:
        case AST_ADD:
        case AST_SUB:
        case AST_MUL:
        case AST_DIV:
        case AST_LE:
        case AST_LT:
        case AST_GE:
        case AST_GT:
        case AST_EQ:
        case AST_DIF:
            preResult = tacCreate(getTacType(node->type), makeTemp(), 
                                        code[0]?code[0]->res:0, 
                                        code[1]?code[1]->res:0);
            result = tacJoin(code[0], tacJoin(code[1], preResult));
            break;


        case AST_FUNCTION:
            result = tacJoin(tacCreate(TAC_BEGINGFUN, node->symbol, 0, 0), 
                            tacJoin(code[1], 
                                tacJoin(code[2], 
                                    tacCreate(TAC_ENDFUN, node->symbol, 0, 0))
                                )
                            );
            break;

    

        default:
            result = tacJoin(code[0], 
                            tacJoin(code[1], 
                                    tacJoin(code[2], code[3]
                                    )
                                )
                            );
            break;
    }

    return result;
}




