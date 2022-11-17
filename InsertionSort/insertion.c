#include "insertion.h"

void insertionSort(int *array, int size){
    int i, key, j;
    for (i = 1; i < size; i++){
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printArray(int *array, int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}