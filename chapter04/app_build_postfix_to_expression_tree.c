#include <stdio.h>
#include <stdlib.h>
// #include "../chapter03/my_stack_list.h"

/**
 *  When this file is compiled needs to be with '../chapter/my_statck_lsit.c'  
 */ 

typedef char Tree_ElementType;
typedef struct TreeNode *ptrNode;
typedef ptrNode Tree;
typedef Tree ElementType;


typedef struct TreeNode{
    Tree_ElementType e;
    Tree left;
    Tree right;
}aTreeNode;

struct Node ;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack ;

struct Node
{
    ElementType value;
    PtrToNode next;
} sNode;

/**
     * 创建一个栈
     */
Stack create_stack()
{
    Stack S = NULL;
    S = (Stack)malloc(sizeof(sNode));
    S->next = NULL;
    S->value = 0;
}

void push(ElementType e, Stack S)
{
    PtrToNode tmpCell = NULL;
    tmpCell = (PtrToNode)malloc(sizeof(sNode));
    if (!tmpCell)
    {
        exit(1);
    }
    tmpCell->value = e;
    tmpCell->next = S->next;
    S->next = tmpCell;
}
/**
     * 栈顶元素
     */
ElementType top(Stack S)
{
    return S->next->value;
}
/**
     * 元素出栈
     */
void pop(Stack S)
{
    PtrToNode p = NULL;
    p = S->next;
    S->next = p->next;
    free(p);
}
/**
     * 出栈且返回栈顶元素
     */
ElementType top_pop(Stack S)
{
    ElementType e = top(S);
    pop(S);
    return e;
}

/**
 * 构造表达式树
 */ 
Tree build_exp_tree(Tree_ElementType e,Tree left , Tree right)
{
    Tree T = NULL;
    T = (Tree) malloc(sizeof(aTreeNode));
    if(!T){
        exit(1);
    }
    T->e = e;
    T->left = left;
    T->right = right;
    return T;

}

void preorder_traversal(Tree T)
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
void inorder_traversal(Tree T){
    
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
void postorder_traversal(Tree T)
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
    char input = '\0';
    Stack S = create_stack();
    while ((input = getchar()) != '\n')
    {
        if(input != 32)
        {
            if('0'<= input && input >= '9' )
            {
                push(build_exp_tree(input,NULL,NULL),S);
            }else
            {
                push(build_exp_tree(input,top_pop(S),top_pop(S)),S);
            }
            
        }
    }
    Tree T = top(S);
    inorder_traversal(T);
    printf("\n");
    preorder_traversal(T);
    printf("\n");
    postorder_traversal(T);
    return 0;
}

