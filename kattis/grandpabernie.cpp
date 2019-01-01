#include <bits/stdc++.h>
using namespace std;

int main() {
	int trips;
	cin >> trips;
	unordered_map<string, vector<int>> saver;
	while (trips--) {
		string country;
		int year;
		cin >> country >> year;
		saver[country].push_back(year);
	}
	unordered_map<string, vector<int>>::iterator it;
	for (it = saver.begin(); it != saver.end(); it++) {
		sort(it->second.begin(), it->second.end());
	}
	int queries;
	cin >> queries;
	while (queries--) {
		string country;
		int times;
		cin >> country >> times;
		cout << saver[country][times-1] << endl;
	}
}
