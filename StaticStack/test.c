#include "staticStack.h"

int main(int argc, char **argv){
    int error;
    StackS s;
    createStackS(&error, &s);
    Node userData;
    while (!isFullS(s, &error)){
        puts("ingresa un valor");
        fflush(stdin);
        scanf("%d", &userData.value);
        pushS(&s, &error, userData);
    }
    popS(&s, &error, &userData);
    printf("Ultimo elemento ingresado en la pila: %d", userData.value);
    clearS(&s, &error);
    return 0;
}