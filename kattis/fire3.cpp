#include <bits/stdc++.h>
using namespace std;



int main() {
	int r, c;
	cin >> r >> c;
	char arr[r][c];
	int arr1[r][c];
	int arr2[r][c];
	int x, y;
	queue<pair<int, int> > jp, vp; 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				y = i;
				x = j;
				arr1[i][j] = 2e9;
				arr2[i][j] = 0;
			} else if (arr[i][j] == '#') {
				arr1[i][j] = -2;
				arr2[i][j] = -2;
			} else if (arr[i][j] == 'F') {
				arr1[i][j] = 0;
				arr2[i][j] = 1e9;
				vp.push(make_pair(i, j));
			} else {
				arr1[i][j] = 1e9;
				arr2[i][j] = 1e9;
			}
		}
	}
	jp.push(make_pair(y, x));
	while (!vp.empty()) {
		pair<int, int> coor = vp.front();
		vp.pop();
		int a = coor.first, b = coor.second;
		if (arr1[a-1][b] > arr1[a][b]+1 && arr1[a-1][b] != 2e9 && arr1[a-1][b] != -2 && a-1 >= 0 && a-1 < r && b >= 0 && b < c) {
			arr1[a-1][b] = arr1[a][b]+1;
			vp.push(make_pair(a-1, b));
		}
		if (arr1[a+1][b] > arr1[a][b]+1 && arr1[a+1][b] != 2e9 && arr1[a+1][b] != -2&& a+1 >= 0 && a+1 < r && b >= 0 && b < c) {
			arr1[a+1][b] = arr1[a][b]+1;
			vp.push(make_pair(a+1, b));
		}
		if (arr1[a][b-1] > arr1[a][b]+1 && arr1[a][b-1] != 2e9 && arr1[a][b-1] != -2&& a >= 0 && a < r && b-1 >= 0 && b-1 < c) {
			arr1[a][b-1] = arr1[a][b]+1;
			vp.push(make_pair(a, b-1));
		}
		if (arr1[a][b+1] > arr1[a][b]+1 && arr1[a][b+1] != 2e9 && arr1[a][b+1] != -2&& a >= 0 && a < r && b+1 >= 0 && b+1 < c) {
			arr1[a][b+1] = arr1[a][b]+1;
			vp.push(make_pair(a, b+1));
		}
	}
	while (!jp.empty()) {
		pair<int, int> coor = jp.front();
		jp.pop();
		int a = coor.first, b = coor.second;
		if (arr2[a-1][b] > arr2[a][b]+1 && arr2[a-1][b] != -1 && arr2[a-1][b] != -2&& a-1 >= 0 && a-1 < r && b >= 0 && b < c) {
			arr2[a-1][b] = arr2[a][b]+1;
			jp.push(make_pair(a-1, b));
		}
		if (arr2[a+1][b] > arr2[a][b]+1 && arr2[a+1][b] != -1 && arr2[a+1][b] != -2&& a+1 >= 0 && a+1 < r && b >= 0 && b < c) {
			arr2[a+1][b] = arr2[a][b]+1;
			jp.push(make_pair(a+1, b));
		}
		if (arr2[a][b-1] > arr2[a][b]+1 && arr2[a][b-1] != -1 && arr2[a][b-1] != -2&& a >= 0 && a < r && b-1 >= 0 && b-1 < c) {
			arr2[a][b-1] = arr2[a][b]+1;
			jp.push(make_pair(a, b-1));
		}
		if (arr2[a][b+1] > arr2[a][b]+1 && arr2[a][b+1] != -1 && arr2[a][b+1] != -2&& a >= 0 && a < r && b+1 >= 0 && b+1 < c) {
			arr2[a][b+1] = arr2[a][b]+1;
			jp.push(make_pair(a, b+1));
		}
	}
	// for (int i = 0; i < r; i++) {
	// 	for (int j = 0; j < c; j++) {
	// 		cout << arr1[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// for (int i = 0; i < r; i++) {
	// 	for (int j = 0; j < c; j++) {
	// 		cout << arr2[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	int ans = 1e9;
	for (int i = 0; i < r; i++) {
		if (arr1[i][0] != -2 && arr1[i][0] > arr2[i][0] && ans > arr2[i][0]) {
			ans = arr2[i][0];
		}
	}
	for (int i = 0; i < r; i++) {
		if (arr1[i][c-1] != -2 && arr1[i][c-1] > arr2[i][c-1] && ans > arr2[i][c-1]) {
			ans = arr2[i][c-1];
		}
	}
	for (int i = 0; i < c; i++) {
		if (arr1[0][i] != -2 && arr1[0][i] > arr2[0][i] && ans > arr2[0][i]) {
			ans = arr2[0][i];
		}
	}
	for (int i = 0; i < c; i++) {
		if (arr1[r-1][i] != -2 && arr1[r-1][i] > arr2[r-1][i] && ans > arr2[r-1][i]) {
			ans = arr2[r-1][i];
		}
	}
	if (ans == 1e9) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << ans+1 << endl;
	}
}