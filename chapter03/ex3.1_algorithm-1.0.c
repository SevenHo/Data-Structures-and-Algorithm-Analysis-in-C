#include<stdio.h>
#include<stdlib.h>
#include"my_linked_list.h"


int main(void)
{
    List L = make_empty(NULL);
    /*code 见 my_linked_list.c*/
    insert(1,L,NULL);
    printf_list(L);
    return 0;
}