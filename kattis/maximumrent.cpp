#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, m, d;
	cin >> a >> b >> m >> d;
	vector<pair<long long, long long>> coor;
	coor.emplace_back(d - m, (2*m)-d);
	coor.emplace_back(1, m-1);
	coor.emplace_back(1, d-2);
	coor.emplace_back(m-1, 1);
	coor.emplace_back(((d-1)/2), 1);
	long long maxi = -1e9;
	for (int i = 0; i < coor.size(); i++) {
		if ((coor[i].first >= 1) && (coor[i].second >= 1) && (coor[i].first + coor[i].second <= m) && ((2*coor[i].first) + coor[i].second >= d)) {
			maxi = max(maxi, ((a*coor[i].first) + (b*coor[i].second)));
		}
	}
	cout << maxi << endl;
}