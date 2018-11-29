#include <iostream>
#include <string>
#include  <queue>
#define D 8
using namespace std;


int dx[D] = {1, 2, 2, 1,-1,-2,-2,-1};
int dy[D] = {-2, -1, 1, 2,2,1,-1,-2};
int chess[8][8];
struct node{
int x,y,step;
};
node startp;
node endp;
void init()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }

}
int  bfs(node &startp, node &endp)
{
    queue<node> Q;
    chess[startp.x][startp.y] = 1;
    Q.push(startp);

    while(!Q.empty())
    {
       node u = Q.front();
       Q.pop();
       if(u.x == endp.x && u.y == endp.y ) return u.step;

       for(int i = 0; i < 8; i++)
       {
           int cx = u.x + dx[i];
           int cy = u.y + dy[i];
           if(cx < 0 || cx > 7 || cy < 0 || cy > 7) continue;
           if(chess[cx][cy] == 1) continue;
           node n;
           n.x = cx;
           n.y = cy;
           n.step = u.step + 1;
           Q.push(n);
        }

    }
   return -1;
}
int main()
{
    char str[6];
    while(cin.getline(str,6))
    {
        init();
       // cout<<str<<endl;
       // cout<<str[0]<<str[1]<<" **"<<str[3]<<str[4]<<endl;
        startp.x = str[0]-'a';
        startp.y = str[1]-'1';
        startp.step = 0;
        endp.x = str[3]-'a';
        endp.y = str[4]-'1';

        int ans = bfs(startp,endp);
       // cout<<"start: "<<startp.x<<" "<<startp.y<<endl;
       // cout<<"end: "<<endp.x<<" "<<endp.y<<endl;
        cout<<"To get from "<<str[0]<<str[1]<<" to "<<str[3]<<str[4]<<" takes "<<ans<<" knight moves."<<endl;
    }
    return 0;
}
