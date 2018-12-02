#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, vector<int>>> prizes;
		for (int i = 0; i < n; i++) {
			int stickers;
			cin >> stickers;
			vector<int> saver1;
			for (int j = 0; j < stickers; j++) {
				int no;
				cin >> no;
				saver1.push_back(no);
			}
			int cash;
			cin >> cash;
			prizes.emplace_back(cash, saver1);
		}
		unordered_map<int, int> saver;
		for (int j = 1; j < m+1; j++) {
			int much;
			cin >> much;
			saver[j] = much;
		}
		int total = 0;
		for (int j = 0; j < prizes.size(); j++) {
			vector<int> temp = prizes[j].second;
			int mini = 1e9;
			for (int k = 0; k < temp.size(); k++) {
				mini = min(saver[temp[k]], mini);
			}
			total += mini*(prizes[j].first);
		}
		cout << total << endl;
	}
}