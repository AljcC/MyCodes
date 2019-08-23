/*
d[i][r0][r1]表示前i行，当前行（第i行）炮台摆放状态的集合是r0，上一行（第i-1行）炮台摆放状态的集合是r1的最优解
d[i][r0][r1] = max(d[i-1][r1][r2]+sum(r0)) 其中r2表示上上行（第i-2行）炮台摆放状态的集合，sum(r0)表示r0表示的状态中炮台摆放的个数(即r0代表的二进制数中有多少个1）
解：max(d[n][r0][r1])
边界：d[0][i][j]=0
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 110;
const int MAXM = 11;
int m, n, ans,d[2][1<<MAXM][1<<MAXM], field[MAXN];
bool valid[1<<MAXM];

bool isValid(int x) {
	while(x>0) {
		if((x&1)>0) {
			if((x&2)>0 || (x&4)>0) return false;
		}
		x>>=1;
	}
	return true;
}

int js(int x) {
	int ret=0;
	while(x>0) {
		if((x&1)==1) ret++;
		x>>=1;
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		string s;
		cin >> s;
		int tmp = 0;
		for(int j=0; j<m; j++) {
			if(s[j] == 'P') {
				tmp += (1<<j);
			}
		}
		field[i] = tmp;
	}
	for(int i=0; i<1<<m; i++) {
		valid[i] = isValid(i);
	}
	for(int i=1; i<=n; i++) {
		for(int r0=0; r0<1<<m; r0++) {
			int sum = js(r0);
			if(valid[r0] && (~field[i]&r0)==0) {
				for(int r1=0; r1<1<<m; r1++) {
					if(valid[r1] && (r0&r1)==0) {
							for(int r2=0; r2<1<<m; r2++) {
								if(valid[r2] && (r0&r2)==0) {
									d[i%2][r0][r1] = max(d[i%2][r0][r1], d[(i-1)%2][r1][r2]+sum);
								}
							}
							ans = max(ans, d[i%2][r0][r1]);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}