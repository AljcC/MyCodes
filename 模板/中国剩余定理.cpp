int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int CRT(int a[],int m[],int n)
{
    int M=1;
    for(int i=1;i<=n;i++)
        M*=m[i];
    for(int i=1;i<=n;i++)
    {
        int x,y;
        int Mi=M/m[i];
        exgcd(Mi,m[i],x,y);
        x=(x%b[i]+b[i])%b[i];
        ans=(ans+a[i]*x*Mi)%M;
    }
    return (ans%M+M)%M;
}
