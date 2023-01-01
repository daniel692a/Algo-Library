#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int Data;

typedef struct Node{
    Data value;
    int pos;
    struct Node *prev, *next;
} Node;

typedef struct Node* DCLL;

Node* createNode(Data val, int *error);
DCLL* createDCLL(int *error);
void insertEndDCLL(DCLL *l, Data val, int *error);
void insertStartDCLL(DCLL *l, Data val, int *error);
void insertNDCLL(DCLL *l, Data val, int pos, int *error);
void showDCLL(DCLL *l, int *error);
void extractBeginDCLL(DCLL *l, Data *val, int *error);
void extractEndDCLL(DCLL *l, Data *val, int *error);
void extractNDCLL(DCLL *l, Data *val, int pos, int *error);
void clearDCLL(DCLL *l);
int lengthDCLL(DCLL l);
void copyDCLL(DCLL *l, DCLL *copyL, int *error);
void sortDCLL(DCLL *arreglo, int tam, int *error);
void mergeDCLL(DCLL *arrIzq, int tamIzq, DCLL *arrDer, int tamDer, DCLL *arreglo, int *error);