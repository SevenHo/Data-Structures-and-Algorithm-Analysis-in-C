#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void alg_1(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum++;
    }
    printf("\nsum1 = %4d\n",sum);
}

void alg_2(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum++;
        }
        
    }
    printf("\nsum2 = %4d\n",sum);
}

void alg_3(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N*N; j++)
        {
            sum++;
        }
        
    }
    printf("\nsum3 = %4d\n",sum);
}

void alg_4(int N )
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum++;
        }
        
    }
    printf("\nsum4 = %4d\n",sum);
    
}

void alg_5(int N)
{
    int sum = 0 ;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i*i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                sum++;
            }
            
        }
        
    }
    printf("\nsum5 = %4d\n",sum);
    
}

void alg_6(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i*i; j++)
        {
            if (j%i == 0)
            {
                for (int k = 0; k < j; k++)
                {
                    sum++ ;
                }
                
            }
            
        }
        
    }
    printf("\nsum6 = %4d\n",sum);
    
}

int main(void)
{
    time_t t ;
    int start = 0 ;
    int end = 0 ;
    int N = 0;
    scanf("%d",&N);
    
    start = time(NULL);
    alg_1(N);
    end = time(NULL);
    printf("\nalg_1 times = %d\n",end - start);

    start = time(NULL);
    alg_2(N);
    end = time(NULL);
    printf("\nalg_2 times = %d\n",end - start);

    start = time(NULL);
    alg_3(N);
    end = time(NULL);
    printf("\nalg_3 times = %d\n",end - start);

    start = time(NULL);
    alg_4(N);
    end = time(NULL);
    printf("\nalg_4 times = %d\n",end - start);

    start = time(NULL);
    alg_5(N);
    end = time(NULL);
    printf("\nalg_5 times = %d\n",end - start);

    start = time(NULL);
    alg_6(N);
    end = time(NULL);
    printf("\nalg_6 times = %d\n",end - start);
    return 0;
}