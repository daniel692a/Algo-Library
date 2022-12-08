#include "BiQueue.h"

int main(){
    int error = 0;
    BiQueue *myQueue = createBiQueue(&error);
    struct Node data;
    Data extract;
    int answer;
    int option;
    do{
        puts("Menú de ususario\n");
        puts("1.Ingresar un nodo por la derecha\n");
        puts("2.Ingresar un nodo por la izquierda\n");
        puts("3.Mostrar todos los nodos\n");
        puts("4.Contar nodos\n");
        puts("5.Eliminar el primer nodo\n");
        puts("6.Eliminar toda la bicola\n");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor\n");
                scanf("%d", &data.value);
                enqueue(myQueue, &error, data);
                break;
            case 2:
                puts("Inserte valor\n");
                scanf("%d", &data.value);
                enqueueStart(myQueue, &error, data);
                break;

            case 3:
                iterateBiQueue(myQueue, &error);
                break;
            case 4:
                countNodes(myQueue, &error);
                break;
            case 5:
                extract = dequeue(myQueue, &error);
                printf("Dato extraido: %d\n", extract);
                break;
            case 6:
                deleteBiQueue(myQueue, &error);
                break;

            default:
                puts("No es una opcion valida\n");
                break;
        }
        puts("¿Desea continuar? 1-Si 2-No\n");
        scanf("%d", &answer);
    } while (answer==1);
    return 0;
}