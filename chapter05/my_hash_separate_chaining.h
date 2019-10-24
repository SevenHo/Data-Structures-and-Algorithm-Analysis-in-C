#ifndef __HashSep_H__

#define ElementType char*

struct ListNode;
typedef struct ListNode *Position ;
typedef struct HashTbl *HashTable ;

HashTable initialize_hashtbale(int tablesize);
void destroy_hashtable(HashTable T);
Position find_hashtable(ElementType key,HashTable T);
void insert_hashtable(ElementType e , HashTable T);
ElementType retrieve_hashtable(Position p);
void delete_e_hashtable(ElementType e , HashTable T);
void make_empty_hashtable(HashTable T);
#endif