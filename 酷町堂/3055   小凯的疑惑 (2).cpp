/**题意：给定a,b且(a,b)=1,找到一个最小的正整数k,使得方程ax+by=k无非负整数解
根据题意，可以转化为找到一个正整数k,k可以用ax+by，表示而k-1 不可以
则一定存在非负整数x,y满足ax+by=k(x>=0,y>=0)
先考虑这个方程ax+by=gcd(a,b)=1
令x1,y1为此方程x为非负整数且最小的一组解，则ax1+by1=1
令x2,y2为此方程y为非负整数且最小的一组解，则ax2+by2=1
那么将ax+by=k减去这两个式子，得到
a(x-x1)+b(y-y1)=k-1         (1)式
a(x-x2)+b(y-y2)=k-1         (2)式
这时候，如果(1)是x-x1<0或y-y1<0,(2)式x-x2<0或y-y2<0，这样k-1就没有
办法被表示出来了
考虑x1>0,x2<0,y1<0,y2>0,且x>=0,y>=0,那么x-x1,y-y2恰取-1是最优的
移项得：x=x1-1,y-y2-1
将x,y代入,a(x1-1)+b(y2-1)=k
所以题目要求的k-1就是
a(x1-1)+b(y2-1)-1**/
#include<iostream>
using namespace std;
int exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long r=exgcd(b,a%b,x,y);
    long long t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main()
{
    long long a,b,x,y,x1,y1;
    cin>>a>>b;
    exgcd(a,b,x,y);
    x=(x%b+b)%b;
    y=(y%a+a)%a;
    long long ans=a*(x-1)+b*(y-1);
    cout<<ans-1;
    return 0;
}
