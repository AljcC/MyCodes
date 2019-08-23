#include<iostream>
using namespace std;
int n;
int work(int n)
{
    int t=n;
    for(int i=2;(long long)i*i<=n;i++)
        if(n%i==0)
        {
            t=t/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    if(n!=1)
        t=t/n*(n-1);
    return t;
}
int main()
{
    cin>>n;
    cout<<work(n);
    return 0;
}
