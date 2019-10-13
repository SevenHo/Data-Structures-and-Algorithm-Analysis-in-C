#include <stdio.h>
#include <stdlib.h>
#include "my_doubly_linked_list.h"

/**
     * 创建一个空链表,或删除链表
     */
LinkList make_empty(LinkList L){
    Position tmpPrior;
    Position tmpNext;
    if(L){
        Position tmpCell , release ;
        tmpCell = L;
        while(tmpCell->next){
            release = tmpCell;
            tmpCell = tmpCell->next;
            free(release);
            release = NULL;
        }
        return NULL;
        // int size = L->value;
        // Position tmpCell;
        // tmpPrior = L->prior;
        // tmpNext = L->next;
        // for ( int i = 0; i < size/2; i++)
        // {
        //     tmpCell = tmpPrior->prior;
        //     free(tmpPrior);
        //     tmpPrior = tmpCell;

        //     tmpCell = tmpNext->next;
        //     free(tmpNext);
        //     tmpNext = tmpCell;
        // }
        // if(size%2 != 0){
        //     free(tmpNext);
        // }
        // free(L);
        // return NULL;
    }else{
        L = (LinkList)malloc(sizeof(Node));
        if(!L){
            exit(1);
        }
        L->prior = NULL;
        L->next = NULL;
        L->value = 0;
        return L;
    }
}
/**
     * 判断链表是否为空
     */
int is_empty(LinkList L){
    return L->next==NULL;
}
/**
     * 判断是否为最后一个元素
     */
int is_last(Position p, LinkList L){
    return p->next == NULL;
}
/**
     * 插入元素,指定节点或链表尾
     */
void insert(ElementType e, LinkList L, Position p){
    Position tmpCell = NULL ;
    tmpCell = (Position)malloc(sizeof(Node));
    if(!tmpCell){
        exit(1) ;
    }
    tmpCell->value = e ;
    tmpCell->next = NULL;
    tmpCell->prior = NULL;
    if(p){
        p->prior->next = tmpCell;
        tmpCell->prior = p->prior;
        tmpCell->next = p;
        p->prior = tmpCell;
    }else{
        Position tmp = L;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = tmpCell;
        tmpCell->prior = tmp;
    }
}
/**
     * 删除元素节点,true 全部,false 第一次出现
     */
void delete_e(ElementType e, LinkList L, int boolean){
    Position p = L;
    while (p->next)
    {   
        p = p->next;
        if(p->value == e){
            p->prior->next = p->next;
            if(p->next){
                p->next->prior = p->prior;
            }
            Position release = p;
            p = p->prior;
            free(release);
            if(!boolean){
                break;
            }
        }
    }
    
}
/**
 * 查找元素第一次出现的位置节点
 */
Position find(ElementType e, LinkList L){
    Position p = L->next;
    while(p && p->value != e){
        p = p->next;
    }
    return p;
}
/**
 * 打印链表
 */ 
void print_list(LinkList L){
    Position p = L->next;
    printf("\n[");
    while (p)
    {
        printf(format,p->value);
        p = p->next;
    }
    printf("]\n");
    
}

int main(void)
{   
    LinkList L ;
    L = make_empty(NULL);
    insert(1,L,NULL);
    insert(2,L,NULL);
    insert(3,L,NULL);
    Position entry = find(3,L);
    insert(0,L,entry);
    // Position entry1 = find_previous(0,L);
    // insert(-1,L,entry1);
    printf("list is empty : %d\n",is_empty(L));
    printf("3 is last ele : %d\n",is_last(entry,L));
    delete_e(3,L,0);
    print_list(L);
    insert(4,L,NULL);
    insert(4,L,NULL);
    delete_e(4,L,1);
    print_list(L);
    return 0;
}