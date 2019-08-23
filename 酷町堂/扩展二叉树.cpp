#include<iostream>
using namespace std;
struct node
{
	char c;
	int l,r;
}a[10001];
int cnt,sidx;
string s;
int newnode(char c)
{
	cnt++;
	a[cnt].c=c;
    a[cnt].l=a[cnt].r=0;
    return cnt;
}
void build(int fa,bool left)
{
	if(sidx>s.size()-1||s[sidx]=='.')
	{ 
		sidx++; 
		return;
	} 
	int id=newnode(s[sidx]);
	if(fa)
	{
		if(left)
			a[fa].l=id;
		else a[fa].r=id;
	}
	sidx++;
	build(id,1);
	build(id,0);
}
void zx(int x)
{
	if(x==0)
		return;
	zx(a[x].l);
	cout<<a[x].c;
	zx(a[x].r);
}
void hx(int x)
{
	if(x==0)
		return;
	hx(a[x].l);
	hx(a[x].r);
	cout<<a[x].c;
}
int main()
{
	cin>>s;
	build(0,0);
	zx(1);
	cout<<endl;
	hx(1);
	return 0;
}
