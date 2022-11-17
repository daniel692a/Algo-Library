#include "selectionSort.h"

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int *array, int n){
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&array[min_idx], &array[i]);
    }
}

void printArray(int *array, int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}