#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

#define NUM_BLOCKS 1000000

int main()
{
	/*
	 * Initialize variables.
	 */
	int i;
	int* a;
	int* b;
	int* c;

	char avg_bytes_requested_txt[100] = "Average number of bytes requested:";
	char avg_free_in_pages_txt[100] = "Average number of free bytes in searched pages:";
	char line_short[100] = "------------------";
	char line[100] = "-------------------------------------------------------------";
	
        /*
	 * Print out average number of bytes requested over a 100 request span
	 * Also print out average number of free bytes in each searched page over a 100 request span
	 *
	 * This will show the number of free bytes that could not be allocated
	 * due to external and internal fragmentation.
	 *
	 * Internal fragmentation - Free blocks can't be allocated because they are allocated to another process
	 *                          that does not need them.
	 * External fragmentation - Free blocks can't be allocated because they are not contiguously laid out
	 *                          in memory.
	 */
	
	for (i = 0; i <= 10; i++) {
		/*
		 * Allocate blocks to starve memory. Number of bytes allocated will be increased by 2x, 3x, 4x,
		 * etc. every loop iteration.
		 */
		a = (int*)malloc(NUM_BLOCKS * i);
		b = (int*)malloc(NUM_BLOCKS * i);
		c = (int*)malloc(NUM_BLOCKS * i);
		printf("%sAllocating 3 x %d x %d blocks%s\n", line_short, NUM_BLOCKS, i, line_short);
		long int avg_bytes_requested = syscall(543) + 100;
		printf("%-50s%10ld\n", avg_bytes_requested_txt, avg_bytes_requested);
		long int avg_free_in_pages = syscall(544) + 100;
		printf("%-50s%10ld\n", avg_free_in_pages_txt, avg_free_in_pages);
		printf("%s\n", line);
	}
	
	/*
	 * Free up allocated space.
	 */ 
	free(a);
	free(b);
	free(c);
	
	return 0;
}
