#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	char grid[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char x;
			cin >> x;
			grid[i][j] = x;
		}
	}
	int squashzero = 0, squashone = 0, squashtwo = 0, squashthree = 0, squashfour = 0;
	pair<int, int> coor1 = make_pair(0, 0);
	pair<int, int> coor2 = make_pair(0, 1);
	pair<int, int> coor3 = make_pair(1, 0);
	pair<int, int> coor4 = make_pair(1, 1);
	while (coor3.first < r) {
		if (grid[coor1.first][coor1.second] != '#' && grid[coor2.first][coor2.second] != '#' && grid[coor3.first][coor3.second] != '#' && grid[coor4.first][coor4.second] != '#') {
			int squashed = 0;
			if (grid[coor1.first][coor1.second] == 'X') {
				squashed++;
			}
			if (grid[coor2.first][coor2.second] == 'X') {
				squashed++;
			}
			if (grid[coor3.first][coor3.second] == 'X') {
				squashed++;
			}
			if (grid[coor4.first][coor4.second] == 'X') {
				squashed++;
			}
			if (squashed == 0) {
				squashzero++;
			}
			if (squashed == 1) {
				squashone++;
			}
			if (squashed == 2) {
				squashtwo++;
			}
			if (squashed == 3) {
				squashthree++;
			}
			if (squashed == 4) {
				squashfour++;
			}
		}
		if (coor2.second+1 == c) {
			coor1 = make_pair(coor1.first+1, 0);
			coor2 = make_pair(coor2.first+1, 1);
			coor3 = make_pair(coor3.first+1, 0);
			coor4 = make_pair(coor4.first+1, 1);
		}
		else {	
			coor1 = make_pair(coor1.first, coor1.second+1);
			coor2 = make_pair(coor2.first, coor2.second+1);
			coor3 = make_pair(coor3.first, coor3.second+1);
			coor4 = make_pair(coor4.first, coor4.second+1);
		}
	}
	cout << squashzero << endl;
	cout << squashone << endl;
	cout << squashtwo << endl;
	cout << squashthree << endl;
	cout << squashfour << endl;
}