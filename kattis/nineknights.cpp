#include <bits/stdc++.h>
using namespace std;

int main() {
	bool grids[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			grids[i][j] = false;
		}
	} 
	int counter = 0;
	for (int i = 2; i < 7; i++) {
		for (int j = 2; j < 7; j++) {
			char temp;
			cin >> temp;
			if (temp == '.') {
				grids[i][j] = false;
			}
			else {
				counter++;
				grids[i][j] = true;
			}
		}
	}
	if (counter != 9) {
		cout << "invalid" << endl;
	}
	else {
		bool valid = true;
		for (int i = 2; i < 7; i++) {
			for (int j = 2; j < 7; j++) {
				if (grids[i][j]) {
					if (grids[i-2][j-1]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i-2][j+1]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i-1][j-2]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i-1][j+2]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i+1][j-2]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i+1][j+2]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i+2][j-1]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
					if (grids[i+2][j+1]) {
						cout << "invalid" << endl;
						valid = false;
						break;
					}
				}
			}
			if (!valid) {
				break;
			} 
		}
		if (valid) {
			cout << "valid" << endl;
		}
	}
}