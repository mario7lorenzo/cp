#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int w, h, n;
		cin >> w >> h >> n;
		vector<vector<char>> grid1, grid2;
		int ship1 = 0, ship2 = 0;
		for (int j = 0; j < h; j++) {
			vector<char> temp;
			for (int k = 0; k < w; k++) {
				char cond;
				cin >> cond;
				if (cond == '#') {
					ship1++;
				}
				temp.push_back(cond);
			}
			grid1.push_back(temp);
		}
		for (int j = 0; j < h; j++) {
			vector<char> temp;
			for (int k = 0; k < w; k++) {
				char cond;
				cin >> cond;
				if (cond == '#') {
					ship2++;
				}
				temp.push_back(cond);
			}
			grid2.push_back(temp);
		}
		reverse(grid1.begin(), grid1.end());
		reverse(grid2.begin(), grid2.end());
		bool turn = true;
		bool end = false;
		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			if (end) {
				continue;
			}
			if (turn) {
				if (grid2[y][x] == '#') {
					ship2--;
					grid2[y][x] = '_';
					if (ship2 == 0) {
						turn = !turn;
					}
				}
				else {
					turn = !turn;
				}
			}
			else {
				if (grid1[y][x] == '#') {
					ship1--;
					grid1[y][x] = '_';
					if (ship1 == 0) {
						end = true;
						turn = !turn;
					}
				}
				else {
					turn = !turn;
				}
			}
		}
		// cout << "ini ship 1 " << ship1 << endl;
		// cout << "ini ship 2 " << ship2 << endl;
		if ((ship1 == 0 && ship2 == 0) | (ship1 > 0 && ship2 > 0)) {
			cout << "draw" << endl;
		}
		else if (ship1 == 0 && ship2 > 0) {
			cout << "player two wins" << endl;
		}
		else if (ship2 == 0 && ship1 > 0) {
			cout << "player one wins" << endl;
		}
	}
}