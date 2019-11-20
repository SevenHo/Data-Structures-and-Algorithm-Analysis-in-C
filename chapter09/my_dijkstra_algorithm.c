#include <stdio.h>
#include <limits.h>

#include "my_shortest_path_graph_struct.c"

#define INFINITY INT_MAX

/*使用配对最小堆，对于sparse graph 有着 O(|E|log|V|) 的界，
* 对于 dense graph 可以不用二叉堆和邻接链表，因为它的 O(|V^2|)的界
* 对于dense graph 来说是最优的。
* 等学完12 配对堆再编写此函数
*/
findMinUnknowDist(Graph G);

void Dijkstra(Graph G , Vertex S )
{
    for (int i = 0; i < G->Nv; i++)
    {
        G->list[i].dv = INFINITY;
        G->list[i].pv = -1;
        G->list[i].know = 0;
    }
    G->list[S].dv = 0;

    Vertex v , w;
    ACell cell ;
    WeightType dist;
    while(1)
    {
        v = findMinUnknowDist(G->list);
        if(v == -1)
        {
            break;
        }
        G->list[v].know = 1;
        cell = G->list[v].firstEdge;
        while(cell)
        {   
            w = cell->v;
            if(G->list[w].know == 0 )
            {
                dist = (G->list[v].dv + cell->weighted);
                if( dist< G->list[w].dv )
                {
                    G->list[w].dv = dist;
                    G->list[w].pv = v;
                }
            }
        }
    }
}

int main(void)
{

    return 0;
}