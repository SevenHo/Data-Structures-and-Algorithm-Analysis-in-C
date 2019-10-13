#ifndef __MY_QUEUE_ARRAY__
#define __MY_QUEUE_ARRAY__
    typedef int ElementType;
    struct QueueRecord;
    typedef struct QueueRecord *Queue;

    /**
     * 判断是否为空
     */ 
    int is_empty(Queue Q);
    /**
     * 判断是否队列满
     */ 
    int is_full(Queue Q);

    /**
     * 创建一个队列
     */ 
    Queue create_queue(int MaxElements);
    /**
     * 释放队列空间
     */ 
    void dispose_queue(Queue Q);
    /**
     * 队列置空
     */ 
    void make_empty(Queue Q);
    /**
     * 入队
     */ 
    void enqueue(ElementType e , Queue Q);
    /**
     * 出队
     */ 
    void dequeue(Queue Q);

    /**
     * 下一个出队元素
     */ 
    ElementType front(Queue Q);

    /**
     * 出队并返回下一个元素
     */
    ElementType front_dequeue(Queue Q); 
#endif