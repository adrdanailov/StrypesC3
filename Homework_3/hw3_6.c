#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define CHECKBIT(mask,bit) !!(mask & (1ull << (bit)))
#define FORIBITS(start, stop) for(int i = (stop); i >= (start); i--)
#define PRINTBITS(a) FORIBITS(0, 63)printf("%d|", CHECKBIT((a), i))

int onesCount(uint64_t x)
{
    int count;
    for (count = 0; x; count++)
        x &= x - 1ull;
    return count;
}

int onesCount_build_in(uint64_t mask)
{
	return  __builtin_popcountll(mask);
}

bool contains(uint64_t mask, int el) {
    return mask & (1 << el);
}

void insert(uint64_t *mask, int el) {
    *mask |= (1ull << el);
}

void erase(uint64_t *mask, int el) {
    *mask &= ~(1ull << el);
}

void change(uint64_t *mask, int el) {
    *mask ^= (1ull << el);
}

int main(void)
{
    uint64_t attendance = 0;
    unsigned int i, option, student_num, students_sel = 0;
    while (1)
    {
        printf("\n");
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n: ");
        scanf("%d", &option);
        students_sel = 0;
        switch (option)
        {
            case 1:
                printf("Which student is present (0 - 64 || EOF):");
                while ((i = scanf(" %u", &student_num))!=EOF)
                {
                    scanf("%*[^\n]\n");
                    students_sel+=i;
                    insert(&attendance, student_num);
                    PRINTBITS(attendance);
                    printf("\n");
                }
                printf("\nNumber of set bits = %d", students_sel);
                students_sel=i=0;
            break;

            case 2:
            printf("Which student to mark absent (0 - 64 || EOF):");
            while (i = scanf(" %u", &student_num)!=EOF)
                {
                    scanf("%*[^\n]\n");
                    students_sel+=i;
                    erase(&attendance, student_num);
                    PRINTBITS(attendance);
                    printf("\n");

                    
                }
                printf("\nNumber of set bits = %d", students_sel);
                students_sel=i=0;
            break;

            case 3: //attendance info - count the 1s in the int (minimum weight)
                printf("\n The number of present students is %d\n", onesCount(attendance));
                break;

            case 4:
            printf("Which student to change (0 - 64 || EOF):");
            while (i = scanf(" %u", &student_num)!=EOF)
                {
                    scanf("%*[^\n]\n");
                    students_sel+=i;
                    change(&attendance, student_num);
                    for(int bit=63; bit;bit--)
                        printf("%d", !!(attendance & (1ull<<bit)));
                    printf("\n");

                    
                }
                printf("\nNumber of set bits = %d", students_sel);
                students_sel=i=0;
            break;

            case 5:
            return EXIT_SUCCESS;
            break;

            default:
            printf("\nInput 1 to 5 !\n");
        }

    }
    return EXIT_SUCCESS;
}

