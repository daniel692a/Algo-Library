#include "stack.h"

int main(int argc, char **argv){
    int error = 0;
    Stack *myStack = createStack(&error);
    struct Node data;
    Value extract;
    int answer;
    int option;
    do{
        puts("Menú de ususario");
        puts("1.Push");
        puts("2.Obtener el tope");
        puts("3.Pop");
        puts("4.Mostrar la pila");
        puts("5.Limpiar la pila");
        puts("------------------");
        scanf("%d", &option);
        switch (option){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.value);
                push(myStack, &error, data);
                break;
            case 2:
                getTop(*myStack, &error);
                break;
            case 3:
                extract = pop(myStack, &error);
                printf("Valor extraido: %d\n", extract);
                break;
            case 4:
                showStack(*myStack, &error);
                break;
            case 5:
                clearStack(myStack, &error);
                break;
            default:
                puts("No es una opción válida");
                break;
        }
        puts("¿Desea continuar?\t1-Sí\t2-No");
        scanf("%d", &answer);
        puts("------------------");
    } while (answer == 1);
    deleteStack(myStack, &error);
    puts("Gracias por usar el programa:)");
    return 0;
}