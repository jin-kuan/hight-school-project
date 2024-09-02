#include<stdio.h>
int main(){
int x,sum;
int a=0;
int b=0;
int f=10;



scanf("%d",&x);


for(int i=2;i<100;i++){

    if(i%2==0){


        b=b+x%f;

    }
    else{
        a=a+x%f;
    }

    x=x/10;

    if(x==0){
        break;
    }


}


sum=a-b;
if(sum<0){
    sum=sum*-1;
}

printf("%d",sum);
}
