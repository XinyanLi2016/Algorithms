#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#define MAX 1002
#define INF 0x3f3f3f3f
//计算两个车站之间的最短路径 只不过是起点有多个
using namespace std;
int n, m, s;
int map[MAX][MAX];
int visited[MAX];
int dist[MAX];
void Dijkstra(int start)
{
    for(int i = 1 ; i <=n ; i++)
    {
        dist[i] = map[start][i];
        //prev[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    int u;

    for(int i = 1; i <= n; i++)
    {
        int temp = INF;
        for(int j = 1; j <=n ; j++)//find the vertex u with the minimum dist
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
        for(int v = 1; v <= n; v++ )
        {
            if((!visited[v]) && (dist[u] + map[u][v] < dist[v]))
            {
                dist[v] = dist[u] + map[u][v];
                //prev[v] = u;
            }
        }

    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <=n; j++)
                map[i][j] = INF;
        }
        while(m--)
        {
            int p,q,t;
            scanf("%d%d%d",&p,&q,&t);
            if(map[q][p]==INF)
                map[q][p] = t;//这里要注意 因为终点设置为起点 第一次错在这里了
            else if(map[q][p]>t)
                map[q][p] = t;//这是个坑啊 好气  还有重复的边！！ 要取最小的那个！
        }
        int num;
        scanf("%d",&num);
        int start;
        int ans = INF;
        Dijkstra(s);
        while(num--)
        {
            scanf("%d",&start);//倒过来其实也可以
            ans = ans < dist[start] ? ans : dist[start];
        }
        // for (int i = 1 ; i<= n; i++)
        //printf("%d  **",dist[i]);
        if(ans==INF)
            printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
