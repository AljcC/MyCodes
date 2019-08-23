/*
  1.lowbit(i)��ʾ��bit�е�i���������䳤�ȣ��� i&-i
  2.bit[i]���ǵ�����Ϊ��bit[i-1],bit[i-2],bit[i-4],...,bit[i-j] | j<lowbit(i)
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
