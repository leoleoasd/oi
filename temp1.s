	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	__Z3asdv                ## -- Begin function _Z3asdv
	.p2align	4, 0x90
__Z3asdv:                               ## @_Z3asdv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, %rax
	movb	$0, -1(%rbp)
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	__ZN4testC1Ev
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	(%rax), %rdi
	movl	$1, (%rdi)
	movb	$1, -1(%rbp)
	testb	$1, -1(%rbp)
	jne	LBB0_2
## %bb.1:
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	callq	__ZN4testD1Ev
LBB0_2:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN4testC1Ev           ## -- Begin function _ZN4testC1Ev
	.weak_def_can_be_hidden	__ZN4testC1Ev
	.p2align	4, 0x90
__ZN4testC1Ev:                          ## @_ZN4testC1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN4testC2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN4testD1Ev           ## -- Begin function _ZN4testD1Ev
	.weak_def_can_be_hidden	__ZN4testD1Ev
	.p2align	4, 0x90
__ZN4testD1Ev:                          ## @_ZN4testD1Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	__ZN4testD2Ev
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	$0, -4(%rbp)
	leaq	-16(%rbp), %rdi
	callq	__Z3asdv
	movq	-16(%rbp), %rsi
Ltmp0:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	callq	_printf
Ltmp1:
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	jmp	LBB3_1
LBB3_1:
	movq	-16(%rbp), %rax
	movl	(%rax), %esi
Ltmp2:
	leaq	L_.str.1(%rip), %rdi
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movb	%dl, %al
	callq	_printf
Ltmp3:
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jmp	LBB3_2
LBB3_2:
Ltmp4:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	leaq	-32(%rbp), %rsi
	movb	%cl, %al
	callq	_printf
Ltmp5:
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	jmp	LBB3_3
LBB3_3:
Ltmp6:
	movl	$4, %edi
	callq	__Znwm
Ltmp7:
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	jmp	LBB3_4
LBB3_4:
Ltmp8:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movq	-56(%rbp), %rsi         ## 8-byte Reload
	movb	%cl, %al
	callq	_printf
Ltmp9:
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	jmp	LBB3_5
LBB3_5:
	movl	$0, -4(%rbp)
	leaq	-16(%rbp), %rdi
	callq	__ZN4testD1Ev
	movl	-4(%rbp), %eax
	addq	$80, %rsp
	popq	%rbp
	retq
LBB3_6:
Ltmp10:
	movl	%edx, %ecx
	movq	%rax, -24(%rbp)
	movl	%ecx, -28(%rbp)
Ltmp11:
	leaq	-16(%rbp), %rdi
	callq	__ZN4testD1Ev
Ltmp12:
	jmp	LBB3_7
LBB3_7:
	jmp	LBB3_8
LBB3_8:
	movq	-24(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
LBB3_9:
Ltmp13:
	movq	%rax, %rdi
	movq	%rdx, -72(%rbp)         ## 8-byte Spill
	callq	___clang_call_terminate
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table3:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.uleb128 Lttbase0-Lttbaseref0
Lttbaseref0:
	.byte	1                       ## Call site Encoding = uleb128
	.uleb128 Lcst_end0-Lcst_begin0
Lcst_begin0:
	.uleb128 Lfunc_begin0-Lfunc_begin0 ## >> Call Site 1 <<
	.uleb128 Ltmp0-Lfunc_begin0     ##   Call between Lfunc_begin0 and Ltmp0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp0-Lfunc_begin0     ## >> Call Site 2 <<
	.uleb128 Ltmp9-Ltmp0            ##   Call between Ltmp0 and Ltmp9
	.uleb128 Ltmp10-Lfunc_begin0    ##     jumps to Ltmp10
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp9-Lfunc_begin0     ## >> Call Site 3 <<
	.uleb128 Ltmp11-Ltmp9           ##   Call between Ltmp9 and Ltmp11
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.uleb128 Ltmp11-Lfunc_begin0    ## >> Call Site 4 <<
	.uleb128 Ltmp12-Ltmp11          ##   Call between Ltmp11 and Ltmp12
	.uleb128 Ltmp13-Lfunc_begin0    ##     jumps to Ltmp13
	.byte	1                       ##   On action: 1
	.uleb128 Ltmp12-Lfunc_begin0    ## >> Call Site 5 <<
	.uleb128 Lfunc_end0-Ltmp12      ##   Call between Ltmp12 and Lfunc_end0
	.byte	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lcst_end0:
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
	.p2align	2
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
Lttbase0:
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	___clang_call_terminate ## -- Begin function __clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## %bb.0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev
                                        ## -- End function
	.globl	__ZN4testC2Ev           ## -- Begin function _ZN4testC2Ev
	.weak_def_can_be_hidden	__ZN4testC2Ev
	.p2align	4, 0x90
__ZN4testC2Ev:                          ## @_ZN4testC2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movl	$4, %eax
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	callq	__Znwm
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	movq	%rax, (%rdi)
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	movq	(%rdi), %rsi
	leaq	L_.str(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN4testD2Ev           ## -- Begin function _ZN4testD2Ev
	.weak_def_can_be_hidden	__ZN4testD2Ev
	.p2align	4, 0x90
__ZN4testD2Ev:                          ## @_ZN4testD2Ev
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	(%rdi), %rdi
	cmpq	$0, %rdi
	movq	%rdi, -16(%rbp)         ## 8-byte Spill
	je	LBB6_2
## %bb.1:
	movq	-16(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZdlPv
LBB6_2:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%p\n"

L_.str.1:                               ## @.str.1
	.asciz	"%lld\n"

L_.str.2:                               ## @.str.2
	.asciz	"\346\236\204\351\200\240\n"

L_.str.3:                               ## @.str.3
	.asciz	"\346\236\220\346\236\204\n"


.subsections_via_symbols
