#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int Data;

typedef struct Node{
    Data valor;
    int pos;
    struct Node *ant,*sig;
}Node;

typedef struct Node* DoublyLL;

Node* create_Node(Data valor, int* error);
DoublyLL* create_doublyLL(int* error);
DoublyLL create_doubly2(int *error);
void insertEndDoubly(DoublyLL *l, Data valor, int* error);
void insertStartDoubly(DoublyLL *l, Data valor, int *error);
void insertNDoubly(DoublyLL *l, Data valor, int pos, int* error);
void showDoublyLL(DoublyLL *l, int *error);
void extractBeginDoubly(DoublyLL *l, Data *valor, int* error);
void extractEndDoubly(DoublyLL *l, Data *valor, int* error);
void extractNDoubly(DoublyLL *l, Data *valor, int pos, int* error);
void clearDoublyLL(DoublyLL *l);
int lengthDoublyLL(DoublyLL l);
void copyDoublyLL(DoublyLL *l, DoublyLL *copia, int*error);
void sortDoublyLL(DoublyLL *arreglo, int tam, int *error);
void mergeDoublyLL(DoublyLL *arrIzq, int tamIzq, DoublyLL *arrDer, int tamDer, DoublyLL *arreglo, int *error);
void reverseLinkedList(DoublyLL *lista, int *error);