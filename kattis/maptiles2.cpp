#include <bits/stdc++.h>
using namespace std;

long long res(long long a, long long b) {
	long long x = 1;
	for (int i = 0; i < b; i++) {
		x *= a;
	}
	return x;
}

int main() {
	string op;
	cin >> op;
	long long x = 0, y = 0;
	for (int i = 0; i < op.length(); i++) {
		long long fac = res(2, op.length()-i-1);
		if (op[i] == '1') {
			x+= fac;
		}
		else if (op[i] == '2') {
			y += fac;
		}
		else if (op[i] == '3') {
			x += fac;
			y += fac;
		}
	}
	cout << op.length() << ' ' << x << ' ' << y << endl;
}