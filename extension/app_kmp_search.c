#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 求 next 数组
 */
void solve_next(char pattern[], int next[], int len)
{

    int i = 0; // head
    int j = 1; // tail

    next[0] = 0; // 固定值

    while (j < len)
    {
        if (pattern[i] == pattern[j]) /*前后缀匹配*/
        {
            next[j] = next[j - 1] + 1;
            j++;
            i++;
        }
        else
        {
            // i = next[i-1];
            while (i && (i = next[i - 1]) >= 0)
            {
                if (pattern[i] == pattern[j])
                {
                    next[j++] = next[i] + 1;
                    break;
                }
            }
            if (i == 0 && pattern[i] != pattern[j]) // i == 0
            {
                next[j] = 0;
                j++;
            }
        }
    }
}

/**
 * 字符检索，kmp
 */
void kmp_search(char text[], char pattern[])
{
    int len = strlen(pattern);
    int *next = (int *)malloc(sizeof(int));
    solve_next(pattern, next, len);

    int m = strlen(text); // text length
    int t = 0;            // text[t]
    int p = 0;            // pattern[p]

    while (t < m)
    {
        if (text[t] == pattern[p])
        {
            t++;
            p++;
        }
        else
        {
            if (p)
            {
                p = next[p - 1];
            }
            else
            {
                t++;
            }
        }
        if (p == len)
        {
            printf("found pattern at %d\n", t - p);
            p = 0;
            t = t - len + 1;
        }
    }
}

int main(void)
{
    char pattern[] = "aabaa";
    char text[] = "abaaabaabaaabaa";
    int len = 5;
    int next[5];

    kmp_search(text,pattern);

    solve_next(pattern, next, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ,", next[i]);
    }

    return 0;
}