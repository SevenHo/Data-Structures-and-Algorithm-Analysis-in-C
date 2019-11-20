#include <stdio.h>
#include <stdlib.h>
#include "my_disjoint_set.h"

/**
 * 初始化为集合大小的负数
 */ 
void initialize(DisjSet S)
{
    for (int i = 1; i <= NumSets; i++)
    {
        /*当按高度求并时，不影响高度比较，可以认为所有的树高度为-1*/
        S[i] = -1;
    }
}
/**
 * union by size
 */ 
void setUnionBySize(DisjSet S, SetType root1, SetType root2)
{
    if(S[root1] < S[root2])
    {
        S[root1] += S[root2];
        S[root2] = root1;
    }else
    {
        S[root2] += S[root1];
        S[root1] = root2;
    }
    
}
void setUnionByHeight(DisjSet S , SetType root1 , SetType root2)
{
    if(S[root1] < S[root2])
    {
        S[root2] = root1;
    }else 
    {
        S[root2] = root1;
        /*update height*/
        if(S[root1] == S[root2])
            S[root1] --;
    }
}

/*查找元素属于那个集合*/
ElementType find(ElementType x, DisjSet S)
{
    if(S[x] <= 0)
    {
        return x;
    }else
    {
        return find(S[x],S);
    }
    
}
