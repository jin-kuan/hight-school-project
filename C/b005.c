#include<stdio.h>
int main(){
    int a=0;
    int b=0;
    int c=0;

    printf("����");
    scanf("%d",&a);
    printf("��J���B");
    scanf("%d",&b);

    if(a<b){
        c=b-a;
        printf("��%d",c);

    }
    else{

        c=a-b;
        printf("�t%d",c);
    }
}