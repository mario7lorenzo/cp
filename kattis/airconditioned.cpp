#include <bits/stdc++.h>
using namespace std;

bool cuscom(pair<int, int> x, pair<int, int> y) {
	return (x.second < y.second);
}
int main() {
	int minion;
	cin >> minion;
	vector<pair<int, int>> lst;
	for (int i = 0; i < minion; i++) {
		int l, u;
		cin >> l >> u;
		lst.emplace_back(l, u);
	}
	int mini = 0;
	int office = 0;
	sort(lst.begin(), lst.end(), cuscom);
	while (mini < minion) {
		int temp = lst[mini].second;
		office++;
		while (lst[mini].first <= temp && temp <= lst[mini].second) {
			mini++;
		}
	}
	cout << office << endl;
}