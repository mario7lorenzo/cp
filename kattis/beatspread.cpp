#include <bits/stdc++.h>
using namespace std;

pair<bool, pair<int, int> > scorecount(int s, int d) {
	int x = (s+d)/2;
	int y = s-x;
	if ((s+d)%2==0 && x >= 0 && y >= 0) {
		return make_pair(true, make_pair(max(x, y), min(x, y)));
	} else {
		return make_pair(false, make_pair(0, 0));
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int s, d;
		cin >> s >> d;
		pair<bool, pair<int, int> > scores = scorecount(s, d);
		if (scores.first) {
			cout << scores.second.first << ' ' << scores.second.second << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
}