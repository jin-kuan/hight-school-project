#include<stdio.h>
int main(){
int a,b,c,d;

printf("輸入三角型的三邊長\n");
scanf("%d %d %d",&a,&b,&c);

if(a>c){
    d=a;
    a=c;
    c=d;
}

if(b>c){
    d=b;
    b=c;
    c=d;
}

if(a>b){
    d=a;
    a=b;
    b=d;
}
printf("邊長為:%d %d %d ",a,b,c);

if(a+b<c){
    printf("不可能是三角形");
}
else{
    if(a*a+b*b==c*c){
        printf("直角三角形");
    }
    else if(c==a||c==b){
        printf("等鈍銳角三角形");
    }
    else if(a==b){
        printf("等腰鈍角三角形");
    }
    else if(a==b==c){
        printf("正三角形");
    }

    else{
        printf("一般的三角形");
    }
}



}
