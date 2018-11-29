#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX 502
#define INF 0x3f3f3f3f
using namespace std;
int map[MAX][MAX];
int n,m,w;
//这道题用spfa判断有没有负环
int num[MAX];//记录进入队列的次数
int visited[MAX];
int dist[MAX];
bool spfa()
{
    queue<int> Q;
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        num[i] = 0;
    }
    Q.push(1);
    visited[1] = 1;
    num[1]= 1;
    dist[1] = 0;
    while(!Q.empty())
    {
        int s = Q.front();
        Q.pop();
        visited[s] = 0;
        for(int i = 1; i <=n; i++ )
        {
         if(dist[s] + map[s][i] < dist[i])
         {
             dist[i] = dist[s] + map[s][i];
             if(visited[i]==0)
             {
                 num[i] ++;
                 if(num[i]==n) //入队次数等于n说明有负环存在
                    return false;
                 else
                    visited[i] = 1;
                 Q.push(i);
             }
         }
        }
    }
    return true;
}
int main()
{
    int F;
    scanf("%d",&F);
    while(F--)
    {

        scanf("%d%d%d",&n,&m,&w);
        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(i== j) map[i][j] = 0;
                else   map[i][j] = INF;
            }
        }
        while(m--)
        {
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            if(map[s][e]>t)
            {
                map[s][e] = t;
                map[e][s] = t;
            }
        }
        while(w--)
        {
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            map[s][e] = -t;

        }
        if(spfa())
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
