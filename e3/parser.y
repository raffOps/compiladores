%{
    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"
    int yyerror();
    int getLineNumber();
    int yylex();
    FILE *output = NULL;
%}

%union
{
    HASH_NODE *symbol;
    AST *ast;
}

%token KW_CHAR           
%token KW_INT            
%token KW_FLOAT          
%token KW_IF             
%token KW_THEN           
%token KW_ELSE           
%token KW_WHILE          
%token KW_GOTO           
%token KW_READ           
%token KW_PRINT          
%token KW_RETURN         
%token OPERATOR_LE       
%token OPERATOR_GE       
%token OPERATOR_EQ       
%token OPERATOR_DIF      
%token<symbol> TK_IDENTIFIER

%token<symbol> LIT_INTEGER       
%token<symbol> LIT_CHAR          
%token<symbol> LIT_STRING        
%token TOKEN_ERROR

%type<ast> label
%type<ast> expression 
%type<ast> command_list
%type<ast> simple_command
%type<ast> assignment
%type<ast> parameter_list
%type<ast> print_arguments
%type<ast> print_argument
%type<ast> block_command
%type<ast> control_flow
%type<ast> function
%type<ast> type
%type<ast> function_arguments
%type<ast> function_argument
%type<ast> lit_list
%type<ast> literal
%type<ast> lit_integer
%type<ast> identifier
%type<ast> global_variable
%type<ast> program
%type<ast> decl
%type<ast> dec

%left '*' '/'
%left '+' '-'
%left OPERATOR_EQ OPERATOR_DIF OPERATOR_GE OPERATOR_LE '<' '>'
%right KW_THEN KW_ELSE


%%

program: decl {decompile($1, 0, output);}
    ;

decl: dec decl { $$ = astCreate(AST_DECL, 0, $1, $2, 0, 0);}
    | { $$ = 0;}
    ;

dec: global_variable {$$ = $1;}
    | function {$$ = $1;}
    ;
    
// Declarações de variáveis globais 

type: KW_CHAR { $$ = astCreate(AST_CHAR, 0, 0, 0, 0, 0); }
    | KW_INT { $$ = astCreate(AST_INT, 0, 0, 0, 0, 0); }
    | KW_FLOAT { $$ = astCreate(AST_FLOAT, 0, 0, 0, 0, 0); }
    ;

