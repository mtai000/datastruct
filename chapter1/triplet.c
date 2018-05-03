#include <stdio.h>
struct Triplet{
    int e1;
    int e2;
    int e3;
};

void InitTriplet(struct Triplet *T,int v1,int v2,int v3)
{
    T->e1 = v1;
    T->e2 = v2;
    T->e3 = v3;
}

void main()
{
    struct Triplet T;
    InitTriplet(&T,1,2,3);
    printf("%d%d%d\n",T.e1,T.e2,T.e3);
}


