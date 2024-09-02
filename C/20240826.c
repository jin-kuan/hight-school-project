// #include<stdio.h>

// void abc(int h){

    
//     int b;
//     int a;
//     int s=1;
//     b=h*2+1;
//     a=b/2;

//     for(int i=0;i<h;i++){
//         for(int j=0;j<h-i-1;j++){
//             printf(" ");
//         }
//         for(int u=0;u<s;u++){
//             printf("*");
//         }
//         printf("\n");
//         s=s+2;
//         // for(int j=0;j<b;j++){
        



//     }
//     s=s-4;
//     for(int i=0;i<h-1;i++){
//         for(int u=0;u<i+2-1;u++){
//             printf(" ");
            
//         }
//         for(int k=0;k<s;k++){
//             printf("*");
//         }
//         s=s-2;
//         printf("\n");
//     }


// }
// int main(){
//     int h;
//     scanf("%d",&h);
//     abc(h);

// }


#include <stdio.h>
#include <time.h>


void abc(int h){

    
    int b;
    int a;
    int s=1;
    b=h*2+1;
    a=b/2;

    for(int i=0;i<h;i++){
        for(int j=0;j<h-i-1;j++){
            printf(" ");
        }
        for(int u=0;u<s;u++){
            printf("*");
        }
        printf("\n");
        s=s+2;
        // for(int j=0;j<b;j++){
        



    }
    s=s-4;
    for(int i=0;i<h-1;i++){
        for(int u=0;u<i+2-1;u++){
            printf(" ");
            
        }
        for(int k=0;k<s;k++){
            printf("*");
        }
        s=s-2;
        printf("\n");
    }


}

int main() {
    clock_t START, END;
    START = clock();
    // 要測量的程式碼區域
    long h=1000000000;
    // // scanf("%d",&h);
    // abc(h);
    double  a=2;
    double  b=3;
    for (int i=0;i<h;i++){
        b=b+4/(a*(a+1)*(a+2))-4/((a+2)*(a+3)*(a+4));
        a=a+4;
    }
    b=b*10000000;
    printf("%f",b);
    END = clock();

    printf("執行時間：%f 秒\n", (double)(END - START) / CLOCKS_PER_SEC);
    return 0;
}

