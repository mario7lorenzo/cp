#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int p;
		cin >> p;
		vector<int> pos;
		for (int j = 0; j < p; j++) {
			int x;
			cin >> x;
			pos.push_back(x);
		}
		sort(pos.begin(), pos.end());
		cout << 2*(pos[pos.size()-1] - pos[0]) << endl;
	}
}