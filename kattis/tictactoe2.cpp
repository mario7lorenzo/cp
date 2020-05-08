#include <bits/stdc++.h>
using namespace std;

bool solver(int x, int o, int streakx, int streako) {
	if (streakx && streako) {
		return false;
	}
	else if (x < o) {
		return false;
	}
	else if (x - o > 1) {
		return false;
	}
	else if (streako) {
		if (x > o) {
			return false;
		}
	}
	else if (streakx) {
		if (x == o) {
			return false;
		}
	}
	return true;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int x = 0, o = 0, streakx = 0, streako = 0;
		char grid[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char p;
				cin >> p;
				grid[i][j] = p;
				if (p == 'X') {
					x++;
				} 
				else if (p == 'O') {
					o++;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '.') {
				if (grid[i][0] == 'X') {
					streakx++;
				}
				else {
					streako++;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '.') {
				if (grid[0][i] == 'X') {
					streakx++;
				}
				else {
					streako++;
				}
			}
		}
		if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '.') {
			if (grid[0][0] == 'X') {
				streakx++;
			}
			else {
				streako++;
			}
		}
		bool can = solver(x, o, streakx, streako);
		if (can) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}