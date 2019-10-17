#include<stdio.h>
#include<stdlib.h>
#include"my_doubly_linked_list.h"

void print_lots(LinkList L,LinkList P)
{
    int counter = 1; //计数L链表的第多少个节点
    Position Lpos = first_pos(L);
    Position Ppos = first_pos(P);
    
    while(Lpos != NULL && Ppos != NULL)
    {
        if (Ppos->value == counter++) //Ppos当前所表示位置与L链表当前位置比较
        {
            printf(format,Lpos->value);
            Ppos = next_pos(Ppos,P);// O(P)
        }
        Lpos = next_pos(Lpos,L); //O(L)
    }
    /* total O(L+P)*/
}

int main(void)
{
    LinkList L = make_empty(NULL);
    LinkList P = make_empty(NULL);
    
    insert(11,L,NULL);
    insert(2,L,NULL);
    insert(33,L,NULL);
    insert(44,L,NULL);
    insert(5,L,NULL);
    insert(66,L,NULL);

    insert(1,P,NULL);
    insert(3,P,NULL);
    insert(4,P,NULL);
    insert(6,P,NULL);

    print_lots(L,P);
    return 0;
}