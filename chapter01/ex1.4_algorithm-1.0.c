#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 读入一个文件
 * 将该文件中的 # include filename 语句替换为对应的导入文件内容
 * 
 */

/**
 * 处理文件
 */
void processFile(const char *filename);

/**
 * 字符串去除前后空格
 */
void trim(char *str, char *dest);

int main(void)
{

    puts("\n-----------------start--------------------");
    processFile("ex1.4_file.c");
    puts("\n------------------end---------------------");
    return 0;
}

void processFile(const char *filename)
{
    FILE *fp = NULL;
    char buff[1024];
    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("failed to open file");
        exit(1);
    }
    char temp[1024];
    while (fgets(buff, 1024, fp)) // 读到文件尾
    {
        memset(temp, '\0', 1024);
        trim(buff, temp);
        if (strncmp(temp, "#include", 8) == 0)
        {
            char file_name[255];
            /* 获取文件导入名 */
            strncpy(file_name, strchr(temp, '<') + 1, strchr(temp, '>') - strchr(temp, '<') - 1);
            /* 递归检索 */
            processFile(file_name);
        }
        else
        {
            printf(buff);
        }
    }
    fclose(fp);
}

void trim(char *str, char *dest)
{
    int start = 0;
    int end = strlen(str) - 1;

    while (*(str + start) == 32)
    {
        start++;
    }
    if (*(str + end) == '\n' || *(str + end) == '\r')
    {
        end--;
    }
    while (*(str + end) == 32)
    {
        end--;
    }
    int count = end - start + 1;
    if (count < 1 || end == 0)
    {
        return;
    }
    memset(dest, '\0', count + 1);
    strncpy(dest, str + start, count);
}