#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	char arr[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char x;
			cin >> x;
			arr[i][j] = x;
		}
	}
	for (int i = 0; i < c; i++) {
		int apples = 0, pointer = 0;
		for (int j = 0; j < r; j++) {
			if (arr[j][i] == 'a') {
				apples++;
			}
			else if (arr[j][i] == '#') {
				int temp = j-1;
				while (apples > 0) {
					arr[temp][i] = 'a';
					temp--;
					apples--;
				}
				for (int k = pointer; k <= temp; k++) {
					arr[k][i] = '.';
				}
				pointer = j+1;
			}
		}
		if (apples != 0) {
			int temp = r-1;
			while (apples--) {
				arr[temp][i] = 'a';
				temp--;
			}
			while (pointer <= temp) {
				arr[pointer][i] = '.';
				pointer++;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}