/*
错误代码！！


web:luogu.org/problem/P1043
Date:2019年10月6日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 60;
int n, m;
int a[2*N];
int f[N][N];
int g[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[n+i] = a[i];
	}
	memset(g, 0x3f, sizeof(g));
	for(int len=1; len<=n; len++) {
		for(int l=1; l+len-1<=n; l++) {
			int r = l+len-1;
			for(int k=l; k<=r; k++) {
				int x=0, y=0;
				for(int i=l; i<=k; i++) x=(x+a[i])%10;
				for(int i=k+1; i<=r; i++) y=(y+a[i])%10;
				f[l][r] = max(f[l][r], f[l][k]+f[k+1][r]+x*y);
				g[l][r] = min(g[l][r], g[l][k]+g[k+1][r]+x*y);
			}
		}
	}
	cout << f[1][n] <<' ' <<g[1][n];
	return 0;
}