#include<bits/stdc++.h>
using namespace std;
bool vis[1010];
int n,m,S,G[1010][1010],d[1010];
void dijkstra(int sum)
{
    fill(d+1,d+n+1,2147483647);
    d[sum]=0;
    memset(vis,0,sizeof(vis));
    while(1)
	{
        int v=-1;
        for (int i=1;i<=n;i++)
            if (!vis[i]&&(v==-1||d[i]<d[v]))
				v=i;
        if (v==-1)
			break;
        vis[v]=1;
        for (int i=1;i<=n;i++)
            if (!vis[i]&d[v]+G[v][i]<d[i])
                d[i]=d[v]+G[v][i];
	}
	for(int i=1;i<=n;i++)
		cout<<d[i]<<' ';
}
int main()
{
    cin>>n>>m>>S;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            G[i][j]=1e9;
        G[i][i]=0;
    }
    for (int i=1;i<=m;i++)
	{
        int to,sum,cost;
        cin>>to>>sum>>cost;
        if(to==sum)
			continue; 
        G[to][sum]=min(G[to][sum],cost);
        G[sum][to]=min(G[sum][to],cost);
    }
    dijkstra(S);
    return 0;
}
