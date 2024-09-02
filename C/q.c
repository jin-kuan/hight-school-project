#include<stdio.h>
int main(){
    int a, b=0, c=0, n=0;
    
   

    scanf("%d",&a);
    int s[a];
    for(int i=0; i<a; i++){
      scanf("%d",&s[i]);
    }
    
    for(int u=0; u<a; u++){
      for(n=0; n<a-1; n++){
            if(s[n]<s[n+1]){
                c=s[n];
                s[n]=s[n+1];
                s[n+1]=c;
            }
        }
    }
    for(int j=0; j<a; j++){
        printf("%d ",s[j]);
    }
printf("\n");

  if(s[a-1]>=60){ 
        printf("best case\n");
        printf("%d\n",s[a-1]);
    }
    else if (s[0]<60){
        printf("worst case\n");
        printf("%d\n",s[0]);
    }

    else{
        for(int g=0; g<a; g++){
            if(s[g]<60){
                printf("%d/n",s[g]);
                break;
            }
        }
        for(int p=a-1; p>=0; p=p-1){
            if(s[p]>=60){
                printf("%d",s[p]);
                break;
            }
        }
    }  
}