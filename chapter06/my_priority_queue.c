#include <stdio.h>
#include <stdlib.h>
#include "my_priority_queue.h"


struct HeapStruct
{
    int capacity;
    int size;
    ElementType *arr;
};

PriorityQueue initialize_heap(int capacity)
{
    PriorityQueue H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    H->arr = (ElementType *)malloc(sizeof(ElementType) * (capacity+1));
    H->size = 0;
    H->capacity = capacity;
    H->arr[0] = Min;
    return H;
}
int is_full(PriorityQueue H)
{
    return H->size == H->capacity;
}
int is_empty(PriorityQueue H)
{
    return H->size == 0;
}
void destroy_heap(PriorityQueue H)
{
    free(H->arr);
    free(H);
}
void make_empty_heap(PriorityQueue H)
{
    H->size = 0;
}
/**
 * 上滤
 */
void percolate_up(int index, ElementType arr[])
{
    ElementType tmp = arr[index];
    int i;
    for (i = index; arr[i / 2] > tmp; i /= 2)
    {
        arr[i] = arr[i / 2];
    }
    arr[i] = tmp;
}

/**
 * 下滤
 */
void percolate_down(int index, ElementType arr[], int len)
{
    ElementType tmp = arr[index];
    int i,child;
    for (i = index; i*2 <= len;i = child)
    {
        child = 2*i;
        /*有右孩子*/
        if (child!= len && arr[child] > arr[child+1])
        {
            child++;
        }
        /*最后一个元素与当前小孩子比较*/
        if(arr[len] > arr[child])
        {
            arr[i] = arr[child]; /*继续下滤*/
        }else
        {
            break; /*停止下滤*/
        }
    }
    arr[i] = arr[len];
}
void insert(ElementType e, PriorityQueue H)
{
    H->arr[++H->size] = e;
    percolate_up(H->size, H->arr);
}

ElementType delete_min(PriorityQueue H)
{
    ElementType val = H->arr[1];
    percolate_down(1, H->arr,H->size--);
    return val;
}
ElementType find_min(PriorityQueue H)
{
    return H->arr[1];
}

PriorityQueue build_heap(ElementType *arr,int len)
{
    for (int i = len/2; i > 0; i--)
    {   
        int child;
        for (int j = i; j*2 < len; j = child)
        {
            child = 2*j;
            if(2*j != len && arr[child] > arr[child+1])
            {
                child ++;
            }
            if(arr[j] > arr[child])
            {
                int temp = arr[j];
                arr[j] = arr[child];
                arr[child] = temp;
            }else
            {
                break;
            }
            
        }
    }
    PriorityQueue heap = initialize_heap(len);
    free(heap->arr);
    heap->arr = arr;
    heap->capacity = len;
    heap->size = len;
    return heap;
}

int main(void)
{
    PriorityQueue heap ;
    heap = initialize_heap(11);
    insert(13,heap);
    insert(19,heap);
    insert(31,heap);
    insert(16,heap);
    insert(19,heap);
    insert(21,heap);
    insert(68,heap);
    insert(65,heap);
    insert(14,heap);
    insert(26,heap);
    insert(32,heap);

    for (int i = 0; i < 12; i++)
    {
        printf("%d,",heap->arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d,",delete_min(heap));
    }
    destroy_heap(heap);

    /*构建堆*/
    printf("\n");
    ElementType arr[] = {INT_MIN,13,19,31,16,19,21,68,65,14,26,32};
    PriorityQueue PQ = build_heap(arr,11);   

    for (int i = 0; i < 12; i++)
    {
        printf("%d,",PQ->arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%d,",delete_min(PQ));
    }
}