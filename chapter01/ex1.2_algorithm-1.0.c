#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  Exercise 1.2:
 *  word puzzle problem
 *  输入n阶的字母矩阵,和单词表
 *  输出字谜中的单词,(水平、垂直、对角线方向)
 */

int main(void)
{
    /* 8个方向移动(x,y) */
    int direction_x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int direction_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    char(*table)[30] = NULL;    //words table
    char **puzzle_board = NULL; // letter board

    int t_size; // the number of words
    int n;      //the dimension of puzzle board

    printf("input the number of words:\n");
    scanf("%d", &t_size);
    table = (char(*)[30])malloc(sizeof(char) * 30 * t_size); // allocate memories to  the table

    /* initialize words of table */
    int i = t_size;
    while (i--)
    {
        scanf("%10s", table + i);
        // printf("%s\n", table + i);
    }

    printf("input the demension of puzzle board:\n");
    scanf("%d", &n);

    /* allocate memories to the puzzle board */
    puzzle_board = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        *(puzzle_board + i) = (char *)malloc(sizeof(char) * n);
    }

    /* initialize the puzzle board */
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        char letter;
        int j = 0;
        while ((letter = getchar()) != '\n' || j < n)
        {
            if (letter != 32)
            {
                *(*(puzzle_board + i) + j) = letter;
                j++;
            }
        }
    }

    /* 遍历检索 */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            /* 向八个方向检索 */
            for (int k = 0; k < 8; k++)
            {
                int x = i;
                int y = j;
                char word[30] = "";
                int index = 0;
                /* 单个方向逐一检索,直到边界 */
                while (x >= 0 && x < n && y >= 0 && y < n)
                {
                    // strcat(word, (*(puzzle_board + x) + y));
                    word[index++] = *(*(puzzle_board + x) + y);
                    x += direction_x[k];
                    y += direction_y[k];
                    // printf("%s\n", word);
                    for (int m = 0; m < t_size; m++)
                    {
                        if (!strcmp(word, table[m]))
                        {
                            printf("-->%s\n", word);
                        }
                    }
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%c", *(*(puzzle_board + i) + j));
    //     }
    // }

    return 0;
}
