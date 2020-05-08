#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<int, priority_queue<int>> umap;
	int c;
	cin >> c;
	set<int> s;
	while (c--) {
		string st;
		cin >> st;
		if (st == "add") {
			int e, g;
			cin >> e >> g;
			umap[e].push(g);
			s.insert(e);
		} else {
			int x;
			cin >> x;
			long long gold = 0;
			bool change = true;
			while (change) {
				if (x < *(s.begin()) || s.empty()) {
					cout << gold << endl;
					break;
				} else {
					int c;
					set<int>::iterator i = s.lower_bound(x);
					c = *i;
					if (x != c) {
						c = *(prev(i));
					}
					priority_queue<int> temp = umap[c];
					while (!umap[c].empty() && x >= c) {
						int num = umap[c].top();
						umap[c].pop();
						x -= c;
						gold += num;
					}
					if (umap[c].empty()) {
						s.erase(c);
					}
				}
			}
		}
	}
}