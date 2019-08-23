//DFS拓扑排序：
int topo[501],vis[501],V,cntn;
vector<int> G[501];
bool DFS(int u)
{
	vis[u]=-1;//正在访问
	for(int i=1;i<G[u].size();i++)
	{
		int v=G[u][i];
		//存在有向环，失败退出
		if(vis[v]==-1)
			return 0;
		//没有访问过v，且DFS(v)无解
		if(!vis[v]&&!DFS(v))
			return 0;
		//若vis[v]==1，不进行任何处理
	}
	top[cnt++]=u;
	vis[u]=1;
	return 1;
}
bool TopSort()
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<V;i++)
		if(!vis[i]&&!dfs(i))
			return 0;
	return 1;
}
