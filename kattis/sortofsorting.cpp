#include <bits/stdc++.h>
using namespace std;
bool verifier(string a, string b) {
	if (a[0] != b[0]) {
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int main() {
	int p;
	string m;
	bool is_first = true;
	while (cin >> p) {
		if (p == 0) {
			break;
		}
		if (is_first) {
			is_first = false;
		}
		else {
			cout << endl;
		}
		vector<string> lst;
		for (int i = 0; i < p; i++) {
			cin >> m;
			lst.push_back(m);
		}
		stable_sort(lst.begin(), lst.end(), verifier);
		int length = lst.size();
		for (int i = 0; i < length; i++) {
			cout << lst[i] << endl;
		}
	}
}