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
        *newCLL = NULL;
        *error = 0;
    }
    return newCLL;
}

/*
    @def Función para extraer del inicio
    @param cl Cola Circualr
    @param error Manejador de errores
*/
Data extractBeginCL(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("La lista esta vacia");
        *error = -1;
        return -1;
    } else {
        struct Node *aux = *cl;
        Data extract = (*cl)->value;

        if(aux->next==*cl){
            *cl = NULL;
            return extract;
        }

        while (aux->next!=*cl){
            aux = aux->next;
        }
        struct Node *aux2 = *cl;
        aux->next = aux2->next;
        *cl = (*cl)->next;
        aux = *cl;
        int i = 0;
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
Data extractEndCL(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("Lista Vacia");
        *error = -1;
        return -1;
    } else {
        Data extract;
        struct Node *aux = *cl;

        if(aux->next==*cl){
            extract = aux->value;
            *cl = NULL;
            return extract;
        }

        while(aux->next->next!=*cl){
            aux = aux->next;
        }
        struct Node *aux2 = aux->next;
        aux2->next = NULL;
        extract =  aux2->value;
        aux->next=*cl;
        *error = 0;
        return extract;
    }
}

/*
    @def Función para extraer de una posición
    @param cl Cola Circualr
    @param error Manejador de errores
    @param pos Posición a extraer
*/
Data extractNCL(CircularList *cl, int *error, int npos){
    if(npos==0){
        return extractBeginCL(cl, error);
    }
    if(*cl==NULL){
        perror("No puedes extraer:(");
        *error = -1;
        return -1;
    } else {
        Data extract;
        struct Node *aux = *cl;
        while(aux->next!=*cl){
            if(aux->pos==npos-1){
                extract = aux->next->value;
                struct Node *aux2 = aux->next;
                aux->next = aux2->next;
                aux = aux->next;
                while (aux->next!=*cl){
                    aux->pos=aux->pos-1;
                    aux = aux->next;
                }
                aux->pos = aux->pos - 1;
                *error = 0;
                return extract;
            }
            aux = aux->next;
        }
        perror("No se encontro la posición");
        *error = -1;
        return -1;
    }
}

/*
    @def Función para insertar al Inicio
    @param val Valor que vamos a insertar
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void insertBeginCL(Data val, CircularList *cl, int *error){
    struct Node *node = malloc(sizeof(struct Node));
    node->value = val;
    if(*cl==NULL){
        *cl = node;
        node->next = node;
        node->pos = 0;
        *error = 0;
    } else {
        struct Node *aux = *cl;
        int i=1;
        while(aux->next!=*cl){
            aux->pos=i;
            aux = aux->next;
            i++;
        }
        aux->pos = i;
        node->next = *cl;
        node->pos = 0;
        aux->next = node;
        *cl = node;
    }
    *error = 0;
}

/*
    @def Función para insertar al Final
    @param val Valor que vamos a insertar
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void insertEndCL(Data val, CircularList *cl, int *error){
    struct Node *node = malloc(sizeof(struct Node));
    node->value = val;
    if(*cl==NULL){
        *cl = node;
        node->next = node;
        node->pos = 0;
        *error = 0;
    } else {
        struct Node *aux = *cl;
        int prevPos;
        while(aux->next!=*cl){
            aux = aux->next;
        }
        prevPos = aux->pos;
        node->pos = prevPos+1;
        node->next = *cl;
        aux->next = node;
    }
    *error = 0;
}

/*
    @def Función para insertar en una posicion n
    @param val Valor que vamos a insertar
    @param cl Cola Circualr
    @param error Manejador de errores
    @param npos Posicion en la que vamos a insertar
*/
void insertNCL(Data val, CircularList *cl, int *error, int npos){
    struct Node *node = malloc(sizeof(struct Node));
    node->value = val;
    if(*cl==NULL && npos!=0){
        perror("No puedes hacer esta operacion");
        *error = -1;
    } else if(*cl==NULL && npos==0){
        insertBeginCL(val, cl, error);
    } else {
        struct Node *aux = *cl;
        while (aux->next!=*cl){
            if(aux->pos==npos-1){
                node->pos = npos;
                node->next = aux->next;
                aux->next = node;
                aux = aux->next->next;
                while(aux->next!=*cl){
                    aux->pos = aux->pos+1;
                    aux = aux->next;
                }
                aux->pos = aux->pos+1;
                *error = 0;
                break;
            }
            aux = aux->next;
        }
        *error = 0;
        if(npos==aux->pos+1){
            insertEndCL(val, cl, error);
        }
    }
}

/*
    @def Función para conocer si esta vacía
    @param cl Cola Circular
    @param error Manejador de errores
*/
bool isEmptyCL(CircularList cl, int *error){
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
        while(!isEmptyCL(*cl, error)){
            temp = extractBeginCL(cl, error);
            printf("Eliminado %d\n", temp);
        }
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
        printf("Valor: %d\tPosicion: %d\n", aux->value, aux->pos);
        *error = 0;
    }
}

/*
    @def Función para contar sus elementos de la lista
    @param cl Cola Circualr
    @param error Manejador de errores
*/
void countNodesCL(CircularList *cl, int *error){
    if(*cl==NULL){
        printf("Esta vacía\n");
        *error = -1;
    } else {
        struct Node *aux = *cl;
        int counter = 0;
        while(aux->next!=*cl){
            counter++;
            aux = aux->next;
        }
        counter++;
        printf("Existen %d nodos en la lista\n", counter);
        *error=0;
    }
}


int searchCList(CircularList *cl, int val, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        struct Node *aux = *cl;
        while(aux->next!=*cl){
            if(aux->value==val){
                return aux->pos;
            }
            aux = aux->next;
        }
        if(aux->value==val){
            return aux->pos;
        }
        return -1;
    }
}

void updateNodeCL(CircularList *cl, int *error, int npos, Data val){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        struct Node *aux = *cl;
        bool exists = false;
        while(aux->next!=*cl){
            if(aux->pos==npos){
                aux->value = val;
                *error = 0;
                exists = true;
                return;
            }
            aux = aux->next;
        }
        if(aux->pos==npos){
            aux->value = val;
            exists = true;
            *error = 0;
        }
        if(!exists){
            perror("No existe el nodo");
            *error = -1;
        }
    }
}

CircularList *copyCList(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        CircularList *newCL = malloc(sizeof(CircularList));
        struct Node *aux = *cl;
        while(aux->next!=*cl){
            insertEndCL(aux->value, newCL, error);
            aux = aux->next;
        }
        insertEndCL(aux->value, newCL, error);
        return newCL;
    }
}

void deleteCList(CircularList *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        clearCList(cl, error);
        free(cl);
        printf("Lista eliminada\n");
    }
}