#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, n;
	cin >> c >> n;
	bool consistent = true;
	int curr = 0;
	int enter, exit, wait;
	for (int i = 0; i < n; i++) {
		cin >> exit >> enter >> wait;
		curr -= exit;
		if (curr < 0) {
			consistent = false;
		}
		curr += enter;
		if (curr > c) {
			consistent = false;
		}
		if (curr < c && wait != 0) {
			consistent = false;
		}
	}
	if (curr != 0 || enter != 0 || wait != 0) {
		consistent = false;
	}
	if (!consistent) {
		cout << "impossible" << endl;
	}
	else {
		cout << "possible" << endl;
	}
}