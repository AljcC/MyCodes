/*
web:www.acwing.com/problem/content/1074/
Date:2019年10月6日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct P {
	int to;
	int cost;
};
const int N = 10010;
int n, ans;
int f[N][N];
vector<P> G[N];

int dfs(int u,int fa) {
	int dist = 0;//表示当前往下的最大长度
	int d1=0, d2=0;
	for(int i=0; i<G[u].size(); i++) {
		int e = G[u][i].to;
		if(e == fa) continue;
		int d = dfs(e, u) + G[u][i].cost;
		dist = max(dist, d);
		if(d>=d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
	}
	ans = max(ans, d1 + d2);
    return dist;
}

void add(int u, int v, int w) {
	G[u].push_back(P{v, w});
}

int main() {
	cin >> n;
	for(int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, -1);
	cout << ans;
	return 0;
}