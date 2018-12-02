#include <bits/stdc++.h>
using namespace std;

int main() {
	int shops;
	cin >> shops;
	int item;
	cin >> item;
	unordered_map<string, set<int>> lst2;
	for (int i = 0; i < item; i++) {
		int no;
		cin >> no;
		string things;
		cin >> things;
		lst2[things].insert(no);
	}
	int buy;
	cin >> buy;
	vector<string> saver;
	for (int i = 0; i < buy; i++) {
		string curr;
		cin >> curr;
		saver.push_back(curr);
	}
	int maxi = 0, mini = 1e9;
	for (int i = 0; i < saver.size(); i++) {
		string bentar = saver[i];
		set<int> sementara = lst2[saver[i]];
		vector<int> temp;
		set<int>::iterator itr;
		for (itr = sementara.begin(); itr != sementara.end(); itr++) {
			if (*itr < maxi) {
				temp.push_back(*itr);
			}
		}
		for (int j = 0; j < temp.size(); j++) {
			lst2[bentar].erase(temp[j]);
		}
		if (lst2[bentar].size() > 0) {
			maxi = max(maxi, *lst2[saver[i]].begin());
		}
	}
	for (int i = saver.size()-1; i >= 0; i--) {
		vector<int> temp;
		set<int>::iterator itr;
		for (itr = lst2[saver[i]].begin(); itr != lst2[saver[i]].end(); itr++) {
			if (*itr > mini) {
				temp.push_back(*itr);
			}
		}
		for (int j = 0; j < temp.size(); j++) {
			lst2[saver[i]].erase(temp[j]);
		}
		if (lst2[saver[i]].size() > 0) {
			mini = min(mini, *lst2[saver[i]].rbegin());
		}
	}
	unordered_map<string, set<int>>::iterator itr;
	bool amb = false;
	bool can = true;
	for (int i = 0; i < saver.size(); i++) {
		if (lst2[saver[i]].size() == 0) {
			can = false;
		}
		if (lst2[saver[i]].size() > 1) {
			amb = true;
		}
	}
	if (!can) {
		cout << "impossible" << endl;
	}
	else if (amb) {
		cout << "ambiguous" << endl;
	}
	else {
		cout << "unique" << endl;
	}
}