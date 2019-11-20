#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode *Adj;
typedef struct LenderNode *LN;

typedef struct {
    int w;
    int v1;
    int v2;
}Edge;

struct AdjNode {
    int w;
    int v;
    Adj next;
};

struct LenderNode {
    int M;
    Adj firstEdge;
};

void insertEdge(Edge E , LN List)
{
	Adj node = malloc(sizeof(struct AdjNode));
	Adj node2 = malloc(sizeof(struct AdjNode));

	node->v = E.v2;
	node->w = E.w;
	node->next = List[E.v1].firstEdge;
	List[E.v1].firstEdge = node;

	node2->v = E.v1;
	node2->w = E.w;
	node2->next = List[E.v2].firstEdge;
	List[E.v2].firstEdge = node2;
}

void handle(LN List, int start,int N);
int findMinUnknow(LN List,int len);
void printPath(int dest);

int (*visited)[5]; /*know , dv , pv , count , sum */

int main(void)
{
	/* undirected graph */
    int N,M,S,D;
    LN AdjList;

    scanf("%d %d %d %d",&N,&M,&S,&D);
    AdjList = (LN )malloc(sizeof(struct LenderNode)*N);
	visited = (int (*)[5])malloc(sizeof(int)*N*5);

    for(int i = 0 ; i < N; i++)
    {
        scanf("%d",&(AdjList[i].M));
		AdjList[i].firstEdge = NULL;
		visited[i][0] = 0; /*know*/
		visited[i][1] = INT_MAX; /*dv*/
		visited[i][2] = -1; /*pv*/
		visited[i][3] = 0; /*count,最短路径条数*/
		visited[i][4] = 0; /*sum, 救援队最大数 */
    }
	

    Edge E;
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d %d",&E.v1,&E.v2,&E.w);
		insertEdge(E,AdjList);
    }

	handle(AdjList,S,N);

	printf("%d %d\n",visited[D][3],visited[D][4]);
	printPath(D);

   return 0; 
}

void handle(LN List, int start,int N)
{
	int v , w ;
	Adj tmp;

	visited[start][1] = 0 ;
	visited[start][3] = 1 ;
	visited[start][4] = List[start].M;

	while(1)
	{
		v = findMinUnknow(List,N);
		if(v == -1)
		{
			break;
		}
		visited[v][0] = 1;
		tmp = List[v].firstEdge;
		while(tmp)
		{
			if(visited[tmp->v][0] == 0)
			{
				w = tmp->v;
				if(visited[v][1] + tmp->w < visited[w][1])
				{
					visited[w][1] = visited[v][1] + tmp->w;
					visited[w][2] = v;
					visited[w][3] = visited[v][3];
					visited[w][4] = visited[v][4] + List[w].M;
				}else if(visited[v][1] + tmp->w == visited[w][1])
				{
					if(visited[v][4] + List[w].M > visited[w][4])
					{
						visited[w][2] = v;
						visited[w][4] = visited[v][4] + List[w].M;
					}
					visited[w][3] += visited[v][3];
				}
			}
			tmp = tmp->next;
		}
	}
}

int findMinUnknow(LN List,int len)
{
	int min = 0;
	while(min < len && visited[min][0])
	{
		min++;
	}
	for (int i = min+1; i < len; i++)
	{
		if(visited[i][0] == 0 && visited[i][1] < visited[min][1])
		{
			min = i;
		}
	}
	if(min < len)
	{
		return min;
	}else
	{
		return -1;
	}
	
	
}

void printPath(int dest)
{
	if(visited[dest][2] != -1)
	{
		printPath(visited[dest][2]);
		printf(" ");
	}
	printf("%d",dest);
}