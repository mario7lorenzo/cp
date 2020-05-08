#include <bits/stdc++.h>
using namespace std;

bool cuscom1(pair<string, int> v1, pair<string, int> v2) {
	return v1.first < v2.first;
}

bool cuscom2(pair<string, int> v1, pair<string, int> v2) {
	return v1.second > v2.second;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			string x;
			int k;
			cin >> x >> k;
			mp[x] += k;
		}
		map<string, int>::iterator itr;
		vector<pair<string, int> > saver;
		for (itr = mp.begin(); itr != mp.end(); itr++) {
			saver.push_back(make_pair(itr->first, itr->second));
		}
		stable_sort(saver.begin(), saver.end(), cuscom1);
		stable_sort(saver.begin(), saver.end(), cuscom2);
		cout << saver.size() << endl;
		for (auto i : saver) {
			cout << i.first << ' ' << i.second << endl;
		}
	}
}