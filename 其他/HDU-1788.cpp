#include<iostream>
using namespace std;
#define LL long long
LL k,a[100010],r[10010],ans;
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
LL CRT(LL m[],LL r[],LL n)
{
    LL a,b,c,r1,r2;
    a=m[1];
    r1=r[1];
    for(LL i=2;i<=n;i++)
    {
        LL k1,k2;
        b=m[i];
        r2=r[i];
        c=r2-r1;
        LL d=exgcd(a,b,k1,k2);
        if(c%d!=0)
            return -1;
        k1=(k1*(c/d)%(b/d)+b/d)%(b/d);
        r1=a*k1+r1;
        a=a*m[i]/d;
    }
    return (r1%a+a)%a==0?a:(r1%a+a)%a;
}
int main()
{
    LL t,c=0;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(LL i=1;i<=k;i++)
            cin>>a[i];
        for(LL i=1;i<=k;i++)
            cin>>r[i];
        cout<<"Case "<<++c<<": "<<CRT(a,r,k)<<'\n';
    }
    return 0;
}
