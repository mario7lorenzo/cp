#include <bits/stdc++.h>
using namespace std;

bool cuscom(pair<string, string> x, pair<string, string> y) {
	return x.first < y.first;
}

bool cuscom2(pair<string, string> x, pair<string, string> y) {
	return x.second < y.second;
}
int main() {
	string dpn, blkg;
	vector<pair<string, string>> lst;
	unordered_map<string, int> freqfirst;
	unordered_map<string, int> freqlast;
	while (cin >> dpn >> blkg) {
		lst.emplace_back(dpn, blkg);
		freqfirst[dpn]++;
		freqlast[blkg]++;
	}
	sort(lst.begin(), lst.end(), cuscom);
	stable_sort(lst.begin(), lst.end(), cuscom2);
	for (auto i : lst) {
		string firstname = i.first;
		string lastname = i.second;
		if (freqfirst[firstname] > 1) {
			cout << firstname << ' ' << lastname << endl;
		}
		else {
			cout << firstname << endl;
		}
	}
}