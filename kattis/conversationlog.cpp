#include <bits/stdc++.h>
using namespace std;

bool cuscom(pair<string, int> x, pair<string, int> y) {
	return x.first < y.first;
}

bool cuscom2(pair<string, int> x, pair<string, int> y) {
	return x.second > y.second;
}

int main() {
	int t;
	cin >> t;
	unordered_map<string, unordered_set<string>> saver;
	unordered_map<string, int> counter;
	unordered_set<string> allwords;
	vector<string> helper;
	cin.ignore();
	while (t--) {
		string p, name, temp = "";
		getline(cin, p);
		// cout << p << endl;
		bool nama = true;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == ' ') {
				if (nama) {
					name = temp;
					temp = "";
					nama = false;
					// cout << name << endl;
				}
				else {
					saver[name].insert(temp);
					counter[temp]++;
					if (allwords.find(temp) == allwords.end()) {
						allwords.insert(temp);
						helper.push_back(temp);
					}
					temp = "";
				}
			}
			else {
				temp += p[i];
			}
		}
		saver[name].insert(temp);
		counter[temp]++;
		if (allwords.find(temp) == allwords.end()) {
			allwords.insert(temp);
			helper.push_back(temp);
		}
		temp = "";		
	}
	vector<pair<string, int>> final;
	unordered_map<string, unordered_set<string>>::iterator it;
	for (int i = 0; i < helper.size(); i++) {
		bool benar = true;
		for (it = saver.begin(); it != saver.end(); it++) {
			if (it->second.find(helper[i]) == it->second.end()) {
				benar = false;
				break;
			}
		}
		if (benar) {
			final.emplace_back(helper[i], counter[helper[i]]);
		}
	}
	sort(final.begin(), final.end(), cuscom);
	sort(final.begin(), final.end(), cuscom2);
	if (final.size() == 0) {
		cout << "ALL CLEAR" << endl;
	}
	else {
		for (auto i : final) {
			cout << i.first << endl;
		}		
	}
}