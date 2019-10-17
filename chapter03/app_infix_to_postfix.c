#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_stack_list.h"

char static operator_level[][7] = {
                            {"(*/+-)"},
                            {"122334"}
                            };

int find_leve(const char operator)
{
    char *index = strchr(operator_level[0],operator);
    if(index){
        return operator_level[1][index-operator_level[0]] + 48;
    }
    return 0;
}

int is_operator(char operator)
{
    return strchr(operator_level[0],operator) != NULL;
}

void print_stack(Stack S)
{
    while(!is_empty(S))
    {
        printf("%c ",top_pop(S));
    }
}

int main(void ){

    
    Stack S = create_stack();                 

    char input = '\0';
    while ((input =getchar()) != '\n')
    {
        if(is_operator(input)) //非操纵符
        {
            if(is_empty(S)) //栈为空直接入栈
            {
                push(input,S);
                continue;
            }
            char operator = top(S); //此时栈顶操作符
            if(input==')') //遇见右括号，栈中左括号之前的全部出栈
            {
                while (top(S) != '(')
                {   
                    printf("%c ",top_pop(S));
                }
                pop(S);
            }else if (operator == '(') // 右括号拥有最高优先级，直接入栈
            {
                push(input,S);
            }else
            {   /*读入的操作符，比栈顶操作符的优先级低或相等时，出栈。不处理 右括号时，左括号不出栈*/
                while(!is_empty(S)&&top(S) != '('&&(find_leve(input)>=find_leve(top(S))))
                {
                    printf("%c ",top_pop(S));
                }
                push(input,S); // 读入操作符入栈
            }
            
            
        }else
        {
            printf("%c ",input);
        }
        
    }
    print_stack(S); // 输入结束，剩余操作符全部被出栈
    
    return 0;
}