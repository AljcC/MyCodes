/*
web:https://www.acwing.com/problem/content/1070/
Date:2019年10月5日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 210;
const int INF= 0x3f3f3f3f;
int n, a[2*N];
int s[N];
int f[N][N], g[N][N];

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int i=1; i<=2*n; i++) {
		s[i] = s[i-1]+a[i];
	}
	memset(f, -INF, sizeof(f));
	memset(g, INF, sizeof(g));
	f[1][1] = 0;
	g[1][1] = 0;
	for(int len=1; len<=n; len++) {
		for(int l=1; l+len-1<=2*n; l++) {
			int r = l+len-1;
			if(len == 1) f[l][r] = g[l][r] = 0;
			else
			for(int k=l; k<r; k++) {
				f[l][r] = max(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
				g[l][r] = min(g[l][r], g[l][k]+g[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	int res1 = 0, res2 = INF;
	for(int i=1; i<=2*n; i++) {
		res1 = max(res1, f[i][i+n-1]);
		res2 = min(res2, g[i][i+n-1]);
	}
	cout << res2 << '\n' << res1;
	return 0;
}
/*
4 5 9 4 4 5 9 4
8 9 13 8 8 9 13 13
*/	