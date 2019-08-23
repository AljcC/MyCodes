#include<iostream>
#include<queue>
using namespace std;
priority_queue< int,vector<int>,greater<int> > q;
int ans;
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b;
            q.push(b);
        }
        if(a==2)
        {
            ans=q.top();
            cout<<ans<<endl;
        }
        if(a==3)
            q.pop();
    }
    return 0;
}
