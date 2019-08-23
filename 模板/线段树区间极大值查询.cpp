#include<iostream>
using namespace std;
#define maxn 10000
struct tree
{
	int maxx;
	int minn;
}tree[maxn*4+5]; 
int ans[maxn];
void build(int node,int Left,int Right)
{
	if(Left==Right)
	{
		tree[node].maxx=tree[node].minn=ans[Left];
	}
	else
	{
		build(2*node,Left,(Left+Right)/2);
		build(2*node+1,(Left+Right)/2+1,Right);
		tree[node].maxx=max(tree[2*node].maxx,tree[2*node+1].maxx);
		tree[node].minn=min(tree[2*node].minn,tree[2*node+1].minn);
	}
}
int query(int node,int begin,int end,int Left,int Right)
{
	if(end<Left || begin>Right)
	{
	    return -1; 	
	} 
    if(Left<=begin && end<=Right)
	{
	     return tree[node].maxx;	
	}
	int mid=(begin+end)/2;
	int max1=query(2*node,begin,mid,Left,Right);
	int max2=query(2*node+1,mid+1,end,Left,Right);
	if(max1==-1)return max2;
	if(max2==-1)return max1;
	return max(max1,max2);	
} 
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>ans[i]; 
	}
	build(1,1,n);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
    	int l,r;
    	cin>>l>>r;
    	cout<<query(1,1,n,l,r)<<endl;;
	}
	return 0;
}
