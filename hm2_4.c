#include <stdio.h>

int main(){
    float buf = 0.0, num1 = 0.0, num2 = 0.0;

    while (scanf("%f%f%f", &buf, &num1, &num2) != EOF){

          printf("Output Three nums = %d\n", (!!buf)^(!!num1)^(!!num2));

    }

    return 0;
}