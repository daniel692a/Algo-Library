#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node{
    Data value;
    struct Node* next;
};

typedef struct {
    struct Node *head;
    struct Node *tail;
    int size;
} BiQueue;

BiQueue *createBiQueue(int *error);
void enqueue(BiQueue *bq, int *error, struct Node newNode);
void enqueueStart(BiQueue *bq, int *error, struct Node newNode);
Data dequeue(BiQueue *bq, int *error);
void countNodes(BiQueue *q, int *error);
bool isEmpty(BiQueue bq, int *error);
void clear(BiQueue *bq, int *error);
void deleteBiQueue(BiQueue *bq, int *error);
void iterateBiQueue(BiQueue *bq, int *error);