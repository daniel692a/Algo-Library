#include "CLL.h"

/*
    @def Función para crear la cola circular
    @param error Manejador de errores
*/
CircularList *createCList(int *error){
    CircularList *newCLL = malloc(sizeof(CircularList));
    if(newCLL==NULL){
        perror("No se puede crear la lista");
        *error = -1;
    } else {
        newCLL = NULL;
        *error = 0;
    }
    return newCLL;
}

/*
    @def Función para extraer del inicio
    @param cl Cola Circualr
    @param error Manejador de errores
*/
Data extractStart(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("La lista esta vacia");
        *error = -1;
        return -1;
    } else {
        CircularList aux = *cl;
        Data extract;
        while(aux->next!=*cl){
            aux=aux->next;
        }
        extract = aux->value;
        if(aux==*cl){
            *cl = NULL;
            aux->next = NULL;
            free(aux);
        } else {
            aux->next=(*cl)->next;
            aux = *cl;
            *cl = (*cl)->next;
            aux = NULL;
        }
        aux=*cl;
        int i = 0;
        aux = aux->next;
        while (aux->next!=*cl){
            aux->pos=i;
            aux = aux->next;
            i++;
        }
        aux->pos = i;
        *error = 0;
        return extract;
    }
}

/*
    @def Función para extraer del final
    @param cl Cola Circualr
    @param error Manejador de errores
*/
Data extractEnd(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("Lista Vacia");
        *error = -1;
        return -1;
    } else {
        Data extract;
        CircularList aux = *cl;
        while(aux->next->next!=*cl){
            aux = aux->next;
        }
        CircularList aux2 = aux->next;
        aux2->next = NULL;
        extract =  aux2->value;
        aux->next=*cl;
        free(aux);
        free(aux2);
        *error = 0;
        return extract;
    }
}

/*
    @def Función para insertar al Inicio
    @param val Valor que vamos a insertar
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void insertStart(Data val, CircularList *cl, int *error){
    if(*cl==NULL){
        (*cl)->value = val;
        (*cl)->next = *cl;
        (*cl)->pos = 0;
        *error = 0;
    } else {
        CircularList aux = *cl;
        int i=1;
        while(aux->next!=*cl){
            aux->pos=i;
            aux = aux->next;
            i++;
        }
        CircularList *temp;
        (*temp)->value = val;
        (*temp)->next = *cl;
        (*temp)->pos = 0;
        aux->next=*temp;
        *cl = *temp;
    }
    *error = 0;
}

/*
    @def Función para insertar al Final
    @param val Valor que vamos a insertar
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void insertEnd(Data val, CircularList *cl, int *error){
    if(*cl==NULL){
        (*cl)->value = val;
        (*cl)->next = *cl;
        (*cl)->pos = 0;
        *error = 0;
    } else {
        CircularList aux = *cl;
        int prevPos;
        while(aux->next!=*cl){
            prevPos = aux->pos;
            aux = aux->next;
        }
        CircularList *temp;
        (*temp)->value = val;
        (*temp)->pos = prevPos+1;
        (*temp)->next = *cl;
        aux->next = *temp;
    }
    *error = 0;
}

/*
    @def Función para conocer si esta vacía
    @param cl Cola Circular
    @param error Manejador de errores
*/
bool isEmpty(CircularList cl, int *error){
    if(cl==NULL){
        return true;
    } else {
        return false;
    }
}

/*
    @def Función para borrar la lista
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void clearCList(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        Data temp;
        while(!isEmpty(*cl, error)){
            temp = extractStart(cl, error);
            printf("Eliminado %d\n", temp);
        }
        free(cl);
    }
}

/*
    @def Función para mostrar la lista
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void showCList(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        CircularList aux = *cl;
        while(aux->next!=*cl){
            printf("Valor: %d\tPosicion: %d\n", aux->value, aux->pos);
            aux = aux->next;
        }
        *error = 0;
    }
}

/*
    @def Función para contar sus elementos de la lista
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void countNodes(CircularList *cl, int *error){
    if(*cl==NULL){
        printf("Esta vacía\n");
        *error = -1;
    } else {
        CircularList aux = *cl;
        int counter = 0;
        while(aux->next!=*cl){
            counter++;
            aux = aux->next;
        }
        printf("Existen %d nodos en la lista", counter);
        *error=0;
    }
}