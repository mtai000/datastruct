#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int Status;
typedef int Elem;

typedef struct{
    Elem *elem;
    int length;
    int listsize;
}SqList;

Status InitList(SqList *L)
{
    L->elem = (Elem *) malloc (LIST_INIT_SIZE * sizeof(Elem)); 
    if(!L->elem)
        return ERROR;
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList *L)
{
    free(L->elem);
    L->elem = NULL;
    if(L->elem)
        return ERROR;
    return OK;
}
void main()
{
    SqList L;
    if(InitList(&L))
        printf("InitList success\n");
    else
        printf("InitList fail\n");
    if(DestroyList(&L))
        printf("Destroy List success\n");
    else
        printf("Destroy List fail\n");

}
