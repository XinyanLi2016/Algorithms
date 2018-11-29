#include <iostream>
#include <stdio.h>
#define MAX 1005
using namespace std;
double map[MAX][MAX];
int visited[MAX];
double safe[MAX];
int n;

void init()
{
    for(int i = 1; i <=n; i++)
    {
        for( int j = 1; j <= n ; j++)
        {
            map[i][j] = 0.0;
        }
    }
}
void Print()//- - 测试用的
{
     for(int i = 1; i <=n; i++)
        {
            for( int j = 1; j <= n ; j++)
            {

               printf("%lf* ",map[i][j]);
            }
            printf("\n");
        }
}
void Dijkstra(int s)
{
    for(int i = 1 ; i <=n ; i++)
    {
        safe[i] = map[s][i];
        //prev[i] = INF;
        visited[i] = 0;
    }
    safe[s] = 1;
    visited[s] = 1;
    int u;

    for(int i = 1; i <=n; i++)
    {
        double temp = 0;
        for(int j = 1; j <=n ; j++)//找到最安全的道路
        {
            if((visited[j]==0)&&(temp < safe[j]))
            {
                u = j;
                temp = safe[j];
            }
        }
        if(temp == 0)
            break;
        visited[u] = 1; //erase u
        for(int v = 1; v <= n; v++ )
        {
            if((visited[v]==0)&&(safe[u]*map[u][v]>safe[v]))
            {
                safe[v] = safe[u]*map[u][v];
                //prev[v] = u;
            }
        }

    }
}

int main()
{

    while(scanf("%d",&n)!=EOF)
    {
        init();
        double tmp;
        for(int i = 1; i <=n; i++)
        {
            for( int j = 1; j <= n ; j++)
            {
                scanf("%lf",&map[i][j]);
            }
        }
       // Print();
        int Q;
        scanf("%d",&Q);
        int start, end;
        while(Q--)
        {
          scanf("%d%d",&start,&end);
          Dijkstra(start);
          if(safe[end]==0)
            printf("What a pity!\n");
          else
            printf("%.3f\n",safe[end]);
        }
    }
    return 0;
}
