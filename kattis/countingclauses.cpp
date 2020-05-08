#include <bits/stdc++.h>
using namespace std;

vector<bool> vb;
vector<vector<int>> clauses;
int m, n;

void increment() {
	int capt = 1e9;
	for (int i = n-1; i >= 0; i--) {
		if (!vb[i]) {
			capt = i;
			break;
		}
	}
	if (capt == 1e9) {

	} else {
		vb[capt] = true;
		for (int i = capt+1; i < m; i++) {
			vb[i] = false;
		}
	}
}

bool eval() {
	bool res = true;
	for (auto i : clauses) {
		bool ev = false;
		for (auto j : i) {
			if (j < 0) {
				ev = ev || !(vb[-(j)-1]);
			} else {
				ev = ev || vb[j-1];
			}
		}
		res = res && ev;
	}
	return res;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		vb.push_back(false);
	}
	for (int i = 0; i < m; i++) {
		vector<int> clause;
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			clause.push_back(x);
		}
		clauses.push_back(clause);
	}
	bool satisfied = false;
	for (int i = 0; i < pow(2, n)-1; i++) {
		if (satisfied) {
			break;
		}
		satisfied = satisfied || eval();
		increment();
	}
	satisfied = satisfied || eval();
	if (m >= 8) {
		cout << "satisfactory" << endl;
	} else {
		cout << "unsatisfactory" << endl;
	}
}