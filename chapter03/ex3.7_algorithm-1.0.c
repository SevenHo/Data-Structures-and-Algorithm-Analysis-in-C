#include <stdio.h>
#include <stdlib.h>

/**
 * 计算多项式乘积
 */

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

void insert(int coef, int exp, List L)
{
    ptrNode p = (ptrNode)malloc(sizeof(aNode));
    p->coefficient = coef;
    p->exponet = exp;
    p->next = NULL;

    ptrNode temp = L->next;
    ptrNode temp_before = L;
    while (temp)
    {
        // temp = temp->next;
        if (p->exponet > temp->exponet)
        {
            temp_before->next = p;
            p->next = temp;
            break;
        }
        temp_before = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        temp_before->next = p;
    }
}

/**
 * 释放连表空间
 */
void dispose_list(List L)
{
    ptrNode p = L->next;
    ptrNode delcell;
    while (p)
    {
        L->next = p->next;
        delcell = p;
        p = p->next;
        free(delcell);
    }
    free(L);
}

void show_poly(List L)
{
    ptrNode p = L->next;
    while (p)
    {
        printf("%d%c^%d ", p->coefficient, 'X', p->exponet);
        if (p->next && p->next->coefficient > 0)
        {
            printf("+");
        }

        p = p->next;
    }
    printf("\n");
}

/**
 * 将src插入的dest
 */
void merge_list(List dest, List src)
{
    ptrNode d = dest->next;
    ptrNode s = src->next;
    while (d && s) // O(M) M = min(dest,src);
    {
        if (d->exponet == s->exponet)
        {
            d->coefficient *= s->coefficient;
            s = s->next;
            d = d->next;
        }
        else if(d->exponet < s->exponet)
        {
            
            insert(s->coefficient, s->exponet, dest);
            s = s->next;
            
        }else
        {
            d = d->next;
        }        
    }
    if (s)
    {
        while (s)
        {
            insert(s->coefficient,s->exponet,dest);
            s = s->next;
        }
        
    }
    
}

/**
 * O(M^2N^2)
 */
List multiply_poly_alg_a(List L1, List L2, List p_mul)
{
    if (!p_mul)
    {
        p_mul = create_list();
    }
    ptrNode p1 = L1->next;
    ptrNode p2;
    while (p1) // O(M)
    {
        p2 = L2->next;
        while (p2) // O(N)
        {
            /*each of M*N */
            insert(p1->coefficient * p2->coefficient, p1->exponet + p2->exponet, p_mul);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    p1 = p_mul->next;
    while (p1) // O(MN)
    {
        p2 = p1->next;
        ElemenetType exp_count = p1->exponet;
        while (p2 && p2->exponet == exp_count) //O(MN)
        {
            p1->coefficient += p2->coefficient;
            p2 = p2->next;
            p1->next = p2;
        }
        p1 = p2;
    }

    return p_mul;
}

List multiply_poly_alg_b(List p1, List p2, List p_mul)
{
    ptrNode tpr1 = p1->next;
    ptrNode tpr2 = p2->next;
    List tmp_l;

    while (tpr1) //O(M)
    {
        tmp_l = create_list();
        while (tpr2) //O(N)
        {
            insert(tpr1->coefficient * tpr2->coefficient, tpr1->exponet + tpr2->exponet, tmp_l);
            tpr2 = tpr2->next;
        }
        merge_list(p_mul, tmp_l); // O(M)
        dispose_list(tmp_l);
        tpr1 = tpr1->next;
        tpr2 = p2->next;
    }
    return p_mul;
    /*total running time is O(M^2N)*/
}

List multiply_poly_alg_c(List p1, List p2, List p_mul)
{
    // waiting to learn Chapter 7
}

/**
 * 输入多项式
 */ 
List scan_poly()
{
    List p1 = create_list();
    int coef = 0;
        int exp = 0;
        char x = '\0';
        char end = '\0';
        while (x != '\n' && end != '\n')
        {
            scanf("%d%c^%d%c", &coef, &x, &exp, &end);
            // printf("\n[%d%c^%d]", coef, x, exp);
            insert(coef, exp, p1);
        }
    return p1;
}

/**
int main(void)
{
  
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
    // multiply_poly_alg_a(list_arr[0], list_arr[1], p_sum);
    multiply_poly_alg_b(list_arr[0], list_arr[1], p_sum);
    show_poly(p_sum);
    dispose_list(list_arr[0]);
    dispose_list(list_arr[1]);
    dispose_list(p_sum);

    return 0;
}

*/