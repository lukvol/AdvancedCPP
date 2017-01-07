	.file	"main_inline.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	movl	$5, %edx
	movl	$15, %eax
.L5:
	subl	%edx, %eax
	movl	%eax, %ecx
	cmpl	%edx, %eax
	jl	.L2
	subl	%edx, %eax
.L4:
	movl	%eax, %ecx
	cmpl	%edx, %eax
	jl	.L2
	subl	%edx, %eax
	testl	%edx, %edx
	jne	.L4
	movl	$5, %edx
	movl	$27, %eax
.L9:
	subl	%edx, %eax
	movl	%eax, %ecx
	cmpl	%edx, %eax
	jl	.L6
	subl	%edx, %eax
.L8:
	movl	%eax, %ecx
	cmpl	%edx, %eax
	jl	.L6
	subl	%edx, %eax
	testl	%edx, %edx
	jne	.L8
.L7:
	movl	$0, %eax
	ret
.L2:
	movl	%edx, %eax
	movl	%ecx, %edx
	testl	%ecx, %ecx
	jne	.L5
	movl	$5, %edx
	movl	$27, %eax
	jmp	.L9
.L6:
	movl	%edx, %eax
	movl	%ecx, %edx
	testl	%ecx, %ecx
	jne	.L9
	jmp	.L7
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits