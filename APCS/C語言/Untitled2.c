#include<stdio.h>
int main(){
int a,b,c,d;

printf("��J�T�������T���\n");
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
printf("�����:%d %d %d ",a,b,c);

if(a+b<c){
    printf("���i��O�T����");
}
else{
    if(a*a+b*b==c*c){
        printf("�����T����");
    }
    else if(c==a||c==b){
        printf("���w�U���T����");
    }
    else if(a==b){
        printf("���y�w���T����");
    }
    else if(a==b==c){
        printf("���T����");
    }

    else{
        printf("�@�몺�T����");
    }
}



}
