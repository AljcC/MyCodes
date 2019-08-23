/*
从2开始枚举，当前数i，去掉i*p这个合数，其中p是质数，且p<i
每个合数只会被其最小的质因数筛去，所以总的复杂度是线性的
*/
int primes[MAXN+1],cnt;
int mark[MAXN+1];
void make()
{
    mark[1]=1;
    for(int i=2;i<=MAXN;i++)
    {
        if(mark[i]==0)//如果i没有划去，则i为质数，加入质数表
            primes[++cnt]=i;
        //划去i与所有已筛出的质数的乘积
        for(int j=1;j<=cnt&&(long long)i*primes[j]<=MAXN;j++)
        {
            mark[i*primes[j]]=1;//划去在区间内的合数
            //保证合数只被其最小的质因数划去，提高筛选效率
            if(i%primes[j]==0)
                break;
        }
    }
}
