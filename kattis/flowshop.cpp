#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		} 
	}
	for (int i = 1; i < m; i++) {
		arr[0][i] = arr[0][i-1] + arr[0][i];
	}
	for (int i = 1; i < n; i++) {
		arr[i][0] = arr[i-1][0] + arr[i][0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			arr[i][j] = arr[i][j-1] + arr[i][j];
			if (arr[i][j-1] < arr[i-1][j]) {
				arr[i][j] += arr[i-1][j] - arr[i][j-1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << arr[i][m-1];
		}
		else {
			cout << ' ' << arr[i][m-1];
		}
	}
	cout << endl;
}