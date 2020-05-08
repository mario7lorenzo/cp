#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> fac;

void factor(int x) {
	for (int i = 1; i <= x; i++) {
		if (x%i == 0) {
			if (i <= x/i) {
				fac.emplace_back(i, x/i);
			}
		}
	}
}

int main() {
	string dec;
	cin >> dec;
	int pjg = dec.length();
	factor(pjg);
	pair<int, int> pasang = fac[fac.size()-1];
	int r = pasang.first;
	int c = pasang.second;
	char grids[r][c];
	int ind = 0;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			grids[j][i] = dec[ind];
			ind++;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << grids[i][j];
		}
	}
	cout << endl;
}