#include<stdio.h>
int main(){
    int a=0;
    int b=0;
    int c=0;

    printf("價格");
    scanf("%d",&a);
    printf("輸入金額");
    scanf("%d",&b);

    if(a<b){
        c=b-a;
        printf("找%d",c);

    }
    else{

        c=a-b;
        printf("差%d",c);
    }
}