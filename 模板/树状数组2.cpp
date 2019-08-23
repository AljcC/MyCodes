void solve() {
	for(int i=1; i<=n; i++)
		add(bit0, i, a[i]);
	for(int i=1; i<=Q; i++) {
		if(T[i]== 'C') {
			add(bit0, l[i], -x[i]*(l[i]-1));
			add(bit1, l[i], x[i]);
			add(bit0, r[i]+1, x[i]*r[i]);
			add(bit1, r[i]+1, -x[i]);
		}
		else {
			LL res=0;
			res = sum(bit0, r[i]) + sum(bit1, l[i] - 1) *(l[i] - 1);
			res -= sum(bit0, l[i] - 1) + sum(bit1, l[i] - 1) *(l[i] - 1);
			printf("%lld\n", res);
		}
	}
} 
