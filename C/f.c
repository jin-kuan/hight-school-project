#include <stdio.h>

int a;

int main(){
printf("成績\n");
scanf("%d", &a);
printf("成績為:");
printf("%d\n",a);

if(a>=60){

    printf("及格 \n"); 
}

else if (a<60){
    printf("當掉\n");
}

else{
    printf("不要騙了");
}



return 0;

    

}
