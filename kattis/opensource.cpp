#include <bits/stdc++.h>
using namespace std;

bool cuscom(pair<string, int> x, pair<string, int> y) {
	return x.first < y.first;
}

bool cuscom2(pair<string, int> x, pair<string, int> y) {
	return x.second > y.second;
}
 
int main() {
	unordered_map<string, unordered_set<string>> lst;
	string p, booth;
	unordered_map<string, string> dupdet;
	while (getline(cin, p)) {
		if (int(p[0]) <= 90 && int(p[0]) >= 65) {
			booth = p;
			lst[booth].insert("tes");
		}
		else if (int(p[0]) >= 97 && int(p[0]) <= 122) {
			if (dupdet.find(p) == dupdet.end()) {
				lst[booth].insert(p);
				dupdet[p] = booth;
			}
			else {
				if (dupdet[p] != booth) {
					lst[dupdet[p]].erase(p);
				}
			}
		}
		else if (p == "1") {
			vector<pair<string, int>> final;
			unordered_map<string, unordered_set<string>>::iterator it;
			for (it = lst.begin(); it != lst.end(); it++) {
				final.emplace_back(it->first, it->second.size());
			}
			sort(final.begin(), final.end(), cuscom);
			stable_sort(final.begin(), final.end(), cuscom2);
			for (auto i : final) {
				cout << i.first << ' ' << i.second-1 << endl;
			}
			lst.clear();
			dupdet.clear();
		}
		else if (p == "0") {
			break;
		}
	}
}