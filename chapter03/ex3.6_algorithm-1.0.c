#include <stdio.h>
#include <stdlib.h>

typedef int ElemenetType;
typedef struct Node *ptrNode;
typedef ptrNode List;

typedef struct Node
{
    ElemenetType coefficient; // 系数
    ElemenetType exponet;     // 指数
    ptrNode next;
} aNode;

List create_list()
{
    List L = NULL;
    L = (List)malloc(sizeof(aNode));
    if (!L)
        exit(1);
    L->next = NULL;
    L->coefficient = 0;
    L->exponet = 0;

    return L;
}

/**
 * 插入多项式
 */
void insert(int coef, int exp, List L)
{
    ptrNode p = (ptrNode)malloc(sizeof(aNode));
    p->coefficient = coef;
    p->exponet = exp;
    p->next = NULL;

    ptrNode temp = L;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = p;
}

/**
 * 释放连表空间
 */
void dispose_list(List L)
{
    ptrNode p = L->next;
    while (p)
    {
        L->next = p->next;
        free(p);
        p = p->next;
    }
    free(L);
}

/**
 * 多项式相加
 */
List add_polynomial(const List p1, const List p2, List p_sum)
{
    if (!p_sum)
    {
        p_sum = create_list();
    }
    ptrNode tp1 = p1->next;
    ptrNode tp2 = p2->next;
    /*从高阶到低阶相加*/
    while (tp1 && tp2)
    {
        if (tp1->exponet == tp2->exponet)
        {
            if(tp1->coefficient + tp2->coefficient)
                insert(tp1->coefficient + tp2->coefficient, tp1->exponet, p_sum);
            tp1 = tp1->next;
            tp2 = tp2->next;
        }
        else if (tp1->exponet > tp2->exponet)
        {
            insert(tp1->coefficient, tp1->exponet, p_sum);
            tp1 = tp1->next;
        }
        else
        {
            insert(tp2->coefficient, tp2->exponet, p_sum);
            tp2 = tp2->next;
        }
    }
    /*未遍历完的多项式链表*/
    ptrNode rest = tp1 != NULL ? tp1 : tp2;
    while (rest)
    {
        insert(rest->coefficient, rest->exponet, p_sum);
        rest = rest->next;
    }

    return p_sum;
}

void show_poly(List L)
{   
    ptrNode p = L->next;
    while (p)
    {
        printf("%d%c^%d ", p->coefficient, 'X', p->exponet);
        if(p->next && p->next->coefficient > 0)
        {
            printf("+");
        }

        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    /**
     * T = O(M+N);
     */ 

    List p1 = create_list();
    List p2 = create_list();
    List p_sum = create_list();

    List list_arr[2] = {p1, p2};
    //输入格式 10x^100 +5x^14 -1x^1 +1x^0
    for (int i = 0; i < 2; i++)
    {
        int coef = 0;
        int exp = 0;
        char x = '\0';
        char end = '\0';
        while (x != '\n' && end != '\n')
        {

            scanf("%d%c^%d%c", &coef, &x, &exp, &end);
            // printf("\n[%d%c^%d]", coef, x, exp);
            insert(coef, exp, list_arr[i]);
        }
    }
    // show_poly(list_arr[0]);
    // show_poly(list_arr[1]);
    add_polynomial(list_arr[0], list_arr[1], p_sum);
    show_poly(p_sum);
    dispose_list(list_arr[0]);
    dispose_list(list_arr[1]);
    dispose_list(p_sum);

    return 0;
}
