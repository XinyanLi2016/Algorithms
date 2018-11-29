#include <iostream>
#include <queue>
#include <stdio.h>
#define MAXM 1005
#define MAXN 205
#define INF 0x3f3f3f3f
using namespace std;
int graph[MAXN][MAXN];
int dist[MAXN];
int visited[MAXN];
//int prev[MAXN];
int N, M;
void init()
{
    for(int i = 0; i < MAXN ; i++)
    {
        for(int j = 0; j < MAXN; j++)
        {
            graph[i][j] = INF ;
        }
    }
}
void Dijkstra(int s)
{
    for(int i = 0 ; i < N ; i++)
    {
        dist[i] = graph[s][i];
        //prev[i] = INF;
        visited[i] = 0;
    }
    dist[s] = 0;
    visited[s] = 1;
    int u;

    for(int i = 0; i < N; i++)
    {
        int temp = INF;
        for(int j = 0; j <N ; j++)//find the vertex u with the minimum dist
        {
            if((visited[j]==0)&&(temp > dist[j]))
            {
                u = j;
                temp = dist[j];
            }
        }
        if(temp == INF)
            break;
        visited[u] = 1; //erase u
        for(int v = 0; v < N; v++ )
        {
            if(dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                //prev[v] = u;
            }
        }

    }
}




int main()
{

    while(scanf("%d%d",&N,&M)!=EOF)
    {
        init();
        while(M--)
        {
            int a,b,x;
            scanf("%d%d%d",&a,&b,&x);
            if(graph[a][b] > x)
            {
                graph[a][b] = x;
                graph[b][a] = x;
            }
        }
        int s,t;
        scanf("%d%d",&s,&t);
        Dijkstra(s);
        if (dist[t] == INF)
            printf("-1\n");
        else
            printf("%d\n",dist[t]);
    }
    return 0;
}
