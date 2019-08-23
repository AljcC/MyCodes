//�Ը���n���������ֽ⡣ʱ�临�Ӷ�O(sqrt(n))
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


//ɸ����ŷ������ֵ�ı�
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
    //�������ŷ������ֵ����������������ô˵������Ϊ����
        if(euler[i]==i)
        {
            for(int j=i;j<maxn;j+=i)
            //����i�������������������euler[j]=j-1
                euler[j]=euler[j]/i*(i-1);
        }
}
