#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int Data;

typedef struct Node{
    Data valor;
    int pos;
    struct Node *ant,*sig;
} Node;

typedef struct Node* DoublyLL;

Node* create_Node(Data valor, int* error);
DoublyLL* create_doublyLL(int* error);

void insertEndDoubly(DoublyLL *l, Data valor, int* error);
void insertStartDoubly(DoublyLL *l, Data valor, int *error);
void insertNDoubly(DoublyLL *l, Data valor, int pos, int* error);

Data extractBeginDoubly(DoublyLL *l, int* error);
Data extractEndDoubly(DoublyLL *l, int* error);
Data extractNDoubly(DoublyLL *l, int pos, int* error);

void showDoublyLL(DoublyLL *l, int *error);
void clearDoublyLL(DoublyLL *l, int *error);
int lengthDoublyLL(DoublyLL l);
DoublyLL* copyDoublyLL(DoublyLL *l, int*error);

void sortDoublyLL(DoublyLL *arreglo, int tam, int *error);
void mergeDoublyLL(DoublyLL *arrIzq, int tamIzq, DoublyLL *arrDer, int tamDer, DoublyLL *arreglo, int *error);

void reverseLinkedList(DoublyLL *lista, int *error);
int searchDLL(DoublyLL *l, Data value, int *error);
void updateNodeDLL(DoublyLL *l, Data value, int pos, int *error);

void deleteDLL(DoublyLL *l, int *error);