#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases = 1;
	int n;

	while (cin >> n) {
		cout << "Case " << cases << ":" << endl;
		vector<int> vec;

		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			vec.push_back(k);
		}

		vector<int> sums;

		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				if (vec[i] != vec[j]) {
					sums.push_back(vec[i] + vec[j]);
				}
			}
		}

		// sort(sums.begin(), sums.end());

		int queries;
		cin >> queries;

		for (int i = 0; i < queries; i++) {
			int target;
			cin >> target;
			int closest = sums[0];
			for (int i = 1; i < sums.size(); i++) {
				if (abs(sums[i] - target) < abs(closest - target)) {
					closest = sums[i];
				}
			}

			cout << "Closest sum to " << target << " is " << closest << "." << endl;
		}
		

		cases += 1;
	}
}