#include <bits/stdc++.h>
using namespace std;

int main() {
	string mon;
	cin >> mon;
	int i = 0;
	while (i < mon.length()) {
		if (i >= mon.length()-2) {
			if (mon[i] == 'R') {
				cout << 'S';
			}
			if (mon[i] == 'B') {
				cout << 'K';
			}
			if (mon[i] == 'L') {
				cout << 'H';
			}
			i++;
		}
		else {
			if (mon.substr(i, 3) == "RBL" || mon.substr(i, 3) == "RLB" || mon.substr(i, 3) == "BLR" || mon.substr(i, 3) == "BRL" || mon.substr(i, 3) == "LRB" || mon.substr(i, 3) == "LBR") {
				cout << "C";
				i += 3;
			}
			else {
				if (mon[i] == 'R') {
					cout << 'S';
				}
				if (mon[i] == 'B') {
					cout << 'K';
				}
				if (mon[i] == 'L') {
					cout << 'H';
				}
				i++;
			}
		}
	}
	cout << endl;
}