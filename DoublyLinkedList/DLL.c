#include "DLL.h"

Node* create_Node(Data valor, int* error){
    Node* nodo = (Node*)malloc(sizeof(Node));
    nodo->valor = valor;
    nodo->sig = nodo->ant = NULL;
    nodo->pos = 0;
    *error = 0;
    return nodo;
}

DoublyLL *create_doublyLL(int *error){
    DoublyLL* l =(DoublyLL*)malloc(sizeof(DoublyLL));
    if(l == NULL)
        *error = 1;
    *l = NULL;
    *error = 0;
    return l;
}

DoublyLL create_doubly2(int *error){
    DoublyLL l = (DoublyLL)malloc(sizeof(DoublyLL));
    if(l == NULL)
        *error = 1;
    l = NULL;
    *error = 0;
    return l;
}

void insertEndDoubly(DoublyLL* lista, Data dato, int* error){
    Node* nuevo = create_Node(dato, error);
    if(*lista == NULL){
        *lista = nuevo;
        (*lista)->sig = (*lista)->ant = NULL;
        (*lista)->pos = 0;
    }
    else{
        Node* aux = *lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = aux;
        nuevo->pos = aux->pos + 1;
    }
    *error = 0;
}

void insertStartDoubly(DoublyLL* lista, Data dato, int* error){
    Node* nuevo = create_Node(dato, error);
    if(*lista == NULL){
        *lista = nuevo;
        (*lista)->sig = (*lista)->ant = NULL;
        (*lista)->pos = 0;
    }
    else{
        Node* aux = *lista;
        aux->ant = nuevo;
        nuevo->ant = NULL;
        nuevo->sig = aux;
        nuevo->pos = 0;
        *lista = nuevo;
        while(aux->sig != NULL){
            aux->pos = aux->pos + 1;
            aux = aux->sig;
        }
        aux->pos = aux->pos + 1;
    }
    *error = 0;
}

void insertNDoubly(DoublyLL *l, Data valor, int pos, int *error){
    Node* nuevo = create_Node(valor, error);
    if(*l == NULL){
        *l = nuevo;
        (*l)->sig = (*l)->ant = NULL;
        (*l)->pos = 1;
    } else if(pos == 0) {
        insertStartDoubly(l, valor, error);
    } else if(pos == longitud(*l)) {
        insertEndDoubly(l, valor, error);
    } else {
        Node* aux = *l;
        while(aux->pos != pos){
            aux = aux->sig;
        }
        nuevo->sig = aux;
        nuevo->ant = aux->ant;
        nuevo->pos = pos;
        aux->ant->sig = nuevo;
        aux->ant = nuevo;
        while(aux->sig != NULL){
            aux->pos = aux->pos + 1;
            aux = aux->sig;
        }
        aux->pos = aux->pos + 1;
    }
    *error = 0;
}

void showDoublyLL(DoublyLL *l, int *error){
    if(*l == NULL){
        printf("Lista vacia\n");
        *error = 1;
    }
    else{
        Node* aux = *l;
        while(aux->sig != NULL){
            printf("%d , %d  ||  ", aux->valor, aux->pos);
            aux = aux->sig;
        }
        printf("%d , %d  ||  ", aux->valor, aux->pos);
        printf("\n---------------------\n");
        *error = 0;
    }
}

void extractBeginDoubly(DoublyLL *l, Data *valor, int *error){
    if(*l == NULL){
        *error = 1;
    }else{
        Node* aux = *l;
        *valor = aux->valor;
        *l = (*l)->sig;
        aux->sig = NULL;
        free(aux);
        if(*l != NULL){
            (*l)->ant = NULL;
            (*l)->pos = 0;
            aux = *l;
            while(aux->sig != NULL){
                aux = aux->sig;
                aux->pos = aux->pos - 1;
            }
            aux->pos = aux->pos - 1;
        }
    }
    *error = 0;
}

