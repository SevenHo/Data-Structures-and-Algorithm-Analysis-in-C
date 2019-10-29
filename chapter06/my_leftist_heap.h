#ifndef _MY_LEFTITST_HEAP_
#define ElementType int
typedef struct TreeNode *PriortyQueue;

PriortyQueue initialize_heap();
ElementType findMin(PriortyQueue H);
int is_empty(PriortyQueue H);
PriortyQueue Merge(PriortyQueue H1, PriortyQueue h2);
/*个人理解：插入和删除操作会改变根节点,定义宏函数，隐含式返回*/
#define insert_heap(X, H) (H = insert((X), (H)))
#define delete_min(H) (H = delete_min1((H)))

PriortyQueue insert(ElementType x, PriortyQueue H);
PriortyQueue delete_min1(PriortyQueue H);

#endif