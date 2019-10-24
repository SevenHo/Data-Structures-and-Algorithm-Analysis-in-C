#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_hash_open_addressing.h"

typedef enum KindOfEntry
{
	Legitimate,
	Deleted,
	Empty
} state;
typedef struct HashEntry
{
	ElementType e;
	state status;
} Cell;

typedef struct HashTbl
{
	int tablesize;
	Cell *TheCells;
} Table;

int hash1(ElementType key, int tablesize)
{
	return key % tablesize;
}

int nextprime(int n)
{
	while (1)
	{
		int m = (int)sqrtl(n);
		while (m != 1)
		{
			if (n % m == 0)
			{
				break;
			}
			m--;
		}

		if (m != 1)
		{
			n++;
		}
		else
		{
			return n;
		}
	}
}

HashTable initialize_hashtable(int tablesize)
{
	HashTable H;

	H = (HashTable)malloc(sizeof(Table));
	if (!H)
	{
		exit(1);
	}
	tablesize = nextprime(tablesize);
	H->TheCells = (Cell *)malloc(sizeof(Cell) * tablesize);
	if (H->TheCells == NULL)
	{
		exit(1);
	}
	for (int i = 0; i < tablesize; i++)
	{
		H->TheCells[i].status = Empty;
	}
	H->tablesize = tablesize;
	return H;
}

void destroy_hashtable(HashTable T)
{
	free(T->TheCells);
	free(T);
}
Position find_hashtable(ElementType key, HashTable T)
{
	Position currentpos;
	int collisionNum = 0;

	currentpos = hash1(key, T->tablesize);
	while (T->TheCells[currentpos].status != Empty && T->TheCells[currentpos].e != key)
	{
		currentpos += (++collisionNum << 1) - 1; /*平方探索*/ 
		if (currentpos >= T->tablesize)
		{
			currentpos -= T->tablesize;
		}
	}
	return currentpos;
}

void insert_hashtable(ElementType key, HashTable T)
{
	Position p = find_hashtable(key,T);
	if (T->TheCells[p].status != Legitimate)
	{
		T->TheCells[p].e = key;
		T->TheCells[p].status = Legitimate;
	}

}

ElementType retrieve(Position p, HashTable T){
	if (T->TheCells[p].status == Legitimate)
	{
		return T->TheCells[p].e;
	}
	
}

HashTable rehash(HashTable T)
{
	int old_size = T->tablesize;
	Cell * old_cells = T->TheCells;
	int new_size = nextprime((old_size << 1) + 1);
	
	HashTable new_table = initialize_hashtable(new_size);

	for (int i = 0; i < old_size; i++ )
	{	
		if (old_cells[i].status == Legitimate)
		{
			insert_hashtable(old_cells[i].e,new_table);
		}
		
	}
	free(old_cells);
	free(T);
	return new_table;
	
}

int main(void)
{
	HashTable T = initialize_hashtable(11);
	insert_hashtable(1,T);
	insert_hashtable(2,T);
	insert_hashtable(1233,T);
	Position p = find_hashtable(1233,T);
	ElementType v = retrieve(p,T);
	printf("e-> :%d\n",v);
	p = find_hashtable(13,T);
	v = retrieve(p,T);
	printf("e2->%d\n",v);
	
	T = rehash(T);
	printf("size->%d",T->tablesize);
	return 0;
}
