#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct graph{
    int** adjMatrix;
    int vertices;
}Graph;

int port;

Graph* create_graph(int vertices)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->adjMatrix = (int**) malloc(vertices*sizeof(int*));
    for (int i=0;i<vertices;i++)
    {
        graph->adjMatrix[i] = (int*) calloc(vertices,sizeof(int));
    }
    graph->vertices = vertices;
    return graph;
}

int* array_init(int n)
{
    int* a = (int*) malloc(n*sizeof(int));
    return a;
}

Graph* input()
{
    int n,m;
    scanf("%d %d %d",&port,&n,&m);
    Graph* graph = create_graph(n);
    int** aM = graph->adjMatrix;
    int src,dst,time;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&src,&dst,&time);
        aM[src][dst] = time;
    }
    return graph;
}

int min_distance(int* dist,int* sptSet,int V)
{
    int min = INT_MAX, min_ind;

    for (int v = 0;v<V;v++)
    {
        if (sptSet[v] == 0 && dist[v]<=min)
            min = dist[v], min_ind = v;
    }
    return min_ind;
}
void remake(Graph*,int*);
void dijkstra(Graph* graph,int src,int port)
{
    int V = graph->vertices;
    int** am = graph->adjMatrix;
    int *dist = array_init(V), *sptSet = array_init(V);
    int* paths = (int*) malloc(V*sizeof(int)), count =0;
    for (int i=0;i<V;i++)
        dist[i] = INT_MAX, sptSet[i] = 0;


    dist[src] = 0;

    for (int cnt = 0; cnt < V-1; cnt++)
    {
        int u = min_distance(dist,sptSet,V);
        sptSet[u] = 1;
        for (int v=0;v<V;v++)
        {

            if ((!sptSet[v]) && (am[u][v]) && (dist[u] != INT_MAX) && (dist[u] + am[u][v] < dist[v])) {
                dist[v] = dist[u] + am[u][v];
            }
        }
    }
    printf("%d\n",dist[port]);
    remake(graph,dist);
}

void remake(Graph* graph, int* dist)
{
    int v = graph->vertices;
    int** am = graph->adjMatrix;

    int *visited = (int*) malloc(v*sizeof(int));
    int end = port;
    visited[0] = port;
    int k = 1;
    int weight = dist[end];

    while (end != 0)
    {
        for (int i = 0;i<v;i++)
        {
            if (am[i][end] != 0)
            {
                int tmp = weight - am[i][end];
                if (tmp == dist[i])
                {
                    weight = tmp;
                    end = i;
                    visited[k] = i;
                    k++;
                }
            }
        }
    }
    for (int i=k-1;i>=0;i--)
    {
        printf("%d ",visited[i]);
    }
}


int main()
{
    Graph *graph = input();
    dijkstra(graph,0,port);
    return 0;
}