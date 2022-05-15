	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 1
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	_x(%rip), %eax
	cmpl	_y(%rip), %eax
	setl	%al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, _a(%rip)
	movl	_a(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	_x(%rip), %eax
	cmpl	_y(%rip), %eax
	setg	%al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, _b(%rip)
	movl	_b(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	_x(%rip), %eax
	cmpl	_y(%rip), %eax
	setge	%al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, _c(%rip)
	movl	_c(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	_x(%rip), %eax
	cmpl	_y(%rip), %eax
	setle	%al
	andb	$1, %al
	movzbl	%al, %eax
	movl	%eax, _d(%rip)
	movl	_d(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_a                              ## @a
.zerofill __DATA,__common,_a,4,2
	.globl	_b                              ## @b
.zerofill __DATA,__common,_b,4,2
	.globl	_c                              ## @c
.zerofill __DATA,__common,_c,4,2
	.globl	_d                              ## @d
.zerofill __DATA,__common,_d,4,2
	.section	__DATA,__data
	.globl	_x                              ## @x
	.p2align	2
_x:
	.long	2                               ## 0x2

	.globl	_y                              ## @y
	.p2align	2
_y:
	.long	4                               ## 0x4

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

.subsections_via_symbols
