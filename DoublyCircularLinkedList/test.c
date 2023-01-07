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
    do{
        puts("Menú de ususario");
        puts("1.Insertar al inicio");
        puts("2.Insertar al final");
        puts("3.Insertar en una posición");
        puts("4.Extraer del inicio");
        puts("5.Extraer del final");
        puts("6.Extraer de una posición");
        puts("7.Limpiar la Lista");
        puts("8.Copiar la Lista");
        puts("9.Mostrar la Lista");
        puts("10.Contar Nodos");
        puts("11.Ordenar Lista");
        scanf("%d", &option);
        puts("-------------------------");
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &new);
                insertStartDCLL(myList, new, &error);
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
                extractBeginDCLL(myList, &extract, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 5:
                extractEndDCLL(myList, &extract, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &pos);
                extractNDCLL(myList, &extract, pos, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 7:
                clearDCLL(myList);
                break;
            case 8:
                copyDCLL(myList, copyList, &error);
                break;
            case 9:
                showDCLL(myList, &error);
                break;
            case 10:
                printf("La lista tiene %d nodos\n", lengthDCLL(*myList));
                break;
            case 11:
                sortDCLL(myList, lengthDCLL(*myList), &error);
                puts("-------------------------");
                showDCLL(myList, &error);
                break;
            default:
                puts("No es una opcion valida");
                break;
        }
        puts("¿Desea continuar? 1-Si 2-No");
        scanf("%d", &answer);
        puts("-------------------------");
    } while (answer == 1);
    return 0;
}