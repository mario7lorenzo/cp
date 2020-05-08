#include <bits/stdc++.h>
using namespace std;

int main() {
	// cout << "tes" << endl;
	int g, s;
	vector<vector<int>> grid;
	for (int i = 0; i < 10010; i++) {
		vector<int> tmp;
		for (int j = 0; j < 10010; j++) {
			tmp.push_back(0);
		}
		grid.push_back(tmp);
	}
	cin >> g;
	vector<pair<pair<int, int>, int>> vec;
	for (int i = 0; i < g; i++) {
		int x, y;
		cin >> x >> y;
		grid[x][y]++;
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		vec.emplace_back(make_pair(x, y), r);
	}
	int killed = 0;
	for (int i = 0; i < s; i++) {
		int x = vec[i].first.first, y = vec[i].first.second, r = vec[i].second;
		for (int j = x-r; j <= x+r; j++) {
			for (int k = y-r; k <= y+r; k++) {
				if (j >= 0 && k >= 0 && j <= 10000 && k <= 10000) {
					if (((j - x) * (j - x)) + ((k - y) * (k - y)) <= r * r) {
						killed += grid[j][k];
						grid[j][k] = 0;
					}
				}
			}
		}
	}
	cout << g - killed << endl;
}