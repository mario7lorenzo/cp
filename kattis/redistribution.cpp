#include <bits/stdc++.h>
using namespace std;

int main() {
	int classes;
	vector<pair<int, int>> saver;
	cin >> classes;
	int totstudents = 0;
	for (int i = 1; i < classes+1; i++) {
		int students;
		cin >> students;
		saver.emplace_back(students, i);
		totstudents += students;
	}
	sort(saver.begin(), saver.end());
	if (saver[saver.size()-1].first > totstudents-saver[saver.size()-1].first) {
		cout << "impossible" << endl;
	}
	else {
		bool isfirst = true;
		for (int i = saver.size()-1; i >= 0; i--) {
			if (isfirst) {
				isfirst = false;
			}
			else {
				cout << ' ';
			}
			cout << saver[i].second;
		}
		cout << endl;
	}
}