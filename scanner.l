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
^(string)$ {printf("achou palavra reservada string");}
^(if)$ {printf("achou palavra reservada if");}
^(then)$ {printf("achou palavra reservada then");}
^(else)$ {printf("achou palavra reservada else");}
^(while)$ {printf("achou palavra reservada while");}
^(do)$ {printf("achou palavra resrvada do");}
^(input)$ {printf("achou palavra reservada input");}
^(output)$ {printf("achou palavra reservada output");}
^(return)$ {printf("achou palavra reservada return");}
^(const)$ {printf("achou palavra reservada const");}
^(static)$ {printf("achou palavra reservada static");}
^(foreach)$ {printf("achou palavra reservada foreach");}
^(for)$ {printf("achou palavra reservada for");}
^(switch)$ {printf("achou palavra reservada switch");}
^(case)$ {printf("achou palavra reservada case");}
^(break)$ {printf("achou palavra reservada break");}
^(continue)$ {printf("achou palavra reservada continue");}
^(class)$ {printf("achou palavra reservada class");}
^(private)$ {printf("achou palavra reservada private");}
^(public)$ {printf("achou palavra reservada public");}
^(protected)$ {printf("achou palavra reservada protected");}
^(end)$ {printf("achou palavra reservada end");}
^(default)$ {printf("achou palavra reservada default");}

^\,$ {printf("achou virgula"); return (int)',';}



^[-|+]?[0-9]+$ {printf("achou inteiro");}

^(false|true)$ {printf("achou booleano");}

%%