#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, pair<int, int>> shouldbe, actual;
	int piv = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 3 && j == 3) {
				shouldbe['.'] = make_pair(i, j);
			}
			else {				
				shouldbe[char(65+piv)] = make_pair(i, j);
				piv++;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char x;
			cin >> x;
			actual[x] = make_pair(i, j);
		}
	}
	int diff = 0;
	for (int i = 0; i < 16; i++) {
		if (i != 15) {
			diff += abs(shouldbe[char(65+i)].first-actual[char(65+i)].first) + abs(shouldbe[char(65+i)].second-actual[char(65+i)].second);
		}
	}
	cout << diff << endl;
}