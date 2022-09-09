#include<stdio.h>

void main(void)
{
    double number;
    double temp, sqrt;
    printf("Provide the number: ");
    scanf("%lf", &number);
    sqrt = number / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = (temp + number/temp ) / 2;
    }
    printf("\nThe square root of %0.4lf is %0.4lf", number, sqrt);
}
