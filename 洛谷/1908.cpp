#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;
const int mod = 99999997;

int a[maxn],b[maxn],c[maxn],d[maxn];
int n,q[maxn],bit[maxn];

int lowbit(int x){
    return x & -x;
}

void add(int x,int y){
    for(;x <= n;x += lowbit(x)) bit[x] += y;
}

int sum(int x){
    int res = 0;
    for(;x >= 1;x -= lowbit(x)) res += bit[x];
    return res;
}

int cmp1(int x,int y){
    return a[x] < a[y];
}

int cmp2(int x,int y){
    return b[x] < b[y];
}

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        c[i] = i;
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&b[i]);
        d[i] = i;
    }
    sort(c+1,c+n+1,cmp1);
    sort(d+1,d+n+1,cmp2);
    for(int i = 1;i <= n;i++){
        q[c[i]] = d[i];
    }
    int ans = 0;
    for(int i = n;i;i--){
        ans += sum(q[i]-1);
        if(ans > mod) ans -=mod;
        add(q[i],1);
    }
    printf("%d\n",ans);
    return 0;
}