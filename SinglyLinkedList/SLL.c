#include "SLL.h"


/*
    @author Daniel Armas Ramírez
    @param *error Nos ayudará a manejar errores internos
*/
SinglyList* createLL(int *error){
    SinglyList *newLL = malloc(sizeof(SinglyList));

    if(newLL==NULL){
        perror("No existe memoria para crear la lista\n");
        *error = -1;
        return NULL;
    }
    *newLL = NULL;
    return newLL;
}


/*
    @author Daniel Armas Ramírez
    @param *l Lista a la cual insertaremos un nuevo nodo al final
    @param val Valor que añadiremos a la Lista
    @param *error Nos ayudará a manejar errores internos
*/
void insertEnd(SinglyList *l, Data val, int *error){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    if(*l==NULL){
        new->value = val;
        new->next = NULL;
        new->pos = 0;
        *l = new;
    } else {
        SinglyList aux = *l;
        while(aux->next!=NULL){
            aux = aux->next;
        }
        new->value = val;
        new->pos = (aux->pos)+1;
        new->next = NULL;
        aux->next = new;
        *error = 0;
    }
}


/*
    @author Daniel Armas Ramírez
    @param *l Lista a la cual insertaremos un nuevo nodo al inicio
    @param val Valor que añadiremos a la Lista
    @param *error Nos ayudará a manejar errores internos
*/
void insertStart(SinglyList *l, Data val, int *error){
    struct Node *new = malloc(sizeof(struct Node));

    new->value = val;
    new->next=NULL;
    new->pos = 0;

    if(*l == NULL){
        *l = new;
    } else {
        SinglyList aux = *l;
        *l = new;
        (*l)->next = aux;
        aux = *l;
        aux = aux->next;
        while (aux->next != NULL){
            aux->pos = (aux->pos)+1;
            aux = aux->next;
        }
    }
    *error = 0;
}

/*
    @author Daniel Armas Ramírez
    @param *l Lista a la cual insertaremos un nuevo nodo en una posicion específica
    @param val Valor que añadiremos a la Lista
    @param *error Nos ayudará a manejar errores internos
    @param position Posicion en la que queremos insertar el valor
*/
void insertNposition(SinglyList *l, Data val, int *error, int position){
    struct Node *new = malloc(sizeof(SinglyList));

    SinglyList aux = *l;
    bool exists = false;

    new->value = val;
    new->next = NULL;
    new->pos = position;

    while (aux->next != NULL){
        if (aux->pos == position - 1){
            exists = true;
            new->next = aux->next;
            aux->next = new;
            aux = aux->next;
            while (aux->next != NULL){
                aux->pos++;
                aux = aux->next;
            }
            *error = 0;
            return;
        }
        aux = aux->next;
        exists = false;
    }
    if(!exists){
        perror("La posicion no existe\n");
        *error = -1;
    }
}

/*
    @author Daniel Armas Ramírez
    @param *l Lista a la cual vamos a eliminar un nodo al inicio
    @param *error Nos ayudará a manejar errores internos
*/
void removeStart(SinglyList *l, int *error){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else {
        Data extract = (*l)->value;
        printf("%d ", extract);
        SinglyList aux = *l;
        *l=(*l)->next;
        aux->next=NULL;
        free(aux);
        aux = *l;
        while (aux->next != NULL){
            aux->pos--;
            aux = aux->next;
        }
        *error = 0;
    }
}


/*
    @author Daniel Armas Ramírez
    @param *l Lista a la cual vamos a eliminar un nodo al final
    @param *error Nos ayudará a manejar errores internos
*/
void removeEnd(SinglyList *l, int *error){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else {
        SinglyList aux = *l;
        while (aux->next->next != NULL){
            aux = aux->next;
        }
        Data extract = aux->next->value;
        printf("%d ", extract);
        free(aux);
        aux->next=NULL;
        *error = 0;
    }
}


/*
    @author Daniel Armas Ramírez
    @param *l Lista a la cual vamos a eliminar un nodo al final
    @param *error Nos ayudará a manejar errores internos
*/
void removeN(SinglyList *l, int *error, int npos){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else if(npos == 0){
        removeStart(l, error);
    } else {
        SinglyList aux = *l;
        bool exists = false;
        while (aux->next != NULL){
            if (aux->pos == npos - 1){
                exists = true;
                SinglyList aux2 = aux->next;
                Data extract = aux2->value;
                printf("%d ", extract);
                aux->next = aux2->next;
                aux2->next = NULL;
                free(aux2);
                aux=aux->next;
                while (aux->next != NULL){
                    aux->pos--;
                    aux = aux->next;
                }
                *error = 0;
                return;
            }
            aux = aux->next;
            exists = false;
        }
        *error = 0;
        if (!exists){
            perror("La posicion no existe\n");
            *error = -1;
        }
    }
}


void printList(SinglyList current){
    if(current == NULL){
        return;
    }
    printf("%d %d\n", current->value, current->pos);
    printList(current->next);
}
/*
    @author Daniel Armas Ramírez
    @param *l Lista que queremos mostrar
    @param *error Nos ayudará a manejar errores internos
*/
void showList(SinglyList *l, int *error){
    SinglyList aux = *l;
    if(l==NULL){
        perror("NO hay información\n");
        *error = -1;
    } else {
        printList(aux);
        *error = 0;
    }
}



int searchList(SinglyList current, int val){
    if(current == NULL){
        return -1;
    }
    if(current->value==val) {
        return current->pos;
    }
    searchList(current->next, val);
}
/*
    @author Daniel Armas Ramírez
    @param *l Lista en la que vamos a buscar
    @param *error Nos ayudará a manejar errores internos
*/
void searchItem(SinglyList *l, int *error, int value){
    SinglyList aux = *l;
    if(l==NULL){
        perror("NO hay información\n");
        *error = -1;
    } else {
        int result = searchList(aux, value);
        if(result>=0){
            printf("Valor encontrado en la posicion: %d\n", result);
            *error = 0;
        } else {
            perror("No existe en la lista");
            *error = -2;
        }
    }
}


/*
    @author Daniel Armas Ramírez
    @param *l Lista de la que vamos a copiar
    @param *error Nos ayudará a manejar errores internos
*/
SinglyList *copyList(SinglyList *l, int *error){
    SinglyList *copy = malloc(sizeof(SinglyList));
    if(copy==NULL){
        perror("No hay más memoria\n");
        *error = -3;
        return NULL;
    } else {
        SinglyList aux = *l;
        while(aux->next!=NULL){
            (*copy)->value = aux->value;
            (*copy)->pos = aux->pos;
            (*copy)->next = aux->next;
            aux = aux->next;
        }
        *error = 0;
        return copy;
    }
}
