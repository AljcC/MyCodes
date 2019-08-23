#include<iostream>
using namespace std;
int n;
string s;
char a[1<<11];
void build(int x,int l,int r)
{
	if(l==r)
	{
		a[x]=s[l]=='0'?'B':'I';
		cout<<a[x];
		return;
	}
	int m=(l+r)/2;
	build(2*x,l,m);
	build(2*x+1,m+1,r);
	if(a[2*x]=='I'&&a[2*x+1]=='I')
		a[x]='I';
	else if(a[2*x]=='B'&&a[2*x+1]=='B')
		a[x]='B';
	else a[x]='F';
	cout<<a[x];
}
int main()
{
	cin>>n>>s;
	build(1,0,s.size()-1);
	return 0;
}
