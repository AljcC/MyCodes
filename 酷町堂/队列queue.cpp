#include<iostream>
using namespace std;
const int MAX=10000; 
struct Queue
{
	int head,tail;
	int a[MAX];
}q;
void init(Queue &q)
{
	q.head=q.tail=0;
}
bool isEmpty(Queue &q)
{
	if(q.head==q.tail)
		return 1;
	else return 0;
}
bool isFull(Queue &q)
{
	return (q.tail+1)%MAX==q.head; 
}
bool Ru(Queue &q,int e)
{
	if(isFull(q))
		return 0;
	q.a[q.tail]=e;
	q.tail=(q.tail+1)%MAX;
	return 1;
}
bool Chu(Queue &q,int &e)
{
	if(isEmpty(q))
		return 0;
	e=q.a[q.tail];
	q.head=(q.head+1)%MAX;
	return 1;
}
bool Size(Queue &q)
{
	return (q.tail-q.head+MAX)%MAX;
}
int main()
{
	int n, i, x;
	cin >> n;  
	for(i = 0; i < n; i ++)
	{
		cin>>x;
		Ru(q, x);
	}
	for(i=0;i<n;i++)
	{
		Chu(q, x);
		cout << x;
	}
	return 0;
}
/*
STL �ж��е�ʹ��(queue) 

push(x) ��xѹ����е�ĩ��

pop() �������еĵ�һ��Ԫ��(�Ӷ�Ԫ��)��ע��˺������������κ�ֵ

front() ���ص�һ��Ԫ��(�Ӷ�Ԫ��)

back() �������ѹ���Ԫ��(��βԪ��)

empty() ������Ϊ��ʱ������true

size() ���ض��еĳ��� 

ͷ�ļ���#include <queue>

1����ͨ���� queue<int>q;

2���ṹ������
struct node
{    
   int x, y;
};
queue<node>q;

*/
