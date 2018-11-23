#include <bits/stdc++.h>
using namespace std;

int main() {
	int command;
	bool isfirst = true;
	while (cin >> command, command) {
		if (isfirst) {
			isfirst = false;
		}
		else {
			cout << endl;
		}
		int a = 0;
		int b = 0;
		for (int i = 0; i < command; i++) {
			string act;
			cin >> act;
			int plate;
			cin >> plate;
			if (act == "DROP") {
				b += plate;
				cout << "DROP 2 " << plate << endl;
			}
			else if (act == "TAKE") {
				if (a < plate) {
					if (a != 0) {
						cout << "TAKE 1 " << a << endl;
						plate -= a;
						a = 0;
					}
					cout << "MOVE 2->1 " << b << endl;
					a = b-plate;
					b = 0;
					cout << "TAKE 1 " << plate << endl;
				}
				else {
					cout << "TAKE 1 " << plate << endl;
					a -= plate;
				}
			}
		}
	}
}