#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	long long x;
	while (cin >> x) {
		long long jumlah = -x;
		long long batas = x;
		long long sekarang = 1;
		while (sekarang < batas) {
			if (x%sekarang == 0) {
				jumlah += sekarang;
				batas = x/sekarang;
				if (sekarang != batas) {
					jumlah += batas;
				}
			}
			// cout << "ini skrg " << sekarang << endl;
			// cout << "ini batas " << batas << endl;
			// cout << "ini jumlah " << jumlah << endl;
			sekarang++;
		}
		cout << x << ' ';
		if (x == jumlah) {
			cout << "perfect" << endl;
		}
		else if (abs(jumlah - x) <= 2) {
			cout << "almost perfect" << endl;
		}
		else {
			cout << "not perfect" << endl;
		}
	}
}