#include "BiQueue.h"

/*
    @def Función para incializar una bicola
    @param *error Manejar errores internos
*/
BiQueue* createBiQueue(int *error){
    BiQueue *newBiQueue = malloc(sizeof(BiQueue));
    if(newBiQueue==NULL){
        perror("No hay memoria para la Bicola");
        *error = -2;
        return NULL;
    }
    newBiQueue->head=NULL;
    newBiQueue->tail=NULL;
    newBiQueue->size=0;
    *error=0;
    return newBiQueue;
}

/*
    @def Función para encolar al final
    @param bq Estructura BiCola
    @param error Manejador de errores
    @param newNode Nodo que insertaremos a la cola
*/
void enqueue(BiQueue *bq, int *error, struct Node newNode){
    struct Node *nodeUser = malloc(sizeof(struct Node));
    if(nodeUser==NULL){
        perror("No hay memoria para almacenar tu información");
        *error = -1;
        return;
    }
    nodeUser->value = newNode.value;
    nodeUser->next = NULL;
    if(isEmpty(*bq, error)){
        bq->head = nodeUser;
        bq->tail = nodeUser;
    } else {
        bq->tail->next = nodeUser;
        bq->tail = bq->tail->next;
    }
    *error = 0;
    bq->size=bq->size+1;
}

/*
    @def Función para encolar al inicio
    @param bq Estructura BiCola
    @param error Manejador de errores
    @param newNode Nodo que insertaremos a la cola
*/
void enqueueStart(BiQueue *bq, int *error, struct Node newNode){
    struct Node *nodeUser = malloc(sizeof(struct Node));
    if(nodeUser==NULL){
        perror("No hay memoria para almacenar tu información");
        *error = -1;
        return;
    }
    nodeUser->value = newNode.value;
    nodeUser->next = NULL;
    if(isEmpty(*bq, error)){
        bq->head = nodeUser;
        bq->tail = nodeUser;
    } else {
        nodeUser->next = bq->head;
        bq->head = nodeUser;
    }
    *error = 0;
    bq->size = bq->size+1;
}

/*
    @def Función para desencolar del inicio
    @param bq Estructura BiCola
    @param error Manejador de errores
*/
Data dequeue(BiQueue *bq, int *error){
    struct Node *aux = malloc(sizeof(struct Node));
    if(isEmpty(*bq, error)){
        perror("No puedes realizar esta operacion");
        *error = -1;
        return -1;
    } else {
        aux->value = bq->head->value;
        aux->next = NULL;
        if (bq->size==1){
            bq->head = NULL;
            bq->tail = NULL;
            bq->size = 0;
        } else {
            bq->head = bq->head->next;
            bq->size = bq->size-1;
        }
        *error=0;
        return aux->value;
    }
}

/*
    @def Función para contar los nodos
    @param bq Estructura BiCola
    @param error Manejador de errores
*/
void countNodes(BiQueue *q, int *error){
    if(isEmpty(*q, error)){
        perror("No hay nodos\n");
        *error = -1;
    } else {
        printf("%d \n", q->size);
    }
}

/*
    @def Función para desencolar del inicio
    @param bq Estructura BiCola
    @param error Manejador de errores
*/
bool isEmpty(BiQueue q, int *error){
    if (q.size == 0){
        *error = -3;
        return true;
    } else {
        *error = 0;
        return false;
    }
}

/*
    @def Función para limpiar todos los nodos de mi cola
    @param bq Estructura BiCola
    @param error Manejador de errores
*/
void clear(BiQueue *bq, int *error){
    struct Node *aux = malloc(sizeof(struct Node));
    while(!isEmpty(*bq, error)){
        aux = bq->head;
        printf("Eliminando nodo con valor: %d\n", aux->value);
        bq->head = bq->head->next;
        bq->size = bq->size - 1;
    }
    free(aux);
    *error = 0;
}

/*
    @def Función para borrar la cola
    @param bq Estructura BiCola
    @param error Manejador de errores
*/
void deleteBiQueue(BiQueue *bq, int *error){
    if(isEmpty(*bq, error)){
        perror("No hay información en la cola\n");
        *error = -1;
    } else{
        clear(bq, error);
        free(bq);
        *error=0;
    }
}

/*
    @def Función para mostrar los datos de la cola
    @param bq Estructura BiCola
    @param error Manejador de errores
*/
void iterateBiQueue(BiQueue *bq, int *error){
    struct Node *temp = bq->head;
    printf("----------------------\n");
    while(temp){
        printf("%d \n", temp->value);
        temp = temp->next;
    }
    printf("\n");
    *error = 0;
}