#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

#define NUM_BYTES 10000000000

int main()
{
   int i;
   int* a;
   int* b;
   int* c;
   for (i = 0; i < 10000; i++) {
	a = (int*)malloc(255);
	b = (int*)malloc(0);
	c = (int*)malloc(0);
	long int amma = syscall(543);
	printf("System call sys_get_slob_amt_claimed returned %ld\n", amma);
	amma = syscall(544);
	printf("System call sys_get_slob_amt_free returned %ld\n", amma);
   }
	free(a);
	free(b);
	free(c);
	return 0;
}
