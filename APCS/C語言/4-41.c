#include<stdio.h>
int main(){

int a,b,n;


int sum=0;

int total=0;

scanf("%d %d",&a,&b);

scanf("%d",&n);




for (int i=0; i<n;i++){
        scanf("%d",&sum);

        int A=0;
        int B=0;

        while(sum!=0){
            if(sum==a){
                A++;
            }

            if(sum==-a){
                A--;
            }

            if(sum==b){
                B++;
            }
            if(sum==-b){
                B--;
            }

            scanf("%d",&sum);
        }


        if(A>0&&B>0){

            total++;
        }
}


printf("%d",total);
}


