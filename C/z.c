#include<stdio.h>
int main(){
    for(int i=1;i<=9;i++){
        int j=1;
        for(j;j<=i;j++){

            if(j>i){
                break;
            }
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
}