#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SZ 10

typedef struct{
    int value;
} Node;

typedef struct{
    Node elements[SZ];
    int top;
} StackS;

void createStackS(int *error, StackS *s);
void getTopS(StackS s, int *error);
void pushS(StackS *s, int *error, Node data);
void popS(StackS *s, int *error, Node *remove);
bool isEmptyS(StackS s, int *error);
bool isFullS(StackS s, int *error);
void clearS(StackS *s, int *error);