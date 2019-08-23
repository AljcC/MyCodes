#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 110;
int n, x, y, z, m1, m2;
int a[MAXN], b[MAXN], f[MAXN][MAXN];

int main() {
	cin >> n >> x >> y >> z;
	for(int i=1; i<=n; i++) {
		int x1, y1;
		cin >> x1 >> y1;
		while(x1--) a[++m1] = i;
		while(y1--) b[++m2] = i;
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0]=0;
	for(int i=1; i<=m1; i++) f[i][0]=i*y;
	for(int i=1; i<=m2; i++) f[0][i]=i*x;	
	for(int i=1; i<=m1; i++) {
		for(int j=1; j<=m2; j++) {
			f[i][j] = min(min(f[i][j-1]+x, f[i-1][j]+y), f[i-1][j-1]+abs(a[i]-b[j])*z);
		}
	}
	cout << f[m1][m2];
	return 0;
}
/*
4 100 200 1 
1 4 
2 3 
3 2 
4 0 
*/