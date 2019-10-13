/*
web:  https://www.acwing.com/problem/content/851/
Date: 2019年9月27日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 510;
int n, m, G[N][N];
int f[N];
bool st[N];

int Dijkstra() {
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int i=1; i<=n; i++) {
		int t = -1;
		for(int j=1; j<=n; j++) {
			if(!st[j] && (t==-1 || f[j]<f[t])) 
				t = j;
		}
		st[i] = 1;
		for(int j=1; j<=n; j++) {
			f[j] = min(f[j], f[t]+G[t][j]);
		}
	}
	if(f[n] == 0x3f3f3f3f) return -1;
	return f[n];
}

int main() {
	scanf("%d %d", &n, &m);
	memset(G, 0x3f, sizeof(G));
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u][v] = w;
	}
	int ans = Dijkstra();
	printf("%d\n", ans);
	return 0;
}