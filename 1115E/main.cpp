#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 100002
using namespace std;
//����δ��������õ����ڴ浥Ԫ�����滻
struct node{
 int value;//�ýڵ��ֵ
 int nextv;//�ýڵ���һ�˳��ֵ�λ��
 node(int v, int n){value = v; nextv = n;}
 bool operator < (node t) const{return nextv < t.nextv;}
 };
 priority_queue<node> q; //Ĭ�ϴ���� ʹ��һ�γ���λ�ÿ���Ľڵ�����
 map<int,int>s,vis; //��map�������һ���ڵ��next  map�÷��ķ���֮������Ҫ���˽��˽�
 //vis���ڼ�¼Ҫ���ʵ��ڴ��Ƿ���cache�� ��map����Ϊmap���㶯̬����
 //���ȶ��в�����cache��������Ϊһ������Ĺ��ߣ���q��Ĳ�һ����cache��
int mem[MAX];
int next[MAX];
int N,M;
int main()
{

    scanf("%d%d",&N,&M);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d",&mem[i]);
    }
    //��ʼ��ÿ���ڵ��next���м��� �����ʱ�����˺ܾ� �˴��вο�
    for(int i = N; i >=1; i--)
    {
        if(s.count(mem[i]))
            next[i] = s[mem[i]];//�Ӻ���ǰ�� ����ýڵ��ں�����ֹ������ҵ���Ӧ��λ��
        else next[i] = N+1;//�����ֵĽڵ��ǵ�next����ֵΪN+1
        s[mem[i]] = i;
    }

    int cap = 0;//cache��ӵ�е��ڴ浥Ԫ����
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
       if(vis[mem[i]])//���ʵ��ڴ��Ѿ���cache�������һ��node��next
       {
           q.push(node(mem[i],next[i]));
           continue;
       }
       if(cap == M)//���cache������������Ҫ���л��潻��
       {
           cap--;
           while(!q.empty())
           {
               node change = q.top();
               q.pop();
               if(!vis[change.value]) continue;
               vis[change.value] = 0;//��ʾ�Ѿ�����cache��
               break;
           }
       }
       cap++;
       ans++;
       vis[mem[i]] = 1;
       q.push(node(mem[i],next[i]));
    }
    printf("%d\n",ans);
    return 0;
}
