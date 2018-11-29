#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 10005
#define INF 0x3f3f3f3f
//树中所有最短路径距离的最大值是书的直径
//在加dist的时候需要用到边的权值  - -还是用链式前向星来存吧
using namespace std;
int n,m,cnt; //cnt是边的计数 从1开始计数
int head[MAX]; //head[i]表示以i为起点的第一条边
int visited[MAX];
int dist[MAX];
int ed,sum;//ed 是最长路径的终点
struct EDGE{

int to;//这条边的终点
int w;//该边的权值
int next;//下一条边的存储下标

};
EDGE edge[MAX];

void Add(int u, int v, int w) //起点u,终点v,权值w
{
    edge[++cnt].next = head[u];
    edge[cnt].w = w;

    edge[cnt].to = v;
    head[u] = cnt;
}
void Print(int st)
{
    /*int st;
    cout<< "begin with[please input]:"<<endl;
    cin >> st;*/
    for(int i = head[st]; i!=0; i = edge[i].next)
    {
        cout<<"start: "<<st<<endl;
        cout<<"end: "<<edge[i].to<<endl;
        cout<<"w: "<<edge[i].w<<endl<<endl;
    }
}
void init()
{
   cnt = 1;
   sum = 0;
   ed = 0;
   memset(head,0,sizeof(head));
}
void bfs(int s)
{
    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(visited));
    queue<int> que;
    ed = s;
    dist[s] = 0;
    visited[s] = 1;
    que.push(s);
    while(!que.empty())
    {
        int u = que.front();
        //int maxDist = 0;
        que.pop();
        for(int i = head[u]; i!=0; i = edge[i].next)
        {
            int v = edge[i].to;
            if(visited[v]==0)
            {
                dist[v] = dist[u] + edge[i].w;
                visited[v] = 1;
                que.push(v);
                if(sum < dist[v])
                {
                    ed = v;
                    sum = dist[v];
                }

            }
        }
        //sum = sum + maxDist;
    }
}
int main()
{

    int x,y,length;
    int num = 0;
    init();
    while(scanf("%d%d%d",&x,&y,&length)!=EOF)
    {
        Add(x,y,length);
        Add(y,x,length);
        num = max(num,x);
        num = max(num,y);
    }
   /* for(int i =1; i <= num; i ++)
    {
        Print(i);
        printf("*********************\n");
    }*/
    bfs(1);//先对任意一点进行搜索 搜索到以该点为起点的最长路径 得到终点
   /* printf("%d\n",sum);
    printf("%d\n",ed);*/
    bfs(ed);//再以上面得到的终点进行搜索  以该终点为起点得到的最长路径一定是整棵树的高度
    printf("%d\n",sum);

    return 0;
}
