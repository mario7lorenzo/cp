#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, m;
	while (cin >> k, k != 0) {
		cin >> m;
		bool verify = true;
		unordered_set<string> taken;
		for (int i = 0; i < k; i++) {
			string mods;
			cin >> mods;
			taken.insert(mods);
		}
		for (int i = 0; i < m; i++) {
			int r, c;
			cin >> r >> c;
			int satisfy = 0;
			for (int i = 0; i < r; i++) {
				string mods;
				cin >> mods;
				if (taken.find(mods) != taken.end()) {
					satisfy++;
				}
			}
			if (satisfy < c) {
				verify = false;
			}
		}
		if (verify) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}