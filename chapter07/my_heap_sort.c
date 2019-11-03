#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct 
{
    int capacity;
    int size;
    ElementType *arr;
}Heap;

Heap* initialize(int capacity)
{
    Heap* heap = (Heap *)malloc(sizeof(Heap));
    if(!heap)
    {
        exit(1); //error
    }
    heap->arr = (ElementType *)malloc(sizeof(ElementType)*capacity);
    if(!heap->arr)
    {
        exit(1);
    }
    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

/**
 * build a Max heap 
 */
Heap* build_heap(ElementType arr[],int len)
{
    Heap* heap = initialize(len);
    free(heap->arr);
    heap->arr = arr;
    heap->size = len;
    for (int i = len/2 - 1 ; i >= 0; i--)
    {
        int child , j;
        ElementType tmp = arr[i];
        for (j = i; 2*(j+1)-1 < len; j = child)
        {
            child = 2*(j+1) - 1;
            if(child+1 < len && arr[child] < arr[child+1])
            {
                child++;
            }
            if(tmp < arr[child])
            {
                arr[j] = arr[child];
            }else{
                break;
            }
        }
        arr[j] = tmp;
    }
    
    return heap;
}

ElementType delete_min(Heap* heap)
{
    ElementType* arr = heap->arr;
    int *size = &heap->size;
    
    ElementType maxval = arr[0];
    ElementType last_e = arr[*size-1];
    int child,i;
    for (i = 0; 2*(i+1)-1 < *size; i = child)
    {
        child = 2*(i+1)-1;
        if(child + 1 < *size && arr[child] < arr[child + 1])
        {
            child++;
        }
        if(arr[child]> last_e)
        {
            arr[i] = arr[child];
        }else
        {
            break;
        }
    }
    arr[i] = last_e;   
    heap->size--;
    return maxval; 
}

/**
 * 堆排序
 */ 
void heap_sort(ElementType arr[],int len)
{
    Heap* heap = build_heap(arr,len);
    ElementType tmp;
    for (int i = 0; i < len; i++)
    {
       tmp = delete_min(heap);
       heap->arr[heap->size] = tmp;
    }
    
}

int main(void)
{
    ElementType arr[] = {9,8,6,4,3,89,31,12,4,7,1,0};
    heap_sort(arr,12);
    for (int i = 0; i < 12; i++)
    {
        printf("%2d,",arr[i]);
    }
    
    return 0;
}