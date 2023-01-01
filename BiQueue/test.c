#include "BiQueue.h"

int main(){
    int error = 0;
    BiQueue *myBiQueue = createBiQueue(&error);
    struct Node data;
    Data extract;
    int answer;
    int option;
    do{
        puts("Menú de ususario");
        puts("1.Encolar");
        puts("2.Encolar al inicio");
        puts("3.Desencolar");
        puts("4.Contar nodos");
        puts("5.Limpiar la bicola");
        puts("6.Mostrar la bicola");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.value);
                enqueue(myBiQueue, &error, data);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &data.value);
                enqueueStart(myBiQueue, &error, data);
                break;

            case 3:
                extract = dequeue(myBiQueue, &error);
                printf("Dato extraido: %d\n", extract);
                break;
            case 4:
                countNodes(myBiQueue, &error);
                break;
            case 5:
                clear(myBiQueue, &error);
                break;
            case 6:
                iterateBiQueue(myBiQueue, &error);
                break;
            default:
                puts("No es una opción válida\n");
                break;
        }
        puts("¿Desea continuar?\n1-Sí\t2-No");
        scanf("%d", &answer);
    } while (answer==1);
    deleteBiQueue(myBiQueue, &error);
    puts("Gracias por usar el programa:)");
    return 0;
}