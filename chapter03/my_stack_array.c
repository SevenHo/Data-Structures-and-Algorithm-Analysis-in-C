#include <stdio.h>
#include <stdlib.h>
#include "my_stack_array.h"

typedef struct StackRecord
{
    int capacity;
    int top_stack;
    ElementType *Array;
} aStack;

/**
     * 判断是否为空
     */
int is_empty(Stack S)
{
    return S->top_stack == -1;
}
/**
     *  栈是否已满
     */
int is_full(Stack S)
{
    return S->top_stack == (S->capacity - 1);
}
/**
     * 创建一个栈
     */
Stack create_stack(int MaxElements)
{
    Stack S = NULL;
    S = (Stack)malloc(sizeof(aStack));
    if (!S)
    {
        exit(1);
    }
    ElementType *tmp = NULL;
    tmp = malloc(sizeof(ElementType) * MaxElements);
    if (!tmp)
    {
        exit(1);
    }
    S->Array = tmp;
    S->capacity = MaxElements;
    S->top_stack = -1;
}
/**
     * 栈置空
     */
void make_empty(Stack S)
{
    S->top_stack = -1;
}
/**
     * 释放栈
     */
void dispose_stack(Stack S)
{
    free(S->Array);
    free(S);
}
/**
     * 入栈
     */
void push(ElementType e, Stack S)
{
    if (is_full(S))
    {
        exit(2);
    }
    else
    {
        S->top_stack += 1;
        (S->Array)[S->top_stack] = e;
    }
}
/**
     * 出栈
     */
void pop(Stack S)
{
    if (is_empty(S))
    {
        exit(3);
    }
    else
    {
        S->top_stack -= 1;
    }
}
/**
     * 取栈顶元素
     */
ElementType top(Stack S)
{
    if (is_empty(S))
    {
        exit(3);
    }
    else
    {
        return (S->Array)[S->top_stack];
    }
}
/**
     * 返回并删除栈顶元素
     */
ElementType top_pop(Stack S)
{
    ElementType tmp = top(S);
    pop(S);
    return tmp;
}

int main(void)
{
    Stack S = NULL;
    S = create_stack(10);
    push(1, S);
    push(2, S);
    push(3, S);
    push(4, S);
    push(5, S);

    printf("top:%d\n", top(S));
    pop(S);
    printf("top:%d\n", top_pop(S));

    make_empty(S);
    printf("%d\n", is_empty(S));
    dispose_stack(S);
    printf("success...");
    return 0;
}