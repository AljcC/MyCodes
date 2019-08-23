/*
1、建图（此题用反向图） 
2、求强联通分量，得到每个点属于哪个强联通分量（着色） 
3、计算每个强联通分量的入度
4、如果入读为0的强联通分量>1个说明无解； 
如果如度为0的强联通分量为1个，则则输出强联通分量里的奶牛个数 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> G[10001];
stack<int> s;
int cnt,colornum,n,m;
int dfn[10001],low[10001],color[10001],vis[10001],ind[10001],outd[10001];
void dfs(int u)
{
    dfn[u]=low[u]=++cnt;
    s.push(u);
    vis[u]=true;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        colornum++;
        while(1)
        {
            int x=s.top();
            s.pop();
            color[x]=colornum;
            vis[x]=0;
            if(x==u)
                break;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            dfs(i);
    for(int u=1; u<=n; u++)
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(color[u]!=color[v])
            {
                ind[color[v]]++;
                outd[color[u]]++;
            }
        }	
    int sum=0,count=0;
    for(int i=1; i<=colornum; i++)
        if(outd[i]==0)
        {
            count++;
            for(int j=1; j<=n; j++)
                if(color[j]==i)
                    sum++;
        }
    if(count==1)
        cout<<sum;
    else cout<<0;
    return 0;
}
