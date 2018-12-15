#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, x, y, e;
	cin >> a >> b >> c >> d >> e;
	x = abs(a-c);
	y = abs(b-d);
	e -= x+y;
	if (e < 0 | e%2 != 0) {
		cout << "N" << endl;
	}
	else {
		cout << "Y" << endl;
	}
}