#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef int Data;

struct Node{
    Data val;
    int pos;
    struct Node *next;
};

typedef struct Node* List;

List* createList(int *error);
Data extractStart(List *l, int *error);
Data extractEnd(List *l, int *error);
void insertStart(Data val, List *l, int *error);
void insertEnd(Data val, List *l, int *error);