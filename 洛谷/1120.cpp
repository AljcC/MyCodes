#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool vis[101];
int n,a[101],tot,all,len;
int cmp(int x,int y)
{
    return x>y;
}
bool dfs(int now,int pos,int d)
{
    if(d==tot)
        return 1;
    if(now==0) 
        if(dfs(len,1,d+1)==1) 
            return 1;
    for(int i=pos;i<=n;++i)
        if(vis[i]==0&&a[i]<=now)
        {
            vis[i]=1;
            if(dfs(now-a[i],i+1,d)) 
                return 1;
            vis[i]=0;
            if(now==a[i]||now==len) 
                break;   
            while(a[i+1]==a[i]) 
                i++;        
    }
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]>50)
        {
            i--;n--;
        }
        else all+=a[i];
    }
    sort(a+1,a+1+n,cmp);        
    for(int i=a[1];i<=all;++i)  
    {
        if(all%i==0) 
        {   len=i;
            tot=all/i;
            if(dfs(len,1,0)==1)
            {
                cout<<len;
                return 0;
            }
        }
    }
}