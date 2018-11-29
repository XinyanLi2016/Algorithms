#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define max 10005
//该题判断图是否为强连通 暴力对每个节点dfs 判断能否到达所有节点
vector<int> graph[max];
int visited[max];
//int in[max];
//int out[max];
int n,m;
void dfs(int u)
{
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int nbr = graph[u][i];
        if(visited[nbr]==0)
        {
            dfs(nbr);
        }
    }
}
bool judge(int u)
{
    dfs(u);
    for(int i = 1; i <= n ; i++)
    {
        if(visited[i]==0)
            return false;
    }
    return true;
}
void init()
{
    for (int i = 1; i <=n; i++)
    {
        graph[i].clear();
    }
   // memset(in,0,sizeof(in));
    //memset(out,0,sizeof(out));
    memset(visited,0,sizeof(visited));
}
int main()
{

    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        init();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
            //in[y]++;
            //out[x]++;
        }
        bool can = true;
        for(int i = 1; i<= n; i++)
        {
            if(!judge(i))
                {can  = false;}
            else
                {
                    for(int i = 1; i <= n ;i ++)
                    {
                        visited[i]=0;
                    }
                }
        }
        if(can) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
