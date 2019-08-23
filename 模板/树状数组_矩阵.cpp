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