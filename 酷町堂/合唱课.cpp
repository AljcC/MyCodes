#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
struct node
{
    int x,y,c;
    bool operator<(const node &p)const{
        if(p.c==c)
        {
            return p.x<x;
         } 
        return p.c<c;
    }
 };
priority_queue<node>que;
int cnt=0;
struct part
{
    int x,y;
}par[100005];
int n,a[200005];
bool f[200005];
char c[200005];
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        node t;
        if(i>1)
        if(c[i-1]!=c[i-2])
        {
                t.x=i-1;
                t.y=i;
                t.c=abs(a[i]-a[i-1]);
                que.push(t);
        }    
    }
    bool flag;
    while(!que.empty())
    {
        flag=0;
        node t=que.top();
        que.pop();
        if(f[t.x]||f[t.y])
        continue;
        par[++cnt].x=t.x;
        f[t.x]=true;
        par[cnt].y=t.y;
        f[t.y]=true;
        while(f[t.x-1])
        {
            if(t.x<=2)
            {
                flag=1;
                break;
            }
            t.x--;
        }
        if(flag==1)
            continue;
        while(f[t.y+1])
        {
            if(t.y>=n-1)
            {
                flag=1;
                break;
            }
            t.y++;
        }
        if(flag==1)
            continue;
        if(c[t.x-2]!=c[t.y]&&t.x>1&&t.y<n)
        {
            t.x=t.x-1;
            t.y=t.y+1;
            t.c=abs(a[t.x]-a[t.y]);
            que.push(t);
        }    
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
        cout<<par[i].x<<' '<<par[i].y<<endl;
    return 0;
}
