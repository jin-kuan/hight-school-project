#include<stdio.h>
int main(){
    int n=0;
    int m[5]={};
    
void logic (int i, int j, int k){


    while (n<5)
    {
        m[n]=i*j+k;
        printf("%d * %d + %d =%d\n",i,j,k,m[n]);
        n++;
        i++;
        k=k-1;
    }

}
    
logic(1,5,4);

}