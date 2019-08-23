#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
int n;
stack<int> p;
struct des
{
    int num;
    string s;
} q[2001];
int main()
{
	int i,j,t=0;
	stack<int> stk;
    while(1)
	{
		t++;
        cin>>q[t].s;
        if(q[t].s=="NUM")
			cin>>q[t].num;
        if(q[t].s=="END")
			break;
    }
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	int a;
    	bool flag=0;
    	cin>>a;
    	stk.push(a);
    	for(j=1;j<=t;j++)
    	{
    		if(q[j].s=="NUM")
				stk.push(q[j].num);
            else if(q[j].s=="POP")
            {
				if(stk.empty())
				{
					flag=1;
					break;
				}
				stk.pop();
			}
            else if(q[j].s=="INV")
            {
			    if(stk.empty())
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				stk.push(-s1);
			}
            else if(q[j].s=="DUP")
			{
				if(stk.empty())
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.push(s1);
			}
            else if(q[j].s=="SWP")
			{
				if(stk.size()<2)
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				int s2=stk.top();
				stk.pop();
				stk.push(s2);
				stk.push(s1);
			}
            else if(q[j].s=="ADD")
			{
				if(stk.size()<2)
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				int s2=stk.top();
				stk.pop();
				stk.push(s1+s2);
				if(abs(stk.top())>1000000000)
				{
					flag=1;
					break;
				}
			}
            else if(q[j].s=="SUB")
			{
				if(stk.size()<2)
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				int s2=stk.top();
				stk.pop();
				stk.push(s2-s1);
				if(abs(stk.top())>1000000000)
				{
					flag=1;
					break;
				}
			}
            else if(q[j].s=="MUL")
			{
				if(stk.size()<2)
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				int s2=stk.top();
				stk.pop();
				stk.push(s1*s2);
				if(abs(stk.top())>1000000000)
				{
					flag=1;
					break;
				}
			}
            else if(q[j].s=="DIV")
			{
				if(stk.size()<2)
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				int s2=stk.top();
				stk.pop();
				stk.push(s2/s1);
				if(abs(stk.top())>1000000000)
				{
					flag=1;
					break;
				}
			}
            else if(q[j].s=="MOD")
			{
				if(stk.size()<2)
				{
					flag=1;
					break;
				}
				int s1=stk.top();
				stk.pop();
				int s2=stk.top();
				stk.pop();
				stk.push(s2%s1);
				if(abs(stk.top())>1000000000)
				{
					flag=1;
					break;
				}
			}
			else if(q[j].s=="END")
				break;
		}
		if(flag||stk.size()!=1) 	
            cout<<"ERROR!"<<endl;
        else cout<<stk.top()<<endl;
        while(!stk.empty())
        	stk.pop();
	}
    return 0;
}
