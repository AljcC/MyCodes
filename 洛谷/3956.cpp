#include <iostream>
#include <cstdio>
using namespace std;

int m, n;
int board[110][110], f[110][110];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int dir2[8][2] = {{2,0}, {-2,0}, {0,2}, {0,-2}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};

void dfs(int x, int t, int cst) {
	if(cst>=f[x][y]) return;
	f[x][y] = cst;
	if(x==m && y==m) return;
	for(int i=)
}

int main() {
	memset(f, 0x3f, sizeof(f));
	cin >> m >> n;
	for(int i=1; i<=n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		board[x][y] = c+1;
	}
	dfs(1, 1)
	return 0;
}