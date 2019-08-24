#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
int n, a[MAXN], f[MAXN];

int main() {

	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}	
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) {
		f[i] = max(f[i-1], a[i]-f[i-1]);
	}
	cout << f[n];
	return 0;
}