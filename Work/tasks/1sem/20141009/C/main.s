	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Give me a value \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "Answer: %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$0, -4(%rbp)
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	print_bits
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	max_number_0
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "Bit introduction \0"
	.text
	.globl	print_bits
	.def	print_bits;	.scl	2;	.type	32;	.endef
	.seh_proc	print_bits
print_bits:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$32, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L7:
	movl	-8(%rbp), %eax
	subl	-4(%rbp), %eax
	subl	$1, %eax
	movl	16(%rbp), %edx
	movl	%eax, %ecx
	shrl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L11
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jb	.L7
	jmp	.L6
.L11:
	nop
.L6:
	leaq	.LC3(%rip), %rcx
	call	printf
	jmp	.L8
.L9:
	movl	-8(%rbp), %eax
	subl	-4(%rbp), %eax
	subl	$1, %eax
	movl	16(%rbp), %edx
	movl	%eax, %ecx
	shrl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	addl	$1, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jb	.L9
	movl	$10, %ecx
	call	putchar
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	max_number_0
	.def	max_number_0;	.scl	2;	.type	32;	.endef
	.seh_proc	max_number_0
max_number_0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$0, 16(%rbp)
	jne	.L13
	movl	$0, %eax
	jmp	.L14
.L13:
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$32, -20(%rbp)
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)
.L17:
	movl	-16(%rbp), %eax
	movl	16(%rbp), %edx
	movl	%eax, %ecx
	shrl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L25
	subl	$1, -16(%rbp)
	jmp	.L17
.L25:
	nop
	movl	$0, -12(%rbp)
	jmp	.L18
.L22:
	movl	16(%rbp), %eax
	andl	$1, %eax
	movl	%eax, -24(%rbp)
	cmpl	$0, -24(%rbp)
	jne	.L19
	addl	$1, -8(%rbp)
	jmp	.L20
.L19:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jbe	.L21
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
.L21:
	movl	$0, -8(%rbp)
.L20:
	shrl	16(%rbp)
	addl	$1, -12(%rbp)
.L18:
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jbe	.L22
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jbe	.L23
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
.L23:
	movl	-4(%rbp), %eax
.L14:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
