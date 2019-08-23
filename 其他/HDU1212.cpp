#include<iostream>
using namespace std;
string a;
int b,ans;
int main()
{
    while(cin>>a>>b)
    {
        ans=0;
        for(int i=0;i<a.size();i++)
            ans=(ans*10+a[i]-'0')%b;
        cout<<ans<<'\n';
    }
    return 0;
}
