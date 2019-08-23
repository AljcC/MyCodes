#include<iostream>
using namespace std;
#define LL long long
LL mul(LL a,LL b,LL mod)
{
    LL ans=0;
    while(b)
    {
        if(b&1)
            ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL r=exgcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
LL k,M,ans,a[10],b[10];
LL CRT(LL a[],LL b[],LL n)
{
    LL M=1;
    for(LL i=1;i<=n;i++)
        M*=b[i];
    for(LL i=1;i<=n;i++)
    {
        LL x,y;
        LL Mi=M/b[i];
        exgcd(Mi,b[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+mul(mul(a[i],x,M),Mi,M))%M;
    }
    return (ans%M+M)%M;
}
int main()
{
    cin>>k;
    for(LL i=1;i<=k;i++)
        cin>>a[i];
    for(LL i=1;i<=k;i++)
        cin>>b[i];
    for(int i=1;i<=k;i++)
        a[i]=(a[i]%b[i]+b[i])%b[i];
    cout<<CRT(a,b,k);
    return 0;
}
