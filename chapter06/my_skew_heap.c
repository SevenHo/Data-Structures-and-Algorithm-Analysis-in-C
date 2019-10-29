#include <stdio.h>
#include <stdlib.h>
#include "my_skew_heap.h"

struct TreeNode
{
    ElementType e;
    PriortyQueue left;
    PriortyQueue right;
};

int is_empty(PriortyQueue H)
{
    return H == NULL;
}
PriortyQueue insert(ElementType x, PriortyQueue H)
{
    PriortyQueue cell = (PriortyQueue)malloc(sizeof(struct TreeNode));
    cell->e = x;
    cell->left = NULL;
    cell->right = NULL;

    return Merge(H, cell);
}

PriortyQueue delete_min(PriortyQueue H)
{
    PriortyQueue leftheap, rightheap;
    leftheap = H->left;
    rightheap = H->right;
    free(H);
    return Merge(leftheap, rightheap);
}

void swapchild(PriortyQueue H)
{
    if (H && H->left && H->right)
    {
        PriortyQueue tmp = H->left;
        H->left = H->right;
        H->right = tmp;
    }
}

PriortyQueue static Merge1(PriortyQueue H1, PriortyQueue H2)
{
    if (H1->left == NULL)
    {
        H1->left = H2;
    }
    else
    {
        H1->right = Merge(H1->right, H2);
        swapchild(H1);
    }
    return H1;
}

PriortyQueue Merge(PriortyQueue H1, PriortyQueue H2)
{
    if (H1 == NULL)
    {
        return H2;
    }
    if (H2 == NULL)
    {
        return H1;
    }
    if (H1->e < H2->e)
    {
        return Merge1(H1, H2);
    }
    else
    {
        return Merge1(H2, H1);
    }
}