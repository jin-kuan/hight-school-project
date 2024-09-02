#include<stdio.h>
int main(){
    int n=22 ,a=1;
    while(n!=1){
        if((n%2)==1){
        n=n*3+1;
        }

        else 
        {
            n=n/2;
        }

        a=a+1;

        printf("%d %d\n",n,a);
        
    
    }
}