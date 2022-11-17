#include "stack.h"

int main(int argc, char **argv){
    int error;
    int n;
    Stack *s = createStack(&error);
    struct Node data;
    puts("¿Cuantos valores quieres agregar a la pila?");
    fflush(stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d", &data.value);
        push(s, &error, data);
    }
    getTop(*s, &error);
    clear(s, &error);
    return error;
}