#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define __BMI_COEF__ 1.3

int main (){
    //variables
    float mass, height = 0.00f;
    float BMI, new_BMI = 0.00f;
    //inputs
    printf("Please enter your mass (in KG -> min 1.00 | max 200.00): ");
    scanf("%f", &mass);
    printf("Please enter your height (in meters -> min 0.30 | max 230.00): ");
    scanf("%f", &height);
    /*data validation

    */
    //prints input
    printf("Mass:%.2f\nHeight:%.2f\n",mass, height);
    //calculations
    BMI = mass/pow(height,2);
    new_BMI = __BMI_COEF__*(mass/pow(height,2.5));

    //optional prints underweight, normalweight, overweight * calculated by new_BMI
   char* cur_index;

    if (new_BMI < 18.5){
        cur_index =  "UNDERWEIGHT";
    }else if (new_BMI > 35){
        cur_index = "OVERWEIGHT";
    }else
        cur_index = "NORMALWEIGHT";

    //prints  results
    printf("\tBMI = %.2f\t%s\n", BMI, cur_index);
    printf("\tNew BMI = %.2f\t%s\n", new_BMI, cur_index);

    //BONUS LEVEL if new_BMI above 40 get COWSAY command to say You COW ? :)
    if (new_BMI > 40)
              system(" if [ $( whereis cowsay | grep  '/cowsay' | awk  '{print $2}' ) != NULL ]; then eval \
                     \"$( whereis cowsay | grep  '/cowsay' | awk  '{print $2}' ) 'YOU COW?'\" ; else echo 'No Cowsay installed !' ; fi ");

    return 0;
}
