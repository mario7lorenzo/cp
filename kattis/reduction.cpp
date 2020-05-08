#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	for (int i = 1; i <= tc; i++) {
		int n, m, l;
		cin >> n >> m >> l;
		unordered_map<string, pair<int, int>> umap;
		while (l--) {
			string x;
			cin >> x;
			bool name = true;
			string name = "";
			string num = "";
			int a, b;
			for (auto k : x) {
				if (k == ':') {
					name = false;
				} else if (k == ',') {
					a = stoi(num);
					num = "";
				} else if (name) {
					name += k;
				} else {
					num += k;
				}
			}
			b = stoi(num);
			umap[name] = make_pair(a, b);
		}
		
	}
}