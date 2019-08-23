#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 100000000;
const int MAXN = 200;
int T, n, f[MAXN][MAXN], p[MAXN][MAXN];
char s[MAXN];

void print(int l, int r) {
	if(l>r) return;
	if(l==r) {
		if(s[l]=='(' || s[r]==')') {
			printf("()");
		} else {
			printf("[]");
		}
		return;
	}
	if(p[l][r]==-1) {
		printf("%c", s[l]);
		print(l+1, r-1);
		printf("%c", s[r]);
		return;
	}
	print(l, p[l][r]);
	print(p[l][r]+1, r);
}

bool match(char a, char b) {
	if(a=='(' && b==')' || a=='[' && b==']') return true;
	return false;
}

int main() {
	cin >> T;
	cin.ignore();
	while(T--) {
		gets(s+1);
		gets(s+1);
		n = strlen(s+1);
		memset(p, -1, sizeof(p));
		for(int i=1; i<=n; i++) f[i][i] = 1;
		for(int l=1; l<=n; l++) {
			for(int i=1; i<=n; i++) {
				int j = i+l;
				if(j>n) break;
				f[i][j] = INF;
				if(match(s[i], s[j])) f[i][j] = min(f[i][j], f[i+1][j-1]);
				for(int k=i; k<j; k++) {
					if(f[i][k]+f[k+1][j] < f[i][j]) {
						f[i][j] = f[i][k]+f[k+1][j];
						p[i][j] = k;
					}
				}
			}
		}
		print(1, n);
		printf("\n");
		if(T) printf("\n");
	}
	return 0;
}