/*
状压DP
1.判断一个数字x二进制下第i位是不是等于1。
方法：if(((1<<(i−1))&x)>0)
将1左移i-1位，相当于制造了一个只有第i位上是1，其他位上都是0
的二进制数。然后与x做与运算，如果结果>0，说明x第i位上是1，反之则是0。

2.将一个数字x二进制下第i位更改成1。
方法：x=x|(1<<(i−1))
证明方法与1类似，此处不再重复证明。

3.把一个数字二进制下最靠右的第一个1去掉。
方法：x=x&(x−1)
*/
#include <iostream>
#include <cstdio>
using namespace std;

#define LL long long
const int MAXN = 17;
int n, k, a[MAXN];
LL f[1<<MAXN][MAXN];

int main() {
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) 
		f[1<<i-1][i] = 1;
	for(int i=1; i<1<<n; i++) {
		for(int j=1; j<=n; j++) {
			if(((1<<j-1)&i)==0) continue;
			for(int l=1; l<=n; l++) {
				if(((1<<l-1)&i) || abs(a[j]-a[l])<=k) continue;
				f[i|(1<<l-1)][l]+=f[i][j];
			}
		}
	}
	LL ans=0;
	for(int i=1; i<=n; i++) {
		ans += f[(1<<n)-1][i];
	}
	cout << ans;
	return 0;
}
