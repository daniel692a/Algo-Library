#include "CLL.h"

List* createList(int *error){
    List *newCLL = malloc(sizeof(List));
    if(newCLL==NULL){
        perror("No se puede crear la lista");
        *error = -1;
    } else {
        (*newCLL)->val = NULL;
        (*newCLL)->next = *newCLL;
        (*newCLL)->pos = 0;
        *error = 0;
    }
}

Data extractStart(List *l, int *error){
    if(*l==NULL){
        perror("La lista esta vacia");
        *error = -1;
        return -1;
    } else {
        List aux = *l;
        Data extract;
        while(aux->next!=*l){
            aux=aux->next;
        }
        extract = aux->val;
        if(aux==*l){
            *l = NULL;
            aux->next=NULL;
            free(aux);
        } else {
            aux->next=(*l)->next;
            *l = (*l)->next;
        }
        aux=*l;
        int i =0;
        while (aux->next!=*l){
            aux->pos=i;
            aux = aux->next;
            i++;
        }
        aux->pos = i;
        *error = 0;
        return extract;
    }
}

Data extractEnd(List *l, int *error){
    if(*l==NULL){
        perror("Lista Vacia");
        *error = -1;
        return -1;
    } else {
        Data extract;
        List aux = *l;
        while(aux->next->next->pos!=0){
            aux = aux->next;
        }
        List aux2 = aux;
        aux2 = aux->next;
        aux2->next = NULL;
        extract =  aux2->val;
        aux->next=*l;
        free(aux);
        free(aux2);
        *error = 0;
        return extract;
    }
}

void insertStart(Data val, List *l, int *error){
    if(*l==NULL){
        (*l)->val = val;
        (*l)->next = *l;
        (*l)->pos = 0;
        *error = 0;
    } else {
        List aux = *l;
        int i=1;
        while(aux->next->pos!=0){
            aux->pos=i;
            aux = aux->next;
            i++;
        }
        List *temp;
        (*temp)->val = val;
        (*temp)->next = *l;
        (*temp)->pos = 0;
        aux->next=*temp;
        *l = *temp;
    }
    *error = 0;
}

void insertEnd(Data val, List *l, int *error){
    if(*l==NULL){
        (*l)->val = val;
        (*l)->next = *l;
        (*l)->pos = 0;
        *error = 0;
    } else {
        List aux = *l;
        int prevPos;
        while(aux->next->pos!=0){
            prevPos = aux->pos;
            aux = aux->next;
        }
        List *temp;
        (*temp)->val = val;
        (*temp)->pos = prevPos+1;
        (*temp)->next = *l;
        aux->next = *temp;
    }
    *error = 0;
}