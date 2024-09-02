#include<stdio.h>
int main(){
int m,n,k,p;
int a[1000]={0};
int c=0;
int d=0;
int u=1;
scanf("%d %d %d",&n,&m,&k);

for(int i=0;i<n+1;i++){
    a[i]=1;
}



while(u){




    for(int i=0;i<n+1;i++){\



        if(a[i]==1){
            c=c+1;



        }

        if(c%m==0){

            a[i]=0;


        }

         if(c==m*k){
            printf("%d",i+1);

            return 0;

         }

    }





}



}
