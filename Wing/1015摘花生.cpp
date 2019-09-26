#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 110;
int T;
int n, m;
int a[MAXN][MAXN];
int f[MAXN][MAXN];

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(f, 0, sizeof(f));
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				f[i][j] = max(f[i][j-1]+a[i][j], f[i-1][j]+a[i][j]);
			}
		}
		printf("%d\n", f[n][m]);
	}
	return 0;
}