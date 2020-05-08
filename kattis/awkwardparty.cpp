#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<int, pair<int, int>> umap;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (umap.find(c) == umap.end()) {
			umap[c] = make_pair(1e9, i);
		}
		else {
			pair<int, int> temp = umap[c];
			umap[c] = make_pair(min(temp.first, i-temp.second), i);
		}
	}
	int level = 1e9;
	unordered_map<int, pair<int, int>>::iterator itr;
	for (itr = umap.begin(); itr != umap.end(); itr++) {
		pair<int, int> temp = itr->second;
		if (temp.first != 1e9) {
			level = min(level, temp.first);
		}
	}
	if (level == 1e9) {
		cout << n << endl;
	}
	else {
		cout << level << endl;
	}
}