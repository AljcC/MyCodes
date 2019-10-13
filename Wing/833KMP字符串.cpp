/*
web:https://www.acwing.com/problem/content/description/833/
Date:2019.10.2
Code by LJC
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10010;
const int M = 100010;
int n, m;
char p[N], s[M];
int f[N];

int main() {
    cin>>n>>p+1>>m>>s+1;
    for(int i=2,j=0; i<=n; i++) {
        while(j && p[i]!=p[j+1]) j = f[j];
        if(p[i] == p[j+1])
            j++;
        f[i] = j;
    }
    for(int i=1,j=0; i<=m; i++) {
        while(j && s[i]!=p[j+1]) j = f[j];
        if(s[i] == p[j+1])
            j++;
        if(j==n) {
            cout << i-n <<' ';
            j = f[j];
        }
    }
    return 0;
}