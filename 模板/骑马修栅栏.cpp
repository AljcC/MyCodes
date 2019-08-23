#include<iostream>
using namespace std;
int num[501],g[501][501],a[5000],t=0,n,maxn=0;
void dfs(int u)
{
    for(int i=1;i<=maxn;i++)
    	if(g[u][i])
    	{
            g[u][i]--;
            g[i][u]--;
        	dfs(i);
    	}
    t++;
	a[t]=u;
}
int main()
{
    int start=501,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	int u,v;
        cin>>u>>v;
        g[u][v]++;
        g[v][u]++;
        num[u]++;
        num[v]++;
        maxn=max(maxn,max(u,v));
        start=min(start,min(u,v));
    }
    for(i=1;i<=maxn;i++)
    {
        if(num[i]%2==1)
        {
            dfs(i);
            while(t)
                cout<<a[t--]<<endl;
            return 0;
        }
    }
    dfs(start);
    while(t)
        cout<<a[t--]<<endl;
    return 0;
}
