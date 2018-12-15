#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> dur, quiet;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		dur.push_back(t);
	}
	for (int i = 0; i < m; i++) {
		int l;
		cin >> l;
		quiet.push_back(l);
	}
	sort(dur.begin(), dur.end());
	sort(quiet.begin(), quiet.end());
	int solved = 0;
	int ind = 0;
	for (int i = 0; i < dur.size(); i++) {
		bool solve = false;
		while (!solve) {
			if (ind >= quiet.size()) {
				break;
			}
			if (quiet[ind] >= dur[i]) {
				ind++;
				solve = true;
				solved++;
				break;
			}
			else {
				ind++;
			}
		}
	}
	cout << solved << endl;
}