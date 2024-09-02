
#include<stdio.h>

int big(int a,int b){
    int c;

        c=a%b;
        if(c!=0){
            big(b,c);
        }

        else{
            printf("%d",b);
        }




}


int max(int a,int b){

    int c;
    if(b>a){
        c=a;
        a=b;
        b=c;
    }
    big(a,b);



}
int main(){

    int a,b;

   scanf("%d %d",&a,&b);
   max(a,b);



}
