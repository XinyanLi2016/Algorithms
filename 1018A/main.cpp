#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define max 2005
using namespace std;
//该题建立无向图
int n,m;
int visited[max];
int sex[max];//每只虫子对应的性别 1-雄性 0- 雌性
vector<int> graph[max];
void init()
{
    for(int i = 0; i <= n; i++)
    {
        graph[i].clear();
    }
    memset(visited,0,sizeof(visited));
    memset(sex,0,sizeof(sex));
}
bool bfs(int u)//广度优先搜索一个点是否和其邻居节点性别相同
{
    queue<int> que;
    visited[u] = 1;
    sex[u] = 1;//先初始一个性别为雄性
    que.push(u);
    while(!que.empty())
    {
        int nbr;
        nbr = que.front();
        que.pop();
        for(int i = 0; i < graph[nbr].size(); i++)
        {
            if(visited[graph[nbr][i]]==0)
            {
                visited[graph[nbr][i]] = 1;
                que.push(graph[nbr][i]);
                sex[graph[nbr][i]] = !sex[nbr]; //将其邻居节点性别设置为相反
            }
            else if(sex[nbr]==sex[graph[nbr][i]])//性别和邻居节点性别相同
            {
                while(!que.empty())
                {
                    que.pop();
                }
                return true;
            }
        }

    }
    while(!que.empty())
    {
        que.pop();
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    int x,y;
    for(int t = 1; t <=T; t++)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 1; i <=m; i++)
        {
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        printf("Scenario #%d:\n",t);
        bool hasS = false;
        for(int i = 1; i <= n; i++)
        {
            if((visited[i]==0)&&(bfs(i)))
            {
                hasS = true;
                break;
            }
        }
        if(hasS)
        {
            printf("Suspicious bugs found!");
            printf("\n\n");
        }
        else
        {
            printf("No suspicious bugs found!");
            printf("\n\n");
        }
        /*for(int i = 1; i <=n; i++)
        {
            printf("%d*%d  ",i,sex[i]);
        }
        printf("\n");*/
    }
    return 0;
}
