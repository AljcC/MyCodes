/*
d[s] 表示当前刺蛇状态是s时，传送门的最小损耗
d[s] = d[s-{j}]+cost[j]; | valid[j]=true;(其中j是s的子集)
边界 d[0] = 0
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 20;
int W, n, s[MAXN], w[MAXN], d[1<<MAXN], cost[1<<MAXN], valid[1<<MAXN];

int main() {
	cin >> W >> n;
	for(int i=1; i<=n; i++) {
		cin >> s[i] >> w[i];
	}
	memset(d, 127, sizeof(d));
	d[0] = 0;
	for(int i=1; i<1<<n; i++) {
		for(int j=1; j<=n; j++) {
			if(i&(1<<(j-1))) {
				cost[i] = max(s[j], cost[i]);
			}
		}
	}
	for(int i=1; i<1<<n; i++) {
		int cnt = 0;
		for(int j=1; j<=n; j++) {
			if(i&(1<<(j-1))) {
				cnt += w[j];
			}
		}
		if(cnt <= W) valid[i] = 1;
	}
	for(int i=1; i<1<<n; i++) {
		for(int j=i; j>0; j=(j-1)&i) {
			if(valid[j]==1) {
				d[i] = min(d[i], d[i^j]+cost[j]);
			}
		}
	}
	cout << d[(1<<n)-1] << ' ';
	return 0;
}