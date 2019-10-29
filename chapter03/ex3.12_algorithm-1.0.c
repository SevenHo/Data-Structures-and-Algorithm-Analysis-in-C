#include <stdio.h>
#include <stdlib.h>

/**
 * 链表反转:
 * a.使用栈,但空间消耗大 O(N)
 * b.常数反转 O(N)
 */

#define ElementType int
typedef struct aList
{
    ElementType e;
    struct aList *next;
} * List, *Position;

/**
 * 常数反转
 */
List reverse_list(List L)
{
    Position pp, cp, np;
    /*非空*/
    if (L && L->next)
    {
        pp = NULL;
        cp = L->next;
        np = cp->next;

        while (np)
        {
            cp->next = pp;
            pp = cp;
            cp = np;
            np = np->next;
        }
        cp->next = pp;
        L->next = cp;
    }

    return L;
}

List insert(ElementType e , List L)
{
    if(!L){
        L = malloc(sizeof(struct aList));
        L->e = e;
        L->next = NULL;
        return L;
    }else
    {
       L->next = insert(e,L->next);
    }
    return L;
}

List create_list()
{
    List L = malloc(sizeof(struct aList));
    L->e = -1;
    L->next = NULL;
    return L;
}

void to_string(List L){
    Position P = L;
    while (P)
    {
        printf("%2d,",P->e);
        P = P->next;
    }
    
}

int main(void)
{
    List L = create_list();
    L = insert(1,L);
    L = insert(2,L);
    L = insert(3,L);
    L = insert(4,L);
    L = insert(5,L);
    L = reverse_list(L);
    to_string(L);
}