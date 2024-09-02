#include<stdio.h>

int main(){
    int b[2];
    
    int p=0;
    
    for (int i = 0; i<2;i++){
        scanf("%d",&b[i]);
    }
    
    int c[10000];
    for(int i = 0; i<b[0];i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<b[1];i++){
        scanf("%d",&p);

        for(int h=0;h<b[0];h++){
            for(int j = h; j<b[0];j++){
                
                if(p==c[h]-c[j]){
                    p++;
                    printf("YES");

        }
        }
    }
    if (p==0){
        printf("NO");
    }
    }
    
}
    

