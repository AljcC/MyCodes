#include<iostream>
#include<queue>
using namespace std;
const int dir[12][2]=
{
	{-2,-2},{-1,-2},{-2,-1},
	{-2,2},{-2,1},{-1,2},
	{2,-2},{1,-2},{2,-1},
	{2,2},{2,1},{1,2}
};
bool vis[101][101];
struct coord
{
	int x,y;
	int count;
};
queue<coord> q;
bool canJump(int x,int y)
{
	if(x>=1&&x<=100&&y>=1&&y<=100)
		return 1;
	else return 0;
}
int bfs(int x,int y)
{
	while(!q.empty())
		q.pop();
	q.push((coord){x,y,0});
	while(!q.empty())
	{
		coord now=q.front();
		q.pop();
		if(now.x==1&&now.y==1)
			return now.count;
		for(int i=0;i<12;i++)
		{
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(canJump(nx,ny)&&!vis[nx][ny])
			{
				vis[nx][ny]=1;
				q.push((coord){nx,ny,now.count+1});
			}
		}
	}
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	vis[a][b]=1;
	cout<<bfs(a,b);
	vis[a][b]=1;
	cout<<bfs(c,d);
	return 0;
} 
