#include "SLL.h"

int main(){
    int error=0;
    SinglyList *myLL = createLL(&error);

    insertEnd(myLL, 5, &error);
    insertEnd(myLL, 10, &error);
    insertEnd(myLL, 189, &error);
    insertStart(myLL, 4, &error);
    showList(myLL, &error);

    printf("\n");
    insertEnd(myLL, 7, &error);
    showList(myLL, &error);
    printf("\n");

    insertNposition(myLL, 0, &error, 1);
    showList(myLL, &error);
    printf("\n");

    removeStart(myLL, &error);
    showList(myLL, &error);
    printf("\n");

    removeEnd(myLL, &error);
    showList(myLL, &error);
    printf("\n");

    removeN(myLL, &error, 2);
    showList(myLL, &error);
    printf("\n");

    searchItem(myLL, &error, 180);

    SinglyList *copyLL = copyList(myLL, &error);
    showList(copyLL, &error);

    return 0;
}