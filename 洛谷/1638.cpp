#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000010; 
int n, m, a[MAXN], ans = 1e9, cnt, c[2001], id1, id2;

void insert(int x) {
	if(c[x] == 0) {
		cnt++;
	}
	++c[x];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for(int r=1; r<=n; r++) {
		cnt=0;
		memset(c, 0, sizeof(c));
		for(int l=r; l>=1; l--) {
			if(r-l+1 >= ans) break;
			insert(a[l]);
			if(cnt == m) {
				if(r-l+1 < ans) {
					ans = r-l+1;
					id1 = l, id2 = r;
				}
				break;
			}
		}
	}
	printf("%d %d", id1, id2);
	return 0;
}