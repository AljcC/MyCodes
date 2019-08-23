/*
d[i][s] 表示当前在第i个城市，且走过的城市的状态为s的最小路程和(编号从0~n-1)
d[i][s] = min(d[j][s^(1<<i)]+G[i][j])
边界：d[i][1<<i]=G[0][i] ( i!=0 )
解：d[0][(1<<n)-1]
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 16;
const int INF = 100000000;
int n, G[MAXN][MAXN],d[MAXN][1<<MAXN];

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> G[i][j];
		}
	}
	for(int i=0; i<n; i++) {
		for(int s=0; s<1<<n; s++){
			d[i][s] = INF;
		}
	}
	for(int i=1; i<n; i++) {
		d[i][1<<i] = G[0][i];
	}
	for(int s=0; s<1<<n; s++) {
		for(int i=0; i<n; i++) {
			if(s&(1<<i)) {
				for(int j=0; j<n; j++) {
					if(s&(1<<j) && i!=j) {
						d[i][s] = min(d[i][s], d[j][s^(1<<i)]+G[i][j]);
					}
				}
			}
		}
	}
	cout << d[0][(1<<n)-1];
	return 0;
}