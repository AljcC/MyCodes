#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
const int MAXN=500000; 
int n, m, a[MAXN+10];
LL bit[MAXN+10];
LL sum(int i) {
	LL ret=0;
	while(i>0) {
		ret += bit[i];
		i -= i&-i;
	}
	return ret;
}
void add(int i, int x) {
	while(i<=n) {
		bit[i] += x;
		i += i&-i;
	}
} 
int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	while(m--) {
		int t,x,y;
		scanf("%d %d %d", &t, &x, &y);
		if(t==1) {
			add(x, y);
		} 
		else {
			printf("%lld\n", sum(y)-sum(x-1));
		}
	}
	return 0;
}
