#ifndef _MY_SKEW_HEAP_
#define ElementType int
typedef struct TreeNode *PriortyQueue;
int is_empty(PriortyQueue H);
PriortyQueue insert(ElementType x, PriortyQueue H);
PriortyQueue delete_min(PriortyQueue H);
PriortyQueue Merge(PriortyQueue H1, PriortyQueue H2);

#endif