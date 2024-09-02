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
int main(){

    big(21,15);



}