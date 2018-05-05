#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1

typedef int Status;
typedef int Elem;
typedef Elem *Triplet;

Status InitTriplet(Triplet *T, Elem v0, Elem v1, Elem v2)
{
	*T = (Elem *)malloc(3 * sizeof(Elem));
	(*T)[0] = v0;
	(*T)[1] = v1;
	(*T)[2] = v2;
	return OK;
}

Status DestroyTriplet(Triplet *T)
{
	free(*T);
	*T = NULL;
	return OK;
}

Status Get(Triplet T,int i,Elem *e)
{
    if( i<1 || i>3 || T == NULL)
        return ERROR;
    *e = T[i-1];
    return OK;
}

Status Put(Triplet T, int i, Elem e)
{
    if( i<1 || i>3 || T == NULL)
        return ERROR;
    T[i] = e;
    return OK;
}

Status IsAscending(Triplet T)
{
    if(T == NULL)
        return ERROR;
    return(T[0]<T[1] && T[1]<T[2]);
}

Status IsDescending(Triplet T)
{
    if(T == NULL)
        return ERROR;
    return(T[0]>T[1] && T[1]>T[2]);
}

int Max(Triplet T)
{
    if(T == NULL)
        return ERROR;
    int temp = T[0]>T[1]?T[0]:T[1];
    return temp>T[2]?temp:T[2];
}

int Min(Triplet T)
{
    if(T == NULL)
        return ERROR;
    int temp = T[0]>T[1]?T[1]:T[0];
    return temp>T[2]?T[2]:temp;
}

int main(void)
{
    Triplet t;
    InitTriplet(&t, 1, 2, 3);
    printf("%d%d%d\n", t[0], t[1], t[2]);
    printf("%d\n",IsAscending(t));
    printf("%d\n",IsDescending(t));
    printf("%d\n",Max(t));
    printf("%d\n",Min(t));
    return 0;
}


