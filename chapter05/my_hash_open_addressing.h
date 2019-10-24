#ifndef _HashQuad_H_
#define ElementType int
typedef unsigned int Index;
typedef Index Position ;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable initialize_hashtable(int tablesize);
void destroy_hashtable(HashTable T);
Position find_hashtable(ElementType key,HashTable T);
void insert_hashtable(ElementType key, HashTable T);
ElementType retrieve(Position p , HashTable T);
HashTable rehash(HashTable T);

#endif 


