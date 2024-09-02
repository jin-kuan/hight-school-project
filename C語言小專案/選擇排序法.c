#include <stdio.h>
#define size 8

void selectionSort(int *);
void printArray(int *);

int main() {
    int date[size] = {16, 25, 39, 27, 12, 8, 45, 63};
    selectionSort(date);
    printArray(date);
    return 0;
}

void selectionSort(int *arry) {
    void swap(int *, int *);
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;

        for (j = i + 1; j < size; j++) {
            if (arry[min_index] > arry[j]) {
                min_index = j;
            }
        }
        swap(&arry[min_index], &arry[i]);
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arry) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arry[i]);
    }
    printf("\n");
}
