#include <stdio.h>



int main(){
    int m,d; 
    scanf("%d %d", &m, &d);
  
    int S = (m*2+d)%3;
   
    switch (S){
         case 0:

            printf("���q\n");
            break;
        case 1:
            printf("�N\n");
            break;
        case 2:
            printf("�j�N");

    }

       

    
    
    
    
}