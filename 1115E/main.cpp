#include <iostream>
#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 100002
using namespace std;
//对于未来最近会用到的内存单元不被替换
struct node{
 int value;//该节点的值
 int nextv;//该节点下一此出现的位置
 node(int v, int n){value = v; nextv = n;}
 bool operator < (node t) const{return nextv < t.nextv;}
 };
 priority_queue<node> q; //默认大根堆 使下一次出现位置靠后的节点在上
 map<int,int>s,vis; //用map方便计算一个节点的next  map用法的方便之处还需要再了解了解
 //vis用于记录要访问的内存是否在cache中 用map是因为map方便动态管理
 //优先队列不代表cache，而是作为一个排序的工具，在q里的不一定在cache中
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
    //开始对每个节点的next进行计算 在想的时候想了很久 此处有参考
    for(int i = N; i >=1; i--)
    {
        if(s.count(mem[i]))
            next[i] = s[mem[i]];//从后往前找 如果该节点在后面出现过则能找到对应的位置
        else next[i] = N+1;//最后出现的节点们的next都赋值为N+1
        s[mem[i]] = i;
    }

    int cap = 0;//cache内拥有的内存单元个数
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
       if(vis[mem[i]])//访问的内存已经在cache中则更改一下node的next
       {
           q.push(node(mem[i],next[i]));
           continue;
       }
       if(cap == M)//如果cache容量不足则需要进行缓存交换
       {
           cap--;
           while(!q.empty())
           {
               node change = q.top();
               q.pop();
               if(!vis[change.value]) continue;
               vis[change.value] = 0;//表示已经不在cache里
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
