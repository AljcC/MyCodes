int mark[MAXN+1];//������飬0��ʾû��ɸ��������
int primes[MAXN+1],cnt;//primes��������
void make_prime()
{
    mark[1]=1;
    for(int i=2;i<=MAXN;i++)//��2��ʼö��
    {
        if(mark[i]==0)
        {
            primes[++cnt]=i;//�������Ž���������
            for(int j=i*i;j<=MAXN;j+=i)//��i*2��һ��
                mark[j]=1;//��ȥ����i�ı���
        }
    }
}
