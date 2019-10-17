#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_stack_list.h"

char static operators[] = "+-*/";

int find_index(char operator)
{
    char *index = strchr(operators, operator);
    if (index)
    {
        return index - operators;
    }
    return -1;
}
int is_operator(char operator)
{
    return strchr(operators, operator) != NULL;
}
int main(void)
{
    Stack S = create_stack();
    char input = '\0';
    while ((input = getchar()) != '\n')
    {
        if(input == 32){
            continue;
        }
        if (is_operator(input))
        {
            int b = top_pop(S);
            int a = top_pop(S);
            switch(find_index(input))
            {
                case 0 : push(a+b,S); 
                break;
                case 1 : push(a-b,S); 
                break;
                case 2 : push(a*b,S); 
                break;
                case 3 : push(a/b,S); 
                break;
                default : exit(1);
            }
        }else
        {
            input -= 48;
            // printf("%d,",input);
            push(input,S);
        }
        
    }
    printf("result = %4d,",top(S));
    dispose_stack(S);
    return 0;
}