#include<iostream>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
}
int main()
{
    int a,b,s,t;
    cin>>a>>b;
    exgcd(a,b,s,t);
    cout<<(s%b+b)%b
    return 0;
}
