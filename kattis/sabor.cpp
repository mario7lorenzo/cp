#include <bits/stdc++.h>
using namespace std;

int main() {
	int mp;
	cin >> mp;
	vector<vector<int>> argue(mp);
	string party = "";
	for (int i = 0; i < 5; i++) {
		int p;
		cin >> p;
		for (int i = 0; i < p; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			argue[a].push_back(b);
			argue[b].push_back(a);
		}
	}
	queue<int> q;
	for (int i = 0; i < mp; i++) {
		if (i%2 == 1) {
			party += 'B';
		}
		else {
			party += 'A';
		}
	}
	for (int i = 0; i < mp; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		int sim = 0;
		for (auto i : argue[curr]) {
			if (party[curr] == party[i]) {
				sim++;
			}
		}
		if (sim > 2) {
			if (party[curr] == 'A') {
				party[curr] = 'B';
			}
			else {
				party[curr] = 'A';
			}
			for (auto i : argue[curr]) {
				q.push(i);
			}
		}
	}
	cout << party << endl;
}