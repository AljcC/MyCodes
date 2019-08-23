#include <iostream>
using namespace std;
int main()
{
    int n,m,i,j,min1,min2,a[10010],b[10010],c[10010],f[10010];
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        f[i]=1;
    }
    for(i=0;i<m;i++)
    {
        min1=100000000;
        for(j=0;j<n;j++)
            if(a[j]*f[j]*f[j]+b[j]*f[j]+c[j]<min1)
            {
                min1=a[j]*f[j]*f[j]+b[j]*f[j]+c[j];
                min2=j;
            }
        cout<<a[min2]*f[min2]*f[min2]+b[min2]*f[min2]+c[min2]<<' ';
        f[min2]++;
    }
    return 0;
}
