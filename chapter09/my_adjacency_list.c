#include <stdio.h>
#include <stdlib.h>
#include "./my_adjacency_list.h"
#include "../chapter03/my_queue_array.c"

#define True (1)
#define False (0)
/*边,v1->v2*/
struct ENode
{
    Vertex v1, v2;
    WeightType weight;
};

/*邻接点*/
struct AdjNode
{
    Vertex v;
    WeightType weight;
    PtrToAdjNode next;
};

/*顶点*/
typedef struct VNode
{
    DataType data;
    PtrToAdjNode firstEdge;
} * PtrToV;

struct GNode
{
    int NumOfV;     //顶点数
    int NumOfE;     // 边数
    PtrToV AdjList; // 邻接表
};

Graph createGraph(int NumOfVertices)
{
    Graph G = NULL;
    G = (Graph)calloc(1, sizeof(struct GNode));
    if (!G)
        exit(1);
    G->NumOfV = NumOfVertices;
    G->NumOfE = 0;
    G->AdjList = calloc(NumOfVertices, sizeof(struct VNode));
    if (!G->AdjList)
        exit(1);

    return G;
}
Graph buildGraph(int isDigraph, int hasData)
{
    Graph G;
    int N;
    scanf("%d", &N);
    G = createGraph(N);
    scanf("%d", &G->NumOfE);
    if (G->NumOfE)
    {
        Edge E = malloc(sizeof(struct ENode));
        for (int i = 0; i < G->NumOfE; i++)
        {
            scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
            insertEdge(E, G, isDigraph);
        }
    }
    if (hasData)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &(G->AdjList[i].data));
        }
    }
    return G;
}
void insertEdge(Edge E, Graph G, int isDigraph)
{
    PtrToAdjNode node = malloc(sizeof(struct AdjNode));
    if (!node)
        exit(1);
    node->v = E->v2;
    node->weight = E->weight;

    node->next = G->AdjList[E->v1].firstEdge;
    G->AdjList[E->v1].firstEdge = node;
    if (!isDigraph)
    {
        node = malloc(sizeof(struct AdjNode));
        if (!node)
            exit(1);
        node->v = E->v1;
        node->weight = E->weight;
        node->next = G->AdjList[E->v2].firstEdge;
        G->AdjList[E->v2].firstEdge = node;
    }
}
void deleteEdge(Edge E, Graph G, int isDigraph)
{
    PtrToAdjNode tmp, tmpBefore;

    Vertex arr[2];
    arr[0] = E->v1;
    arr[1] = E->v2;

    int t = isDigraph ? 1 : 2;
    for (int i = 0; i < t; i++)
    {
        tmpBefore = tmp = G->AdjList[arr[i]].firstEdge;
        while (tmp && tmp->weight != E->weight)
        {
            tmpBefore = tmp;
            tmp = tmp->next;
        }
        if (tmp)
        {
            if (tmpBefore != tmp)
            {
                tmpBefore->next = tmp->next;
            }
            else
            {
                G->AdjList[arr[i]].firstEdge = tmp->next;
            }
            free(tmp);
        }
    }
}

int isEmpty(Graph G)
{
    return G->NumOfV == 0;
}
void visit(Vertex v, Graph G)
{
    printf("%d->", G->AdjList[v].data);
}
void DFS(Graph G, int startVertex, void (*visit)(Vertex, Graph), int visited[])
{
    visit(startVertex, G);
    visited[startVertex] = True;
    PtrToAdjNode tmp = G->AdjList[startVertex].firstEdge;
    while (tmp)
    {
        if(visited[tmp->v] == False)
        {
            DFS(G, tmp->v, visit, visited);
        }
        tmp = tmp->next;
    }
}
void BFS(Graph G, int startVertex, void (*visit)(Vertex, Graph), int visited[])
{
    Queue Q = create_queue(G->NumOfV);
    enqueue(startVertex, Q);
    visited[startVertex] = True;
    while (!is_empty(Q))
    {
        Vertex v = front_dequeue(Q);
        visit(v, G);
        PtrToAdjNode tmp = G->AdjList[v].firstEdge;
        while (tmp)
        {
            if(visited[tmp->v] == False)
            {
                enqueue(tmp->v, Q);
                visited[tmp->v] = True;
            }
            tmp = tmp->next;
        }
    }
}
/**
 * accessWay
 * 1--> DFS
 * 0--> BFS
 */ 
void traversal(Graph G, int startVertex, void (*visit)(Vertex, Graph), int accessWay)
{
    int *visited =(int *) calloc(G->NumOfV,sizeof(int));
    for (int i = 0; i < G->NumOfV; i++)
    {
        visited[i] = False;
    }
    if(accessWay)
    {
        DFS(G,startVertex,visit,visited);
        printf("end\n");
    }else
    {
        BFS(G,startVertex,visit,visited);
        printf("end\n");
    }
    
}
/*
int main(void)
{
    int digraph, hasData;
    Graph G;
    scanf("%d %d", &digraph, &hasData);
    G = buildGraph(digraph, hasData);
    traversal(G,0,visit,1);
    traversal(G,0,visit,0);
    return 0;
}
*/