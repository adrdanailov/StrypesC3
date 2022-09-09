#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_INT_X32 2147483647

#define MAX(x, y, z) (x)>(y)?((x)>(z)?x:z):((y)>(z)?y:z)
#define MIN(x, y, z) (x)<(y)?((x)<(z)?x:z):((y)<(z)?y:z)

#define SETBIT(mask,bit) (mask |= (1ull << (bit)))
#define CLEARBIT(mask,bit) (mask &= ~(1ull << (bit)))
#define INVERSEBIT(mask,bit) (mask ^= (1ull << (bit)))
#define CHECKBIT(mask,bit) !!(mask & (1ull << (bit)))

#define INVERSEBIT_X32(mask,bit) (mask ^= (1 << (bit)))
#define CHECKBIT_X32(mask,bit) !!(mask & (1 << (bit)))

#define CHK_X64(a) ((a) > MAX_INT_X32 ? 1 : 0) //checks if there is a need to go past 32-nd bit

#define FORIBITS(start, stop) for(int i = (stop); i >= (start); i--)

#define SWAP_TOO_COMPLICATED(a,b) if(CHK_X64(a) | CHK_X64(b)) \
                        FORIBITS(0, 63) { ((CHECKBIT((a), i)) ^ (CHECKBIT((b), i))) ? \
                            (INVERSEBIT((a) ,i) && INVERSEBIT((b) ,i)) : 0 ; } \
                  else \
                        FORIBITS(0, 31) { ((CHECKBIT_X32((a), i)) ^ (CHECKBIT_X32((b), i))) ? \
                            (INVERSEBIT_X32((a) ,i) && INVERSEBIT_X32((b) ,i)) : 0 ; }

#define PRINTBITS(a) FORIBITS(0, (CHK_X64(a) ? 63 : 31))printf("%d", CHECKBIT(a, i))

#define SWAP(a,b) (a)^=(b);(b)^=(a);(a)^=(b)

int main(){

    uint64_t a, b, c;
    int ch;
    uint64_t AA,BB;

    do {
        printf("\n***Choose option***");
        printf("\n1: MIN/MAX");
        printf("\n2: SWAP");
        printf("\n3: EXIT\n\noption:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter three numbers: \na: ");
                scanf("%ld", &a);
                printf("b: ");
                scanf("%ld", &b);
                printf("c: ");
                scanf("%ld", &c);
                printf("Largest of three numbers is %ld\n", MAX(a, b, c));
                printf("Smallest of three numbers is %ld\n", MIN(a, b, c));
            break;

            case 2:
                printf("\nEnter A: ");
                scanf("%lu", &AA);

                printf("\nEnter B: ");
                scanf("%lu", &BB);
                printf("\nORIGINAL\n[decimal]: ");
                printf(" A=%lu B=%lu\n", AA, BB);
                printf("\n[binary]: \n");
                PRINTBITS(AA);
                putchar('\n');
                PRINTBITS(BB);
                putchar('\n');
                //swap unswap swap
                SWAP(AA,BB);
                SWAP_TOO_COMPLICATED(AA, BB);
                SWAP(AA,BB);
                //both work
                printf("\nSWAPPED\n[decimal]: ");
                printf(" A=%lu B=%lu\n", AA, BB);
                printf("\n[binary]: \n");
                PRINTBITS(AA);
                putchar('\n');
                PRINTBITS(BB);
                putchar('\n');
                break;

            case 3:
                return 0;
                break;

            default:
                printf("\n\tNo valid entry! \n");
                break;
        }
    }while(1);
    return EXIT_SUCCESS;
}
