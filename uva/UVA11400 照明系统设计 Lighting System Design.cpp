/*
d[i]表示前i种灯泡（电压从小到大排序后）购买的最优解
s[i]表示1~i的灯泡的需求量之和（前缀和）
d[i] = min(d[j]+(s[i]-s[j])*l*c[i]+k[i],d[i]);
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
struct pt {
    int v, k, c, l;
} a[MAXN];
int n, s[MAXN], d[MAXN];
bool cmp(pt a,pt b) {
    return a.v < b.v;
}
int main() {
    while(cin >> n && n) {
        for(int i=1; i<=n; i++) cin>>a[i].v>>a[i].k>>a[i].c>>a[i].l;
        sort(a+1, a+n+1, cmp);
        for(int i=1; i<=n; i++) s[i] = s[i-1] + a[i].l;
        memset(d, 127, sizeof(d));
        d[0] = 0;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                d[i] = min(d[i], d[j]+(s[i]-s[j])*a[i].c+a[i].k);
            }
        }
        cout << d[n] << "\n";
    }
    return 0;
}