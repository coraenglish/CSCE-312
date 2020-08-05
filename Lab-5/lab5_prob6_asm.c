 // File named “lab5_prob6.c”
#include <stdio.h>

int very_fast_function(int i) {
  __asm__(
	"movl	%edi, %eax\n\t"
	"sall	$6, %eax\n\t"
	"addl	$1, %eax\n\t"
	"cmpl	$1024, %eax\n\t"
	"jle	.L2\n\t"
	"movl	-4(%rbp), %eax\n\t"
	"leal	1(%rax), %edx\n\t"
	"movl	%edx, -4(%rbp)\n\t"
	"jmp	.L3\n\t"
".L2:\n\t"
	"movl	$0, %eax\n\t"
".L3:\n\t"
	"popq	%rbp\n\t"
	"ret"
 );
}

int main(int argc, char *argv[]) {
  int i;
  i=40;
  printf("The function value of i is %d\n", very_fast_function(i) );
  return 0;
}
