#include<stdio.h>
int main(){
    int i=2;
    while (i<=65536)
    {
        i=i*i*i;
    
        printf("%d\n",i);
    }
    
}