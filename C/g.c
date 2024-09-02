#include <stdio.h>

int main(){

    int a;

    printf("块俱计\n");
    scanf("%d", &a);

    if (a%2==0){
        if(a%12==0){
            printf("12计\n");
            }
        else{
            if(a%10==0){
                printf("10计");
            }   
            else{
                if(a%4==0){
                    if(a%8==0){
                        printf("8计");
                    }
                    else{
                        printf("4计");
                    }
                }
                else{
                    if(a%6==0){
                        printf("6计");
                    }
                    else{
                        printf("2计");

                    }
                }            
            }
        }
    }
    else{
        if(a%7==0){
            printf("7计");
        
        }
        else{
            if(a%5==0){
            printf("5计");
            }
            else{
                if(a%3==0){
                    if(a%9==0){
                        printf("9计");
                    }
                    else{
                        printf("3计");
                    }
                }
                else{
                    if(a%11==0){
                    printf("11计");
                    }
                    else{
                        printf("计び");


                    }
            }

        }
    
    }
          
    }
}