/*
��״����

����lowbit
����������x��lowbit(x)��ֵΪx�Ķ����Ʊ��ʽ�����ұߵ�1�����Ӧ��ֵ
���磺x=6,��ôx�Ķ����Ʊ��ʽ��110�����lowbit(6)=2;
ʵ�֣�lowbit(x)=x&(-x)

����sum
����A[1]+A[2]+...+A[x](x<=n)
int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
}

����add
A[x]+=d(1<=x<=n)
void add(int x,int d)
{
	while(x<=n)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}
*/
//����:https://www.luogu.org/problemnew/show/UVA1428 
#include<bits/stdc++.h>
using namespace std;
int b[100005],a[20000],x[20000],y[20000];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x)
{
	while(x<=100000)
	{
		b[x]++;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=b[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0; i<n; i++)
			cin>>a[i];
		memset(b,0,sizeof(b));
		for(i=0; i<n; i++)
		{
			x[i]=sum(a[i]-1);
			add(a[i]);
		}
		memset(b,0,sizeof(b));
		for(i=n-1; i>=0; i--)
		{
			y[i]=sum(a[i]-1);
			add(a[i]);
		}
		long long res=0;
		for(i=0; i<n ; i++)
			res+=(i-x[i])*y[i]+x[i]*(n-i-1-y[i]);
		cout<<res<<"\n";
	}
	return 0;
}
