#include <stdio.h>

int main(){
    double max = 0.0, num = 0.0;
    int i = 0;
    while ((scanf("%lf", &num) != EOF) && i<3){ // i will limit the number of numbers to 3 but Ctrl+D is still needed to stop.
         if (max < num)
        {
            max = num;
        }
        i++;
    }
    printf("The largest num in: %.2lf\n", max);
    return 0;
}