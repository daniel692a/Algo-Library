#include "queue.h"

int main(){
    int error = 0;
    Queue *myQueue = createQueue(&error);
    struct Node data;
    Data extract;
    int answer;
    int option;
    struct Node* result;
    do{
        puts("Menú de ususario");
        puts("1.Encolar");
        puts("2.Desencolar");
        puts("3.Limpiar la cola");
        puts("4.Mostrar la cola");
        puts("5.Ordenar la cola");
        puts("------------------");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.value);
                enqueue(myQueue, &error, data);
                break;
            case 2:
                extract = dequeue(myQueue, &error);
                printf("Dato extraido: %d\n", extract);
                break;
            case 3:
                clear(myQueue, &error);
                break;
            case 4:
                iterateQueue(myQueue, &error);
                break;
            case 5:
                result = mergeSortQueue(myQueue->head, &error);
                iterateNodes(result, &error);
                break;
            default:
                puts("No es una opción válida");
                break;
        }
        puts("¿Desea continuar?\t1-Sí\t2-No");
        scanf("%d", &answer);
        puts("------------------");
    } while (answer == 1);
    deleteQueue(myQueue, &error);
    puts("Gracias por usar el programa:)");
    return 0;
}