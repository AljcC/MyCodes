//对给定n进行整数分解。时间复杂度O(sqrt(n))
int eurler_phi(int n)
{
    int res=n;
    for(int i=2;(long long)i*i<=n;i++)
        if(n%i==0)
        {
            res=res/i*(i-1);
            while(n%i==0)
                n/=i;
        }
    if(n!=1)
        res=res/n*(n-1);
    return res;
}


//筛法求欧拉函数值的表
int euler[maxn];
void euler_phi2()
{
    for(int i=1;i<=maxn;i++)
    {
        if(i%2==0)
            euler[i]=i/2;
        else euler[i]=i;
    }
    for(int i=3;i<maxn;i+=2)
    //如果遇到欧拉函数值等于自身的情况，那么说明概述为素数
        if(euler[i]==i)
        {
            for(int j=i;j<maxn;j+=i)
            //对于i是质数的情况，计算后边euler[j]=j-1
                euler[j]=euler[j]/i*(i-1);
        }
}
