#include <bits/stdc++.h>
using namespace std;

int main() {
	long long m, n, t;
	cin >> m >> n >> t;
	if (t == 1) {
		long long tmp = 1;
		bool bs = true;
		for (int i = 2; i <= n; i++) {
			tmp *= i;
			if (tmp > m) {
				bs = false;
				break;
			}
		}
		if (bs) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
	else if (t == 5) {
		long long num = n;
		for (int i = 0; i < 1; i++) {
			n *= num;
			if (n > m) {
				break;
			}
		}
		if (n <= m) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
	else if (t == 3) {
		long long num = n;
		for (int i = 0; i < 3; i++) {
			n *= num;
			if (n > m) {
				break;
			}
		}
		if (n <= m) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
	else if (t == 4) {
		long long num = n;
		for (int i = 0; i < 2; i++) {
			n *= num;
			if (n > m) {
				break;
			}
		}
		if (n <= m) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
	else if (t == 2) {
		bool bs = true;
		long long num = 1;

		for (int i = 0; i < n; i++) {
			num = num << 1;
			if (num > m) {
				bs = false;
				break;
			}
		}
		if (bs) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
	else if (t == 6) {
		double c = double(n)*log2(n);
		// cout << c << endl;
		if (c <= m) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
	else if (t == 7) {
		if (n <= m) {
			cout << "AC" << endl;
		}
		else {
			cout << "TLE" << endl;
		}
	}
}