#include <iostream>
#include <algorithm>
using namespace std;
int f[100001],a[100001],b[100001][3],fl[100001];
int find(int x)
{
    if (f[x]==x)
        return x;
    f[x]=find(f[x]);
    return f[x];
}
int init(int x,int y)
{
    if (find(x)!=find(y))
    {
        f[find(x)]=find(y);
        return 1;
    }
    return 0;
}
int cmp(int x,int y)
{
    return x<y;
}
int main()
{
    int n,m,t=0;
    cin>>n>>m;
    for (int i=0;i<=n*2;i++)
        f[i]=i;
    for (int i=1;i<=m;i++)
    {
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        if (ch=='0')
            init(x,y);
        else 
        {
            init(x,y+n);
            init(y,x+n);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        a[i]=find(f[i]);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
        if (a[i]!=a[i-1]) ans++;
    cout<<ans;
    return 0;
}
