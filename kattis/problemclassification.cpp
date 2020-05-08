#include <bits/stdc++.h>
using namespace std;

int main() {
	int cat;
	cin >> cat;
	unordered_set<string> saver;
	unordered_map<string, vector<string>> revsaver;
	unordered_map<string, int> counter;
	set<string> nama;
	while (cat--) {
		string name;
		cin >> name;
		int many;
		cin >> many;
		while(many--) {
			string words;
			cin >> words;
			saver.insert(words);
			nama.insert(name);
			revsaver[words].push_back(name);
		}
	}
	string par;
	set<string> final;
	while (cin >> par) {
		if (saver.find(par) != saver.end()) {
			for (auto i : revsaver[par]) {
				counter[i]++;
			}
		}
	}
	unordered_map<string, int>::iterator it;
	int maxi = -1;
	for (it = counter.begin(); it != counter.end(); it++) {
		maxi = max(maxi, it->second);
	}
	for (it = counter.begin(); it != counter.end(); it++) {
		if (maxi == it->second) {
			final.insert(it->first);
		}
	}
	if (maxi == -1) {
		for (auto i : nama) {
			cout << i << endl;
		}
	}
	for (auto i : final) {
		cout << i << endl;
	}
}
