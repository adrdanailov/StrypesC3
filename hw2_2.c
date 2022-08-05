#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES //use pi constant
#include <math.h>

int main (){
    //variables
    float R, H, L,volume, area = 0.00f;
    char ch, restart = ' ';
    //inputs
    do {
        printf("\n***\tWelcome to Cylinnder volume calculation\t\t***\n\n");
        printf("What kind of cylinder Vertical\\Horizontal (input V or H): ");
        //data validation
        while ( !((scanf("%c", &ch) == 1) && (ch == 'V' || ch =='H' || ch == 'v' || ch =='h')) ){
        printf("\r\tInput V or H: ");
        }

        if (ch=='h' || ch=='H'){
            printf("\n\t Horizontal positioned cylinder\n");
            printf("Please enter Lenght(L): ");
            scanf("%f", &L);
        }else printf("\n\t Vertical positioned cylinder\n");
        printf("Please enter Radius(R): ");
        scanf("%f", &R);
        printf("Please enter Water Level(H): ");
        scanf("%f", &H);
        //data validation

        //prints input
        printf("\nL:%.2f m\nR:%.2f m\nH:%.2f m", L, R, H);
        //calculations

        if (ch=='h' || ch=='H'){
            area = acos((R-H)/R) * pow(R,2) - (R-H)*sqrt(2*R*H-pow(H,2));
            volume = area * L;
        }else  volume = M_PI * pow(R,2) * H;

        //prints  results
        printf("\n\nVolume = %.2f m3\n\n", volume);

        printf("\nStart again? (input Y): ");
        //ch=' ';
        scanf("%s", &restart);  //if I use %c it skips the scanf ???????

    }
    while (restart == 'y' || restart == 'y');
    printf("\n");
    return 0;
}