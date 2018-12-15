#include <bits/stdc++.h>
using namespace std;

bool cuscom(pair<bool, int> x, pair<bool, int> y) {
	return x.second < y.second;
}

int main() {
	int a, b, c, aa, da, ab, db, ac, dc;
	cin >> a >> b >> c >> aa >> da >> ab >> db >> ac >> dc;
	vector<pair<bool, int>> events;
	events.emplace_back(true, aa);
	events.emplace_back(false, da);
	events.emplace_back(true, ab);
	events.emplace_back(false, db);
	events.emplace_back(true, ac);
	events.emplace_back(false, dc);
	sort(events.begin(), events.end(), cuscom);
	int t = 0, car = 0, cost = 0;
	for (int i = 0; i < events.size(); i++) {
		int currt = events[i].second;
		if (car == 1) {
			cost += (currt - t)*a;
		}
		if (car == 2) {
			cost += (currt - t)*(2*b);
		}
		if (car == 3) {
			cost += (currt - t) * (3*c);
		}
		if (events[i].first == true) {
			car++;
		}
		if (events[i].first == false) {
			car--;
		}
		t = currt;
	}
	cout << cost << endl;
}