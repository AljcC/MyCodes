#include <cstdio>
using namespace std;
#define N 100010
#define LL long long
LL mul[N << 2], add[N << 2], sp[N << 2];
int n, m;
LL p;
inline void up(int id) {
    sp[id] = (sp[id << 1] + sp[id << 1 | 1]) % p;
}
void build(int id, int l, int r) {
    mul[id] = 1;
    if(l == r) {
        scanf("%lld", &sp[id]);
        sp[id] %= p;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void down(int id, int l, int r) {
    if(mul[id] != 1 || add[id]) {
        mul[id << 1] = mul[id << 1] * mul[id] % p;
        mul[id << 1 | 1] = mul[id << 1 | 1] * mul[id] % p;
        add[id << 1] = add[id << 1] * mul[id] % p;
        add[id << 1 | 1] = add[id << 1 | 1] * mul[id] % p;
        sp[id << 1] = sp[id << 1] * mul[id] % p;
        sp[id << 1 | 1] = sp[id << 1 | 1] * mul[id] % p;
        mul[id] = 1;
        add[id << 1] = (add[id << 1] + add[id]) % p;
        add[id << 1 | 1] = (add[id << 1 | 1] + add[id]) % p;
        int mid = (l + r) >> 1;
        sp[id << 1] = (sp[id << 1] + (mid - l + 1) * add[id]) % p;
        sp[id << 1 | 1] = (sp[id << 1 | 1] + (r - mid) * add[id]) % p;
        add[id] = 0;
    }
}
void update(int id, int l, int r, int x, int y, int v, int opt) {
    if(x <= l && r <= y) {
        if(opt == 1) {
            sp[id] = sp[id] * v % p;
            add[id] = add[id] * v % p;
            mul[id] = mul[id] * v % p;
        }
        else {
            add[id] = (add[id] + v) % p;
            sp[id] = (sp[id] + (r - l + 1) * v) % p;
        }
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) update(id << 1, l, mid, x, y, v, opt);
    if(y > mid) update(id << 1 | 1, mid + 1, r, x, y, v, opt);
    up(id);
}
LL query(int id, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return sp[id];
    down(id, l, r);
    int mid = (l + r) >> 1;
    LL ret = 0;
    if(ql <= mid) ret = (ret + query(id << 1, l, mid, ql, qr)) % p;
    if(qr > mid) ret = (ret + query(id << 1 | 1, mid + 1, r, ql, qr)) % p;
    return ret;
}
int main() {
    scanf("%d %d %lld", &n, &m, &p);
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int opt, x, y, k;
        scanf("%d", &opt);
        if(opt == 1) {
            scanf("%d %d %d", &x, &y, &k);
            update(1, 1, n, x, y, k, 1);
        }
        else if(opt == 2) {
            scanf("%d %d %d", &x, &y, &k);
            update(1, 1, n, x, y, k, 2);
        }
        else {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
