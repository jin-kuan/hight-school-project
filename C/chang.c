#include <stdio.h>
int a,b,c;
int main(){
    printf("number1\n");
    scanf("%d", &a);
    printf("number2\n");
    scanf("%d", &b);
    c=b;
    b=a;
    a=c;
    printf("number1 %d.\n",a);
    printf("number2 %d.\n",b);


}