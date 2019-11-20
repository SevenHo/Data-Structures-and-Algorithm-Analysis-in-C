#ifndef _MY_ADJACENCY_MATRIX_
#define INFINITY 0
typedef int Vertex;
typedef int WeightType;
typedef int DataType;

typedef struct GNode *PtrToGNode;
typedef PtrToGNode Graph;
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;

Graph createGraph(int NumOfVertexs,int isDirectedGraph);
Graph buildGraph(int isDiGraph , int hasData);
void insertEdge(Graph G, Edge E);
void delteEdge(Graph G , Edge E);
int isEmpty(Graph G);
void visit(Vertex v);
void DFS(Graph G,Vertex startVertex,void (*visit)(Vertex),int visited[]);
void BFS(Graph G,Vertex startVertex,void (*visit)(Vertex), int visited[]);
#endif