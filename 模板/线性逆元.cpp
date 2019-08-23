#include<iostream>
using namespace std;
#define LL long long
LL inv[MAXN];
int main()
{
	//1.循环求解
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv=(p-p/i)*inv[p%i]%p;
	//2.递归求解
	int Get_inv(int n)
	{
		if(n==1)
			return 1;
		return (p-p/n)*(Get_inv(p%n))%p;
	} 
}
