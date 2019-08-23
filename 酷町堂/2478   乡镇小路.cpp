#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int v,next;
} edge[1001];
int DFN[1001],LOW[1001];
int stack[1001],heads[1001],visit[1001],cnt,tot,index;
void add(int x,int y)
{
	edge[++cnt].next=heads[x];
	edge[cnt].v = y;
	heads[x]=cnt;
	return;
}
void tarjan(int x)
{
	DFN[x]=LOW[x]=++tot;
	stack[++index]=x;
	visit[x]=1;
	for(int i=heads[x]; i!=-1; i=edge[i].next)
	{
		if(!DFN[edge[i].v])
		{
			tarjan(edge[i].v);
			LOW[x]=min(LOW[x],LOW[edge[i].v]);
		}
		else if(visit[edge[i].v])
			LOW[x]=min(LOW[x],DFN[edge[i].v]);
	}
	if(LOW[x]==DFN[x])
	{
		while(x!=stack[index+1])
		{
			visit[stack[index]]=0;
			index--;
		}
		cout<"Yes\n";
	}
	return;
}
int main()
{
	memset(heads,-1,sizeof(heads));
	int n,m;
	while(cin>>n>>m&&n||m)
	{
		memset(visit,0,sizeof(visit));
		memset(DFN,0,sizeof(DFN));
		memset(LOW,0,sizeof(LOW));
		for(int i=1; i<=m; i++)
		{
			int x,y;
			cin>>x>>y;
			add(x,y);
		}
		for(int i=1; i<=n; i++)
			if(!DFN[i])
				tarjan(i);
	}
	return 0;
}
