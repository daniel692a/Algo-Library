#include "queue.h"

int main(){
    int error;
    int n;
    Queue *myQueue = createQueue(&error);
    struct Node data;
    puts("Ingrese número de valores para la cola");
    fflush(stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d", &data.value);
        enqueue(myQueue, &error, data);
    }
    iterateQueue(myQueue, &error);
    struct Node *orderQueue = mergeSortQueue(myQueue->head, &error);
    iterateNodes(orderQueue, &error);
    return 0;
}