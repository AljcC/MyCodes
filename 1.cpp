#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 3010;
int n, a[MAXN], c[MAXN], b[MAXN];

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	b[1] = 1;
	int mx, max1=0;
	for(int i=2; i<=n; i++) {
		mx=0;
		for(int j=1; j<i; j++) {
			if(a[j]>a[i] && b[j]>mx) mx=b[j];
		b[i]=mx+1;
		max1=max(max1, b[i]);
	}
	c[1] = 1;
	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(a[j]g>a[i] && b[i]==b[j]+1) c[i]+=c[j];
		}
		if(c[i]==0) c[i]++;
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(b[i]==max1)
			ans+=c[i];
	}
	cout <<n-max1 << ' '<< ans;
	return 0;
}
