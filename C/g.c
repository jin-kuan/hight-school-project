#include <stdio.h>

int main(){

    int a;

    printf("��J�@�Ӿ��\n");
    scanf("%d", &a);

    if (a%2==0){
        if(a%12==0){
            printf("12������\n");
            }
        else{
            if(a%10==0){
                printf("10������");
            }   
            else{
                if(a%4==0){
                    if(a%8==0){
                        printf("8������");
                    }
                    else{
                        printf("4������");
                    }
                }
                else{
                    if(a%6==0){
                        printf("6������");
                    }
                    else{
                        printf("2������");

                    }
                }            
            }
        }
    }
    else{
        if(a%7==0){
            printf("7������");
        
        }
        else{
            if(a%5==0){
            printf("5������");
            }
            else{
                if(a%3==0){
                    if(a%9==0){
                        printf("9������");
                    }
                    else{
                        printf("3������");
                    }
                }
                else{
                    if(a%11==0){
                    printf("11������");
                    }
                    else{
                        printf("�Ʀr�Ӥj�F");


                    }
            }

        }
    
    }
          
    }
}