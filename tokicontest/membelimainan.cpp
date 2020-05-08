#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, a, b, c;
	cin >> x >> a >> b >> c;
	int harga = a + b + c;
	int masing = x/harga;
	int total = 3 * masing;
	int saver1 = a + b;
	int saver2 = a + c;
	int saver3 = b + c;
	if (x%harga >= saver1 || x%harga >= saver2 || x%harga >= saver3) {
		cout << total + 2 << endl;
	}
	else if (x%harga >= a || x%harga >= b || x%harga >= c) {
		cout << total + 1 << endl;
	}
	else {
		cout << total << endl;
	}
}