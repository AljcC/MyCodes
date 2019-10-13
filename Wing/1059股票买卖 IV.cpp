/*
web:https://www.acwing.com/problem/content/1059/
Date:2019年9月29日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10010;
const int K = 110;
int n, k;
int a[N];
int f[N][K][2];

int main() {
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	memset(f, 0xcf, sizeof(f));
	for(int i=0; i<=n; i++) {
		f[i][0][0] = 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]+a[i]);
			f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0]-a[i]);
		}
	}
	int res=0;
	for(int i=1; i<=k; i++) {
		res = max(f[n][i][0], res);
	}
	cout << res;
	return 0;
}