lit_integer: LIT_INTEGER {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    ;

identifier: TK_IDENTIFIER {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    ;


literal: LIT_CHAR {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | LIT_INTEGER {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | lit_integer '/' lit_integer {$$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
    ;

lit_list: LIT_INTEGER lit_list {$$ = astCreate(AST_LIT_LIST, $1, $2, 0, 0, 0); }
    | LIT_CHAR lit_list {$$ = astCreate(AST_LIT_LIST, $1, $2, 0, 0, 0); }
    | LIT_INTEGER {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | LIT_CHAR {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    ;

global_variable: type identifier ':' literal ';' {$$ = astCreate(AST_GLOBAL_VARIABLE, 0, $1, $2, $4, 0); }
    | type identifier '[' lit_integer ']' ';' {$$ = astCreate(AST_GLOBAL_VARIABLE, 0, $1, $2, $4, 0); }
    | type identifier '[' lit_integer ']' ':' lit_list ';' {$$ = astCreate(AST_GLOBAL_VARIABLE, 0, $1, $2, $4, $7); }
    ;

// Definição de funções 

function_argument: type identifier  { $$ = astCreate(AST_FUNCTION_ARGUMENT, 0, $1, $2, 0, 0); }


function_arguments: function_argument ',' function_arguments  { $$ = astCreate(AST_FUNCTION_ARGUMENTS, 0, $1, $3, 0, 0); }
    | function_argument { $$ = $1;}
    | { $$ = 0;}
    ;

function: type identifier '(' function_arguments ')' simple_command { $$ = astCreate(AST_FUNCTION, 0, $1, $2, $4, $6); }
    ;

// Bloco de Comandos 

block_command: '{' command_list '}'    { $$ = astCreate(AST_BLOCK_COMMAND, 0, $2, 0, 0, 0); }    
    | '{' '}' { $$ = astCreate(AST_BLOCK_COMMAND, 0, 0, 0, 0, 0); }
    ;

label: TK_IDENTIFIER ':' { $$ = astCreate(AST_LABEL, $1, 0, 0, 0, 0); }

command_list: simple_command ';' command_list { $$ = astCreate(AST_LCMD, 0, $1, $3, 0, 0); }
    | label command_list { $$ = astCreate(AST_LCMD, 0, $1, $2, 0, 0); }
    | simple_command ';' { $$ = $1; }
    | label              { $$ = $1; }
    ;
// // Comandos simples 

assignment: TK_IDENTIFIER '=' expression { $$ = astCreate(AST_ASSIGMENT, $1, $3, 0, 0, 0); }
    |  TK_IDENTIFIER '[' expression ']' '=' expression {$$ = astCreate(AST_ASSIGMENT, $1, $3, $6, 0, 0); }
    ;
print_argument: LIT_STRING {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | expression { $$ = $1; }
    ;
print_arguments: print_argument ',' print_arguments {$$ = astCreate(AST_PRINT_ARGS, 0, $1, $3, 0, 0); }
    | print_argument { $$ = $1; }
    ;
simple_command:  assignment  {$$ = $1;} 
    | KW_PRINT print_arguments   { $$ = astCreate(AST_PRINT_FUN, 0, $2, 0, 0,0 ); }
    | KW_RETURN expression  { $$ = astCreate(AST_RETURN, 0, $2, 0, 0, 0 ); }
    | block_command  { $$ = $1; }
    | control_flow  { $$ = $1; }
    ;
// // Expressões Aritméticas 

parameter_list: expression ',' parameter_list {$$ = astCreate(AST_PARAM_LIST, 0, $1, $3, 0, 0); }
    | expression { $$ = $1; }
    ;


expression:   TK_IDENTIFIER '('   ')' {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | TK_IDENTIFIER '(' parameter_list  ')' {$$ = astCreate(AST_SYMBOL, $1, $3,  0, 0, 0); }
    | TK_IDENTIFIER '[' expression ']' {$$ = astCreate(AST_SYMBOL, $1, $3,  0, 0, 0); }
    | TK_IDENTIFIER {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | LIT_INTEGER {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | LIT_CHAR {$$ = astCreate(AST_SYMBOL, $1, 0,  0, 0, 0); }
    | expression '+' expression {$$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
    | expression '-' expression {$$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
    | expression '*' expression {$$ = astCreate(AST_MUL, 0, $1, $3, 0, 0); }
    | expression '/' expression {$$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
    | expression '<' expression {$$ = astCreate(AST_LT, 0, $1, $3, 0, 0); }
    | expression '>' expression {$$ = astCreate(AST_GT, 0, $1, $3, 0, 0); }
    | expression OPERATOR_LE expression {$$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }
    | expression OPERATOR_GE expression {$$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }
    | expression OPERATOR_EQ expression {$$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }
    | expression OPERATOR_DIF expression {$$ = astCreate(AST_DIF, 0, $1, $3, 0, 0); }
    | '(' expression ')' { $$ = $2;}
    | KW_READ {$$ = astCreate(AST_READ, 0, 0, 0, 0, 0); }
    ;

// Comandos de Controle de de Fluxo 

control_flow: KW_IF expression KW_THEN simple_command { $$ = astCreate(AST_IF, 0, $2, $4, 0, 0); }
    | KW_IF expression KW_THEN simple_command KW_ELSE simple_command { $$ = astCreate(AST_IF_ELSE, 0, $2, $4, $6, 0); }
    | KW_WHILE expression simple_command { $$ = astCreate(AST_WHILE, 0, $2, $3, 0, 0); }
    | KW_GOTO identifier { $$ = astCreate(AST_GOTO, 0, $2, 0, 0, 0); }
    ;

%%
int yyerror () {
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}
