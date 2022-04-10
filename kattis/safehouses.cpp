#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
	int n;
	cin >> n;

	vector<pii> spies;
	vector<pii> houses;

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;

		for (int j = 0; j < n; j++) {
			if (row[j] == 'H') {
				houses.push_back({i,j});
			} else if (row[j] == 'S') {
				spies.push_back({i,j});
			}
		}
	}

	vector<int> distances;

	for (pii spy :spies) {
		int mini = abs(houses[0].first - spy.first) + abs(houses[0].second - spy.second);

		for (pii house: houses) {
			int dist = abs(house.first - spy.first) + abs(house.second - spy.second);
			mini = min(mini, dist);
		}

		distances.push_back(mini);
	}

	cout << *max_element(distances.begin(), distances.end()) << endl;
}