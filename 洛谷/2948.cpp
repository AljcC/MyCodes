#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10010;
const int MAXS = 110;
int s, t, n;
int last[MAXN][MAXN], mi[MAXN], dp[MAXS][MAXN], f[MAXN];

int main() {
	cin >> t >> s >> n;
	for(int i=1; i<=s; i++) {
		int m, l, a;
		cin >> m >> l >> a;
		last[m-l+1][a] = max(last[m-l+1][a], m);
	}
	memset(mi, 63, sizeof(mi));
	for(int i=1; i<=n; i++) {
		int c, d;
		cin >> c >> d;
		mi[c] = min(mi[c], d);
	}
	for(int i=1; i<=100; i++) 
		mi[i] = min(mi[i], mi[i-1]);
	memset(dp, 128, sizeof(dp));
	dp[0][0] = dp[0][1] = 0;
	for(int i=1; i<=t; i++) {
		for(int j=1; j<=100; j++) {
			dp[i][j] = dp[i-1][j];
			if(i-mi[j]>=0) dp[i][j] = max(dp[i][j], dp[i-mi[j]][j]+1);
			if(last[i-1][j]) dp[i][j] = max(dp[i][j], f[last[i-1][j]]);
			f[i] = max(f[i], dp[i][j]);
		}
	}
	cout << f[t];
	return 0;
}