#ifndef _MY_BIN_QUEUE_
    #define ElementType int
    #define Max_Trees 8
    typedef struct BinNode *Position;
    typedef struct BinNode *BinTree;
    typedef struct Collection *BinQueue;

    BinQueue initialize();
    is_empty(BinQueue H);
    void insert(ElementType x,BinQueue H);
    ElementType find_min(BinQueue H);
    void delete_min(BinQueue H);
    BinQueue Merge(BinQueue H1,BinQueue H2);
    void destroy(BinQueue H);
#endif