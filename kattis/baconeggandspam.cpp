#include <bits/stdc++.h>
using namespace std;

int main() {
	int cus;
	while (cin >> cus, cus) {
		map<string, vector<string>> dicti;
		bool pertama = true;
		for (int i = 0; i < cus; i++) {
			string keysaver = "";
			string name = "";
			if (pertama) {
				pertama = false;
				cin.ignore();
			}
			else {
				char x;
				cin >> x;
				name += x;
			}
			string ln;
			getline(cin, ln);
			bool nameverify = true;
			for (int j = 0; j < ln.length(); j++) {
				if (nameverify) {
					if (ln[j] != ' ') {
						name += ln[j];
					}
					else {
						nameverify = false;
					}
				}
				else {
					if (ln[j] != ' ') {
						keysaver += ln[j];
					}
					else {
						dicti[keysaver].push_back(name);
						keysaver = "";
					}
				}
			}
			dicti[keysaver].push_back(name);
		}
		map<string, vector<string>>:: iterator itr;
		for (itr = dicti.begin(); itr != dicti.end(); itr++) {
			cout << itr->first << ' ';
			sort(itr->second.begin(), itr->second.end());
			vector<string> anon = itr->second;
			int sz = itr->second.size();
			bool isfirst = true;
			for (int k = 0; k < sz; k++) {
				if (isfirst) {
					isfirst = false;
				}
				else {
					cout << ' ';
				}
				cout << anon[k];
			}
			cout << endl;
		}
		cout << endl;
	}
}