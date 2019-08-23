#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=50005;
long long ans=0;
int heap[maxn],sz=0,n;
int pop()
{
    int ans=heap[0];
    int x=heap[--sz];
    int i=0;
    while((i*2+1)<sz)
    {
        int a=i*2+1,b=i*2+2;
        if(b<sz && heap[b]<heap[a]) a=b;
        if(heap[a]>=x)
        break;
        heap[i]=heap[a];
        i=a;
    }
    heap[i]=x;
    return ans;
}
void push(int x){
    int i=sz++;
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=x) break;
        heap[i]=heap[p];
        i=p;
    }
    heap[i]=x;
    return;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        push(t);
    }
    for(int i=1;i<n;i++){
        int x=pop();
        int y=pop();
        x+=y;
        ans+=x;
        push(x);
    }
    cout<<ans;
    return 0;
}
