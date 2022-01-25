%{
#include <stdio.h>
#include "tokens.h"
#include "main.c"
int line_number = 1;

int get_line_number(void) {
    return line_number;
}
%}

%x comentario

%%

"/*" {BEGIN(comentario);}
<comentario>[^*\n]*        /* eat anything that's not a '*' */
<comentario>"*"+[^*/\n]*   /* eat up '*'s not followed by '/'s */
<comentario>"*"+"/"        BEGIN(INITIAL);
<comentario><<EOF>>    {BEGIN(INITIAL); return TOKEN_ERRO;}
<INITIAL,comentario>\n {line_number++;}

"//".*$ {}

\'\' {return TOKEN_ERRO;}
\'.\' {return TK_LIT_CHAR;}
'..+' {return TOKEN_ERRO;}
'.[^']+ {return TOKEN_ERRO;}

[-|+]?[0-9]+\.[^0-9|\n]* {return TOKEN_ERRO;}
[0-9]\.[0-9]+e[^0-9|\n]* {return TOKEN_ERRO;}
[-|+]?[0-9]+[a-zA-z]+ {return TOKEN_ERRO;}
\.[0-9]* {return TOKEN_ERRO;}


\"[^\"|\n]*\"  {return TK_LIT_STRING;}
\"[^\n|\"]* {return TOKEN_ERRO;}

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


int {return KW_INT;}
float {return KW_FLOAT;}
bool {return KW_BOOL;}
char {return KW_CHAR;}
string {return KW_STRING;}
if {return KW_IF;}
then {return KW_THEN;}
else {return KW_ELSE;}
while {return KW_WHILE;}
goto {return KW_GOTO;}
read {return KW_READ;}
print {return KW_PRINT;}
return {return KW_RETURN;}


[-|+]?[0-9]+ {return LIT_INTEGER;}
[-|+]?[0-9]+\.[0-9]+|[0-9]\.[0-9]+e[\+|\-]?[0-9]+ {return LIT_FLOAT;}


[a-zA-Z][a-zA-Z0-9_]* {return TK_IDENTIFICADOR;}

%%

