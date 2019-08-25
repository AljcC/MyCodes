#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define LL long long
struct pt {
	LL v, h;
}a[110], b[110];
int n, m, k, cnt1, cnt2;
LL f[1010], g[1010], x, y, ans;

bool cmp(pt c,pt d) {
	return (c.h==d.h?c.v<d.v:c.h<d.h);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
 	for (int i=1; i<=n; i++) {
      	scanf("%lld%lld",&x,&y);
      	if (y>=k) {
      		a[++cnt1].h=y;
      		a[cnt1].v=x;
      	} else {
      	   b[++cnt2].h=y;
      	   b[cnt2].v=x;
      	}
  	}
  	for (int i=0; i<=m; i++) 
  		f[i]=g[i]=-2100000000;
  	sort(a+1, a+1+cnt1, cmp);
  	sort(b+1, b+1+cnt2, cmp);
  	for (int i=1; i<=cnt1; i++) {
      	int temp=(a[i].h/5)*4;
      	g[a[i].h]=max(g[a[i].h],a[i].v);
      	for (int j=temp;j<=m;j++) 
      		g[j]=max(g[j-temp]+a[i].v,g[j]);
  	}
  	f[0]=0;
  	for (int i=1; i<=cnt2; i++) {
   		int temp=b[i].h/5*4;
   		for (int j=b[i].h; j<=m; j++)
   			f[j]=max(f[j],f[j-b[i].h]+b[i].v);
   		for (int j=temp; j<=m; j++)
   			g[j]=max(g[j-temp]+b[i].v,g[j]);
  	}
  	for (int i=0; i<=m; i++)
  		ans=max(max(ans,g[i]),f[i]);
  	printf("%lld\n",ans);
  	return 0;
}