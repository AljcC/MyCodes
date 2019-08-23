/**

*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,T,k,w[51],v[51];
int f[5000001];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>t;
        memset(f,-1,sizeof(f));
        f[0]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>w[i];
            for(int j=t-1; j>=w[i]; j--)
                if(f[j-w[i]]!=-1)
                    f[j]=max(f[j],f[j-w[i]]+1);
        }
        int ans=t-1;
        for(int i=t-1;i>=0;i--)
            if(f[i]>f[ans])
                ans=i;
        cout<<"Case "<<++k<<": "<<f[ans]+1<<' '<<678+ans<<'\n';
    }
    return 0;
}
