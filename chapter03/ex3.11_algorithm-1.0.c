#include <stdio.h>
#include <stdlib.h>

#define ElementType int
typedef struct aList
{
    ElementType e;
    struct aList *next;
} * List, *Position;

/**
 * 递归查找，元素大致在4500个时，栈就会溢出
 */
Position find_recursive(ElementType e, List L)
{
    if (L)
    {
        if (e == L->e)
        {
            return L;
        }
        else
        {
            return find_rcursive(e, L->next);
        }
    }
    return NULL;
}

/**
 * 非递归
 */

Position find_nonrecursive(ElementType e, List L)
{
    if (L)
    {
        Position p = L->next;
        while (p)
        {
            if (p->e == e)
            {
                return p;
            }
            p = p->next;
        }
    }
}