/*
web:https://www.acwing.com/problem/content/1023/
Date:2019年10月2日
Code by LJC
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 3010;
int n, m;
int a[N], f[N];

int main() {
	cin >> n >> m;
	for(int i=1 ;i<=n; i++) {
		cin >> a[i];
	}
	f[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=a[i]; j<=m; j++) {
			f[j] += f[j-a[i]];
		}
	}
	cout << f[m];
	return 0;
}