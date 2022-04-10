#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"
#include <stdlib.h>

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_LIST 6
#define TAC_FUNCTION_CALL 7
#define TAC_BEGINGFUN 8
#define TAC_ENDFUN 9
#define TAC_ARG 10
#define TAC_ARG_LIST 11
#define TAC_PRINT 12
#define TAC_PRINT_ARGS 13
#define TAC_RETURN 14
#define TAC_LE 15
#define TAC_LT 16
#define TAC_GE 17
#define TAC_GT 18
#define TAC_EQ 19
#define TAC_DIF 20
#define TAC_FUNCTION_PARAMS 21
#define TAC_IFZ 22
#define TAC_JUMP 23
#define TAC_JUMPZ 24
#define TAC_LABEL 25
#define TAC_MOVE 30

#define TAC_LIT 40

typedef struct tac_node
{
    int type;
    HASH_NODE* res;
    HASH_NODE* op1;
    HASH_NODE* op2; 

    struct tac_node* prev;
    struct tac_node* next;

} TAC;


TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
void tacPrint(TAC* tac);
void tacPrintBackwards(TAC* tac);
TAC* generateCode(AST* node);
TAC* makeIfThen(TAC* code0, TAC* code1);
TAC* makeIfThenElse(TAC* code0, TAC* code1, TAC* code2);

#endif

