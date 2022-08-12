#include <stdio.h>

int main (){
//vars
double num1,num2;
char operator;
//welcome screen
printf("\n***\tCalculator v0.1\t***\n");
printf("\n=>");
while(scanf(" %4lf %c %4lf", &num1, &operator, &num2)!=EOF){
    
    //scanf("%*[^\n]\n");
    switch (operator){
        case '+':
            //printf(" %.2lf %c %.2lf = \n", num1,operator,num2);
            printf("\t = %.2lf", num1+num2);
            break;

        case '-':
            //printf(" %.2lf %c %.2lf = \n", num1,operator,num2);
            printf("\t = %.2lf", num1-num2);
            break;

        case 'x':
            //printf(" %.2lf %c %.2lf = \n", num1,operator,num2);
            printf("\t = %.2lf", num1*num2);
            break;

        case '/':
            //printf(" %.2lf %c %.2lf = \n", num1,operator,num2);
            printf("\t = %.2lf", num1/num2);
            break;

        default:
            fprintf(stderr, "(STDERR->) Error! operator is not correct");
            break;
    }
    printf("\n=>");
}

return 0;
}
