//DFS��������
int topo[501],vis[501],V,cntn;
vector<int> G[501];
bool DFS(int u)
{
	vis[u]=-1;//���ڷ���
	for(int i=1;i<G[u].size();i++)
	{
		int v=G[u][i];
		//�������򻷣�ʧ���˳�
		if(vis[v]==-1)
			return 0;
		//û�з��ʹ�v����DFS(v)�޽�
		if(!vis[v]&&!DFS(v))
			return 0;
		//��vis[v]==1���������κδ���
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
