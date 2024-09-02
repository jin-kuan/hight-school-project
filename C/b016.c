#include<stdio.h>

int ans;
void abc(int h,int w){
     ans=h*w;
}

int main(){
   
    abc(2,4);
    printf("%d",ans);
}