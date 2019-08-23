/*
f[u][0] 表示 当前节点u选的最优解
f[u][1] 表示 当前节点u不选，但其父亲选的最优解
f[u][2] 表示 当前节点u不选，其父亲也不选的最优解
【动态转移方程】
f[u][0] = sum(min(f[v][0], f[v][1]));
f[u][1] = sum(f[v][2]);
f[u][2] = f[u][1]+f[v'][0]-f[v'][2];
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 10010;
const int INF = 10000000;
vector<int> G[MAXN];
int n, f[MAXN][3];
bool vis[MAXN];

void dfs(int u) {
	vis[u] = 1;
	f[u][0] = 1;
	f[u][1] = 0;
	f[u][2] = INF;
	vector<int> cur;
	for(int i=0; i<G[u].size(); i++) {
		int v = G[u][i];
		if(vis[v]==true) continue;
		dfs(v);
		cur.push_back(v);
		f[u][0] += min(f[v][0], f[v][1]);
		f[u][1] += f[v][2];
	}
	for(int i=0; i<cur.size(); i++) {
		int v = cur[i];
		f[u][2] = min(f[u][2], f[u][1]-f[v][2]+f[v][0]);
	}
}

int main() {
	while(1) {
		cin >> n;
		for(int i=0; i<MAXN; i++) G[i].clear();
		for(int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1; i<=n; i++) {
			vis[i] = false;
		}
		dfs(1);
		if(f[1][0] > f[1][2]) cout << f[1][2] << '\n';
		else cout << f[1][0] << '\n';
		int e;
		cin >> e;
		if(-1 == e) break;
	}
	return 0;
}