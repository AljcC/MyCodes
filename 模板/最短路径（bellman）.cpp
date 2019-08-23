#include<iostream>
using namespace std;
int n,m,dis[10001],u[10001],v[10001],w[10001];
int main()
{
    int i,j,k,check;
    cin>>n>>m;
    for(i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(i=1;i<=n;i++)
        dis[i]=1e9;
    dis[1]=0;
    for(k=1;k<=n-1;k++)
    {
        check=0;
        for(int i=1;i<=m;i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
            {
                dis[v[i]]=dis[u[i]]+w[i];
                check=1;
            }
            if(dis[u[i]]>dis[v[i]]+w[i])
            {
                dis[u[i]]=dis[v[i]]+w[i];
                check=1;
            }
        }
        if(check==0)
			break;
    }
    cout<<dis[n];
    return 0; 
}
