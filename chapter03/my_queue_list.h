#ifndef __MY_QUEUE_LIST__
#define __MY_QUEUE_LIST__
    typedef int ElementType;
    struct QueueRecord;
    typedef struct QueueRecord *Queue;
    typedef struct QueueRecord *PtrNode;
    
    /**
     * 创建一个队列
     */ 
    Queue create_queue();
    /**
     * 判断是否为空
     */ 
    int is_empty(Queue Q);
    /**
     * 释放队列
     */ 
    void dispose_queue(Queue Q);
    /**
     * 队列置空
     */ 
    void make_empty(Queue Q);
    /**
     * 入队
     */ 
    void enqueue(ElementType e,Queue Q);
    /**
     * 出队
     */ 
    void dequeue(Queue Q);
    /**
     * 下一个出队元素
     */ 
    ElementType front(Queue Q);
    /**
     * 出队并返回元素
     */ 
    ElementType front_dequeue(Queue Q);
    
#endif