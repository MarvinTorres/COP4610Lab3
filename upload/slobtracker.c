#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

#define NUM_BYTES 10000000000

int main()
{
	/*
	 * Initialize variables.
	 */
	int i;
	int* a;
	int* b;
	int* c;
	/*
	 * Allocate bytes to starve memory.
	 */
	a = (int*)malloc(NUM_BYTES);
	b = (int*)malloc(NUM_BYTES);
	c = (int*)malloc(NUM_BYTES);
	
        /*
	 * Print out average of bytes requested over a 100 instance period
	 * Also print out average of free bytes in each searched page
	 *
	 * This will show the number of free bytes that could not be allocated
	 * due to external and internal fragmentation.
	 *
	 * Internal fragmentation - Free blocks can't be allocated because they are allocated to another process
	 *                          that does not need them.
	 * External fragmentation - Free blocks can't be allocated because they are not contiguously laid out
	 *                          in memory.
	 */
	long int amma = syscall(543);
	printf("System call sys_get_slob_amt_claimed returned %ld\n", amma);
	amma = syscall(544);
	printf("System call sys_get_slob_amt_free returned %ld\n", amma);
	
	/*
	 * Free up allocated space.
	 */ 
	free(a);
	free(b);
	free(c);
	
	return 0;
}
