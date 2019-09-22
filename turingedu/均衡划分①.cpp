#include <iostream>
#include <cstdio>
using namespace std;

int x[1000010], y[1000010];
int n, m, a, b, c1, c2, c3, c4, ans=1e9;

int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) 
		cin >> x[i] >> y[i];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			a = x[i] + 1;
			b = y[j] + 1;
			for(int k=1; k<=n; k++) {
				if(x[k]>a && y[k]>b) c1++;
				if(x[k]<a && y[k]>b) c2++;
				if(x[k]<a && y[k]<b) c3++;
				if(x[k]>a && y[k]<b) c4++;
			}
			ans = min(ans, max(max(c1, c2), max(c3, c4)));
			c1 = c2 = c3 = c4 = 0;
		}
	}
	cout << ans;
	return 0;
}