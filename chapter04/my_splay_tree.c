#include <stdio.h>
#include <stdlib.h>
#include "my_splay_tree.h"

typedef struct SplayTreeNode
{
    ElementType e;
    struct SplayTreeNode *left;
    struct SplayTreeNode *right;
} aNode;

SplayTree single_rotate_left(SplayTree T)
{
    Position LT = T->left;

    T->left = LT->right;
    LT->right = T;

    return LT;
}

SplayTree single_rotate_right(SplayTree T)
{
    Position RT = T->right;

    T->right = RT->left;
    RT->left = T;

    return RT;
}

/**
 *一字形 
 */
SplayTree zig_zig_left(SplayTree T)
{
    T = single_rotate_left(T);
    T = single_rotate_left(T);
    return T;
}

SplayTree zig_zig_right(SplayTree T)
{
    T = single_rotate_right(T);
    T = single_rotate_right(T);

    return T;
}

/**
 * 之字形
 */
SplayTree zig_zag_left(SplayTree T)
{
    T->left = single_rotate_right(T->left);
    T = single_rotate_left(T);

    return T;
}

SplayTree zig_zag_right(SplayTree T)
{
    T->right = single_rotate_left(T->right);
    T = single_rotate_right(T);

    return T;
}

/**
 * 找最大值
 */
Position find_max(SplayTree T)
{
    if (T)
    {
        while (T->right)
        {
            T = T->right;
        }
    }
    return T;
}

SplayTree insert_splay_tree(ElementType e, SplayTree T)
{
    if (!T)
    {
        T = (Position)malloc(sizeof(aNode));
        if (!T)
        {
            exit(1);
        }
        T->e = e;
        T->left = NULL;
        T->right = NULL;
        return T;
    }
    else if (e < T->e)
    {
        T->left = insert_splay_tree(e, T->left);
    }
    else if (e > T->e)
    {
        T->right = insert_splay_tree(e, T->right);
    }

    return T;
}
static Position find_splay_tree1(ElementType e, SplayTree T)
{
    if (!T)
    {
        return NULL;
    }
    else if (e < T->e)
    {
        SplayTree tmpT = find_splay_tree1(e, T->left);
        if(tmpT){
          T->left = tmpT;
        }else
        {
            return NULL;
        }
    
        if (T->left && e < T->left->e)
        { // 展开
            T = zig_zig_left(T);
        }
        else if (T->left && e > T->left->e)
        {
            T = zig_zag_left(T);
        }
    }
    else if (e > T->e)
    {
        SplayTree tmpT = find_splay_tree1(e, T->right);
        if(tmpT){
          T->right = tmpT;
        }else
        {
            return NULL;
        }

        if (T->right && e < T->right->e)
        {
            T = zig_zag_right(T);
        }
        else if (T->right && e > T->right->e)
        {
            T = zig_zig_right(T);
        }
    }

    return T;
}

SplayTree find_splay_tree(ElementType e, SplayTree T)
{
    SplayTree tmpT;
    tmpT = find_splay_tree1(e, T);
    if (!tmpT)
    {
        return NULL;
    }
    else
    {
        if (tmpT->e == e)
        {
            return tmpT;
        }
        else if (tmpT->left->e == e)
        {
            T = single_rotate_left(tmpT);
        }
        else if (tmpT->right->e == e)
        {
            T = single_rotate_right(tmpT);
        }
        return T;
    }
}

SplayTree delete_splay_tree(ElementType e, SplayTree T)
{
    Position cell = find_splay_tree(e, T);
    if (cell)
    {
        Position maxLeft = find_max(cell->left);
        if (maxLeft)
        {
            maxLeft = find_splay_tree(maxLeft->e, T);
            maxLeft->right = T->right;
            T = maxLeft;
        }
        else
        {
            T = cell->right;
        }
        free(cell);
    }
    return T;
}
void dispose_tree(SplayTree T)
{
    if (T)
    {
        dispose_tree(T->left);
        dispose_tree(T->right);
        free(T);
    }
}

void postorder_traversal(SplayTree T)
{

    if (T)
    {
        postorder_traversal(T->left);
        postorder_traversal(T->right);
        printf("%2d, ", T->e);
    }
}

int main(void)
{
    SplayTree T = NULL;
    T = insert_splay_tree(7, T);

    T = insert_splay_tree(6, T);
    T = insert_splay_tree(5, T);
    T = insert_splay_tree(4, T);
    T = insert_splay_tree(3, T);
    T = insert_splay_tree(2, T);
    T = insert_splay_tree(1, T);

    T = find_splay_tree(1, T);
    postorder_traversal(T);
    T = delete_splay_tree(1, T);
    printf("\n");
    postorder_traversal(T);
    dispose_tree(T);

    return 0;
}