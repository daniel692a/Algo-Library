#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int Data;

typedef struct Node{
    Data value;
    int pos;
    struct Node *prev, *next;
} Node;

typedef struct Node* DCLL;

Node* createNode(Data val, int* error);
DCLL* createDCLL(int* error);

void insertBeginDCLL(DCLL* l,Data val, int* error);
void insertEndDCLL(DCLL* l, Data val, int* error);
void insertNDCLL(DCLL* l, Data val, int pos, int* error);

Data deleteEndDCLL(DCLL* l, int* error);
Data deleteBeginDCLL(DCLL* l, int* error);
Data deleteNDCLL(DCLL* l, int pos, int* error);

void showDCLL(DCLL l);
int lengthDCLL(DCLL l);
void clearDCLL(DCLL* l, int *error);

DCLL* copyDCLL(DCLL *l, int* error);
int searchDCLL(DCLL *l, Data val, int *error);
void updateNodeDCLL(DCLL *l, Data val, int pos, int *error);

void deleteDCLL(DCLL *l, int *error);