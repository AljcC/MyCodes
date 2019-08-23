#include<iostream>
#include<cmath>
using namespace std;
long long n,p[10000100],t;
int main()
{
    cin>>n;
    cout<<n<<"=";
    for(int i=2;i<=sqrt(n);i++)
        while(n%i==0)
        {
            n/=i;
            p[++t]=i;
        }
    p[++t]=n;
    for(int i=1;i<t;i++)
        cout<<p[i]<<'*';
    cout<<p[t];
    return 0;
}
