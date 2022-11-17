#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef int Value;

void split(int *array, int l, int r);
void merge(int *arr, int l, int m, int r);
void printArray(int *array, int size);