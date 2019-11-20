#include <stdio.h>

#define is_empty(Q) (Q->size == 0)
#define INPUT_FORMAT "%d"
#define EDGE_INPUT "%d %d %d"

typedef int ElementType;
typedef int Vertex;
typedef int WeightType;

typedef struct ENode *Edge; /*边节点*/
typedef struct HeaderCell *HCell; /*邻接链表头节点*/
typedef struct AdjacencyCell *ACell; /*邻接节点*/
typedef struct GraphNode *Graph;
typedef HCell AdjList;

struct ENode {
    Vertex v;
    Vertex w;
    WeightType weighted;
};

struct HeaderCell {
    ElementType value;
    ACell firstEdge;
    int know; /* 是否已知 */
    int dv; /* 当前vertex 到 源点 */
    int pv; /* 前驱vertex */
};

struct AdjacencyCell {
    Vertex v;
    WeightType weighted;
    ACell next;
};

struct GraphNode {
    int Nv; /* number of vertices */
    int Ne; /* Number of edges */
    AdjList list; /* adjcency list */
};

typedef struct {
    int capacity;
    int size;
    int front;
    int rear;
    Vertex *arr;
}Queue;

typedef struct {
    int capacity;
    int size;
    Vertex *arr;
}MinHeap;

Queue * initQueue(int capacity)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->arr = (Vertex *)malloc(sizeof(Vertex)*capacity);
    Q->capacity = capacity;
    Q->size = Q->front = Q->rear = 0;

    return Q;
}
void enQueue(Vertex x , Queue* Q)
{
    if(Q->size < Q->capacity)
    {
        Q->arr[Q->rear++] = x;
        Q->size++;
        Q->rear = Q->rear == Q->capacity ? 0 : Q->rear;
    }
}

Vertex deQueue(Queue* Q)
{
    Vertex var;
    if(Q->size > 0)
    {
        var = Q->arr[Q->front++];
        Q->front %= Q->capacity;
        Q->size--;
        return var;
    }

}

void insertEdge(Edge E , Graph G)
{
    ACell cell = malloc(sizeof(struct AdjacencyCell));
    cell->v = E->w;
    cell->weighted = E->weighted;
    cell->next = G->list[E->v].firstEdge;
    G->list[E->v].firstEdge = cell;
}

Graph read_buildGraph(int Nv, int Ne)
{
    Graph G = malloc(sizeof(struct GraphNode));
    G->list = (HCell) malloc(sizeof(struct HeaderCell)*Nv);
    G->Nv = Nv;
    G->Ne = Ne;
    for (int i = 0; i < Nv; i++)
    {
        scanf(INPUT_FORMAT,&G->list[i].value);
        G->list[i].firstEdge = NULL;
    }
    Edge E = malloc(sizeof(struct ENode));
    for (int i = 0; i < Ne; i++)
    {
        scanf(EDGE_INPUT,&E->v,&E->w,&E->weighted);
        insertEdge(E,G);
    }
    
    return G;
    
}

void printPath(Graph G,Vertex dest);



