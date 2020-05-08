#include <bits/stdc++.h>
using namespace std;

string spaceslicer(string x) {
	int sz = x.length();
	string s = "";
	for (int i = 0; i < sz; i++) {
		if (x[i] == ' ') {
			return s;
		}
		s += x[i];
	}
}

bool verifier(string x, vector<string> y) {
	int sz = y.size();
	bool ver = false;
	for (int i = 0; i < sz; i++) {
		if (x == y[i]) {
			ver = true;
			return ver;
		}
	}
	return ver;
}

int main() {
	int nmbr;
	cin >> nmbr;
	string p;
	vector<string> lst;
	vector<string> final;
	while(getline(cin, p)) {
		string team = spaceslicer(p);
		if (final.size() == 12) {
			break;
		}
		if (p == "") {
			continue;
		}
		else if (verifier(team, lst) == false) {
			lst.push_back(team);
			final.push_back(p);
		}
		else if (verifier(team, lst)) {
			continue;
		}
	}
	for (int i = 0; i < final.size(); i++) {
		cout << final[i] << endl;
	}
}