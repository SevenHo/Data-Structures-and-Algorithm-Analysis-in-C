#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex3.7_algorithm-1.0.c"

int transfer(int p)
{
    int exp[21] = {0};
}

/**
 * 计算多项式L的p次幂 //  0 < p < 20^20
 */
List multiply_poly_exp(int p , List poly)
{
    List result , tmp ,tmpbackup;
    int counter = 1;
    int q = 0, r;
    result = create_list();
    tmp = create_list();
    insert(1,0,result);
    merge_list(tmp,poly);
    /*O(P)*/
    while (1)
    {
        q = p/2;
        r = p%2;
        p = q;
        if(r == 1)
        {   
            List res_tmp , res_tmp1;
            res_tmp = create_list();
            res_tmp1 = result;
            result = multiply_poly_alg_b(result,tmp,res_tmp);
            dispose_list(res_tmp1);
        }
        tmpbackup = tmp;
        if(p == 0 && r == 0){
            dispose_list(tmpbackup);
            break;
        }
        /* O(M^2N),M为较短多项式长度，N为较长多项式长度 */
        tmp = multiply_poly_alg_b(tmp, poly,create_list()); 
        dispose_list(tmpbackup);
    }

    return result ;
}

int main(void)
{
    int p;
    List poly = scan_poly();
    scanf("%d",&p);
    poly = multiply_poly_exp(p,poly);
    show_poly(poly);
    return 0;
}