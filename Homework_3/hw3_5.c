#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

unsigned onesCount(uint64_t mask){
    int bit;
    int count=0;
    for(bit=63; bit>=0;bit--){
        printf("%u", !!(mask & (1<<bit)));
        if(mask & (1<<bit)) count++;
    }
    return count;
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
