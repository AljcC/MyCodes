#include<iostream>
using namespace std;
struct node
{
    char l,r,p;
    bool flag;
}a[230];
int n;
void dfs(char x)
{
    cout<<x;
    if(a[x].l!='0')
        dfs(a[x].l);
    if(a[x].r!='0')
        dfs(a[x].r);
}
int main()
{
    int i;
    char x,y,z;
    cin>>n;
    for(i=0;i<230;i++)
    {
        a[i].flag=0;
        a[i].p=0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        a[x].l=y;
        a[x].r=z;
        a[y].p=x;
        a[z].p=x;
        a[x].flag=1;
    }
    for(i=0;i<230;i++)
        if(a[i].flag==1&&a[i].p==0)
            break; 
    dfs(i);
    return 0;
}
