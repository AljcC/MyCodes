#include<iostream>
using namespace std;
int n,m,g[1001][1001],ans[1001]; 
bool f[1001];
bool dfs(int u,int t)
{
	if(t>n)
	{
		if(g[u][1])
			return 1;
		else return 0; 
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(g[u][i]&&!f[i])
			{
				ans[t]=i;
				f[i]=1;
				if(dfs(i,t+1))
					return 1;
				f[i]=0;
			} 
	} 
	return 0;
}
int main()
{
	int i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u][v]=g[v][u]=1;
	}
	ans[1]=1,f[1]=1;
	if(dfs(1,2))
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
	else cout<<"Error!!";
	return 0;
}
