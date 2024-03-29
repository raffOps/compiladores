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


    case TAC_JUMP: fprintf(stderr, "TAC_JUMP");
        break; 

    case TAC_JUMPZ: fprintf(stderr, "TAC_JUMPZ");
        break; 

    case TAC_LABEL: fprintf(stderr, "TAC_LABEL");
        break; 

    case TAC_VEC_READ: fprintf(stderr, "TAC_VEC_READ");
        break; 

    case TAC_READ: fprintf(stderr, "TAC_READ");
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

        case AST_READ:
            result = tacCreate(TAC_READ, 0, 0, 0);
            break;

        case AST_RETURN:
            preResult = tacCreate(TAC_RETURN, code[0]?code[0]->res:0, 0, 0);
            result = tacJoin(code[0], preResult);
            break;
        case AST_PRINT_FUN:
            result = code[0];
            break;
        case AST_PRINT_ARGS: 
            preResult = tacCreate(TAC_PRINT, 
                                node->symbol, 
                                code[0]?code[0]->res:0, 
                                0); 
            result = tacJoin(code[1], preResult);
            break;

        case AST_INT_LIST: 
            result = makeBinOperation(TAC_LIST, code[0], code[1]); 
            break;
        case AST_CHAR_LIST:
            result = makeBinOperation(TAC_LIST, code[0], code[1]); 
            break;
        case AST_FUNCTION_PARAMS:
            result = makeBinOperation(TAC_FUNCTION_PARAMS, code[0], code[1]); 
            break;
        case AST_ARG_LIST: 
            result = makeBinOperation(TAC_ARG_LIST, code[0], code[1]); 
            break;
        case AST_ADD: 
            result = makeBinOperation(TAC_ADD, code[0], code[1]); 
            break;
        case AST_SUB: 
            result = makeBinOperation(TAC_SUB, code[0], code[1]); 
            break;
        case AST_MUL: 
            result = makeBinOperation(TAC_MUL, code[0], code[1]); 
            break;
        case AST_DIV:
            result = makeBinOperation(TAC_DIV, code[0], code[1]);
            break;
        case AST_LE: 
            result = makeBinOperation(TAC_LE, code[0], code[1]); 
            break;
        case AST_LT: 
            result = makeBinOperation(TAC_LT, code[0], code[1]); 
            break;
        case AST_GE: 
            result = makeBinOperation(TAC_GE, code[0], code[1]); 
            break;
        case AST_GT: 
            result = makeBinOperation(TAC_GT, code[0], code[1]); 
            break;
        case AST_EQ: 
            result = makeBinOperation(TAC_EQ, code[0], code[1]); 
            break;
        case AST_DIF:
            result = makeBinOperation(TAC_DIF, code[0], code[1]); 
            break;

        case AST_FUNCTION_CALL_TYPE_A:
        case AST_FUNCTION_CALL_TYPE_B:
            preResult = tacCreate(TAC_FUNCTION_CALL, node->symbol, 
                                        code[0]?code[0]->res:0, 
                                        code[1]?code[1]->res:0);
            result = tacJoin(code[1], tacJoin(code[0], preResult));
            break;
        case AST_FUNCTION:
            preResult = tacJoin(tacJoin(tacCreate(TAC_BEGINGFUN, node->symbol, 
                                            0, 
                                            code[1]?code[1]->res:0),
                                code[2]), 
                                    tacCreate(TAC_ENDFUN, node->symbol, 0, 0));

            result = tacJoin(code[1], preResult);
            break;

        case AST_EXPRESSION_TYPE_C:
            preResult = tacCreate(TAC_VEC_READ, makeTemp(),  node->symbol, code[0]?code[0]->res:0);
            result = tacJoin(code[0], preResult);
            break;

        case AST_IF:
            result = makeIfThen(code[0], code[1]);
            break;

        case AST_IF_ELSE:
            result = makeIfThenElse(code[0], code[1], code[2]);
            break;

        case AST_WHILE:
            result = makeWhile(code[0], code[1]);
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

TAC* makeBinOperation(int type, TAC* code0, TAC* code1) {
    TAC* preResult = 0;
    preResult = tacCreate(type, makeTemp(), 
                                        code0?code0->res:0, 
                                        code1?code1->res:0);
    return tacJoin(code0, tacJoin(code1, preResult));

}

TAC* makeIfThen(TAC* code0, TAC* code1) {
    TAC* jumpztac = 0;
    TAC* labeltac = 0;

    HASH_NODE* falseLabel = 0;
    falseLabel = makeLabel();

    jumpztac = tacCreate(TAC_JUMPZ, falseLabel, code0?code0->res:0, 0);
    
    labeltac = tacCreate(TAC_LABEL, falseLabel, 0, 0);
    return tacJoin(code0,
                    tacJoin(jumpztac, 
                            tacJoin(code1, labeltac)));
}

TAC* makeIfThenElse(TAC* code0, TAC* code1, TAC* code2) {
    TAC* jumpztac = 0;
    TAC* jumpzlabelTAC = 0;
    TAC* jumptac = 0;
    TAC* jumplabelTAC = 0;

    HASH_NODE* jumpzlabel = 0;
    jumpzlabel = makeLabel();

    HASH_NODE* jumplabel = 0;
    jumplabel = makeLabel();


    jumpztac = tacCreate(TAC_JUMPZ, jumpzlabel, code0?code0->res:0, 0);
    jumpzlabelTAC = tacCreate(TAC_LABEL, jumpzlabel, 0, 0);
    
    jumptac = tacCreate(TAC_JUMP, jumplabel, 0, 0);    
    jumplabelTAC = tacCreate(TAC_LABEL, jumplabel, 0, 0);


    return tacJoin(code0,
                    tacJoin(jumpztac, 
                            tacJoin(code1, 
                                tacJoin(jumptac,
                                    tacJoin(jumpzlabelTAC, 
                                        tacJoin(code2, jumplabelTAC))))));
}


TAC* makeWhile(TAC* code0, TAC* code1) {
    TAC* whileTAC = 0;
    TAC* whilelabelTAC = 0;
    TAC* jumptac = 0;
    TAC* jumplabelTAC = 0;

    HASH_NODE* whilelabel = 0;
    whilelabel = makeLabel();

    HASH_NODE* jumplabel = 0;
    jumplabel = makeLabel();

    whileTAC = tacCreate(TAC_JUMPZ, whilelabel, code0?code0->res:0, 0);
    whilelabelTAC = tacCreate(TAC_LABEL, whilelabel, 0, 0);
    
    jumptac = tacCreate(TAC_JUMP, jumplabel, 0, 0);    
    jumplabelTAC = tacCreate(TAC_LABEL, jumplabel, 0, 0);



    return tacJoin(jumplabelTAC,
                tacJoin(code0,
                        tacJoin(whileTAC,
                            tacJoin(code1,
                                tacJoin(jumptac, whilelabelTAC)))));

}



