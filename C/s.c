#include<stdio.h>
int main(){
    int g;
    int n;
    
    
    scanf("%d",&g);


    for(int i=0;;i++){


    if(n>100||n<0){
        printf("���s��J\n");
        scanf("%d",&g);
        break;
    }
   

    else{
    n=g/10;
    printf("%d",n);
    switch(n){
        case 10:
        printf("�A�W��\n");
        break;

        case 9:
        printf("�A�ܴ�\n");
        break;

        case 8:
        printf("��\n");
        break;

        case 7:
        printf("��ok");
        break;

        case 6:
        printf("�ή�F\n");
        break;

        case 5:
        printf("�A�Q��F\n");
        break;

        case 4:
        printf("�ܸ�i\n");
        break;

        case 3:
        printf("�ܸ�i\n");
        break;

        case 2:
        printf("�ܸ�i\n");
        break;

        case 1:
        printf("�A���F\n");
        break;

        case 0:
        printf("�A���w�F\n");
        break;
    }
    }
    }
}