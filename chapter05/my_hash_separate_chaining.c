#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "my_hash_separate_chaining.h"

/**
 * 分离链接法
 */ 

typedef unsigned int Index ;

typedef struct ListNode List;
struct HashTbl{
    int tablesize;
    List *arrays;
};

struct ListNode{
    ElementType e;
    Position next;
};

/**
 * 求hash值
 */ 
Index hash(const char *key ,int table_size )
{
	Index hashval = 0;
	while(*key != '\0')
	{   
        /*k1 + 32k2 + 32^2k3 + ... + 32^(n-1)kn*/
		hashval = (hashval << 8) + *key++ ;
	}
	return hashval % table_size ;
}

/**
 * 下一个质数
 */ 
int nextprime(int n)
{
    while (1)
    {
        int m = (int) sqrtl(n) ;
        while (m != 1)
        {
            if (n % m == 0)
            {
                break;
            }
            m--;
        }
        
        if( m != 1)
        {
            n ++;
        }else
        {
            return n;
        }
        
    }
    
}


HashTable initialize_hashtbale(int tablesize)
{
    HashTable T = NULL;
    T = (HashTable) malloc(sizeof(struct HashTbl));
    if (!T)
    {
        exit(1);
    }
    T->tablesize = nextprime(tablesize);
    T->arrays = malloc(sizeof(List)*T->tablesize);
    if(!T->arrays)
    {
        exit(1);
    }
    for (int i = 0; i < T->tablesize; i++)
    {
        T->arrays[i].e = NULL;
        T->arrays[i].next = NULL;
    }
    
    return T;
}
void destroy_hashtable(HashTable T)
{
    for (int i = 0; i < T->tablesize; i++)
    {
        Position p,tmp;
        p = T->arrays[i].next;
        while(p){
          tmp = p;
          p = p->next;
          free(p);  
        }
    }
    free(T->arrays);
    free(T);
}


Position find_hashtable(ElementType key,HashTable T)
{
    Position p ;
    p = &T->arrays[hash(key,T->tablesize)];
    while (p)   
    {
        if ( p->e && strcmp(p->e,key) == 0)
        {
            return p;
        }else
        {
            p = p->next;
        }
    }
    return p;
    
}
void insert_hashtable(ElementType e , HashTable T)
{
    Position cell = (Position) malloc(sizeof(List));
    cell->e = e;
    cell->next = NULL;
    Index i = hash(e,T->tablesize);
    Position p ;
    if (T->arrays[i].e)
    {
        cell->next = T->arrays[i].next;
        T->arrays[i].next = cell;
    }else
    {
        T->arrays[i] = *cell;
    }
    
}
ElementType retrieve_hashtable(Position p)
{
    return p->e;
}

void delete_e_hashtable(ElementType e , HashTable T){
    Position p = &T->arrays[hash(e,T->tablesize)];
    if (strcmp(e,p->e) == 0)
    {
        p->e = NULL;
    }else
    {   
        Position pbefore = p;
        while ((p = p->next))
        {

            if (strcmp(e,p->e) == 0)
            {
                pbefore->next = p->next;
                free(p); 
                break;    
            }
            pbefore = p;
        }
        
    }
    
    
}

int main(void)
{
	printf("%d",hash("hewei123",7));
    HashTable H = initialize_hashtbale(10);
    insert_hashtable("123456s",H);
    insert_hashtable("123456",H);
    insert_hashtable("asdfse",H);
    Position v = find_hashtable("asdfse",H);
    printf("%s,\n",retrieve_hashtable(v));
    delete_e_hashtable("123456",H);
    Position v1 = find_hashtable("123456",H);
    printf("%s,\n",v1);
    destory_hashtable(H);
}
