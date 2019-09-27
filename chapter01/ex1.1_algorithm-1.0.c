#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sel_problem_2(int *list, int N, int k);


/*
    selection problem
    有一组 N 个数而要确定其中第 k 个最大数

----algorithm_1.0
    将 N 个数全部 载入数组list , 然后排序（降序）, 返回数组第 k 个元素
*/
int sel_problem_1(int *list, int N, int k);

/**
 *  Bubble Sort 
 *  冒泡排序
 */
extern void bubble_sort(int *array, int length);

/**
 * 打印数组
 * 
 */
void array_print(int *array, int length);

int main(void)
{
    int N = 0, k = 0; // N 个数，第k个大
    time_t t;
    srand((unsigned)time(&t));

    int *list; //数组指针
    
    printf(" input number N , K : \n");
    scanf("%d %d", &N, &k);

    time_t start_time = time(NULL);
    list = (int *)malloc(sizeof(int) * N); // 初始化N个int大小的空间

    int randnum;
    int *list_temp;
    list_temp = list;
    for (int i = 0; i < N; i++)
    {
        /* 随机产生N个数，存入数组list */
        randnum = rand() % 1000;
        *list_temp++ = randnum;
        // list_temp ++ ;
    }
    // array_print(list, N);
    // int array[] = {1,2,3,4,5,6,7,8,9,10,11};
    // list = array;
    k = sel_problem_1(list, N, k);

    printf("\nnumber of NO.k : %4d\n", k);
    // array_print(list, N);
    time_t end_time = time(NULL);

    printf("\ntotal time : %d \n", end_time - start_time);

    // free(list);

    // getchar();
    // getchar();
    return 0;
}


int sel_problem_1(int *list, int N, int k)
{
    bubble_sort(list, N);
    return *(list + k - 1);
}

void bubble_sort(int *array, int length)
{
    int size = length;
    int min_index = length - 1, max_index = 0;

    for (int i = 0; i < size / 2; i++)
    {
        /* 双向冒泡 */
        for (int j = i + 1; j < size - i; j++)
        { /* 寻找最大,最小元素下边 */
            if (*(array + max_index) < *(array + j))
            {
                max_index = j;
            }
            if (*(array + min_index) > *(array + j - 1))
            {
                min_index = j - 1;
            }
        }
        /* 最大和最小元素索引有交叉指向时,增加判断标志 */
        int flag = -1;
        if (max_index == size - i - 1)
        {
            flag = *(array + max_index);
        }
        /* 未排序的最小元素排序 */
        int temp = *(array + size - i - 1);
        *(array + size - i - 1) = *(array + min_index);
        *(array + min_index) = temp;

        /* 交叉情况处理 */
        if (flag == -1)
        { /* 未交叉情况 */
            temp = *(array + max_index);
            *(array + max_index) = *(array + i);
            *(array + i) = temp;
        }
        else
        { /* 交叉情况 */
            *(array + min_index) = *(array + i);
            *(array + i) = temp;
        }

        min_index = size - i - 1 - 1; //游标向前移动
        max_index = i + 1;            // 游标向后移动

        // array_print(array, size);
    }
}

void array_print(int *array, int length)
{
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        /* code */
        printf("%8d ", *(array + i));
    }
    printf("\n");
}