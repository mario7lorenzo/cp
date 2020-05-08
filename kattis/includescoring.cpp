#include <bits/stdc++.h>
using namespace std;

bool custcom (pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
	return (a.first.first > b.first.first) || ((a.first.first == b.first.first) && a.first.second < b.first.second) || 
	(((a.first.first == b.first.first) && a.first.second == b.first.second) && a.second.first < b.second.first);
}

int main() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, pair<int, int>>> vpp, sorter;
	map<pair<pair<int, int>, pair<int, int>>, int> mp;
	map<pair<pair<int, int>, int>, int> cp;
	for (int i = 0; i < n; i++) {
		int s, p, f, o;
		cin >> s >> p >> f >> o;
		vpp.push_back(make_pair(make_pair(s, p), make_pair(f, o)));
	}
	sorter = vpp;
	stable_sort(sorter.begin(), sorter.end(), custcom);
	vector<int> vi {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int i = 0; i < 1000; i++) {
		vi.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		int a = sorter[i].first.first;
		int b = sorter[i].first.second;
		int c = sorter[i].second.first;
		cp[make_pair(make_pair(a, b), c)]++;
	}
	int i = 0;
	while (i < n) {
		int temp = i;
		int a = sorter[i].first.first;
		int b = sorter[i].first.second;
		int c = sorter[i].second.first;
		int many = cp[make_pair(make_pair(a, b), c)];
		int score = 0;
		for (int j = temp; j < temp+many; j++) {
			score += vi[i];
			i++;
		}
		int final = (int)(ceil(((double) score /(double) many)));
		for (int j = temp; j < temp+many; j++) {
			mp[sorter[j]] = final;
		}
	}
	for (int k = 0; k < n; k++) {
		int score = mp[vpp[k]];
		if (vpp[k].second.second) {
			score++;
		}
		cout << score << endl;
	}
}