#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 255;
const int MAXM = 2010;
struct pt {
	int x, y;
} a[MAXN];
int n, m, f[MAXM][MAXM];
char s[MAXM];

int main() {
	cin >> m >> n >> s+1;
	for(int i=1; i<=m; i++) {
		char c;
		cin >> c;
		cin >> a[(int)(c)].x >> a[(int)(c)].y;
	}
	memset(f,63, sizeof(f));
	for(int i=1; i<=n; i++) {
		f[i][i]=0;
	}
    for(int i=0; i<=n+1; i++) {
        for(int j=0; j<i; j++) {
        	f[i][j]=0;
        }
    }
	for(int k=1; k<=n; k++) {
		for(int i=1; i+k<=n; i++) {
			int j=k+i;
			f[i][j] = min(f[i+1][j]+min(a[(int)s[i]].x, a[(int)s[i]].y), f[i][j-1]+min(a[(int)s[j]].x, a[(int)s[j]].y));
			if(s[i]==s[j]) {
				if(j-i==1) f[i][j]=0;
				else f[i][j] = min(f[i][j], f[i+1][j-1]);
			}
		}
	}
	cout << f[1][n];
	return 0;
}