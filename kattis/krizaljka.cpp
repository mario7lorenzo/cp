#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	unordered_set<char> temp;
	for (int i = 0; i < b.length(); i++) {
		temp.insert(b[i]);
	}
	int inda, indb;
	for (int i = 0; i < a.length(); i++) {
		if (temp.find(a[i]) != temp.end()) {
			inda = i;
			break;
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == a[inda]) {
			indb = i;
			break;
		}
	}
	char grids[b.length()][a.length()];
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			grids[i][j] = '.';
		}
	}
	for (int i = 0; i < b.length(); i++) {
		grids[i][inda] = b[i];
	}
	for (int i = 0; i < a.length(); i++) {
		grids[indb][i] = a[i];
	}
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			cout << grids[i][j];
		}
		cout << endl;
	}
}