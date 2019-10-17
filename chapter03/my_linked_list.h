#ifndef __MY_LINKED_LIST__
#define __MY_LINKED_LIST__
#define format "%d,"
typedef int ElementType;
typedef struct aNode
{
    ElementType value;
    struct aNode *next;
} Node;
typedef Node *List;
typedef Node *Position;
/**
     * 将链表置空;L为空,创建一个空链表
     */
List make_empty(List L);
/**
     * 判断链表是否为空
     */
int is_empty(List L);
/**
     * 判断位置 p 是否为最后一个元素
     */
int is_last(Position p, List L);
/**
     * 查找元素e第一次出现的节点,存在返回节点,否则返回NULL
     */
Position find(ElementType e, List L);
/**
     * 删除元素 e
     * boolean 为true全部删除，false只删除第一次出现的e
     */
void delete_e(ElementType e, List L, int boolean);
/**
     * 查找前驱节点,并返回,否则返回NULL
     */
Position find_previous(ElementType e, List L);

/**
     * 插入元素e,位置节点p之后,p为NULL时插入表尾
     */
void insert(ElementType e, List L, Position p);

/**
     * 打印链表
     */
void printf_list(List L);

/**
 * 第一个节点
 */ 
Position first_pos(List L);
/**
 * 下一个节点
 */ 
Position next_pos(Position P,List L);
#endif