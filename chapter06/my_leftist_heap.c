#include <stdio.h>
#include <stdlib.h>
#include "my_leftist_heap.h"

#define MIN_NPL(A, B) ((A) > (B) ? (B) : (A))

struct TreeNode
{
    ElementType e;
    int Npl;
    PriortyQueue left;
    PriortyQueue right;
};

int getNpl(PriortyQueue H)
{
    if (H)
    {
        return H->Npl;
    }
    return -1;
}

PriortyQueue initialize_heap()
{
    PriortyQueue heap = malloc(sizeof(struct TreeNode));
    heap->left = 0;
    heap->right = 0;
    heap->Npl = 0;
}
ElementType findMin(PriortyQueue H)
{
    if (H)
    {
        return H->e;
    }
}

int is_empty(PriortyQueue H)
{
    return H == NULL;
}

void swapchild(PriortyQueue H)
{
    PriortyQueue tmp = H->left;
    H->left = H->right;
    H->right = tmp;
}

/**
 * 时间程序
 */ 
PriortyQueue Merge1(PriortyQueue H1, PriortyQueue H2)
{
    if (H1->left == NULL)
    {
        H1->left = H2;
    }
    else
    {
        H1->right = Merge(H1->right, H2);
        if (H1->left->Npl < H1->right->Npl)
        {
            swapchild(H1);
        }
        H1->Npl = MIN_NPL(getNpl(H1->left), getNpl(H1->right)) + 1;
    }
    return H1;
}
/**
 * 驱动函数，处理两棵树，然后返回的也是树，
 * 进行预处理，
 */
PriortyQueue Merge(PriortyQueue H1, PriortyQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->e < H2->e)
    {
        /*H2 合并到 H1*/
        return Merge1(H1, H2);
    }
    else
    {
        /*H1 合并到 H2*/
        return Merge1(H2, H1);
    }
}

PriortyQueue insert(ElementType x, PriortyQueue H)
{
    PriortyQueue cell = (PriortyQueue)malloc(sizeof(struct TreeNode));
    cell->e = x;
    cell->left = NULL;
    cell->right = NULL;
    cell->Npl = 0;

    return Merge(H, cell);
}

PriortyQueue delete_min1(PriortyQueue H)
{
    PriortyQueue leftheap, rightheap;
    leftheap = H->left;
    rightheap = H->right;
    free(H);
    return Merge(leftheap, rightheap);
}

int main(void)
{
    PriortyQueue H = NULL;
    insert_heap(3, H);
    insert_heap(8, H);
    insert_heap(10, H);
    insert_heap(21, H);
    insert_heap(14, H);
    insert_heap(23, H);
    insert_heap(17, H);
    insert_heap(26, H);

    PriortyQueue H2 = NULL;
    insert_heap(6, H2);
    insert_heap(18, H2);
    insert_heap(37, H2);
    insert_heap(18, H2);
    insert_heap(24, H2);
    insert_heap(7, H2);
    insert_heap(12, H2);
    insert_heap(33, H2);

    H = Merge(H, H2);
    delete_min(H);

    return 0;
}