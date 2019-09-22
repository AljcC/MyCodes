#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5010;
int n, a[MAXN], c[MAXN], b[MAXN];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    b[1] = 1;
    int mx, max1=b[1];
    for(int i=2; i<=n; i++) {
        mx=0;
        for(int j=1; j<i; j++) {
            if(a[j]>a[i] && b[j]>mx) mx=b[j];
        }
        b[i]=mx+1;
        max1=max(max1, b[i]);
    }
    c[1] = 1;
    for(int i=2; i<=n; i++) {
        bool book[MAXN];
        for(int i=1; i<MAXN; i++) book[i] =1;
        for(int j=i-1; j>=1; j--) {
            if(a[j]>a[i] && b[i]==b[j]+1 &&book[j]) {
                c[i]+=c[j];
                for(int k=1; k<=j-1; k++)
                    if(a[k] == a[j] && b[k] == b[j]) 
                        book[k]=0;
                }
        }
        if(c[i]==0) c[i]++;
    }
    int ans=0;
    for(int i=n; i>=1; i--) {
        if(b[i]==max1)
            ans+=c[i];
    }
        cout <<max1 << ' '<< ans;
    return 0;
}