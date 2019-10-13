#ifndef __MY_STACK_ARRAY__
#define __MY_STACK_ARRAY__
    typedef int ElementType;
    struct StackRecord;
    typedef struct StackRecord *Stack;

    /**
     * 判断是否为空
     */ 
    int is_empty(Stack S);
    /**
     *  栈是否已满
     */ 
    int is_full(Stack S);
    /**
     * 创建一个栈
     */ 
    Stack create_stack(int MaxElements);
    /**
     * 栈置空
     */ 
    void make_empty(Stack S);
    /**
     * 释放栈
     */ 
    void dispose_stack(Stack S);
    /**
     * 入栈
     */
    void push(ElementType e , Stack S);
    /**
     * 出栈
     */
    void pop(Stack S);
    /**
     * 取栈顶元素
     */  
    ElementType top(Stack S);
    /**
     * 返回并删除栈顶元素
     */ 
    ElementType top_pop(Stack S);


#endif 