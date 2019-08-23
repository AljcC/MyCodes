#include<iostream>
#include<cmath>
using namespace std;
int p[1000010],cnt,n,f[1000010];
void make()
{
    f[1]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(f[i]==0)
            p[++cnt]=i;
        for(int j=1;j<=cnt&&(long long)i*p[j]<=n;j++)
        {
            f[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
}
int main()
{
    cin>>n;
    cout<<n<<'=';
    make();
    for(int i=1;p[i]<=sqrt(n);i++)
        if(n%p[i]==0)
        {
            cout<<p[i]<<'*';
            n/=p[i];
        }
    if(n!=1)
        cout<<n;
    return 0;
}
