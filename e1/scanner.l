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
<comentario><<EOF>>    {BEGIN(INITIAL); return TOKEN_ERROR;}
<INITIAL,comentario>\n {line_number++;}

"//".*$ {}

\'\' {return TOKEN_ERROR;}
\'.\' {return LIT_CHAR;}
'..+' {return TOKEN_ERROR;}
'.[^']+ {return TOKEN_ERROR;}

[-|+]?[0-9]+\.[^0-9|\n]* {return TOKEN_ERROR;}
[0-9]\.[0-9]+e[^0-9|\n]* {return TOKEN_ERROR;}
[-|+]?[0-9]+[a-zA-z]+ {return TOKEN_ERROR;}
\.[0-9]* {return TOKEN_ERROR;}


\"[^\"|\n]*\"  {return LIT_STRING;}
\"[^\n|\"]* {return TOKEN_ERROR;}

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


[-|+]?[0-9]+ {return LIT_INTEGER;}

[a-zA-Z][a-zA-Z0-9_]* {return TK_IDENTIFIER;}

%%

