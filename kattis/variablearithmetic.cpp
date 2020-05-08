#include <bits/stdc++.h>
using namespace std;

int main() {
	string p;
	unordered_map<string, int> definition;
	while (getline(cin, p), p != "0") {
		int counter = 0;
		vector<string> saver;
		string defi;
		string temp = "";
		bool definisi = false;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == ' ') {
				if (temp != "") {
					saver.push_back(temp);
					temp = "";
				}
			}
			else if (p[i] == '=') {
				definisi = true;
				defi = saver[0];
				temp = "";
			}
			else if (p[i] == '+') {
				continue;
			}
			else {
				temp += p[i];
			}
		}
		if (definisi) {
			definition[defi] = stoi(temp);
		}
		else {
			saver.push_back(temp);
			vector<string> nondef;
			int counter = 0;
			for (int i = 0; i < saver.size(); i++) {
				if (isdigit(saver[i][0])) {
					counter += stoi(saver[i]);
				}
				else {
					if (definition.find(saver[i]) != definition.end()) {
						counter += definition[saver[i]];
					}
					else {
						nondef.push_back(saver[i]);
					}
				}
			}
			if (counter == 0 && nondef.size() == 0) {
				cout << 0 << endl;
			}
			else if (counter == 0 && nondef.size() != 0) {
				bool isfirst = true;
				for (auto i : nondef) {
					if (isfirst) {
						cout << i;
						isfirst = false;
					}
					else {
						cout << " + " << i;
					}
				}
				cout << endl;
			}
			else {
				cout << counter;
				for (auto i : nondef) {
					cout << " + " << i;
				}
				cout << endl;
			}
		}
	}
}			