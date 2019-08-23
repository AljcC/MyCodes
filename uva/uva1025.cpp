// UVA1025 城市里的间谍 A Spy in the Metro
//code by LJC
#include<iostream>
#include<cstring>
using namespace std;
int n,T,m,k,dp[2100][2100],t[2100],d[300][300][300];
int main()
{
    while(cin>>n&&n)
    {
        memset(dp,0,sizeof(dp));
        memset(t,0,sizeof(t));
        memset(d,0,sizeof(d));
        cin>>T;
        for(int i=1;i<n;i++)
            cin>>t[i];
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            d[x][1][0]=1;
            for(int j=1;j<n;j++)
                d[x+t[j]][j+1][0]=1,x+=t[j];
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            d[x][n][1]=1;
            for(int j=n-1;j>=1;j--)
                d[x+t[j]][j][1]=1,x+=t[j];
        }
        for(int i=1; )
        for(int i=1;i<n;i++)
            dp[T][i]=1e9;
        dp[T][n]=0;
        for(int i=T-1;i>=0;i--)
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&d[i][j][0]&&i+t[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
                if(j>1&&d[i][j][1]&&i+t[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        cout<<"Case Number "<<++k<<": ";
        if(dp[0][1]>=1e9)
            cout<<"impossible\n";
        else cout<<dp[0][1]<<'\n';
    }
    return 0;
}