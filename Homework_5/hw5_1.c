#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define MAX_INT_X32 2147483647

#define MAX(x, y, z) (x)>(y)?((x)>(z)?x:z):((y)>(z)?y:z)
#define MIN(x, y, z) (x)<(y)?((x)<(z)?x:z):((y)<(z)?y:z)

#define SETBIT(mask,bit) (mask |= (1ull << (bit)))
#define CLEARBIT(mask,bit) (mask &= ~(1ull << (bit)))
#define INVERSEBIT(mask,bit) (mask ^= (1ull << (bit)))
#define CHECKBIT(mask,bit) !!(mask & (1ull << (bit)))

#define INVERSEBIT_X32(mask,bit) (mask ^= (1 << (bit)))
#define CHECKBIT_X32(mask,bit) !!(mask & (1 << (bit)))

#define CHK_X64(a) ((a) > MAX_INT_X32 ? 1 : 0)

#define FORIBITS(start, stop) for(int i = (stop); i >= (start); i--)


#define SWAP_TOO_COMPLICATED(a,b) if(CHK_X64(a) | CHK_X64(b)) \
                        FORIBITS(0, 63) { ((CHECKBIT((a), i)) ^ (CHECKBIT((b), i))) ? \
                            (INVERSEBIT((a) ,i) && INVERSEBIT((b) ,i)) : 0 ; } \
                  else \
                        FORIBITS(0, 31) { ((CHECKBIT_X32((a), i)) ^ (CHECKBIT_X32((b), i))) ? \
                            (INVERSEBIT_X32((a) ,i) && INVERSEBIT_X32((b) ,i)) : 0 ; }

#define PRINTBITS(a) FORIBITS(0, (CHK_X64(a) ? 63 : 31))printf("%d", CHECKBIT(a, i));

#define SWAP(a,b) (a)^=(b);(b)^=(a);(a)^=(b);

int main(){

    uint64_t a, b, c;
    int ch,ii=10000001;
    uint64_t AA,BB;
    clock_t t;
    double time_taken;

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

                printf("\nA=%lu B=%lu\n", AA, BB);

                printf("\nORIGINAL[binary]: \n");
                    PRINTBITS(AA)
                    putchar('\n');
                    PRINTBITS(BB)
                    putchar('\n');
t = clock();AA*=1ull;
while(ii){
                SWAP(AA,BB)
                //SWAP_TOO_COMPLICATED(AA, BB);
ii--;
}
t = clock() - t;

                printf("\nSWAPED[binary]: \n");

time_taken = ((double)t)/CLOCKS_PER_SEC;
printf("SWAP(a, b) took %.7f seconds to execute \n", time_taken);
//printf("SWAP_TOO_COMPLICATED(a, b) took %.7f seconds to execute \n", time_taken);

                    PRINTBITS(AA)
                    putchar('\n');
                    PRINTBITS(BB)
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

    return 0;
}
