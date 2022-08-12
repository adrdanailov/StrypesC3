#include <stdio.h>
#include <math.h>

int quadEq(double a, double b, double c, double* x1, double *x2){
    double D = pow(b,2) - 4*a*c;
    if (D>0){
        //have 2 real roots
        *x1 = (-b+sqrt(pow(b,2)-4*a*c))/2*a;
        *x2 = (-b-sqrt(pow(b,2)-4*a*c))/2*a;
        return 0;
    }
    else if(D=0){
        //have 1 real root
        *x1= -b/2*a;
        *x2='\0';
    }
    else {
        fprintf(stderr, "(STDERR->) No real roots!");
        return -1;
    }    
}


int main (){
//vars
double a1,b1,c1,x1,x2;
double* ptrX1 = &x1;
double* ptrX2 = &x2;
int sc = 111;

//welcome screen
printf("\n***\tQuadratic Equations Calculator v0.1\t***\n");
printf("\n=>");

while((sc=scanf(" %4lf %4lf %4lf", &a1, &b1, &c1))!=EOF){
        //printf("\n%.60lf\n%.60lf\n%.60lf\n%d\n", a1, b1, c1, sc);
        //data validation only int and flaot no 0 s!
        if(sc!=3 || !a1 || !b1 || !c1){
            printf("Enter only float numbers no 0 ! -> 1.12");
            printf("\n=>");
        }
        else if(!quadEq(a1,b1,c1,ptrX1,ptrX2)){
            printf("\n\tX1 = %.2lf\n\tX2 = %.2lf", x1, x1);
            printf("\n=>");
        }
        scanf("%*[^\n]\n"); //prevents infinite loop coused by the buffering of \n charecter !
        
}

return 0;
}





