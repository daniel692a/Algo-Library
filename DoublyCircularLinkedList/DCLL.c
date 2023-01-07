#include "DCLL.h"

Node* createNode(Data val, int *error){
    Node* nodo = (Node*)malloc(sizeof(Node));
    nodo->value = val;
    nodo->next = nodo->prev = NULL;
    nodo->pos = 0;
    *error = 0;
    return nodo;
}

DCLL* createDCLL(int *error){
    DCLL *l =(DCLL*)malloc(sizeof(DCLL));
    if(l == NULL){
        *error = -1;
        perror("No hay memoria");
    } else {
        *l = NULL;
        *error = 0;
    }
    return l;
}

void insertEndDCLL(DCLL *l, Data val, int *error){
    Node* new = createNode(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->next = (*l)->prev = *l;
        (*l)->pos = 0;
    } else {
        Node* aux = *l;
        new->next = *l;
        new->pos = (*l)->prev->pos+1;
        new->prev = (*l)->prev;
        (*l)->prev->next = new;
        (*l)->prev = new;
    }
    *error = 0;
}

void insertStartDCLL(DCLL *l, Data val, int *error){
    Node *new = createNode(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->next = (*l)->prev = *l;
        (*l)->pos = 0;
    } else {
        new->next = *l;
        new->pos = 0;
        (*l)->prev->next = new;
        new->prev = (*l)->prev;
        (*l)->prev = new;
        *l = new;
        int i = 1;
        Node *aux = (*l)->next;
        while (aux!=*l){
            aux->pos=i;
            i++;
        }
    }
    *error = 0;
}

void insertNDCLL(DCLL *l, Data val, int pos, int *error){
    Node* new = createNode(val, error);
    if(*l == NULL && pos>0){
        perror("No existe la posicion\n");
        *error = -1;
        return;
    } else if(pos == 0) {
        insertStartDCLL(l, val, error);
    } else if(pos == lengthDCLL(*l)-1) {
        insertEndDCLL(l, val, error);
    } else {
        Node* aux = *l;
        while(aux->pos != pos){
            aux = aux->next;
        }
        new->next = aux;
        new->prev = aux->prev;
        new->pos = pos;
        aux->prev->next = new;
        aux->prev = new;
        while(aux->next != NULL){
            aux->pos = aux->pos + 1;
            aux = aux->next;
        }
        aux->pos = aux->pos + 1;
    }
    *error = 0;
}

void showDCLL(DCLL *l, int *error){
    if(*l == NULL){
        printf("Lista vacia\n");
        *error = -1;
    } else {
        Node* aux = *l;
        while(aux->next != *l){
            printf("%d , %d\n", aux->value, aux->pos);
            aux = aux->next;
        }
        printf("%d , %d  ||  ", aux->value, aux->pos);
        printf("\n---------------------\n");
        *error = 0;
    }
}

void extractBeginDCLL(DCLL *l, Data *val, int *error){
    if(*l == NULL){
        perror("No se puede realizar esta operacion\n");
        *error = -1;
    } else {
        Node* aux = *l;
        *val = aux->value;
        (*l)->prev->next = (*l)->next;
        (*l)->next->prev = (*l)->prev;
        aux->next = NULL;
        aux->prev = NULL;
        free(aux);
        *error = 0;
    }
}

void extractEndDCLL(DCLL *l, Data *val, int *error){
    if(*l == NULL){
        perror("No se puede realizar esta operacion\n");
        *error = -1;
    } else {
        Node* aux = (*l)->prev;
        *val = aux->value;
        aux->prev->next = *l;
        (*l)->prev = aux->prev;
        aux->next = NULL;
        aux->prev = NULL;
        free(aux);
        *error = 0;
    }
}

void extractNDCLL(DCLL *l, Data *val, int pos, int *error) {
    if(*l == NULL){
        perror("No se puede realizar esta operacion\n");
        *error = -1;
    } else if(pos == 0){
        extractBeginDCLL(l, val, error);
    } else if(pos == lengthDCLL(*l)-1){
        extractEndDCLL(l, val, error);
    } else {
        Node* aux;
        Node* aux2 = (*l)->next;
        while(aux2->pos != 0){
            if(aux2->pos == pos){
                aux = aux2;
                aux2 = aux2->next;
                while (aux2->pos != 0){
                    aux2->pos = aux2->pos - 1;
                    aux2 = aux2->next;
                }
                break;
            }
            aux2 = aux2->next;
        }
        *val = aux->value;
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        free(aux);
        free(aux2);
        *error = 0;
    }
}

void clearDCLL(DCLL *l){
    Node* aux = *l;
    while(aux != NULL){
        *l = (*l)->next;
        aux->next = NULL;
        aux->prev = NULL;
        free(aux);
        aux = *l;
    }
}

int lengthDCLL(DCLL l){
    return l->prev->pos + 1;
}

void copyDCLL(DCLL *l, DCLL *copyL, int *error){
    if(*l == NULL){
        perror("No se puede realizar esta operacion\n");
        *error = -1;
    } else {
        Node* aux = *l;
        while(aux->next != *l){
            insertEndDCLL(copyL, aux->value, error);
            aux = aux->next;
        }
        free(aux);
        *error = 0;
    }
}

void sortDCLL(DCLL *arreglo, int tam, int *error){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;
        Node* temp = *arreglo;
        DCLL* arrIzq = createDCLL(error);
        DCLL* arrDer = createDCLL(error);
        for(i=0; i<mitad; i++){
            insertEndDCLL(arrIzq, temp->value, error);
            temp = temp->next;
        }
        for(j=0; j< (tam-mitad); j++){
            insertEndDCLL(arrDer, temp->value, error);
            temp = temp->next;
        }
        sortDCLL(arrIzq,mitad,error);
        sortDCLL(arrDer,tam-mitad,error);
        clearDCLL(arreglo);
        mergeDCLL(arrIzq,mitad, arrDer,tam-mitad,arreglo,error);
    }
}

void mergeDCLL(DCLL *arrIzq, int tamIzq, DCLL *arrDer, int tamDer, DCLL *arreglo, int *error){
    int i=0, j=0;
    Data *val;
    while(i<tamIzq && j<tamDer){
        if((*arrIzq)->value < (*arrDer)->value){
            insertEndDCLL(arreglo,(*arrIzq)->value,error);
            extractBeginDCLL(arrIzq, val, error);
            i++;
        } else{
            insertEndDCLL(arreglo,(*arrDer)->value,error);
            extractBeginDCLL(arrDer, val, error);
            j++;
        }
    }
    while(j<tamDer){
        insertEndDCLL(arreglo,(*arrDer)->value, error);
        extractBeginDCLL(arrDer, val, error);
        j++;
    }
    while(i<tamIzq){
        insertEndDCLL(arreglo,(*arrIzq)->value,error);
        extractBeginDCLL(arrIzq, val, error);
        i++;
    }
}