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
void insertBeginCL(Data val, CircularList *cl, int *error);
void insertEndCL(Data val, CircularList *cl, int *error);
void insertNCL(Data val, CircularList *cl, int *error, int npos);

Data extractBeginCL(CircularList *cl, int *error);
Data extractEndCL(CircularList *cl, int *error);
Data extractNCL(CircularList *cl, int *error, int npos);

void showCList(CircularList *cl, int *error);
int searchCList(CircularList *cl, int val, int *error);
CircularList* copyCList(CircularList *cl, int *error);
void clearCList(CircularList *cl, int *error);
void countNodesCL(CircularList *cl, int *error);
void updateNodeCL(CircularList *cl, int *error, int npos, Data val);
bool isEmptyCL(CircularList cl, int *error);
void deleteCList(CircularList *cl, int *error);