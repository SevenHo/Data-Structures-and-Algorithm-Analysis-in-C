#include <stdio.h>
#include <stdlib.h>
#include "my_binary_search_tree.h"

typedef struct TreeNode
{
    ElementType e;
    SearchTree left;
    SearchTree right;
} aNode;

/**
 * 置空
 */
SearchTree make_empty(SearchTree ST)
{
    if (ST)
    {
        make_empty(ST->left);
        make_empty(ST->right);
        free(ST);
    }
    return NULL;
}
Position find(ElementType e, SearchTree ST)
{
    if (!ST)
        return NULL;
    if (e < ST->e)
    {
        find(e, ST->left);
    }
    else if (e > ST->e)
    {
        return find(e, ST->right);
    }
    else
    {
        return ST;
    }
}
Position find_min(SearchTree ST){
    if (!ST)
    {
        return NULL;
    }
    // if (ST->left)
    // {
    //     return find_min(ST->left);
    // }else
    // {
    //     return ST;
    // }
    Position tmpcell = ST;
    while (tmpcell->left)
    {
        tmpcell = tmpcell->left;
    }  
    return tmpcell;
}

Position find_max(SearchTree ST){
    if (!ST)    
    {
        return NULL;
    }
    while (ST->right)   
    {
        ST = ST->right;
    }
    return ST;
}
/**
 * 插入元素
 */ 
SearchTree insert(ElementType e, SearchTree ST)
{
    if (!ST)
    {
        ST = (SearchTree)malloc(sizeof(aNode));
        if(!ST)
            exit(1);
        ST->e = e;
        ST->left = NULL;
        ST->right = NULL;
        
    }else
    {
        if(e < ST->e)
        {
            ST->left = insert(e,ST->left);
        }else if(e > ST->e)
        {
            ST->right = insert(e,ST->right);
        }
    }
    return ST;
}

SearchTree delete_min(SearchTree ST)
{
    if(!ST)
        return NULL;
    if(ST->left)
    {
        ST->left = delete_min(ST->left);
    }else
    {
        /*found element to be deleted*/
        Position tmpcell = ST->right;
        if(tmpcell){
            ST->e = tmpcell->e;
            ST->left = tmpcell->left;
            ST->right = tmpcell->right;
            free(tmpcell);
        }else
        {
            free(ST);
            ST = NULL;
        }
    }
    return ST;    
}

SearchTree delete_e(ElementType e, SearchTree ST)
{
    Position tmpcell = NULL;
    if (!ST)
    {
        return NULL;
    }
    if (e < ST->e)
    {   /*go left*/
        ST->left = delete_e(e,ST->left);
    }else if(e > ST->e)
    {   /*go right*/
        ST->right = delete_e(e,ST->right);
    }else
    {
        /*found element to be deleted*/
        if(ST->left && ST->right)
        {
            /*two childs*/
            /*find smallest element in right SearchTree*/
            tmpcell = find_min(ST->right); 
            ST->e = tmpcell->e;
            // ST->right = delete_e(ST->e,ST->right);  
            ST->right = delete_min(ST->right);
        }else
        {
            tmpcell = ST;
            if(!ST->right)
            {
                ST = ST->left;
            }else
            if(!ST->left)
            {
                ST = ST->right;
            }
            free(tmpcell);
        }
            
    }
    return ST;
}

ElementType retrieve(Position P)
{
    return P->e;
}

void preorder_traversal(SearchTree T)
{
    if(T)
    {
        printf("%2c",T->e);
        preorder_traversal(T->left);
        preorder_traversal(T->right);
    }
}
/**
 * 中序遍历
 */ 
void inorder_traversal(SearchTree T){
    
    if(T)
    {
        inorder_traversal(T->left);
        printf("%2c",T->e);
        inorder_traversal(T->right);
    }
}
/**
 * 后续遍历
 */ 
void postorder_traversal(SearchTree T)
{
    if (T)
    {
        postorder_traversal(T->left);
        postorder_traversal(T->right);
        printf("%2c",T->e);
    }
    
}

int main(void)
{
    SearchTree T = NULL;
    char input = '\0';
    while((input = getchar()) != '\n')
    {   
        if(input != 32)
           T = insert(input,T);
    }
    preorder_traversal(T);
    printf("\n");
    inorder_traversal(T); 
    printf("\n"); 
    postorder_traversal(T);

    printf("\n%2c\n",retrieve(find_max(T)));
    printf("\n%2c\n",retrieve(find_min(T)));
    
    T = delete_e('2',T);

    preorder_traversal(T);
    printf("\n");
    inorder_traversal(T); 
    printf("\n"); 
    postorder_traversal(T);

    printf("\n"); 
    T = delete_e('5',T);

    preorder_traversal(T);
    printf("\n");
    inorder_traversal(T); 
    printf("\n"); 
    postorder_traversal(T);

    printf("\n"); 
    T = delete_e('4',T);

    preorder_traversal(T);
    printf("\n");
    inorder_traversal(T); 
    printf("\n"); 
    postorder_traversal(T);

}