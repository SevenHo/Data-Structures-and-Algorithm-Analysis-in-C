#include <stdio.h>
#include <stdlib.h>
#include "../chapter03/my_queue_array.c"

typedef int DataType;   //顶点值类型
typedef int WeightType; //权值类型
typedef int Vertex;     //定点下标

typedef struct AdjNode *PtrToAdjNode;
typedef struct GNode *Graph;
typedef struct ENode *Edge;

struct ENode
{
    Vertex v1, v2;
    WeightType weight;
};

typedef struct VNode
{
    DataType data;
    PtrToAdjNode firstEdge;
} * HeaderNode;

struct AdjNode
{
    Vertex v;
    WeightType weight;
    PtrToAdjNode next;
};

struct GNode
{
    int Nv;
    int Ne;
    int* Indegree;
    HeaderNode AdjList;
};

void insertEdge(Edge E, Graph G)
{
    PtrToAdjNode tmpcell = malloc(sizeof(struct AdjNode));
    tmpcell->v = E->v2;
    tmpcell->weight = E->weight;
    tmpcell->next = G->AdjList[E->v1].firstEdge;
    G->AdjList[E->v1].firstEdge = tmpcell;
}

Graph buildGraph()
{
    int Nv, Ne;
    Graph G;
    scanf("%d%d", &Nv, &Ne);

    G = malloc(sizeof(struct GNode));
    G->Nv = Nv;
    G->Ne = Ne;
    G->AdjList = calloc(Nv, sizeof(struct VNode));

    G->Indegree = (int *)calloc(Nv, sizeof(int));
    for (int i = 0; i < Nv; i++)
    {
        G->Indegree[i] = 0;
    }
    if (Ne)
    {
        Edge E = malloc(sizeof(struct ENode));
        for (int i = 0; i < Ne; i++)
        {
            scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
            insertEdge(E, G);
            G->Indegree[E->v2]++;
        }
    }
    for (int i = 0; i < Nv; i++)
    {
        scanf("%d",&G->AdjList[i].data);
    }
    

    return G;
}

void topSort1(Graph G)
{
    int i;
    while (1)
    {
        for (i = 0; i < G->Nv; i++)
        {
            if (G->Indegree[i] == 0)
            {
                printf("%d->", G->AdjList[i].data);
                G->Indegree[i] = -1;
                PtrToAdjNode tmp = G->AdjList[i].firstEdge;
                while (tmp)
                {
                    G->Indegree[tmp->v]--;
                    tmp = tmp->next;
                }
                break;
            }
        }
        if (i == G->Nv)
            break;
    }
}

void topSort2(Graph G)
{
    int counter = 0;
    Vertex v;
    Queue Q = create_queue(G->Nv);
    for (int i = 0; i < G->Nv; i++)
    {
        if(G->Indegree[i] == 0)
        {
            enqueue(i,Q);
        }
    }
    while(!is_empty(Q))
    {
        v = front_dequeue(Q);
        printf("%d-->",G->AdjList[v].data); /*TopNum[v] == ++counter,排序顺序保存到TopNum 数组中 */
        PtrToAdjNode tmp = G->AdjList[v].firstEdge;
        while(tmp)
        {
            if(--G->Indegree[tmp->v] == 0)
            {
                enqueue(tmp->v,Q);
            }
            tmp = tmp->next;
        }
    }
    
}

int main(void)
{
    Graph G;
    G = buildGraph();
    // topSort1(G);
    topSort2(G);
    return 0;
}