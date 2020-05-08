#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	unordered_map<int, vector<int>> lst;
	unordered_set<int> pos;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		int d, r, g;
		cin >> d >> r >> g;
		pos.insert(d);
		temp.push_back(r);
		temp.push_back(g);
		lst[d] = temp;
	}
	int curr = 0;
	int durr = 0;
	while (curr < l) {
		if (pos.find(curr) != pos.end()) {
			if (durr%(lst[curr][0]+lst[curr][1]) < lst[curr][0]) {
				durr += lst[curr][0] - durr%(lst[curr][0]+lst[curr][1]);
			}
		}
		curr++;
		durr++;
	}
	cout << durr << endl;
}