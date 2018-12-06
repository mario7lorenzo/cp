#include <bits/stdc++.h>
using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;
	int drank = 0;
	int kosong = e + f;
	while (kosong >= c) {
		int temp = kosong/c;
		drank += kosong/c;
		kosong = kosong%c;
		kosong += temp;
	}
	cout << drank << endl;
}