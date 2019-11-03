#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ElementType int

void merge(ElementType src[], ElementType dest[], int Lpos, int Rpos, int end)
{
    int Lend = Rpos - 1;
    int count = 0;
    int tmpLpos = Lpos;
    while (Lpos <= Lend && Rpos <= end)
    {
        if (src[Lpos] < src[Rpos])
        {
            dest[count++] = src[Lpos++];
        }
        else
        {
            dest[count++] = src[Rpos++];
        }
    }
    int index, iend;
    if (Lpos > Lend)
    {
        index = Rpos;
        iend = end;
    }
    else
    {
        index = Lpos;
        iend = Lend;
    }
    while (index <= iend)
    {
        dest[count++] = src[index++];
    }

    for (int i = 0; i < count; i++)
    {
        src[i + tmpLpos] = dest[i];
    }
}

void m_sort(ElementType A[], ElementType B[], int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        m_sort(A, B, left, center);
        m_sort(A, B, center + 1, right);
        merge(A, B, left, center + 1, right);
    }
}

/**
 * 归并排序
 */
void merge_sort(ElementType arr[], int len)
{
    ElementType *tmparr = malloc(sizeof(ElementType) * len);
    if (!tmparr)
    {
        exit(1); //error
    }

    m_sort(arr, tmparr, 0, len - 1);
    free(tmparr);
}

int main(void)
{
    ElementType arr[] = {7,6,5,4,3,2,1,0,7,12,11,10,9,8};
    merge_sort(arr,14);
    for (int i = 0; i < 14; i++)
    {
        printf("%2d, " , arr[i]);
    }
 
    return 0;
}