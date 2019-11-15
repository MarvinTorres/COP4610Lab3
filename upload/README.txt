1 - Recording of Results From Running Unmodified and Modified Kernel 
This section summarizes the results of running slobtracker with a kernel running an unmodified slob allocator that uses first-fit and one running a modified slob allocator that uses best-fit.

1.1 - Results of Running slobtracker.c With an Unmodified Slob Allocator

The output of running slobtracker is shown on Figure 1.1.1. One salient observation is the constant averages regardless of the number of blocks allocated. The number of bytes requested and the number of free bytes in the searched pages do not increase and decrease, respectively, when the number of blocks allocated increases by a factor of 2, 3, and 4, and so on. This was an observation that appeared multiple times during this lab's development.

------------------Allocating 3 x 1000000 x 0 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 1 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 2 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 3 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 4 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 5 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 6 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 7 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 8 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------
------------------Allocating 3 x 1000000 x 9 blocks------------------
Average number of bytes requested:                       309
Average number of free bytes in searched pages:       522534
-------------------------------------------------------------

Figure 1.1.1: Results of running slobtracker using slob.c (unmodified).

1.2 - Results of Running slobtracker.c With a Modified Slob Allocator

The output of running slobtracker is shown on Figure 1.2.1.


Figure 1.2.1: Results of running slobtracker using slob.c (modified).

2 - Comparison of Results
This section analyzes and explains the differences in measurements between kernels regarding memory management behavior.

The differences between the results lies with the first-fit and best-fit algorithms used by the unmodfiied and modified slob allocators, respectively. The one that stands out is that the average number of free bytes in the searched pages is lower in the modified allocator than in the unmodified allocator. This decrease stems from the higher rate of internal fragmentation that follows from using a first-fit approach. Namely, 
