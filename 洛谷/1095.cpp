#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 300010;
int m, s, t, f[MAXN];

int main() {
	cin >> m >> s >> t;
	for(int i=1; i<=t; i++) {
		if(m>=10) {
			f[i] = f[i-1]+60;
			m -= 10;
		} else {
			f[i] = f[i-1];
			m += 4;
		} 
	}
	for(int i=1; i<=t; i++) {
		f[i] = max(f[i], f[i-1]+17);
		if(f[i] >= s) {
			cout << "Yes\n" << i;
			return 0;
		}
	}
	cout << "No\n" << f[t];
	return 0;
}