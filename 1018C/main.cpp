#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 205
using namespace std;
//�����bug's life ������
int n,m;
int sum;//��������
int guarded[MAX]; //��ʼֵ����Ϊ-1��������ŵ���������Ϊ1�����ܰ�����������Ϊ0
int visited[MAX];
vector<int> graph[MAX];
bool bfs(int s)
{
    int fenliangcnt = 0;
    int num = 0;
    queue<int> que;
    visited[s] = 1;
    num++;
    guarded[s] = 1;//��ʼ��������
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
                guarded[v] = !guarded[u];//��Ϊ�෴
                if(guarded[v]==1)
                {
                    fenliangcnt++;
                }
            }
            else if(guarded[v]==guarded[u])//�ھӽڵ��Ѿ��������������������ο�����ͬ ��˵���г�ͻ
            {
                while(!que.empty())
                {
                    que.pop();
                }
                return false;//�޷�����
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
