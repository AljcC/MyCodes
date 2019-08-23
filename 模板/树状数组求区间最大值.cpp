/*
  1.lowbit(i)表示：bit中第i个数的区间长度，即 i&-i
  2.bit[i]覆盖的区间为：bit[i-1],bit[i-2],bit[i-4],...,bit[i-j] | j<lowbit(i)
*/ 
void init() {
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		bit[i] = a[i];
		for(int j=1; j<lowbit(i); j<<=1)
			bit[i] = max(bit[i], b[i-j]);
	}
}
void update(int i, int x) {
	a[i] = x; 
	while(i<=n) {
		bit[i] = a[i];
		for(int j=1; j<lowbit(i); j<<=1)
			bit[i] = max(bit[i], b[i-j]);
		i += lowbit(i);
	}
}
int query(int l, int r) {
	int ret = 0;
	while(l<=r) {
		ret = max(a[r], ret);
		for(--r; r-l>=lowbit; r-=lowbit(r)) {
			ret = max(ret, bit[r]);
		}
	}
	return ret;
}
