#include <stdio.h>
#include <stdlib.h>
#include "my_stack_list.h"

struct Node
{
    ElementType value;
    PtrToNode next;
} sNode;

/**
     * 判断是否为空
     */
int is_empty(Stack S)
{
    return S->next == NULL;
}
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
/**
     * 释放栈空间
     */
void dispose_stack(Stack S)
{
    Stack tmp = NULL;
    tmp = S->next;
    make_empty(S);
    free(S);
}
/**
     * 栈置空
     */
void make_empty(Stack S)
{
    Stack tmp = NULL;
    tmp = S->next;
    while (tmp)
    {
        S->next = tmp->next;
        free(tmp);
        tmp = S->next;
    }
}
/**
     * 元素入栈
     */
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
/*
int main(void)
{
    Stack S = NULL;
    S = create_stack();
    push(1, S);
    push(2, S);
    push(3, S);
    push(4, S);
    push(5, S);

    printf("top:%d\n", top(S));
    pop(S);
    printf("top:%d\n", top_pop(S));

    make_empty(S);
    printf("%d", is_empty(S));
    dispose_stack(S);

    return 0;
}
*/