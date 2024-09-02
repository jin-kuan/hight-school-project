#include<stdio.h>
int main(){
   double b[3]={0,1,0};
   for(int i=0;i<499;i++){
    b[0]=b[0]*0+b[1]*1+b[2]*0;
    b[1]=b[0]*1/6+b[1]*0.5+b[2]*1/3;
    b[2]=b[0]*0+b[1]*1/3+b[2]*1/3;
   }
   printf("%f\n",b[0]);
   printf("%f\n",b[1]);
   printf("%f\n",b[2]);
}

