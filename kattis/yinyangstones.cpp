#include <bits/stdc++.h>
using namespace std;

int main() {
	string arr;
	cin >> arr;
	int w = 0, b = 0;
	for (auto i : arr) {
		if (i == 'W') {
			w++;
		}
		else {
			b++;
		}
	}
	if (w == b) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}