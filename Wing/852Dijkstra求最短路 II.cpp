/*
web:https://www.acwing.com/problem/content/852/
Date:2019年9月27日
Code by LJC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;

struct edge {
    int to, cost;
};

vector<edge> G[MAXN];
int d[MAXN], n, m, cnt;
priority_queue< P, vector<P>, greater<P> > q;

void add(int u, int v, int w) {
	G[u].push_back((edge){v,w});
}

int dijkstra(int s)
{
    int i;
    priority_queue<P,vector<P>,greater<P> >q;
    memset(d, 0x3f, sizeof(d));
    d[s]=0;
    q.push((P){0,s});
    while(!q.empty())
    {
        P p=q.top();
        q.pop();
        int v=p.second;
        if(d[v]<p.first)
            continue;
        for(i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[v]+e.cost<d[e.to])
            {
                d[e.to]=d[v]+e.cost;
                q.push((P){d[e.to],e.to});
            }
        }
    }
    if(d[n]==0x3f3f3f3f) return -1;
    return d[n];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	int ans = dijkstra(1);
	cout << ans;
    return 0;
}
