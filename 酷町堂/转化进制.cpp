#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int main() {
	int n, d;
	cin >> n >> d;
	while(n) {
		int r = n % d;
		if(n<=9)
			s.push(r+'0');
		else s.push((char)(r-10+'A'));
		n /= d;
	}
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
} 
