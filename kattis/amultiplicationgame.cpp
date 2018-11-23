#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	while (getline(cin, n)) {
		bool turn = true;
		long long p = 1;
		while (p < stoll(n)) {
			if (turn) {
				p *= 9;
				// cout << "ini p skrg " << p << endl;
				turn = !turn;
			}
			else {
				p *= 2;
				// cout << "ini p skrg " << p << endl;
				turn = !turn;
			}
		}
		turn = !turn;
		if (turn) {
			cout << "Stan wins." << endl;
		}
		else {
			cout << "Ollie wins." << endl;
		}
	}
}