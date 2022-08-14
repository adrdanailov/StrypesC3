#include <stdio.h>
#include <stdint.h>

int onesCount(uint64_t x)
{
    int count;
    for (count=0; x; count++)
        x &= x - 1;
    return count;
}

int onesCount_build_in(uint64_t mask)
{
	return  __builtin_popcountll(mask);
}


int main (){

uint64_t mask;

printf("\nEnter a INT number: ");
scanf("%lu", &mask);
printf("\n%lu\n", mask);
printf("\nNumber of 1s is: %u", onesCount(mask));

putchar('\n');

return 0;

}
