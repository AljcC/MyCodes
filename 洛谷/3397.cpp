//www.luogu.org/problemnew/show/P3397
//code by LJC
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1010;
int n, t;
int bit[MAXN][MAXN];
void add(int x, int y, int v) {
	for(int i=x; i<=n; i+=i&-i)
		for(int j=y; j<=n; j+=j&-j)
			bit[i][j] += v;
}
int sum(int x, int y) {
    int ret = 0;
    for(int i=x; i>0; i-=i&-i)
        for(int j=y; j>0; j-=j&-j)
            ret += bit[i][j];
    return ret;
}
int main() {
	scanf("%d %d", &n, &t);
	while(t--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		add(x1, y1, 1);
		add(x2+1, y1, -1);
		add(x2+1, y2+1, 1);
		add(x1, y2+1, -1);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ", sum(i, j));
		}
		printf("\n");
	}
    return 0;
}