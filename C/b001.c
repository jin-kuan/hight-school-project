#include<stdio.h>
int main(){
    for(int a=1; a<=100; a++){
        if(a%2==0){
            continue;
        }

        printf("%d ",a);
}