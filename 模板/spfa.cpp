#include <iostream>
#include <queue>
#include<cstring>
#include <vector>
using namespace std;
struct edge {
    int to, cost;
};

const int MAXN = 100000;
queue<int> q;
vector<edge> G[MAXN];
int d[MAXN], n, m, S;
bool exist[MAXN];

void spfa(int s) {
    fill(d+1, d+1+n,1e9);
    memset(exist, false, sizeof(exist));
    d[s] = 0;
    q.push(s);
    exist[s] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        exist[v] = false;
        for(int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if(d[v]+e.cost < d[e.to]) {
                d[e.to] = d[v] + e.cost;
                if(!exist[e.to]) {
                    q.push(e.to);
                    exist[e.to] = true;
                }
            }
        }
    }
}
int main()
{
	cin>>n>>m>>S;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back((edge){v,w}); 
	}
	spfa(S);
	for(int i=1;i<=n;i++)
		cout<<d[i]<<' ';
	return 0;
}
