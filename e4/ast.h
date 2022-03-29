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
#define AST_DECL 31
#define AST_INT 32
#define AST_CHAR 33
#define AST_FLOAT 34
#define AST_READ 35
#define AST_BLOCK_COMMAND 36
#define AST_FUNCTION_CALL_TYPE_A 37
#define AST_FUNCTION_CALL_TYPE_B 38
#define AST_EXPRESSION_TYPE_C 39
#define AST_GLOBAL_VARIABLE_TYPE_A 40
#define AST_GLOBAL_VARIABLE_TYPE_B 41
#define AST_GLOBAL_VARIABLE_TYPE_C 42
#define AST_ASSIGMENT_TYPE_A 43
#define AST_ASSIGMENT_TYPE_B 44
#define AST_EMPTY_COMMAND 45

#define AST_VAR_DEC 46
#define AST_FUNCTION_DEC 47
#define AST_STR 48
#define AST_KW_INT 49
#define AST_KW_FLOAT 50
#define AST_KW_CHAR 51


typedef struct astnode {
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);
void decompile(AST *ast, int level, FILE *out);


#endif