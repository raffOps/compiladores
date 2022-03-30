%{    
#include "hash.h"
#include "ast.h"
#include "y.tab.h"


int line_number = 1;
int running = 1;

int getLineNumber(void) {
    return line_number;
}

int isRunning(void) {
    return running;
}

void initMe(void) {
  hashInit();
}

int yyerror();
%}

%x comentario

%%

"\\*" {BEGIN(comentario);}
<comentario>"\n"        {line_number++;}
<comentario>"\*\\"     BEGIN(INITIAL);
<comentario>. {}

"\n" {line_number++;}
"\\\\".* {}
[ \t]  {}

\'.\' {yylval.symbol = hashInsert(yytext, SYMBOL_LIT_CHAR); 
        return LIT_CHAR;}

\"[^\"\n]*\"  {yylval.symbol = hashInsert(yytext, SYMBOL_STRING); return LIT_STRING;}


\, {return (int)',' ;}
\; {return (int)';' ;}
\: {return (int)':' ;}
\( {return (int)'(' ;}
\) {return (int)')' ;}
\[ {return (int)'[' ;}
\] {return (int)']' ;}
\{ {return (int)'{' ;}
\} {return (int)'}' ;}
\+ {return (int)'+' ;}
\- {return (int)'-' ;}
\* {return (int)'*' ;}
\/ {return (int)'/'; }
\< {return (int)'<' ;}
\> {return (int)'>' ;}
\= {return (int)'=';}


\<\= {return OPERATOR_LE;}
\>\= {return OPERATOR_GE;}
\=\= {return OPERATOR_EQ;}
\!\= {return OPERATOR_DIF;}

char {return KW_CHAR;}
int {return KW_INT;}
float {return KW_FLOAT;}
if {return KW_IF;}
then {return KW_THEN;}
else {return KW_ELSE;}
while {return KW_WHILE;}
goto {return KW_GOTO;}
read {return KW_READ;}
print {return KW_PRINT;}
return {return KW_RETURN;}


[0-9]+ { yylval.symbol = hashInsert(yytext, SYMBOL_LIT_INT);
         return LIT_INTEGER;}

[a-z_-]+ { yylval.symbol = hashInsert(yytext, SYMBOL_IDENTIFIER); 
            return TK_IDENTIFIER;}

. {return TOKEN_ERROR;}


%%


int yywrap() {
    running = 0;
    return 1;
}

