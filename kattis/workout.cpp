#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<long long> jimtot;
	vector<pair<long long, long long>> jim;
	for (int i = 0; i < 10; i++) {
		long long u, r;
		cin >> u >> r;
		jimtot.push_back(u+r);
		jim.emplace_back(u, r);
	}
	vector<pair<long long, long long>> otherstot;
	vector<pair<long long, long long>> others;
	for (int i = 0; i < 10; i++) {
		long long u, r, t;
		cin >> u >> r >> t;
		others.emplace_back(u, r);
		otherstot.emplace_back(t, u+r);
	}
	long long t = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (t >= otherstot[j].first) {
				if ((t - otherstot[j].first)%otherstot[j].second <= others[j].first) {
					t += others[j].first - (t - otherstot[j].first)%otherstot[j].second;
				}
				otherstot[j].first = t - (t - otherstot[j].first)%otherstot[j].second;
			}
			if (t + jim[j].first >= otherstot[j].first + otherstot[j].second) {
				otherstot[j].first = t + jim[j].first;
			}
			else if (t < otherstot[j].first && t + jim[j].first > otherstot[j].first) {
				otherstot[j].first = t + jim[j].first;
			}
			t += jimtot[j];
		}
	}
	cout << t-jim[9].second << endl;
}