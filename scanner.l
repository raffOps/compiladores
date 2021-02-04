%{
#include <stdio.h>
#include "tokens.h"
// #include "main.c"
%}

%%

\/\/.*\n$ {printf("achou comentario 1 linha");}
\/\*.*\*\/ {printf("achou comentario varias linhas");}

^\,$ {printf("achou virgula"); return (int)',' ;}
^\;$ {printf("achou ponto e virgula"); return (int)';' ;}
^\:$ {printf("achou dois pontos"); return (int)':' ;}

^\($ {printf("achou abre parenteses"); return (int)'(' ;}
^\)$ {printf("achou fecha parenteses"); return (int)')';}

^\[$ {printf("achou abre colchetes"); return (int)'[';}
^\]$ {printf("achou fecha_colchetes"); return (int)']' ;}

^\{$ {printf("achou abre chaves"); return (int)'{' ;}
^\}$ {printf("achou fecha chaves"); return (int)'}' ;}

^\+$ {printf("achou mais"); return (int)'+' ;}
^\-$ {printf("achou menos"); return (int)'-' ;}
^\|$ {printf("achou pipe"); return (int)'|' ;}
^\*$ {printf("achou asterisco"); return (int)'*' ;}
^\/$ {printf("achou / "); return (int)'/'; }

^\<$ {printf("achou menor que"); return (int)'<' ;}
^\>$ {printf("achou maior que"); return (int)'>' ;}
^\=$ {printf("achou igual "); return (int)'='; }

^\!$ {printf("achou exclamacao "); return (int)'!'; }
^\&$ {printf("achou e comercial "); return (int)'&'; }

^\%$ {printf("achou porcento "); return (int)'%'; }
^\#$ {printf("achou hashtag "); return (int)'#'; }
^\^$ {printf("achou circunflexo "); return (int)'^'; }

^\.$ {printf("achou ponto "); return (int)'.'; }
^\$$ {printf("achou dolar "); return (int)'$'; }

^\<\=$ {printf("achou menor ou igual  "); return TK_OC_LE; }
^\>\=$ {printf("achou maior ou igual "); return TK_OC_GE; }
^\=\=$ {printf("achou igualdade "); return TK_OC_EQ; }
^\!\!$ {printf("achou diferenca "); return TK_OC_NE; }

^\&\&$ {printf("achou and "); return TK_OC_AND; }
^\|\|$ {printf("achou or "); return TK_OC_OR; }

^\>\>$ {printf("achou shift esquerda "); return TK_OC_SL; }
^\<\<$ {printf("achou shift direito "); return TK_OC_SR; }






^(int)$ {printf("achou palavra reservada int"); return TK_PR_INT;}
^(float)$ {printf("achou palavra reservada float"); return TK_PR_FLOAT;}
^(bool)$ {printf("achou palavra reservada bool"); return TK_PR_BOOL;}
^(char)$ {printf("achou palavra reservada char"); return TK_PR_CHAR;}
^(string)$ {printf("achou palavra reservada string"); return TK_PR_STRING;}
^(if)$ {printf("achou palavra reservada if"); return TK_PR_IF;}
^(then)$ {printf("achou palavra reservada then"); return TK_PR_THEN;}
^(else)$ {printf("achou palavra reservada else"); return TK_PR_ELSE;}
^(while)$ {printf("achou palavra reservada while"); return TK_PR_WHILE;}
^(do)$ {printf("achou palavra resrvada do"); return TK_PR_DO;}
^(input)$ {printf("achou palavra reservada input"); return TK_PR_INPUT;}
^(output)$ {printf("achou palavra reservada output"); return TK_PR_OUTPUT;}
^(return)$ {printf("achou palavra reservada return"); return TK_PR_RETURN;}
^(const)$ {printf("achou palavra reservada const"); return TK_PR_CONST;}
^(static)$ {printf("achou palavra reservada static"); return TK_PR_STATIC;}
^(foreach)$ {printf("achou palavra reservada foreach"); return TK_PR_FOREACH;}
^(for)$ {printf("achou palavra reservada for"); return TK_PR_FOR;}
^(switch)$ {printf("achou palavra reservada switch"); return TK_PR_SWITCH;}
^(case)$ {printf("achou palavra reservada case"); return TK_PR_CASE;}
^(break)$ {printf("achou palavra reservada break"); return TK_PR_BREAK;}
^(continue)$ {printf("achou palavra reservada continue"); return TK_PR_CONTINUE;}
^(class)$ {printf("achou palavra reservada class"); return TK_PR_CLASS;}
^(private)$ {printf("achou palavra reservada private"); return TK_PR_PRIVATE;}
^(public)$ {printf("achou palavra reservada public"); return TK_PR_PUBLIC;}
^(protected)$ {printf("achou palavra reservada protected"); return TK_PR_PROTECTED;}
^(end)$ {printf("achou palavra reservada end"); return TK_PR_END;}
^(default)$ {printf("achou palavra reservada default"); return TK_PR_DEFAULT;}





^[-|+]?[0-9]+$ {printf("achou inteiro");}

^(false|true)$ {printf("achou booleano");}

%%