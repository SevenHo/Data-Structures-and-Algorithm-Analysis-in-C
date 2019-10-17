#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "my_stack_list.h"

static char symbol_open[] = "([{";
static char symbol_close[] = ")]}";
int is_match(const char open, const char close)
{
    return (strchr(symbol_open,open) - symbol_open) == (strchr(symbol_close,close) - symbol_close);
}

int main(void)
{

    Stack S = create_stack();

    char input = '\0';
    while (input != '\n')
    {
        input = getchar();
        // printf("%c", input);
        if (strchr(symbol_open, input))
        {
            push(input, S);
        }
        else if (strchr(symbol_close, input))
        {
            if (!is_empty(S))
            {
                char open = top(S);
                if (!is_match(open,input))
                {
                    break ;
                }else
                {
                    pop(S);
                }
                
            }else
            {
                break ;
            }
            
        }
    }
    if(!is_empty(S))
    {
        printf("symbol is not match.\n");
    }else
    {
        printf("success. ^_^\n");
    }
    
    return 0;
}