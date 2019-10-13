#include <stdio.h>
#include <stdlib.h>
#include "my_cursor_list.h"
#define NULL 0

static int size = 0;
static Node *CursorSpace = NULL;

/**
 * 分配节点空间
 */
static Position CursorAlloc(void)
{
    Position p;
    p = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[p].next;
    CursorSpace[p].next = NULL;
    return p;
}

/**
 * free节点空间
 */
static void CursorFree(Position p)
{
    CursorSpace[p].next = CursorSpace[0].next;
    CursorSpace[0].next = p;
}

/**
     * 初始化CursorSpace数组
     */
Node *init_cursor_space(int _size)
{
    CursorSpace = (Node *)malloc(sizeof(Node) * _size);
    if (!CursorSpace)
    {
        exit(1);
    }
    size = _size;
    for (int i = 0; i < _size - 1; i++)
    {
        (CursorSpace + i)->next = i + 1;
    }
    (CursorSpace + _size - 1)->next = 0;

    return CursorSpace;
}
/**
     * 将链表置空,创建新的空表
     */
List make_empty(List L)
{
    Position p, temp;
    if (L)
    {
        p = L;
        while ((temp = CursorSpace[p].next))
        {

            CursorFree(p);
            p = temp;
        }
        return L;
    }
    else
    {
        if (size)
        {
            return CursorAlloc();
        }
        else
        {
            exit(1);
        }
    }
}
/**
     * 判断是否为空表
     */
int is_empty(const List L)
{
    return CursorSpace[L].next == 0;
}
/**
     * 判断p是否为最后一个元素
     */
int is_last(const Position p, const List L)
{
    return CursorSpace[p].next == 0;
}
/**
     * 查找元素e
     */
Position find(ElementType e, const List L)
{
    Position p;
    p = L;
    if (p)
    {
        p = CursorSpace[p].next;
        while (p && CursorSpace[p].value != e)
        {
            p = CursorSpace[p].next;
        }
        return p;
    }
}
/**
     * 删除元素e , boolean 为 true 全部删除, false 只删除第一次出现的
     */
void delete_e(ElementType e, List L, int boolean)
{
    Position p = L;
    if (p)
    {
        Position prior = p;
        p = CursorSpace[p].next;
        while (p)
        {
            if (CursorSpace[p].value == e)
            {
                CursorSpace[prior].next = CursorSpace[p].next;
                CursorFree(p);
                if (!boolean)
                {
                    break;
                }
                else
                {
                    p = CursorSpace[prior].next;
                    continue;
                }
            }
            prior = p;
            p = CursorSpace[p].next;
        }
    }
}
/**
     * 查找p的前驱节点
     */
Position find_previous(Position p, const List L)
{
    Position temp = L;
    while (CursorSpace[temp].next && CursorSpace[temp].next != p)
    {
        temp = CursorSpace[temp].next;
    }
    return temp;
}
/**
     * 插入元素 , p为空插入表尾
     */
void insert(ElementType e, List L, Position p)
{
    Position tmpCell = CursorAlloc();
    CursorSpace[tmpCell].value = e;
    CursorSpace[tmpCell].next = 0;
    Position temp;
    if (p)
    {
        temp = find_previous(p, L);
        CursorSpace[temp].next = tmpCell;
        CursorSpace[tmpCell].next = p;
    }
    else
    {
        temp = L;
        while (CursorSpace[temp].next)
        {
            temp = CursorSpace[temp].next;
        }
        CursorSpace[temp].next = tmpCell;
    }
}
/**
     * 删除链表
     */
void delete_list(List L)
{
    free(CursorSpace);
}
/**
 * 打印表
 */
void print_list(List L)
{
    Position p = CursorSpace[L].next;
    printf("\n[");
    while (p)
    {
        printf("%d,", CursorSpace[p].value);
        p = CursorSpace[p].next;
    }
    printf("]\n");
}
int main(void)
{
    List L;
    init_cursor_space(10);
    L = make_empty(NULL);
    insert(1, L, NULL);
    insert(2, L, NULL);
    insert(3, L, NULL);
    printf("\n%d", is_empty(L));
    Position p = find(3, L);
    printf("\n%d", is_last(p, L));
    insert(4, L, p);
    insert(4, L, p);
    insert(4, L, p);
    insert(4, L, NULL);
    delete_e(4, L, 0);
    print_list(L);
    delete_e(4, L, 1);
    print_list(L);
    delete_list(L);
    return 0;
}