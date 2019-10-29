#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int capacity;
    int size;
    int front ;
    int rear;
    int *array;
} * Queue, aQueue;

Queue create_queue(int capacity)
{
    capacity++;
    Queue Q = (Queue)malloc(sizeof(aQueue));
    if (!Q)
    {
        exit(1);
    }
    Q->array = (int *)malloc(sizeof(int) * capacity);
    if (!Q->array)
    {
        exit(1);
    }
    Q->capacity = capacity;
    Q->size = 0;
    Q->front = 0;
    Q->rear = 0;

    return Q;
}
int is_full(Queue Q)
{
    return Q->size == (Q->capacity - 1);
}

int is_empty(Queue Q)
{
    return Q->size == 0;
}

void enqueue(int e, Queue Q)
{
    if (!is_full(Q))
    {
        
        Q->array[Q->rear] = e;
        Q->rear = ++Q->rear % Q->capacity;
        Q->size++;
    }
}

int dequeue(Queue Q)
{
    if (!is_empty(Q))
    {
        Q->size++;
        int val = Q->array[Q->front];
        Q->front = ++Q->front % Q->capacity;
        return val;
    }
    
}

int main(void)
{
    int M, N;
    int start = 1;
    scanf("%d %d", &M, &N);
    Queue Q = create_queue(N);
    int counter = N - 1;
    for (int i = 0; i < N; i++)
    {
        enqueue(i+1,Q);
    }
    while (counter--) /*O((M+1)N)*/
    {
        int val;
        for (int i = 0; i < M; i++)
        {
            val = dequeue(Q);
            enqueue(val,Q);
        }
        val = dequeue(Q);
        printf("%d,",val);
    }
    
    printf("\nwinner->>%d",dequeue(Q));
}