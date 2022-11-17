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
    s->size++;
    *error = 0;
}

int pop(Stack *s, int *error, struct Node *remove){
    if (!isEmpty(*s, error)){
        struct Node *aux = s->top;
        remove->value = aux->value;
        s->top = aux->below;
        aux->below = NULL;
        s->size--;
        free(aux);
        *error = 0;
        return aux->value;
    } else {
        *error = -3;
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

void clear(Stack *s, int *error){
    while (!isEmpty(*s, error)){
        struct Node remove;
        pop(s, error, &remove);
        printf("Valor extraido: %d\n", remove.value);
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