#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 205
using namespace std;
//此题和bug's life 类似呢
int n,m;
int sum;//守卫数量
int guarded[MAX]; //初始值都设为-1，如果安排的守卫则置为1，不能安排守卫则置为0
int visited[MAX];
vector<int> graph[MAX];
bool bfs(int s)
{
    int fenliangcnt = 0;
    int num = 0;
    queue<int> que;
    visited[s] = 1;
    num++;
    guarded[s] = 1;//初始放置守卫
    fenliangcnt++;
    que.push(s);

    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                num++;
                que.push(v);
                guarded[v] = !guarded[u];//置为相反
                if(guarded[v]==1)
                {
                    fenliangcnt++;
                }
            }
            else if(guarded[v]==guarded[u])//邻居节点已经遍历过而且守卫安排形况和相同 则说明有冲突
            {
                while(!que.empty())
                {
                    que.pop();
                }
                return false;//无法安排
            }
        }
    }
    while(!que.empty())
    {
        que.pop();
    }
    if((num-fenliangcnt)==0)
    {
        sum+= fenliangcnt;
    }
    else
    {
        sum += min(fenliangcnt,num-fenliangcnt);

    }
    return true;
}
void init()
{
    for(int i = 0; i < n; i++)
    {
        graph[i].clear();
    }
    sum = 0;
    memset(guarded,-1,sizeof(guarded));
    memset(visited,0,sizeof(visited));
}
int main()
{
    int T;
    int x,y;
    cin>>T;
    while(T--)
    {
        init();
        cin>>n>>m;
        for(int i = 0; i < m; i++)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool impossible = false;

        for(int i = 0; i < n; i++)
        {
            if((visited[i]==0)&&(!bfs(i)))
            {
                impossible = true;
               // cout<<"break at "<<i<<endl;
                break;
            }

        }
      /*  for(int i = 0; i < n ; i++)
        {
            cout<<i<<"**"<<guarded[i]<<"**visited: "<<visited[i]<<endl;
        } */
        if(impossible)
        {
            cout<<"-1"<<endl;
        }
        else
        {

           cout<<sum<<endl;
        }
    }


    return 0;
}
