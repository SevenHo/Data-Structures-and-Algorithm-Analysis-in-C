#ifndef _DISJ_SET_
#define NumSets 10
    typedef int DisjSet[NumSets + 1];
    typedef int SetType;
    typedef int ElementType;

    void initialize(DisjSet S);
    void setUnion(DisjSet S , SetType root1 , SetType root2);
    ElementType find(ElementType x,DisjSet S);
#endif