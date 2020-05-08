#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c, n;
	cin >> r >> c >> n;
	int arr[r+2][c+2];
	for (int i = 0; i < r+2; i++) {
		for (int j = 0; j < c+2; j++) {
			arr[i][j] = -1;
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			arr[i][j] = 1;
		}
	}
	int conq = 0, days = 1;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (arr[x][y] == 1) {
			arr[x][y] = 0;
			conq++;
		}
	}
	while (conq < r*c) {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (arr[i][j] == 0) {
					if (arr[i-1][j] == 1) {
						arr[i-1][j] = 2;
						conq++;
					}
					if (arr[i][j-1] == 1) {
						arr[i][j-1] = 2;
						conq++;
					}
					if (arr[i+1][j] == 1) {
						arr[i+1][j] = 2;
						conq++;
					}
					if (arr[i][j+1] == 1) {
						arr[i][j+1] = 2;
						conq++;
					}
					arr[i][j] = 5;
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (arr[i][j] == 2) {
					arr[i][j] = 0;
				}
			}
		}
		days++;
	}
	cout << days << endl;
}