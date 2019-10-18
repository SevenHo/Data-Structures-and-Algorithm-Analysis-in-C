#include <stdio.h>
#include <stdlib.h>
#include "my_doubly_linked_list.h"

/**
 * 求集合交集
 * 初始化p1,p2两个指针分别指向两个链表表头.
 * 元素值相等时,及为交集元素
 * 不等时，较小元素指针向后指向下一个元素，直到遍历完一个链表
 */
void intersection(LinkList L1, LinkList L2)
{
    Position p1 = first_pos(L1);
    Position p2 = first_pos(L2);
    Position tmp = NULL;

    while (p1 && p2)
    {
        if (p1->value < p2->value)
        {
            p1 = next_pos(p1, L1);
        }
        else if (p1->value > p2->value)
        {
            p2 = next_pos(p2, L2);
        }
        else
        {
            if (!tmp || tmp->value != p1->value)
            {
                printf("%d, ", p1->value);
            }
            tmp = p1;
            p1 = next_pos(p1, L1);
            p2 = next_pos(p2, L2);
        }
    }
}

/**
 * 求集合并集
 * 初始化p1,p2两个指针分别指向两个链表表头.
 * 较小元素输出并指向像一个元素，
 * 相等时，输出其中一个元素，并两个指针都向后，直到一个指针为null
 * 遍历未遍历完的链表
 */
void list_union(LinkList L1, LinkList L2)
{
    Position p1 = first_pos(L1);
    Position p2 = first_pos(L2);
    Position temp = NULL;
    Position temp1 = NULL;
    while (p1 && p2)
    {
        if (p1->value < p2->value)
        {
            temp = p1;
            p1 = next_pos(p1, L1);
        }
        else if (p1->value > p2->value)
        {
            temp = p2;
            p2 = next_pos(p2, L2);
        }
        else
        {
            temp = p1;
            p1 = next_pos(p1, L1);
            p2 = next_pos(p2, L2);
        }
        if (!temp1 || temp1->value != temp->value)
        {
            printf("%d, ", temp->value);
            temp1 = temp;
        }
    }
    while (p1)
    {
        if(!temp1 || temp1->value != p1->value)
            printf("%d, ", p1->value);
        temp1 = p1;  
        p1 = next_pos(p1, L1);
    }
    while (p2)
    {
        if(!temp1 || temp1->value != p2->value)
            printf("%d, ", p2->value);
        temp1 = p2;
        p2 = next_pos(p2, L2);
    }
}

int main(void)
{
    LinkList L1 = make_empty(NULL);
    LinkList L2 = make_empty(NULL);

    insert(1, L1, NULL);
    insert(3, L1, NULL);
    insert(4, L1, NULL);
    insert(7, L1, NULL);
    insert(8, L1, NULL);
    insert(8, L1, NULL);

    insert(4, L2, NULL);
    insert(5, L2, NULL);
    insert(7, L2, NULL);
    insert(8, L2, NULL);
    insert(8, L2, NULL);
    insert(8, L2, NULL);
    insert(9, L2, NULL);
    printf("intersection: ");
    intersection(L1, L2);
    printf("\n");
    printf("union: ");
    list_union(L1, L2);
}
