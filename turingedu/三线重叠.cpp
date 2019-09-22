#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c, d, e, f;

int main() {
	cin >> a >> b >> c >> d >> e >> f;
	cout << max(0, min(min(b, d), f) - max(max(a, c), e) );
	return 0;
}