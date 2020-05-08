#include <bits/stdc++.h>
using namespace std;
bool verifier(vector<int> x) {
	bool verify = true;
	for (int i = 2; i < x.size(); i++) {
		if (x[i-1] - x[i] != x[i-2]-x[i-1]) {
			verify = false;
			return verify;
		}
	}
	return verify;
}

int main() {
	int total;
	cin >> total;
	for (int i = 0; i < total; i++) {
		int n;
		cin >> n;
		vector<int> seq;
		for (int j = 0; j < n; j++) {
			int sem;
			cin >> sem;
			seq.push_back(sem);
		}

		if (verifier(seq)) {
			cout << "arithmetic" << endl;
		}
		else {
			stable_sort(seq.begin(), seq.end());
			if (verifier(seq)) {
				cout << "permuted arithmetic" << endl;
			}
			else {
				cout << "non-arithmetic" << endl;
			}
		}
	}
}