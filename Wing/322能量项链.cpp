/*
web:https://www.acwing.com/problem/content/322/
Date:2019年10月5日
Code by LJC
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2010;
int n, a[N];
int f[N][N];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		a[n+i] = a[i];
	}
	for(int len=3; len<=n+1; len++) {
		for(int l=1; l+len-1<=2*n; l++) {
			int r = l+len-1;
			for(int k=l+1; k<r; k++)
				f[l][r] = max(f[l][r], f[l][k]+f[k][r]+a[l]*a[k]*a[r]);
		}
	}
	int res = 0;
	for(int i=1; i<=n; i++) {
		res = max(res, f[i][i+n]);
	}
	cout << res;
	return 0;
}