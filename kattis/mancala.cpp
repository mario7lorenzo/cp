#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int k, n;
		cin >> k >> n;
		int j = 0;
		int board[1000];
		for (int i = 0; i < 1000; i++) {
			board[i] = 0;
		}
		while (n--) {
			for (int i = 1; i <= 1000; i++) {
				j = max(i, j);
				if (board[i] == 0) {
					board[i] = i;
					break;
				}
				else {
					board[i]--;
				}
			}
		}
		cout << k << ' ' << j << endl;
		for (int i = 1; i <= j; i++) {
			cout << board[i] << ' ';
			if (i%10 == 0 && i!=j) {
				cout << endl;
			}
		}
		cout << endl;
	}
}