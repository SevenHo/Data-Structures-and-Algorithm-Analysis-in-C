#include <stdio.h>
#include <stdlib.h>
#include "my_doubly_linked_list.h"
// #include "my_linked_list.h" /*单链表时头文件*/

/**
 * 单链表时使用单链表头文件和swap_next()方法。双链表的注释
 * 双链表时使用双链表头文件和swap_next_d()方法。单链表的注释
 */ 

/*单链表L, p与p next 交换 */
void swap_next(Position P, List L)
{
    Position P_before = find_previous(P->value,L);
    Position P_after = P->next;
    P_before->next = P_after;
    P->next = P_after->next;
    P_after->next = P;
}
/*双链表,p与p next 交换*/
void swap_next_d(Position P , LinkList L)
{
    Position P_before = P->prior;
    Position P_after = P->next;
    
    if(P_after){ // P 为尾节点
        if(P_before) // P为头节点
        {
            P_before->next = P_after;
        }
        P_after->prior = P_before;
        P->next = P_after->next;
        P_after->next = P;
        P->prior = P_after;
        if(P_after->next){
            P_after->next->prior = P;
        }
    }
}

int main(void)
{   
    /**
     * 单行注释内容为检验单链表交换
     */

    LinkList L = make_empty(NULL);
    // List L = make_empty(NULL);
    insert(1,L,NULL);
    insert(2,L,NULL);
    // insert(3,L,NULL);
    // printf_list(L);
    print_list(L);
    swap_next_d(first_pos(L),L);
    swap_next(first_pos(L),L);
    // swap_next(first_pos(L),L);
    // printf_list(L);
    print_list(L);
    return 0;
}