#include <stdio.h>
#include <stdlib.h>
#include "my_queue_list.h"

typedef struct QueueRecord
{
    ElementType value;
    PtrNode prior;
    PtrNode next;
} qNode;

/**
     * 创建一个队列
     */
Queue create_queue()
{
    Queue Q = NULL;
    Q = (Queue)malloc(sizeof(qNode));
    Q->next = Q;
    Q->prior = Q;
    return Q;
}
/**
     * 判断是否为空
     */
int is_empty(Queue Q)
{
    return Q->next == Q;
}
/**
     * 释放队列
     */
void dispose_queue(Queue Q)
{
    make_empty(Q);
    free(Q);
}
/**
     * 队列置空
     */
void make_empty(Queue Q)
{
    while (!is_empty(Q))
    {
        dequeue(Q);
    }
}
/**
     * 入队
     */
void enqueue(ElementType e, Queue Q)
{
    PtrNode tmpcell = NULL;
    tmpcell = (PtrNode)malloc(sizeof(qNode));
    if (!tmpcell)
    {
        exit(1);
    }
    tmpcell->value = e;
    tmpcell->next = Q->next;
    tmpcell->prior = Q;
    Q->next = tmpcell;
    tmpcell->next->prior = tmpcell;
}
/**
     * 出队
     */
void dequeue(Queue Q)
{
    if (!is_empty(Q))
    {
        PtrNode p = Q->prior;
        Q->prior = p->prior;
        p->prior->next = Q;
        free(p);
    }
}
/**
     * 下一个出队元素
     */
ElementType front(Queue Q)
{
    return Q->prior->value;
}
/**
     * 出队并返回元素
     */
ElementType front_dequeue(Queue Q)
{
    ElementType e = front(Q);
    dequeue(Q);
    return e;
}

int main(void)
{
    Queue Q = NULL;
    Q = create_queue();
    enqueue(1, Q);
    enqueue(2, Q);
    enqueue(3, Q);
    enqueue(4, Q);
    enqueue(5, Q);
    printf("%d\n", is_empty(Q));
    printf("front:%d\n", front(Q));
    dequeue(Q);
    printf("front:%d\n", front_dequeue(Q));
    make_empty(Q);
    printf("%d\n", is_empty(Q));
    enqueue(6, Q);
    printf("front:%d\n", front(Q));
    dispose_queue(Q);
    printf("success...");
    return 0;
}