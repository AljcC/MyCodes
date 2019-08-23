/*
d[i][S]表示前i个点中，状态为S的情况下的最小距离和
d[i][s]=min(d[i][s],dis(p[i],p[j])+d[i-1][s^(1<<(i-1))^(1<<(j-1))]); 在集合s中第i为1
d[i][s] = d[i-1][s];                                                 在集合s中第i为0
边界：d[0][0] = 0;
解：d[n][(1<<n)-1]
1.判断状态s中第i位是否为1.
if(s&(1<<(i-1))) {
	//表示s中第i位是1.
}
2.捋第i位置为0.
s^(1<<(i-1))    必须要求s中第i位是1.
s&~(1<<(i-1))   无上述要求
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 22;
const int INF = 100000000;
struct pt {
	int x, y, z;
};
int n;
pt p[MAXN];
double d[MAXN][1<<MAXN];

double dis(pt p1, pt p2) {
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	d[0][0] = 0;
	for(int i=1; i<=n; i++){
		for(int s=0; s<(1<<i); s++) {
			//判断第i个点是否在集合s中
			d[i][s] = INF;
			if(s&(1<<(i-1))) {
				for(int j=1; j<i; j++){
					if(s&(1<<(j-1))){
						d[i][s] = min(d[i][s], dis(p[i],p[j])+d[i-1][s^(1<<(i-1))^(1<<(j-1))]);
					}
				}
			} else {
				d[i][s] = d[i-1][s];
			}
		}
	}
	printf("%.3f", d[n][(1<<n)-1]);
	return 0;
}