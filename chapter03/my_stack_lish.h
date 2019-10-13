#ifndef __MY_STACK_LIST__
#define __MY_STACK_LIST__
    typedef int ElementType;
    struct Node ;
    typedef struct Node *PtrToNode;
    typedef PtrToNode Stack ;

    /**
     * 判断是否为空
     */ 
    int is_empty(Stack S);
    /**
     * 创建一个栈
     */
    Stack create_stack();
    /**
     * 释放栈空间
     */
    void dispose_stack(Stack S);
    /**
     * 栈置空
     */
    void make_empty(Stack S);
    /**
     * 元素入栈
     */ 
    void push(ElementType e , Stack S);
    /**
     * 栈顶元素
     */ 
    ElementType top(Stack S);
    /**
     * 元素出栈
     */ 
    void pop(Stack S);
    /**
     * 出栈且返回栈顶元素
     */ 
    ElementType top_pop(Stack S);
#endif 