#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 声明函数原型 */
void bubble_sort(int *array,int length) ;
void arrary_print(int *array, int length);

/*
    selection problem
    有一组 N 个数而要确定其中第 k 个最大数

----algorithm_2.0
    将 N 个数, 将前k个载入数组list , 然后排序（降序）
    将 N-k 个数逐一插入到list正确的位置,最后返回数组第 k 个元素
*/
int sel_problem_2(int *list , int N , int k);

/**
 *  insert_array
 *  插入元素e到降序数组的合适位置
 */ 
void insert_array(int *array ,int length, int e);


int main(void)
{   
    int N , k ;
    time_t t;
    int *list = NULL;
    srand(time(&t));

    printf("enter number N,k :\n");
    scanf("%d %d",&N , &k);

    time_t start_time = time(NULL);
    list = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        *(list + i) = rand();
    }
    k = sel_problem_2(list, N , k);
    time_t end_time = time(NULL);
    printf("\nnumber of NO.k : %d\n" , k);
    printf("\ntotal time is : %d s", end_time - start_time);

    return 0;
}

int sel_problem_2(int *list , int N , int k )
{   
    bubble_sort(list, k );
    for (int i = k; i < N; i++)
    {   
        if(*(list + i) >  *(list + k - 1))
        {   //大于第k个数才需要插入
            insert_array(list , k , *(list + i));
        }
    }
    
    return *(list+k-1);
}

void insert_array(int *array ,int length , int e )
{
    for (int i = 0; i < length; i++)
    {
        if(*(array+i) < e)
        {
            for (int j = length -1 ; j > i; j--)
            {
                *(array+j) = *(array + j - 1);
            }
            *(array+i) = e;
        }
    }
    
}
