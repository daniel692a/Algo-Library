#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef int Data;

struct Node{
    Data value;
    int pos;
    struct Node *next;
};

typedef struct Node* CircularList;

CircularList *createCList(int *error);
Data extractStart(CircularList *cl, int *error);
Data extractEnd(CircularList *cl, int *error);
void insertStart(Data val, CircularList *cl, int *error);
void insertEnd(Data val, CircularList *cl, int *error);
void clearCList(CircularList *cl, int *error);
void showCList(CircularList *cl, int *error);
void countNodes(CircularList *cl, int *error);
bool isEmpty(CircularList cl, int *error);