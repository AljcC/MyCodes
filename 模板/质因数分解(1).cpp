#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<n<<"=";
    for(int i=2;i<=n;i++)
        while(n%i==0)
        {
            n/=i;
            if(n!=1)
                cout<<i<<'*';
            else cout<<i;
        }
    return 0;
}
