#include<stdio.h>
int main(){
    int a,i;
    scanf("%d",&a);

    for( i=1;i<=a;i++){
        
        for(int e=a;e>=i;e--){
            printf(" ");
        }
        
        for(int o=0;o<i;o++){
            printf("%d",i);
        }
        
        printf("  ");

        for(int o=0;o<i;o++){
            printf("%d",i);
        }

        printf("\n");


    }

}