#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX1 100001
#define MAX2 500001
using namespace std;
int N,M;
vector<int> graph[MAX2];
int in[MAX1] = {0};
/*void dfs(vector<int> *graph,int u,int visited[])
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
}*/
bool topo_sort()
{
    queue<int> que;
    for (int i = 0; i < N; i++)
    {
        if (in[i]==0)
           {
               que.push(i);
               //cout<<i<<"**"<<endl;
           }
    }
    int count = 0;

    while(!que.empty())
    {
        int u = que.front();
        //cout<<u<<"pop"<<endl;
        que.pop();
        count++;
        int length = graph[u].size();
        for(int i = 0; i < length; i++)
        {
            int v = graph[u][i];
            in[v]--;
            if(in[v]==0)
            {
                que.push(v);
            }
        }
    }
    if(count == N)
        return true;
    else
        return false;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {

      cin>>N>>M;
            for (int i = 0; i < N; i++)
            {
                graph[i].clear();
            }
            memset(in,0,sizeof(in));
            int u, v;
            for(int i = 0; i < M ; i++)
            {
                cin>>u>>v;
                graph[u-1].push_back(v-1);
                in[v-1]++;
            }
            /*for(int i = 0; i < N; i++)
            {
                cout<<i<<"rudu"<<in[i]<<endl;
            }
            cout<<"hello"<<endl;*/
            if(topo_sort())
                cout<<"Correct"<<endl;
            else
                cout<<"Wrong"<<endl;


    }
    return 0;
}
