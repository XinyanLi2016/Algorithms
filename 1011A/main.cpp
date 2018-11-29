#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

void dfs(vector<int> *graph,int u,int visited[])
{
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int nbr = graph[u][i];
        if(visited[nbr]==0)
        {
            dfs(graph,nbr,visited);
        }
    }
}

int main()
{
    int N,M;
    while(cin>>N)
    {
        if(N == 0)
            break;
        else
        {
            cin>>M;
            vector<int> graph[MAX];
            int visited[MAX] = {0};
            for (int i = 0; i < N; i++)
            {
                graph[i].clear();
            }
            for(int i = 0; i < M ; i++)
            {
                int u, v;
                cin>>u>>v;
                graph[u-1].push_back(v-1);
                graph[v-1].push_back(u-1);
            }
            int count = 0;
            for(int i=0; i<N; i++)
            {
                if(!visited[i])
                {
                    dfs(graph,i,visited);
                    count++;//每有一个新的未被标记的点就有了一个新的分支
                }
            }
          cout<<count -1<<endl;
        }

    }
    return 0;
}
