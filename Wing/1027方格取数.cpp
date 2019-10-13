#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10;
const int INF = 0x3f3f3f3f;
int n, a[N][N];
int f[2*N][N][N];

int main() {
	scanf("%d", &n);
	int u, v, w;
	while(cin >> u >> v >> w , u || v || w) {
		a[u][v] = w;
	}
	for(int k=2; k<=2*n; k++) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=1; i2<=n; i2++) {
				int j1 = k-i1, j2 = k-i2;
				if(j1>=1 && j2>=1 && j1<=n && j2<=n) {
					int t = a[i1][j1];
					if(i1 != i2) t += a[i2][j2];
					int &x = f[k][i1][i2];
					x = max(x, f[k-1][i1-1][i2-1]+t);
					x = max(x, f[k-1][i1][i2-1]+t);
					x = max(x, f[k-1][i1-1][i2]+t);
					x = max(x, f[k-1][i1][i2]+t);
				}
			}
		}
	}
	printf("%d", f[2*n][n][n]);
	return 0;
}