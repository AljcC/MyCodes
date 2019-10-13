/*
web:https://www.acwing.com/problem/content/736/
Date:2019年9月27日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 110000;
int T, n, Case;
int f[N];
struct pt {
	int s, e, l;
} a[N];

bool cmp(pt a, pt b) {
	return a.s*b.l < b.s*a.l;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		int m = 0;
        memset(f, 0xcf, sizeof f);
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d", &a[i].s, &a[i].e, &a[i].l);
			m += a[i].s;
		}
		sort(a+1, a+n+1, cmp);
		f[0]=0;
		for(int i=1; i<=n; i++) {
			for(int j=m; j>=a[i].s; j--) {
				f[j] = max(f[j], f[j-a[i].s] + max(0, a[i].e - (j-a[i].s)*a[i].l));
			}
		}
		int res = 0;
		for(int i=0; i<=m; i++) {
			res = max(res, f[i]);
		}
		printf("Case #%d: %d\n", ++Case, res);
	}
	return 0;	
}