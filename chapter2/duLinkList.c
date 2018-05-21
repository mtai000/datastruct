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

typedef struct DuLNode{
    Elem data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*Link,*Position;

typedef struct{
    Link head,tail;
    int len;
}DuLinkList;

Status CreateDuList(DuLinkList *L, int len)
{
    L->len = len;
    
    if (len == 0)
    {
        return OK;
    }
    Position pos = L->head;
    for (int i = 1; i <= L->len; i++)
    {
        DuLNode *p = (Link)malloc(sizeof(DuLNode));
        if (i == 1)
        {
            L->head = p;
            L->tail = p;
            printf("Input %d value:", i);
            scanf("%d", &(p->data));
            p->next = p;
            p->prior = p;
        }
        else
        {
            p->prior = pos;
            pos->next = p;
            L->tail = p;
            p->next = L->head;
            L->head->prior = p;
            printf("Input %d value:", i);
            scanf("%d", &(p->data));
        }
        pos = p;
    }

    return OK;
}



int main(void)
{
    DuLinkList L/*,L2,L3,L4*/;

    CreateDuList(&L,5);
    //int e=6;
    //ListDelete_L(&L,5,&e);
    //CreateList_L(&L2,3);
    //CreateList_L(&L3,4);
    //CreateList_L(&L4,0);
    //MergeList(&L2,&L3,&L4);
    Position p = L.head;
    for(int i =0; i<L.len;i++)
    {
        printf("%d,",p->data);
        p = p->next;
    }
    printf("\n");
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



