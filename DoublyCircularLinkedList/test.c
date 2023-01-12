#include "DCLL.h"

int main(){
    int error = 0;
    DCLL *myList = createDCLL(&error);
    DCLL *copyList = createDCLL(&error);
    Data new;
    Data extract;
    int answer;
    int option;
    int pos;
    int search;
    do{
        puts("Menú de ususario");
        puts("1.Insertar al inicio");
        puts("2.Insertar al final");
        puts("3.Insertar en una posición");
        puts("4.Extraer del inicio");
        puts("5.Extraer del final");
        puts("6.Extraer de una posición");
        puts("7.Mostrar Lista");
        puts("8.Buscar un elemento");
        puts("9.Copiar Lista");
        puts("10.Limpiar Lista");
        puts("11.Contar Nodos");
        puts("12.Modificar Nodo");
        scanf("%d", &option);
        puts("-------------------------");
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &new);
                insertBeginDCLL(myList, new, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &new);
                insertEndDCLL(myList, new, &error);
                break;
            case 3:
                puts("Inserte el valor y la posición");
                scanf("%d", &new);
                scanf("%d", &pos);
                insertNDCLL(myList, new, pos, &error);
                break;
            case 4:
                extract = deleteBeginDCLL(myList, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 5:
                extract = deleteEndDCLL(myList, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &pos);
                extract = deleteNDCLL(myList, pos, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 7:
                showDCLL(*myList);
                break;
            case 8:
                puts("Inserte el valor a buscar");
                scanf("%d", &search);
                printf("El elemento se encuentra en la posición: %d\n", searchDCLL(myList, search, &error));
                break;
            case 9:
                copyList = copyDCLL(myList, &error);
                showDCLL(*copyList);
                break;
            case 10:
                clearDCLL(myList, &error);
                break;
            case 11:
                printf("La lista tiene %d nodos\n", lengthDCLL(*myList));
                break;
            case 12:
                puts("Inserte el valor y la posición");
                scanf("%d %d", &new, &pos);
                updateNodeDCLL(myList, new, pos, &error);
                break;
            default:
                puts("No es una opcion valida");
                break;
        }
        puts("¿Desea continuar? 1-Si 2-No");
        scanf("%d", &answer);
        puts("-------------------------");
    } while (answer == 1);
    deleteDCLL(myList, &error);
    deleteDCLL(copyList, &error);
    puts("Programa terminado");
    return 0;
}