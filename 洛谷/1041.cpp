#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,o,o2,maxd,ans;
bool v[301];
struct node{
	int x,next;
}e[1000],e2[1000];
int k[301],k2[301];
int p[301],d[301][301];
int son[301][301];
void add2(int x,int y){
	e2[++o2].x=y;
	e2[o2].next=k2[x];
	k2[x]=o2;
}
void add(int x,int y){
	e[++o].x=y;
	e[o].next=k[x];
	k[x]=o;
}
void maketree(int x){
    for (int t=k2[x];t;t=e2[t].next)
		if (!v[e2[t].x]){
			v[e2[t].x]=true;
			add(x,e2[t].x);
			maketree(e2[t].x);
		}
}
void getlen(int x,int deep){
	d[deep][++d[deep][0]]=x;
	if (deep>maxd) maxd=deep;
	for (int t=k[x];t;t=e[t].next)
		getlen(e[t].x,deep+1);
}
int change(int x,bool V[]){
    int s=0;
    for (int t=k[x];t;t=e[t].next)
        if (!v[e[t].x]){
                       v[e[t].x]=true;
                       V[e[t].x]=true;
                       s+=change(e[t].x,V)+1;
        }
    return s;
}
void change2(int x,bool V[]){
     for (int t=k[x];t;t=e[t].next){
         if (V[e[t].x]){
                        v[e[t].x]=false;
                        V[e[t].x]=false;
                        change2(e[t].x,V);
         }
     }
}
void search(int num,int tot){
	if (num==maxd+1){
		if (ans<tot) ans=tot;
		return;
	}
    bool V[301]; 
	memset(V,0,sizeof(V));
	int sum=0;
	for (int i=1;i<=d[num][0];i++)
        if (!v[d[num][i]]){
                      int x=change(d[num][i],V)+(v[d[num][i]]==0);
                      v[d[num][i]]=true;
                      search(num+1,tot+x);
                      v[d[num][i]]=false;
                      change2(d[num][i],V);
                      sum++;
        }
    if (sum==0) if (ans<tot) ans=tot;
}
int main(){
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=m;i++){
	    int x,y;
		scanf("%d %d\n",&x,&y);
		add2(x,y);
		add2(y,x);
	}
	v[1]=true;
	maketree(1);
	getlen(1,0);
	memset(v,0,sizeof(v));
	search(1,0);
	printf("%d",n-ans);
	return 0;
}