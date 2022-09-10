#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include "zad1_header.h"

int main (void)
{
    int n,m,k;
    char rnd_char[] = {'!', '?', '$', '@', '*', '%' , '-'};
    //n
    printf("\nEnter N:");
    scanf("%d", &n);
    char* ch = malloc(n*sizeof(char));
    if (NULL == ch)
    {
        fprintf(stderr, "Memory alocation failure!");
        return EXIT_FAILURE;
    }
    setRandom(ch, 0, n, 'a', 'z');
    printarr(ch, 0, n);
    //m
    printf("\nEnter M:");
    scanf("%d", &m);
    ch = realloc(ch, (n+m)*sizeof(char));
    if (NULL == ch)
    {
        fprintf(stderr, "Memory alocation failure!");
        return EXIT_FAILURE;
    }
    setRandom(ch, n, m, 'A', 'Z');
    printarr(ch, n, m);

    //k
    printf("\nEnter K:");
    scanf("%d", &k);
    ch = realloc(ch, (n+m+k)*sizeof(char));
    if (NULL == ch)
    {
        fprintf(stderr, "Memory alocation failure!");
        return EXIT_FAILURE;
    }
    setRandom_from_arr(ch, m+n, k, rnd_char); // rnd_char[6]
    printarr(ch, m+n, k);
    printf("\n*** FINAL RESULT ***\n");
    printarr(ch, 0, n+m+k);
    ch = realloc(ch, ((n+m+k) + 1)*sizeof(char));
    ch[(n+m+k) - 1] == '\0'; //терминиращ символ
    printf("\nNumber of lower cases letters = %d\n", get_lower_caps_count(ch));
    printf("\nThe most freq char is:%c\n\n", most_freq_char(ch, n+m+k+1));
    free(ch);
    return EXIT_SUCCESS;
}
