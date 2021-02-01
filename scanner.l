%{
#include <stdio.h>
#include "tokens.h"
%}

%%

\/\/.*\n$ {printf("achou comentario 1 linha");}
\/\*.*\*\/ {printf("achou comentario varias linhas");}

^(int)$ {printf("achou palavra reservada int");}
^(float)$ {printf("achou palavra reservada float");}
^(bool)$ {printf("achou palavra reservada bool");}
^(char)$ {printf("achou palavra reservada char");}


^[-|+]?[0-9]+$ {printf("achou inteiro");}

^(false|true)$ {printf("achou booleano");}

%%

