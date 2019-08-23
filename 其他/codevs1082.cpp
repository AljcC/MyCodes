#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN=200000;
#define LL long long
LL bit0[MAXN+10], bit1[MAXN+10];
int n, q;
void add(LL bit[], int i, int x) {
	while(i<=n) {
		bit[i] += x;
		i += i&-i;
	}
} 
LL sum(LL bit[], int i) {
	LL ret = 0;
	while(i) {
		ret += bit[i];
		i -= i&-i;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		add(bit0, i, t);
	}
	scanf("%d", &q);
	for(int i=1; i<=q; i++) {
		int t, a, b, x;
		scanf("%d %d %d", &t, &a, &b);
		if(t==1) {
			scanf("%d", &x);
			add(bit0, a, -x*(a-1));
			add(bit1, a, x);
			add(bit0, b+1,x*b);
			add(bit1, b+1, -x);
		} else {
			LL res=0;
			res = sum(bit1, b)*b + sum(bit0, b) ;
			res -= sum(bit0, a - 1) + sum(bit1, a - 1) *(a - 1);
			printf("%lld\n", res);
		}
	}
	return 0;
} 
