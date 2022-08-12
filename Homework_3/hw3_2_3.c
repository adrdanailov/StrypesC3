#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* S, double *P){
    if (a+b>c && a+c>b && b+c>a){
        //valid triangle sides
        *S = 0.25 * sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
        *P = a + b + c;
        return 0;
    }
    else {
        fprintf(stderr, "(STDERR->) Error! Incorrect trianlge sides");
        return -1;
    }    

}

int rectangle(double w, double h, double* S, double *P){
    if (w && h){
        //valid rectangle sides no 0s
        *S = w * h;
        *P = 2*(w+h);
        return 0;
    }
    else {
        fprintf(stderr, "(STDERR->) Error! Incorrect rectangle sides");
        return -1;
    }    

}

int main (){
//vars
double a1,b1,c1,w1,h1,S,P;
double* ptrS = &S;
double* ptrP = &P;
int sc = 111;
int flag_tr = 0;

//welcome screen
printf("\n***\tTriangle\\Rectangle Calculator v0.1\t***\n");
printf("Triangle [0] or Rectangle [1] ? ");
scanf("%d", &flag_tr);
printf("\n=>");

if(flag_tr){
    while((sc=scanf(" %4lf %4lf %4lf", &a1, &b1, &c1))!=EOF){
        //printf("\n%.60lf\n%.60lf\n%.60lf\n%d\n", a1, b1, c1, sc);
        //data validation only int and flaot no 0 s!
        if(sc!=3 || !a1 || !b1 || !c1){
            printf("Enter only float numbers no 0 ! -> 1.12");
            printf("\n=>");
        }
        else if(!triangle(a1,b1,c1,ptrS,ptrP)){
            printf("\n\tS = %.2lf\n\tP = %.2lf", S, P);
            printf("\n=>");
        }
        scanf("%*[^\n]\n"); //prevents infinite loop coused by the buffering of \n charecter !
        
    }
}
else {
     while((sc=scanf(" %4lf %4lf", &w1, &h1))!=EOF){
        //printf("\n%.60lf\n%.60lf\n%.60lf\n%d\n", a1, b1, c1, sc);
        //data validation only int and flaot ! no 0
        if(sc!=2 || !w1 || !h1 ){
            printf("Enter only float numbers no 0 ! -> 1.12");
            printf("\n=>");
        }
        else if(!rectangle(w1,h1,ptrS,ptrP)){
            printf("\n\tS = %.2lf\n\tP = %.2lf", S, P);
            printf("\n=>");
        }
        scanf("%*[^\n]\n"); //prevents infinite loop coused by the buffering of \n charecter !
        
    }


}
return 0;
}





