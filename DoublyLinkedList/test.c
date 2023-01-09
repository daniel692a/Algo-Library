#include "DLL.h"

int main(){
    int error = 0;
    DoublyLL *mydll = create_doublyLL(&error);
    DoublyLL *dllcpy;
    Node data;
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
        puts("13.Ordenar Lista");
        puts("14.Revertir lista");
        puts("------------------");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.valor);
                insertStartDoubly(mydll, data.valor, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &data.valor);
                insertEndDoubly(mydll, data.valor, &error);
                break;
            case 3:
                puts("Inserte valor y la posición");
                scanf("%d %d", &data.valor, &position);
                insertNDoubly(mydll, data.valor, position, &error);
                break;
            case 4:
                extract = extractBeginDoubly(mydll, &error);
                printf("El valor extraido es %d\n", extract);
                break;
            case 5:
                extract = extractEndDoubly(mydll, &error);
                printf("El valor extraido es %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &position);
                extract = extractNDoubly(mydll, position, &error);
                printf("El valor extraido es %d\n", extract);
                break;
            case 7:
                showDoublyLL(mydll, &error);
                break;
            case 8:
                puts("Inserte el valor a buscar");
                scanf("%d", &data.valor);
                int answer = searchDLL(mydll, data.valor, &error);
                printf("El valor se encuentra en la posición %d\n", answer);
                break;
            case 9:
                dllcpy = copyDoublyLL(mydll, &error);
                showDoublyLL(dllcpy, &error);
                break;
            case 10:
                clearDoublyLL(mydll, &error);
                break;
            case 11:
                printf("La lista tiene %d nodos\n", lengthDoublyLL(*mydll));
                break;
            case 12:
                puts("Inserte la posición y el valor");
                scanf("%d %d", &position, &data.valor);
                updateNodeDLL(mydll, data.valor, position, &error);
                break;
            case 13:
                sortDoublyLL(mydll, lengthDoublyLL(*mydll), &error);
                showDoublyLL(mydll, &error);
                break;
            case 14:
                reverseLinkedList(mydll, &error);
                showDoublyLL(mydll, &error);
                break;
            default:
                puts("No es una opción válida");
                break;
        }
        puts("¿Desea continuar?\t1-Sí\t2-No");
        scanf("%d", &answer);
        puts("------------------");
    } while (answer == 1);
    deleteDLL(mydll, &error);
    deleteDLL(dllcpy, &error);
    puts("Gracias por usar el programa:)");
    return 0;
}