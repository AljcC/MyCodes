#include<iostream>
using namespace std;
bool a[1<<20+1];
int main()
{
	int d,t,i,j,now;
	cin>>d>>t;
	for(i=1;i<=t;i++)
	{
		now=1;
		for(j=1;j<d;j++)
		{
			a[now]=!a[now];
			now=a[now]?2*now:2*now+1;
		}
	}
	cout<<now;
	return 0;
}
