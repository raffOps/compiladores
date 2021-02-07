%{
#include <stdio.h>
#include "tokens.h"
%}

%%
<<<<<<< Updated upstream

\/\/.*\n$ {printf("achou comentario 1 linha");}
\/\*.*\*\/ {printf("achou comentario varias linhas");}

^(int)$ {printf("achou palavra reservada int");}
^(float)$ {printf("achou palavra reservada float");}
^(bool)$ {printf("achou palavra reservada bool");}
^(char)$ {printf("achou palavra reservada char");}


^[-|+]?[0-9]+$ {printf("achou inteiro");}

^(false|true)$ {printf("achou booleano");}

%%
=======
\n {line_number++;}

\/\/.* {}
\/\*.*\*\/ {}

\/\*.*[^\*^\/]$ {printf("comentario linha multipla terminando sem o */ "); return TOKEN_ERRO;}
(^\".*\n.*\"$)|(^\".*[^\"]$) {return TOKEN_ERRO;}
^\'..+\' {printf("char com mais de um caractere "); return TOKEN_ERRO;}
^\'\' {printf("char vazio "); return TOKEN_ERRO;}

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
\| {return (int)'|' ;}
\* {return (int)'*' ;}
\/ {return (int)'/'; }

\< {return (int)'<' ;}
\> {return (int)'>' ;}
\= {return (int)'=';}

\! {return (int)'!';}
\& {return (int)'&';}

\% {return (int)'%';}
\# {return (int)'#';}
\^ {return (int)'^';}

\. {return (int)'.';}
\$ {return (int)'$';}

\<\= {return TK_OC_LE;}
\>\= {return TK_OC_GE;}
\=\= {return TK_OC_EQ;}
\!\! {return TK_OC_NE;}

\&\& {return TK_OC_AND;}
\|\| {return TK_OC_OR;}

\>\> {return TK_OC_SL;}
\<\< {return TK_OC_SR;}

int {return TK_PR_INT;}
float {return TK_PR_FLOAT;}
bool {return TK_PR_BOOL;}
char {return TK_PR_CHAR;}
string {return TK_PR_STRING;}
if {return TK_PR_IF;}
then {return TK_PR_THEN;}
else {return TK_PR_ELSE;}
while {return TK_PR_WHILE;}
do {return TK_PR_DO;}
input {return TK_PR_INPUT;}
output {return TK_PR_OUTPUT;}
return {return TK_PR_RETURN;}
const {return TK_PR_CONST;}
static {return TK_PR_STATIC;}
foreach {return TK_PR_FOREACH;}
for {return TK_PR_FOR;}
switch {return TK_PR_SWITCH;}
case {return TK_PR_CASE;}
break {return TK_PR_BREAK;}
continue {return TK_PR_CONTINUE;}
class {return TK_PR_CLASS;}
private {return TK_PR_PRIVATE;}
public {return TK_PR_PUBLIC;}
protected {return TK_PR_PROTECTED;}
end {return TK_PR_END;}
default {return TK_PR_DEFAULT;}

[-|+]?[0-9]+ {return TK_LIT_INT;}
\"[^"]*\" {return TK_LIT_STRING;}
\'.\' {return TK_LIT_CHAR;}
false {return TK_LIT_FALSE;}
true {return TK_LIT_TRUE;}

[a-zA-Z][a-zA-Z0-9_]* {return TK_IDENTIFICADOR;}

>>>>>>> Stashed changes

