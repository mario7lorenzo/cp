#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	int cases = 1;
	while (tc--) {
		cout << "Case #" << cases << ':' << endl;
		bool alr = false;
		unordered_map<int, vector<int>> saver;
		unordered_map<int, int> mapper;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mapper[i] = x;
		}
		for (int i = 1; i < pow(2, n); i++) {
			bitset<20> bs(i);
			// cout << bs << endl;
			vector<int> vi;
			int counter = 0;
			for (int j = 0; j < 20; j++) {
				if (bs[j]) {
					counter += mapper[j];
					vi.push_back(mapper[j]);
				}
			}
			if (saver.find(counter) == saver.end()) {
				saver[counter] = vi;
			}
			else {
				alr = true;
				vector<int> former = saver[counter];
				for (auto i : former) {
					cout << i << ' ';
				}
				cout << endl;
				for (auto i : vi) {
					cout << i << ' ';
				}
				cout << endl;
				break;
			}
		}
		if (!alr) {
			cout << "impossible" << endl;
		}
		cases++;
	}
}