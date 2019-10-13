#include <iostream>
#include <cstdio> 
#include <vector>
using namespace std;

const int N = 40;
int x, y, k, b;
int f[N][N];

void init() {
	for(int i=0; i<N; i++) 
		for(int j=0; j<=i; j++) {
			if(!j) f[i][j] = 1;
			else f[i][j] = f[i-1][j] + f[i-1][j-1];
		}
}

int dp(int t) {
	vector<int> num;
	int last = 0, res = 0;
	while(t) num.push_back(t%b), t/=b;
	for(int i=num.size()-1; i>=0; i--) {
		int x = num[i];
		if(x) {
			res += f[i][k-last];
			if(x>1) {
			    if(k-last-1 > 0) res += f[i][k-last-1];
				break;
			} else {
				last += x;
				if(last > k) break;
			}
		}
		if(!i && k==last) res++;
	} 
	return res;
}

int main() {
	scanf("%d%d%d%d", &x, &y, &k, &b);
	init();
	printf("%d\n", dp(y)-dp(x-1));
	return 0;
}