#include <iostream>
#include <vector>
using namespace std;
int p[1000010],f[1000010],cnt;
vector<int> S;
int main()
{
    for(int i=5; i<=1000001; i+=4)
    {
        if(!f[i])
            S.push_back(i);
        for(int j=0;j<S.size()&&(long long)(i*S[j])<=1000001;j++)
        {
            if (f[i]==0)
                f[i*S[j]]=2;
            else f[i*S[j]]=1;
        }
    }
    for(int i=1;i<=1000001;i++)
        f[i]=f[i-1]+(f[i]==2?1:0);
    int x;
    while(cin>>x&&x)
        cout<<x<<' '<<f[x]<<'\n';
    return 0;
}
