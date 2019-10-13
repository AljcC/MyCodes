/*
web:https://www.acwing.com/problem/content/1051/
Date:2019年9月27日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100010;
int T, n;
int a[N];
int f[N];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		memset(f, 0, sizeof(f));
		for(int i=1; i<=n; i++) {
			f[i] = max(f[i-1], f[i-2]+a[i]);			
		}
		printf("%d\n", f[n]);
	}
	return 0;
}