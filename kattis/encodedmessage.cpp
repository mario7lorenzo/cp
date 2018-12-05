#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		string p;
		cin >> p;
		int sz = pow(p.length(), 0.5);
		char grids[sz][sz];
		int ind = 0;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				grids[i][j] = p[ind];
				ind++;
			}
		}
		for (int i = sz-1; i >= 0; i--) {
			for (int j = 0; j < sz; j++) {
				cout << grids[j][i];
			}
		}
		cout << endl;
	}
}