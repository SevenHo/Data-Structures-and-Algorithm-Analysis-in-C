#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Exercise 1.3:
 * 只使用处理I/O的printDigit 函数,编写一个过程可以输出任意实数
 *  
 */

/**
 * 只能打印单个数字
 */
void printDigit(int digit);

/**
 * 打印整数
 */
void printInteger(int N);

/**
 * 打印实数
 */
void printReal(double R, int dec);

int main()
{
    double N;
    int dec_places;
    scanf("%lf%d", &N, &dec_places);
    //printInteger(dec_places);
    printReal(N, dec_places);
    return 0;
}

void printDigit(int digit)
{
    if (digit >= 0 && digit < 10)
    {
        digit += 48; // '0'
        putchar(digit);
    }
}

void printInteger(int N)
{
    if (N < 0)
    {
        putchar('-');
        N = -N;
    }

    if (N >= 10)
    {
        printInteger(N / 10); //递归
    }

    printDigit(N % 10);
}

void printReal(double R, int dec)
{

    if (R < 0)
    {
        R = -R;
        putchar('-');
    }
    int IntPart = (int)R;
    double around_to_add = 0.5 * pow(10, -dec); //有效位小数位加1,避免浮点数四舍五入机制的问题
    double FractionPart = R - IntPart;

    printInteger(IntPart);
    if (FractionPart > 0)
    {
        FractionPart += around_to_add;
        putchar('.');
        for (int i = 0; i < dec; i++)
        {
            FractionPart *= 10;
            // FractionPart %= 10;
            printInteger(((int)FractionPart) % 10);
            // printf("\n%lf\n",FractionPart);
        }
    }
}