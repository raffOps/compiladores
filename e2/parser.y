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
%token TK_IDENTIFIER     
%token LIT_INTEGER       
%token LIT_CHAR          
%token LIT_STRING        
%token TOKEN_ERROR       

%left '*' '/'
%left '+' '-'
%left OPERATOR_EQ OPERATOR_DIF OPERATOR_GE OPERATOR_LE '<' '>'


%%

programa: decl
    ;

decl: dec decl
    |
    ;

dec: global_variable
    | function
    ;
    
// Declarações de variáveis globais 

type: KW_CHAR 
    | KW_INT 
    ;

float_: LIT_INTEGER '/' LIT_INTEGER
    ;

literal: LIT_CHAR
    | LIT_INTEGER
    ;


list: LIT_INTEGER list
    | LIT_CHAR list
    | LIT_INTEGER
    | LIT_CHAR
    ;

global_variable: type TK_IDENTIFIER ':' literal ';'
    | KW_FLOAT TK_IDENTIFIER ':' float_ ';'
    | type TK_IDENTIFIER '[' LIT_INTEGER ']' ';' 
    | type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' list ';'
    ;

// Definição de funções 

function_argument: type TK_IDENTIFIER

function_arguments: function_argument ',' function_arguments 
    | function_argument
    ;

function_header: type TK_IDENTIFIER '(' function_arguments ')'
    | type TK_IDENTIFIER '(' ')'
    ;

function_body: block_command
    ;


function: function_header function_body
    ;

// Bloco de Comandos 

block_command: '{' command_list '}'
    | '{' '}'
    ;

label: TK_IDENTIFIER ':'

command_list: simple_command ';' command_list
    | label command_list
    | simple_command ';'
    | label
    ;
// // Comandos simples 

assignment: TK_IDENTIFIER '=' expression
    |  TK_IDENTIFIER '[' expression ']' '=' expression
    ;
print_argument: LIT_STRING
    | expression
    ;
print_arguments: print_argument ',' print_arguments
    | print_argument
    ;
simple_command:  assignment 
    | KW_PRINT print_arguments 
    | KW_RETURN expression 
    | block_command 
    | control_flow 
    ;
// // Expressões Aritméticas 

parameter_list: expression ',' parameter_list
    | expression
    ;


expression:   TK_IDENTIFIER '('   ')'
    | TK_IDENTIFIER '(' parameter_list  ')'
    | TK_IDENTIFIER '[' expression ']'
    | TK_IDENTIFIER 
    | LIT_INTEGER
    | LIT_CHAR
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | expression '<' expression
    | expression '>' expression
    | expression OPERATOR_LE expression
    | expression OPERATOR_GE expression
    | expression OPERATOR_EQ expression
    | expression OPERATOR_DIF expression
    | '(' expression ')'
    | KW_READ
    ;

// Comandos de Controle de de Fluxo 

control_flow: KW_IF expression KW_THEN simple_command
    | KW_IF expression KW_THEN simple_command KW_ELSE simple_command
    | KW_WHILE expression simple_command
    | KW_GOTO TK_IDENTIFIER
    ;
%%
int yyerror () {
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}
