#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
    int l,w;
}a[5003];
int b[5003],n;
bool cmp(const data &x,const data &y)
{
    if(x.l!=y.l) return x.l>y.l;
    return x.w>y.w;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].w);
    }
    sort(a+1,a+n+1,cmp);
    for(i=n;i>=1;i--)
        for(j=i+1;j<=n;j++)
        {
            if(a[i].l<a[j].l&&b[i]<b[j]+1)
                b[i]=b[j]+1;
            else
            {
                if(a[i].w<a[j].w&&b[i]<b[j]+1)
                    b[i]=b[j]+1;
            }
        }
    int ans=0;
    for(i=1;i<=n;i++)
        ans=max(ans,b[i]);  
    printf("%d",ans+1);
    return 0;
}