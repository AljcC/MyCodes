/*
web:https://www.acwing.com/problem/content/481/
Date:2019年10月6日
Code by LJC
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 110;
int n, a[N];
int f[N][N];
int g[N][N];

void dfs(int l, int r) {
	if(l > r) return;
	int root = g[l][r];
	cout << root << ' ';
	dfs(l, root-1);
	dfs(root+1, r);
}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for(int len=1; len<=n; len++) {
		for(int l=1; l+len-1<=n; l++) {
			int r = l+len-1;
			if(len == 1) f[l][r] = a[l], g[l][r] = l;
			else for(int k=l; k<r; k++) {
				int left = l==k?1:f[l][k-1];
				int right = r==k?1:f[k+1][r];
				int x = a[k]+left*right;
				if(f[l][r] < x)	{
					g[l][r] = k;
					f[l][r] = x;
				}
			}
		}
	}
	cout << f[1][n];
	cout << '\n';
	dfs(1, n);
	return 0;
}