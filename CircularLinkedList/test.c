#include "CLL.h"

int main(){
    int error = 0;
    CircularList *mycll = createCList(&error);
    CircularList *cllcpy;
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
                insertBeginCL(data.value, mycll, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &data.value);
                insertEndCL(data.value, mycll, &error);
                break;
            case 3:
                puts("Inserte valor y la posición");
                scanf("%d %d", &data.value, &position);
                insertNCL(data.value, mycll, &error, position);
                break;
            case 4:
                extract = extractBeginCL(mycll, &error);
                printf("El valor extraído es: %d\n", extract);
                break;
            case 5:
                extract = extractEndCL(mycll, &error);
                printf("El valor extraído es: %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &position);
                extract = extractNCL(mycll, &error, position);
                printf("El valor extraído es: %d\n", extract);
                break;
            case 7:
                showCList(mycll, &error);
                break;
            case 8:
                puts("Inserte el valor a buscar");
                scanf("%d", &data.value);
                int answer = searchCList(mycll, data.value, &error);
                printf("El valor se encuentra en la posición %d\n", answer);
                break;
            case 9:
                cllcpy = copyCList(mycll, &error);
                showCList(cllcpy, &error);
                break;
            case 10:
                clearCList(mycll, &error);
                break;
            case 11:
                countNodesCL(mycll, &error);
                break;
            case 12:
                puts("Inserte la posición y el valor");
                scanf("%d %d", &position, &data.value);
                updateNodeCL(mycll, &error, position, data.value);
                break;
            default:
                puts("No es una opción válida");
                break;
        }
        puts("¿Desea continuar?\t1-Sí\t2-No");
        scanf("%d", &answer);
        puts("------------------");
    } while (answer == 1);
    deleteCList(mycll, &error);
    deleteCList(cllcpy, &error);
    puts("Gracias por usar el programa:)");
    return 0;
}