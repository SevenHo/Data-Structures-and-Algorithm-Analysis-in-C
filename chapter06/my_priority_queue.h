#ifndef _PRIORITY_QUEUE_
#define ElementType int
#define Min INT_MIN
	typedef struct HeapStruct *PriorityQueue;
	PriorityQueue initialize_heap(int capacity);
	int is_full(PriorityQueue H);
	int is_empty(PriorityQueue H);
	void destroy_heap(PriorityQueue H);
	void make_empty_heap(PriorityQueue H);
	void insert(ElementType e, PriorityQueue H);
	ElementType delete_min(PriorityQueue H);
	ElementType find_min(PriorityQueue H);

#endif
