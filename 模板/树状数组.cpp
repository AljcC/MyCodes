const int MAXN=100000;
int bit[MAXN+10];
int sum(int i) 
{
	int ret = 0;
	while(i>0) {
		ret += bit[i];
		i -= i&-i;
	}
	return ret;
}
void add(int i, int x)
{
	while(i<=n) {
		bit[i] += x;
		i += i&-i;
	}
} 

