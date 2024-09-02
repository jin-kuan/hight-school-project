#include<stdio.h>
int main(){
int a,b,c,sum;

scanf("%d %d %d",&a,&b,&c);


if (a>c){
    sum=a;
    a=c;
    c=sum;
}

if(b>c){
    sum=b;
    b=c;
    c=sum;
}

if(a*a+b*b<c*c){
    printf("odtuse");
}

else  if(a*a+b*b==c*c){
   printf("right");
}

else if(a*a+b*b > c*c){
      printf("acute");
}

else{
    printf("no");

}
}
