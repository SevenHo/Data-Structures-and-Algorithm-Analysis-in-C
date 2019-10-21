#ifndef __MY_AVL_TREE__
#define __MY_AVL_TREE__
    typedef int ElementType;
    typedef struct AvlNode *Position;
    typedef struct AvlNode *AvlTree;

    AvlTree make_empty(AvlTree T);
    int height(Position P);
    Position find(ElementType e,AvlTree T);
    Position find_min(AvlTree T);
    Position find_max(AvlTree T);
    AvlTree insert(ElementType e,AvlTree);
    AvlTree delete_e(ElementType e,AvlTree);
    ElementType retrieve(Position P);
#endif