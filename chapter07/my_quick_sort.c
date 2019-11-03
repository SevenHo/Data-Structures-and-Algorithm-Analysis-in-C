#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define cutoff (3)

void insertion_sort(ElementType arr[], int len)
{
    ElementType tmp;
    for (int p = 1; p < len; p++)
    {
        tmp = arr[p];
        int i;
        for (i = p; i > 0 && arr[i - 1] > tmp; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i] = tmp;
    }
}
void swap(ElementType *a, ElementType *b)
{
    ElementType tmp = *a;
    *a = *b;
    *b = tmp;
}

ElementType median3(ElementType arr[], int left, int right)
{
    int center = (left + right) / 2;
    if (arr[left] > arr[center])
    {
        swap(&arr[left], &arr[center]);
    }
    if (arr[left] > arr[right])
    {
        swap(&arr[left], &arr[right]);
    }
    if (arr[center] > arr[right])
    {
        swap(&arr[center], &arr[right]);
    }
    /* pivot is placed at right-1 */
    swap(&arr[center], &arr[right - 1]);
    return arr[right - 1];
}

void Qsort(ElementType arr[], int left, int right)
{
    int i, j;
    if ((left + cutoff) <= right)
    {
        int pivot = median3(arr, left, right);
        i = left;
        j = right - 1;
        while (1)
        {
            while (arr[++i] < pivot)
            {
            };
            while (arr[--j] > pivot)
            {
            };
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
            else
            {
                break;
            }
        }
        swap(&arr[i], &arr[right - 1]);
        Qsort(arr, left, i - 1);
        Qsort(arr, i + 1, right);
    }
    else
    {
        insertion_sort(arr + left, right - left + 1);
    }
}

/**
 * 快速排序
 */
void quick_sort(ElementType arr[], int len)
{
    Qsort(arr, 0, len - 1);
}

void Qselect(int k, ElementType arr[], int left, int right)
{
    int i , j;
    if((left+cutoff) <= right )
    {
        int pivot = median3(arr,left,right);
        i = left;
        j = right -1;
        while(1)
        {
            while(arr[++i] < pivot){};
            while(arr[--j] > pivot){};
            if(i < j)
            {
                swap(&arr[i],&arr[j]);
            }else
            {
                break;
            }
        }
        swap(&arr[i] , &arr[right - 1]);
        if(k < i)
        {
            Qselect(k,arr,left,i-1);
        }else if(k > i)
        {
            Qselect(k,arr,i+1,right);
        }
         
    }else
    {
        insertion_sort(arr + left,right - left + 1);
    }
    
}
/**
 * 快速选择问题,k th smallest 
 */
ElementType quick_select(int k, ElementType arr[], int len)
{
    Qselect(k-1, arr, 0, len - 1);
    return arr[k - 1];
}

int main(void)
{
    ElementType arr[] = {12, 3, 10, 4, 11, 5, 10, 6, 9, 7, 2, 8, 0, 1, 5, 3, 13};
    printf("-->%d\n",quick_select(1,arr,17));
    for (int i = 0; i < 17; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
    quick_sort(arr, 17);
    for (int i = 0; i < 17; i++)
    {
        printf("%d,", arr[i]);
    }

    return 0;
}