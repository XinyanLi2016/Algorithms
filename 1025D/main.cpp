#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#define MAX 205
#define INF 0x3f3f3f3f
using namespace std;

int n;
double dist[MAX];
int visited[MAX];
double path[MAX][MAX];//储存两块石头的距离
struct Node
{
    double x;
    double y;
    Node(){}
    Node(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

Node stone[MAX];

double Dijsktra(int s)
{
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = path[s][i];
    }
    dist[s] = 0;
    int u;
    visited[s] = 1;
    for(int i = 0; i < n; i++)
    {
        int temp = INF;
        for(int j = 0; j <n ; j++)//find the vertex u with the minimum dist
        {
            if((visited[j]==0)&&(temp > dist[j]))
            {
                u = j;
                temp = dist[j];
            }
        }

        visited[u] = 1; //erase u
        for(int v = 0; v < n; v++ )
        {
            double maxd = max(dist[u],path[u][v]);
            dist[v] = min (dist[v],maxd);
        }

    }
    return dist[1];
}
int main()
{

    int num = 0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i = 0; i < n ; i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            stone[i]=Node(x,y);
        }
        for(int i =0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                double dx = pow((stone[i].x-stone[j].x),2);
                double dy = pow((stone[i].y-stone[j].y),2);
                path[i][j] = sqrt(dx+dy);
            }
        }
        num++;
        double ans;
        ans = Dijsktra(0);
        printf("Scenario #%d\n",num);
        printf("Frog Distance = %.3f\n\n",ans);
    }
    return 0;
}
