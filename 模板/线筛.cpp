/*
��2��ʼö�٣���ǰ��i��ȥ��i*p�������������p����������p<i
ÿ������ֻ�ᱻ����С��������ɸȥ�������ܵĸ��Ӷ������Ե�
*/
int primes[MAXN+1],cnt;
int mark[MAXN+1];
void make()
{
    mark[1]=1;
    for(int i=2;i<=MAXN;i++)
    {
        if(mark[i]==0)//���iû�л�ȥ����iΪ����������������
            primes[++cnt]=i;
        //��ȥi��������ɸ���������ĳ˻�
        for(int j=1;j<=cnt&&(long long)i*primes[j]<=MAXN;j++)
        {
            mark[i*primes[j]]=1;//��ȥ�������ڵĺ���
            //��֤����ֻ������С����������ȥ�����ɸѡЧ��
            if(i%primes[j]==0)
                break;
        }
    }
}