void extractEndDoubly(DoublyLL *l, Data *valor, int *error){
    if(*l == NULL){
        *error = 1;
    }else{
        Node* aux = *l;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        *valor = aux->valor;
        aux->ant->sig = NULL;
        aux->ant=NULL;
        free(aux);
    }
    *error = 0;
}

void extractNDoubly(DoublyLL *l, Data *valor, int pos, int *error){
    if(*l == NULL){
        *error = 1;
    } else if(pos == 0){
        extractBeginDoubly(l, valor, error);
    } else if(pos == longitud(*l)){
        extractEndDoubly(l, valor, error);
    } else {
        Node* aux = *l, *aux2;
        while(aux->pos != pos){
            aux = aux->sig;
        }
        *valor = aux->valor;
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        aux2 = aux->sig;
        aux->sig = aux->ant = NULL;
        free(aux);
        while(aux2->sig != NULL){
            aux2->pos = aux2->pos - 1;
            aux2 = aux2->sig;
        }
        aux2->pos = aux2->pos - 1;
    }
    *error = 0;
}

void clearDoublyLL(DoublyLL *l){
    Node* aux = *l;
    while(aux != NULL){
        *l = (*l)->sig;
        aux->sig = NULL;
        aux->ant = NULL;
        free(aux);
        aux = *l;
    }
}

int lengthDoublyLL(DoublyLL l){
    Node* aux = l;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

void copyDoublyLL(DoublyLL *l, DoublyLL *copia, int *error){
    Node* aux = *l;
    while(aux != NULL){
        insertEndDoubly(copia, aux->valor, error);
        aux = aux->sig;
    }
    *error = 0;
}

void sortDoublyLL(DoublyLL *arreglo, int tam, int *error){
    if(tam>1){
        int i,j,k;
        int mitad=tam/2;
        Node* temp = *arreglo;
        DoublyLL* arrIzq = create_doublyLL(error);
        DoublyLL* arrDer = create_doublyLL(error);
        for(i=0; i<mitad; i++){
            insertEndDoubly(arrIzq, temp->valor, error);
            temp = temp->sig;
        }
        for(j=0; j< (tam-mitad); j++){
            insertEndDoubly(arrDer, temp->valor, error);
            temp = temp->sig;
        }
        sortDoublyLL(arrIzq,mitad,error);
        sortDoublyLL(arrDer,tam-mitad,error);
        clearDoublyLL(arreglo);
        mergeDoublyLL(arrIzq,mitad, arrDer,tam-mitad,arreglo,error);
    }
}

void mergeDoublyLL(DoublyLL *arrIzq, int tamIzq, DoublyLL *arrDer, int tamDer, DoublyLL *arreglo, int *error){
    int i=0,j=0;
    Data *val;
    while(i<tamIzq && j<tamDer){
        if((*arrIzq)->valor < (*arrDer)->valor){
            insertEndDoubly(arreglo,(*arrIzq)->valor,error);
            extractBeginDoubly(arrIzq, val, error);
            i++;
        } else{
            insertEndDoubly(arreglo,(*arrDer)->valor,error);
            extractBeginDoubly(arrDer, val, error);
            j++;
        }
    }
    while(j<tamDer){
        insertEndDoubly(arreglo,(*arrDer)->valor,error);
        extractBeginDoubly(arrDer, val, error);
        j++;
    }
    while(i<tamIzq){
        insertEndDoubly(arreglo,(*arrIzq)->valor,error);
        extractBeginDoubly(arrIzq, val, error);
        i++;
    }
}

void reverseLinkedList(DoublyLL *lista, int *error){
    if(*lista==NULL){
        perror("no se puede aplicar esta operacion\n");
        return;
    }
    Node *aux = *lista;
    while(aux->sig!=NULL){
        aux = aux->sig;
    }
    Node *aux2 = *lista;
    int size = longitud(*lista);
    int l = 0, r=size-1;
    while (l<=r){
        int temp = aux->valor;
        aux->valor = aux2->valor;
        aux2->valor = temp;
        aux = aux->ant;
        aux2 = aux2->sig;
        l++;
        r--;
    }
}