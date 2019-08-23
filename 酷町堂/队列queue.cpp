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
STL 中队列的使用(queue) 

push(x) 将x压入队列的末端

pop() 弹出队列的第一个元素(队顶元素)，注意此函数并不返回任何值

front() 返回第一个元素(队顶元素)

back() 返回最后被压入的元素(队尾元素)

empty() 当队列为空时，返回true

size() 返回队列的长度 

头文件：#include <queue>

1、普通声明 queue<int>q;

2、结构体声明
struct node
{    
   int x, y;
};
queue<node>q;

*/
