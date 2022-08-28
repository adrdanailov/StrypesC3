
#include <stdio.h>
#include <stdlib.h>

void printarr (double*, int,size_t);
int setRandom(double*, int, size_t, int);

int main (void){

    int n,m,p;
    //n
    printf("\nEnter N:");
    scanf("%d", &n);
    double* num = malloc(n*sizeof(double));
    if (NULL == num){
        return EXIT_FAILURE;
    }
    setRandom(num, 0, n, 0);
    printarr(num, 0, n);


    //m
    printf("\nEnter M:");
    scanf("%d", &m);
    num = realloc(num, (n+m)*sizeof(double));
   // printf("\n%d",n+m);
    if (NULL == num){
        return EXIT_FAILURE;
    }
   // printf("\n%lu", sizeof(num)/sizeof(num[0]));
    setRandom(num, n, m, 1);
    printarr(num, n, m);


    //p
    printf("\nEnter P:");
    scanf("%d", &p);
    num = realloc(num, (n+m+p)*sizeof(double));
    if (NULL == num){
        return EXIT_FAILURE;
    }
    setRandom(num, m+n, p, 2);
    printarr(num, m+n, p);

    printf("\n*** FINAL RESULT ***\n");
    printarr(num, 0, n+m+p);
    free(num);
    return EXIT_SUCCESS;

}


void printarr (double* num, int start, size_t size)
{
        printf("\n");
        for (int i = 0; i < size; ++i)
            printf("%d: %.5f\n", i+1, num[start+i]);
        printf("\n");
    }

int setRandom(double* num, int start, size_t size, int range)
{

   srand( (unsigned)time( NULL ) );
   for (int i = 0; i < size; ++i) {
      num[start+i] = rand() % 1000000;
      num[start+i] = (num[start+i] / 1000000) + range;
      //printf("%.5f\n", r[i]);
   }

   return EXIT_SUCCESS;
}

