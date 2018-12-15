#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<string, unordered_set<string>>> lst;
	vector<string> sma = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
	for (int i = 0; i < sma.size(); i++) {
		int counter = i;
		unordered_set<string> temp2;
		for (int j = 0; j < 8; j++) {
			temp2.insert(sma[counter%sma.size()]);
			if (j == 2 || j == 6) {
				counter++;
			}
			else {
				counter += 2;
			}
		}
		lst.emplace_back(sma[i], temp2);
	}
	int t;
	cin >> t;
	unordered_set<string> q;
	for (int i = 0; i < t; i++) {
		string nt;
		cin >> nt;
		q.insert(nt);
	}
	unordered_set<string>::iterator it;
	vector<string> saver;
	for (int i = 0; i < lst.size(); i++) {
		string note = lst[i].first;
		bool exist = true;
		for (it = q.begin(); it != q.end(); it++) {
			if (lst[i].second.find(*it) == lst[i].second.end()) {
				exist = false;
				break;
			}
		}
		if (exist) {
			saver.push_back(note);
		}
	}
	if (saver.size() == 0) {
		cout << "none" << endl;
	}
	else {
		for (int i = 0; i < saver.size(); i++) {
			if (i == 0) {
				cout << saver[i];
			}
			else {
				cout << ' ' << saver[i];
			}
		}
		cout << endl;
	}
}