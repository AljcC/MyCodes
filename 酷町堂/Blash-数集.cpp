#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
	int n;
	cin>>n;
	q.push(1);
	for(int i=2;i<=n;i++)
	{
		int x=q.front();
		q.pop();
		q.push(2*x+1);
	}
	cout<<q.front();
	return 0;
}
