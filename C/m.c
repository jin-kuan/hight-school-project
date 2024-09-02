#include<stdio.h>
int main(){
    for(int s=1; s<=100; s++){
        if (s>=90){
            printf("%d A\n",s);
        }
        else if (s>=80)
        {
            printf("%d B\n",s);
        }
         else if (s>60)
        {
            printf("%d C\n",s);
        }
         else if (s>70)
        {
            printf("%d D\n",s);
        }
         else 
        {
            printf("%d F\n",s);
        }
        
    }
}