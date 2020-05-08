#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		string let;
		cin >> let;
		int l = let.length();
		int m = pow(l, 0.5);
		if (pow(m, 2) < l) {
			m++;
		}
		char letter[m][m];
		int counter = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (counter > let.length()-1) {
					letter[i][j] = '*';
				}
				else {
					letter[i][j] = let[counter];
				}
				counter++;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = m-1; j >= 0; j--) {
				if (letter[j][i] != '*') {
					cout << letter[j][i];
				}
			}
		}
		cout << endl;
	}
}