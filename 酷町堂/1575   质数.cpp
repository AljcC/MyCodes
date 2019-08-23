#include<iostream>
using namespace std;
int l,r,f[5000010],p[5000010],cnt,t=-1;
int main()
{
    cin>>l>>r;
    f[1]=1;
    for(int i=2;i<=r;i++)
    {
        if(f[i]==0)
            p[++cnt]=i;
        if(i>=l&&t==-1&&f[i]==0)
            t=i;
        for(int j=1;j<=cnt&&(long long)i*p[j]<=r;j++)
        {
            f[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
    cout<<t<<' '<<p[cnt];
    return 0;
}
