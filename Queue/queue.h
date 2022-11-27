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
} Queue;

Queue *createQueue(int *error);
void enqueue(Queue *q, int *error, struct Node newNode);
Data dequeue(Queue *q, int *error);
bool isEmpty(Queue q, int *error);
void clear(Queue *q, int *error);
void deleteQueue(Queue *q, int *error);
void iterateQueue(Queue *q, int *error);
void iterateNodes(struct Node *h, int *error);
struct Node *mergeSortQueue(struct Node *head, int *error);
struct Node *merge(struct Node *list1, struct Node *list2, int *error);
struct Node *getMid(struct Node *h, int *error);