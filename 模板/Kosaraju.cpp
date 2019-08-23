#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,color_num,color[10001],a[10001],ind[10001],outd[10001];
bool vis[10001];
vector<int> G[10001];
vector<int> rG[10001];
void dfs(int v)
{
	vis[v]=1;
	for(int i=0;i<G[v].size();i++)
		if(!vis[G[v][i]])
			dfs(G[v][i]);
	a[++cnt]=v;
}
void rdfs(int v,int k)
{
	vis[v]=1;
	color[v]=k;
	for(int i=0;i<rG[v].size();i++)
		if(!vis[rG[v][i]])
			rdfs(rG[v][i],k);
}
int main()
{
	cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    } 
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	memset(vis,0,sizeof(vis));
	for(int i=cnt;i>=1;i--)
		if(!vis[a[i]])
			rdfs(a[i],++color_num);
	for(int u=1; u<=n; u++)
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(color[u]!=color[v])
            {
                ind[color[v]]++;
                outd[color[u]]++;
            }
        }	
    int sum=0,count=0;
    for(int i=1; i<=color_num; i++)
        if(outd[i]==0)
        {
            count++;
            for(int j=1; j<=n; j++)
                if(color[j]==i)
                    sum++;
        }
    if(count==1)
        cout<<sum;
    else cout<<0;
	return 0;
}
