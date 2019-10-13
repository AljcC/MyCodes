#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int n, a[N];
int f[N];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	f[1] = a[1];
	for(int i=2; i<=n; i++) {
		if(a[i] < a[i-1]) f[i] = f[i-1];
		else f[i] = f[i-1] + a[i] - a[i-1];
	}
	cout << f[n];
	return 0;
}