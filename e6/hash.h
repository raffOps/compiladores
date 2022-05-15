#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>

#define HASH_SIZE 997
#define SYMBOL_IDENTIFIER 1
#define SYMBOL_VARIABLE_INT 2
#define SYMBOL_STRING 3
#define SYMBOL_VARIABLE_CHAR 4
#define SYMBOL_TRUE 5
#define SYMBOL_FALSE 6
#define SYMBOL_VARIABLE 7
#define SYMBOL_FUNCTION 8
#define SYMBOL_VECTOR 9
#define SYMBOL_VARIABLE_FLOAT 10 
#define SYMBOL_FUNCTION_INT 11
#define SYMBOL_FUNCTION_FLOAT 12
#define SYMBOL_FUNCTION_CHAR 13
#define SYMBOL_LIT_INT 14
#define SYMBOL_LIT_FLOAT 15
#define SYMBOL_LIT_CHAR 16
#define SYMBOL_LABEL 17


#define DATATYPE_INT 1
#define DATATYPE_FLOAT 2
#define DATATYPE_CHAR 3
#define DATATYPE_STRING 4

typedef struct hash_node {
   int type;
   int datatype;
   char *text;
   struct hash_node * next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int type);
void hashPrint();
int hashCheckUndeclared(void);
HASH_NODE *makeTemp(void);
HASH_NODE *makeLabel(void);

#endif