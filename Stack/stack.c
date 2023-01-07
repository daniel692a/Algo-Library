#include "stack.h"

Stack *createStack(int *error){
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    if (newStack == NULL){
        perror("No hay memoria para la Stack");
        *error = -2;
        return NULL;
    }
    newStack->top = NULL;
    newStack->size = 0;
    *error = 0;
    return newStack;
}

void getTop(Stack s, int *error){
    if (!isEmpty(s, error) && *error == 0){
        printf("Valor en la cima: %d\n", s.top->value);
    }
    *error = 0;
}


void push(Stack *s, int *error, struct Node newValue){
    struct Node *nodeUser= (struct Node *)malloc(sizeof(struct Node));
    if (nodeUser == NULL){
        perror("No hay memoria para almacenar tu información");
        *error = -1;
    }
    nodeUser->value = newValue.value;
    nodeUser->below = s->top;
    s->top = nodeUser;
    s->size=s->size+1;
    *error = 0;
}

Value pop(Stack *s, int *error){
    if (!isEmpty(*s, error)){
        struct Node *aux = s->top;
        Value answer = aux->value;
        s->top = aux->below;
        aux->below = NULL;
        s->size=s->size-1;
        free(aux);
        *error = 0;
        return answer;
    } else {
        *error = -3;
        perror("No puedes realizar esta operacion");
    }
    return -1;
}

bool isEmpty(Stack s, int *error){
    if (s.top == NULL){
        *error = -3;
        return true;
    } else {
        *error = 0;
        return false;
    }
}

void clearStack(Stack *s, int *error){
    while (!isEmpty(*s, error)){
        Value extract = pop(s, error);
        printf("Valor extraido: %d\n", extract);
        *error = 0;
    }
}

void deleteStack(Stack *s, int *error){
    if (isEmpty(*s, error)){
        puts("Destruyendo Stack");
        free(s);
    } else {
        puts("No se puede destruir debido a que contiene información");
    }
}

void showStack(Stack s, int *error){
    if (!isEmpty(s, error)){
        struct Node *aux = s.top;
        while (aux != NULL){
            printf("%d ", aux->value);
            aux = aux->below;
        }
        printf("\n");
    } else {
        perror("No se puede mostrar debido a que la Stack está vacía");
    }
}