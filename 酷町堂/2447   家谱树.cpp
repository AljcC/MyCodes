#include<bits/stdc++.h>
using namespace std;
int G[101][101],n,indegree[101],topo[101];
priority_queue<int,vector<int>,greater<int> > q;
void TopSort()
{
	for(int i=1;i<=n;i++)
		if(!indegree[i])
			q.push(i);
	int cnt=0;
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		cnt++;
		topo[cnt]=u;
		for(int i=1;i<=n;i++)
			if(G[u][i]!=0)
			{
				indegree[i]--;
				if(!indegree[i])
					q.push(i);
			}
	}
	for(int i=1;i<=n;i++)
		cout<<topo[i]<<' '; 
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		while(cin>>x&&x)
		{
			G[i][x]=1;
			indegree[x]++;
		}
	}
	TopSort();
	return 0;
} 
