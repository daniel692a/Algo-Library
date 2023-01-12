#include "DCLL.h"

Node *createNode(Data val, int *error){
    Node* new = (Node*)malloc(sizeof(Node));
    if(new == NULL){
        perror("Error al crear el nodo");
        *error = -1;
    }else{
        new->value = val;
        new->next = NULL;
        new->prev = NULL;
        *error = 0;
    }
    return new;
}

DCLL* createDCLL(int* error){
    DCLL* l = (DCLL*)malloc(sizeof(DCLL));
    if(l == NULL){
        perror("Error al crear la lista");
        *error = -1;
    }else{
        *l = NULL;
        *error = 0;
    }
    return l;
}

void insertEndDCLL(DCLL *l, Data val, int *error){
    Node* new = createNode(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->next = (*l)->prev = new;
        (*l)->pos = 0;
    } else {
        Node* aux = *l;
        (*l)->prev->next = new;
        new->prev = (*l)->prev;
        (*l)->prev = new;
        new->next = *l;
        new->pos = aux->pos + 1;
    }
    *error = 0;
}

void insertBeginDCLL(DCLL* l, Data val, int* error){
    Node* new = createNode(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->next = (*l)->prev = new;
        (*l)->pos = 0;
    }
    else{
        (*l)->prev->next = new;
        new->next = *l;
        new->prev = (*l)->prev;
        (*l)->prev = new;
        *l = new;
        Node* aux = *l;
        aux = *l;
        int i = 0;
        while(aux->next != *l){
            aux->pos = i;
            aux = aux->next;
            i++;
        }
        aux->pos = i;
    }
    *error = 0;
}

void insertNDCLL(DCLL *l, Data val, int pos, int *error){
    Node* new = createNode(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->next = (*l)->prev = new;
        (*l)->pos = 0;
    } else {
        Node* aux = *l;
        while(aux->pos != pos){
            aux = aux->next;
        }
        aux->prev->next = new;
        new->prev = aux->prev;
        aux->prev = new;
        new->next = aux;
        Node* aux2 = *l;
        int i = 0;
        while(aux2->next != *l){
            aux2->pos = i;
            aux2 = aux2->next;
            i++;
        }
        aux2->pos = i;
    }
    *error = 0;
}

Data deleteEndDCLL(DCLL *l, int *error){
    Data extract;
    if(*l == NULL){
        perror("Error al eliminar el nodo");
        *error = -1;
        return -1;
    } else {
        Node* aux = (*l)->prev;
        extract =(*l)->prev->value;
        if(aux != (*l)->next){
            (*l)->prev->prev->next = *l;
            (*l)->prev = (*l)->prev->prev;
            free(aux);
        }else{
            aux->prev = aux->next = NULL;
            *l = NULL;
            free(aux);
        }
        *error = 0;
        return extract;
    }
}

Data deleteBeginDCLL(DCLL *l, int *error){
    Data extract;
    if(*l == NULL){
        perror("Error al eliminar el nodo");
        *error = -1;
        return -1;
    } else {
        Node* aux = *l;
        extract =(*l)->value;
        if(aux != (*l)->next){
            (*l)->prev->next = (*l)->next;
            (*l)->next->prev = (*l)->prev;
            *l = (*l)->next;
            free(aux);
            Node* aux2 = *l;
            int i = 0;
            while(aux2->next != *l){
                aux2->pos = i;
                aux2 = aux2->next;
                i++;
            }
            aux2->pos = i;
        } else {
            aux->prev = aux->next = NULL;
            *l = NULL;
            free(aux);
        }
        *error = 0;
        return extract;
    }
}

Data deleteNDCLL(DCLL *l, int pos, int *error){
    Data extract;
    if(*l == NULL){
        perror("Error al eliminar el nodo");
        *error = -1;
        return -1;
    } else {
        Node* aux = *l;
        while(aux->pos != pos){
            aux = aux->next;
        }
        extract = aux->value;
        if(aux != (*l)->next){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            Node* aux2 = *l;
            int i = 0;
            while(aux2->next != *l){
                aux2->pos = i;
                aux2 = aux2->next;
                i++;
            }
            aux2->pos = i;
        } else {
            aux->prev = aux->next = NULL;
            *l = NULL;
            free(aux);
        }
        *error = 0;
        return extract;
    }
}

void showDCLL(DCLL l){
    if(l == NULL){
        printf("La lista esta vacia");
    } else {
        Node* aux = l;
        while(aux->next != l){
            printf("%d %d ||\t", aux->value, aux->pos);
            aux = aux->next;
        }
        printf("%d %d ||\n", aux->value, aux->pos);
    }
}

int lengthDCLL(DCLL l){
    if(l == NULL){
        return 0;
    } else {
        return l->prev->pos + 1;
    }
}

void clearDCLL(DCLL *l, int *error){
    if(*l == NULL){
        perror("La lista esta vacia");
    } else {
        while(*l != NULL){
            printf("Eliminando %d\n", deleteBeginDCLL(l, error));
        }
        *error = 0;
    }
}

DCLL *copyDCLL(DCLL *l, int *error){
    DCLL *copy = createDCLL(error);
    if(*l == NULL){
        perror("La lista esta vacia");
        *error = -1;
    } else {
        Node* aux = *l;
        while(aux->next != *l){
            insertEndDCLL(copy, aux->value, error);
            aux = aux->next;
        }
        insertEndDCLL(copy, aux->value, error);
        *error = 0;
    }
    return copy;
}


int searchDCLL(DCLL *l, Data val, int *error){
    if(*l == NULL){
        perror("La lista esta vacia");
    } else {
        Node* aux = *l;
        while(aux->next != *l){
            if(aux->value == val){
                *error = 0;
                return aux->pos;
            }
            aux = aux->next;
        }
        if(aux->value == val){
            *error = 0;
            return aux->pos;
        }
    }
    *error = -1;
    return -1;
}

void updateNodeDCLL(DCLL *l, Data val, int pos, int *error){
    if(*l == NULL){
        perror("La lista esta vacia");
        *error = -1;
    } else {
        Node* aux = *l;
        while(aux->pos != pos){
            aux = aux->next;
        }
        aux->value = val;
        *error = 0;
    }
}

void deleteDCLL(DCLL *l, int *error){
    if(*l == NULL){
        perror("La lista esta vacia");
        *error = -1;
    } else {
        clearDCLL(l, error);
        free(*l);
        *error = 0;
    }
}