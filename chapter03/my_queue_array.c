#include <stdio.h>
#include <stdlib.h>
#include "my_queue_array.h"

typedef struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *array;
} qNode;

/**
     * 判断是否为空
     */
int is_empty(Queue Q)
{
    return Q->size == 0;
}
/**
     * 判断是否队列满
     */
int is_full(Queue Q)
{
    return Q->size == Q->capacity;
}

/**
     * 创建一个队列
     */
Queue create_queue(int MaxElements)
{
    Queue Q = NULL;
    Q = malloc(sizeof(qNode));
    if (!Q)
    {
        exit(1);
    }
    ElementType *tmparr = NULL;

    tmparr = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (!Q)
    {
        exit(1);
    }
    Q->array = tmparr;
    Q->capacity = MaxElements;
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}
/**
     * 释放队列空间
     */
void dispose_queue(Queue Q)
{
    free(Q->array);
    free(Q);
}
/**
     * 队列置空
     */
void make_empty(Queue Q)
{
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;
}
/**
     * 入队
     */
void enqueue(ElementType e, Queue Q)
{
    if (is_full(Q))
    {
        exit(2);
    }
    else
    {
        (Q->array)[Q->rear] = e;
        Q->rear = ++(Q->rear)%(Q->capacity);
        (Q->size)++;
    }
}
/**
     * 出队
     */
void dequeue(Queue Q)
{
    if (is_empty(Q))
    {
        exit(3);
    }else
    {
        Q->front =  ++(Q->front)%(Q->capacity);
        (Q->size)--;
    }
    
}

/**
     * 下一个出队元素
     */
ElementType front(Queue Q)
{
    return (Q->array)[Q->front];
}

/**
     * 出队并返回下一个元素
     */
ElementType front_dequeue(Queue Q)
{
    ElementType e = front(Q);
    dequeue(Q);
    return e;
}

/*
int main(void)
{
    Queue Q = NULL;
    Q = create_queue(5);
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
    printf("success...2");
    return 0;
}
*/