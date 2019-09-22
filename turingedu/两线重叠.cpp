#include <iostream>
#include <cstdio>
using namespace std;

long long x1, y1, x2, y2;

int main() {
	cin >> x1 >> y1 >> x2 >> y2;
		cout << max((long long)0, min(y1, y2) - max (x1,x2));
	return 0;
}