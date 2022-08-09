#include <stdio.h>
#include <math.h>
#include <float.h>


// adaptive epsilon
int doubleCompare3(double a, double b){
    return fabs(a - b) < DBL_EPSILON * fmax(fabs(a), fabs(b));
    
}


int main(void){
    double a = 100000000.0f * 0.1f;
    double b = 0.0f;
    double c = 0.0;
    for (int i = 0; i < 100000000; i++, b += 0.1f);
    for (int i = 0; i < 100000000; i++, c += 0.1);

    printf("\nEPS: %.52lf\n", DBL_EPSILON); //52 знака след запетаята е размера на този епсилон
    printf("\na: %.52lf\n", a);
    printf("\nb: %.52lf\n", b);
    printf("\nc: %.52lf\n", c);
    printf("\nb-c: %.52lf\n", b-c);
    printf("\na-b: %.52lf\n", fabs(a-b));
    printf("\na-c: %.52lf\n", fabs(a-c));

    printf("\n0.1f: %.52lf\n", 0.1f);
    printf("\n0.1: %.52lf\n", 0.1);
    
          if (doubleCompare3(a, b)){
        printf("\na == b\n");
    } else {
        printf("\na != b\n");
    }
      if (doubleCompare3(a, c)){
        printf("\na == c\n");
    } else {
        printf("\na != c\n");
    }

    a=0.0;
    b=0.0;
    c=0.0;  //понякога ми дава различни стойности на а,б,с без да сменям нищо !?
    return 0;
}

//когато се ползва f за инициализиране на променлива независимо че тя е double
//се parse-ва от float и това дава значително по-голяма грешка 