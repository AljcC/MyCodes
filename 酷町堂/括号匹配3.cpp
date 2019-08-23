#include<iostream>
#include<stack>
using namespace std;
int init(string s,int a[])
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='<')
			a[i]=0;
		else if(s[i]=='(')
			a[i]=1;
		else if(s[i]=='[')
			a[i]=2;
		else if(s[i]=='{')
			a[i]=3;
		else if(s[i]=='>')
			a[i]=4;
		else if(s[i]==')')
			a[i]=5;
		else if(s[i]==']')
			a[i]=6;
		else if(s[i]=='}')
			a[i]=7;
	}
}
bool check(int a[],int n)
{
	stack<int> stk;
	for(int i=0;i<n;i++)
	{
		if(a[i]<4)
		{
			if(!stk.empty()&&stk.top()<a[i])
				return 0;
			stk.push(a[i]);
		}
		else
		{
			if(stk.empty())
				return 0;
			if(a[i]-stk.top()==4)
				stk.pop();
			else return 0;
		}
	}
	if(stk.empty())
		return 1;
	else return 0;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		string s;
		int a[300];
		cin>>s;
		init(s,a);
		if(check(a,s.size()))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
