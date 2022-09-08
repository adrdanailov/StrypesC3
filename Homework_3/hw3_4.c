#include <stdio.h>
#include <math.h>

#define _TWO_REAL_ROOTS 0
#define _ONE_REAL_ROOT 0
#define _NO_REAL_ROOTS -1

int quadEq(double a, double b, double c, double* x1, double *x2);

int main ( int argc, char **argv){
    double a1, b1, c1, x1, x2;
    double* ptrX1 = &x1;
    double* ptrX2 = &x2;
    
    if (argc != 4) 
    {
        printf ("\nEnter 3 double numbers !\n");
        return -1;
    }else 
    {
        a1 = atof(argv[1]);
        b1 = atof(argv[2]);
        c1 = atof(argv[3]);
    
        //welcome screen
        printf("\n***\tQuadratic Equations Calculator v0.1\t***\n");
        printf("\n(%.2lf)x^2+(%.2lf)x+(%.2lf) = 0 ", a1, b1, c1);
        
        if(!quadEq(a1,b1,c1,ptrX1,ptrX2)){
            printf("\n\tX1 = %.2lf\n\tX2 = %.2lf \n", x1, x2);
        }
    }
    printf("\n");  
    return 0;
}

int quadEq(double a, double b, double c, double* x1, double *x2)
{
    double D = pow(b,2) - 4*a*c;
    if (D>0){
        *x1 = (-b+sqrt(pow(b,2)-4*a*c))/2*a;
        *x2 = (-b-sqrt(pow(b,2)-4*a*c))/2*a;
        return _TWO_REAL_ROOTS;
    }
    else if(D==0){
        *x1= -b/2*a;
        *x2= *x1;
        return _ONE_REAL_ROOT;
    }
    else {
        printf("\nNo real roots!\n");
        return _NO_REAL_ROOTS;
    }    
}
