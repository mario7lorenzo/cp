#include<bits/stdc++.h>
using namespace std;

int main() {
	string record;
	cin >> record;
	int a = 0;
	int b = 0;

	int ptr = 0;
	bool firstrule = true;

	while (ptr < record.length()) {
		char winner = record[ptr];
		int point = record[ptr+1] - '0';

		if (winner == 'A') {
			a += point;
		} else {
			b += point;
		}

		if (a == 10 && b == 10) {
			firstrule = false;
		}

		if (firstrule) {
			if (a >= 11) {
				cout << "A" << endl;
				break;
			} else if (b >= 11) {
				cout << "B" << endl;
				break;
			}
		} else {
			if (abs(a-b) >= 2) {
				if (a < b) {
					cout << "B" << endl;
				} else {
					cout << "A" << endl;
				}

				break;
			}
		}

		ptr+=2;
	}
}