#include "CLL.h"

int main(){
    int error = 0;
    CircularList *myList = createCList(&error);
    Data new;
    Data extract;
    int answer;
    int option;
    do{
        puts("Menú de ususario\n");
        puts("1.Ingresar un nodo al final\n");
        puts("2.Ingresar un nodo al inicio\n");
        puts("3.Mostrar todos los nodos\n");
        puts("4.Contar nodos\n");
        puts("5.Eliminar el primer nodo\n");
        puts("6.Eliminar el ultimo nodo\n");
        puts("7.Eliminar toda la lista\n");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor\n");
                scanf("%d", &new);
                insertEnd(new, myList, &error);
                break;
            case 2:
                puts("Inserte valor\n");
                scanf("%d", &new);
                insertStart(new, myList, &error);
                break;
            case 3:
                showCList(myList, &error);
                break;
            case 4:
                countNodes(myList, &error);
                break;
            case 5:
                extract = extractStart(myList, &error);
                printf("Dato extraido: %d\n", extract);
                break;
            case 6:
                extract = extractEnd(myList, &error);
                printf("Dato extraido: %d\n", extract);
                break;
            case 7:
                clearCList(myList, &error);
                break;
            default:
                puts("No es una opcion valida\n");
                break;
        }
        puts("¿Desea continuar? 1-Si 2-No\n");
        scanf("%d", &answer);
    } while (answer == 1);
    return 0;
}