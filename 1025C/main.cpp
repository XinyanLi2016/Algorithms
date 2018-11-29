#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX 505
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int start, end;
int map[MAX][MAX];
int score[MAX];
int ans;
int visited[MAX];
int dist[MAX];
vector<int> path[MAX];//先得到最短时间的路径
void Dijkstra(int s)
{
    for(int i = 0; i < n; i++)
      {
        visited[i] = 0;
        dist[i] = map[s][i];
      }
    dist[s] = 0;

    int u;

   for(int i = 0; i < n; i++)
    {
        int temp = INF;
        for(int j = 0; j <n ; j++)//find the vertex u with the minimum dist
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
        for(int v = 0; v < n; v++ )
        {
            if(dist[u] + map[u][v] < dist[v])
            {
                dist[v] = dist[u] + map[u][v];
                //prev[v] = u;
                path[v].clear();
                path[v].push_back(u);
            }
            else if(dist[u] + map[u][v] == dist[v])
                path[v].push_back(u);
        }

    }

}
void dfs(int s, int sum)
{
    sum+= score[s];
    if(s == start)
    {
       ans = max(ans, sum);
       return ;
    }
    for(int i = 0; i < path[s].size();i++)
    {
        dfs(path[s][i],sum);
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&start,&end);
    for(int i =0; i < n ; i++)
    {
        scanf("%d",&score[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            map[i][j] = INF;
        }
    }
    int x,y,z;
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&z);
        map[x][y] = z;
        map[y][x] = z;
    }

    Dijkstra(start);
    ans = 0;
    dfs(end,0);
    printf("%d %d",dist[end],ans);
    return 0;
}
