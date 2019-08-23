#include<iostream>
#include<queue>
using namespace std;
struct cmp1
{
    bool operator () (int &a,int &b)
    {
        return a<b;
    }
};
struct cmp2
{
    bool operator () (int &a,int &b)
    {
        return a>b;
    }
};
int n,x,y;
int main()
{
    priority_queue<int,vector<int>,cmp1>que1;
    priority_queue<int,vector<int>,cmp2>que2;
    cin>>n>>x;
    que1.push(x);
    cout<<x<<endl;
    for(int i=3;i<=n;i+=2)
    {
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        que1.push(x);
        que2.push(y);
        if(que1.top()>que2.top())
        {
            int a=que1.top(),b=que2.top();
            que1.pop();
            que1.push(b);
            que2.pop();
            que2.push(a);
        }
        cout<<que1.top()<<endl;
    }
    return 0;
}
