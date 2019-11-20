#ifndef _MY_ADJACENCY_LIST_
    typedef int DataType; //顶点值类型 
    typedef int WeightType; //权值类型
    typedef int Vertex; //定点下标

    typedef struct AdjNode *PtrToAdjNode;
    typedef struct GNode *Graph;
    typedef struct ENode *Edge;
    

    Graph createGraph(int NumOfVertices);
    Graph buildGraph(int isDigraph, int hasData);
    void insertEdge(Edge E , Graph G,int isDigraph);
    void deleteEdge(Edge E , Graph G,int isDigraph);
    int isEmpty(Graph G);
    void visit(Vertex v,Graph G);
    void DFS(Graph G,int startVertex,void(*visit)(Vertex,Graph),int visited[]);
    void BFS(Graph G,int startVertex,void(*visit)(Vertex,Graph),int visited[]);

#endif