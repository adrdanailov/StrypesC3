#include <stdio.h>
#include <math.h>

int quadEq(double a, double b, double c, double* x1, double *x2){
    double D = pow(b,2) - 4*a*c;
    //printf("\n%.2lf\n", D);
    if (D>0){
        //have 2 real roots
        *x1 = (-b+sqrt(pow(b,2)-4*a*c))/2*a;
        *x2 = (-b-sqrt(pow(b,2)-4*a*c))/2*a;
        return 0;
    }
    else if(D==0){
        //have 1 real root x1=x2
        *x1= -b/2*a;
        *x2= *x1;
        return 0;
    }
    else {
        printf("\nNo real roots!\n");
        return -1;
    }    
}


int main ( int argc, char **argv){
//vars
double a1, b1, c1, x1, x2;
double* ptrX1 = &x1;
double* ptrX2 = &x2;
if (argc != 4) {
    printf ("\nEnter 3 double numbers !\n");
    return -1;
}else {
    a1 = atof(argv[1]);
    b1 = atof(argv[2]);
    c1 = atof(argv[3]);
    //welcome screen
    printf("\n***\tQuadratic Equations Calculator v0.1\t***\n");
    printf("\n(%.2lf)x^2+(%.2lf)x+(%.2lf) = 0 ", a1, b1, c1);


    //printf("\n%.60lf\n%.60lf\n%.60lf\n%d\n", a1, b1, c1, sc);
    if(!quadEq(a1,b1,c1,ptrX1,ptrX2)){
        printf("\n\tX1 = %.2lf\n\tX2 = %.2lf \n", x1, x2);
        //printf("\n=>");
    }
}
printf("\n");  
return 0;
}
