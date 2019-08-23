#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100000;
const int INF = 100000000;

int G[MAXN][MAXN], d[MAXN], n;
bool used[MAXN];

void dijkstra(int s) {
    fill(d+1, d+n+1, INF);
    memset(used, false, sizeof(used));
    d[s] = 0;
    while(true) {
        int v=-1;
        for(int i=1; i<=n; i++) {
            if(!used[i] && (v==-1 || d[i]<d[v])) v = i;
        }
        if(v == -1) break;
        used[v] = true;
        for(int i=1; i<=n; i++) {
            d[i] = min(d[i], d[v]+G[v][i]);
        }
    }
}

int main() {
    return 0;
}
