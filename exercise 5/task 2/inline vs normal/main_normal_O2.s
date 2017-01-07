	.file	"main_normal.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	movl	$5, %edx
	movl	$15, %eax
.L5:
	subl	%edx, %eax
	cmpl	%edx, %eax
	movl	%eax, %ecx
	jl	.L2
	subl	%edx, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	cmpl	%edx, %eax
	movl	%eax, %ecx
	jl	.L2
	subl	%edx, %eax
	testl	%edx, %edx
	jne	.L4
.L10:
	movl	$5, %edx
	movl	$27, %eax
.L9:
	subl	%edx, %eax
	cmpl	%edx, %eax
	movl	%eax, %ecx
	jl	.L6
	subl	%edx, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	cmpl	%edx, %eax
	movl	%eax, %ecx
	jl	.L6
	subl	%edx, %eax
	testl	%edx, %edx
	jne	.L8
.L7:
	xorl	%eax, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	testl	%ecx, %ecx
	movl	%edx, %eax
	movl	%ecx, %edx
	jne	.L9
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L2:
	testl	%ecx, %ecx
	movl	%edx, %eax
	movl	%ecx, %edx
	jne	.L5
	jmp	.L10
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits
