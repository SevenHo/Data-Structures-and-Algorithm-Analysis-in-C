#include <stdio.h>
#include <stdlib.h>
#include "my_adjacency_matrix.h"
#include "../chapter03/my_queue_array.c"

#define True 1
#define False 0

struct GNode
{
    int isDirected;
    int vertices;        //顶点数
    int edges;           //边数
    WeightType **Matrix; //矩阵
    DataType *datas;     //定点值
};

struct ENode
{
    Vertex v1, v2;
    WeightType weight;
};

Graph createGraph(int NumOfVertexs, int isDirectedGraph)
{
    Graph G = NULL;
    G = (Graph)malloc(sizeof(struct GNode));
    if (!G)
    {
        exit(1);
    }
    G->vertices = NumOfVertexs;
    G->isDirected = isDirectedGraph;
    G->edges = 0;
    G->Matrix = (WeightType **)malloc(sizeof(WeightType *) * NumOfVertexs);
    for (int i = 0; i < NumOfVertexs; i++)
    {
        G->Matrix[i] = malloc(sizeof(WeightType) * NumOfVertexs);
        for (int j = 0; j < NumOfVertexs; j++)
        {
            G->Matrix[i][j] = INFINITY;
        }
    }
    return G;
}

Graph buildGraph(int isDiGraph, int hasData)
{
    int Nv, Ne;
    Graph G;
    //printf("Input Numbers of Vertcies:\n");
    scanf("%d", &Nv);
    G = createGraph(Nv, isDiGraph);
    scanf("%d", &G->edges);
    if (G->edges)
    {
        Edge E = (Edge)malloc(sizeof(struct ENode));
        if (!E)
            exit(1);
        for (int i = 0; i < G->edges; i++)
        {
            scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
            insertEdge(G, E);
        }
    }
    if (hasData)
    {
        DataType *datas;
        datas = (DataType *)malloc(sizeof(DataType) * Nv);
        for (int i = 0; i < Nv; i++)
        {
            scanf("%d", &datas[i]);
        }
        G->datas = datas;
    }

    return G;
}

void insertEdge(Graph G, Edge E)
{
    // G->edges++;
    G->Matrix[E->v1][E->v2] = E->weight;
    if (!G->isDirected)
    {
        G->Matrix[E->v2][E->v1] = E->weight;
    }
}
void delteEdge(Graph G, Edge E)
{
    if (G->edges && G->Matrix[E->v1][E->v2])
    {
        // G->edges--;
        G->Matrix[E->v1][E->v2] = 0;
        if (!G->isDirected)
        {
            G->Matrix[E->v2][E->v1] = 0;
        }
    }
}

int isEmpty(Graph G)
{
    return G->vertices == 0;
}
void visit(Vertex v)
{
    printf("%d->", v);
}

/**
 * Depth First Search
 */
void DFS(Graph G, Vertex startVertex, void (*visit)(Vertex), int visited[])
{
    visit(startVertex);
    visited[startVertex] = True;
    for(int i = 0; i < G->vertices; i++)
    {
        if(G->Matrix[startVertex][i] && visited[i] == False)
        {
            DFS(G,i,visit,visited);
        }
    }
}
/**
 * Breadth First Search
 */ 
void BFS(Graph G, Vertex startVertex, void (*visit)(Vertex), int visited[])
{
    Queue Q = create_queue(G->vertices);
    enqueue(startVertex,Q);
    visited[startVertex] = True;
    while(!is_empty(Q))
    {
        Vertex v = front_dequeue(Q);
        visit(v);
        for (int i = 0; i < G->vertices; i++)
        {
            if(G->Matrix[v][i] != INFINITY && visited[i] == False)
            {
                enqueue(i,Q);
                visited[i] = True;
            }
        }
        
    }
}
/**
 * 1--DFS
 * 0--BFS
 */
void traversal(Graph G, Vertex startVertex, int accessWay)
{
    int *visited = (int *)malloc(sizeof(int)*G->vertices);
    for (int i = 0; i < G->vertices; i++)
    {
        visited[i] = False;
    }
    
    if(accessWay)
    {
        DFS(G,startVertex,&visit,visited);
        printf("end\n");
    }else
    {
        BFS(G,startVertex,&visit,visited);
        printf("end\n");
    }
    
}
/*
int main(void)
{
    Graph G;
    int digraph , hasData;
    scanf("%d %d",&digraph , &hasData);
    G = buildGraph(digraph,hasData);
    traversal(G,0,1);
    traversal(G,0,0);
    return 0;
}
*/