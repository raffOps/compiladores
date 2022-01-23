#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int main(int argc, char **argv) {
    char filename[] = "in2.txt";
    char charSet[] = {';', ' ', '\t' };
    char character;
    FILE *fptr;

    if ((fptr = fopen(filename,"r")) == NULL){
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    int counter = 0;
    bool isSpace = false;
    while ((character = fgetc(fptr)) != EOF)
    {
        if((strchr(charSet, character) != NULL ) && !(isSpace)) {
            counter++;
            isSpace = true;
        } else if (character == '\n') {
            printf("%d ", counter);
            counter = 0;
        }
        else {
            isSpace = false;
        }
    }
    printf("%d ", counter);
    fclose(fptr);
}