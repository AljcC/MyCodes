/*
���������㷨˼�룺
1��ѡ��һ�����Ϊ0�Ķ��㲢����� 
2��Ȼ���AOV����ɾ���˶��㼰�Դ˶���Ϊ�������й����ߣ� 
3���ظ�����������ֱ�����������Ϊ0�Ķ���Ϊֹ�� 
4��������Ķ�����С��AOV���еĶ����������л�·�� 
5���ӵ�4�����Կ�������������������ж�һ������ͼ�Ƿ��л���ֻ�������޻�ͼ(DAG)�Ŵ����������� ��
α���룺 
while(!q.empty())
	{
		u=q.front();
		q.pop();
		list.push(u);//listΪ�� ����
		for(u��ÿ���ڽӵ�v){
			ɾ����(u,v);
			if(ind(v)==0)//��Ϊ0,�������q
				q.push(v); 
		} 
	}
	if(ͼG���бߴ���)
		return ���ڻ�;
	else return list;  
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> G[501];//�ڽӱ� 
vector<int> topo;//��� 
int ind[501],V;//��ȣ��������
void TopSort()
{
	//ά�����Ϊ0�Ľڵ㣬��Ŵ�С�������򣬱�֤���С�Ľڵ� С�Ľڵ����������
	priority_queue<int,vector<int>,greater<int> >que;
	//�����Ϊ0�Ľڵ�������
	for(int i=0;i<V;i++)
		if(!ind[i])
			que.push(i);
	//ѭ���������Ϊ�Ľڵ㣬������������
	int cnt=0;
	while(!que.empty())
	{
		int u=que.top();
		que.pop();
		//����С��������Ÿ������Ϊ0�ҵ�ǰ�����С�Ľڵ�
		topo.push_back(u);
		cnt++;
		//ɾ���ڵ�u�����ıߣ������������ڵ�����
		for(int i=0;i<G[u].size();i++)
		{
			//�����������Ϊ0�Ľڵ�������
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
