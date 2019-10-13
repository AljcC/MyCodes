#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50010;
int t, n, a[N];
int f[N];

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		int res = n;
		memset(f, 0, sizeof(f));
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			f[a[i]] = 2;
		}
		sort(a+1, a+n+1);
		for(int i=1; i<=N/2; i++) {
			if(f[i] > 0) {
				for(int j=1; j<=n; j++) {
					f[i+a[j]] = 1;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(f[a[i]] == 1) {
				res--;
			}
		}
		cout << res << '\n';
	}
	return 0;
}