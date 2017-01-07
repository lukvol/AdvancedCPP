	.file	"main_normal.cpp"
	.section	.text._Z3lcmIiET_S0_S0_,"axG",@progbits,_Z3lcmIiET_S0_S0_,comdat
	.weak	_Z3lcmIiET_S0_S0_
	.type	_Z3lcmIiET_S0_S0_, @function
_Z3lcmIiET_S0_S0_:
.LFB4:
	.cfi_startproc
	movl	%edi, %eax
	movl	%esi, %r8d
	movl	%edi, %r9d
	cmpl	%esi, %edi
	jge	.L6
	movl	%edi, %r8d
	movl	%esi, %r9d
	jmp	.L6
.L4:
	movl	%r8d, %r9d
	movl	%ecx, %r8d
.L6:
	testl	%r8d, %r8d
	je	.L3
	movl	%r9d, %ecx
	subl	%r8d, %ecx
	cmpl	%r8d, %ecx
	jl	.L4
.L8:
	subl	%r8d, %ecx
	cmpl	%r8d, %ecx
	jge	.L8
	jmp	.L4
.L3:
	cltd
	idivl	%r9d
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE4:
	.size	_Z3lcmIiET_S0_S0_, .-_Z3lcmIiET_S0_S0_
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$15, %esi
	movl	$5, %edi
	call	_Z3lcmIiET_S0_S0_
	movl	$27, %esi
	movl	$5, %edi
	call	_Z3lcmIiET_S0_S0_
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits