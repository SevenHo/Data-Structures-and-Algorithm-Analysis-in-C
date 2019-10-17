#ifndef __MY_DOUBLY_LINKED_LIST__
#define __MY_DOUBLY_LINKED_LIST__
#define format "%d,"
typedef int ElementType;
typedef struct aNode
{
    ElementType value;
    struct aNode *prior;
    struct aNode *next;
} Node;
typedef Node *LinkList;
typedef Node *Position;

/**
     * 创建一个空链表,或删除链表
     */
LinkList make_empty(LinkList L);
/**
     * 判断链表是否为空
     */
int is_empty(LinkList L);
/**
     * 判断是否为最后一个元素
     */
int is_last(Position p, LinkList L);
/**
     * 插入元素,指定节点或链表尾
     */
void insert(ElementType e, LinkList L, Position p);
/**
     * 删除元素节点,true 全部,false 第一次出现
     */
void delete_e(ElementType e, LinkList L, int boolean);
/**
 * 查找元素第一次出现的位置节点
 */
Position find(ElementType e, LinkList L);
/**
 * 链表第一个元素
 */
Position first_pos(LinkList L);
/**
 * P位置下一个元素
 */ 
Position next_pos(Position P , LinkList L);
/**
 * 打印链表
 */
void print_list(LinkList L);
#endif