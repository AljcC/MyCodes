#include<bits/stdc++.h>
using namespace std;
int n,data[1001],cnt[1001],G[1001][1001];
bool used[1001];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>data[i],cnt[i]=1;
	int a,b,c;
	memset(G,-1,sizeof(G));
	while(cin>>a>>b>>c)
	{
		G[a][b]=c;
		G[b][a]=c;
	} 
	for(int i=0;i<n;i++)
	{
		int v=-1;
		for(int j=0;j<=n;j++)
			if(!used[j]&&(v==-1||data[v]>data[j]))
				v=j;
		used[v]=1;
		for(int j=0;j<n;j++)
		{
			if(used[j]&&G[v][j]!=-1)
			{
				if(data[G[v][j]]>data[v]+data[j])
				{
					data[G[v][j]]=data[v]+data[j];
					cnt[G[v][j]]=cnt[v]*cnt[j];
				}
				else if(data[G[v][j]]==data[v]+data[j])
					cnt[G[v][j]]+=cnt[v]*cnt[j];
			}
		}
	}
	cout<<data[0]<<" "<<cnt[0];
	return 0;
} 
