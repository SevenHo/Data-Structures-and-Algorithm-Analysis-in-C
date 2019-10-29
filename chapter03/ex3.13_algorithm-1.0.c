#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define buckets 10
#define times 3
#define ElementType int

typedef struct Node
{
    ElementType e;
    struct Node *next;
} aNode, *Position;

typedef struct Queue_S
{
    int size;
    Position front;
    Position rear;
} * Queue;

int is_empty(Queue Q)
{
    if (Q)
    {
        return Q->front == Q->rear;
    }
    return 1;
}

Queue create_queue()
{
    Queue Q = (Queue)malloc(sizeof(struct Queue_S));
    Q->front = Q->rear = (Position)malloc(sizeof(aNode));
    Q->rear->next = NULL;
    Q->size = 0;
    return Q;
}
void enqueue(ElementType e, Queue Q)
{
    Position p;
    if (!Q)
    {
        Q = (Queue)malloc(sizeof(struct Queue_S));
        p = (Position)malloc(sizeof(aNode));
        p->e = e;
        p->next = NULL;
        Q->front = p;
        Q->rear = (Position)malloc(sizeof(aNode));
        Q->rear->next = NULL;
        Q->front->next = Q->rear;
        Q->size++;
    }
    else
    {
        Q->rear->e = e;
        p = (Position)malloc(sizeof(aNode));
        Q->rear->next = p;
        Q->rear = p;
        Q->size++;
    }
}

ElementType dequeue(Queue Q)
{
    if (!is_empty(Q))
    {
        Position p = Q->front;
        Q->front = Q->front->next;
        Q->size--;
        return p->e;
    }
}

void put_in_bucket(ElementType e, int time, Queue bucket[])
{
    ElementType i = e;
    while (--time)
    {
        i = i / buckets;
    }

    enqueue(e, bucket[i % buckets]);
}

void print_sort(Queue Q)
{
    while (!is_empty(Q))
    {
        printf("%d,  ", dequeue(Q));
    }
    printf("\n");
}

void stuff_arr(ElementType *arr, Queue bucket[])
{
    int counter = 0;
    for (int i = 0; i < buckets; i++)
    {
        while (!is_empty(bucket[i]))
        {
            arr[counter++] = dequeue(bucket[i]);
        }
    }
}

ElementType *radix_bucket_sort(ElementType *arr, int len, int time)
{
    arr = (ElementType *)malloc(sizeof(ElementType) * len);
    Queue bucket[buckets];
    for (int i = 0; i < buckets; i++)
    {
        bucket[i] = create_queue();
    }
    for (int j = 0; j < time; j++)
    {
        for (int i = 0; i < len; i++)
        {
            put_in_bucket(arr[i], j + 1, bucket);
        }
        stuff_arr(arr, bucket);
    }
    return arr;
}

void bucket_sort()
{
    Queue bucket[buckets];
    /*initialize buckets*/
    for (int i = 0; i < buckets; i++)
    {
        bucket[i] = create_queue();
    }

    srand(time(NULL));
    /*first bucket sort*/
    for (int i = 0; i < 1000; i++)
    {
        int n = 100000000 + rand();
        put_in_bucket(n, 1, bucket);
    }
    /*2nd ~ times sort*/
    for (int i = 1; i < times; i++)
    {
        for (int j = 0; j < buckets; j++) /*O(N + B)*/
        {
            int size = bucket[j]->size;
            while (size--)
            {
                put_in_bucket(dequeue(bucket[j]), i + 1, bucket);
            }
        }
    }

    for (int i = 0; i < buckets; i++)
    {
        print_sort(bucket[i]);
    }
}

int main(void)
{
    ElementType arr[10];
    for (int i = 9; i >= 0; i--)
    {
        arr[i] = pow(i, 3);
    }
    radix_bucket_sort(arr,10,3);
    for (int i = 0; i < 10; i++)
    {
        printf("%2d,",arr[i]);
    }
    
}