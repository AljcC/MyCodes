/**���⣺����a,b��(a,b)=1,�ҵ�һ����С��������k,ʹ�÷���ax+by=k�޷Ǹ�������
�������⣬����ת��Ϊ�ҵ�һ��������k,k������ax+by����ʾ��k-1 ������
��һ�����ڷǸ�����x,y����ax+by=k(x>=0,y>=0)
�ȿ����������ax+by=gcd(a,b)=1
��x1,y1Ϊ�˷���xΪ�Ǹ���������С��һ��⣬��ax1+by1=1
��x2,y2Ϊ�˷���yΪ�Ǹ���������С��һ��⣬��ax2+by2=1
��ô��ax+by=k��ȥ������ʽ�ӣ��õ�
a(x-x1)+b(y-y1)=k-1         (1)ʽ
a(x-x2)+b(y-y2)=k-1         (2)ʽ
��ʱ�����(1)��x-x1<0��y-y1<0,(2)ʽx-x2<0��y-y2<0������k-1��û��
�취����ʾ������
����x1>0,x2<0,y1<0,y2>0,��x>=0,y>=0,��ôx-x1,y-y2ǡȡ-1�����ŵ�
����ã�x=x1-1,y-y2-1
��x,y����,a(x1-1)+b(y2-1)=k
������ĿҪ���k-1����
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
