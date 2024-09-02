#include<stdio.h>
 float abc(int r){
        return r*r*3.14;
}
    int main(){
   int t;
   scanf("%d",&t);
   float ans=abc(t);
   printf("%f",ans);
}