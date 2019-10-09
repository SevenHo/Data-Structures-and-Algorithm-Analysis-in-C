#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * 打印数组
 */
void array_print(const int[], int);

/**
 * 算法1
 */
void alg_1(int[], int);

/**
 * 算法2
 */
void alg_2(int[], int);

/**
 * 算法3
 */
void alg_3(int[], int);

/**
 * 交换函数
 */
void swap(int *, int *);

/**
 * 产生[a,b]范围的随机正整数数，0<a<b
 */
int rand_int(int a, int b);

int main(void)
{
    time_t t;
    int N = 0;
    int *array = NULL;
    scanf("%d", &N);

    array = (int *)malloc(sizeof(int) * N);

    if (!array)
    {
        printf("error:allocated memories!");
        exit(0);
    }
   
    // printf("%d",sizeof(int));
    // printf("%u",INT_MAX);
    int start = time(NULL);
    alg_1(array, N);
    // array_print(array, N);
    int end = time(NULL);
    printf("\ntotal time1 is %d", end - start);

    start = time(NULL);
    alg_2(array, N);
    // array_print(array, N);
    end = time(NULL);
    printf("\ntotal time2 is %d", end - start);

    start = time(NULL);
    alg_3(array, N);
    // array_print(array, N);
    end = time(NULL);
    printf("\ntotal time3 is %d", end - start);

    free(array);
    return 0;
}

void alg_3(int array[], int length)
{
    int temp = 0;
    time_t t;
    srand(t);
    for (int i = 0; i < length; i++)
    {
        array[i] = i + 1;
    }

    for (int i = 0; i < length; i++)
    {
        temp = rand_int(0, length - 1);
        swap(&array[i], &array[temp]);
    }
}

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void alg_2(int array[], int length)
{
    int temp = 0;
    time_t t;
    int *used = NULL;
    used = (int *)malloc(sizeof(int) * length + 1);
    if (!used)
    {
        printf("\n error \n");
        exit(0);
    }
    
    for (int i = 0; i < length+1; i++)
    {
        *(used+i) = 0;
    }
    
    srand(t);
    
    for (int i = 0; i < length; i++)
    {   int count = 0;
        do
        {
            /*由于C产生的是伪随机数,当范围超出Rand_MAX时会导致一些数无法模拟造成死循环*/
            temp = rand_int(1, length);
            count++;
        } while (*(used+temp) == 1);
        
        array[i] = temp;
        used[temp] = 1;
    }
    free(used);
}

void alg_1(int array[], int length)
{
    time_t t;
    srand(t);
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        int j = 0;
        temp = rand_int(1,length);
        while (j != i)
        {
            for (j; j < i; j++)
            {
                if (array[j] == temp)
                {
                    temp = rand_int(1, length);
                    j = 0;
                    break;
                }
            }
        }
        array[i] = temp;
    }
}

void array_print(const int array[], int length)
{
    printf("\n[");
    for (int i = 0; i < length - 1; i++)
    {
        printf("%4d,", array[i]);
    }
    printf("%4d]\n", array[length - 1]);
}

int rand_int(int a, int b)
{   
    return (int) round(1.0*rand()/(RAND_MAX+1)*(b-a)+a);
}