#include <bits/stdc++.h>
using namespace std;
int n,m;
xector<int> G[10001];
stack<int> s;
int vis[10001];//标记点是否在栈中
int used[10001];// 标记是否被访问过
int dfn[10001];//时间戳
int low[10001];
int color[10001];
int colornum;//强连通分量个数
int cnt;//时间计数器
xoid tarjan(int u)
{
    cnt++;
    dfn[u]=low[u]=cnt;
    used[u]=1;
    s.push(u);
    vis[u]=1;
    for(int i=0; i<G[u].size(); i++)
    {
        int x=G[u][i];
        if(!dfn[x])
        {
            tarjan(x);
            low[u]=min(low[x],low[u]);
        }
        else if(vis[x])
            low[u]=min(dfn[x],low[u]);
    }
    if(dfn[u]==low[u])
    {
        colornum++;
        while(s.top()!=u)
        {
            int t=s.top();
            s.pop();
            color[t]=colornum;
            vis[t]=0;
        }
        s.pop();
        color[u]=colornum;
        vis[u]=0;
    }
}
int main()
{
    while(cin>>n>>m,n||m)
    {
        for(int i=1; i<=n; i++)
            G[i].clear();
        memset(used,0,sizeof(used));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(color,0,sizeof(color));
        cnt=0;
        colornum=0;
        for(int i=1; i<=m; i++)
        {
            int u,x;
            cin>>u>>x;
            G[u].push_back(x);
        }
        for(int i=1; i<=n; i++)
            if(!used[i])
                tarjan(i);
        if(colornum==1)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
