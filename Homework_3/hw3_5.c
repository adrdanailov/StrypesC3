#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CHECKBIT(mask,bit) !!(mask & (1ull << (bit)))

int onesCount(uint64_t);
int onesCount_built_in(uint64_t);
int onesCount_check_bit(uint64_t);


int main (void)
{
	uint64_t mask;

	printf("\nEnter a INT number: ");
	scanf("%lu", &mask);
	printf("\n%lu\n", mask);
	printf("\nNumber of 1s is: %d - %d - %d (control value)", onesCount(mask), onesCount_check_bit(mask), onesCount_built_in(mask));

	putchar('\n');

	return EXIT_SUCCESS;
}

int onesCount(uint64_t x)
{
    int count;
    for (count = 0; x; count++)
        x &= x - 1ull;
    return count;
}

int onesCount_check_bit(uint64_t x)
{
    int count = 0;
    for (int i = 0; i<64; i++)
        if (CHECKBIT(x , count))
            count++;
    return count;
}

int onesCount_built_in(uint64_t mask)
{
	return  __builtin_popcountll(mask);
}
