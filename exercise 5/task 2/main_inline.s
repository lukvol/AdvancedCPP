	.file	"main_inline.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$15, %esi
	movl	$5, %edi
	call	_Z3lcmIiET_S0_S0_
	movl	$27, %esi
	movl	$5, %edi
	call	_Z3lcmIiET_S0_S0_
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.text._Z3lcmIiET_S0_S0_,"axG",@progbits,_Z3lcmIiET_S0_S0_,comdat
	.weak	_Z3lcmIiET_S0_S0_
	.type	_Z3lcmIiET_S0_S0_, @function
_Z3lcmIiET_S0_S0_:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_Z3gcfIiET_S0_S0_
	movl	%eax, %ecx
	movl	-4(%rbp), %eax
	cltd
	idivl	%ecx
	imull	-8(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z3lcmIiET_S0_S0_, .-_Z3lcmIiET_S0_S0_
	.section	.text._Z3gcfIiET_S0_S0_,"axG",@progbits,_Z3gcfIiET_S0_S0_,comdat
	.weak	_Z3gcfIiET_S0_S0_
	.type	_Z3gcfIiET_S0_S0_, @function
_Z3gcfIiET_S0_S0_:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L6
	leaq	-8(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z4swapIiEvRT_S1_
.L6:
	movl	-8(%rbp), %eax
	testl	%eax, %eax
	je	.L7
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L6
	leaq	-8(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z4swapIiEvRT_S1_
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_Z3gcfIiET_S0_S0_, .-_Z3gcfIiET_S0_S0_
	.section	.text._Z4swapIiEvRT_S1_,"axG",@progbits,_Z4swapIiEvRT_S1_,comdat
	.weak	_Z4swapIiEvRT_S1_
	.type	_Z4swapIiEvRT_S1_, @function
_Z4swapIiEvRT_S1_:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_Z4swapIiEvRT_S1_, .-_Z4swapIiEvRT_S1_
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits
