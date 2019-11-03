#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char stack[25][10]; int top = 0;
    char queue[25][10]; int front = 0 , rear = 0;
    char name[10] = "";
    int N,s,flag;

    scanf("%d",&N);
    scanf("%d %s",&flag,name);
    strcpy(queue[rear++],name);
    for(int i = 1 ; i < N ; i++)
    {
        scanf("%d %s",&s,name);
        if(s == flag){
            strcpy(queue[rear++],name);
        }else
        {
            strcpy(stack[top++],name);
        }
    }
    while(top)
    {
        printf("%s %s\n",queue[front++],stack[--top]);
    }
}