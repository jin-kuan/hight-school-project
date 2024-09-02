#include<stdio.h>
int main(){
    for(int i=1;i<=9;i++){
        for(int p=1;p<=9;p++){
            printf("%d*%d=%d\n",i,p,i*p);
        }
    }
}