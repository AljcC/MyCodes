#include<iostream>
#include<cstring>
using namespace std;
int n,e;
double g[1001][1001];
int main()
{
	int i,j;
	cin>>n>>e;
	memset(g,0x7f,sizeof(g));
	for(i=1;i<=e;i++)
	{
		int x,y;
		double w;
		cin>>x>>y>>w;
		g[x][y]=w;
		g[y][x]=w;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<g[i][j]<<' ';
		cout<<endl; 
	}
	return 0;
}
