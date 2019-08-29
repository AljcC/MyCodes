#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1010;
int n, m, ans, a[MAXN][MAXN], h[MAXN], l[MAXN], r[MAXN], k[MAXN];

void CountL() {
	int top=0;
	for(int i=m; i>=1; i--) {
		while(top!=0 && h[i]<=h[k[top]])  l[k[top]] = i, top--;
		top++;
		k[top]=i;
	}
	while(top) l[k[top]]=0,top--;
}

void CountR() {
	int top=0;
	for(int i=1; i<=m; i++) {
		while(top!=0 && h[i]<h[k[top]]) r[k[top]] = i, top--;
		top++;
		k[top]=i;
	}
	while(top) r[k[top]]=m+1,top--;
}

void work() {
	CountL();
	CountR();
	for(int i=1; i<=m; i++) 
		ans+=h[i]*(i-l[i])*(r[i]-i);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			char c;
			cin >> c;
			a[i][j] = (c=='.'?1:0);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			h[j]++;
			if(a[i][j]==0) h[j]=0;
		}
		work();
	}
	cout << ans;
	return 0;
}