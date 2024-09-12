#include<stdio.h>

void abc2(){
    float a,b,c,d,e,f;
    float p,g,z;
    float x,y;
    printf("aX+bY=c\n");
    printf("dX+eY=f\n");
    printf("a=");
    scanf("%f",&a);
    
    printf("b=");
    scanf("%f",&b);

    printf("c=");
    scanf("%f",&c);
   
    printf("d=");
    scanf("%f",&d);
  
    printf("e=");
    scanf("%f",&e);
   
    printf("f=");
    scanf("%f",&f);

 
    p=a*e-b*d;
    g=c*e-b*f;
    z=a*f-c*d;

    x=g/p;
    y=z/p;

    printf("X=%f\n",x);
    printf("Y=%f\n",y);

}
void print(){
    for(int i=0;i<20;i++){
        printf("+");
    }
    printf("\n");
}

int main(){
    int n;
    while(1){
        printf("二元一次:1\n");
        printf("三元一次:2\n");
        printf("輸入:");
        scanf("%d",&n);
        if(n==1){
            print();
    
            abc2();
        }
        else if(n==2){
            print();
            // abc3();
        }
        else if(n==0){
            return 0;
        }
        else{
            printf("重來");
        }
                   
    }
}