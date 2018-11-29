#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define max 2005
using namespace std;
//���⽨������ͼ
int n,m;
int visited[max];
int sex[max];//ÿֻ���Ӷ�Ӧ���Ա� 1-���� 0- ����
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
bool bfs(int u)//�����������һ�����Ƿ�����ھӽڵ��Ա���ͬ
{
    queue<int> que;
    visited[u] = 1;
    sex[u] = 1;//�ȳ�ʼһ���Ա�Ϊ����
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
                sex[graph[nbr][i]] = !sex[nbr]; //�����ھӽڵ��Ա�����Ϊ�෴
            }
            else if(sex[nbr]==sex[graph[nbr][i]])//�Ա���ھӽڵ��Ա���ͬ
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
