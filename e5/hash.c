#include "hash.h"
#include <string.h>
#include <stdlib.h>

HASH_NODE*Table[HASH_SIZE];

void hashInit(void) {
    int i;
    for (i=0; i<HASH_SIZE; i++)
        Table[i]=0;
}

int hashAddress(char *text) {
    int address = 1;
    int i;
    for(i=0; i<strlen(text); ++i)
        address = (address * text[i]) % HASH_SIZE + 1;
    return address-1;
}

HASH_NODE *hashFind(char *text) {
    HASH_NODE *node;
    int address = hashAddress(text);
    for (node=Table[address]; node; node=node->next)
        if (strcmp(node->text, text) == 0)
            return node;
    return 0;
}

HASH_NODE *hashInsert(char *text, int type) {
    HASH_NODE *newnode;
    int address = hashAddress(text);
    if ((newnode = hashFind(text)) != 0)
    
        return newnode;
    newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newnode->type = type;
    newnode->text = (char*) calloc(strlen(text)+1, sizeof(char));
    strcpy(newnode->text, text);
    newnode->next = Table[address];
    Table[address] = newnode;
    return newnode;
}

void hashPrint(void) {
    int i;
    HASH_NODE *node;
    char *symbol_name;
    for (i=0;i<HASH_SIZE; ++i) {
        for (node=Table[i]; node; node = node->next) {
            switch (node->type)
            {
            case SYMBOL_VARIABLE:
                printf("Table[%d] has %s with type %s, datatype %d\n", i, node->text, "Variable", node->datatype);
                break;

            case SYMBOL_FUNCTION:
                printf("Table[%d] has %s with type %s, datatype %d\n", i, node->text, "Function", node->datatype);
                break;

            case SYMBOL_VARIABLE_INT:
            case SYMBOL_VARIABLE_CHAR:
            case SYMBOL_VARIABLE_FLOAT: 
                printf("Table[%d] has %s with type %s, datatype %d\n", i, node->text, "Variable", node->datatype); 
                break;

            case SYMBOL_LIT_CHAR:
            case SYMBOL_LIT_FLOAT:
            case SYMBOL_LIT_INT:
                printf("Table[%d] has %s with type %s\n", i, node->text, "Literal"); 
                break;

            default:
                printf("Table[%d] has %s with type %s\n", i, node->text, "undefined");
                break;
            }
        }
    }
}

int hashCheckUndeclared(void) {

    int i;
    int undeclared = 0;
    HASH_NODE *node;
    char *symbol_name;
    for (i=0;i<HASH_SIZE; ++i) {
        for (node=Table[i]; node; node = node->next) {
            if (node->type == SYMBOL_IDENTIFIER) {
                fprintf(stdout, "Semantic ERROR: %s undeclared\n", node->text);
                ++undeclared;
            }
        }
    }
    return undeclared;
}

HASH_NODE *makeTemp(void) {
    static int serial = 0;
    char buffer[256];

    sprintf(buffer, "__temp%d", serial++);
    return hashInsert(buffer, SYMBOL_VARIABLE);
}