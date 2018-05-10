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

typedef struct LNode{
    Elem data;
    struct LNode *next;
}LNode , *LinkList;

void CreateList_L(LinkList *L, int n)
{
    *L = (LinkList) malloc (sizeof (LNode));
    (*L)->next = NULL;
    for(int i = n ;i>0 ; --i)
    {
        LNode *p = (LinkList) malloc (sizeof (LNode));
        printf("Input %d value:" , i);
        scanf("%d",&p->data);
        
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateList(LinkList *L ,int n)
{
    *L =(LinkList) malloc (sizeof (LNode));
    LinkList t = (*L);
    for(int i = n ; i > 0 ; --i)
    {
        LNode *p = (LinkList) malloc (sizeof(LNode));
        printf("Input %d value", n - i+1);
        scanf("%d",&p->data);

        t->next = p;
        t = p;
    }
}

Status GetElem_L(LinkList *L,int i ,Elem *e)
{
    LNode *p = (*L)->next;
    int j =1;
    while(p && j<i)
    {
        p = p->next;
        ++j;
        
    }
    if(!p || j>i) return ERROR;
    *e = p->data;
    return OK;
}

int main(void)
{
    LinkList L;
    CreateList_L(&L,5);
    int e;
    GetElem_L(&L,4,&e);
    printf("e value is : %d\n",e);
    //if(InitList(&L))
    //    printf("InitList success\n");
    //else
    //    printf("InitList fail\n");
    //if(DestroyList(&L))
    //    printf("Destroy List success\n");
    //else
    //    printf("Destroy List fail\n");
    //if(ClearList(&L))
    //    printf("Clear List success\n");
    //else
    //    printf("Clear List fail\n");
    //if(ListEmpty(L))
    //    printf("List is Empty\n");
    //else
    //    printf("List is not Empty\n");
    //InitList(&L);
    //ListInsert(&L,1,3);
    //ListInsert(&L,2,1);
    //ListInsert(&L,1,6);
    //int e = 0;
    
    //GetElem(L,2,&e);
    //printf("%d\n",e);

    //PriorElem(L,3,&e);
    //printf("%d\n",e);
   
    //NextElem(L,3,&e);
    //printf("%d\n",e);

    //ListDelete(&L,1,&e);
    //printf("%d\n",e);
    
    //DestroyList(&L); 
    return 0;
}

