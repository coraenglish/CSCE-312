	.file	"lab5_prob3_1.c"        # file name
	.section	.rodata
.LC0:
	.string	"Hello, world"        # initialize string to be used later in program
	.text
	.globl	main
	.type	main, @function
main:                           # entering main of program
.LFB0:
	.cfi_startproc
	pushq	%rbp                    # push frame pointer onto stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp              # copy contents of stack pointer to 
	.cfi_def_cfa_register 6          frame pointer to maintain original val
	subq	$16, %rsp               # increase stack pointer by 16 to increase space
	movl	%edi, -4(%rbp)          # store edi at 4 above start of stack
	movq	%rsi, -16(%rbp)         # store rsi at end of stack
	movl	$.LC0, %edi             # move string into edi register on stack
	call	puts 
	movl	$0, %eax                # store 0 in eax since func returns 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
