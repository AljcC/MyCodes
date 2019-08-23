#include<iostream>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long r=exgcd(b,a%b,x,y);
    long long t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main()
{
    long long n;
    cin>>n;
    while(n--){
        long long a,b,c,p,q,r,s,x,y;
        cin>>a>>b>>c>>p>>q>>r>>s;
        if(a==0&&b==0&&c!=0)
        {
            cout<<0<<'\n';
            continue;
        }
        if(q<p||s<r)
        {
            cout<<0<<'\n';
            continue;
        }
        if(a==0&&b==0&&c==0)
        {
            cout<<(q-p+1)*(s-r+1);
            continue;
        }
        long long d=exgcd(a,b,x,y);
        if(-c%d!=0)
        {
            cout<<0<<'\n';
            continue;
        }
        x*=-c/d;
        y*=-c/d;
        long long start,end;
        if(b==0)
        {
            if(x>=p&&x<=q)
                cout<<1<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        else if((float)d/b>0)
        {
            start=(p-x)*d/b;
            end=(q-x)*d/b;
        }
        else
        {
            start=(q-x)*d/b;
            end=(p-x)*d/b;
        }
        int ans=0;
        for(long long k=start;k<=end;k++)
                if(y-k*a/d>=r&&y-k*a/d<=s)
                    ans++;
        cout<<ans;
    }
    return 0;
}
