#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef int Data;

typedef struct Node{
    Data value;
    int pos;
    struct Node *next;
};

typedef struct Node* CircularList;

CircularList *createCList(int *error);
Data extractBeginCL(CircularList *cl, int *error);
Data extractEndCL(CircularList *cl, int *error);
Data extractNCL(CircularList *cl, int *error, int npos);
void insertBeginCL(Data val, CircularList *cl, int *error);
void insertEndCL(Data val, CircularList *cl, int *error);
void insertNCL(Data val, CircularList *cl, int *error, int npos);
void clearCList(CircularList *cl, int *error);
void showCList(CircularList *cl, int *error);
void countNodesCL(CircularList *cl, int *error);
bool isEmptyCL(CircularList cl, int *error);