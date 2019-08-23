#include<iostream>
#include<cmath>
using namespace std;
int p[100007815],cnt,n,f[100007815];
int main()
{
    cin>>n;
    cout<<n<<'=';
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(f[i]==0)
                p[++cnt]=i,f[i]=i;
        for(int j=1;j<=cnt&&(long long)i*p[j]<=n;j++)
        {
            f[i*p[j]]=p[j];
            if(i%p[j]==0)
                break;
        }
    }
    while(n>1)
    {
        if(n/f[n]>1)
            cout<<f[n]<<'*';
        else cout<<f[n];
        n/=f[n];
    }
    return 0;
}
