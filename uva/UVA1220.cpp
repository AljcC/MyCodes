//树的最大独立集
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 210;
int n, rootid, id1, id2, cnt;
int G[MAXN][MAXN], d[MAXN][2], f[MAXN][2];
map<string, int> mp;

int name(string s) {
	if(mp.count(s) == 0) {
		mp[s] = ++cnt;
	}
	return mp[s];
}

void dfs(int u) {
	d[u][0] = 0;
	d[u][1] = 1;
	f[u][0] = 1;
	f[u][1] = 1;
	for(int i=1; i<=n; i++) {
		if(G[u][i]) {
			dfs(i);
			d[u][1] += d[i][0];
			d[u][0] += max(d[i][0], d[i][1]);
			f[u][1] = f[u][1] & f[i][0];
			if(d[i][0] == d[i][1]) {
				f[u][0] = 0;
			} else if(d[i][0] > d[i][1]) {
				f[u][0] = f[u][0] & f[i][0];
			} else {
				f[u][0] = f[u][0] & f[i][1];
			}
		}
	}
}
int main() {
	while(cin >> n && n) {
		memset(G, 0, sizeof(G));
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		mp.clear();
		cnt = 0;
		for(int i=1; i<=n; i++) {
			string s1, s2;
			if(i == 1) {
				cin >> s1;
				rootid = name(s1);
			} else {
				cin >> s1 >> s2;
				id1 = name(s1);
				id2 = name(s2);
				G[id2][id1] = 1;
			}
		}
		dfs(rootid);
		if(d[rootid][0] == d[rootid][1]) {
			cout << d[rootid][0] <<" No\n";
		}
		else if(d[rootid][0] > d[rootid][1]) {
			cout << d[rootid][0] <<" " <<(f[rootid][0]?"Yes":"No") <<'\n';
		} else {
			cout << d[rootid][1] <<" " <<(f[rootid][1]?"Yes":"No") <<'\n';
		}
	}
	return 0;
} 