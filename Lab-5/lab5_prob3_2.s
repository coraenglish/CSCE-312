	.file	"lab5_prob3_2.c"            # file name
	.section	.rodata
.LC0:
	.string	"The value of i is %d\n"  # initialize string for later use
	.text
	.globl	main
	.type	main, @function
main:                               # entering main of program
.LFB0:
	.cfi_startproc
	pushq	%rbp                        # push frame pointer onto stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp                  # copy contents of stack pointer to
	.cfi_def_cfa_register 6              frame pointer to maintain original val
	subq	$32, %rsp                   # increase stack pointer by 32 to increase space
	movl	%edi, -20(%rbp)             # store edi at 20 above start of stack
	movq	%rsi, -32(%rbp)             # store rsi at end of stack
	movl	$1, -4(%rbp)                # store 1 at 4 above start of stack
	addl	$1, -4(%rbp)                # increment previous location by 1
	movl	-4(%rbp), %eax              # move previous value to eax
	movl	%eax, %esi                  # move value from eax to esi
	movl	$.LC0, %edi                 # move string into edi
	movl	$0, %eax                    # move 0 into eax since function returns 0
	call	printf                      # call printf to print blurb and i
	movl	$0, %eax                    # repeat the same action ?
	leave
	.cfi_def_cfa 7, 8
	ret 
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits
