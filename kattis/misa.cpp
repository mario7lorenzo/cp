#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, s;
	cin >> r >> s;
	char grid[r+2][s+2];
	for (int i = 0; i < r+2; i++) {
		for (int j = 0; j < s+2; j++) {
			grid[i][j] = 'x';
		}
	}
	queue<pair<int, int>> q;
	int emp = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= s; j++) {
			char c;
			cin >> c;
			grid[i][j] = c;
			if (c == '.') {
				emp++;
			}
		}
	}
	int tot = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= s; j++) {
			if (grid[i][j] == 'o') {
				if (grid[i][j+1] == 'o') {
					tot++;
				}
				if (grid[i+1][j] == 'o') {
					tot++;
				}
				if (grid[i+1][j+1] == 'o') {
					tot++;
				}
				if (grid[i+1][j-1] == 'o') {
					tot++;
				}
			}
			else {
				q.push(make_pair(i, j));
			}
		}
	}
	int maxi = tot;
	while (!q.empty()) {
		int tmp = tot;
		pair<int, int> coor = q.front();
		q.pop();
		int x = coor.first, y = coor.second;
		if (grid[x][y+1] == 'o') {
			tmp++;
		}
		if (grid[x][y-1] == 'o') {
			tmp++;
		}
		if (grid[x+1][y+1] == 'o') {
			tmp++;
		}
		if (grid[x+1][y-1] == 'o') {
			tmp++;
		}
		if (grid[x-1][y+1] == 'o') {
			tmp++;
		}
		if (grid[x-1][y-1] == 'o') {
			tmp++;
		}
		if (grid[x+1][y] == 'o') {
			tmp++;
		}
		if (grid[x-1][y] == 'o') {
			tmp++;
		}
		maxi = max(tmp, maxi);
	}
	cout << maxi << endl;
}