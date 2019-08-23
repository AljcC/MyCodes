/*
树状数组

函数lowbit
对于正整数x、lowbit(x)的值为x的二进制表达式中最右边的1所相对应的值
比如：x=6,那么x的二进制表达式是110，因此lowbit(6)=2;
实现：lowbit(x)=x&(-x)

函数sum
计算A[1]+A[2]+...+A[x](x<=n)
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

函数add
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
//例题:https://www.luogu.org/problemnew/show/UVA1428 
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
