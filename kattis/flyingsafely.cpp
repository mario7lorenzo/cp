#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> asal;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			asal.emplace_back(a, b);
		}
		cout << n-1 << endl;
	}
}