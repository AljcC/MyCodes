#include<iostream>
using namespace std;
struct tree
{
    int maxx;
    int minn;
}tree[40001]; 
int ans[10001];
void build(int node,int Left,int Right)
{
    if(Left==Right)
        tree[node].maxx=tree[node].minn=ans[Left];
    else
    {
        build(2*node,Left,(Left+Right)/2);
        build(2*node+1,(Left+Right)/2+1,Right);
        tree[node].maxx=max(tree[2*node].maxx,tree[2*node+1].maxx);
        tree[node].minn=min(tree[2*node].minn,tree[2*node+1].minn);
    }
}	
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ans[i]; 
    build(1,1,n);
    cout<<tree[1].maxx<<' '<<tree[1].minn<<endl;
} 
