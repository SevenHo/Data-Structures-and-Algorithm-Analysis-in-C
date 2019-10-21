#include <stdio.h>
#include <stdlib.h>
#include "my_avl_tree.h"

#define MAX_H(A, B) ((A) > (B) ? (A) : (B))

typedef struct AvlNode
{
    ElementType e;
    int height;
    AvlTree left;
    AvlTree right;
} aAvlNode;

// AvlTree static single_rotate_with_left(AvlTree T);
// AvlTree static single_rotate_with_right(AvlTree T);

// AvlTree static double_rotate_with_left(AvlTree T);
// AvlTree static double_rotate_with_right(AvlTree T);

AvlTree make_empty(AvlTree T)
{
    if (T)
    {
        make_empty(T->left);
        make_empty(T->right);
        free(T);
    }
    return NULL;
}

int height(Position P)
{
    if (P)
    {
        return P->height;
    }
    return -1;
}

Position find(ElementType e, AvlTree T)
{
    if (T)
    {
        if (e < T->e)
        {
            return find(e, T->left);
        }
        else if (e > T->e)
        {
            return find(e, T->right);
        }
        else
        {
            return T;
        }
        return NULL;
    }
}

Position find_min(AvlTree T)
{
    if (T)
    {
        while (T->left)
        {
            T = T->left;
        }
        return T;
    }
    return NULL;
}

Position find_max(AvlTree T)
{
    if (T)
    {
        while (T->right)
        {
            T = T->right;
        }
        return T;
    }
}

/**
 * 左左-单旋转 
 */
AvlTree static single_rotate_with_left(AvlTree T)
{
    Position TL = T->left;
    T->left = TL->right;
    TL->right = T;

    /*update height of T and TL*/
    T->height = MAX_H(height(T->left), height(T->right)) + 1;
    TL->height = MAX_H(height(T->left), T->height) + 1;
    return TL;
}

/**
 * 右右-单旋转 
 */
AvlTree static single_rotate_with_right(AvlTree T)
{
    Position TR = T->right;
    T->right = TR->left;
    TR->left = T;

    T->height = MAX_H(height(T->left), height(T->right)) + 1;
    TR->height = MAX_H(T->height, height(TR->right)) + 1;
    return TR;
}

/**
 * 左右-双旋转
 */
AvlTree static double_rotate_with_left(AvlTree T)
{
    // Position TL = T->left;
    // Position TLR = TL->right;

    // T->left = TLR->right;
    // TLR->right = T;
    // TL->right = TLR->left;
    // TLR->left = TL;

    /*firstly,rotate right*/
    T->left = single_rotate_with_right(T->left);
    /*second;y, rotate left*/
    T = single_rotate_with_left(T);

    return T;
}

/**
 * 右左-双旋转
 */
AvlTree static double_rotate_with_right(AvlTree T)
{
    // Position TR = T->right;
    // Position TRL = TR->left;

    // T->right = TRL->left;
    // TRL->left = T;
    // TR->left = TRL->right;
    // TRL->right = TR;

    T->right = single_rotate_with_left(T->right);
    T = single_rotate_with_right(T);

    return T;
}

/**
 * 插入
 */
AvlTree insert(ElementType e, AvlTree T)
{
    if (!T)
    {
        T = (AvlTree)malloc(sizeof(aAvlNode));
        if (!T)
        {
            printf("out of space!!!");
            exit(1);
        }
        T->e = e;
        T->left = NULL;
        T->right = NULL;
    }
    if (e < T->e)
    {
        T->left = insert(e, T->left);
        if (height(T->left) - height(T->right) == 2)
        {
            if (e < T->left->e)
            {
                T = single_rotate_with_left(T);
            }
            else
            {
                T = double_rotate_with_left(T);
            }
        }
    }
    else if (e > T->e)
    {
        T->right = insert(e, T->right);
        if (height(T->right) - height(T->left) == 2)
        {
            if (e > T->right->e)
            {
                T = single_rotate_with_right(T);
            }
            else
            {
                T = double_rotate_with_right(T);
            }
        }
    }

    T->height = MAX_H(height(T->left), height(T->right)) + 1;
    return T;
}

int is_balance(AvlTree T)
{
    if (T)
    {
        return abs(height(T->left) - height(T->right)) < 2;
    }
    return 1;
}

AvlTree fix_balance(AvlTree T)
{
    if (height(T->left) - height(T->right) == 2)
    {
        if (T->left->right)
        {
            T = double_rotate_with_left(T);
        }
        else
        {
            T = single_rotate_with_left(T);
        }
    }
    else if (height(T->right) - height(T->left) == 2)
    {
        if (T->right->left)
        {
            T = double_rotate_with_right(T);
        }
        else
        {
            T = single_rotate_with_right(T);
        }
    }

    return T;
}

/**
 * 删除最小元素
 */
AvlTree delete_min(AvlTree T)
{
    if (!T)
    {
        return NULL;
    }
    if (T->left)
    {
        T->left = delete_min(T->left);
        if (height(T->right) - height(T->left) == 2)
        {
            if (T->right && T->right->left) /*double rotate*/
            {
                T = double_rotate_with_right(T);
            }
            else /*else single rotate*/
            {
                T = single_rotate_with_right(T);
            }
        }
    }
    else
    {
        Position tmpcell = T->right;
        if (tmpcell)
        {
            T->e = tmpcell->e;
            T->left = tmpcell->left;
            T->right = tmpcell->right;
            T->height = tmpcell->height;
            free(tmpcell);
        }
        else
        {
            free(T);
            T = NULL;
        }
    }
    return T;
}

/**
 *删除
 */
AvlTree delete_e(ElementType e, AvlTree T)
{
    if (!T)
    {
        return NULL;
    }

    if (e < T->e)
    {
        T->left = delete_e(e, T->left);
    }
    else if (e > T->e)
    {
        T->right = delete_e(e, T->right);
    }
    else
    {
        if (T->left && T->right)
        {
            Position r_min = find_min(T->right);
            T->e = r_min->e;
            T->right = delete_min(T->right);
            // T->right = delete_e(T->e,T->right); /*同上一样*/
        }
        else
        {
            Position tmpcell = T;
            if (!T->left)
            {
                T = T->right;
            }
            else if (!T->right)
            {
                T = T->left;
            }
            free(tmpcell);
        }
    }
    /*同检索二叉树一样删除,删除检查是否平衡,并修复*/
    if (T)
    {
        T->height = MAX_H(height(T->left), height(T->right)) + 1;
        if (!is_balance(T))
            T = fix_balance(T);
    }
    return T;
}
/**
 * 取出元素值
 */
ElementType retrieve(Position P)
{
    if (P)
    {
        return P->e;
    }
}

/**
 * 中序遍历
 */
void inorder_traversal(AvlTree T)
{

    if (T)
    {
        inorder_traversal(T->left);
        printf("%2d ,", T->e);
        inorder_traversal(T->right);
    }
}

int main(void)
{
    AvlTree T = make_empty(NULL);
    for (int i = 1; i < 8; i++)
    {
        T = insert(i, T);
    }
    for (int i = 16; i > 9; i--)
    {
        T = insert(i, T);
    }
    T = insert(8, T);
    T = insert(9, T);
    T = insert(17,T);

    inorder_traversal(T);
    T = delete_e(3, T);
    T = delete_e(5, T);
    T = delete_e(6, T);
    printf("\n");
    inorder_traversal(T);
    return 0;
}