#include <iostream>
using namespace std;

#define MAXLEN 10000

struct Stack {
	int top;
	int a[MAXLEN];
};

Stack s;

bool is_empty(Stack& s) {
	if(s.top == 0) return true;
	return false;
}

bool push(Stack& s, int x) {
	if(s.top >= MAXLEN) return false;
	s.a[s.top] = x;
	s.top++;
	return true;
}

bool pop(Stack& s,int& x){
	if(s.top <= 0) return false;
	s.top --;
	x = s.a[s.top];
	return true;
}
int main() {
	int n, i, x;
	cin >> n;  
	for(i = 0; i < n; i ++) {
		cin>>x;
		push(s, x);
	}
	for(i = 0; i < n; i ++){
		pop(s, x);
		cout << x;
	}
	return 0;
}
