#include<iostream>
using namespace std;
string a,b;
int l;
int find(char ch)
{
	for(int i=0;i<l;i++)
		if(a[i]==ch)
			return i;
}
void dfs(int l1,int r1,int l2,int r2)
{
	int m=find(b[r2]);
	cout<<b[r2];
	if(m>l1)
		dfs(l1,m-1,l2,r2-r1+m-1);
    if(m<r1)
		dfs(m+1,r1,l2+m-l1,r2-1);
}
int main()
{
	cin>>a>>b;
	l=a.size()-1;
	dfs(0,l,0,l);
	return 0;
}
