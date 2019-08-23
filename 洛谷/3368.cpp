#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 500000;
#define LL long long
int n, m, last;
LL bit[MAXN+10];
void add(int i,int x) {
    while(i<=n) {
        bit[i] += x;
        i += i&-i;
    }
}
LL sum(int i) {
    LL ret = 0;
    while(i) {
        ret += bit[i];
        i -= i&-i;
    }
    return ret;
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        int t;
        scanf("%d", &t);
        add(i, t-last);
        last = t;
    }
    while(m--) {
        int t, x, y, k;
        scanf("%d", &t);
        if(t==1) {
            scanf("%d %d %d", &x, &y, &k);
            add(x, k);
            add(y+1, -k);
        } else {
            scanf("%d", &x);
            printf("%lld\n", sum(x));
        }
    }
    return 0;
} 
