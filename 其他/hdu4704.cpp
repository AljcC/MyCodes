#include<iostream>
using namespace std;
#define LL long long
const int MAX=100010;
const int mod=1e9+7;
string s;
LL work(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    while(cin>>s)
    {
        LL sum=0;
        for(int i=0;i<s.size();i++)
            sum=(sum*10+s[i]-'0')%(mod-1);
        LL n=(sum-1+(mod-1))%(mod-1);
        cout<<work(2,n)<<'\n';
    }
    return 0;
}
