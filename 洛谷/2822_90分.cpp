#include <iostream>
using namespace std;

const int N = 2010;
int n, k, m, t;
long long a[N][N];

int main(){
	cin >> t >> k;
	a[1][1] = 1;
	for(int i=1; i<=2000; i++) {
		a[i][0] = 1;
		for(int j=1; j<=2000; j++) {
			a[i][j] += (a[i-1][j-1]%k + a[i-1][j]%k)%k;
		}
	}
	while(t--) {
		cin >>n >> m;
		int res = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=min(i,m); j++) {
				if(a[i][j] % k == 0)
					res ++;
			}
		}
		cout << res << '\n';
	}
	return 0;
}