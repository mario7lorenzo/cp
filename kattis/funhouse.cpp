#include <bits/stdc++.h>
using namespace std;

int main() {
	int houses = 1, w, l;
	while (cin >> w >> l, (w != 0 && l != 0)) {
		char arr[l][w];
		int xmasuk, ymasuk;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w; j++) {
				char t;
				cin >> t;
				if (t == '*') {
					xmasuk = j;
					ymasuk = i;
				}
				arr[i][j] = t;
			}
		}
		int dir;
		if (xmasuk == 0) {
			xmasuk++;
			dir = 0;
		}
		else if (xmasuk == w-1) {
			xmasuk--;
			dir = 2;
		}
		else if (ymasuk == 0) {
			ymasuk++;
			dir = 3;
		}
		else if (ymasuk == l-1) {
			ymasuk--;
			dir = 1;
		}
		while (arr[ymasuk][xmasuk] != 'x') {
			if (arr[ymasuk][xmasuk] == '.') {
				if (dir == 0) {
					xmasuk++;
				}
				else if (dir == 1) {
					ymasuk--;
				}
				else if (dir == 2) {
					xmasuk--;
				}
				else if (dir == 3) {
					ymasuk++;
				} 
			}
			else if (arr[ymasuk][xmasuk] == '/') {
				if (dir == 0) {
					dir = 1;
					ymasuk--;
				}
				else if (dir == 1) {
					dir = 0;
					xmasuk++;
				}
				else if (dir == 2) {
					dir = 3;
					ymasuk++;
				}
				else if (dir == 3) {
					dir = 2;
					xmasuk--;
				}
			}
			else if (arr[ymasuk][xmasuk] == '\\') {
				if (dir == 0) {
					dir = 3;
					ymasuk++;
				}
				else if (dir == 1) {
					dir = 2;
					xmasuk--;
				}
				else if (dir == 2) {
					dir = 1;
					ymasuk--;
				}
				else if (dir == 3) {
					dir = 0;
					xmasuk++;
				}
			}
		}
		arr[ymasuk][xmasuk] = '&';
		cout << "HOUSE " << houses << endl;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < w; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
		houses++;
 	}
}