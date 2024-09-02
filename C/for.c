#include <stdio.h>

int main(){
    int sum,i,a;

    scanf("%d",&a);

    for (i=1,sum=0;i<=a; i++){

        sum=sum+i;
       
        printf("%d+\n",i);
    }
   printf("=%d",sum);
}
