#include "hash.h"
#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_GT 6
#define AST_LT 7
#define AST_GE 8
#define AST_LE 9
#define AST_EQ 10
#define AST_DIF 11
#define AST_LCMD 12
#define AST_LABEL 13
#define AST_ASSIGMENT 14
#define AST_PARAM_LIST 15
#define AST_PRINT_FUN 16
#define AST_PRINT_ARGS 17
#define AST_RETURN 18
#define AST_IF 19
#define AST_IF_ELSE 20
#define AST_THEN 21
#define AST_WHILE 22
#define AST_GOTO 23
#define AST_FUNCTION 24
#define AST_FUNCTION_ARGUMENTS 27
#define AST_FUNCTION_ARGUMENT 28
#define AST_LIT_LIST 29
#define AST_GLOBAL_VARIABLE 30
#define AST_DECL 31

typedef struct astnode {
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);


#endif