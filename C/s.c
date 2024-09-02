#include<stdio.h>
int main(){
    int g;
    int n;
    
    
    scanf("%d",&g);


    for(int i=0;;i++){


    if(n>100||n<0){
        printf("重新輸入\n");
        scanf("%d",&g);
        break;
    }
   

    else{
    n=g/10;
    printf("%d",n);
    switch(n){
        case 10:
        printf("你超棒\n");
        break;

        case 9:
        printf("你很棒\n");
        break;

        case 8:
        printf("棒\n");
        break;

        case 7:
        printf("還ok");
        break;

        case 6:
        printf("及格了\n");
        break;

        case 5:
        printf("你被當了\n");
        break;

        case 4:
        printf("很跨張\n");
        break;

        case 3:
        printf("很跨張\n");
        break;

        case 2:
        printf("很跨張\n");
        break;

        case 1:
        printf("你完了\n");
        break;

        case 0:
        printf("你死定了\n");
        break;
    }
    }
    }
}