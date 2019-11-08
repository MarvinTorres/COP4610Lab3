#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
	long int amma = syscall(543);
	printf("System call sys_get_slob_amt_claimed returned %ld\n", amma);
	amma = syscall(544);
	printf("System call sys_get_slob_amt_free returned %ld\n", amma);
	return 0;
}
