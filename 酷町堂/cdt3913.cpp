#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int MAXN = 200010;
int n, q;
LL bit[MAXN], a[MAXN];
int lowbit(int i) {
	return i&-i;
}
void init() {
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
		bit[i] = a[i];
		for(int j=1; j<lowbit(i); j<<=1)
			bit[i] = max(bit[i], bit[i-j]);
	}
}
void update(int i,int v) {
	a[i] = v;
	while(i<=n) {
		bit[i] = a[i];
		for(int j=1; j<lowbit(i); j<<=1)
			bit[i] = max(bit[i], bit[i-j]);
		i += lowbit(i);
	}
}
LL query(int l,int r) {
	LL ret = a[r];
	while(l<=r) {
		ret = max(ret, a[r]);
		for(--r; r-l>=lowbit(r); r-=lowbit(r))
			ret = max(ret, bit[r]);
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &q);
	init();
	while(q--) {
		int x, a, b;
		scanf("%d %d %d", &x, &a, &b);
		if(x == 1) {
			update(a, b);
		} else {
			printf("%lld\n", query(a, b));
		}
	}
	return 0;
}