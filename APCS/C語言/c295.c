#include<stdio.h>



int main(){

    int c=0;
    int max=-1;
    int b[20]={0};
    int sum=0;

    int n,m,a;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){

        max=-1;
        for(int j=0;j<m;j++){
            scanf("%d",&a);

            if(a>max){
                max=a;
            }

        }

        b[i]=max;
    }


    for(int i=0;i<n;i++){
        sum=sum+b[i];

    }


    printf("%d\n",sum);


    for(int i=0;i<n;i++){
        if(sum%b[i]==0){
            printf("%d ",b[i]);
            c=c+1;
        }
    }

    if(c==0){
        printf("-1");
    }






}
