#include <bits/stdc++.h>
using namespace std;

int main() {
	char grid[11][11];
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			grid[i][j] = 'x';
		}
	}
	for (int i = 2; i < 9; i++) {
		for (int j = 2; j < 9; j++) {
			if ((i < 4 && j < 4) || (i > 6 && j < 4) || (i < 4 && j > 6) || (i > 6 && j > 6)) {
				continue;
			}
			char x;
			cin >> x;
			grid[i][j] = x;
		}
	}
	int counter = 0;
	for (int i = 2; i < 9; i++) {
		for (int j = 2; j < 9; j++) {
			if (grid[i][j] == '.') {
				if (grid[i-1][j] == 'o' && grid[i-2][j] == 'o') {
					counter++;
				}
				if (grid[i+1][j] == 'o' && grid[i+2][j] == 'o') {
					counter++;
				}
				if (grid[i][j-1] == 'o' && grid[i][j-2] == 'o') {
					counter++;
				}
				if (grid[i][j+1] == 'o' && grid[i][j+2] == 'o') {
					counter++;
				}
			}
		}
	}
	cout << counter << endl;
}