#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 500000;
#define LL long long
int n, q, last;
LL bit[MAXN+10];
void add(int i,int x) {
    while(i<=n) {
        bit[i] += x;
        i += i&-i;
    }
}
LL sum(int i) {
    LL ret = 0;
    while(i>0) {
        ret += bit[i];
        i -= i&-i;
    }
    return ret;
}
int main() {
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++) {
        int t;
        scanf("%d", &t);
        add(i, t-last);
        last = t;
    }
    while(q--) {
        int t, x, y;
        scanf("%d", &t);
        if(t==2) {
            scanf("%d %d", &x, &y);
            add(x, 1);
            add(y+1, 1);
        } else {
            scanf("%d", &x);
            LL ans = sum(x);
            printf("%lld\n", ans%2);
        }
    }
    return 0;
} 
