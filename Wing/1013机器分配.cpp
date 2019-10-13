#/*
web:https://www.acwing.com/problem/content/1015/
Date:2019年9月27日
Code by LJC

输入样例：
3 3
30 10 10
20 10 20
20  5  5
输出	样例：
70
1 1
2 1
3 1
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 20;
int n, m;
int a[N][N];
int b[N];
int f[N][N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=1; i<=n; i++) 
		for(int j=0; j<=m; j++)
			for(int k=0; k<=j; k++) 
				f[i][j] = max(f[i][j], f[i-1][j-k] + a[i][k]);
	cout << f[n][m] <<' ';
	int j = m;
	for(int i=n; i; i--)
		for(int k=0; k<=j; k++) 
			if(f[i][j] == f[i-1][j-k] + a[i][k]) {
				b[i] = k;
				j-=k;
				break;
			}
	for(int i=1; i<=n; i++) {
		cout << i << " " << b[i] << '\n';
	}
	return 0;
}