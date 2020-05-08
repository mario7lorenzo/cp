#include <bits/stdc++.h>
using namespace std;

int cost(vector<string> x, vector<string> y) {
	int val = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] != y[i]) {
			val++;
		}
	}
	return val;
}

int main() {
	string quest;
	getline(cin, quest);
	int alt;
	cin >> alt;
	vector<vector<string>> lst;
	bool isfirst = true;
	for (int i = 0; i < alt; i++) {
		vector<string> semen;
		string temp = "";
		string opt;
		if (isfirst) {
			cin.ignore();
			isfirst = false;
		}
		getline(cin, opt);
		for (int i = 0; i < opt.length(); i++) {
			if (opt[i] == ' ' && temp == "") {
				continue;
			}
			else if (opt[i] == ',') {
				semen.push_back(temp);
				temp = "";
			}
			else {
				temp += opt[i];
			}
		}
		semen.push_back(temp);
		lst.push_back(semen);
	}
	int diff[alt];
	for (int i = 0; i < alt; i++) {
		int maxcost = -1e9;
		for (int j = 0; j < alt; j++) {
			maxcost = max(maxcost, cost(lst[i], lst[j]));
		}
		diff[i] = maxcost;
	}
	int mincost = 1e9;
	for (int i = 0; i < alt; i++) {
		mincost = min(mincost, diff[i]);
	}
	for (int i = 0; i < alt; i++) {
		if (diff[i] == mincost) {
			for (int j = 0; j < lst[i].size(); j++) {
				if (j == 0) {
					string temp = "";
					temp += lst[i][j];
					temp += ',';
					cout << temp;
				}
				else if (j == lst[i].size()-1) {
					string temp = " ";
					temp += lst[i][j];
					cout << temp;
				}
				else {
					string temp = " ";
					temp += lst[i][j];
					temp += ',';
					cout << temp;
				}
			}
			cout << endl;
		}
	}
}