	.section	__TEXT,__cstring,cstring_literals
printint: .asciz	"%d\n"

printstring:  .asciz	"%s\n"

	.section	__TEXT,__text,regular,pure_instructions
## TAC_BEGINFUN
	.globl	_main                           
_main:                                 
	pushq	%rbp
	movq	%rsp, %rbp
## TAC_PRINT
	leaq	printint(%rip), %rdi
	movl	_a(%rip), %esi
	movb 	$0, %al
	callq	_printf
## TAC_ENFUN
	popq	%rbp
	retq                           ## -- End function


	.section	__DATA,__data
	.globl	_a                              ## @a
_a: .long	5    