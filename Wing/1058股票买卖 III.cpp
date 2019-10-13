/*
web:https://www.acwing.com/problem/content/1058/
Date:2019年10月2日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100010;
int n, a[N];
int f[N][2];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(f, 0xcf, sizeof(f));
    for(int i=0; i<=n; i++) f[i][0] = 0;
    for(int i=1; i<=n; i++) {
        f[i][0] = max(f[i-1][0], f[i-1][1] + a[i]);
        f[i][1] = max(f[i-1][1], f[i-1][0] - a[i]);
    }
    cout << f[n][0];
    return 0;
}