#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int Value;

typedef struct Node{
    Value value;
    struct Node* below;
};

typedef struct{
    struct Node* top;
    int size;
} Stack;

Stack *createStack(int *error);
void getTop(Stack p, int *error);
void push(Stack *p, int *error, struct Node newValue);
Value pop(Stack *p, int *error);
bool isEmpty(Stack p, int *error);
void clearStack(Stack *s, int *error);
void deleteStack(Stack *p, int *error);
void showStack(Stack s, int *error);