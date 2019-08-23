int mark[MAXN+1];//标记数组，0表示没被筛掉是素数
int primes[MAXN+1],cnt;//primes是质数表
void make_prime()
{
    mark[1]=1;
    for(int i=2;i<=MAXN;i++)//从2开始枚举
    {
        if(mark[i]==0)
        {
            primes[++cnt]=i;//将素数放进素数表里
            for(int j=i*i;j<=MAXN;j+=i)//比i*2快一点
                mark[j]=1;//划去所有i的倍数
        }
    }
}
