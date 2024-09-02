#include<stdio.h>
int main(){
    int k = 4;
    int m = 1;
    for(int i=1; i<4;i++){
          printf("\n");
        for(int j=1; j<=k; j++){
            printf("*");
        }
        for(int j=1; j<=m; j++){
            printf(" ");
        }
         for(int j=1; j<=k; j++){
            printf("*");
           
        }
       
        k=k-1;
        m=m+2;
         
    
    }
    printf("\n");
    for(int i=1; i<4;i++){
        k=k+1;
        m=m-2;
        for(int j=1; j<=k; j++){
            printf("*");
        }
        for(int j=1; j<=m; j++){
            printf(" ");
        }
         for(int j=1; j<=k; j++){
            printf("*");
           
        }
         printf("\n");
        
         

    }
    
}
