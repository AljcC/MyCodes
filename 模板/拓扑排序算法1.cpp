/*
拓扑排序算法思想：
1、选择一个入度为0的定点并输出； 
2、然后从AOV网中删除此顶点及以此顶点为起点的所有关联边； 
3、重复上述两步，直到不存在入读为0的顶点为止； 
4、若输出的顶点数小于AOV网中的顶点数，则有回路； 
5、从第4步可以看出拓扑排序可以用来判断一个有向图是否有环。只有有向无环图(DAG)才存在拓扑排序 。
伪代码： 
while(!q.empty())
	{
		u=q.front();
		q.pop();
		list.push(u);//list为解 集合
		for(u的每个邻接点v){
			删除边(u,v);
			if(ind(v)==0)//度为0,进入队列q
				q.push(v); 
		} 
	}
	if(图G还有边存在)
		return 存在环;
	else return list;  
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> G[501];//邻接表 
vector<int> topo;//结果 
int ind[501],V;//入度，顶点个数
void TopSort()
{
	//维护入度为0的节点，编号从小到大排序，保证编号小的节点 小的节点的拓扑排序
	priority_queue<int,vector<int>,greater<int> >que;
	//将入度为0的节点加入队列
	for(int i=0;i<V;i++)
		if(!ind[i])
			que.push(i);
	//循环处理入度为的节点，并赋予拓扑序
	int cnt=0;
	while(!que.empty())
	{
		int u=que.top();
		que.pop();
		//将最小的拓扑序号赋给入度为0且当前编号最小的节点
		topo.push_back(u);
		cnt++;
		//删除节点u出发的边，并调整其他节点的入度
		for(int i=0;i<G[u].size();i++)
		{
			//将调整后入度为0的节点加入队列
			if(--ind[G[u][i]]==0)
				que.push(G[u][i]); 
		} 
	}
	if(cnt!=V)
		return;
	for(int i=0;i<topo.size();i++)
		cout<<topo[i]<<' '; 
} 
int main()
{
	int n;
	cin>>V>>n;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		ind[v]++;
	}
	TopSort(); 
	return 0;
}
