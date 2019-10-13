#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 50;
int f[N][N];
int a, b;

void init() {
	for(int i=0; i<=9; i++) f[0][i] = 1;
	for(int i=1; i<N; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=j; k<=9; k++) {
				f[i][j] += f[i-1][k];
			}
		}
	}
}

int dp(int t) {
    if (!t) return 1;
	vector<int> num;
	while(t) num.push_back(t%10), t/=10;
	int res = 0, last = 0;
	for(int i=num.size()-1; i>=0; i--) {
		int x = num[i];
		if(last > x) break;
		if(last < x) {
			for(int j=last; j<x; j++) {
				res += f[i][j];
			}	
		}
		last = x;
		if(!i) res++;
	}
	return res;
}

int main() {
		init();
	while(~scanf("%d %d", &a, &b)) {
		printf("%d\n", dp(b)-dp(a-1));
	}
	return 0;
}