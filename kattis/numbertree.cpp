#include <bits/stdc++.h>
using namespace std;

int main() {
	int h;
	string op;
	cin >> h;
	int node = pow(2, h+1) - 1;
	cin >> op;
	int base;
	if (op.length()) {
		for (int i = 0; i < op.length(); i++) {
			if (i == 0) {
				if (op[i] == 'L') {
					base = 1;
					node -= base;
				}
				else {
					base = 2;
					node -= base;
				}
			}
			else {
				if (op[i-1] == 'L') {
					if (op[i] == 'L') {
						base *= 2;
						node -= base;
					}
					else {
						base = (2 * base) + 1;
						node -= base;
					}
				}
				else {
					if (op[i] == 'L') {
						base = (2 * base) - 1;
						node -= base;
					}
					else {
						base *= 2;
						node -= base;
					}
				}
			}
		}
		cout << node << endl;
	}
	else {
		cout << node << endl;
	}
}