#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100000;
const int INF = 100000000;

typedef pair<int, int> P;

struct edge {
    int to, cost;
};

vector<edge> G[MAXN];
int d[MAXN], n;
priority_queue< P, vector<P>, greater<P> > q;

void dijkstra(int s) {
    fill(d+1, d+n+1, INF);
    d[s] = 0;
    q.push(P(0, s));

    while(!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    return 0;
}
