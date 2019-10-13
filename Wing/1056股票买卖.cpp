/*
web:https://www.acwing.com/problem/content/1056/
Date:2019年10月1日
Code by LJC
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int n, a[N];
int ans, minn=0x3f3f3f3f;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        ans = max(ans, a[i] - minn);
        minn = min(minn, a[i]);
    }
    cout << ans;
    return 0;
}