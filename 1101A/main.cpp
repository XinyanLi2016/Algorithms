#include <iostream>
#include <queue>
using namespace std;

int main()
{
   int n,length;
   long long int sum;
   int a,b;
   priority_queue<int,vector<int>,greater<int> > q;
   while(cin>>n)
   {

       for(int i = 0; i <n; i++)
       {
           cin>>length;
           q.push(length);
       }
       sum = 0;
       while(q.size()>1){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        sum+= a+b;
        q.push(a+b);
       }
       while(!q.empty()) q.pop();//«Âø’∞°≈Û”—
       cout<<sum<<endl;
   }
    return 0;
}
