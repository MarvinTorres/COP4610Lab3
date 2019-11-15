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

	char avg_bytes_requested_txt[100] = "Average number of bytes requested:";
	char avg_free_in_pages_txt[100] = "Average number of free bytes in searched pages:";
	char line[100] = "-------------------------------------------------------------";
	/*
	 * Allocate bytes to starve memory.
	 */
	a = (int*)malloc(NUM_BYTES);
	b = (int*)malloc(NUM_BYTES);
	c = (int*)malloc(NUM_BYTES);
	
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
	printf("%s\n", line);
	long int avg_bytes_requested = syscall(543) + 100;
	printf("%-50s%10ld\n", avg_bytes_requested_txt, avg_bytes_requested);
	long int avg_free_in_pages = syscall(544) + 100;
	printf("%-50s%10ld\n", avg_free_in_pages_txt, avg_free_in_pages);
	printf("%s\n", line);
	
	/*
	 * Free up allocated space.
	 */ 
	free(a);
	free(b);
	free(c);
	
	return 0;
}
