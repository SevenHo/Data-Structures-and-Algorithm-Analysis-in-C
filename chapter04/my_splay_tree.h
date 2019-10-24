#ifndef _MY_SPLAY_TREE_
#define _MY_SPLAY_TREE_
#define ElementType int
    
    struct SplayTreeNode ;
    typedef struct SplayTreeNode *Position;
    typedef Position SplayTree;
    
    SplayTree insert_splay_tree(ElementType e,SplayTree T);
    Position find_splay_tree(ElementType e,SplayTree T) ;
    SplayTree delete_splay_tree(ElementType e,SplayTree T);
    void dispose_tree(SplayTree T);
#endif