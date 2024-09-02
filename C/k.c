#include<stdio.h>
int main(){
    int a, b=0, c=0, n=0;
    
   

    scanf("%d",&a);
    int s[a];
    for(int i=0; i<a; i++){
      scanf("%d",&s[i]);
    }

    
    for(int j=0; j<a; j++){
        printf("%d ",s[j]);
    }
printf("\n");
}

