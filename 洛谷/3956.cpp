#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, ans=1e9;
int map[110][110], f[110][110], vis[110][110];
int nxt[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

bool judge(int x, int y) {
	if(x>=1 && y>=1 && x<=m && y<=m) {
		return 1;
	} return 0;
}

void dfs(int x, int y, int cst, int mo) {
	if(x<1||y<1||x>m||y>m)
		return; 
	if(cst >= f[x][y] ) return ;
	f[x][y] = cst;

	vis[x][y] = 1;

	if(x==m && y==m) {
        if(cst<ans)
			ans=cst;
        return;
    }
	for(int i=0; i<4; i++) {
		int nx=x+nxt[i][0], ny=y+nxt[i][1];
			if(map[nx][ny]) {
				if(map[nx][ny] == map[x][y])
					dfs(nx, ny, cst, 0);
				else dfs(nx, ny, cst+1, 0);
			} else if(map[nx][ny]==0){
				if(mo==0) {
					map[nx][ny] = map[x][y];
					dfs(nx, ny, cst+2, 1);
					map[nx][ny] = 0;
				}
			}
	}
}

int main() {
	memset(f, 0x7f, sizeof(f));
	cin >> m >> n;
	for(int i=1; i<=n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		map[x][y] = c+1;
	}
	dfs(1, 1, 0, 0);
	if(ans != 1e9) cout << ans;
	else cout << -1;
	return 0;
} 	