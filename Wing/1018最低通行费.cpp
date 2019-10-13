#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 110;
int n, a[N][N];
int f[N][N];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0; i<=n; i++) {
		f[i][0] = INF;
	}
	for(int j=0; j<=n; j++) {
		f[0][j] = INF;
	}
	f[1][1] = a[1][1];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1 && j==1) continue;
			f[i][j] = min(f[i-1][j], f[i][j-1])+a[i][j];
		}
	}
	printf("%d", f[n][n]);
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;
int n, a[N][N];
int f[N][N];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1&&j==1) {
				f[i][j] = a[i][j];
			} else {
				f[i][j] = 1e9;
				if(i > 1)
					f[i][j] = min(f[i][j], f[i-1][j]+a[i][j]);
				if(j > 1)
					f[i][j] = min(f[i][j], f[i][j-1]+a[i][j]);
			}
		}
	}
	printf("%d", f[n][n]);
	return 0;
}
*/