#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    double s=1;
    double pi=0;
    double i=1.0;
    double n=1.0;
    while (fabs(i)>=1e-6){
        pi+=i;
        n=n+2;
        s=-s;
        i=s/n;
    }
    pi=4*pi;
    printf("pi: %.40f\n",pi);

    return 0;
    
}