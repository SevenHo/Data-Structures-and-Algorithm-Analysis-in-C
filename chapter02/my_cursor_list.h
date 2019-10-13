#ifndef __MY_CURSOR_LIST__
#define __MY_CURSOR_LIST__
    typedef int ElementType;
    typedef int entry; // 一个节点就是一个数组元素
    typedef entry Position; 
    typedef entry List; // 表头
    typedef struct CursorNode{
        ElementType value ;
        Position next ;
    }Node;
    /**
     * 初始化CursorSpace数组
     */ 
    Node* init_cursor_space(int size);
    /**
     * 将链表置空,创建新的空表
     */ 
    List make_empty(List L);
    /**
     * 判断是否为空表
     */ 
    int is_empty(const List L);
    /**
     * 判断p是否为最后一个元素
     */ 
    int is_last(const Position p ,const List L);
    /**
     * 查找元素e
     */ 
    Position find(ElementType e , const List L);
    /**
     * 删除元素e , boolean 为 true 全部删除, false 只删除第一次出现的
     */ 
    void delete_e(ElementType e , List L , int boolean);
    /**
     * 查找p的前驱节点
     */ 
    Position find_previous(Position p , const List L);
    /**
     * 插入元素 , p为空插入表尾
     */ 
    void insert(ElementType e , List L,Position p);
    /**
     * 删除链表
     */ 
    void delete_list(List L);
#endif