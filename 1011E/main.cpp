#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define max 10005

vector<int> graph[max];
vector<int> graphT[max];//��ͼ
vector<int> newGraph[max];//������ͼ
vector<int> List;
int suodianIn[max];//����֮��ÿ��������
int suodianPos[max];//��ͼ��ÿ�����Ӧ������λ��
int visited[max];//��ԭͼ
int newVisited[max];//����ͼ
int n,m;
int suodianNum;//�������
void init()
{
    for (int i = 1; i <=n; i++)
    {
        graph[i].clear();
        newGraph[i].clear();
        graphT[i].clear();
        }

    suodianNum = 0;
    List.clear();
    memset(visited,0,sizeof(visited));
    memset(newVisited,0,sizeof(newVisited));
    memset(suodianIn,0,sizeof(suodianIn));
    memset(suodianPos,0,sizeof(suodianPos));
}
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
    List.push_back(u);//����ʱ������ ��������ʱ��
}
void DFS(int u)//����ͼ��������
{
    newVisited[u] = 1;
    suodianPos[u] = suodianNum;
    for (int i = 0; i < graphT[u].size(); i++)
    {
        int nbr = graphT[u][i];
        if(newVisited[nbr]==0)
        {
            DFS(nbr);
        }
    }
}
bool topo_sort()
{
    queue<int> que;
    for (int i = 1; i <=suodianNum; i++)
    {
        if (suodianIn[i]==0)
        {
            que.push(i);

            //cout<<i<<"**"<<endl;
        }

    }
    int count = 0;

    while(!que.empty())
    {
		if (que.size()> 1)
			return false;
		else
		{
			int u = que.front();
			//cout<<u<<"pop"<<endl;
			que.pop();

			count++;
			int length = newGraph[u].size();
			for (int i = 0; i < length; i++)
			{
				int v = newGraph[u][i];

				suodianIn[v]--;
				if (suodianIn[v] == 0)
				{
					que.push(v);
				}
			}
		}
    }
    if(count == suodianNum)
        return true;
    else
        return false;
}
int main()
{
    int T;
    int x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
            graphT[y].push_back(x);
        }

        for(int i = 1; i<= n; i++)//��ԭͼ������¼���е��������ʱ��Ž�������
        {
            if(visited[i]==0)
                dfs(i);
        }

        for(int i = List.size()-1; i >=0; i--) //����ͼ����������
        {

            if(newVisited[List[i]]==0)
            {
                suodianNum++;
                int v = List[i];
                DFS(v);
            }

        }
        for (int i =1; i <= n ;i++)
        {
            newVisited[i] =0;
        }
        //��ʼ����������ͼ
		//printf("***suodianshuliang %d\n", suodianNum);
        for(int i = 1; i <= suodianNum;i++)
        {
            for(int j = 1; j <= n ;j++)
            {
                if((newVisited[j]==0)&&(suodianPos[j]==i))
                   {
                       newVisited[j]=1;
                       for(int k = 0; k < graphT[j].size();k++)
                        {
                            int target = graphT[j][k];
                            if(i!=suodianPos[target])
                            {
                                newGraph[i].push_back(suodianPos[target]);
                                suodianIn[suodianPos[target]]++;
                            }
                        }
                   }
            }
        }
      /* for(int i =1; i<= suodianNum; i++)
        {
            for(int j =0; j < newGraph[i].size();j++)
            {
                printf("%d->%d...",i,newGraph[i][j]);

            }
			printf("    %d",suodianIn[i]);
            printf("\n");
        }*/





        if(topo_sort()) printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
