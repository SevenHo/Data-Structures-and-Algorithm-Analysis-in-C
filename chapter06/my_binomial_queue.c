#include <stdio.h>
#include <stdlib.h>
#include "my_binomial_queue.h"

struct BinNode
{
    ElementType e;
    Position leftchild;
    Position nextsibling;
};

struct Collection
{
    int currentsize;
    Position forest[Max_Trees];
};

BinQueue initialize()
{
    BinQueue H = (BinQueue)malloc(sizeof(struct Collection));
    H->currentsize = 0;
}
void destroy(BinQueue H)
{
    free(H);
}
is_empty(BinQueue H)
{
    return H->currentsize == Max_Trees;
}
void insert(ElementType x, BinQueue H)
{
    Position cell = (Position)malloc(sizeof(struct BinNode));
    cell->e = x;
    cell->leftchild = NULL;
    cell->nextsibling = NULL;
}
ElementType find_min(BinQueue H)
{
    int min = 0;
    while (!H->forest[min])
    {
        min++;
    }
    for (int i = 1; i < Max_Trees; i++)
    {
        if (H->forest[i] && H->forest[i]->e < H->forest[min]->e)
        {
            min = i;
        }
    }
    return H->forest[min]->e;
}

BinTree combine_trees(BinTree T1, BinTree T2)
{
    if (T1->e > T2->e)
    {
        return combine_trees(T2, T1);
    }
    T2->nextsibling = T1->leftchild;
    T1->leftchild = T2;
    return T1;
}
void delete_min(BinQueue H)
{
    int minindex = 0;
    int minval = INT_MAX;
    for (int i = 0; i < Max_Trees; i++)
    {
        if(H->forest[i] && H->forest[i]->e < minval)
        {
            minval = H->forest[i]->e;
            minindex = i;
        }
    }
    Position deletedTree = H->forest[minindex];
    Position child = deletedTree->leftchild;
    H->forest[minindex] = NULL;
    BinQueue tmpH = initialize();
    while (--minindex && child)
    {
        tmpH->forest[minindex] = child;
        child = child->nextsibling;
        tmpH->forest[minindex]->nextsibling = NULL;
    }
    H = Merge(H,tmpH);
    destroy(tmpH);
    free(deletedTree);
}
BinQueue Merge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;
    if ((H1->currentsize + H2->currentsize) > Max_Trees)
    {
        printf("\rMerge would exceed capacity\n");
        exit(1);
    }
    H1->currentsize += H2->currentsize;
    for (int i = 0,j = 1; j <= H1->currentsize; i++, j << 2)
    {
        T1 = H1->forest[i];
        T2 = H2->forest[i];
        switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
        {
        case 0:
            break; /*no trees*/
        case 1:
            break; /*only T1*/
        case 2:
            H1->forest[i] = T2; /*only T2*/
            break;
        case 4:
            H1->forest[i] = Carry; /*only Carry*/
            Carry = NULL;
            break;
        case 3: /*T1 and T2*/
            Carry = combine_trees(T1, T2); /*T1 and T2*/
            H1->forest[i] = H2->forest[i] = NULL;
            break;
        case 5:/*T1 and Carry*/
            Carry = combine_trees(T1,Carry);
            H1->forest[i] = NULL;
            break;
        case 6: /*T2 and Carry*/
            Carry = combine_trees(T2,Carry);
            H2->forest[i] = NULL;
            break;
        case 7:
            H1->forest[i] = Carry; /*all trees*/
            Carry = combine_trees(T1,T2);
            H2->forest[i] = NULL;
        }
    }
}