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

%%

programa: decl
    ;

decl: dec decl
    |
    ;

// dec: global_variable
//     | function
//     ;

dec: expression
    
// Declarações de variáveis globais 

type: KW_CHAR 
    | KW_INT 
    | KW_FLOAT
    ;

float_: LIT_INTEGER '/' LIT_INTEGER
    ;

literal: LIT_CHAR
    | LIT_INTEGER
    | float_
    ;


// list: integer_list
//     | char_list
//     ;

// integer_list: LIT_INTEGER integer_list
//     | LIT_INTEGER
//     ;

// char_list: LIT_CHAR char_list
//     | LIT_CHAR
//     ;



// global_variable: type TK_IDENTIFIER ':' literal ';'
//     | type TK_IDENTIFIER '[' LIT_INTEGER ']' ';' 
//     | type TK_IDENTIFIER '[' LIT_INTEGER ']' ':' list ';'
//     ;

// Definição de funções 

// function_argument: type TK_IDENTIFIER

// function_arguments: function_argument ',' function_arguments 
//     | function_argument
//     ;

// function_header: type TK_IDENTIFIER '(' function_arguments ')'
//     | type TK_IDENTIFIER '(' ')'
//     ;

// function: function_header 
//     ;

// Bloco de Comandos 

// block_command: '{' command_list '}'
//     ;

// command_list: simple_command ';' | command_list
//     | simple_command ';'
//     ;
// Comandos simples 

// assignment: TK_IDENTIFIER '=' expression
//     |  TK_IDENTIFIER '[' expression ']' '=' expression
//     ;
// print_argument: LIT_STRING
//     | expression
//     ;
// print_arguments: print_argument ',' print_arguments
//     | print_argument
//     ;
// simple_command:  assignment
//     | KW_PRINT print_arguments
//     | KW_RETURN expression
//     | block_command
//     |
//     ;
// Expressões Aritméticas 

operand: TK_IDENTIFIER
    | TK_IDENTIFIER '[' LIT_INTEGER ']'
    | LIT_CHAR
    | LIT_INTEGER
    ;

operator: '+'
    | '-'
    | '*'
    | '/'
    | OPERATOR_LE
    | OPERATOR_GE
    | OPERATOR_LE OPERATOR_EQ  
    | OPERATOR_GE OPERATOR_EQ
    | OPERATOR_EQ
    | OPERATOR_DIF
    ;


expression: operand
    | operand aux_expression

aux_expression: operator aux_expression 
    | operand



%%
int yyerror () {
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}
