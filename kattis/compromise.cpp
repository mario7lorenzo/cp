#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		char arr[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char x;
				cin >> x;
				arr[i][j] = x;
			}
		}
		for (int i = 0; i < m; i++) {
			int nol = 0, satu = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j][i] == '0') {
					nol++;
				}
				else {
					satu++;
				}
			}
			if (nol > satu) {
				cout << 0;
			}
			else {
				cout << 1;
			}
		}
		cout << endl;
	}
}