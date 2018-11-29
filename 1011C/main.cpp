#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX1 100005
#define MAX2 1000005
#define MIN 0x7fffffff
using namespace std;
//一条路径上 起始点入度为0，终止点出度为0
int n,m;//n个点，m条边
int val[MAX1];//每个点的权值
int in[MAX1],out[MAX1];//每个点的入度 出度
int dp[MAX1];//以该点为终点的路径最大权值和
vector<int> graph[MAX1];
void init()
{
    for (int i = 1; i <=n; i++)
    {
        graph[i].clear();
    }
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
}
void topo_sort()
{
    queue<int> que;
    for (int i = 1; i <=n; i++)
    {
        if (in[i]==0)
        {
            que.push(i);
            dp[i] = val[i];
            //cout<<i<<"**"<<endl;
        }
        else
            dp[i] = -MIN;
    }


    while(!que.empty())
    {
        int u = que.front();
        //cout<<u<<"pop"<<endl;
        que.pop();

        int length = graph[u].size();
        for(int i = 0; i < length; i++)
        {
            int v = graph[u][i];
            dp[v] = max (dp[v],dp[u] + val[v]);
            in[v]--;
            if(in[v]==0)
            {
                que.push(v);
            }
        }
    }
}
int main()
{
    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i = 1; i <=n ; i++)
        {
            scanf("%d",&val[i]);//为什么scanf就可以不超时呢？？
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
            out[x]++;
            in[y]++;
        }
       /* for(int i = 1; i <= n; i ++)
        {
            if(in[i]==0)
                dp[i] = val[i];
            else
                dp[i] = -MIN;
        }*/
        topo_sort();
        int result = -MIN;
        for(int i =1; i <= n; i++)
        {
            if(out[i]==0)
                result = max(result, dp[i]);
        }
        printf("%d\n",result);
    }
    return 0;
}
