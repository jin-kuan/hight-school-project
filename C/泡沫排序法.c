#include<stdio.h>
#define size 8

void bubbleSort(int *);
void printArray(int *);
int main(){
    int date[size]={16,25,39,27,12,8,45,63};
    bubbleSort(date);
    printArray(date);
}

void  bubbleSort(int *array){
    void swap (int *,int *);
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1-i;j++){
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);

            }   
        }
    }
}

void swap(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void printArray(int *array){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",array[i]);
    }
}