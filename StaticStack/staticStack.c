#include "staticStack.h"

void createStackS(int *error, StackS *s){
    (*s).top = -1;
    *error = 0;
}

void getTopS(StackS s, int *error){
    printf("El valor de la cima es %d y contiene el valor: %d", s.top, s.elements[s.top]);
}

void pushS(StackS *s, int *error, Node data){
    if (!isFullS(*s, error)){
        (*s).top++;
        s->elements[s->top] = data;
        *error = 0;
    } else {
        puts("Pila llena");
        *error = -1;
    }
}

void popS(StackS *s, int *error, Node *remove){
    if (!isEmptyS(*s, error)){
        *remove = s->elements[s->top];
        s->top--;
        *error = 0;
    } else {
        puts("Pila vacia, no hay elementos que se puedan extraer");
        *error = -2;
    }
}

bool isEmptyS(StackS s, int *error){
    if (s.top == -1) {
        *error = -2;
        return true;
    } else {
        *error = 0;
        return false;
    }
}

bool isFullS(StackS s, int *error){
    if (s.top == (SZ - 1)){
        *error = -1;
        return true;
    } else {
        *error = 0;
        return false;
    }
}

void clearS(StackS *s, int *error) {
    Node aux;
    puts("Start clear");
    while (!isEmptyS(*s, error)){
        popS(s, error, &aux);
        printf("El valor extraido es: %d\n", aux.value);
    }
    puts("Finish clear");
}