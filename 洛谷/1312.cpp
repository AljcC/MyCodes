#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, map[10][10];
int ans[10][10], last[10][10][10];
bool f[10][10];

bool check() {
	for(int i=1; i<=5; i++) {
		if(map[i][1]) return 0;
	}
	return 1;
}

bool remove(){
    int flag=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++){
            if(i-1>=1&&i+1<=5&&map[i][j]==map[i-1][j]&&map[i][j]==map[i+1][j]&&map[i][j]){
                f[i-1][j]=1;f[i+1][j]=1;f[i][j]=1;flag=1;
            }
            if(j-1>=1&&j+1<=7&&map[i][j]==map[i][j+1]&&map[i][j]==map[i][j-1]&&map[i][j]){
                f[i][j]=1;f[i][j+1]=1;f[i][j-1]=1;flag=1;
            }
        }
    if(!flag)return 0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
        if(f[i][j]){
            f[i][j]=0;
            map[i][j]=0;
        } 
    return 1;
}

void copy(int x){
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
        last[x][i][j]=map[i][j];
}

void update(){
    for(int i=1;i<=5;i++){
        int wow=0;
        for(int j=1;j<=7;j++){
            if(!map[i][j])wow++;
            else{
                if(!wow)continue;
                map[i][j-wow]=map[i][j];
                map[i][j]=0;
            }
        }
    }
}

void move(int i,int j,int x){
    int tmp=map[i][j];
    map[i][j]=map[i+x][j];
    map[i+x][j]=tmp;
    update();
    while(remove())update();
}

void DFS(int x){
    if(check()){
        for(int i=1;i<=n;i++){
            if(i!=1)printf("\n");
            for(int j=1;j<=3;j++)
            printf("%d ",ans[i][j]);
        }
        exit(0);
    }
    if(x==n+1)return;
    copy(x);
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++){
            if(map[i][j]){
                if(i+1<=5&&map[i][j]!=map[i+1][j]){
                move(i,j,1);
                ans[x][1]=i-1;ans[x][2]=j-1;ans[x][3]=1;
                DFS(x+1);
                for(int i=1;i<=5;i++)
                    for(int j=1;j<=7;j++)
                    map[i][j]=last[x][i][j];
                ans[x][1]=-1;ans[x][2]=-1;ans[x][3]=-1;
            }
            if(i-1>=1&&map[i-1][j]==0){
                move(i,j,-1);
                ans[x][1]=i-1;ans[x][2]=j-1;ans[x][3]=-1;
                DFS(x+1);
                for(int i=1;i<=5;i++)
                    for(int j=1;j<=7;j++)
                    map[i][j]=last[x][i][j];
                ans[x][1]=-1;ans[x][2]=-1;ans[x][3]=-1;
            }
            }
        }
}

int main() {
	cin >> n;
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=8; j++) {
			int x;
			cin >> x;
			if(x==0) break;
			map[i][j]=x;
		}
	}
	memset(ans, 1, sizeof(ans));
	DFS(1);
	cout << -1;
	return 0;
}