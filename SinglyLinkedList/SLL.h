#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int Data;
typedef struct Node{
    Data value;
    struct Node* next;
    int pos;
};

typedef struct Node* SinglyList;

SinglyList *l;

SinglyList* createLL(int *error);
void insertStart(SinglyList *l, Data val, int *error);
void insertEnd(SinglyList *l, Data val, int *error);
void insertNposition(SinglyList *l, Data val, int *error, int position);
void removeStart(SinglyList *l, int *error);
void removeEnd(SinglyList *l, int *error);
void removeN(SinglyList *l, int *error, int npos);
void showList(SinglyList *l, int *error);
int searchList(SinglyList current, int val);
void clearList(SinglyList *l, int *error);
SinglyList* copyList(SinglyList *l, int *error);
void deleteSLL(SinglyList *l, int *error);
