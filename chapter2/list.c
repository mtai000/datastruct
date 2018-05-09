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

Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    return L.length == 0? TRUE : FALSE;
}

int ListLength(SqList L)
{
    return L.length;
}

Status GetElem(SqList L , int i ,int *e)
{
    if(i < 1 || i > ListLength(L))
    {
        printf("Get invalid value : i = %d\n", i);
        return ERROR;
    }
    *e = L.elem[i-1];
    return OK;
}

Status ListInsert(SqList *L , int i, int e)
{
    if(i < 1 || i > ListLength(*L)+1)
    {
        printf("Insert invalid value : i = %d\n", i);
        return ERROR;
    }
    if(ListLength(*L) >= L->listsize)
    {
        int *newbase = (Elem*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof (Elem));
        if(!newbase) return ERROR;
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    int *q = &(L->elem[i - 1]);
    for( int *p = &(L->elem[L->length - 1]); p >= q; --p) *(p+1) = *p;
    *q = e;
    ++ (L->length);
      
    return OK;
}
Status ListDelete(SqList *L , int i, int *e)
{
    if(i < 1 || i > ListLength(*L)+1)
    {
        printf("Insert invalid value : i = %d\n", i);
        return ERROR;
    }

    int *p = &(L->elem[i - 1]);
    *e = *p;
    int *q;
    q = L->elem + (L->length -1)*sizeof(Elem);
    for( p+= sizeof(Elem) ; p <= q; p += sizeof(Elem)) 
        *p = *(p+sizeof(Elem));
    
    -- (L->length);
      
    return OK;
}


int LocateElem(SqList L,int e, Status (*compare)(Elem ,Elem))
{
    int i;
    Elem *p;
    i = 1;
    p=L.elem;

    while (i <= L.length && !(*compare)(*p++,e) )
    {
        ++i;
    }
    if( i <= L.length) return i;
    else return ERROR;
}

Status PriorElem(SqList L,Elem cur_e, Elem* pre_e)
{
    int i = 0;
   
    while( i < L.length)
    {
        if( L.elem[i] == cur_e && i != 0)
        {     
            *pre_e=L.elem[i-1];
            return OK;
        }
        i++;
    }

    return  ERROR;
}

Status NextElem(SqList L,Elem cur_e, Elem* next_e)
{
    int i = 0;
   
    while( i < L.length)
    {
        if( L.elem[i] == cur_e && i != L.length -1)
        {     
            *next_e=L.elem[i+1];
            return OK;
        }
        i++;
    }

    return  ERROR;
}



int main(void)
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
    if(ClearList(&L))
        printf("Clear List success\n");
    else
        printf("Clear List fail\n");
    if(ListEmpty(L))
        printf("List is Empty\n");
    else
        printf("List is not Empty\n");
    InitList(&L);
    ListInsert(&L,1,3);
    ListInsert(&L,2,1);
    ListInsert(&L,1,6);
    int e = 0;
    
    GetElem(L,2,&e);
    printf("%d\n",e);

    PriorElem(L,3,&e);
    printf("%d\n",e);
   
    NextElem(L,3,&e);
    printf("%d\n",e);

    ListDelete(&L,1,&e);
    printf("%d\n",e);
    
    DestroyList(&L); 
    return 0;
}

