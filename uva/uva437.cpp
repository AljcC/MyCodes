#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 50;
int n, k, ans, dp[MAXN][3];
struct block {
	int no[3];
} blk[MAXN];
int dfs(int t, int h) {
	if(dp[t][h] > 0) return dp[t][h];
	dp[t][h] = blk[t].no[h];
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=2; j++) {
			int a = (h+1)%3;
			int b = (h+2)%3;
			int x = (j+1)%3;
			int y = (j+2)%3;
			if(blk[i].no[x]<blk[t].no[a] && blk[i].no[y]<blk[t].no[b] || blk[i].no[y]<blk[t].no[a] && blk[i].no[x]<blk[t].no[b]) {
				dp[t][h] = max(dp[t][h], blk[t].no[h]+dfs(i, j));
			}
		}
	}
	return dp[t][h];
}
int main() {
	while(cin >> n && n) {
		memset(dp, 0, sizeof(dp));
		ans = -1;
		for(int i=1; i<=n; i++)
			cin >> blk[i].no[0] >> blk[i].no[1] >> blk[i].no[2];
		for(int i=1; i<=n; i++)
			for(int j=0; j<=2; j++)
				ans = max(ans, dfs(i, j));
		printf("Case %d: maximum height = %d\n", ++k, ans);
	}
	return 0;
}