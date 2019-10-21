#ifndef __MY_BINARY_SEARCH_TREE__
#define __MY_BINARY_SEARCH_TREE__
    typedef int ElementType;
    typedef struct TreeNode *Position;
    typedef struct TreeNode *SearchTree;

    SearchTree make_empty(SearchTree ST);
    Position find(ElementType e,SearchTree ST);
    Position find_min(SearchTree ST);
    Position find_max(SearchTree ST);
    SearchTree insert(ElementType e,SearchTree ST);
    SearchTree delete_e(ElementType e,SearchTree ST);
    ElementType retrieve(Position P);

#endif