#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=100000;
#define LL long long
LL sp[4*MAXN+10],add[4*MAXN+10];
int n,m;
void up(int id)
{
	sp[id]=sp[id*2]+sp[id*2+1]; 
} 
void build(int id,int l,int r)
{
	if(l==r)
	{
		scanf("%lld",&sp[id]);
		return;
	}
	int m=(l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	up(id);
} 
void down(int id,int l,int r)
{
	if(add[id])
	{
		add[id*2]+=add[id];
		add[id*2+1]+=add[id];
		int m=(l+r)/2;
		sp[id*2]+=(m-l+1)*add[id];
		sp[id*2+1]+=(r-m)*add[id];
		add[id]=0;
	}
}
void update(int id,int l,int r,int x,int y,int v)
{
	if(x<=l&&r<=y)
	{
		add[id]+=v;
		sp[id]+=(r-l+1)*v;
		return;
	}
	down(id,l,r);
	int m=(l+r)/2;
	if(x<=m)
		update(id*2,l,m,x,y,v);
	if(y>m)
		update(id*2+1,m+1,r,x,y,v);
	up(id);
}
LL query(int id,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
		return sp[id];
	down(id,l,r);
	int m=(l+r)/2;
	LL ret=0;
	if(ql<=m)
		ret+=query(id*2,l,m,ql,qr);
	if(qr>m)
		ret+=query(id*2+1,m+1,r,ql,qr);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--)
	{
		int t,x,y,k;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
		{
			scanf("%d",&k);
			update(1,1,n,x,y,k);
		}
		else printf("%lld\n",query(1,1,n,x,y));
	}
	return 0;
}
