#include "SLL.h"

int main(){
    int error = 0;
    SinglyList *mysll = createLL(&error);
    SinglyList *myCopy;
    struct Node data;
    Data extract;
    int answer;
    int option;
    int position;
    do{
        puts("Menú de ususario");
        puts("1.Insertar al Inicio");
        puts("2.Insertar al Final");
        puts("3.Insertar en N posición");
        puts("4.Eliminar al Inicio");
        puts("5.Eliminar al Final");
        puts("6.Eliminar en N posición");
        puts("7.Mostrar Lista");
        puts("8.Buscar elemento");
        puts("9.Copiar Lista");
        puts("10.Limpiar Lista");
        puts("11.Contar Nodos");
        puts("12.Modificar Nodo");
        puts("------------------");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.value);
                insertStart(mysll, data.value, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &data.value);
                insertEnd(mysll, data.value, &error);
                break;
            case 3:
                puts("Inserte valor y la posición");
                scanf("%d %d", &data.value, &position);
                insertNposition(mysll, data.value, &error, position);
                break;
            case 4:
                removeStart(mysll, &error);
                break;
            case 5:
                removeEnd(mysll, &error);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &position);
                removeN(mysll, &error, position);
                break;
            case 7:
                showList(mysll, &error);
                break;
            case 8:
                puts("Inserte el valor a buscar");
                scanf("%d", &data.value);
                int answer = searchList(*mysll, data.value);
                printf("El valor se encuentra en la posición %d\n", answer);
                break;
            case 9:
                myCopy = copyList(mysll, &error);
                showList(myCopy, &error);
                break;
            case 10:
                clearList(mysll, &error);
                break;
            case 11:
                countNodesSL(mysll, &error);
                break;
            case 12:
                puts("Inserte la posición y el valor");
                scanf("%d %d", &position, &data.value);
                updateNode(mysll, &error, position, data.value);
                break;
            default:
                puts("No es una opción válida");
                break;
        }
        puts("¿Desea continuar?\t1-Sí\t2-No");
        scanf("%d", &answer);
        puts("------------------");
    } while (answer == 1);
    deleteSLL(myCopy, &error);
    deleteSLL(mysll, &error);
    puts("Gracias por usar el programa:)");
    return 0;
}