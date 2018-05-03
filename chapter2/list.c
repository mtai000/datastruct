#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1


typedef int Elem;
typedef int Status;
typedef Elem *List;

Status InitList(List *L)
{
    *L = (List)malloc(sizeof(Elem));
    if(!(*L))
        return ERROR;
    return OK;
}

Status DestroyList(List *L)
{
    free(*L);
    *L = NULL;
    if(*L)
        return ERROR;
    return OK;
}

void main()
{
    List L;
    if(InitList(&L))
        printf("InitList success\n");
    else
        printf("InitList fail");
}
