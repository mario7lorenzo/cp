#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<long long> vi;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		vi.push_back(x);
	}

	if (t == 1) {
		cout << 7 << endl;
	} else if (t == 2) {
		if (vi[0] < vi[1]) {
			cout << "Smaller" << endl;
		} else if (vi[0] > vi[1]) {
			cout << "Bigger" << endl;
		} else {
			cout << "Equal" << endl;
		}
	} else if (t == 3) {
		vector<long long> subv;
		for (int i = 0; i < 3; i++) {
			subv.push_back(vi[i]);
		}
		sort(subv.begin(), subv.end());
		cout << subv[1] << endl;
	} else if (t == 4) {
		long long counter = 0;
		for (int i = 0; i < n; i++) {
			counter += vi[i];
		}
		cout << counter << endl;
	} else if (t == 5) {
		long long counter = 0;
		for (int i = 0; i < n; i++) {
			if (vi[i]%2 == 0) {
				counter += vi[i];
			}
		}
		cout << counter << endl;
	} else if (t == 6) {
		for (int i = 0; i < n; i++) {
			char c = char(vi[i]%26 + 97);
			cout << c;
		}
		cout << endl; 
	} else if (t == 7) {
		long long curr = 0;
		string stat;
		unordered_set<long long> uset;

		while (true) {
			curr = vi[curr];
			if (curr >= n) {
				stat = "Out";
				break;
			} else if (curr == n - 1) {
				stat = "Done";
				break;
			} else if (uset.find(curr) != uset.end()) {
				stat = "Cyclic";
				break;
			}
			uset.insert(curr);
		}

		cout << stat << endl;
	}
}