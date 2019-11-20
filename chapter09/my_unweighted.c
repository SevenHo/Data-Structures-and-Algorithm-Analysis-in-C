#include <stdio.h>
#include <stdlib.h>
#include "./my_shortest_path_graph_struct.c"

#define INFINITY (-1)

void unweighted(Graph G,Vertex start)
{
    Vertex v,w;
    ACell tmp;
    Queue* Q = initQueue(G->Nv);
    /* 初始化辅助信息结构 */
    for (int i = 0; i < G->Nv; i++ )
    {
        G->list[i].dv = INFINITY;
        G->list[i].know = 0;
        G->list[i].pv = -1;
    }
    /* 初始化初始点 距离 */
    G->list[start].dv = 0;
    enQueue(start,Q);

    while(!is_empty(Q))
    {
        v = deQueue(Q);
        // G->list[v].know = 1;
        tmp = G->list[v].firstEdge;
        while(tmp)
        {
            w = tmp->v;
            if(G->list[w].dv == INFINITY)
            {
                G->list[w].dv = G->list[v].dv + 1;
                G->list[w].pv = v;
                enQueue(w,Q);
            }
            tmp = tmp->next;
        }

    }   
}

void printPath(Graph G,Vertex dest)
{
    if(G->list[dest].pv != -1)
    {
        printPath(G,G->list[dest].pv);
        printf("-->");
    }
    printf("%d",G->list[dest].value);
}
/*
int main(void)
{
    int Nv , Ne , S , D ;
    scanf("%d %d %d %d",&Nv,&Ne,&S,&D);
    Graph G = read_buildGraph(Nv,Ne);
    unweighted(G,S);
    printPath(G,D);
    return 0;
}
*/