#include <bits/stdc++.h>
using namespace std;

int ke;
bool cuscom(vector<string> x, vector<string> y) {
	return x[ke] < y[ke];
}

int main() {
	string p;
	getline(cin, p);
	string temp = "";
	vector<string> att;
	vector<vector<string>> lst;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == ' ') {
			att.push_back(temp);
			temp = "";
		}
		else {
			temp += p[i];
		}
	}
	att.push_back(temp);
	temp = "";
	int unit;
	cin >> unit;
	for (int i = 0; i < unit; i++) {
		vector<string> song;
		for (int j = 0; j < att.size(); j++) {
			string cat;
			cin >> cat;
			song.push_back(cat);
		}
		lst.push_back(song);
	}
	int cats;
	cin >> cats;
	bool pertama = true;
	for (int i = 0; i < cats; i++) {
		if (pertama) {
			pertama = false;
		}
		else {
			cout << endl;
		}
		string genre;
		cin >> genre;
		for (int j = 0; j < att.size(); j++) {
			if (att[j] == genre) {
				ke = j;
				break;
			}
		}
		stable_sort(lst.begin(), lst.end(), cuscom);
		cout << p << endl;
		for (int j = 0; j < lst.size(); j++) {
			for (int k = 0; k < lst[j].size(); k++) {
				if (k == 0) {
					cout << lst[j][k];
				}
				else {
					cout << ' ' << lst[j][k];
				}
			}
			cout << endl;
		}
	}
}