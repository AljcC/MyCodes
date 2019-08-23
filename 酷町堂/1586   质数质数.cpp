#include<iostream>
#include<cmath>
using namespace std;
int p1[1000010],p2[1000010];
long long x,y;
long long ans;
int main()
{
    cin>>x>>y;
    p1[1]=p1[0]=1;
    for(long long i=2;i<=sqrt(y);i++)
    {
        if(p1[i]==0)
        {
            for(long long j=i*i;j<=sqrt(y);j+=i)
                p1[j]=1;
            for(long long j=max((long long)2,((x+i-1)/i)*i);j<=y;j+=i)
                p2[j-x]=1;
        }
    }
    for(int i=0;i<y-x;i++)
        if(!p2[i])
            ans++;
    cout<<ans;
    return 0;
}
