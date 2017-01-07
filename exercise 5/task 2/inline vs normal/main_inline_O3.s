	.file	"main_inline.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	movl	$5, %edx
	movl	$15, %ecx
.L2:
	movl	%ecx, %eax
	subl	%edx, %eax
	cmpl	%edx, %eax
	jl	.L3
	testl	%edx, %edx
	je	.L4
	.p2align 4,,10
	.p2align 3
.L5:
	subl	%edx, %eax
	cmpl	%edx, %eax
	jge	.L5
.L3:
	testl	%eax, %eax
	je	.L14
.L6:
	movl	%edx, %ecx
	movl	%eax, %edx
	jmp	.L2
.L4:
	testl	%eax, %eax
	js	.L6
.L14:
	movl	$5, %edx
	movl	$27, %ecx
.L7:
	movl	%ecx, %eax
	subl	%edx, %eax
	cmpl	%edx, %eax
	jl	.L9
	testl	%edx, %edx
	je	.L10
	.p2align 4,,10
	.p2align 3
.L11:
	subl	%edx, %eax
	cmpl	%edx, %eax
	jge	.L11
.L9:
	testl	%eax, %eax
	je	.L13
.L12:
	movl	%edx, %ecx
	movl	%eax, %edx
	jmp	.L7
.L10:
	testl	%eax, %eax
	js	.L12
.L13:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits
