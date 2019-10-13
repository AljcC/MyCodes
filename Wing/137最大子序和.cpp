#include <iostream>
#include <cstdio>
using namespace std;

const int N = 300010;
int n, m;
int a[N];
int s[N], q[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
	int l = 0, r = 0;
	int res = 0;
	for(int i=1; i<=n; i++) {
		while(q[l] < i-m) l++;
		res = max(res, s[i] - s[q[l]]);
		while(l<=r && s[i] <= s[q[l]]) r--;
		q[++r] = i;
	} 
	printf("%d\n", res);
	return 0;
}