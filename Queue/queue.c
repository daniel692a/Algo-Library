#include "queue.h"

Queue* createQueue(int *error){
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    if(newQueue==NULL){
        perror("No hay memoria para la Stack");
        *error = -2;
        return NULL;
    }
    newQueue->head=NULL;
    newQueue->tail=NULL;
    newQueue->size=0;
    *error=0;
    return newQueue;
}

void enqueue(Queue *q, int *error, struct Node newNode){
    struct Node *nodeUser = malloc(sizeof(struct Node));
    if(nodeUser==NULL){
        perror("No hay memoria para almacenar tu información");
        *error = -1;
        return;
    }
    nodeUser->value = newNode.value;
    nodeUser->next = NULL;
    if(isEmpty(*q, error)){
        q->head = nodeUser;
        q->tail = nodeUser;
    } else {
        q->tail->next = nodeUser;
        q->tail = q->tail->next;
    }
    *error = 0;
    q->size++;
}

Data dequeue(Queue *q, int *error){
    struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
    if(isEmpty(*q, error)){
        perror("No puedes realizar esta operacion");
        *error = -1;
        return -1;
    } else {
        aux->value = q->head->value;
        aux->next = NULL;
        if (q->size==1){
            q->head = NULL;
            q->tail = NULL;
            q->size--;
        } else {
            q->head = q->head->next;
            q->size--;
        }
        *error=0;
    }
    return aux->value;
}

bool isEmpty(Queue q, int *error){
    if (q.size == 0){
        *error = -3;
        return true;
    }
    else{
        *error = 0;
        return false;
    }
}

void clear(Queue *q, int *error){
    while(!isEmpty(*q, error)){
        Data retVal;
        retVal = dequeue(q, error);
        printf("Valor obtenido: %d", retVal);
        *error = 0;
    }
}
int getLen(struct Node* head){
    int len = 0;
    struct Node *temp = head;
    while (temp){
        len++;
        temp = temp->next;
    }
    return len;
}


// O(nlogn) -> Merge Sort
struct Node *getMid(struct Node *head, int *error){
    struct Node *midPrev = NULL;
    while (head && head->next){
        midPrev = (midPrev == NULL) ? head : midPrev->next;
        head = head->next->next;
    }
    struct Node *mid = midPrev->next;
    midPrev->next = NULL;
    return mid;
}

struct Node* mergeSortQueue(struct Node *head, int *error){
    if (!head || !head->next)
        return head;
    struct Node *mid = getMid(head, error);
    struct Node *left = mergeSortQueue(head, error);
    struct Node *right = mergeSortQueue(mid, error);
    return merge(left, right, error);
}

struct Node *merge(struct Node *list1, struct Node *list2, int *error){
    struct Node dummyHead;
    struct Node *ptr = &dummyHead;
    while (list1 && list2){
        if (list1->value < list2->value){
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if (list1)
        ptr->next = list1;
    else
        ptr->next = list2;
    return dummyHead.next;
}

void iterateQueue(Queue *q, int *error){
    struct Node *temp = q->head;
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    *error = 0;
}

void iterateNodes(struct Node *h, int *error){
    struct Node *temp = h;
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    *error = 0;
}