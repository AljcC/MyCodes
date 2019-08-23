#include<iostream>
#include<cstring> 
using namespace std;
int n,e;
bool g[1001][1001],visited[1001]; 
int dfs(int i)
{
	cout<<i<<' ';
	visited[i]=1;
	for(int j=1;j<=n;j++)
		if(g[i][j]!=0&&!visited[j])
			dfs(j);
}
int main()
{
    int i,j;
	cin>>n>>e;
	memset(g,0x7f,sizeof(g));
	for(i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	for(i=1;i<=n;i++)
		if(!visited[i]) 
			dfs(i);
	return 0;
}
