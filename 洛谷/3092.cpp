#include<bits/stdc++.h>
using namespace std;
#define man 100010

int k,n,a[man],f[1<<16];
int sum[man],maxn=0,ans=-1;

inline int find_max(int l,int r,int x)
{    int ans=l,mid,pre=l;
    while(l<=r)
    {    mid=(l+r)>>1;
        if(sum[mid]-sum[pre]<=a[x]) ans=mid,l=mid+1;
        else r=mid-1;
        }
    return ans;
    }

inline int calc_surplus(int sta)
{    int ans=0;
    for(int i=1;i<=k;i++)
    {    if((sta&(1<<(i-1)))==0) ans+=a[i];
        }
    return ans;
    }
    
int main()
{    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=1,x;i<=n;i++)
    {    scanf("%d",&x);
        sum[i]=sum[i-1]+x;
        }
    f[0]=0;
    for(int sta=1;sta<(1<<k);sta++)
    {    maxn=0;
        for(int i=1;i<=k;i++)
        {    if(sta&(1<<(i-1)))
            {    int tmp=f[sta-(1<<(i-1))];
                maxn=max(maxn,find_max(tmp,n,i));
                }
            }
        f[sta]=maxn;
        if(maxn==n) ans=max(ans,calc_surplus(sta));
        }
    printf("%d\n",ans);
    return 0;
    }