#include <stdio.h>
#include <stdlib.h>
#include "my_linked_list.h"

List make_empty(List L)
{
    if (L)
    {
        Position p;
        p = L;
        while (p->next != NULL)
        {
            L = p->next;
            free(p);
            p = L->next;
        }
        L->value = 0;
    }
    else
    {
        L = (List)malloc(sizeof(Node));
        L->next = NULL;
        L->value = 0;
    }

    return L;
}

int is_empty(List L)
{
    return L->next == NULL;
}

int is_last(Position p, List L)
{
    return p->next == NULL;
}

Position find(ElementType e, List L)
{
    Position p;
    p = L->next;
    while (p != NULL && p->value != e)
    {
        p = p->next;
    }
    return p;
}

void delete_e(ElementType e, List L, int bool)
{
    Position p = L;
    while (p->next != NULL)
    {
        if (p->next->value == e)
        {
            p->next = p->next->next;
            if (!bool)
            {
                return;
            }
            else
            {
                continue;
            }
        }
        p = p->next;
    }
}

Position find_previous(ElementType e, List L)
{
    Position p = L;
    while (p->next != NULL && p->next->value != e)
    {
        p = p->next;
    }
    return p;
}

void insert(ElementType e, List L, Position p)
{
    Position tmpCell = NULL;
    tmpCell = (Position)malloc(sizeof(Node));
    if (!tmpCell)
    {
        return;
    }
    tmpCell->value = e;
    tmpCell->next = NULL;
    if (p)
    {
        tmpCell->next = p->next;
        p->next = tmpCell;
    }
    else
    {
        Position pt = L;
        while (pt->next != NULL)
        {
            pt = pt->next;
        }
        pt->next = tmpCell;
    }
}

void printf_list(List L)
{
    Position p = L->next;
    printf("\n[");
    while (p)
    {
        printf(format, p->value);
        p = p->next;
    }
    printf("]\n");
}
int main(void)
{
    List L;
    L = make_empty(NULL);
    insert(1, L, NULL);
    insert(2, L, NULL);
    insert(3, L, NULL);
    Position entry = find(2, L);
    insert(0, L, entry);
    Position entry1 = find_previous(0, L);
    insert(-1, L, entry1);
    printf("list is empty : %d\n", is_empty(L));
    printf("3 is last ele : %d\n", is_last(entry1, L));
    delete_e(3, L, 0);
    printf_list(L);
    insert(4, L, NULL);
    insert(4, L, NULL);
    delete_e(4, L, 1);
    printf_list(L);
}