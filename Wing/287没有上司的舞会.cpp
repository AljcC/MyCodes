/*
web:https://www.acwing.com/problem/content/287/
Date:2019年10月2日
Code by LJC
*/
#include <iostream>
#include <cstdio> 
#include <vector>
using namespace std;

const int N = 6010;

int n, k, a[N];
vector<int> G[N];
bool f[N];
int dp[N][2];

void dfs(int u) {
	dp[u][1] = a[u];
	for(int i=0; i<G[u].size(); i++) {
		int e = G[u][i];
		dfs(e);
		dp[u][0] += max(dp[e][0], dp[e][1]);
		dp[u][1] += dp[e][0];
	}
}
int main() {
	cin >> n ;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		G[v].push_back(u);
		f[u] = 1;
	}
	int root = 1;
	while(f[root]) root++;
	dfs(root);
	cout << max(dp[root][0], dp[root][1]);
	return 0;
}