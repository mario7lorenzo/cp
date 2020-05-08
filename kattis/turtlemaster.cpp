#include <bits/stdc++.h>
using namespace std;

int main() {
	char grids[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			grids[i][j] = 'X';
		}
	}
	int x,y;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			char temp;
			cin >> temp;
			if (temp == 'T') {
				x = i;
				y = j;
				grids[i][j] = '.';
			}
			else {
				grids[i][j] = temp;
			}
		}
	}
	bool eror = false;
	char op;
	int dir = 0;
	while (cin >> op) {
		if (op == 'F') {
			if (dir == 0) {
				if (grids[x][y+1] != '.' && grids[x][y+1] != 'D') {
					eror = true;
					break;
				}
				else {
					y++;
				}
			}
			else if (dir == 1) {
				if (grids[x+1][y] != '.' && grids[x+1][y] != 'D') {
					eror = true;
					break;
				}
				else {
					x++;
				}
			}
			else if (dir == 2) {
				if (grids[x][y-1] != '.' && grids[x][y-1] != 'D') {
					eror = true;
					break;
				}
				else {
					y--;
				}
			}
			else if (dir == 3) {
				if (grids[x-1][y] != '.' && grids[x-1][y] != 'D') {
					eror = true;
					break;
				}
				else {
					x--;
				}
			}
		}
		else if (op == 'R') {
			dir = (dir+1)%4;
		}
		else if (op == 'L') {
			if (dir == 0) {
				dir = 3;
			}
			else {
				dir--;
			}
		}
		else if (op == 'X') {
			if (dir == 0) {
				if (grids[x][y+1] == 'I') {
					grids[x][y+1] = '.';
				}
				else {
					eror = true;
					break;
				}
			}
			else if (dir == 1) {
				if (grids[x+1][y] == 'I') {
					grids[x+1][y] = '.';
				}
				else {
					eror = true;
					break;
				}
			}
			else if (dir == 2) {
				if (grids[x][y-1] == 'I') {
					grids[x][y-1] = '.';
				}
				else {
					eror = true;
					break;
				}
			}
			else if (dir == 3) {
				if (grids[x-1][y] == 'I') {
					grids[x-1][y] = '.';
				}
				else {
					eror = true;
					break;
				}
			}			
		}
	}
	if (eror || grids[x][y] != 'D') {
		cout << "Bug!" << endl;
	}
	else {
		cout << "Diamond!" << endl;
	}
}