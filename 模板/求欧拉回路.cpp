#include<iostream>
using namespace std;
int n,m,g[1001][1001],degree[1001];
void dfs(int u)
{
	for(int i=1;i<=n;i++)
		if(g[u][i])
		{
			g[u][i]=g[i][u]=0;
			dfs(i);
		}
	cout<<u<<' ';
}
int main()
{
	int i,num=0;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u][v]=g[v][u]=1;
		degree[u]++;
		degree[v]++;
	}
	for(i=1;i<=n;i++)
		if(degree[i]%2==1)
			num++;
	if(num!=0&&num!=2)
	{
		cout<<"Error£¡£¡" ;
		return 0;
	}
	int start=1;
	for(i=1;i<=n;i++)
		if(degree[i]%2)
		{
			start=i;
			break;
		}
	dfs(start);
	return 0;
}
