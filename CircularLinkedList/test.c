#include "CLL.h"

int main(){
    int error = 0;
    CircularList *myList = createCList(&error);
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
        puts("8.Mostrar la Lista");
        puts("9.Contar Nodos");
        scanf("%d", &option);
        puts("-------------------------");
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &new);
                insertBeginCL(new, myList, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &new);
                insertEndCL(new, myList, &error);
                break;
            case 3:
                puts("Inserte el valor y la posición");
                scanf("%d", &new);
                scanf("%d", &pos);
                insertNCL(new, myList, &error, pos);
                break;
            case 4:
                extract = extractBeginCL(myList, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 5:
                extract = extractEndCL(myList, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &pos);
                extract = extractNCL(myList, &error, pos);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 7:
                clearCList(myList, &error);
                break;
            case 8:
                showCList(myList, &error);
                break;
            case 9:
                countNodesCL(myList, &error);
                break;
            default:
                puts("No es una opcion valida");
                break;
        }
        puts("¿Desea continuar? 1-Si 2-No");
        scanf("%d", &answer);
        puts("-------------------------");
    } while (answer == 1);
    showCList(myList, &error);
    free(myList);
    puts("Fin del programa");
    return 0;
}