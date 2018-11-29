#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 10005
#define INF 0x3f3f3f3f
//�����������·����������ֵ�����ֱ��
//�ڼ�dist��ʱ����Ҫ�õ��ߵ�Ȩֵ  - -��������ʽǰ���������
using namespace std;
int n,m,cnt; //cnt�Ǳߵļ��� ��1��ʼ����
int head[MAX]; //head[i]��ʾ��iΪ���ĵ�һ����
int visited[MAX];
int dist[MAX];
int ed,sum;//ed ���·�����յ�
struct EDGE{

int to;//�����ߵ��յ�
int w;//�ñߵ�Ȩֵ
int next;//��һ���ߵĴ洢�±�

};
EDGE edge[MAX];

void Add(int u, int v, int w) //���u,�յ�v,Ȩֵw
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
    bfs(1);//�ȶ�����һ��������� �������Ըõ�Ϊ�����·�� �õ��յ�
   /* printf("%d\n",sum);
    printf("%d\n",ed);*/
    bfs(ed);//��������õ����յ��������  �Ը��յ�Ϊ���õ����·��һ�����������ĸ߶�
    printf("%d\n",sum);

    return 0;
}
